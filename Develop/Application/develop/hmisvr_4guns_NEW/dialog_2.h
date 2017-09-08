#ifndef DIALOG_2_H
#define DIALOG_2_H

#include <QDialog>

namespace Ui {
class dialog_2;
}

class dialog_2 : public QDialog
{
    Q_OBJECT
    
public:
    explicit dialog_2(QWidget *parent = 0);
    ~dialog_2();
    
private:
    Ui::dialog_2 *ui;

protected:
    void changeEvent(QEvent *e);

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
    void call_p19_dlg(void);
    void call_p11_dlg(void);
    void call_p12_dlg(void);
    void call_p20_dlg(void);
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
 //   void signal_enable_maindlg_timer();
//    void signal_enable_p02dlg_timer();
    void signal_enable_p12dlg_timer();
    void signal_enable_p20dlg_timer();
 //   void signal_enable_dlg_1_timer();
    void signal_exit_dlg_2();
    void signal_timer_dlg_2();

};

#endif // DIALOG_2_H
