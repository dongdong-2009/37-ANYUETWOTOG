#ifndef P21_LEFTMONEY_DIALOG_H
#define P21_LEFTMONEY_DIALOG_H

#include <QDialog>

namespace Ui {
class p21_leftmoney_dialog;
}

class p21_leftmoney_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit p21_leftmoney_dialog(QWidget *parent = 0);
    ~p21_leftmoney_dialog();

private:
    Ui::p21_leftmoney_dialog *ui;

private:
        QTimer *timer;
private slots:
        void init_page_dlg(void);
        void init_page_val(void);
        void start_timer(void);
        void timer_handle(void);
        void exit_page_dlg(void);

private:
    void update_page_info(void);
    void update_hmi_page_index(void);

private slots:

    void on_pbtn_cancel_clicked();


signals:

    void signal_exit_p21dlg();
};

#endif // P21_LEFTMONEY_DIALOG_H
