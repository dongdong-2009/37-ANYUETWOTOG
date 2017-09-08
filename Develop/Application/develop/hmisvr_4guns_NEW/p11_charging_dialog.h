#ifndef P11_CHARGING_DIALOG_H
#define P11_CHARGING_DIALOG_H

#include <QDialog>


namespace Ui {
    class p11_charging_dialog;
}

class p11_charging_dialog : public QDialog {
    Q_OBJECT
public:
    p11_charging_dialog(QWidget *parent = 0);
    ~p11_charging_dialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::p11_charging_dialog *ui;

private:
    QTimer *timer;
//    QTimer *timer1;

private:
    void update_page_info(void);
    void update_hmi_page_index(void);

private:
    int s_pic_count;
private slots:
    void init_page_dlg(void);
    void init_page_val(void);
    void start_timer(void);
    void timer_handle(void);
//    void timer1_handle(void);
    //int caculate_pic_count(int soc);
    void exit_page_dlg(void);
//     void call_dlg_1(void);
     void call_dlg_2(void);
     void call_p12_dlg(void);
signals:
     void signal_enable_p12dlg_timer();
     //void signal_enable_dlg_1_timer();
     void signal_enable_dlg_2_timer();
    void signal_exit_p11dlg();
};

#endif // P11_CHARGING_DIALOG_H
