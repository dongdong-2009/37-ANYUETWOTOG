#include "p04_alarmquery_dialog.h"
#include "ui_p04_alarmquery_dialog.h"
#include "globalhmi.h"

p04_alarmquery_dialog::p04_alarmquery_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p04_alarmquery_dialog)
{
    ui->setupUi(this);
}

p04_alarmquery_dialog::~p04_alarmquery_dialog()
{
    delete ui;
}

void p04_alarmquery_dialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void p04_alarmquery_dialog::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(PAGE_FLUSH_TIMER);        
    init_page_val();
}


char temp[50][200]={};
int i=0;

void p04_alarmquery_dialog::init_page_val()
{
        UINT8 data = NO_BUTTON;
        FILE *fp=NULL;
        int index=0;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));


       fp=fopen(data_path,"r");
        if(fp==NULL)
        {
            return;
        }
        for(index=0;index<50;index++)
        {
             memset(temp[index],0,sizeof(temp[0]));
        }


        while(fgets(temp[i],256,fp))
        {
            i++;
            if(i>49)
            {
                break;
            }
        }
        memset(temp[i-1],0,sizeof(temp[i-1]));


             lbl_num=1;
             lbl_num_2=2;
             lbl_num_3=3;
             lbl_num_4=4;
             lbl_num_5=5;

            memcpy(lbl_txt,temp[0],sizeof(lbl_txt));
            memcpy(lbl_txt_2,temp[1],sizeof(lbl_txt_2));
            memcpy(lbl_txt_3,temp[2],sizeof(lbl_txt_3));
            memcpy(lbl_txt_4,temp[3],sizeof(lbl_txt_4));
            memcpy(lbl_txt_5,temp[4],sizeof(lbl_txt_5));
    fclose(fp);
}

void p04_alarmquery_dialog::start_timer()
{
    timer->start(PAGE_FLUSH_TIMER);
}


void p04_alarmquery_dialog::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}

void p04_alarmquery_dialog::update_page_info()
{
     ui->label_code->setText(code);
      ui->label_phone->setText(phonenum);
    ui->label_txt->setText(QString::fromUtf8(lbl_txt));
    ui->label_txt_2->setText(QString::fromUtf8(lbl_txt_2));
    ui->label_txt_3->setText(QString::fromUtf8(lbl_txt_3));
    ui->label_txt_4->setText(QString::fromUtf8(lbl_txt_4));
    ui->label_txt_5->setText(QString::fromUtf8(lbl_txt_5));

    ui->label_num->setNum(lbl_num);
    ui->label_num_2->setNum(lbl_num_2);
    ui->label_num_3->setNum(lbl_num_3);
    ui->label_num_4->setNum(lbl_num_4);
    ui->label_num_5->setNum(lbl_num_5);
}

void p04_alarmquery_dialog::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX_CUR,(INT8 *)(&hmi_page_index_cur),sizeof(hmi_page_index_cur));
    DebugMsg(hmilev,8,"hmi_page_index=[%d]cur[%d]\n",hmi_page_index,hmi_page_index_cur);
    if(hmi_page_index!=hmi_page_index_cur)
    {
        API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX_CUR,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
        if(hmi_page_index==PAGEINDEX_ERRORCHECK)
        {
                DebugMsg(hmilev,8,"hmi_page_index=[%d]cur[%d]\n",hmi_page_index,hmi_page_index_cur);
        }else
        if(hmi_page_index==PAGEINDEX_SERVICECHOICE)
        {
                exit_page_dlg();
        }else
        {
                ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
                exit(1);
        }
    }
}

void p04_alarmquery_dialog::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_p04dlg();
    i=0;
    delete p04_dlg;
    p04_dlg = NULL;
}



void p04_alarmquery_dialog::on_pbtn_up_clicked()
{

     if(lbl_num-5>0)
     {
             lbl_num=lbl_num-5;
             lbl_num_2=lbl_num_2-5;
             lbl_num_3=lbl_num_3-5;
             lbl_num_4=lbl_num_4-5;
             lbl_num_5=lbl_num_5-5;

            memcpy(lbl_txt,temp[lbl_num-1],sizeof(lbl_txt));
            memcpy(lbl_txt_2,temp[lbl_num_2-1],sizeof(lbl_txt_2));
            memcpy(lbl_txt_3,temp[lbl_num_3-1],sizeof(lbl_txt_3));
            memcpy(lbl_txt_4,temp[lbl_num_4-1],sizeof(lbl_txt_4));
            memcpy(lbl_txt_5,temp[lbl_num_5-1],sizeof(lbl_txt_5));
    }
     else
     {

     }
}


void p04_alarmquery_dialog::on_pbtn_down_clicked()
{

     if(lbl_num_5+5<51)
     {
             lbl_num=lbl_num+5;
             lbl_num_2=lbl_num_2+5;
             lbl_num_3= lbl_num_3+5;
             lbl_num_4=lbl_num_4+5;
             lbl_num_5=lbl_num_5+5;

            memcpy(lbl_txt,temp[lbl_num-1],sizeof(lbl_txt));
            memcpy(lbl_txt_2,temp[lbl_num_2-1],sizeof(lbl_txt_2));
            memcpy(lbl_txt_3,temp[lbl_num_3-1],sizeof(lbl_txt_3));
            memcpy(lbl_txt_4,temp[lbl_num_4-1],sizeof(lbl_txt_4));
            memcpy(lbl_txt_5,temp[lbl_num_5-1],sizeof(lbl_txt_5));

    }
     else
     {

     }
}

void p04_alarmquery_dialog::on_pbtn_enter_clicked()
{
    hmi_button_dn_num=OK_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));
}
