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
    result = ui->label_2->text();
    if(hasAnswer){
        input = num;
        result = nullptr;
        hasAnswer= false;
        ui->label->setText(num);
        ui->label_2->setText(result);
    }else if(special){
        input = num;
        special = false;
    }else{
        if (input == "0") {
            input = num;
        }else if(input == "-0"){
            input = "-"+num;
        }else {
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


void widget::on_plusOrMinus_clicked()
{
    input = ui->label->text();
    result = ui->label_2->text();
    if(hasAnswer){
        result = nullptr;
        formula = nullptr;
        hasAnswer= false;
        ui->label_2->setText(result);
    }
    if(input[0]=='-'){
        input = input.replace("-","");
    }else{
        input = '-' + input;
    }
    ui->label->setText(input);
}


void widget::on_decimalPoint_clicked()
{
    input = ui->label->text();
    result = ui->label_2->text();
    if(hasAnswer){
        input = "0";
        result = nullptr;
        formula = nullptr;
        hasAnswer= false;
        ui->label->setText(input);
        ui->label_2->setText(result);
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
    result = ui->label_2->text();
    if(hasAnswer){
        input = "0";
        result = nullptr;
        formula = nullptr;
        hasAnswer= false;
        ui->label_2->setText(result);
    }
    result = ui->label_2->text();
    if(result!= nullptr&&result.back()==')'){
        formula = formula + '+';
        result = result+'+';
    }
    formula = formula + '(';
    result = result+'(';
    input = nullptr;
    input = "0";
    leftRemain++;
    ui->label->setText(input);
    hasPoint= false;
    ui->label_2->setText(result);
}


void widget::on_closingParenthesis_clicked()
{
    if(leftRemain>0){
        result = ui->label_2->text();
        if (hasAnswer) {
            result = nullptr;
            formula = nullptr;
            hasAnswer = false;
            ui->label_2->setText(result);
        }
        leftRemain--;
        input = ui->label->text();
        result = ui->label_2->text();
        if(result.back()==')'){
            formula = formula + ')';
            result = result + ')';
        }else{
            formula = formula + input + ')';
            result = result + input + ')';
        }
        input = nullptr;
        input = "0";
        ui->label->setText(input);
        hasPoint = false;
        ui->label_2->setText(result);
    }
}


void widget::enterOperator(QString opera,QString operaFor){
    result = ui->label_2->text();
    if(hasAnswer){
        result = nullptr;
        formula = nullptr;
        hasAnswer= false;
        ui->label_2->setText(result);
    }
    input = ui->label->text();
    result = ui->label_2->text();
    if(input[0]==' ')input = "0";
    if(result== nullptr){
        formula = input+operaFor;
        result = input+opera;
    }else if(result.back()!=')'&&result.back()!='!'){
        formula = formula + input + operaFor;
        result = result + input + opera;
    }else{
        formula=formula+operaFor;
        result=result+opera;
    }
    ui->label_2->setText(result);
    input= "0";
    hasPoint= false;
    ui->label->setText(input);
}


void widget::on_plusSign_clicked()
{
    enterOperator("+","+");
}


void widget::on_minusSign_clicked()
{
    enterOperator("-","-");
}


void widget::on_mutiplicationSign_clicked()
{
    enterOperator("×","*");
}


void widget::on_divisionSign_clicked()
{
    enterOperator("÷","/");
}


void widget::on_square_clicked()
{
    result = ui->label_2->text();
    if(hasAnswer){
        result = nullptr;
        formula = nullptr;
        hasAnswer= false;
        ui->label_2->setText(result);
    }
    input = ui->label->text();
    result = ui->label_2->text();
    if(input[0]==' ')input = "0";
    if(result == nullptr){
        result = input + "^";
        formula = input + "^";
        input = "0";
    }else if(result.back() == ')'){
        result = result + "^";
        formula = formula + "^";
        input = "0";
    }else{
        result = result + input + '^';
        formula = formula + input +  "^";
        input = "0";
    }
    ui->label_2->setText(result);
    ui->label->setText(input);
    hasPoint= false;
}


void widget::on_factorial_clicked()//简单阶乘，暂无法处理括号及小数
{
    input = ui->label->text();
    result = ui->label_2->text();
    if(hasAnswer){
        result = nullptr;
        formula = nullptr;
        hasAnswer= false;
        ui->label_2->setText(result);
    }
    if(result!= nullptr&&result.back()==')') {
        result = result + "!";
        formula = formula + "!";
    }else{
        input = input + "!";
        result = result + input;
        formula = formula + input;
    }
    input = "0";
    ui->label->setText(input);
    ui->label_2->setText(result);
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
    result = ui->label_2->text();
    input = "0";
    result = nullptr;
    formula = nullptr;
    leftRemain = 0;
    ui->label_2->setText(result);
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
        result = ui->label_2->text();
        result= nullptr;
        formula = nullptr;
        hasAnswer = false;
        ui->label_2->setText(result);
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
        result = ui->label_2->text();
        result= nullptr;
        formula = nullptr;
        hasAnswer = false;
        ui->label_2->setText(result);
    }
    special = true;
    hasPoint= false;
    ui->label->setText(input);
}


void widget::on_equalSign_clicked()
{
    result = ui->label_2->text();
    if(hasAnswer){
        result = nullptr;
        formula = nullptr;
        hasAnswer= false;
        ui->label_2->setText(result);
    }
    input = ui->label->text();
    result = ui->label_2->text();
    if(result == nullptr){
        result = input;
        formula = input;
    }else if(result[0] == ' '){
        input = "0";
        result = "0";
        formula = nullptr;
    }else if(result.back() != ')' && result.back() != '('&&result.back()!='!'){
        result = result + input;
        formula = formula + input;
    }
    input = wrongCheck(formula, leftRemain);
    if(input=="TRUE"){
        bool isZero = false;
        bool minusFactorial = false;
        char* str;
        QByteArray ba = formula.toLatin1();
        str= ba.data();
        btNode *btNode;
        btNode = createBtTree(str, 0, strlen(str),minusFactorial);
        double tempResult= cal(btNode,isZero);
        input = doubleToQStr(tempResult);
        if(isZero)input = " 除数不能为0";
        else if(minusFactorial)input = " 出现负数阶乘";
        else{
            cout << "Formula = " << formula.toStdString() << endl;
            FirstOrder(btNode);
            cout << endl;
            MiddleOrder(btNode);
            cout << endl;
            PostOrder(btNode);
            cout << endl;
            cout << "Result  = " << tempResult << endl;
        cout<<"------------------------------------------------------------"<<endl;
        }
    }
    ui->label->setText(input);
    ui->label_2->setText(result);
    hasPoint = false;
    special= false;
    leftRemain = 0;
    hasAnswer = true;
    formula = nullptr;
}