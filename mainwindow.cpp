#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setMaximumSize(300,300);
    this->setMinimumSize(200,200);

    this->setWindowTitle("计算器");

    QFont f("微软雅黑",10);
    ui->mainlineEdit->setFont(f);

    //按钮修改图片
    QIcon con("G:\\qtproject\\cal\\delete.png");
    ui->deleteButton->setIcon(con);

    //修改按钮背景色
    ui->sumButton->setStyleSheet("background:purple");
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_zeroButton_clicked()
{
    expression += "0";
    ui->mainlineEdit->setText(expression);
}

void MainWindow::on_oneButton_clicked()
{
    expression += "1";
    ui->mainlineEdit->setText(expression);
}
void MainWindow::on_twoButton_clicked()
{
    expression += "2";
    ui->mainlineEdit->setText(expression);
}
void MainWindow::on_threeButton_clicked()
{
    expression += "3";
    ui->mainlineEdit->setText(expression);
}
void MainWindow::on_fourButton_clicked()
{
    expression += "4";
    ui->mainlineEdit->setText(expression);
}
void MainWindow::on_fiveButton_clicked()
{
    expression += "5";
    ui->mainlineEdit->setText(expression);
}
void MainWindow::on_sixButton_clicked()
{
    expression += "6";
    ui->mainlineEdit->setText(expression);
}
void MainWindow::on_sevenButton_clicked()
{
    expression += "7";
    ui->mainlineEdit->setText(expression);
}
void MainWindow::on_eightButton_clicked()
{
    expression += "8";
    ui->mainlineEdit->setText(expression);
}
void MainWindow::on_nineButton_clicked()
{
    expression += "9";
    ui->mainlineEdit->setText(expression);
}
void MainWindow::on_addButton_clicked()
{
    expression += "+";
    ui->mainlineEdit->setText(expression);
}

void MainWindow::on_divButton_clicked()
{
    expression += "/";
    ui->mainlineEdit->setText(expression);
}

void MainWindow::on_subButton_clicked()
{
    expression += "-";
    ui->mainlineEdit->setText(expression);
}

void MainWindow::on_mulButton_clicked()
{
    expression += "*";
    ui->mainlineEdit->setText(expression);
}

void MainWindow::on_leftButton_clicked()
{
    expression += "(";
    ui->mainlineEdit->setText(expression);
}

void MainWindow::on_rightButton_clicked()
{
    expression += ")";
    ui->mainlineEdit->setText(expression);
}

void MainWindow::on_clearButton_clicked()
{
    expression.clear();
    ui->mainlineEdit->clear();
}

void MainWindow::on_deleteButton_clicked()
{
    expression.chop(1);
    ui->mainlineEdit->setText(expression);
}

void MainWindow::on_sumButton_clicked()
{
    QStack<int> s_num, s_opt;
    char opt[128] = {0};
    int i = 0, tmp = 0, num1, num2;

    QByteArray ba;
    ba.append(expression); //把QString转换成QByteArray
    strcpy(opt, ba.data()); //data把QbyteArray转换成char*

    while (opt[i] != '\0' || s_opt.empty() != true)
    {
        if (opt[i] >= '0' && opt[i] <= '9')
        {
            tmp = tmp * 10 + opt[i] - '0';
            i++;
            if (opt[i] < '0' || opt[i] > '9')
            {
                s_num.push(tmp);
                tmp = 0;
            }
        }
        else //操作符
        {
            if (s_opt.empty() == true | Priority(opt[i]) > Priority(s_opt.top()) ||
                    (s_opt.top() == '(' && opt[i] != ')'))
            {
                s_opt.push(opt[i]);
                i++;
                continue;
            }

            if (s_opt.top() == '(' && opt[i] == '('){
                s_opt.pop();
                i++;
                continue;
            }

            if (Priority(opt[i]) <= Priority(s_opt.top()) || (opt[i] == ')' && s_opt.top() != '(')
                    || (opt[i] ==  '\0' && s_opt.empty() != true))
            {
                char ch = s_opt.top();
                s_opt.pop();
                switch (ch)
                {
                case '+':
                    num1 = s_num.top();
                    s_num.pop();
                    num2 = s_num.top();
                    s_num.pop();
                    s_num.push(num1 + num2);
                    break;
                case '-':
                    num1 = s_num.top();
                    s_num.pop();
                    num2 = s_num.top();
                    s_num.pop();
                    s_num.push(num1 - num2);
                    break;
                case '*':
                    num1 = s_num.top();
                    s_num.pop();
                    num2 = s_num.top();
                    s_num.pop();
                    s_num.push(num1 * num2);
                    break;
                case '/':
                    num1 = s_num.top();
                    s_num.pop();
                    num2 = s_num.top();
                    s_num.pop();
                    s_num.push(num1 / num2);
                    break;
                }
            }
        }
    }
    ui->mainlineEdit->setText(QString::number(s_num.top()));
    expression.clear();
}
int MainWindow::Priority(char ch){
    switch (ch)
    {
    case '(':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}
