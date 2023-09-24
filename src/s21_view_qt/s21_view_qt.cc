#include "s21_view_qt.h"

#include "ui_s21_view_qt.h"

MainWindow::MainWindow(QWidget *parent, s21::CalcController *calc_controller)
    : QMainWindow(parent), calc_(calc_controller), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ConnectsRelise();
  double_valid_ = new QDoubleValidator(-10000000, 10000000, 8, ui->line_X);
  double_valid_->setNotation(QDoubleValidator::StandardNotation);
  ui->line_X->setValidator(double_valid_);
  ui->line_X_from->setValidator(double_valid_);
  ui->line_X_to->setValidator(double_valid_);
  ui->line_Y_from->setValidator(double_valid_);
  ui->line_Y_to->setValidator(double_valid_);
  //  void DoubleValidInit();
}

MainWindow::~MainWindow() {
  delete ui;
  delete double_valid_;
}

void MainWindow::DoubleValidInit() {
  //  TODO
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
  qDebug() << event->key();
  switch (event->key()) {
    case Qt::Key_Space:
      BackspaseLogic();
      break;
    case Qt::Key_Backspace:
      BackspaseLogic();
      break;
    case Qt::Key_Enter:
      EqualsButton();
      break;
    case Qt::Key_Return:
      EqualsButton();
      break;
    default:
      LineEditEvent(char(event->key()));
  }
}
//  TODO
void MainWindow::LineEditEvent(char key) {
  QString tmp_str("1234567890-+*/.,");
  if (tmp_str.contains(char(key))) {
    LineInput((QString)key);
  } else {
    BackspaseLogic();
  }
}

void MainWindow::LineInput(QString str) {
  if (ui->result->text() == "0" || calc_done_)
    ui->result->setText(str);
  else
    ui->result->setText(ui->result->text() + str);
  calc_done_ = false;
}

void MainWindow::BackspaseLogic() {
  if (ui->result->text() == "0")
    return;
  else if (ui->result->text().size() == 1)
    ui->result->setText("0");
  else
    ui->result->backspace();
}

void MainWindow::EqualsButton() {
  QByteArray ba = (ui->result->text()).toLocal8Bit();
  const char *new_str = ba.data();  //  Преобразование в str* для СИ
  calc_->StartCalc(new_str, ui->line_X->text().toDouble());
  double result = calc_->GetResult();
  ui->result->setText(QString::number(result, 'g', 15));
  calc_done_ = true;
}

void MainWindow::x_button_push() {}

void MainWindow::digits_numbers() {
  QPushButton *button = (QPushButton *)sender();
  LineInput(button->text());
}

//  Умные скобки, ставится та скобка, которая должна быть
void MainWindow::skobki() {}

void MainWindow::AC_button() {
  ui->result->setText("0");
  calc_->Reset();
}

void MainWindow::C_button() { BackspaseLogic(); }

void MainWindow::graf_button() {}

void MainWindow::func_button() {}

void MainWindow::simp_math_button() {}

void MainWindow::on_cred_Button_clicked() {}

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
  connect(ui->push_X, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  //  Рабочие кнопки
  connect(ui->push_AC, SIGNAL(clicked()), this, SLOT(AC_button()));
  connect(ui->push_AC_2, SIGNAL(clicked()), this, SLOT(C_button()));
  connect(ui->push_ravno, SIGNAL(clicked()), this, SLOT(EqualsButton()));
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
  connect(ui->push_plus, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->push_minus, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->push_mult, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->push_div, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->push_mod, SIGNAL(clicked()), this, SLOT(simp_math_button()));
  connect(ui->push_stepen, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  //  Скобки
  connect(ui->push_scobka, SIGNAL(clicked()), this, SLOT(skobki()));
  //  Точка  TODO
  connect(ui->push_dot, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  //  Input lines
}
