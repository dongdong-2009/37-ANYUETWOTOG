#include "dialog_gunselect.h"
#include "ui_dialog_gunselect.h"
#include "globalhmi.h"

Dialog_gunselect::Dialog_gunselect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_gunselect)
{
    ui->setupUi(this);
}

Dialog_gunselect::~Dialog_gunselect()
{
    delete ui;
}

void Dialog_gunselect::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(PAGE_FLUSH_TIMER);
    init_page_val();
    ui->label_code->setText(code);
   // ui->label_phone->setText(phonenum);
   // ui->label_phone_2->setText(phonenum_2);
}

UINT16 num_temp_select=0;
int clicknum_1 = 0,num_bit_1=0;
int clicknum_2 = 0,num_bit_2=0;
int clicknum_3 = 0,num_bit_3=0;
int clicknum_4 = 0,num_bit_4=0;

void Dialog_gunselect::init_page_val()
{
    clicknum_1 = 0,num_bit_1=0;
    clicknum_2 = 0,num_bit_2=0;
    clicknum_3 = 0,num_bit_3=0;
    clicknum_4 = 0,num_bit_4=0;
    num_temp_select=0;
    UINT8 data = NO_BUTTON;
    UINT16 num_temp = 0;
     API_Write_DB_Nbyte(PL_GETNEEDCHARGUNNUM,(UINT16 *)(&num_temp),sizeof(num_temp));
     API_Write_DB_Nbyte(PL_GETNEEDSTOPGUNNUM,(UINT16 *)(&num_temp),sizeof(num_temp));
     API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));

    ui->label_num->setText(" ");
    ui->label_speaker->setText(QString::fromUtf8("点击选中,再次单击取消"));
}

void Dialog_gunselect::start_timer()
{
    timer->start(PAGE_FLUSH_TIMER);
}

void Dialog_gunselect::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}

void Dialog_gunselect::update_page_info()
{
     ui->label_num->setText(QString::number(((num_temp_select&(0xF000))>>12)*10+((num_temp_select&(0xF00))>>8)));
     ui->lbl_sysdate->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd"));
     ui->lbl_systime->setText(QTime::currentTime().toString("hh:mm:ss"));
      if(language_num == 1)
      {
           // ui->label_logo->setText(QString::fromUtf8("直 流 充 电 桩"));
          //  ui->label_title->setText(QString::fromUtf8("余 额 查 询"));
            ui->label_stubnum->setText(QString::fromUtf8(" 桩   编   号  :"));
          //  ui->pbtn_cancel->setText(QString::fromUtf8("返        回"));
      }
      else  if(language_num == 2)
      {
          //  ui->label_logo->setText("DC charging pile");
           // ui->label_title->setText("Balance Inquire");
            ui->label_stubnum->setText("Pile Number :");
         //   ui->pbtn_cancel->setText("Back");
      }
}

void Dialog_gunselect::update_hmi_page_index()
{
        API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
       if(hmi_page_index != PAGEINDEX_USERACTION)
       {
           exit_page_dlg();
       }
       else
       {

       }
}

void Dialog_gunselect::exit_page_dlg()
{
    init_page_val();
    UINT8 data = NO_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
    timer->stop();
    emit signal_exit_dlg_gun();
    //delete dlg_gun;
    //dlg_gun = NULL;
}

int bit_judge()
{
    if(num_temp_select & (0xF<<12))
    {
        if(num_temp_select & (0xF<<8))
        {
            if(num_temp_select & (0xF<<4))
            {
                return 0;
            }
            else
            {
                return 4;
            }
        }
        else
        {
            return 8;
        }
    }
    else
    {
        return 12;
    }
}

void Dialog_gunselect::on_pbtn_1_clicked()
{
    //num_temp_select
    if(clicknum_1==0)
    {
        clicknum_1=1;
        num_bit_1 = bit_judge();
        num_temp_select +=(1<<num_bit_1);
    }
    else if(clicknum_1==1)
    {
        clicknum_1=0;
        num_temp_select -=(1<<num_bit_1);
    }
 //   printf("@@@@@@[%x]\r\n",num_temp_select);
}

void Dialog_gunselect::on_pbtn_2_clicked()
{
    if(clicknum_2==0)
    {
        clicknum_2=1;
        num_bit_2 = bit_judge();
        num_temp_select +=(2<<num_bit_2);
    }
    else if(clicknum_2==1)
    {
        clicknum_2=0;
        num_temp_select -=(2<<num_bit_2);
    }
 //   printf("@@@@@@[%x]\r\n",num_temp_select);
}

void Dialog_gunselect::on_pbtn_3_clicked()
{
    if(clicknum_3==0)
    {
        clicknum_3=1;
        num_bit_3 = bit_judge();
        num_temp_select +=(3<<num_bit_3);
    }
    else if(clicknum_3==1)
    {
        clicknum_3=0;
        num_temp_select -=(3<<num_bit_3);
    }
  //  printf("@@@@@@[%x]\r\n",num_temp_select);
}

void Dialog_gunselect::on_pbtn_4_clicked()
{
    if(clicknum_4==0)
    {
        clicknum_4=1;
        num_bit_4 = bit_judge();
        num_temp_select +=(4<<num_bit_4);
    }
    else if(clicknum_4==1)
    {
        clicknum_4=0;
        num_temp_select -=(4<<num_bit_4);
    }
 //   printf("@@@@@@[%x]\r\n",num_temp_select);
}

void Dialog_gunselect::on_pushButton_ok_clicked()
{
    UINT8 char_state_1=0,char_state_2=0;
    if(num_temp_select == 0)
    {
        ui->label_speaker->setText(QString::fromUtf8("请选择所需的充电枪"));
        return;
    }
    API_Read_DB_Nbyte(PL_STUBISCHARGING_1,(UINT8 *)(&char_state_1),sizeof(char_state_1));
    API_Read_DB_Nbyte(PL_STUBISCHARGING_2,(UINT8 *)(&char_state_2),sizeof(char_state_2));
    if(char_state_1)
     {
        if((((num_temp_select & 0xF000)>>12) == 1) ||(((num_temp_select & 0xF00)>>8) == 1))
        {
            num_temp_select = 0;
            clicknum_1 = 0,num_bit_1=0;
            clicknum_2 = 0,num_bit_2=0;
            clicknum_3 = 0,num_bit_3=0;
            clicknum_4 = 0,num_bit_4=0;
           ui->label_speaker->setText(QString::fromUtf8("一号枪已在使用中,请重新选择"));
           return;
        }
    }

    if(char_state_2)
     {
        if((((num_temp_select & 0xF000)>>12) == 2) ||(((num_temp_select & 0xF00)>>8) == 2))
        {
            num_temp_select = 0;
            clicknum_1 = 0,num_bit_1=0;
            clicknum_2 = 0,num_bit_2=0;
            clicknum_3 = 0,num_bit_3=0;
            clicknum_4 = 0,num_bit_4=0;
           ui->label_speaker->setText(QString::fromUtf8("二号枪已在使用中,请重新选择"));
           return;
        }
    }
    API_Write_DB_Nbyte(PL_GETNEEDCHARGUNNUM,(UINT16 *)(&num_temp_select),sizeof(num_temp_select));
    hmi_button_dn_num=PRINTSURE_ACBUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),
                       sizeof(hmi_button_dn_num));
}

void Dialog_gunselect::on_pushButton_cancel_clicked()
{
    hmi_button_dn_num=CANCEL_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));
}

void Dialog_gunselect::on_pushButton_stop_clicked()
{
    if(num_temp_select == 0)
    {
        ui->label_speaker->setText(QString::fromUtf8("请选择所需的充电枪"));
        return;
    }

    UINT8 char_state_1=0,char_state_2=0;
    API_Read_DB_Nbyte(PL_STUBISCHARGING_1,(UINT8 *)(&char_state_1),sizeof(char_state_1));
    API_Read_DB_Nbyte(PL_STUBISCHARGING_2,(UINT8 *)(&char_state_2),sizeof(char_state_2));

    if(char_state_1 == 0)
     {
        if((((num_temp_select & 0xF000)>>12) == 1) ||(((num_temp_select & 0xF00)>>8) == 1))
        {
            num_temp_select = 0;
            clicknum_1 = 0,num_bit_1=0;
            clicknum_2 = 0,num_bit_2=0;
            clicknum_3 = 0,num_bit_3=0;
            clicknum_4 = 0,num_bit_4=0;
           ui->label_speaker->setText(QString::fromUtf8("一号枪已停止使用,请重新选择"));
           return;
        }
    }

    if(char_state_2 == 0)
     {
        if((((num_temp_select & 0xF000)>>12) == 2) ||(((num_temp_select & 0xF00)>>8) == 2))
        {
            num_temp_select = 0;
            clicknum_1 = 0,num_bit_1=0;
            clicknum_2 = 0,num_bit_2=0;
            clicknum_3 = 0,num_bit_3=0;
            clicknum_4 = 0,num_bit_4=0;
           ui->label_speaker->setText(QString::fromUtf8("二号枪已停止使用,请重新选择"));
           return;
        }
    }

    API_Write_DB_Nbyte(PL_GETNEEDSTOPGUNNUM,(UINT16 *)(&num_temp_select),
                       sizeof(num_temp_select));
    hmi_button_dn_num=PRINTCANCEL_ACBUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),
                       sizeof(hmi_button_dn_num));
}
