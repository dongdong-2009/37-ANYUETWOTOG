#ifndef P22_ELECPRICE_DIALOG_H
#define P22_ELECPRICE_DIALOG_H

#include <QDialog>

namespace Ui {
class p22_ElecPrice_dialog;
}

class p22_ElecPrice_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit p22_ElecPrice_dialog(QWidget *parent = 0);
    ~p22_ElecPrice_dialog();

private:
    Ui::p22_ElecPrice_dialog *ui;
private:
        QTimer *timer;
private slots:
        void init_page_dlg(void);
        void init_page_val(void);
        void start_timer(void);
        void timer_handle(void);
        void exit_page_dlg(void);

private:
    void update_page_info(void);
    void update_hmi_page_index(void);

private slots:

    void on_pbtn_cancel_clicked();


signals:

    void signal_exit_p22dlg();
};

#endif // P22_ELECPRICE_DIALOG_H
