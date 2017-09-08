#ifndef P05_CHARGELINK_DIALOG_H
#define P05_CHARGELINK_DIALOG_H

#include <QDialog>

namespace Ui {
    class p05_chargelink_dialog;
}

class p05_chargelink_dialog : public QDialog {
    Q_OBJECT
public:
    p05_chargelink_dialog(QWidget *parent = 0);
    ~p05_chargelink_dialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::p05_chargelink_dialog *ui;

private:
        QTimer *timer;

private:
    void update_page_info(void);
    void update_hmi_page_index(void);

private slots:
    void init_page_dlg(void);
    void init_page_val(void);
    void start_timer(void);
    void timer_handle(void);
    void exit_page_dlg(void);
    void call_p06_dlg(void);
   // void call_dlg_1(void);

private slots:
    void on_pushButton_14_clicked();

signals:
    void signal_enable_p06dlg_timer();
    void signal_enable_dlg_1_timer();
    void signal_exit_p05dlg();
};

#endif // P05_CHARGELINK_DIALOG_H
