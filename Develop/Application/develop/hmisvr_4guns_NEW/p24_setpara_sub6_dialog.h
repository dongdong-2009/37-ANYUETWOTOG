#ifndef P24_SETPARA_SUB6_DIALOG_H
#define P24_SETPARA_SUB6_DIALOG_H

#include <QDialog>

namespace Ui {
class p24_setpara_sub6_dialog;
}

class p24_setpara_sub6_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit p24_setpara_sub6_dialog(QWidget *parent = 0);
    ~p24_setpara_sub6_dialog();

private:
    Ui::p24_setpara_sub6_dialog *ui;

protected:
    void changeEvent(QEvent *e);

private:
        QTimer *timer;

private:
    void update_page_info(void);
    void update_hmi_page_index(void);

    unsigned char t1_len;
    char t1[8];
    float ft1;

    unsigned char p1_len;
    char p1[8];
    float fp1;

    unsigned char f1_len;
    char f1[8];
    float ff1;

    unsigned char g1_len;
    char g1[8];
    float fg1;

    unsigned char t2_len;
    char t2[8];
    float ft2;

    unsigned char p2_len;
    char p2[8];
    float fp2;

    unsigned char f2_len;
    char f2[8];
    float ff2;

    unsigned char g2_len;
    char g2[8];
    float fg2;

    unsigned char t1_len_1;
    char t1_1[8];
    float ft1_1;

    unsigned char t1_len_2;
    char t1_2[8];
    float ft1_2;

    unsigned char p1_len_1;
    char p1_1[8];
    float fp1_1;

    unsigned char p1_len_2;
    char p1_2[8];
    float fp1_2;

    unsigned char f1_len_1;
    char f1_1[8];
    float ff1_1;

    unsigned char f1_len_2;
    char f1_2[8];
    float ff1_2;

    unsigned char g1_len_1;
    char g1_1[8];
    float fg1_1;

    unsigned char g1_len_2;
    char g1_2[8];
    float fg1_2;


    unsigned char t2_len_1;
    char t2_1[8];
    float ft2_1;

    unsigned char t2_len_2;
    char t2_2[8];
    float ft2_2;

    unsigned char p2_len_1;
    char p2_1[8];
    float fp2_1;

    unsigned char p2_len_2;
    char p2_2[8];
    float fp2_2;

    unsigned char f2_len_1;
    char f2_1[8];
    float ff2_1;

    unsigned char f2_len_2;
    char f2_2[8];
    float ff2_2;

    unsigned char g2_len_1;
    char g2_1[8];
    float fg2_1;

    unsigned char g2_len_2;
    char g2_2[8];
    float fg2_2;


private slots:
    void init_page_dlg(void);
    void init_page_val(void);
    void start_timer(void);
    void timer_handle(void);
    void exit_page_dlg(void);
    void btn_press(void);


    void on_pbtn_down_clicked();
    void on_pbtn_up_clicked();
    void on_pbtn_ok_clicked();
    void on_pbtn_cancel_clicked();
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

    void on_pbtn_enter_clicked();
    void call_p17_dlg(void);
    void call_p18_dlg(void);

signals:
    void signal_enable_p18dlg_timer();
    void signal_exit_p24dlg();
    void signal_timer_p24dlg();

protected:
    bool eventFilter(QObject *obj, QEvent *event);
};

#endif // P24_SETPARA_SUB6_DIALOG_H
