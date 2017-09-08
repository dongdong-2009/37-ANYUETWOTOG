#ifndef P03_HISTORYQUERY_DIALOG_H
#define P03_HISTORYQUERY_DIALOG_H

#include <QDialog>

namespace Ui {
    class p03_historyquery_dialog;
}

class p03_historyquery_dialog : public QDialog {
    Q_OBJECT
public:
    p03_historyquery_dialog(QWidget *parent = 0);
    ~p03_historyquery_dialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::p03_historyquery_dialog *ui;

private:
        QTimer *timer;

        int lbl_num;
        int lbl_num_2;
        int lbl_num_3;
        int lbl_num_4;
        int lbl_num_5;

        char lbl_txt[17];
        char lbl_txt_2[17];
        char lbl_txt_3[17];
        char lbl_txt_4[17];
        char lbl_txt_5[17];

        char start;
        char start_2;
        char start_3;
        char start_4;
        char start_5;

        char end;
        char end_2;
        char end_3;
        char end_4;
        char end_5;

        float meter;
        float meter_2;
        float meter_3;
        float meter_4;
        float meter_5;

        int chtime;
        int chtime_2;
        int chtime_3;
        int chtime_4;
        int chtime_5;

private:
    void update_page_info(void);
    void update_hmi_page_index(void);


private slots:
    void init_page_dlg(void);
    void init_page_val(void);
    void start_timer(void);
    void timer_handle(void);
    void exit_page_dlg(void);

private slots:
    void on_pbtn_enter_clicked();
    void on_pbtn_down_clicked();
    void on_pbtn_up_clicked();

signals:
    void signal_exit_p03dlg();
};

#endif // P03_HISTORYQUERY_DIALOG_H
