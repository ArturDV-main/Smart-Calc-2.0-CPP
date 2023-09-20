#include "s21_view_qt.h"
#include "ui_s21_view_qt.h"


MainWindow::MainWindow(QWidget *parent, s21::CalcController * calc_controller)
    : QMainWindow(parent),calc(calc_controller), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ConnectsRelise();
//  calc = calc_controller;
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::x_button_push() {}

void MainWindow::digits_numbers() {
    QString str = ui->result->text();
    QString new_str;
    QPushButton *button = (QPushButton *)sender();
    if(ui->result->text() != "0") {
      ui->result->setText(ui->result->text() + button->text());
    } else {
      ui->result->setText(button->text());
    }
}

//  Умные скобки, ставится та скобка, которая должна быть
void MainWindow::skobki() {
}

void MainWindow::AC_button() {
    ui->result->setText("0");
}

void MainWindow::equals_button() {
}

void MainWindow::graf_button() {}

void MainWindow::func_button() {}

void MainWindow::simp_math_button() {}

void MainWindow::on_cred_Button_clicked() {}

void MainWindow::on_line_X_cursorPositionChanged() {}

void MainWindow::on_line_X_from_cursorPositionChanged() {}

void MainWindow::on_line_X_to_cursorPositionChanged() {}

void MainWindow::on_line_Y_from_cursorPositionChanged() {}

void MainWindow::on_line_Y_to_cursorPositionChanged() {}

void MainWindow::ConnectsRelise() {
    //  Кнопки с цифрами
    connect(ui->push_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->push_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->push_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->push_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->push_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->push_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->push_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->push_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->push_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->push_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    //  Кнопка Х
    connect(ui->push_X, SIGNAL(clicked()), this, SLOT(x_button_push()));
    //  Рабочие кнопки
    connect(ui->push_AC, SIGNAL(clicked()), this, SLOT(AC_button()));
    connect(ui->push_ravno, SIGNAL(clicked()), this, SLOT(equals_button()));
    connect(ui->push_graf, SIGNAL(clicked()), this, SLOT(graf_button()));
    //  Тригонометрия
    connect(ui->push_cos, SIGNAL(clicked()), this, SLOT(func_button()));
    connect(ui->push_sin, SIGNAL(clicked()), this, SLOT(func_button()));
    connect(ui->push_tan, SIGNAL(clicked()), this, SLOT(func_button()));
    connect(ui->push_acos, SIGNAL(clicked()), this, SLOT(func_button()));
    connect(ui->push_asin, SIGNAL(clicked()), this, SLOT(func_button()));
    connect(ui->push_atan, SIGNAL(clicked()), this, SLOT(func_button()));
    connect(ui->push_log, SIGNAL(clicked()), this, SLOT(func_button()));
    connect(ui->push_ln, SIGNAL(clicked()), this, SLOT(func_button()));
    connect(ui->push_sqrt, SIGNAL(clicked()), this, SLOT(func_button()));
    //  Простые операции
    connect(ui->push_plus, SIGNAL(clicked()), this, SLOT(simp_math_button()));
    connect(ui->push_minus, SIGNAL(clicked()), this, SLOT(simp_math_button()));
    connect(ui->push_mult, SIGNAL(clicked()), this, SLOT(simp_math_button()));
    connect(ui->push_div, SIGNAL(clicked()), this, SLOT(simp_math_button()));
    connect(ui->push_mod, SIGNAL(clicked()), this, SLOT(simp_math_button()));
    connect(ui->push_stepen, SIGNAL(clicked()), this, SLOT(simp_math_button()));
    //  Скобки
    connect(ui->push_scobka, SIGNAL(clicked()), this, SLOT(skobki()));
    //  Точка
    connect(ui->push_dot, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    //  Input lines

    connect(ui->line_Y_from, SIGNAL(cursorPositionChanged(int, int)), this,
            SLOT(on_line_Y_to_cursorPositionChanged()));
    connect(ui->line_Y_to, SIGNAL(cursorPositionChanged(int, int)), this,
            SLOT(on_line_Y_to_cursorPositionChanged()));
}
