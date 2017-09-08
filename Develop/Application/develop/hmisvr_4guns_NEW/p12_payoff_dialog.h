#ifndef P12_PAYOFF_DIALOG_H
#define P12_PAYOFF_DIALOG_H

#include <QDialog>

namespace Ui {
    class p12_payoff_dialog;
}

class p12_payoff_dialog : public QDialog {
    Q_OBJECT
public:
    p12_payoff_dialog(QWidget *parent = 0);
    ~p12_payoff_dialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::p12_payoff_dialog *ui;

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
   // void call_dlg_1(void);
    void on_pbtn_cancel_clicked();
  //  void on_pbtn_print_clicked();

signals:
    void signal_exit_p12dlg();
    void signal_enable_dlg_1_timer();
};

#endif // P12_PAYOFF_DIALOG_H
