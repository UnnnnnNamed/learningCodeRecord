//
// Created by wood on 2022/12/25.
//

#ifndef CALCULATOR_WIDGET_H
#define CALCULATOR_WIDGET_H

#include <QWidget>
#include <QPushButton>


QT_BEGIN_NAMESPACE
namespace Ui { class widget; }
QT_END_NAMESPACE

class widget : public QWidget {
Q_OBJECT

public:
    explicit widget(QWidget *parent = nullptr);
    ~widget() override;

private slots:
    void on_enter0_clicked();

    void on_enter1_clicked();

    void on_enter2_clicked();

    void on_enter3_clicked();

    void on_enter4_clicked();

    void on_enter5_clicked();

    void on_enter6_clicked();

    void on_enter7_clicked();

    void on_enter8_clicked();

    void on_enter9_clicked();

    void on_decimalPoint_clicked();

    void on_openBracket_clicked();

    void on_closingParenthesis_clicked();

    void on_plusSign_clicked();

    void on_minusSign_clicked();

    void on_mutiplicationSign_clicked();

    void on_divisionSign_clicked();

    void on_clearEntry_clicked();

    void on_clear_clicked();

    void on_backspace_clicked();

    void on_PI_clicked();

    void on_naturalConstant_clicked();

    void on_square_clicked();

    void on_equalSign_clicked();

    void on_plusOrMinus_clicked();

    void on_factorial_clicked();

private:
    Ui::widget *ui;
    QString input;
    QString result;
    QString formula;
    int leftRemain=0;
    bool hasPoint = false;
    bool special = false;
    bool hasAnswer = false;


    void enterNumber(QString num);

    void enterOperator(QString opera,QString operaFor);
};


#endif //CALCULATOR_WIDGET_H
