#ifndef DIALOG_HANDSET_H
#define DIALOG_HANDSET_H

#include <QDialog>

namespace Ui {
class Dialog_handset;
}

class Dialog_handset : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_handset(QWidget *parent = 0);
    ~Dialog_handset();

private:
    Ui::Dialog_handset *ui;

private:
        QTimer *timer;

        unsigned char volt_len;
        char volt[25];
        unsigned char current_len;
        char current[25];


private slots:
    void init_page_dlg(void);
    void init_page_val(void);
    void start_timer(void);
    void timer_handle(void);
    void exit_page_dlg(void);
    void btn_press();
    void on_pbtn_volt_clicked(void);
    void on_pbtn_current_clicked(void);

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
    void on_pbtn_go_clicked();
    void on_pbtn_ok_clicked();
    void call_p07_dlg();
    void call_p11_dlg();

private:
    void update_page_info(void);
    void update_hmi_page_index(void);

signals:
    void signal_enable_p11dlg_timer();
    void signal_timer_dlg();
    void signal_exit_dlg();
};

#endif // DIALOG_HANDSET_H
