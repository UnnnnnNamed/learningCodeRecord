//
// Created by wood on 2022/12/25.
//

#ifndef CALCULATOR_CALCULATE_H
#define CALCULATOR_CALCULATE_H
#include "QMainWindow"
using namespace std;

QString wrongCheck(QString str,int leftRemain){
    if(leftRemain!=0)return " 括号数量不匹配";
    string formula = str.toStdString();
    for(int i=0;i<formula.length();i++){
        if(formula[i]=='0'&&formula[i-1]=='/'){
            int flagZero = true;
            if(formula[i+1]!='.'){
                return " 除数不能为0";
            }else{
                for(int m=i+2;;m++){
                    if(formula[m]=='+'||formula[m]=='-'||formula[m]=='*'||formula[m]=='/'||formula[m]=='^'){
                        break;
                    }else if(formula[m]!='0'){
                        flagZero= false;
                        break;
                    }
                }
            }
            if(flagZero)return " 除数不能为0";
        }
        if(formula[i]=='('&&formula[i+2]==')')return " 无法处理(num)类型数据";
        if((formula[i]=='.'&&(formula[i+1]=='*'||formula[i+1]=='/'||formula[i+1]=='+'||formula[i+1]=='-'||formula[i+1]=='^'))||formula.back()=='.'){
            return " 小数点后无数字";
        }
    }
    return "TRUE";
}
typedef struct btNode{
    double data;//数字型节点
    char Operator;//运算符型节点
    struct btNode *lChild;
    struct btNode *rChild;
}btNode;

btNode* afaToBtree(char *input, int begin, int end){
    int i;
    int localR=0,flag=0;
    int power=0,mnd=0,ans=0,x=0;//power=Power Side;mnd = Multiply And Divide;ans = Addition And Subtraction
    double coe;//系数
    for(i=begin; i < end; i++)
        if(input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i]=='/'||input[i]=='^')
            x++;
    if(!x){
        double y = 0;
        bool isDecimal=false;
        for(i=begin, coe=1; i <= end - 1; i++){
            if(input[i]=='.'){
                isDecimal = true;
                continue;
            }
            if(!isDecimal){
                y = y * 10 + (input[i] - '0');
            }else{
                coe/=10;
                y = y + coe * (input[i] - '0');
            }
        }//数字
        btNode* bn=(struct btNode*)malloc(sizeof(struct btNode));
        bn->data=y;
        bn->Operator=NULL;
        bn->lChild=NULL;
        bn->rChild=NULL;
        return bn;//将该数字的值返回给节点的data中
    }
    for(i=begin; i < end; i++){
        if(input[i]=='(')
            flag++;
        else if(input[i]==')')
            flag--;//判断该字符是否在括号内，在内flag为1，在外为0
        if(!flag){
            if(input[i]=='^')
                power=i;
            else if(input[i]=='*'||input[i]=='/')
                mnd=i;//将括号外的最右侧的*或/号的位置记录下来
            else if(input[i]=='+'||input[i]=='-')
                ans=i;//将括号外的最右侧的+或-号的位置记录下来
        }
    }
    if((power == 0) && (mnd == 0) && (ans == 0)){
        afaToBtree(input, begin + 1, end - 1);//去掉最外层的括号
    }else{
        if(ans > 0)
            localR=ans;
        else if(mnd > 0)
            localR=mnd;
        else if (power > 0)
            localR=power;//将记录下的+-或*/号记录下来，作为根节点
        btNode* b=(struct btNode*)malloc(sizeof(struct btNode));
        b->Operator=input[localR];
        b->lChild=afaToBtree(input, begin, localR);
        b->rChild=afaToBtree(input, localR + 1, end);//对该根节点的左侧和右侧分别再次操作
        return b;
    }
}

double cal(btNode *root){
    double v1,v2;
    if(root->lChild==NULL&&root->rChild==NULL)return root->data;
    v1= cal(root->lChild);
    v2= cal(root->rChild);
    switch(root->Operator){
        case '+':
            return v1+v2;
        case '-':
            return v1-v2;
        case '/':
            return v1/v2;
        case '*':
            return v1*v2;
        case '^':
            return pow(v1,v2);//通过对根节点的运算符的遍历，判断加减乘除并进行操作，最后将结果返回
    }
    return root->data;
}

QString doubleToQStr(double num){
    QString str;
    QString tempStr;
    if(num==(int)num){
        tempStr = QString("%1").arg(num, 0, 'f', 0);
        if(tempStr.length()>21)str = QString("%1").arg(num);
        else str=tempStr;
    }else{
        tempStr = QString("%1").arg(num,0,'f',5);
        if(tempStr.length()>21)str = QString("%1").arg(num);
        else{
            int record = 5;
            for (int i = 0; i < tempStr.length(); i++) {
                if (tempStr[tempStr.length() - i - 1] != '0') {
                    break;
                } else {
                    record--;
                }
            }
            str = QString("%1").arg(num, 0, 'f', record);
        }
    }
    return str;
}

void FirstOrder(btNode *T){
    if(T== nullptr)return;
    if(T->Operator)cout<<T->Operator<<"  ";
    else cout<<T->data<<"  ";
    FirstOrder(T->lChild);
    FirstOrder(T->rChild);
}
void MiddleOrder(btNode *T){
    if(T== nullptr)return;
    MiddleOrder(T->lChild);
    if(T->Operator)cout<<T->Operator<<"  ";
    else cout<<T->data<<"  ";
    MiddleOrder(T->rChild);
}
void PostOrder(btNode *T){
    if(T== nullptr)return;
    PostOrder(T->lChild);
    PostOrder(T->rChild);
    if(T->Operator)cout<<T->Operator<<"  ";
    else cout<<T->data<<"  ";
}
#endif //CALCULATOR_CALCULATE_H
