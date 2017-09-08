#ifndef P04_ALARMQUERY_DIALOG_H
#define P04_ALARMQUERY_DIALOG_H

#include <QDialog>

namespace Ui {
    class p04_alarmquery_dialog;
}

class p04_alarmquery_dialog : public QDialog {
    Q_OBJECT
public:
    p04_alarmquery_dialog(QWidget *parent = 0);
    ~p04_alarmquery_dialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::p04_alarmquery_dialog *ui;

private:
        QTimer *timer;
        int lbl_num;
        int lbl_num_2;
         int lbl_num_3;
          int lbl_num_4;
           int lbl_num_5;

        char lbl_txt[256];
         char lbl_txt_2[256];
          char lbl_txt_3[256];
           char lbl_txt_4[256];
            char lbl_txt_5[256];

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
    void signal_exit_p04dlg();
};

#endif // P04_ALARMQUERY_DIALOG_H
