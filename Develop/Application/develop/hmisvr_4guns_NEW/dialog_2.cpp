#include "dialog_2.h"
#include "ui_dialog_2.h"
#include "globalhmi.h"

dialog_2::dialog_2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_2)
{
    ui->setupUi(this);
}

dialog_2::~dialog_2()
{
    delete ui;
}

void dialog_2::changeEvent(QEvent *e)
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

void dialog_2::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(PAGE_FLUSH_TIMER);
    //timer->start(300);
    init_page_val();
    btn_press();
    ui->label_code->setText(code);
    ui->label_phone->setText(phonenum);
    ui->label_phone_2->setText(phonenum_2);
}
static int time_add=0;
static UINT8 jump_num;
static BOOL enter_clc;
void dialog_2::init_page_val()
{
    jump_num=0;
    enter_clc=FALSE;
    btn_passwd_pos=0;
    memset(btn_passwd,0,sizeof(btn_passwd));
    UINT8 data = NO_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void dialog_2::start_timer()
{
    timer->start(PAGE_FLUSH_TIMER);
    //timer->start(300);
    init_page_val();
}

void dialog_2::timer_handle()
{
    update_page_info();
    update_hmi_page_index();

}

void dialog_2::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_dlg_2();
    delete dlg_2;
    dlg_2 = NULL;
}

//#define DEF_DEBUG_PASSWD_BY_NUM
void dialog_2::btn_press()
{

  ui->pbtn_num0->setStyleSheet("QPushButton{border-image: url(:/key/qrc/keyboard-b/0.png);}\
                                QPushButton:pressed{border-image: url(:/key/qrc/keyboard-b/0-d.png);}");

  ui->pbtn_num1->setStyleSheet("QPushButton{border-image: url(:/key/qrc/keyboard-b/1.png);}\
                                QPushButton:pressed{border-image: url(:/key/qrc/keyboard-b/1-d.png);}");

  ui->pbtn_num2->setStyleSheet("QPushButton{border-image: url(:/key/qrc/keyboard-b/2.png);}\
                                QPushButton:pressed{border-image: url(:/key/qrc/keyboard-b/2-d.png);}");

  ui->pbtn_num3->setStyleSheet("QPushButton{border-image: url(:/key/qrc/keyboard-b/3.png);}\
                                QPushButton:pressed{border-image: url(:/key/qrc/keyboard-b/3-d.png);}");

  ui->pbtn_num4->setStyleSheet("QPushButton{border-image: url(:/key/qrc/keyboard-b/4.png);}\
                                QPushButton:pressed{border-image: url(:/key/qrc/keyboard-b/4-d.png);}");

  ui->pbtn_num5->setStyleSheet("QPushButton{border-image: url(:/key/qrc/keyboard-b/5.png);}\
                                QPushButton:pressed{border-image: url(:/key/qrc/keyboard-b/5-d.png);}");

  ui->pbtn_num6->setStyleSheet("QPushButton{border-image: url(:/key/qrc/keyboard-b/6.png);}\
                                QPushButton:pressed{border-image: url(:/key/qrc/keyboard-b/6-d.png);}");

  ui->pbtn_num7->setStyleSheet("QPushButton{border-image: url(:/key/qrc/keyboard-b/7.png);}\
                                QPushButton:pressed{border-image: url(:/key/qrc/keyboard-b/7-d.png);}");

  ui->pbtn_num8->setStyleSheet("QPushButton{border-image: url(:/key/qrc/keyboard-b/8.png);}\
                                QPushButton:pressed{border-image: url(:/key/qrc/keyboard-b/8-d.png);}");

  ui->pbtn_num9->setStyleSheet("QPushButton{border-image: url(:/key/qrc/keyboard-b/9.png);}\
                                QPushButton:pressed{border-image: url(:/key/qrc/keyboard-b/9-d.png);}");

  ui->pbtn_dot->setStyleSheet("QPushButton{border-image: url(:/key/qrc/keyboard-b/dot.png);}\
                                QPushButton:pressed{border-image: url(:/key/qrc/keyboard-b/dot-d.png);}");

  ui->pbtn_back->setStyleSheet("QPushButton{border-image: url(:/key/qrc/keyboard-b/c.png);}\
                                QPushButton:pressed{border-image: url(:/key/qrc/keyboard-b/c-d.png);}");
}

void dialog_2::update_page_info()
{
    //passwd information
    DebugMsg(hmilev,8,"btn_passwd[%s][%d]\n",btn_passwd,btn_passwd_pos);
    memset(btn_passwd_disp,0,sizeof(btn_passwd_disp));
    #ifdef DEF_DEBUG_PASSWD_BY_NUM
    strcpy(btn_passwd_disp,btn_passwd);
    #else
    memset(btn_passwd_disp,'*',btn_passwd_pos);
    #endif
    ui->label_passwd->setText(btn_passwd_disp);

    //main card information
    BOOL get_maincard_flag = FALSE;

    API_Read_DB_Nbyte(PL_GETMAINCARD_FLAG,(INT8 *)(&get_maincard_flag),sizeof(get_maincard_flag));
    if(get_maincard_flag==TRUE)
    {
    API_Read_DB_Nbyte(PL_MAINCARD_SN,(INT8 *)(&main_card_sn),sizeof(main_card_sn));
    ui->label_card_sn->setText(main_card_sn);
    // ErrMsg("$$$$$$$$$[%s]\n",main_card_sn);
    }

    //speaker info
    if(jump_num==0)
    {
    ui->label_speaker->setText(QString::fromUtf8("安全提示:请注意遮挡键盘!"));
    }
    else if(jump_num==6)
    {
    ui->label_speaker->setText(QString::fromUtf8("密码不能为空,请重新输入!"));
    }
    else if(jump_num==8)
    {
    ui->label_speaker->setText(QString::fromUtf8("密码错误,请重新输入!"));
    }
    else
    {
        UINT8 num_add=0;
        time_add++;
        if(time_add>5)
        {
            API_Read_DB_Nbyte(PL_CHRPASSWRDERR_FLAG,(UINT8 *)(&num_add),sizeof(num_add));
            time_add=0;
        }

        // ErrMsg("$$$$$$$$$$$$=%d\n",num_add);

        if((num_add==1)&&enter_clc)
        {
        btn_passwd_pos=0;
        memset(btn_passwd,0,sizeof(btn_passwd));
        enter_clc=FALSE;
        ui->label_speaker->setText(QString::fromUtf8("密码验证失败,请重新输入!"));
        }
        else if(num_add==2)
        {
        ui->label_speaker->setText(QString::fromUtf8("正在验证密码,请耐心等待!"));
        }
        else if(num_add==3)
        {
        ui->label_speaker->setText(QString::fromUtf8("密码验证成功!"));
        }
        else if(num_add==4)
        {
        ui->label_speaker->setText(QString::fromUtf8("正在结束充电,请耐心等待!"));
        }
        else if(num_add==5)
        {
        ui->label_speaker->setText(QString::fromUtf8("获取结算信息中,请耐心等待!"));
        }
        else if(num_add==6)
        {
        ui->label_speaker->setText(QString::fromUtf8("获取结算信息失败!"));
        }
        else
        {
        // ErrMsg("jump_num=%d\n",num_add);
        }
    }
}

void dialog_2::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX_CUR,(INT8 *)(&hmi_page_index_cur),sizeof(hmi_page_index_cur));
    DebugMsg(hmilev,8,"hmi_page_index=[%d]cur[%d]\n",hmi_page_index,hmi_page_index_cur);
    if(hmi_page_index!=hmi_page_index_cur)
    {
        API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX_CUR,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));

        if(hmi_page_index==PAGEINDEX_CHARGEPROCESS)
        {
            call_p11_dlg();
        }
        else
        if(hmi_page_index==PAGEINDEX_ACCHARGEPROCESS)
        {
            call_p19_dlg();
        }
        else
        if(hmi_page_index==PAGEINDEX_PAYOFF)
        {
            call_p12_dlg();
        }
        else
        if(hmi_page_index==PAGEINDEX_ACPAYOFF)
        {
            call_p20_dlg();
        }
        /*
        else
        if(hmi_page_index==PAGEINDEX_LITTLEWINDOW_ONE)
        {
            call_dlg_1();
        }
        */
        else{
            ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
            exit(1);
        }

    }
}

void dialog_2::call_p11_dlg()
{
    timer->stop();
    emit signal_timer_dlg_2();
    delete dlg_2;
    dlg_2 = NULL;
}

void dialog_2::call_p19_dlg()
{
    timer->stop();
    emit signal_timer_dlg_2();
    delete dlg_2;
    dlg_2 = NULL;
}

void dialog_2::call_p12_dlg()
{
    timer->stop();
    if(p12_dlg){
            delete p12_dlg;
            p12_dlg = NULL;
            handle_dlg_p12--;
    }
    p12_dlg = new  p12_payoff_dialog;
    p12_dlg->setWindowFlags(Qt::FramelessWindowHint);
    handle_dlg_p12++;

    connect(this,SIGNAL(signal_enable_p12dlg_timer()),p12_dlg,SLOT(init_page_dlg()));
    connect(p12_dlg,SIGNAL(signal_exit_p12dlg()),this,SLOT(exit_page_dlg()));
    emit signal_enable_p12dlg_timer();
    p12_dlg->exec();
}

void dialog_2::call_p20_dlg()
{
    timer->stop();
    if(p20_dlg){
            delete p20_dlg;
            p20_dlg = NULL;
            handle_dlg_p20--;
    }
    p20_dlg = new  p20_payoff_dialog;
    p20_dlg->setWindowFlags(Qt::FramelessWindowHint);
    handle_dlg_p20++;

    connect(this,SIGNAL(signal_enable_p20dlg_timer()),p20_dlg,SLOT(init_page_dlg()));
    connect(p20_dlg,SIGNAL(signal_exit_p20dlg()),this,SLOT(exit_page_dlg()));
    emit signal_enable_p20dlg_timer();
    p20_dlg->exec();
}
/*
void dialog_2::call_dlg_1()
{
    timer->stop();
    if(dlg_1){
            delete dlg_1;
            dlg_1 = NULL;

    }

    dlg_1 = new dialog_1 ;
    dlg_1->setWindowFlags(Qt::FramelessWindowHint);
    connect(this,SIGNAL(signal_enable_dlg_1_timer()),dlg_1,SLOT(init_page_dlg()));
    connect(dlg_1,SIGNAL(signal_exit_dlg_1()),this,SLOT(exit_page_dlg()));
    emit signal_enable_dlg_1_timer();
    dlg_1->exec();
}

void dialog_2::call_p02_dlg()
{
    timer->stop();
    if(p02_dlg){
            delete p02_dlg;
            p02_dlg = NULL;
            handle_dlg_p02--;
    }
    p02_dlg = new  p02_servchoose_dialog;
    p02_dlg->setWindowFlags(Qt::FramelessWindowHint);
    handle_dlg_p02++;
    connect(this,SIGNAL(signal_enable_p02dlg_timer()),p02_dlg,SLOT(init_page_dlg()));
    connect(p02_dlg,SIGNAL(signal_exit_p02dlg()),this,SLOT(exit_page_dlg()));
    emit signal_enable_p02dlg_timer();
    p02_dlg->exec();
}
*/

void dialog_2::on_pbtn_num0_clicked()
{
    if(btn_passwd_pos>=MAX_PASSWD_LEN)
    {
        btn_passwd_pos=MAX_PASSWD_LEN;
    }else{
        btn_passwd[btn_passwd_pos++]='0';
    }
}

void dialog_2::on_pbtn_num1_clicked()
{
    if(btn_passwd_pos>=MAX_PASSWD_LEN)
    {
        btn_passwd_pos=MAX_PASSWD_LEN;
    }else{
        btn_passwd[btn_passwd_pos++]='1';
    }
}

void dialog_2::on_pbtn_num2_clicked()
{
    if(btn_passwd_pos>=MAX_PASSWD_LEN)
    {
        btn_passwd_pos=MAX_PASSWD_LEN;
    }else{
        btn_passwd[btn_passwd_pos++]='2';
    }
}

void dialog_2::on_pbtn_num3_clicked()
{
    if(btn_passwd_pos>=MAX_PASSWD_LEN)
    {
        btn_passwd_pos=MAX_PASSWD_LEN;
    }else{
        btn_passwd[btn_passwd_pos++]='3';
    }
}

void dialog_2::on_pbtn_num4_clicked()
{
    if(btn_passwd_pos>=MAX_PASSWD_LEN)
    {
        btn_passwd_pos=MAX_PASSWD_LEN;
    }else{
        btn_passwd[btn_passwd_pos++]='4';
    }
}

void dialog_2::on_pbtn_num5_clicked()
{
    if(btn_passwd_pos>=MAX_PASSWD_LEN)
    {
        btn_passwd_pos=MAX_PASSWD_LEN;
    }else{
        btn_passwd[btn_passwd_pos++]='5';
    }
}

void dialog_2::on_pbtn_num6_clicked()
{
    if(btn_passwd_pos>=MAX_PASSWD_LEN)
    {
        btn_passwd_pos=MAX_PASSWD_LEN;
    }else{
        btn_passwd[btn_passwd_pos++]='6';
    }
}

void dialog_2::on_pbtn_num7_clicked()
{

    if(btn_passwd_pos>=MAX_PASSWD_LEN)
    {
        btn_passwd_pos=MAX_PASSWD_LEN;
    }else{
        btn_passwd[btn_passwd_pos++]='7';
    }
}

void dialog_2::on_pbtn_num8_clicked()
{
    if(btn_passwd_pos>=MAX_PASSWD_LEN)
    {
        btn_passwd_pos=MAX_PASSWD_LEN;
    }else{
        btn_passwd[btn_passwd_pos++]='8';
    }
}

void dialog_2::on_pbtn_num9_clicked()
{
    if(btn_passwd_pos>=MAX_PASSWD_LEN)
    {
        btn_passwd_pos=MAX_PASSWD_LEN;
    }else{
        btn_passwd[btn_passwd_pos++]='9';
    }
}

void dialog_2::on_pbtn_dot_clicked()
{
    if(btn_passwd_pos>=MAX_PASSWD_LEN)
    {
        btn_passwd_pos=MAX_PASSWD_LEN;
    }else{
        btn_passwd[btn_passwd_pos++]='.';
    }
}

void dialog_2::on_pbtn_back_clicked()
{
    if(btn_passwd_pos>0)
    {
        btn_passwd_pos--;
        btn_passwd[btn_passwd_pos]=0;
    }
    else
    {
        btn_passwd_pos=0;
    }
}

void dialog_2::on_pbtn_go_clicked()
{

    DebugMsg(hmilev,5,"on_pbtn_cancel_clicked\n");

    btn_passwd_pos=0;
    memset(btn_passwd,0,sizeof(btn_passwd));

    hmi_button_dn_num=CANCEL_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));
}


void dialog_2::on_pbtn_ok_clicked()
{

    DebugMsg(hmilev,5,"on_pbtn_enter_clicked\n");

    if(btn_passwd_pos==0)
    {
        jump_num=6;
      // ErrMsg("hmi_page_index error[%d]\n",0);
       // return;
    }
    else if(btn_passwd_pos<6)
    {
        jump_num=8;
        btn_passwd_pos=0;
        memset(btn_passwd,0,sizeof(btn_passwd));
      // ErrMsg("hmi_page_index error[%d]\n",0);
       // return;
    }
    else
    {
    //    API_Read_DB_Nbyte(PL_CHRPASSWRDERR_FLAG,(UINT8 *)(&num_add),sizeof(num_add));

        jump_num=7;
        enter_clc=TRUE;

        API_Write_DB_Nbyte(PL_HMI_CARD_PASSWD,(INT8 *)(&btn_passwd),sizeof(btn_passwd));

        hmi_button_dn_num=OK_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));
    }
}
