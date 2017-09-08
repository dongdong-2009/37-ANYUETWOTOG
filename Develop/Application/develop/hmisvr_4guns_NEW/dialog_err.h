#ifndef Dialog_err_H
#define Dialog_err_H

#include <QDialog>

namespace Ui {
class Dialog_err;
}

class Dialog_err : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_err(QWidget *parent = 0);
    ~Dialog_err();

private:
    Ui::Dialog_err *ui;

private:
        QTimer *timer;

        int lbl_num;
        int lbl_num_2;
        int lbl_num_3;
        int lbl_num_4;
        int lbl_num_5;

        char lbl_txt[50];
        char lbl_txt_2[50];
        char lbl_txt_3[50];
        char lbl_txt_4[50];
        char lbl_txt_5[50];

private slots:
    void init_page_dlg(void);
    void init_page_val(void);
    void start_timer(void);
    void timer_handle(void);
    void exit_page_dlg(void);
    void on_pbtn_err_clicked(void);
    void on_pbtn_up_clicked(void);
    void on_pbtn_down_clicked(void);
    void on_pbtn_back_clicked(void);

private:
    void update_page_info(void);
    void update_hmi_page_index(void);

signals:

    void signal_exit_errdlg();
    void signal_exit_errdlg_link();
    void signal_exit_errdlg_charging();
    void signal_exit_errdlg_payoff();
    void signal_exit_errdlg_judge();
};

#endif // Dialog_err_H
