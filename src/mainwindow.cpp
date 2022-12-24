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

void MainWindow::on_pushButton_equally_clicked()
{
    QByteArray tmp = ui->input_string->text().toLocal8Bit();
    char *src = tmp.data();
    double result = 0;

    int error = 0;
    QString x_val = ui->x_value->text();
    double x = x_val.toDouble();
    error = main_calc(src, x, &result);
    if (error) {
        ui->input_string->setText("Input error!");
    } else {
        QString res_val = QString::number((double)result);
        ui->input_string->setText(res_val);
    }


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




void MainWindow::on_pushButton_graphic_clicked()
{
    ui->widget->clearGraphs();

//    QString xMa = ui->lineEdit_xmax->text();
//    long double xMax = xMa.toDouble();

//    QString xMi = ui->lineEdit_xmin->text();
//    long double xMin = xMi.toDouble();

//    QString yMa = ui->lineEdit_ymax->text();
//    long double yMax = yMa.toDouble();

//    QString yMi = ui->lineEdit_ymin->text();
//    long double yMin = yMi.toDouble();

//    QString ste = ui->lineEdit_step->text();
//    long double step = ste.toDouble();

//    if (axis_validation(xMax, xMin, yMin, yMax)) {
//        xBegin = xMin;
//        xEnd = xMax;
//        h = step;
//        N = (xEnd - xBegin)/h + 2;
        ui->widget->xAxis->setRange(-10, 10);
        ui->widget->yAxis->setRange(-10, 10);

        QByteArray tmp = ui->input_string->text().toLocal8Bit();
        char* expression = tmp.data();
        double result;
        for (X = -10; X <= 10; X += 0.1) {
            x.push_back(X);
//            qt_entry(expression, X, &result);
            main_calc(expression, X, &result);
            y.push_back(result);
        }
        ui->widget->addGraph();
        ui->widget->graph(0)->addData(x, y);
        ui->widget->replot();
        x.clear();
        y.clear();

//        if (validation(expression)) {
//            for (X = xBegin; X <= xEnd; X += h) {
//                x.push_back(X);
//                qt_entry(expression, X, &result);
//                y.push_back(result);
//            }
//            ui->widget->addGraph();
//            ui->widget->graph(0)->addData(x, y);
//            ui->widget->replot();
//            x.clear();
//            y.clear();
//        } else {
//            QMessageBox::about(this, "Error", "Invalid input");
//        }
//    } else {
//        QMessageBox::about(this, "Error", "Invalid input");
//    }

}

