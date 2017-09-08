#ifndef P09_CHARGEBYENERGY_DIALOG_H
#define P09_CHARGEBYENERGY_DIALOG_H

#include <QDialog>

namespace Ui {
    class p09_chargebyenergy_dialog;
}

class p09_chargebyenergy_dialog : public QDialog {
    Q_OBJECT
public:
    p09_chargebyenergy_dialog(QWidget *parent = 0);
    ~p09_chargebyenergy_dialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::p09_chargebyenergy_dialog *ui;

private:
    QTimer *timer;

private:
    void update_page_info(void);
    void update_hmi_page_index(void);


private slots:


    void on_pbtn_25dot_clicked();
    void on_pbtn_20dot_clicked();
    void on_pbtn_15dot_clicked();
    void on_pbtn_10dot_clicked();

    void init_page_dlg(void);
    void init_page_val(void);
    void start_timer(void);
    void timer_handle(void);
    void exit_page_dlg(void);
    void call_p11_dlg(void);
    //void call_dlg_1(void);
    void call_p07_dlg(void);
    void on_pbtn_ok_clicked();
    void on_pbtn_go_clicked();

    void btn_press(void);
    void on_pbtn_back_clicked();
    void on_pbtn_dot_clicked();
    void on_pbtn_num0_clicked();
    void on_pbtn_num9_clicked();
    void on_pbtn_num8_clicked();
    void on_pbtn_num7_clicked();
    void on_pbtn_num6_clicked();
    void on_pbtn_num5_clicked();
    void on_pbtn_num4_clicked();
    void on_pbtn_num3_clicked();
    void on_pbtn_num2_clicked();
    void on_pbtn_num1_clicked();

signals:
    void signal_enable_p11dlg_timer();
       void signal_enable_dlg_1_timer();
    void signal_exit_p09dlg();
     void signal_timer_p09dlg();
};

#endif // P09_CHARGEBYENERGY_DIALOG_H
