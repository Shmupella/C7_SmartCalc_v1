#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::check_zero(const QString text)
{
    if (text == "0")
        ui->input_string->setText("");
}

void MainWindow::on_pushButton_zero_clicked()
{
    check_zero(ui->input_string->text());
    ui->input_string->setText(ui->input_string->text() + "0");
}


void MainWindow::on_pushButton_one_clicked()
{
    check_zero(ui->input_string->text());
    ui->input_string->setText(ui->input_string->text() + "1");
}


void MainWindow::on_pushButton_two_clicked()
{
    check_zero(ui->input_string->text());
    ui->input_string->setText(ui->input_string->text() + "2");
}


void MainWindow::on_pushButton_three_clicked()
{
    check_zero(ui->input_string->text());
    ui->input_string->setText(ui->input_string->text() + "3");
}


void MainWindow::on_pushButton_four_clicked()
{
    check_zero(ui->input_string->text());
    ui->input_string->setText(ui->input_string->text() + "4");
}


void MainWindow::on_pushButton_five_clicked()
{
    check_zero(ui->input_string->text());
    ui->input_string->setText(ui->input_string->text() + "5");
}


void MainWindow::on_pushButton_six_clicked()
{
    check_zero(ui->input_string->text());
    ui->input_string->setText(ui->input_string->text() + "6");
}


void MainWindow::on_pushButton_seven_clicked()
{
    check_zero(ui->input_string->text());
    ui->input_string->setText(ui->input_string->text() + "7");
}


void MainWindow::on_pushButton_eight_clicked()
{
    check_zero(ui->input_string->text());
    ui->input_string->setText(ui->input_string->text() + "8");
}


void MainWindow::on_pushButton_nine_clicked()
{
    check_zero(ui->input_string->text());
    ui->input_string->setText(ui->input_string->text() + "9");
}


void MainWindow::on_pushButton_dot_clicked()
{
    ui->input_string->setText(ui->input_string->text() + ".");
}


void MainWindow::on_pushButton_division_clicked()
{
    ui->input_string->setText(ui->input_string->text() + "/");
}


void MainWindow::on_pushButton_multiply_clicked()
{
    ui->input_string->setText(ui->input_string->text() + "*");
}


void MainWindow::on_pushButton_minus_clicked()
{
    ui->input_string->setText(ui->input_string->text() + "-");
}


void MainWindow::on_pushButton_plus_clicked()
{
    ui->input_string->setText(ui->input_string->text() + "+");
}


void MainWindow::on_pushButton_cos_clicked()
{
    check_zero(ui->input_string->text());
    ui->input_string->setText(ui->input_string->text() + "cos(");
}


void MainWindow::on_pushButton_sin_clicked()
{
    check_zero(ui->input_string->text());
    ui->input_string->setText(ui->input_string->text() + "sin(");
}


void MainWindow::on_pushButton_tan_clicked()
{
    check_zero(ui->input_string->text());
    ui->input_string->setText(ui->input_string->text() + "tan(");
}


void MainWindow::on_pushButton_acos_clicked()
{
    check_zero(ui->input_string->text());
    ui->input_string->setText(ui->input_string->text() + "acos(");
}


void MainWindow::on_pushButton_asin_clicked()
{
    check_zero(ui->input_string->text());
    ui->input_string->setText(ui->input_string->text() + "asin(");
}


void MainWindow::on_pushButton_atan_clicked()
{
    check_zero(ui->input_string->text());
    ui->input_string->setText(ui->input_string->text() + "atan(");
}


void MainWindow::on_pushButton_log_clicked()
{
    check_zero(ui->input_string->text());
    ui->input_string->setText(ui->input_string->text() + "log(");
}


void MainWindow::on_pushButton_ln_clicked()
{
    check_zero(ui->input_string->text());
    ui->input_string->setText(ui->input_string->text() + "ln(");
}


void MainWindow::on_pushButton_sqrt_clicked()
{
    check_zero(ui->input_string->text());
    ui->input_string->setText(ui->input_string->text() + "sqrt(");
}


void MainWindow::on_pushButton_pow_clicked()
{
    check_zero(ui->input_string->text());
    ui->input_string->setText(ui->input_string->text() + "^");
}


void MainWindow::on_pushButton_mod_clicked()
{
    check_zero(ui->input_string->text());
    ui->input_string->setText(ui->input_string->text() + "mod");
}


void MainWindow::on_pushButton_X_clicked()
{
    check_zero(ui->input_string->text());
    ui->input_string->setText(ui->input_string->text() + "x");
}


void MainWindow::on_pushButton_leftbracket_clicked()
{
    check_zero(ui->input_string->text());
    ui->input_string->setText(ui->input_string->text() + "(");
}


void MainWindow::on_pushButton_AC_clicked()
{
    ui->input_string->setText("0");
}


void MainWindow::on_pushButton_rightbracket_clicked()
{
    check_zero(ui->input_string->text());
    ui->input_string->setText(ui->input_string->text() + ")");
}


void MainWindow::on_pushButton_unaryminus_clicked()
{

}


void MainWindow::on_pushButton_equally_clicked()
{
    // QString xval = ui->lineEdit_x->text();
    // long double xv = xval.toDouble();
    QByteArray tmp = ui->input_string->text().toLocal8Bit();
    char *src = tmp.data();
    char *result = NULL;

    result = main_calc(src, 5);
    QString resvalue(result);
    ui->input_string->setText(resvalue);

//    if (validation(src)) {
//        double num = 0;
//        stack *res1 = NULL;
//        res1 = parcing(src);
//        res1 = polish(res1);
//        num = calculate(res1, xv);
//        QString resval = QString::number((double)num);
//        ui->result->setText(resval);
//    } else {
//        ui->result->setText("invalid expression");
//    }

}

