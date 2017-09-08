#ifndef DIALOG_STOP_H
#define DIALOG_STOP_H

#include <QDialog>

namespace Ui {
class Dialog_stop;
}

class Dialog_stop : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_stop(QWidget *parent = 0);
    ~Dialog_stop();

private:
    Ui::Dialog_stop *ui;
    QTimer *timer;
    void update_hmi_page_index(void);
    void init_page_val(void);
    void update_page_info(void);
    void start_timer(void);
private slots:
    void on_pushButton_ok_clicked(void);
    void on_pushButton_cancel_clicked(void);
    void init_page_dlg(void);
    void timer_handle(void);
    void exit_page_dlg(void);

signals:
    void signal_exit_dlg();
};

#endif // DIALOG_STOP_H
