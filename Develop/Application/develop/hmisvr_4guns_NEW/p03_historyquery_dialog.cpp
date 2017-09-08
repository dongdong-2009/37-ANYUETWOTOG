#include "p03_historyquery_dialog.h"
#include "ui_p03_historyquery_dialog.h"
#include "globalhmi.h"
#include <string.h>


p03_historyquery_dialog::p03_historyquery_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p03_historyquery_dialog)
{
    ui->setupUi(this);
}

p03_historyquery_dialog::~p03_historyquery_dialog()
{
    delete ui;
}

void p03_historyquery_dialog::changeEvent(QEvent *e)
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


void p03_historyquery_dialog::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(PAGE_FLUSH_TIMER);
    init_page_val();
    ui->label_code->setText(code);

    if(language_num == 1)
    {
         // ui->label_logo->setText(QString::fromUtf8("直 流 充 电 桩"));
          ui->label_stubnum->setText(QString::fromUtf8(" 桩   编   号  :"));
          ui->pbtn_enter->setText(QString::fromUtf8("返       回"));
    }
    else  if(language_num == 2)
    {
          //ui->label_logo->setText("DC charging pile");
          ui->label_stubnum->setText("Pile Number :");
          ui->pbtn_enter->setText("Back");
    }

  //  ui->label_phone->setText(phonenum);
 //   ui->label_phone_2->setText(phonenum_2);
}

struct _historyinfor
{
    //鐢ㄦ埛ID
    short  UerID;//BYTE=2
    //鎸囦护搴忓垪
    short  CMD_Serail;//BYTE=2
    //unsigned char  HistoryCheckCount;
    unsigned int  RecordIndex;
    unsigned char StubIndex[8];
    unsigned char  CardNumber[16];
    unsigned char Car_VIN[17];//if no,fill it with space
    unsigned char Car_plate[8];
    unsigned char Start_Soc;
    unsigned char Stop_Soc;
    short UseCapa;//an*hour
    short Use_kwh;
    unsigned int chargecontinuetm;//sec
    unsigned char DealType;
    unsigned char Stop_Reason;
    SYNCHRO_TIME_S Startcharge_TM;
    SYNCHRO_TIME_S Stopcharge_TM;
    //SYNCHRO_TIME_S DealTime;
    unsigned int   Start_KWH;
    unsigned int   Stop_KWH;
};

int HistoryAnanisis_show(const char *file_name, struct _historyinfor  *p_cmd_code_0x92OutPt,int maxindex)
{
    unsigned char linedatabuf[MAXCHAROFPERONELINE];
    FILE *fp_file;
    //char *file_name="/home/Development/Application/develop/test_hislog.txt";
    //char *file_name="/usr/data/history.txt";
    //total pos for each line
    unsigned  int startpos=0;
    //one line total len
    unsigned  int  readLen=0;

    //singal for each split
    unsigned  int Sectionindex=0;
    //store the char for each split
    unsigned char SectionBuf[50];
    //pos for each split
    unsigned  int  SectiondataPos=0;

    //flag for getting the start index of history
    //unsigned  int  startInsertFlag=0;
       //insert history count
    unsigned  int  TempHistoryInsertCount=0;
    struct _historyinfor tempHistoryRecord ;
    int tempcount=0;
    int linetotal=0;
    fp_file = fopen(file_name, "r");
    if(fp_file ==0)//open file error
    {
        printf("open historyfile eeror\r\n");
        return 0;
    }
    else
    {
        printf("open historyfileshow success\r\n");
    }
    if(p_cmd_code_0x92OutPt==NULL)
    {
        fclose(fp_file);
        return 0;
    }
    memset(linedatabuf,0,MAXCHAROFPERONELINE);
    TempHistoryInsertCount=0;
      //  while (fgets((char *)linedatabuf, sizeof(linedatabuf), fp_file))
    while (!feof(fp_file))
    {
        fgets((char *)linedatabuf, sizeof(linedatabuf), fp_file);
        if(feof(fp_file))
        {
                     //at the end of file ,stopping get historyrecord

            break;
        }

        readLen=strlen((char *)linedatabuf);
        if(readLen<=3)
        {
            continue;
        }


        //please tar the string buf for your struct
        //tile of the text
        printf("####read linenumber=%d,%s\r\n",linetotal,linedatabuf);
        if( linedatabuf[startpos]=='i'&& linedatabuf[startpos+1]=='d'&&linedatabuf[startpos+2]=='x')
        {
            continue;
        }
        if( linedatabuf[startpos]=='#'&& linedatabuf[startpos+1]=='#'&&linedatabuf[startpos+2]=='#')
        {
            continue;
        }
           linetotal++;

        memset(SectionBuf,0,50);
        Sectionindex=0;
        SectiondataPos=0;
        for(startpos=0;startpos<readLen;startpos++)
        {

            if(linedatabuf[startpos]==0x0d||linedatabuf[startpos]==0x0a)
            {
                //break;
                continue;
            }
            if(linedatabuf[startpos]==0x7c)//"|"
            {
                     // printf("1111111111111\r\n");
                if(Sectionindex==0)//record index
                {

                }//end of if(Sectionindex==0)//record index

                else if(Sectionindex==1)//stub code
                {
                    memcpy(&tempHistoryRecord.StubIndex,SectionBuf,sizeof(tempHistoryRecord.StubIndex));
                }
                else if(Sectionindex==2)//card number
                {
                       memcpy(&tempHistoryRecord.CardNumber,SectionBuf,sizeof(tempHistoryRecord.CardNumber));
                }
                else if(Sectionindex==3)//Car_VIN
                {
                    memcpy(&tempHistoryRecord.Car_VIN,SectionBuf,sizeof(tempHistoryRecord.Car_VIN));
                }
                else if(Sectionindex==4)//Car_plate
                {
                    memcpy(&tempHistoryRecord.Car_plate,SectionBuf,sizeof(tempHistoryRecord.Car_plate));
                }
                else if(Sectionindex==5)//Start_Soc
                {
                    tempHistoryRecord.Start_Soc=atoi((char *)SectionBuf);
                }
                else if(Sectionindex==6)//Stop_Soc
                {
                      tempHistoryRecord.Stop_Soc=atoi((char *)SectionBuf);
                }
                else if(Sectionindex==7)//UseCapa
                {
                       tempHistoryRecord.UseCapa=atoi((char *)SectionBuf);
                }
                else if(Sectionindex==8)//Use_kwh
                {
                       tempHistoryRecord.Use_kwh=atoi((char *)SectionBuf);
                }
                else if(Sectionindex==9)//chargecontinuetm
                {
                    tempHistoryRecord.chargecontinuetm=atoi((char *)SectionBuf);
                }
                else if(Sectionindex==10)//DealType
                {
                    tempHistoryRecord.DealType=atoi((char *)SectionBuf);
                }
                else if(Sectionindex==11)//Stop_Reason
                {
                    tempHistoryRecord.Stop_Reason=atoi((char *)SectionBuf);
                }
                else if(Sectionindex==12)//Startcharge_TM
                {
                    strcat((char *)SectionBuf,"-");
                    TimeAnanisis(&tempHistoryRecord.Startcharge_TM,SectionBuf);
                }
                else if(Sectionindex==13)//Stopcharge_TM
                {
                    strcat((char *)SectionBuf,"-");
                    TimeAnanisis(&tempHistoryRecord.Stopcharge_TM,SectionBuf);
                }
                else if(Sectionindex==14)//Start_KWH
                {
                    tempHistoryRecord.Start_KWH=atoi((char *)SectionBuf);
                }
                else if(Sectionindex==15)//Stop_KWH
                {
                    tempHistoryRecord.Stop_KWH=atoi((char *)SectionBuf);
                }
                memset(SectionBuf,0,50);
                SectiondataPos=0;
                Sectionindex++;
                continue;
            }//end of if(linedatabuf[startpos]==0x7c)//"|"
            else//end of if(linedatabuf[startpos]==0x7c)//"|"
            {
	              if(SectiondataPos<50)
	                {
	     					SectionBuf[SectiondataPos++]=linedatabuf[startpos];
	                }
            }
       }//end of for(startpos=0;startpos<readLen;startpos++)
        Sectionindex=0;
        memset(linedatabuf,0,MAXCHAROFPERONELINE);
        //if(startInsertFlag==1&&tempHistoryRecord.RecordIndex!=0&&HistoryInsertCount<MAXHISTORYRETURNCOUNT)//start insert history
        if(TempHistoryInsertCount<maxindex)//start insert history
        {
                  if(strncmp((char *)(tempHistoryRecord.CardNumber),main_card_sn,16)==0)
                  {
                  //     ErrMsg("$$$$$$$$$$$$$$$$$$\n");
                        memcpy(&p_cmd_code_0x92OutPt[TempHistoryInsertCount],&tempHistoryRecord,sizeof(struct _historyinfor));
                        p_cmd_code_0x92OutPt[TempHistoryInsertCount].RecordIndex=linetotal;
                        TempHistoryInsertCount++;
                  }


        }//end of  if(startInsertFlag==1)//start insert history
        else
        {
            break;
        }
        memset(&tempHistoryRecord,0,sizeof(struct _historyinfor));

    }//end of  while (fgets(linedatabuf, sizeof(linedatabuf), fp_file))
    fclose(fp_file);
    return TempHistoryInsertCount;
}


struct _historyinfor history_buf[30];
int sum=0;
void p03_historyquery_dialog::init_page_val()
{
        UINT8 data = NO_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));

         memset(lbl_txt,0,sizeof(lbl_txt));
         memset(lbl_txt_2,0,sizeof(lbl_txt_2));
         memset(lbl_txt_3,0,sizeof(lbl_txt_3));
         memset(lbl_txt_4,0,sizeof(lbl_txt_4));
         memset(lbl_txt_5,0,sizeof(lbl_txt_5));

        memset(history_buf,0,sizeof(history_buf));
        sum=HistoryAnanisis_show(history_path, history_buf,30);

             lbl_num=1;
             lbl_num_2=2;
             lbl_num_3=3;
             lbl_num_4=4;
             lbl_num_5=5;

            memcpy(lbl_txt, history_buf[0].CardNumber,sizeof(history_buf[0].CardNumber));
            memcpy(lbl_txt_2, history_buf[1].CardNumber,sizeof(history_buf[1].CardNumber));
            memcpy(lbl_txt_3, history_buf[2].CardNumber,sizeof(history_buf[2].CardNumber));
            memcpy(lbl_txt_4, history_buf[3].CardNumber,sizeof(history_buf[3].CardNumber));
            memcpy(lbl_txt_5, history_buf[4].CardNumber,sizeof(history_buf[4].CardNumber));

            start=history_buf[0].Start_Soc;
            start_2= history_buf[1].Start_Soc;
            start_3= history_buf[2].Start_Soc;
            start_4= history_buf[3].Start_Soc;
            start_5= history_buf[4].Start_Soc;

            end= history_buf[0].Stop_Soc;
            end_2= history_buf[1].Stop_Soc;
            end_3= history_buf[2].Stop_Soc;
            end_4= history_buf[3].Stop_Soc;
            end_5= history_buf[4].Stop_Soc;

            meter= (float)history_buf[0].Use_kwh/1000;
            meter_2= (float)history_buf[1].Use_kwh/1000;
            meter_3= (float)history_buf[2].Use_kwh/1000;
            meter_4= (float)history_buf[3].Use_kwh/1000;
            meter_5= (float)history_buf[4].Use_kwh/1000;

            chtime= history_buf[0].chargecontinuetm/60;
            chtime_2= history_buf[1].chargecontinuetm/60;
            chtime_3= history_buf[2].chargecontinuetm/60;
            chtime_4= history_buf[3].chargecontinuetm/60;
            chtime_5= history_buf[4].chargecontinuetm/60;

}

void p03_historyquery_dialog::start_timer()
{
    timer->start(PAGE_FLUSH_TIMER);
}


void p03_historyquery_dialog::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}



char *itoa(int num,char*str)
{
    memset(str,0,sizeof(str));
    if(num==0)
    {
       // memset(str,0,sizeof(str));
    }
    else
    {
        sprintf(str,"%d",num);
    }
    return str;
}

char * itob(float num,char*str)
{
    memset(str,0,sizeof(str));
    if(num==0)
    {
       // memset(str,0,sizeof(str));
    }
    else
    {
        sprintf(str,"%.2f",num);
    }
    return str;
}

void p03_historyquery_dialog::update_page_info()
{
    ui->label_txt->setText(QString::fromUtf8(lbl_txt));
    ui->label_txt_2->setText(QString::fromUtf8(lbl_txt_2));
    ui->label_txt_3->setText(QString::fromUtf8(lbl_txt_3));
    ui->label_txt_4->setText(QString::fromUtf8(lbl_txt_4));
    ui->label_txt_5->setText(QString::fromUtf8(lbl_txt_5));


    char ttemp[50]={};

    ui->label_end->setText(itoa(end,ttemp));
    ui->label_end_2->setText(itoa(end_2,ttemp));
    ui->label_end_3->setText(itoa(end_3,ttemp));
    ui->label_end_4->setText(itoa(end_4,ttemp));
    ui->label_end_5->setText(itoa(end_5,ttemp));

    ui->label_start->setText(itoa(start,ttemp));
    ui->label_start_2->setText(itoa(start_2,ttemp));
    ui->label_start_3->setText(itoa(start_3,ttemp));
    ui->label_start_4->setText(itoa(start_4,ttemp));
    ui->label_start_5->setText(itoa(start_5,ttemp));

    if(chtime==0&&lbl_txt[0])
    {
        ui->label_time->setNum(0);
    }
    else
    {
        ui->label_time->setText(itoa(chtime,ttemp));
    }

    if(chtime_2==0&&lbl_txt_2[0])
    {
        ui->label_time_2->setNum(0);
    }
    else
    {
        ui->label_time_2->setText(itoa(chtime_2,ttemp));
    }

    if(chtime_3==0&&lbl_txt_3[0])
    {
        ui->label_time_3->setNum(0);
    }
    else
    {
        ui->label_time_3->setText(itoa(chtime_3,ttemp));
    }

    if(chtime_4==0&&lbl_txt_4[0])
    {
        ui->label_time_4->setNum(0);
    }
    else
    {
        ui->label_time_4->setText(itoa(chtime_4,ttemp));
    }

    if(chtime_5==0&&lbl_txt_5[0])
    {
        ui->label_time_5->setNum(0);
    }
    else
    {
        ui->label_time_5->setText(itoa(chtime_5,ttemp));
    }


    if(meter==0&&lbl_txt[0])
    {
        ui->label_meter->setNum(0);
    }
    else
    {
        ui->label_meter->setText(itob(meter,ttemp));
    }

    if(meter_2==0&&lbl_txt_2[0])
    {
        ui->label_meter_2->setNum(0);
    }
    else
    {
        ui->label_meter_2->setText(itob(meter_2,ttemp));
    }

    if(meter_3==0&&lbl_txt_3[0])
    {
        ui->label_meter_3->setNum(0);
    }
    else
    {
      ui->label_meter_3->setText(itob(meter_3,ttemp));
    }

    if(meter_4==0&&lbl_txt_4[0])
    {
        ui->label_meter_4->setNum(0);
    }
    else
    {
        ui->label_meter_4->setText(itob(meter_4,ttemp));
    }

    if(meter_5==0&&lbl_txt_5[0])
    {
        ui->label_meter_5->setNum(0);
    }
    else
    {
         ui->label_meter_5->setText(itob(meter_5,ttemp));
    }


    if(lbl_txt[0])
    {
         ui->label_num->setNum(lbl_num);
    }
    else
    {
         ui->label_num->setText(NULL);
    }

    if(lbl_txt_2[0])
    {
       ui->label_num_2->setNum(lbl_num_2);
    }
    else
    {
        ui->label_num_2->setText(NULL);
    }

    if(lbl_txt_3[0])
    {
         ui->label_num_3->setNum(lbl_num_3);
    }
    else
    {
         ui->label_num_3->setText(NULL);
    }

    if(lbl_txt_4[0])
    {
        ui->label_num_4->setNum(lbl_num_4);
    }
    else
    {
         ui->label_num_4->setText(NULL);
    }

    if(lbl_txt_5[0])
    {
       ui->label_num_5->setNum(lbl_num_5);
    }
    else
    {
         ui->label_num_5->setText(NULL);
    }

}

void p03_historyquery_dialog::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
    if(hmi_page_index != PAGEINDEX_HISTORYCHECK)
    {
        exit_page_dlg();
    }
    else
    {

    }
}

void p03_historyquery_dialog::exit_page_dlg()
{
  //  DebugMsg(hmilev,8,"exit_page_dlg\n");

    UINT8 data = NO_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));

   // ErrMsg("$$$ leave history page $$$\n");

    timer->stop();
    emit signal_exit_p03dlg();
    //delete p03_dlg;
    //p03_dlg = NULL;
}

void p03_historyquery_dialog::on_pbtn_up_clicked()
{
        if(lbl_num-5>0)
     {
             lbl_num=lbl_num-5;
             lbl_num_2=lbl_num_2-5;
             lbl_num_3=lbl_num_3-5;
             lbl_num_4=lbl_num_4-5;
             lbl_num_5=lbl_num_5-5;

            start=history_buf[lbl_num-1].Start_Soc;
            start_2= history_buf[lbl_num_2-1].Start_Soc;
            start_3= history_buf[lbl_num_3-1].Start_Soc;
            start_4= history_buf[lbl_num_4-1].Start_Soc;
            start_5= history_buf[lbl_num_5-1].Start_Soc;

            end= history_buf[lbl_num-1].Stop_Soc;
            end_2= history_buf[lbl_num_2-1].Stop_Soc;
            end_3= history_buf[lbl_num_3-1].Stop_Soc;
            end_4= history_buf[lbl_num_4-1].Stop_Soc;
            end_5= history_buf[lbl_num_5-1].Stop_Soc;

            meter= (float)history_buf[lbl_num-1].Use_kwh/1000;
            meter_2= (float)history_buf[lbl_num_2-1].Use_kwh/1000;
            meter_3= (float)history_buf[lbl_num_3-1].Use_kwh/1000;
            meter_4= (float)history_buf[lbl_num_4-1].Use_kwh/1000;
            meter_5= (float)history_buf[lbl_num_5-1].Use_kwh/1000;

            chtime= history_buf[lbl_num-1].chargecontinuetm/60;
            chtime_2= history_buf[lbl_num_2-1].chargecontinuetm/60;
            chtime_3= history_buf[lbl_num_3-1].chargecontinuetm/60;
            chtime_4= history_buf[lbl_num_4-1].chargecontinuetm/60;
            chtime_5= history_buf[lbl_num_5-1].chargecontinuetm/60;


            memcpy(lbl_txt, history_buf[lbl_num-1].CardNumber,sizeof(history_buf[lbl_num-1].CardNumber));
            memcpy(lbl_txt_2, history_buf[lbl_num_2-1].CardNumber,sizeof(history_buf[lbl_num-2].CardNumber));
            memcpy(lbl_txt_3, history_buf[lbl_num_3-1].CardNumber,sizeof(history_buf[lbl_num-3].CardNumber));
            memcpy(lbl_txt_4, history_buf[lbl_num_4-1].CardNumber,sizeof(history_buf[lbl_num-4].CardNumber));
            memcpy(lbl_txt_5, history_buf[lbl_num_5-1].CardNumber,sizeof(history_buf[lbl_num-5].CardNumber));
    }
     else
     {

     }
}

void p03_historyquery_dialog::on_pbtn_down_clicked()
{
   // ErrMsg("hmi_page_index error[%d]\n",sum);
     if(lbl_num+5<sum+1)
     {
             lbl_num=lbl_num+5;
             lbl_num_2=lbl_num_2+5;
             lbl_num_3= lbl_num_3+5;
             lbl_num_4=lbl_num_4+5;
             lbl_num_5=lbl_num_5+5;

            start=history_buf[lbl_num-1].Start_Soc;
            start_2= history_buf[lbl_num_2-1].Start_Soc;
            start_3= history_buf[lbl_num_3-1].Start_Soc;
            start_4= history_buf[lbl_num_4-1].Start_Soc;
            start_5= history_buf[lbl_num_5-1].Start_Soc;

            end= history_buf[lbl_num-1].Stop_Soc;
            end_2= history_buf[lbl_num_2-1].Stop_Soc;
            end_3= history_buf[lbl_num_3-1].Stop_Soc;
            end_4= history_buf[lbl_num_4-1].Stop_Soc;
            end_5= history_buf[lbl_num_5-1].Stop_Soc;

            meter= (float)history_buf[lbl_num-1].Use_kwh/1000;
            meter_2= (float)history_buf[lbl_num_2-1].Use_kwh/1000;
            meter_3= (float)history_buf[lbl_num_3-1].Use_kwh/1000;
            meter_4= (float)history_buf[lbl_num_4-1].Use_kwh/1000;
            meter_5= (float)history_buf[lbl_num_5-1].Use_kwh/1000;

            chtime= history_buf[lbl_num-1].chargecontinuetm/60;
            chtime_2= history_buf[lbl_num_2-1].chargecontinuetm/60;
            chtime_3= history_buf[lbl_num_3-1].chargecontinuetm/60;
            chtime_4= history_buf[lbl_num_4-1].chargecontinuetm/60;
            chtime_5= history_buf[lbl_num_5-1].chargecontinuetm/60;

            memcpy(lbl_txt, history_buf[lbl_num-1].CardNumber,sizeof(history_buf[lbl_num-1].CardNumber));
            memcpy(lbl_txt_2, history_buf[lbl_num_2-1].CardNumber,sizeof(history_buf[lbl_num-2].CardNumber));
            memcpy(lbl_txt_3, history_buf[lbl_num_3-1].CardNumber,sizeof(history_buf[lbl_num-3].CardNumber));
            memcpy(lbl_txt_4, history_buf[lbl_num_4-1].CardNumber,sizeof(history_buf[lbl_num-4].CardNumber));
            memcpy(lbl_txt_5, history_buf[lbl_num_5-1].CardNumber,sizeof(history_buf[lbl_num-5].CardNumber));

    }
     else
     {

     }
}

void p03_historyquery_dialog::on_pbtn_enter_clicked()
{


    hmi_button_dn_num=OK_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));
}

