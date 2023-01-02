//
// Created by wood on 2022/12/25.
//

// You may need to build the project (run Qt uic code generator) to get "ui_widget.h" resolved
#include "iostream"
#include "widget.h"
#include "ui_widget.h"
#include "QStyleFactory"
#include "calculate.h"
widget::widget(QWidget *parent) :
        QWidget(parent), ui(new Ui::widget) {
    ui->setupUi(this);
    QApplication::setStyle(QStyleFactory::create("Fusion"));
    this->setWindowTitle("Calculator");
    ui->label->setText("0");
}
widget::~widget() {
    delete ui;
}


void widget::enterNumber(QString num){
    input = ui->label->text();
    formula = ui->label_2->text();
    if(hasAnswer){
        input = num;
        formula = nullptr;
        hasAnswer= false;
        ui->label->setText(num);
        ui->label_2->setText(formula);
    }else if(special){
        input = num;
        special = false;
    }else{
        if (input == "0") {
            input = num;
        } else {
            input = input + num;
        }
    }
    ui->label->setText(input);
}


void widget::on_enter0_clicked()
{
    enterNumber("0");
}

void widget::on_enter1_clicked()
{
    enterNumber("1");
}


void widget::on_enter2_clicked()
{
    enterNumber("2");
}


void widget::on_enter3_clicked()
{
    enterNumber("3");
}


void widget::on_enter4_clicked()
{
    enterNumber("4");
}


void widget::on_enter5_clicked()
{
    enterNumber("5");
}


void widget::on_enter6_clicked()
{
    enterNumber("6");
}


void widget::on_enter7_clicked()
{
    enterNumber("7");
}


void widget::on_enter8_clicked()
{
    enterNumber("8");
}


void widget::on_enter9_clicked()
{
    enterNumber("9");
}


void widget::on_decimalPoint_clicked()
{
    input = ui->label->text();
    formula = ui->label_2->text();
    if(hasAnswer){
        input = "0";
        formula = nullptr;
        hasAnswer= false;
        ui->label->setText(input);
        ui->label_2->setText(formula);
    }
    if(special){
        input = "0";
        special= false;
    }
    if(!hasPoint){
        input = input+'.';
        hasPoint = true;
    }
    ui->label->setText(input);
}



void widget::on_openBracket_clicked()
{
    input = ui->label->text();
    formula = ui->label_2->text();
    if(hasAnswer){
        input = "0";
        formula = nullptr;
        hasAnswer= false;
        ui->label_2->setText(formula);
    }
    formula = ui->label_2->text();
    if(formula != nullptr && formula.back() == ')'){
        formula = formula + '+';
    }
    formula = formula + '(';
    input = nullptr;
    input = "0";
    leftRemain++;
    ui->label->setText(input);
    hasPoint= false;
    ui->label_2->setText(formula);
}


void widget::on_closingParenthesis_clicked()
{
    if(leftRemain>0){
        formula = ui->label_2->text();
        if (hasAnswer) {
            formula = nullptr;
            hasAnswer = false;
            ui->label_2->setText(formula);
        }
        leftRemain--;
        input = ui->label->text();
        formula = ui->label_2->text();
        if(formula.back() == ')'){
            formula = formula + ')';
        }else{
            formula = formula + input + ')';
        }
        input = nullptr;
        input = "0";
        ui->label->setText(input);
        hasPoint = false;
        ui->label_2->setText(formula);
    }
}


void widget::on_plusSign_clicked()
{
    formula = ui->label_2->text();
    if(hasAnswer){
        formula = nullptr;
        hasAnswer= false;
        ui->label_2->setText(formula);
    }
    input = ui->label->text();
    formula = ui->label_2->text();
    if(input[0]==' ')input = "0";
    if(formula == nullptr){
        formula = input + '+';
    }else if(formula.back() == '-'||formula.back()=='*'||formula.back()=='/'||formula.back()=='^'){
        formula.back()='+';
    }else if(formula.back()!=')'){
        formula= formula + input + '+';
    }else{
        formula = formula+'+';
    }
    ui->label_2->setText(formula);
    input= "0";
    hasPoint= false;
    ui->label->setText(input);
}


void widget::on_minusSign_clicked()
{
    formula = ui->label_2->text();
    if(hasAnswer){
        formula = nullptr;
        hasAnswer= false;
        ui->label_2->setText(formula);
    }
    input = ui->label->text();
    formula = ui->label_2->text();
    if(input[0]==' ')input = "0";
    if(formula == nullptr){
        formula = input + '-';
    }else if(formula.back() == '+'||formula.back()=='*'||formula.back()=='/'||formula.back()=='^'){
        formula.back()='-';
    }else if(formula.back()!=')'){
        formula= formula + input + '-';
    }else{
        formula = formula+'-';
    }
    ui->label_2->setText(formula);
    input= "0";
    hasPoint= false;
    ui->label->setText(input);
}


void widget::on_mutiplicationSign_clicked()
{
    formula = ui->label_2->text();
    if(hasAnswer){
        formula = nullptr;
        hasAnswer= false;
        ui->label_2->setText(formula);
    }
    input = ui->label->text();
    formula = ui->label_2->text();
    if(input[0]==' ')input = "0";
    if(formula == nullptr){
        formula = input + "*";
    }else if(formula.back() == '-'||formula.back()=='+'||formula.back()=='/'||formula.back()=='^'){
        formula.back()='*';
    }else if(formula.back()!=')'){
        formula= formula + input + '*';
    }else{
        formula = formula+'*';
    }
    ui->label_2->setText(formula);
    input= "0";
    hasPoint= false;
    ui->label->setText(input);
}


void widget::on_divisionSign_clicked()
{
    formula = ui->label_2->text();
    if(hasAnswer){
        formula = nullptr;
        hasAnswer= false;
        ui->label_2->setText(formula);
    }
    input = ui->label->text();
    formula = ui->label_2->text();
    if(input[0]==' ')input = "0";
    if(formula == nullptr){
        formula = input + "/";
    }else if(formula.back() == '-'||formula.back()=='*'||formula.back()=='+'||formula.back()=='^'){
        formula.back()='/';
    }else if(formula.back()!=')'){
        formula= formula + input + '/';
    }else{
        formula = formula+'/';
    }
    ui->label_2->setText(formula);
    input= "0";
    hasPoint= false;
    ui->label->setText(input);
}


void widget::on_square_clicked()
{
    formula = ui->label_2->text();
    if(hasAnswer){
        formula = nullptr;
        hasAnswer= false;
        ui->label_2->setText(formula);
    }
    input = ui->label->text();
    formula = ui->label_2->text();
    if(input[0]==' ')input = "0";
    if(formula == nullptr){
        formula = input + "^";
        input = "0";
    }else if(formula.back()=='+'||formula.back()=='-'||formula.back()=='*'||formula.back()=='/'){
        formula.back()='^';
        input = "0";
    }else if(formula.back()==')'){
        formula = formula + "^";
        input = "0";
    }else{
        formula = formula + input + '^';
        input = "0";
    }
    ui->label_2->setText(formula);
    ui->label->setText(input);
    hasPoint= false;
}


void widget::on_clearEntry_clicked()
{
    hasPoint= false;
    input = ui->label->text();
    input = "0";
    ui->label->setText(input);
}


void widget::on_clear_clicked()
{
    hasPoint= false;
    input = ui->label->text();
    formula = ui->label_2->text();
    input = "0";
    formula = nullptr;
    leftRemain = 0;
    ui->label_2->setText(formula);
    ui->label->setText(input);
}


void widget::on_backspace_clicked()
{
    input = ui->label->text();
    if(hasAnswer)input="0";
    int len = input.length();
    if(input[0]==' ')input = "0";
    if(len==1){
        input = "0";
    }else{
        if(input.back()=='.'){
            hasPoint= false;
        }
        input.chop(1);
    }
    ui->label->setText(input);
}


void widget::on_PI_clicked()
{
    //3.141592653
    input = ui->label->text();
    input = "3.14159";
    if(hasAnswer){
        formula = ui->label_2->text();
        formula= nullptr;
        hasAnswer = false;
        ui->label_2->setText(formula);
    }
    special = true;
    hasPoint= false;
    ui->label->setText(input);
}


void widget::on_naturalConstant_clicked()
{
    //2.718281828
    input = ui->label->text();
    input = "2.71828";
    if(hasAnswer){
        formula = ui->label_2->text();
        formula= nullptr;
        hasAnswer = false;
        ui->label_2->setText(formula);
    }
    special = true;
    hasPoint= false;
    ui->label->setText(input);
}


void widget::on_equalSign_clicked()
{
    formula = ui->label_2->text();
    if(hasAnswer){
        formula = nullptr;
        hasAnswer= false;
        ui->label_2->setText(formula);
    }
    input = ui->label->text();
    formula = ui->label_2->text();
    if(formula == nullptr){
        formula = input;
    }else if(formula[0]==' '){
        input = "0";
        formula = "0";
    }else if(formula.back() != ')' && formula.back() != '('){
        formula = formula + input;
    }
    input = wrongCheck(formula,leftRemain);
    if(input=="TRUE"){
        cout<<"Formula = "<<formula.toStdString()<<endl;
        char* str;
        QByteArray ba = formula.toLatin1();
        str= ba.data();
        btNode *btNode;
        btNode = afaToBtree(str,0,strlen(str));
        FirstOrder(btNode);
        cout<<endl;
        MiddleOrder(btNode);
        cout<<endl;
        PostOrder(btNode);
        cout<<endl;
        double tempResult= cal(btNode);
        cout<<"Result = "<<tempResult<<endl;
        cout<<"------------------------------------------------------------"<<endl;
        input = doubleToQStr(tempResult);
    }
    ui->label->setText(input);
    ui->label_2->setText(formula);
    hasPoint = false;
    special= false;
    leftRemain = 0;
    hasAnswer = true;
    formula = nullptr;
}

