#ifndef P06_CHARGECONFIGRM_DIALOG_H
#define P06_CHARGECONFIGRM_DIALOG_H

#include <QDialog>

namespace Ui {
    class p06_chargeconfigrm_dialog;
}

class p06_chargeconfigrm_dialog : public QDialog {
    Q_OBJECT
public:
    p06_chargeconfigrm_dialog(QWidget *parent = 0);
    ~p06_chargeconfigrm_dialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::p06_chargeconfigrm_dialog *ui;

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
    void call_p07_dlg(void);
   //  void call_dlg_1(void);

private slots:
    void on_pbtn_num1_clicked();
    void on_pbtn_num2_clicked();
    void on_pbtn_num3_clicked();
    void on_pbtn_num4_clicked();

signals:
    void signal_enable_p07dlg_timer();
      void signal_enable_dlg_1_timer();
    void signal_exit_p06dlg();
};

#endif // P06_CHARGECONFIGRM_DIALOG_H
