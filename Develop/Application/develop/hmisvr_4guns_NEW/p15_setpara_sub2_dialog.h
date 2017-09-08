#ifndef P15_SETPARA_SUB2_DIALOG_H
#define P15_SETPARA_SUB2_DIALOG_H

#include <QDialog>

namespace Ui {
    class p15_setpara_sub2_dialog;
}

class p15_setpara_sub2_dialog : public QDialog {
    Q_OBJECT
public:
    p15_setpara_sub2_dialog(QWidget *parent = 0);
    ~p15_setpara_sub2_dialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::p15_setpara_sub2_dialog *ui;

private:
        QTimer *timer;
      //  bool eventFilter(QObject *target,QEvent *event);

private:
    unsigned char farip_len;
    char farip[25];
    unsigned char localip_len;
    char localip[25];
    unsigned char art_len;
    char art[25];
    unsigned char guan_len;
    char guan[25];
    unsigned char ma_len;
    char ma[25];
    unsigned char mac_len;
    char mac[25];

private slots:
     void btn_press(void);
   // void on_pbtn_enter_clicked();
    void on_pbtn_down_clicked();
    void on_pbtn_up_clicked();
    void on_pbtn_ok_clicked();
    void on_pbtn_go_clicked();
  //  void on_pbtn_cancel_clicked();

     void on_pbtn_back_clicked();
    void on_pbtn_dot_clicked();
    void on_pbtn_num0_clicked();
    void on_pbtn_num9_clicked();
    void on_pbtn_num8_clicked();
    void on_pbtn_num7_clicked();
    void on_pbtn_num6_clicked();
    void on_pbtn_num5_clicked();
    void on_pbtn_num4_clicked();
    void on_pbtn_num3_clicked();
    void on_pbtn_num2_clicked();
    void on_pbtn_num1_clicked();
    void on_btn_1_clicked();
    void on_btn_3_clicked();
    void on_btn_4_clicked();
    void on_btn_5_clicked();
    void on_btn_6_clicked();
    void on_btn_7_clicked();

private:
    void update_page_info(void);
    void update_hmi_page_index(void);

private slots:
    void init_page_dlg(void);
    void init_page_val(void);
    void start_timer(void);
    void timer_handle(void);
    void exit_page_dlg(void);
    void call_p16_dlg(void);
    void call_p14_dlg(void);


signals:
    void signal_enable_p16dlg_timer();
    void signal_enable_p14dlg_timer();
    void signal_timer_p15dlg();
    void signal_exit_p15dlg();

};

#endif // P15_SETPARA_SUB2_DIALOG_H
