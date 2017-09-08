#ifndef P18_SETPARA_SUB5_DIALOG_H
#define P18_SETPARA_SUB5_DIALOG_H

#include <QDialog>

namespace Ui {
    class p18_setpara_sub5_dialog;
}

class p18_setpara_sub5_dialog : public QDialog {
    Q_OBJECT
public:
    p18_setpara_sub5_dialog(QWidget *parent = 0);
    ~p18_setpara_sub5_dialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::p18_setpara_sub5_dialog *ui;

private:
        QTimer *timer;

private:
    void update_page_info(void);
    void update_hmi_page_index(void);

    unsigned char type;
    char type_buf[25];
    int type_len;

private slots:
    void init_page_dlg(void);
    void init_page_val(void);
    void start_timer(void);
    void timer_handle(void);
    void exit_page_dlg(void);
    void btn_press(void);

   // void on_pbtn_enter_clicked();
    void on_pbtn_down_clicked();
    void on_pbtn_up_clicked();
    void on_pbtn_ok_clicked();
    void on_pbtn_go_clicked();
   // void on_pbtn_cancel_clicked();
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

       void on_pbtn_clicked();
 //   void on_pbtn_1_clicked();
  //  void on_pbtn_2_clicked();
//    void on_pbtn_3_clicked();
    void call_p17_dlg(void);
    void call_p24_dlg(void);

signals:
    void signal_enable_p24dlg_timer();
    void signal_exit_p18dlg();
    void signal_timer_p18dlg();

};

#endif // P18_SETPARA_SUB5_DIALOG_H
