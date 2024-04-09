#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStack>
#include <string.h>
#include <QApplication>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_oneButton_clicked();

    void on_addButton_clicked();

    void on_divButton_clicked();

    void on_eightButton_clicked();

    void on_twoButton_clicked();

    void on_threeButton_clicked();

    void on_fourButton_clicked();

    void on_leftButton_clicked();

    void on_fiveButton_clicked();

    void on_sixButton_clicked();

    void on_sevenButton_clicked();

    void on_nineButton_clicked();

    void on_zeroButton_clicked();

    void on_subButton_clicked();

    void on_mulButton_clicked();

    void on_rightButton_clicked();

    void on_clearButton_clicked();

    void on_deleteButton_clicked();

    void on_sumButton_clicked();



private:
    Ui::MainWindow *ui;
    QString expression;

    int Priority(char ch);

};
#endif // MAINWINDOW_H
