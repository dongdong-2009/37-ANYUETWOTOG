#ifndef P07_CHARGETYPECHOOSE_DIALOG_H
#define P07_CHARGETYPECHOOSE_DIALOG_H

#include <QDialog>

namespace Ui {
    class p07_chargetypechoose_dialog;
}

class p07_chargetypechoose_dialog : public QDialog {
    Q_OBJECT
public:
    p07_chargetypechoose_dialog(QWidget *parent = 0);
    ~p07_chargetypechoose_dialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::p07_chargetypechoose_dialog *ui;

private:
        QTimer *timer;

private:
    void update_page_info(void);
    void update_hmi_page_index(void);

private slots:
    void on_pbtn_auto_clicked();
    void on_pbtn_cancel_clicked();
    void on_pbtn_byenergy_clicked();
    void on_pbtn_bytime_clicked();
    void on_pbtn_bymoney_clicked();
    void on_pbtn_byhand_clicked();
    void init_page_dlg(void);
    void init_page_val(void);
    void start_timer(void);
    void timer_handle(void);
    void exit_page_dlg(void);
    void call_p08_dlg(void);
    void call_p09_dlg(void);
    void call_p11_dlg(void);
      void call_p23_dlg(void);
      void call_handset_dlg();
    //void call_dlg_1(void);

signals:
    void signal_enable_dlg_1_timer();
    void signal_enable_p08dlg_timer();
    void signal_enable_p09dlg_timer();
    void signal_enable_p11dlg_timer();
    void signal_enable_p23dlg_timer();
    void signal_enable_handset_timer();

    void signal_exit_p07dlg();
};

#endif // P07_CHARGETYPECHOOSE_DIALOG_H
