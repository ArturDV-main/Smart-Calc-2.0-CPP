/********************************************************************************
** Form generated from reading UI file 's21_view_qt.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_S21_VIEW_QT_H
#define UI_S21_VIEW_QT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *push_sin;
    QPushButton *push_cos;
    QPushButton *push_asin;
    QPushButton *push_acos;
    QPushButton *push_plus;
    QPushButton *push_AC;
    QPushButton *push_scobka;
    QPushButton *push_mult;
    QPushButton *push_7;
    QPushButton *push_8;
    QPushButton *push_9;
    QPushButton *push_stepen;
    QPushButton *push_4;
    QPushButton *push_5;
    QPushButton *push_6;
    QPushButton *push_1;
    QPushButton *push_2;
    QPushButton *push_3;
    QPushButton *push_minus;
    QPushButton *push_tan;
    QPushButton *push_div;
    QPushButton *push_mod;
    QPushButton *push_dot;
    QPushButton *push_0;
    QPushButton *push_ravno;
    QPushButton *push_atan;
    QPushButton *push_sqrt;
    QPushButton *push_log;
    QPushButton *push_ln;
    QPushButton *push_X;
    QCustomPlot *widget_graf;
    QLabel *label;
    QLineEdit *line_X;
    QLabel *label_2;
    QLineEdit *line_X_from;
    QLineEdit *line_Y_from;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *line_X_to;
    QLineEdit *line_Y_to;
    QPushButton *push_graf;
    QPushButton *cred_Button;
    QLineEdit *result;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(670, 500);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(670, 500));
        MainWindow->setMaximumSize(QSize(670, 500));
        MainWindow->setBaseSize(QSize(670, 500));
        MainWindow->setFocusPolicy(Qt::NoFocus);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setMaximumSize(QSize(1000, 1000));
        centralwidget->setBaseSize(QSize(700, 700));
        push_sin = new QPushButton(centralwidget);
        push_sin->setObjectName(QString::fromUtf8("push_sin"));
        push_sin->setGeometry(QRect(70, 100, 60, 40));
        push_cos = new QPushButton(centralwidget);
        push_cos->setObjectName(QString::fromUtf8("push_cos"));
        push_cos->setGeometry(QRect(10, 100, 60, 40));
        push_asin = new QPushButton(centralwidget);
        push_asin->setObjectName(QString::fromUtf8("push_asin"));
        push_asin->setGeometry(QRect(190, 100, 60, 40));
        push_acos = new QPushButton(centralwidget);
        push_acos->setObjectName(QString::fromUtf8("push_acos"));
        push_acos->setGeometry(QRect(130, 100, 60, 40));
        push_plus = new QPushButton(centralwidget);
        push_plus->setObjectName(QString::fromUtf8("push_plus"));
        push_plus->setGeometry(QRect(190, 190, 60, 60));
        QFont font;
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setStrikeOut(false);
        push_plus->setFont(font);
        push_plus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 169, 198);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        push_AC = new QPushButton(centralwidget);
        push_AC->setObjectName(QString::fromUtf8("push_AC"));
        push_AC->setGeometry(QRect(10, 190, 121, 60));
        push_AC->setFont(font);
        push_AC->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 169, 198);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        push_AC->setCheckable(false);
        push_scobka = new QPushButton(centralwidget);
        push_scobka->setObjectName(QString::fromUtf8("push_scobka"));
        push_scobka->setGeometry(QRect(130, 190, 61, 60));
        push_scobka->setFont(font);
        push_scobka->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 169, 198);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        push_mult = new QPushButton(centralwidget);
        push_mult->setObjectName(QString::fromUtf8("push_mult"));
        push_mult->setGeometry(QRect(190, 250, 60, 60));
        push_mult->setFont(font);
        push_mult->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 169, 198);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        push_7 = new QPushButton(centralwidget);
        push_7->setObjectName(QString::fromUtf8("push_7"));
        push_7->setGeometry(QRect(10, 250, 60, 60));
        push_8 = new QPushButton(centralwidget);
        push_8->setObjectName(QString::fromUtf8("push_8"));
        push_8->setGeometry(QRect(70, 250, 60, 60));
        push_9 = new QPushButton(centralwidget);
        push_9->setObjectName(QString::fromUtf8("push_9"));
        push_9->setGeometry(QRect(130, 250, 60, 60));
        push_stepen = new QPushButton(centralwidget);
        push_stepen->setObjectName(QString::fromUtf8("push_stepen"));
        push_stepen->setGeometry(QRect(190, 310, 60, 60));
        push_stepen->setFont(font);
        push_stepen->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 169, 198);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        push_4 = new QPushButton(centralwidget);
        push_4->setObjectName(QString::fromUtf8("push_4"));
        push_4->setGeometry(QRect(10, 310, 60, 60));
        push_5 = new QPushButton(centralwidget);
        push_5->setObjectName(QString::fromUtf8("push_5"));
        push_5->setGeometry(QRect(70, 310, 60, 60));
        push_6 = new QPushButton(centralwidget);
        push_6->setObjectName(QString::fromUtf8("push_6"));
        push_6->setGeometry(QRect(130, 310, 60, 60));
        push_1 = new QPushButton(centralwidget);
        push_1->setObjectName(QString::fromUtf8("push_1"));
        push_1->setGeometry(QRect(10, 370, 60, 60));
        push_2 = new QPushButton(centralwidget);
        push_2->setObjectName(QString::fromUtf8("push_2"));
        push_2->setGeometry(QRect(70, 370, 60, 60));
        push_3 = new QPushButton(centralwidget);
        push_3->setObjectName(QString::fromUtf8("push_3"));
        push_3->setGeometry(QRect(130, 370, 60, 60));
        push_minus = new QPushButton(centralwidget);
        push_minus->setObjectName(QString::fromUtf8("push_minus"));
        push_minus->setGeometry(QRect(250, 190, 60, 60));
        push_minus->setFont(font);
        push_minus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 169, 198);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        push_tan = new QPushButton(centralwidget);
        push_tan->setObjectName(QString::fromUtf8("push_tan"));
        push_tan->setGeometry(QRect(250, 100, 60, 40));
        push_div = new QPushButton(centralwidget);
        push_div->setObjectName(QString::fromUtf8("push_div"));
        push_div->setGeometry(QRect(250, 250, 60, 60));
        push_div->setFont(font);
        push_div->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 169, 198);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        push_mod = new QPushButton(centralwidget);
        push_mod->setObjectName(QString::fromUtf8("push_mod"));
        push_mod->setGeometry(QRect(250, 310, 60, 60));
        push_mod->setFont(font);
        push_mod->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 169, 198);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        push_dot = new QPushButton(centralwidget);
        push_dot->setObjectName(QString::fromUtf8("push_dot"));
        push_dot->setGeometry(QRect(130, 430, 60, 61));
        push_0 = new QPushButton(centralwidget);
        push_0->setObjectName(QString::fromUtf8("push_0"));
        push_0->setGeometry(QRect(10, 430, 121, 61));
        push_ravno = new QPushButton(centralwidget);
        push_ravno->setObjectName(QString::fromUtf8("push_ravno"));
        push_ravno->setGeometry(QRect(190, 370, 120, 121));
        push_ravno->setFont(font);
        push_ravno->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 169, 198);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        push_atan = new QPushButton(centralwidget);
        push_atan->setObjectName(QString::fromUtf8("push_atan"));
        push_atan->setGeometry(QRect(10, 140, 60, 40));
        push_sqrt = new QPushButton(centralwidget);
        push_sqrt->setObjectName(QString::fromUtf8("push_sqrt"));
        push_sqrt->setGeometry(QRect(190, 140, 60, 40));
        push_log = new QPushButton(centralwidget);
        push_log->setObjectName(QString::fromUtf8("push_log"));
        push_log->setGeometry(QRect(70, 140, 60, 40));
        push_ln = new QPushButton(centralwidget);
        push_ln->setObjectName(QString::fromUtf8("push_ln"));
        push_ln->setGeometry(QRect(130, 140, 60, 40));
        push_X = new QPushButton(centralwidget);
        push_X->setObjectName(QString::fromUtf8("push_X"));
        push_X->setGeometry(QRect(250, 140, 60, 40));
        widget_graf = new QCustomPlot(centralwidget);
        widget_graf->setObjectName(QString::fromUtf8("widget_graf"));
        widget_graf->setGeometry(QRect(320, 170, 341, 321));
        widget_graf->setCursor(QCursor(Qt::ArrowCursor));
        widget_graf->setInputMethodHints(Qt::ImhNone);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(330, 70, 31, 20));
        line_X = new QLineEdit(centralwidget);
        line_X->setObjectName(QString::fromUtf8("line_X"));
        line_X->setGeometry(QRect(370, 70, 101, 23));
        line_X->setMinimumSize(QSize(10, 5));
        line_X->setMaximumSize(QSize(370, 90));
        line_X->setFocusPolicy(Qt::ClickFocus);
        line_X->setAcceptDrops(true);
        line_X->setMaxLength(12);
        line_X->setCursorPosition(1);
        line_X->setReadOnly(false);
        line_X->setClearButtonEnabled(false);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(330, 110, 41, 20));
        line_X_from = new QLineEdit(centralwidget);
        line_X_from->setObjectName(QString::fromUtf8("line_X_from"));
        line_X_from->setGeometry(QRect(370, 110, 101, 23));
        line_X_from->setCursor(QCursor(Qt::ArrowCursor));
        line_X_from->setMouseTracking(false);
        line_X_from->setFocusPolicy(Qt::ClickFocus);
        line_X_from->setMaxLength(12);
        line_X_from->setReadOnly(false);
        line_X_from->setClearButtonEnabled(false);
        line_Y_from = new QLineEdit(centralwidget);
        line_Y_from->setObjectName(QString::fromUtf8("line_Y_from"));
        line_Y_from->setGeometry(QRect(370, 140, 101, 23));
        line_Y_from->setCursor(QCursor(Qt::ArrowCursor));
        line_Y_from->setMouseTracking(false);
        line_Y_from->setFocusPolicy(Qt::ClickFocus);
        line_Y_from->setInputMethodHints(Qt::ImhNone);
        line_Y_from->setMaxLength(12);
        line_Y_from->setReadOnly(false);
        line_Y_from->setClearButtonEnabled(false);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(330, 140, 41, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(480, 140, 16, 20));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(480, 110, 16, 20));
        line_X_to = new QLineEdit(centralwidget);
        line_X_to->setObjectName(QString::fromUtf8("line_X_to"));
        line_X_to->setGeometry(QRect(500, 110, 101, 23));
        line_X_to->setCursor(QCursor(Qt::ArrowCursor));
        line_X_to->setMouseTracking(false);
        line_X_to->setFocusPolicy(Qt::ClickFocus);
        line_X_to->setMaxLength(12);
        line_X_to->setReadOnly(false);
        line_X_to->setClearButtonEnabled(false);
        line_Y_to = new QLineEdit(centralwidget);
        line_Y_to->setObjectName(QString::fromUtf8("line_Y_to"));
        line_Y_to->setGeometry(QRect(500, 140, 101, 23));
        line_Y_to->setCursor(QCursor(Qt::ArrowCursor));
        line_Y_to->setMouseTracking(false);
        line_Y_to->setFocusPolicy(Qt::ClickFocus);
        line_Y_to->setMaxLength(12);
        line_Y_to->setDragEnabled(false);
        line_Y_to->setReadOnly(false);
        line_Y_to->setClearButtonEnabled(false);
        push_graf = new QPushButton(centralwidget);
        push_graf->setObjectName(QString::fromUtf8("push_graf"));
        push_graf->setGeometry(QRect(610, 110, 51, 21));
        cred_Button = new QPushButton(centralwidget);
        cred_Button->setObjectName(QString::fromUtf8("cred_Button"));
        cred_Button->setGeometry(QRect(20, 60, 181, 25));
        result = new QLineEdit(centralwidget);
        result->setObjectName(QString::fromUtf8("result"));
        result->setGeometry(QRect(10, 10, 651, 41));
        QPalette palette;
        QBrush brush(QColor(145, 145, 145, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(152, 152, 152, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        QBrush brush2(QColor(184, 184, 184, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush2);
        QBrush brush3(QColor(208, 208, 208, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        QBrush brush4(QColor(255, 255, 255, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush4);
        QBrush brush5(QColor(240, 240, 240, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush5);
        QBrush brush6(QColor(164, 166, 168, 96));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush5);
        result->setPalette(palette);
        QFont font1;
        font1.setPointSize(27);
        result->setFont(font1);
        result->setFocusPolicy(Qt::StrongFocus);
        result->setAcceptDrops(true);
        result->setLayoutDirection(Qt::LeftToRight);
        result->setMaxLength(254);
        result->setFrame(false);
        result->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        result->setReadOnly(true);
        result->setClearButtonEnabled(false);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "SmartCalc2_0", nullptr));
#if QT_CONFIG(whatsthis)
        push_sin->setWhatsThis(QCoreApplication::translate("MainWindow", "A", nullptr));
#endif // QT_CONFIG(whatsthis)
        push_sin->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
#if QT_CONFIG(whatsthis)
        push_cos->setWhatsThis(QCoreApplication::translate("MainWindow", "@", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(accessibility)
        push_cos->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        push_cos->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
#if QT_CONFIG(whatsthis)
        push_asin->setWhatsThis(QCoreApplication::translate("MainWindow", "D", nullptr));
#endif // QT_CONFIG(whatsthis)
        push_asin->setText(QCoreApplication::translate("MainWindow", "asin", nullptr));
#if QT_CONFIG(whatsthis)
        push_acos->setWhatsThis(QCoreApplication::translate("MainWindow", "C", nullptr));
#endif // QT_CONFIG(whatsthis)
        push_acos->setText(QCoreApplication::translate("MainWindow", "acos", nullptr));
#if QT_CONFIG(whatsthis)
        push_plus->setWhatsThis(QCoreApplication::translate("MainWindow", "+", nullptr));
#endif // QT_CONFIG(whatsthis)
        push_plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        push_AC->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
#if QT_CONFIG(whatsthis)
        push_scobka->setWhatsThis(QCoreApplication::translate("MainWindow", "(", nullptr));
#endif // QT_CONFIG(whatsthis)
        push_scobka->setText(QCoreApplication::translate("MainWindow", "( )", nullptr));
#if QT_CONFIG(whatsthis)
        push_mult->setWhatsThis(QCoreApplication::translate("MainWindow", "*", nullptr));
#endif // QT_CONFIG(whatsthis)
        push_mult->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        push_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        push_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        push_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
#if QT_CONFIG(whatsthis)
        push_stepen->setWhatsThis(QCoreApplication::translate("MainWindow", "^", nullptr));
#endif // QT_CONFIG(whatsthis)
        push_stepen->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        push_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        push_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        push_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        push_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        push_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        push_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
#if QT_CONFIG(whatsthis)
        push_minus->setWhatsThis(QCoreApplication::translate("MainWindow", "-", nullptr));
#endif // QT_CONFIG(whatsthis)
        push_minus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
#if QT_CONFIG(whatsthis)
        push_tan->setWhatsThis(QCoreApplication::translate("MainWindow", "B", nullptr));
#endif // QT_CONFIG(whatsthis)
        push_tan->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
#if QT_CONFIG(whatsthis)
        push_div->setWhatsThis(QCoreApplication::translate("MainWindow", "/", nullptr));
#endif // QT_CONFIG(whatsthis)
        push_div->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
#if QT_CONFIG(whatsthis)
        push_mod->setWhatsThis(QCoreApplication::translate("MainWindow", "M", nullptr));
#endif // QT_CONFIG(whatsthis)
        push_mod->setText(QCoreApplication::translate("MainWindow", "mod", nullptr));
        push_dot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        push_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        push_ravno->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
#if QT_CONFIG(whatsthis)
        push_atan->setWhatsThis(QCoreApplication::translate("MainWindow", "E", nullptr));
#endif // QT_CONFIG(whatsthis)
        push_atan->setText(QCoreApplication::translate("MainWindow", "atan", nullptr));
#if QT_CONFIG(whatsthis)
        push_sqrt->setWhatsThis(QCoreApplication::translate("MainWindow", "F", nullptr));
#endif // QT_CONFIG(whatsthis)
        push_sqrt->setText(QCoreApplication::translate("MainWindow", "sqrt", nullptr));
#if QT_CONFIG(whatsthis)
        push_log->setWhatsThis(QCoreApplication::translate("MainWindow", "H", nullptr));
#endif // QT_CONFIG(whatsthis)
        push_log->setText(QCoreApplication::translate("MainWindow", "log10", nullptr));
#if QT_CONFIG(whatsthis)
        push_ln->setWhatsThis(QCoreApplication::translate("MainWindow", "G", nullptr));
#endif // QT_CONFIG(whatsthis)
        push_ln->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
#if QT_CONFIG(whatsthis)
        push_X->setWhatsThis(QCoreApplication::translate("MainWindow", "X", nullptr));
#endif // QT_CONFIG(whatsthis)
        push_X->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "X =", nullptr));
        line_X->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "X from", nullptr));
        line_X_from->setText(QCoreApplication::translate("MainWindow", "-17", nullptr));
        line_X_from->setPlaceholderText(QString());
#if QT_CONFIG(statustip)
        line_Y_from->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        line_Y_from->setText(QCoreApplication::translate("MainWindow", "-15", nullptr));
        line_Y_from->setPlaceholderText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "Y from", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "to", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "to", nullptr));
        line_X_to->setText(QCoreApplication::translate("MainWindow", "17", nullptr));
        line_Y_to->setInputMask(QString());
        line_Y_to->setText(QCoreApplication::translate("MainWindow", "17", nullptr));
#if QT_CONFIG(whatsthis)
        push_graf->setWhatsThis(QCoreApplication::translate("MainWindow", "X", nullptr));
#endif // QT_CONFIG(whatsthis)
        push_graf->setText(QCoreApplication::translate("MainWindow", "GFAF", nullptr));
        cred_Button->setText(QCoreApplication::translate("MainWindow", "Credit calculator", nullptr));
        result->setInputMask(QString());
        result->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_S21_VIEW_QT_H
