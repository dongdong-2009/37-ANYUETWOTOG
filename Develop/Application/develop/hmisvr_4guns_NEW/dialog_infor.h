#ifndef DIALOG_INFOR_H
#define DIALOG_INFOR_H

#include <QDialog>

namespace Ui {
class Dialog_infor;
}

class Dialog_infor : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_infor(QWidget *parent = 0);
    ~Dialog_infor();

private:
    Ui::Dialog_infor *ui;
    QTimer *timer;
    void update_hmi_page_index(void);
    void init_page_val(void);
    void update_page_info(void);
    void start_timer(void);

private slots:
    void on_pushButton_ok_clicked(void);
    void init_page_dlg(void);
    void timer_handle(void);
    void exit_page_dlg(void);

signals:
    void signal_exit_dlg_info();
};

#endif // DIALOG_INFOR_H
