#ifndef P10_CHARGEBYAUTO_DIALOG_H
#define P10_CHARGEBYAUTO_DIALOG_H

#include <QDialog>

namespace Ui {
    class p10_chargebyauto_dialog;
}

class p10_chargebyauto_dialog : public QDialog {
    Q_OBJECT
public:
    p10_chargebyauto_dialog(QWidget *parent = 0);
    ~p10_chargebyauto_dialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::p10_chargebyauto_dialog *ui;

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
    void call_p11_dlg(void);
signals:
    void signal_enable_p11dlg_timer();

    void signal_exit_p10dlg();

};

#endif // P10_CHARGEBYAUTO_DIALOG_H
