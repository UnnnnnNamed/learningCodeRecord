/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widget
{
public:
    QGridLayout *gridLayout;
    QPushButton *divisionSign;
    QPushButton *enter2;
    QPushButton *enter4;
    QPushButton *enter1;
    QPushButton *enter9;
    QLabel *label_2;
    QPushButton *decimalPoint;
    QPushButton *enter6;
    QPushButton *enter8;
    QPushButton *enter0;
    QLabel *label;
    QPushButton *minusSign;
    QPushButton *enter5;
    QPushButton *plusSign;
    QPushButton *enter3;
    QPushButton *mutiplicationSign;
    QPushButton *enter7;
    QPushButton *backspace;
    QPushButton *equalSign;
    QPushButton *clear;
    QPushButton *plusOrMinus;
    QPushButton *openBracket;
    QPushButton *square;
    QPushButton *PI;
    QPushButton *naturalConstant;
    QPushButton *closingParenthesis;
    QPushButton *clearEntry;
    QPushButton *factorial;

    void setupUi(QWidget *widget)
    {
        if (widget->objectName().isEmpty())
            widget->setObjectName("widget");
        widget->resize(507, 596);
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        divisionSign = new QPushButton(widget);
        divisionSign->setObjectName("divisionSign");
        divisionSign->setMinimumSize(QSize(0, 40));
        divisionSign->setMaximumSize(QSize(16777215, 500));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font.setPointSize(20);
        divisionSign->setFont(font);

        gridLayout->addWidget(divisionSign, 3, 3, 1, 1);

        enter2 = new QPushButton(widget);
        enter2->setObjectName("enter2");
        enter2->setMinimumSize(QSize(0, 40));
        enter2->setMaximumSize(QSize(16777215, 500));
        QFont font1;
        font1.setPointSize(20);
        enter2->setFont(font1);

        gridLayout->addWidget(enter2, 7, 1, 1, 1);

        enter4 = new QPushButton(widget);
        enter4->setObjectName("enter4");
        enter4->setMinimumSize(QSize(0, 40));
        enter4->setMaximumSize(QSize(16777215, 500));
        enter4->setFont(font1);

        gridLayout->addWidget(enter4, 6, 0, 1, 1);

        enter1 = new QPushButton(widget);
        enter1->setObjectName("enter1");
        enter1->setMinimumSize(QSize(0, 40));
        enter1->setMaximumSize(QSize(16777215, 500));
        enter1->setFont(font1);

        gridLayout->addWidget(enter1, 7, 0, 1, 1);

        enter9 = new QPushButton(widget);
        enter9->setObjectName("enter9");
        enter9->setMinimumSize(QSize(0, 40));
        enter9->setMaximumSize(QSize(16777215, 500));
        enter9->setFont(font1);

        gridLayout->addWidget(enter9, 5, 2, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(0, 100));
        QFont font2;
        font2.setPointSize(22);
        font2.setBold(false);
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        gridLayout->addWidget(label_2, 0, 0, 1, 4);

        decimalPoint = new QPushButton(widget);
        decimalPoint->setObjectName("decimalPoint");
        decimalPoint->setMinimumSize(QSize(0, 40));
        decimalPoint->setMaximumSize(QSize(16777215, 500));
        decimalPoint->setFont(font1);

        gridLayout->addWidget(decimalPoint, 8, 2, 1, 1);

        enter6 = new QPushButton(widget);
        enter6->setObjectName("enter6");
        enter6->setMinimumSize(QSize(0, 40));
        enter6->setMaximumSize(QSize(16777215, 500));
        enter6->setFont(font1);

        gridLayout->addWidget(enter6, 6, 2, 1, 1);

        enter8 = new QPushButton(widget);
        enter8->setObjectName("enter8");
        enter8->setMinimumSize(QSize(0, 40));
        enter8->setMaximumSize(QSize(16777215, 500));
        enter8->setFont(font1);

        gridLayout->addWidget(enter8, 5, 1, 1, 1);

        enter0 = new QPushButton(widget);
        enter0->setObjectName("enter0");
        enter0->setMinimumSize(QSize(0, 40));
        enter0->setMaximumSize(QSize(16777215, 500));
        enter0->setFont(font1);

        gridLayout->addWidget(enter0, 8, 1, 1, 1);

        label = new QLabel(widget);
        label->setObjectName("label");
        label->setMinimumSize(QSize(0, 150));
        label->setMaximumSize(QSize(16777215, 500));
        QFont font3;
        font3.setPointSize(36);
        label->setFont(font3);
        label->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        gridLayout->addWidget(label, 1, 0, 1, 4);

        minusSign = new QPushButton(widget);
        minusSign->setObjectName("minusSign");
        minusSign->setMinimumSize(QSize(0, 40));
        minusSign->setMaximumSize(QSize(16777215, 500));
        minusSign->setFont(font1);

        gridLayout->addWidget(minusSign, 5, 3, 1, 1);

        enter5 = new QPushButton(widget);
        enter5->setObjectName("enter5");
        enter5->setMinimumSize(QSize(0, 40));
        enter5->setMaximumSize(QSize(16777215, 500));
        enter5->setFont(font1);

        gridLayout->addWidget(enter5, 6, 1, 1, 1);

        plusSign = new QPushButton(widget);
        plusSign->setObjectName("plusSign");
        plusSign->setMinimumSize(QSize(0, 40));
        plusSign->setMaximumSize(QSize(16777215, 500));
        plusSign->setFont(font1);

        gridLayout->addWidget(plusSign, 6, 3, 1, 1);

        enter3 = new QPushButton(widget);
        enter3->setObjectName("enter3");
        enter3->setMinimumSize(QSize(0, 40));
        enter3->setMaximumSize(QSize(16777215, 500));
        enter3->setFont(font1);

        gridLayout->addWidget(enter3, 7, 2, 1, 1);

        mutiplicationSign = new QPushButton(widget);
        mutiplicationSign->setObjectName("mutiplicationSign");
        mutiplicationSign->setMinimumSize(QSize(0, 40));
        mutiplicationSign->setMaximumSize(QSize(16777215, 500));
        mutiplicationSign->setFont(font1);

        gridLayout->addWidget(mutiplicationSign, 4, 3, 1, 1);

        enter7 = new QPushButton(widget);
        enter7->setObjectName("enter7");
        enter7->setMinimumSize(QSize(0, 40));
        enter7->setMaximumSize(QSize(16777215, 500));
        enter7->setFont(font1);

        gridLayout->addWidget(enter7, 5, 0, 1, 1);

        backspace = new QPushButton(widget);
        backspace->setObjectName("backspace");
        backspace->setMinimumSize(QSize(0, 40));
        backspace->setMaximumSize(QSize(16777215, 500));
        QFont font4;
        font4.setPointSize(20);
        font4.setBold(false);
        backspace->setFont(font4);

        gridLayout->addWidget(backspace, 2, 3, 1, 1);

        equalSign = new QPushButton(widget);
        equalSign->setObjectName("equalSign");
        equalSign->setMinimumSize(QSize(0, 14));
        equalSign->setMaximumSize(QSize(16777215, 500));
        equalSign->setSizeIncrement(QSize(75, 0));
        equalSign->setFont(font1);

        gridLayout->addWidget(equalSign, 7, 3, 2, 1);

        clear = new QPushButton(widget);
        clear->setObjectName("clear");
        clear->setMinimumSize(QSize(0, 40));
        clear->setMaximumSize(QSize(16777215, 500));
        clear->setFont(font4);

        gridLayout->addWidget(clear, 2, 2, 1, 1);

        plusOrMinus = new QPushButton(widget);
        plusOrMinus->setObjectName("plusOrMinus");
        plusOrMinus->setMinimumSize(QSize(0, 40));
        plusOrMinus->setMaximumSize(QSize(16777215, 500));
        plusOrMinus->setFont(font1);

        gridLayout->addWidget(plusOrMinus, 8, 0, 1, 1);

        openBracket = new QPushButton(widget);
        openBracket->setObjectName("openBracket");
        openBracket->setMinimumSize(QSize(0, 40));
        openBracket->setMaximumSize(QSize(16777215, 500));
        openBracket->setFont(font1);

        gridLayout->addWidget(openBracket, 4, 0, 1, 1);

        square = new QPushButton(widget);
        square->setObjectName("square");
        square->setMinimumSize(QSize(0, 40));
        square->setMaximumSize(QSize(16777215, 500));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Microsoft YaHei UI")});
        font5.setPointSize(20);
        font5.setBold(false);
        font5.setItalic(false);
        square->setFont(font5);

        gridLayout->addWidget(square, 4, 2, 1, 1);

        PI = new QPushButton(widget);
        PI->setObjectName("PI");
        PI->setMinimumSize(QSize(0, 40));
        PI->setMaximumSize(QSize(16777215, 500));
        QFont font6;
        font6.setPointSize(20);
        font6.setBold(false);
        font6.setItalic(false);
        PI->setFont(font6);

        gridLayout->addWidget(PI, 3, 0, 1, 1);

        naturalConstant = new QPushButton(widget);
        naturalConstant->setObjectName("naturalConstant");
        naturalConstant->setMinimumSize(QSize(0, 40));
        naturalConstant->setMaximumSize(QSize(16777215, 500));
        naturalConstant->setFont(font6);

        gridLayout->addWidget(naturalConstant, 3, 1, 1, 1);

        closingParenthesis = new QPushButton(widget);
        closingParenthesis->setObjectName("closingParenthesis");
        closingParenthesis->setMinimumSize(QSize(0, 40));
        closingParenthesis->setMaximumSize(QSize(16777215, 500));
        closingParenthesis->setFont(font1);

        gridLayout->addWidget(closingParenthesis, 4, 1, 1, 1);

        clearEntry = new QPushButton(widget);
        clearEntry->setObjectName("clearEntry");
        clearEntry->setMinimumSize(QSize(0, 40));
        clearEntry->setMaximumSize(QSize(16777215, 500));
        clearEntry->setFont(font1);

        gridLayout->addWidget(clearEntry, 2, 1, 1, 1);

        factorial = new QPushButton(widget);
        factorial->setObjectName("factorial");
        factorial->setMinimumSize(QSize(0, 40));
        factorial->setMaximumSize(QSize(16777215, 500));
        factorial->setFont(font5);

        gridLayout->addWidget(factorial, 3, 2, 1, 1);


        retranslateUi(widget);

        QMetaObject::connectSlotsByName(widget);
    } // setupUi

    void retranslateUi(QWidget *widget)
    {
        widget->setWindowTitle(QCoreApplication::translate("widget", "widget", nullptr));
        divisionSign->setText(QCoreApplication::translate("widget", "\303\267", nullptr));
        enter2->setText(QCoreApplication::translate("widget", "2", nullptr));
        enter4->setText(QCoreApplication::translate("widget", "4", nullptr));
        enter1->setText(QCoreApplication::translate("widget", "1", nullptr));
        enter9->setText(QCoreApplication::translate("widget", "9", nullptr));
        label_2->setText(QString());
        decimalPoint->setText(QCoreApplication::translate("widget", ".", nullptr));
        enter6->setText(QCoreApplication::translate("widget", "6", nullptr));
        enter8->setText(QCoreApplication::translate("widget", "8", nullptr));
        enter0->setText(QCoreApplication::translate("widget", "0", nullptr));
        label->setText(QCoreApplication::translate("widget", "<html><head/><body><p align=\"right\"><br/></p></body></html>", nullptr));
        minusSign->setText(QCoreApplication::translate("widget", "\342\200\224", nullptr));
        enter5->setText(QCoreApplication::translate("widget", "5", nullptr));
        plusSign->setText(QCoreApplication::translate("widget", "+", nullptr));
        enter3->setText(QCoreApplication::translate("widget", "3", nullptr));
        mutiplicationSign->setText(QCoreApplication::translate("widget", "\303\227", nullptr));
        enter7->setText(QCoreApplication::translate("widget", "7", nullptr));
        backspace->setText(QCoreApplication::translate("widget", "<\342\200\224", nullptr));
        equalSign->setText(QCoreApplication::translate("widget", "=", nullptr));
        clear->setText(QCoreApplication::translate("widget", "C", nullptr));
        plusOrMinus->setText(QCoreApplication::translate("widget", "+/-", nullptr));
        openBracket->setText(QCoreApplication::translate("widget", "(", nullptr));
        square->setText(QCoreApplication::translate("widget", "^", nullptr));
        PI->setText(QCoreApplication::translate("widget", "\317\200", nullptr));
        naturalConstant->setText(QCoreApplication::translate("widget", "e", nullptr));
        closingParenthesis->setText(QCoreApplication::translate("widget", ")", nullptr));
        clearEntry->setText(QCoreApplication::translate("widget", "CE", nullptr));
        factorial->setText(QCoreApplication::translate("widget", "n!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class widget: public Ui_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
