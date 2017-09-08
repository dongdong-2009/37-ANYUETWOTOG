#ifndef P16_SETPARA_SUB3_DIALOG_H
#define P16_SETPARA_SUB3_DIALOG_H

#include <QDialog>

namespace Ui {
    class p16_setpara_sub3_dialog;
}

class p16_setpara_sub3_dialog : public QDialog {
    Q_OBJECT
public:
    p16_setpara_sub3_dialog(QWidget *parent = 0);
    ~p16_setpara_sub3_dialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::p16_setpara_sub3_dialog *ui;

private:
        QTimer *timer;

private:
    unsigned char btn_devwd_len;
    char btn_devwd[25];
    unsigned char source_len;
    char source[25];
    unsigned char soft_len;
    char soft[25];
    unsigned char cost_len;
    char cost[25];

    int net_check;
    int line_check;
    int hand_check;



private slots:
    void btn_press(void);
    void on_start_btn_clicked();
    void on_cancle_btn_clicked();
    void on_wifi_btn_clicked();
    void on_online_btn_clicked();

    void on_yidong_btn_clicked();
    void on_liantong_btn_clicked();
    void on_dianxin_btn_clicked();

    void  on_btn_hand_on_clicked();
    void  on_btn_hand_off_clicked();

    //void on_pbtn_enter_clicked();
    void on_pbtn_down_clicked();
    void on_pbtn_up_clicked();
    void on_pbtn_ok_clicked();
    void on_pbtn_go_clicked();
   // void on_pbtn_cancel_clicked();
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
//    void on_btn_2_clicked();
    void on_btn_3_clicked();
    void on_btn_4_clicked();
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
    void call_p17_dlg(void);


signals:
    void signal_enable_p17dlg_timer();
    void signal_timer_p16dlg();
     void signal_enable_p15dlg_timer();
    void signal_exit_p16dlg();
};

#endif // P16_SETPARA_SUB3_DIALOG_H
