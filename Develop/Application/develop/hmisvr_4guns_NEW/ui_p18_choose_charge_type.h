/********************************************************************************
** Form generated from reading UI file 'p18_choose_charge_type.ui'
**
** Created: Fri Apr 18 16:43:29 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_P18_CHOOSE_CHARGE_TYPE_H
#define UI_P18_CHOOSE_CHARGE_TYPE_H

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

class Ui_p18_choose_charge_type
{
public:
    QFrame *frame_4;
    QFrame *frame_2;
    QLabel *label_card_sn;
    QLabel *label_passwd;
    QLabel *label;
    QPushButton *pbtn_type_ac;
    QPushButton *pbtn_type_dc;
    QLabel *label_2;
    QLabel *label_phone;
    QLabel *label_3;
    QLabel *label_code;

    void setupUi(QDialog *p18_choose_charge_type)
    {
        if (p18_choose_charge_type->objectName().isEmpty())
            p18_choose_charge_type->setObjectName(QString::fromUtf8("p18_choose_charge_type"));
        p18_choose_charge_type->resize(809, 491);
        frame_4 = new QFrame(p18_choose_charge_type);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(0, 0, 831, 491));
        frame_4->setStyleSheet(QString::fromUtf8("background-image: url(:/background/qrc/background/bk-potevio-2.png);"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        frame_2 = new QFrame(frame_4);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(30, 100, 741, 321));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setMinimumSize(QSize(13, 0));
        QFont font;
        font.setPointSize(24);
        font.setBold(false);
        font.setWeight(50);
        font.setKerning(true);
        frame_2->setFont(font);
        frame_2->setAutoFillBackground(false);
        frame_2->setStyleSheet(QString::fromUtf8("background-image: url(:/background/qrc/background/back.png);\n"
" "));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Sunken);
        label_card_sn = new QLabel(frame_2);
        label_card_sn->setObjectName(QString::fromUtf8("label_card_sn"));
        label_card_sn->setGeometry(QRect(130, 120, 211, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Courier 10 Pitch"));
        font1.setPointSize(18);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        font1.setKerning(true);
        label_card_sn->setFont(font1);
        label_passwd = new QLabel(frame_2);
        label_passwd->setObjectName(QString::fromUtf8("label_passwd"));
        label_passwd->setGeometry(QRect(130, 170, 81, 31));
        QFont font2;
        font2.setPointSize(18);
        font2.setItalic(false);
        font2.setKerning(true);
        label_passwd->setFont(font2);
        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 50, 411, 51));
        QFont font3;
        font3.setPointSize(28);
        font3.setBold(false);
        font3.setItalic(true);
        font3.setWeight(50);
        label->setFont(font3);
        pbtn_type_ac = new QPushButton(frame_2);
        pbtn_type_ac->setObjectName(QString::fromUtf8("pbtn_type_ac"));
        pbtn_type_ac->setGeometry(QRect(410, 160, 201, 51));
        QFont font4;
        font4.setPointSize(18);
        font4.setBold(false);
        font4.setWeight(50);
        pbtn_type_ac->setFont(font4);
        pbtn_type_ac->setFocusPolicy(Qt::NoFocus);
        pbtn_type_ac->setStyleSheet(QString::fromUtf8("border-image: url(:/btn/qrc/btn/btn_bg.png);"));
        pbtn_type_dc = new QPushButton(frame_2);
        pbtn_type_dc->setObjectName(QString::fromUtf8("pbtn_type_dc"));
        pbtn_type_dc->setGeometry(QRect(90, 160, 191, 51));
        pbtn_type_dc->setFont(font4);
        pbtn_type_dc->setFocusPolicy(Qt::NoFocus);
        pbtn_type_dc->setStyleSheet(QString::fromUtf8("border-image: url(:/btn/qrc/btn/btn_bg.png);"));
        label_2 = new QLabel(frame_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 455, 111, 31));
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
        label_2->setPalette(palette);
        QFont font5;
        font5.setFamily(QString::fromUtf8("Ubuntu"));
        font5.setPointSize(20);
        font5.setBold(false);
        font5.setItalic(false);
        font5.setWeight(50);
        label_2->setFont(font5);
        label_2->setTextFormat(Qt::AutoText);
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
        QFont font6;
        font6.setPointSize(20);
        font6.setBold(true);
        font6.setWeight(75);
        label_phone->setFont(font6);
        label_phone->setTextFormat(Qt::AutoText);
        label_3 = new QLabel(frame_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(565, 460, 51, 21));
        label_3->setFont(font6);
        label_code = new QLabel(frame_4);
        label_code->setObjectName(QString::fromUtf8("label_code"));
        label_code->setGeometry(QRect(600, 460, 191, 21));
        QFont font7;
        font7.setPointSize(18);
        label_code->setFont(font7);

        retranslateUi(p18_choose_charge_type);

        QMetaObject::connectSlotsByName(p18_choose_charge_type);
    } // setupUi

    void retranslateUi(QDialog *p18_choose_charge_type)
    {
        p18_choose_charge_type->setWindowTitle(QApplication::translate("p18_choose_charge_type", "Dialog", 0, QApplication::UnicodeUTF8));
        label_card_sn->setText(QString());
        label_passwd->setText(QString());
        label->setText(QApplication::translate("p18_choose_charge_type", "\350\257\267 \351\200\211 \346\213\251 \345\205\205 \347\224\265 \347\261\273 \345\236\213", 0, QApplication::UnicodeUTF8));
        pbtn_type_ac->setText(QApplication::translate("p18_choose_charge_type", "\344\272\244\346\265\201", 0, QApplication::UnicodeUTF8));
        pbtn_type_dc->setText(QApplication::translate("p18_choose_charge_type", "\347\233\264\346\265\201", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("p18_choose_charge_type", "\347\264\247\346\200\245\347\224\265\350\257\235\357\274\232", 0, QApplication::UnicodeUTF8));
        label_phone->setText(QString());
        label_3->setText(QApplication::translate("p18_choose_charge_type", "ID:", 0, QApplication::UnicodeUTF8));
        label_code->setText(QApplication::translate("p18_choose_charge_type", "00", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class p18_choose_charge_type: public Ui_p18_choose_charge_type {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_P18_CHOOSE_CHARGE_TYPE_H
