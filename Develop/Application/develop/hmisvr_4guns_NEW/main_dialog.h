#ifndef MAIN_DIALOG_H
#define MAIN_DIALOG_H

#include <QDialog>

namespace Ui {
    class main_dialog;
}

class main_dialog : public QDialog {
    Q_OBJECT
public:
    main_dialog(QWidget *parent = 0);
    ~main_dialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::main_dialog *ui;
    QTimer *timer;
    void init_main_dlg(void);
    void init_database(void);
    void call_p01_dlg(void);
    void call_p07_dlg(void);
    void call_p08_dlg(void);
    void call_p09_dlg(void);
    void call_p11_dlg();
    void call_p12_dlg();
    void call_p13_dlg(void);
    void call_p14_dlg(void);
    void call_p15_dlg(void);
    void call_p16_dlg(void);
    void call_p17_dlg(void);
    void call_p18_dlg(void);
    void call_p24_dlg(void);
    void call_dlg_info();
    void call_dlg_gun();
    void call_dlg_stop();
     void call_dlg_err();
     void call_diff_card_dlg();
    void check_hmi_page_index(void);
    float ft1;
    float ft2;
    float fp1;
    float fp2;
    float ff1;
    float ff2;
    float fg1;
    float fg2;
    float ft1_1;
    float ft2_1;
    float fp1_1;
    float fp2_1;
    float ff1_1;
    float ff2_1;
    float fg1_1;
    float fg2_1;

//    char phonenum[25];
//    char code[25];

private slots:
    void on_pbtn_language_clicked();
    void on_pbtn_setpara_clicked();
    void timer_handle(void);
    void start_timer(void);
    void on_pbtn_1_clicked();
    void on_pbtn_2_clicked();
    void on_pbtn_3_clicked();
    void on_pbtn_4_clicked();

signals:
    void signal_enable_p01dlg_timer();
    void signal_enable_p07dlg_timer();
    void signal_enable_p08dlg_timer();
    void signal_enable_p09dlg_timer();
    void signal_enable_p11dlg_timer();
    void signal_enable_p12dlg_timer();
    void signal_enable_p13dlg_timer();
    void signal_enable_p14dlg_timer();
    void signal_enable_p15dlg_timer();
    void signal_enable_p16dlg_timer();
    void signal_enable_p17dlg_timer();
    void signal_enable_p18dlg_timer();
    void signal_enable_p24dlg_timer();
    void signal_enable_dlg_info_timer();
    void signal_enable_dlg_gun_timer();
    void signal_enable_dlg_stop_timer();
    void signal_enable_err_timer();
    void signal_enable_diff_card_timer();
};

#endif // MAIN_DIALOG_H
