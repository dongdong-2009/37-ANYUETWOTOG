#ifndef DIALOG_1_H
#define DIALOG_1_H


#include <QDialog>

namespace Ui {
    class dialog_1;
}

class dialog_1 : public QDialog {
    Q_OBJECT
public:
    dialog_1(QWidget *parent = 0);
    ~dialog_1();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::dialog_1 *ui;
    QTimer *timer;
    void update_hmi_page_index(void);
    void init_page_val(void);

private slots:
    void on_pushButton_ok_clicked(void);
    void init_page_dlg(void);
    void timer_handle(void);
    void exit_page_dlg(void);
  //  void call_p12_dlg(void);
  //  void call_p20_dlg(void);
signals:
    void signal_exit_dlg_1();
 //   void signal_enable_p12dlg_timer();
 //   void signal_enable_p20dlg_timer();
};

#endif // DIALOG_1_H
