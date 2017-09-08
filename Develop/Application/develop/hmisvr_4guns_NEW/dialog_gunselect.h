#ifndef DIALOG_GUNSELECT_H
#define DIALOG_GUNSELECT_H

#include <QDialog>

namespace Ui {
class Dialog_gunselect;
}

class Dialog_gunselect : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_gunselect(QWidget *parent = 0);
    ~Dialog_gunselect();

private:
    Ui::Dialog_gunselect *ui;
    QTimer *timer;
    void update_hmi_page_index(void);
    void init_page_val(void);
    void start_timer(void);
    void update_page_info(void);

private slots:
    void on_pushButton_ok_clicked(void);
    void on_pushButton_cancel_clicked(void);
    void on_pushButton_stop_clicked();
    void init_page_dlg(void);
    void timer_handle(void);
    void exit_page_dlg(void);
    void on_pbtn_1_clicked();
    void on_pbtn_2_clicked();
    void on_pbtn_3_clicked();
    void on_pbtn_4_clicked();

signals:
    void signal_exit_dlg_gun();
};

#endif // DIALOG_GUNSELECT_H
