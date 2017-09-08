#ifndef P17_SETPARA_SUB4_DIALOG_H
#define P17_SETPARA_SUB4_DIALOG_H

#include <QDialog>

namespace Ui {
    class p17_setpara_sub4_dialog;
}

class p17_setpara_sub4_dialog : public QDialog {
    Q_OBJECT
public:
    p17_setpara_sub4_dialog(QWidget *parent = 0);
    ~p17_setpara_sub4_dialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::p17_setpara_sub4_dialog *ui;

private:
        QTimer *timer;

private:
    void update_page_info(void);
    void update_hmi_page_index(void);

    unsigned char maxv_len;
    char maxv[25];
    float fmaxv;

    unsigned char maxi_len;
    char maxi[25];
    float fmaxi;

    unsigned char cost_len;
    char cost[25];
    float fcost;

    unsigned char cost_len_serv;
    char cost_serv[25];
    float fcost_serv;

    unsigned char ac_len;
    char ac[25];
    float fac;

    unsigned char meter_rate_len;
    char meter_rate[25];
    int meter_rate_num;

    unsigned char moudle_sum_len;
    char moudle_sum[25];
    int moudle_sum_num;

    unsigned char moudle_cur_len;
    char moudle_cur[25];
    int moudle_cur_num;

    unsigned char websize_len;
    char websize[25];

private slots:
    void init_page_dlg(void);
    void init_page_val(void);
    void start_timer(void);
    void timer_handle(void);
    void exit_page_dlg(void);
    void btn_press(void);

   // void on_pbtn_enter_clicked();
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

    void on_pbtn_1_clicked();
    void on_pbtn_2_clicked();
    void on_pbtn_3_clicked();
    void on_pbtn_4_clicked();
    void on_pbtn_5_clicked();
    void on_pbtn_6_clicked();
    void on_pbtn_7_clicked();
    void on_pbtn_8_clicked();
    void call_p16_dlg(void);
    void call_p18_dlg(void);
    void call_p24_dlg(void);

signals:
    void signal_enable_p24dlg_timer();
    void signal_enable_p18dlg_timer();
    void signal_exit_p17dlg();
    void signal_timer_p17dlg();

};

#endif // P17_SETPARA_SUB4_DIALOG_H
