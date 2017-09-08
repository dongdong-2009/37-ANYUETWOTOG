#ifndef P23_CHARGEBYMONEY_H
#define P23_CHARGEBYMONEY_H

#include <QDialog>

namespace Ui {
class p23_chargebymoney;
}

class p23_chargebymoney : public QDialog
{
    Q_OBJECT

public:
    explicit p23_chargebymoney(QWidget *parent = 0);
    ~p23_chargebymoney();

private:
    Ui::p23_chargebymoney *ui;

protected:
    void changeEvent(QEvent *e);

private:
    QTimer *timer;

private:
    void update_page_info(void);
    void update_hmi_page_index(void);

private slots:
    void on_pbtn_180min_clicked();
    void on_pbtn_120min_clicked();
    void on_pbtn_60min_clicked();
    void on_pbtn_30min_clicked();
    void init_page_dlg(void);
    void init_page_val(void);
    void start_timer(void);
    void timer_handle(void);
    void exit_page_dlg(void);
    void call_p11_dlg(void);
     void call_p07_dlg(void);
    // void call_dlg_1(void);

private slots:
    void btn_press(void);
    void on_pbtn_ok_clicked();
    void on_pbtn_go_clicked();
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
     void signal_timer_p23dlg();
      void signal_enable_dlg_1_timer();
    void signal_exit_p23dlg();
};

#endif // P23_CHARGEBYMONEY_H
