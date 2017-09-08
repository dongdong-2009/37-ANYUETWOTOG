#ifndef P02_SERVCHOOSE_DIALOG_H
#define P02_SERVCHOOSE_DIALOG_H

#include <QDialog>

namespace Ui {
    class p02_servchoose_dialog;
}

class p02_servchoose_dialog : public QDialog {
    Q_OBJECT
public:
    p02_servchoose_dialog(QWidget *parent = 0);
    ~p02_servchoose_dialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::p02_servchoose_dialog *ui;

private:
        QTimer *timer;
private slots:
        void init_page_dlg(void);
        void init_page_val(void);
        void start_timer(void);
        void timer_handle(void);
        void exit_page_dlg(void);
        void call_p03_dlg(void);
        void call_p19_dlg(void);
        void call_p05_dlg(void);
        void call_p21_dlg(void);
        void call_p22_dlg(void);

private:
    void update_page_info(void);
    void update_hmi_page_index(void);

private slots:
   // void on_pbtn_alarm_query_clicked();
    void on_pbtn_query_clicked();
  //  void on_pbtn_charge_ac_clicked();
    void on_pbtn_charge_clicked();
    void on_pbtn_cancel_clicked();
    void on_pbtn_money_clicked();
    void on_pbtn_meter_clicked();
  //   void call_dlg_1(void);

signals:
    void signal_enable_p03dlg_timer();
    void signal_enable_p19dlg_timer();
     void signal_enable_p21dlg_timer();
      void signal_enable_p22dlg_timer();
    void signal_enable_p05dlg_timer();
    void signal_enable_dlg_1_timer();

    void signal_exit_p02dlg();
};

#endif // P02_SERVCHOOSE_DIALOG_H
