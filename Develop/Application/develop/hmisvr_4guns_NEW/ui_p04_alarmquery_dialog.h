/********************************************************************************
** Form generated from reading UI file 'p04_alarmquery_dialog.ui'
**
** Created: Fri Apr 18 16:43:29 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_P04_ALARMQUERY_DIALOG_H
#define UI_P04_ALARMQUERY_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_p04_alarmquery_dialog
{
public:
    QFrame *frame_4;
    QFrame *frame_5;
    QPushButton *pbtn_down;
    QLabel *label_3;
    QFrame *frame;
    QLabel *label_4;
    QLabel *label_num;
    QLabel *label_txt;
    QLabel *label_7;
    QLabel *label_num_2;
    QLabel *label_num_3;
    QLabel *label_num_4;
    QLabel *label_num_5;
    QLabel *label_txt_2;
    QLabel *label_txt_4;
    QLabel *label_txt_5;
    QLabel *label_txt_3;
    QPushButton *pbtn_up;
    QPushButton *pbtn_enter;
    QLabel *label;
    QLabel *label_phone;
    QLabel *label_2;
    QLabel *label_code;

    void setupUi(QDialog *p04_alarmquery_dialog)
    {
        if (p04_alarmquery_dialog->objectName().isEmpty())
            p04_alarmquery_dialog->setObjectName(QString::fromUtf8("p04_alarmquery_dialog"));
        p04_alarmquery_dialog->resize(803, 491);
        p04_alarmquery_dialog->setStyleSheet(QString::fromUtf8(""));
        frame_4 = new QFrame(p04_alarmquery_dialog);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(0, 0, 811, 491));
        frame_4->setStyleSheet(QString::fromUtf8("background-image: url(:/background/qrc/background/bk-potevio-2.png);"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        frame_5 = new QFrame(frame_4);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(20, 90, 761, 331));
        QFont font;
        font.setPointSize(6);
        frame_5->setFont(font);
        frame_5->setStyleSheet(QString::fromUtf8("background-image: url(:/background/qrc/background/back.png);"));
        frame_5->setFrameShape(QFrame::NoFrame);
        frame_5->setFrameShadow(QFrame::Raised);
        pbtn_down = new QPushButton(frame_5);
        pbtn_down->setObjectName(QString::fromUtf8("pbtn_down"));
        pbtn_down->setGeometry(QRect(310, 280, 121, 41));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        pbtn_down->setFont(font1);
        pbtn_down->setStyleSheet(QString::fromUtf8("border-image: url(:/btn/qrc/btn/button-02.png);"));
        label_3 = new QLabel(frame_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(250, 10, 361, 41));
        QFont font2;
        font2.setPointSize(28);
        font2.setItalic(true);
        label_3->setFont(font2);
        frame = new QFrame(frame_5);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(20, 60, 731, 211));
        frame->setStyleSheet(QString::fromUtf8("background-image: url(:/background/qrc/background/bk-potevio-t1.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 10, 121, 31));
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setWeight(75);
        label_4->setFont(font3);
        label_4->setStyleSheet(QString::fromUtf8("background-image: url(:/background/qrc/background/back.png);"));
        label_num = new QLabel(frame);
        label_num->setObjectName(QString::fromUtf8("label_num"));
        label_num->setGeometry(QRect(40, 40, 51, 31));
        QFont font4;
        font4.setPointSize(18);
        label_num->setFont(font4);
        label_num->setStyleSheet(QString::fromUtf8("background-image: url(:/background/qrc/background/back.png);"));
        label_txt = new QLabel(frame);
        label_txt->setObjectName(QString::fromUtf8("label_txt"));
        label_txt->setGeometry(QRect(130, 45, 571, 41));
        QFont font5;
        font5.setPointSize(18);
        font5.setKerning(true);
        label_txt->setFont(font5);
        label_txt->setStyleSheet(QString::fromUtf8("background-image: url(:/background/qrc/background/back.png);"));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(340, 10, 141, 31));
        QFont font6;
        font6.setPointSize(20);
        font6.setBold(true);
        font6.setWeight(75);
        label_7->setFont(font6);
        label_7->setStyleSheet(QString::fromUtf8("background-image: url(:/background/qrc/background/back.png);"));
        label_num_2 = new QLabel(frame);
        label_num_2->setObjectName(QString::fromUtf8("label_num_2"));
        label_num_2->setGeometry(QRect(40, 73, 51, 31));
        label_num_2->setFont(font4);
        label_num_2->setStyleSheet(QString::fromUtf8("background-image: url(:/background/qrc/background/back.png);"));
        label_num_3 = new QLabel(frame);
        label_num_3->setObjectName(QString::fromUtf8("label_num_3"));
        label_num_3->setGeometry(QRect(40, 106, 51, 31));
        label_num_3->setFont(font4);
        label_num_3->setStyleSheet(QString::fromUtf8("background-image: url(:/background/qrc/background/back.png);"));
        label_num_4 = new QLabel(frame);
        label_num_4->setObjectName(QString::fromUtf8("label_num_4"));
        label_num_4->setGeometry(QRect(40, 139, 51, 31));
        label_num_4->setFont(font4);
        label_num_4->setStyleSheet(QString::fromUtf8("background-image: url(:/background/qrc/background/back.png);"));
        label_num_5 = new QLabel(frame);
        label_num_5->setObjectName(QString::fromUtf8("label_num_5"));
        label_num_5->setGeometry(QRect(40, 172, 51, 31));
        label_num_5->setFont(font4);
        label_num_5->setStyleSheet(QString::fromUtf8("background-image: url(:/background/qrc/background/back.png);"));
        label_txt_2 = new QLabel(frame);
        label_txt_2->setObjectName(QString::fromUtf8("label_txt_2"));
        label_txt_2->setGeometry(QRect(130, 78, 571, 41));
        label_txt_2->setFont(font4);
        label_txt_2->setStyleSheet(QString::fromUtf8("background-image: url(:/background/qrc/background/back.png);"));
        label_txt_4 = new QLabel(frame);
        label_txt_4->setObjectName(QString::fromUtf8("label_txt_4"));
        label_txt_4->setGeometry(QRect(130, 144, 571, 41));
        label_txt_4->setFont(font4);
        label_txt_4->setStyleSheet(QString::fromUtf8("background-image: url(:/background/qrc/background/back.png);"));
        label_txt_5 = new QLabel(frame);
        label_txt_5->setObjectName(QString::fromUtf8("label_txt_5"));
        label_txt_5->setGeometry(QRect(130, 177, 571, 41));
        label_txt_5->setFont(font4);
        label_txt_5->setStyleSheet(QString::fromUtf8("background-image: url(:/background/qrc/background/back.png);"));
        label_txt_3 = new QLabel(frame);
        label_txt_3->setObjectName(QString::fromUtf8("label_txt_3"));
        label_txt_3->setGeometry(QRect(130, 111, 571, 41));
        label_txt_3->setFont(font4);
        label_txt_3->setStyleSheet(QString::fromUtf8("background-image: url(:/background/qrc/background/back.png);"));
        pbtn_up = new QPushButton(frame_5);
        pbtn_up->setObjectName(QString::fromUtf8("pbtn_up"));
        pbtn_up->setGeometry(QRect(90, 280, 121, 41));
        pbtn_up->setFont(font1);
        pbtn_up->setStyleSheet(QString::fromUtf8("border-image: url(:/btn/qrc/btn/button-02.png);"));
        pbtn_enter = new QPushButton(frame_5);
        pbtn_enter->setObjectName(QString::fromUtf8("pbtn_enter"));
        pbtn_enter->setGeometry(QRect(530, 280, 121, 41));
        pbtn_enter->setFont(font1);
        pbtn_enter->setStyleSheet(QString::fromUtf8("border-image: url(:/btn/qrc/btn/button-02.png);"));
        label = new QLabel(frame_4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 455, 111, 31));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(14, 14, 242, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(123, 123, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(68, 68, 248, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(7, 7, 121, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(9, 9, 161, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(134, 134, 248, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        label->setPalette(palette);
        QFont font7;
        font7.setFamily(QString::fromUtf8("Ubuntu"));
        font7.setPointSize(20);
        font7.setBold(false);
        font7.setItalic(false);
        font7.setWeight(50);
        label->setFont(font7);
        label->setTextFormat(Qt::AutoText);
        label_phone = new QLabel(frame_4);
        label_phone->setObjectName(QString::fromUtf8("label_phone"));
        label_phone->setGeometry(QRect(100, 460, 191, 21));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        label_phone->setPalette(palette1);
        label_phone->setFont(font6);
        label_phone->setTextFormat(Qt::AutoText);
        label_2 = new QLabel(frame_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(565, 460, 51, 21));
        label_2->setFont(font6);
        label_code = new QLabel(frame_4);
        label_code->setObjectName(QString::fromUtf8("label_code"));
        label_code->setGeometry(QRect(600, 460, 191, 21));
        label_code->setFont(font4);

        retranslateUi(p04_alarmquery_dialog);

        QMetaObject::connectSlotsByName(p04_alarmquery_dialog);
    } // setupUi

    void retranslateUi(QDialog *p04_alarmquery_dialog)
    {
        p04_alarmquery_dialog->setWindowTitle(QApplication::translate("p04_alarmquery_dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        pbtn_down->setText(QApplication::translate("p04_alarmquery_dialog", "\344\270\213\344\270\200\351\241\265", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("p04_alarmquery_dialog", "\346\225\205 \351\232\234 \344\277\241 \346\201\257 \346\237\245 \350\257\242", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("p04_alarmquery_dialog", " \350\256\260\345\275\225\345\272\217\345\217\267                     ", 0, QApplication::UnicodeUTF8));
        label_num->setText(QString());
        label_txt->setText(QString());
        label_7->setText(QApplication::translate("p04_alarmquery_dialog", "\346\225\205\351\232\234\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        label_num_2->setText(QString());
        label_num_3->setText(QString());
        label_num_4->setText(QString());
        label_num_5->setText(QString());
        label_txt_2->setText(QString());
        label_txt_4->setText(QString());
        label_txt_5->setText(QString());
        label_txt_3->setText(QString());
        pbtn_up->setText(QApplication::translate("p04_alarmquery_dialog", "\344\270\212\344\270\200\351\241\265", 0, QApplication::UnicodeUTF8));
        pbtn_enter->setText(QApplication::translate("p04_alarmquery_dialog", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("p04_alarmquery_dialog", "\347\264\247\346\200\245\347\224\265\350\257\235\357\274\232", 0, QApplication::UnicodeUTF8));
        label_phone->setText(QString());
        label_2->setText(QApplication::translate("p04_alarmquery_dialog", "ID:", 0, QApplication::UnicodeUTF8));
        label_code->setText(QApplication::translate("p04_alarmquery_dialog", "00", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class p04_alarmquery_dialog: public Ui_p04_alarmquery_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_P04_ALARMQUERY_DIALOG_H
