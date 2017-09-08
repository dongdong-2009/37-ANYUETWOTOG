#ifndef DIALOG_DIFF_CARD_H
#define DIALOG_DIFF_CARD_H

#include <QDialog>

namespace Ui {
class Dialog_diff_card;
}

class Dialog_diff_card : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_diff_card(QWidget *parent = 0);
    ~Dialog_diff_card();

private:
    Ui::Dialog_diff_card *ui;

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
signals:

    void signal_exit_diff_card();
};

#endif // DIALOG_DIFF_CARD_H
