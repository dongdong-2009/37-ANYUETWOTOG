#ifndef P14_SETPARA_SUB1_DIALOG_H
#define P14_SETPARA_SUB1_DIALOG_H

#include <QDialog>

namespace Ui {
    class p14_setpara_sub1_dialog;
}

class p14_setpara_sub1_dialog : public QDialog {
    Q_OBJECT
public:
    p14_setpara_sub1_dialog(QWidget *parent = 0);
    ~p14_setpara_sub1_dialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::p14_setpara_sub1_dialog *ui;

private:
        QTimer *timer;
      //  bool eventFilter(QObject *target,QEvent *event);


private:
    unsigned char phone_len;
    char phone[25];
    unsigned char time_len;
    char time[25];
    unsigned char stime_len;
    char stime[25];
    unsigned char pswd_len;
    char pswd[25];
    unsigned char pswd_sure_len;
    char pswd_sure[25];

private slots:
     void btn_press(void);
     void on_pbtn_dateout_clicked();
    void on_pbtn_setpoint_clicked();
    //void on_pbtn_enter_clicked();
    void on_pbtn_down_clicked();
    void on_pbtn_up_clicked();
    void on_pbtn_ok_clicked();
    void on_pbtn_go_clicked();
    //void on_pbtn_cancel_clicked();
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

    void on_btn_2_clicked();
    void on_btn_3_clicked();
    void on_btn_4_clicked();
    void on_btn_5_clicked();
    void on_btn_6_clicked();

private:
    void update_page_info(void);
    void update_hmi_page_index(void);

private slots:
    void init_page_dlg(void);
    void init_page_val(void);
    void start_timer(void);
    void timer_handle(void);
   void exit_page_dlg(void);
    void call_p15_dlg(void);


signals:
    void signal_enable_p15dlg_timer();

    void signal_exit_p14dlg();

};

#endif // P14_SETPARA_SUB1_DIALOG_H
