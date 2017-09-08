#ifndef P18_CHOOSE_CHARGE_TYPE_H
#define P18_CHOOSE_CHARGE_TYPE_H

#include <QDialog>

namespace Ui {
class p18_choose_charge_type;
}

class p18_choose_charge_type : public QDialog
{
    Q_OBJECT
    
public:
    explicit p18_choose_charge_type(QWidget *parent = 0);
    ~p18_choose_charge_type();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::p18_choose_charge_type *ui;

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
    void call_p02_dlg(void);
    void call_p19_dlg(void);

    void on_pbtn_type_dc_clicked();

    void on_pbtn_type_ac_clicked();

signals:
    void signal_enable_p02dlg_timer();
    void signal_enable_p19dlg_timer();

    void signal_exit_p18dlg();
};

#endif // P18_CHOOSE_CHARGE_TYPE_H
