#ifndef P01_PASSWD_DIALOG_H
#define P01_PASSWD_DIALOG_H

#include <QDialog>

namespace Ui {
    class p01_passwd_dialog;
}

class p01_passwd_dialog : public QDialog {
    Q_OBJECT
public:
    p01_passwd_dialog(QWidget *parent = 0);
    ~p01_passwd_dialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::p01_passwd_dialog *ui;


private:
        QTimer *timer;

private slots:
    void init_page_dlg(void);
    void init_page_val(void);
    void start_timer(void);
    void timer_handle(void);
    void exit_page_dlg(void);
    void btn_press(void);

private:
    unsigned char btn_passwd_pos;
    char btn_passwd[9];
    char btn_passwd_disp[9];
private:
    void update_page_info(void);
    void update_hmi_page_index(void);
    void call_p02_dlg(void);
    void call_dlg_gun();
 //   void call_dlg_1(void);

private slots:
    void on_pbtn_ok_clicked();
    void on_pbtn_go_clicked();

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

signals:
    void signal_enable_maindlg_timer();
    void signal_enable_p02dlg_timer();
    void signal_enable_dlg_gun_timer();
 //   void signal_enable_dlg_1_timer();
    void signal_exit_p01dlg();
};

#endif // P01_PASSWD_DIALOG_H
