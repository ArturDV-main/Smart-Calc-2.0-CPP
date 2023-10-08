#include "s21_view_qt.h"

#include "./ui_s21_view_qt.h"

MainWindow::MainWindow(QWidget *parent, s21::CalcController *calc_controller)
    : QMainWindow(parent), calc_(calc_controller), ui_(new Ui::MainWindow) {
  ui_->setupUi(this);
  ConnectsRelise();
  double_valid_ = new QDoubleValidator(-10000000, 10000000, 8, ui_->line_X);
  double_valid_->setNotation(QDoubleValidator::StandardNotation);
  ui_->line_X->setValidator(double_valid_);
  ui_->line_X_from->setValidator(double_valid_);
  ui_->line_X_to->setValidator(double_valid_);
  ui_->line_Y_from->setValidator(double_valid_);
  ui_->line_Y_to->setValidator(double_valid_);
  //  void DoubleValidInit();
}

MainWindow::~MainWindow() {
  delete ui_;
  delete double_valid_;
}

void MainWindow::DoubleValidInit() {
  //  TODO
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
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
  QString tmp_str("1234567890-+*/.");
  if (tmp_str.contains(key)) {
    LineInput((QString)key);
  } else if (key == '(' || key == ')') {
    skobki();
  }
}

void MainWindow::LineInput(QString str, QString code_str) {
  QString tmp_str("-+*/");
  if (code_str.isEmpty()) code_str = str;

  if ((error_ || calc_done_ || result_code_.isEmpty()) &&
      !tmp_str.contains(str)) {
    ui_->result->setText(str);
    result_code_ = code_str;
  } else {
    ui_->result->setText(ui_->result->text() + str);
    result_code_ = result_code_ + code_str;
  }
  error_ = false;
  calc_done_ = false;
}

void MainWindow::BackspaseLogic() {
  if (error_ || calc_done_) {
    AC_button();
  } else if (result_code_.size() > 2) {
    if (result_code_.back() == '(') {
      size_t t = TrigonCheck();
      while (t) {
        ui_->result->backspace();
        --t;
      }
    }
    ui_->result->backspace();
    result_code_.chop(1);
  } else if (result_code_.size() > 0) {
    ui_->result->backspace();
    result_code_.chop(1);
  }
}

size_t MainWindow::TrigonCheck() {
  size_t count = 0;
  QString ch3 = "@ABH";
  if (ch3.contains(result_code_.at(result_code_.size() - 2))) count = 3;
  return count;
}

void MainWindow::EqualsButton() { EqualsLogic(); }

void MainWindow::EqualsLogic() {
  if (error_ || ui_->result->text().isEmpty()) {
    AC_button();
  } else {
    try {
      calc_->StartCalc(result_code_.toStdString(),
                       ui_->line_X->text().toDouble());
      ui_->result->setText(QString::number(calc_->GetResult(), 'g', 15));
      result_code_ = ui_->result->text();
      calc_done_ = false;
    } catch (const std::exception &e) {  // TODO
      AC_button();
      error_ = true;
      ui_->result->setText(e.what());
    }
  }
  calc_done_ = true;
}

void MainWindow::x_button_push() {}

void MainWindow::digits_numbers() {
  QPushButton *button = (QPushButton *)sender();
  LineInput(button->text());
}

//  Умные скобки, ставится та скобка, которая должна быть
void MainWindow::skobki() {
  int valid_line = calc_valid_.SmartBracket(
      result_code_.toStdString());  //  Валидация скобки
  if (valid_line == s21::CalcValid::closed) {  //  Если валидация вернула Тру,
                                               //  ставим закрывающую
    LineInput(")");
  } else if (valid_line == s21::CalcValid::opened) {  //  Если Фолс, открывающую
    LineInput("(");
  }
}

void MainWindow::AC_button() {
  ui_->result->setText("");
  result_code_ = "";
  calc_->Reset();
  calc_done_ = false;
  error_ = false;
}

void MainWindow::C_button() { BackspaseLogic(); }

void MainWindow::graf_button() {}

void MainWindow::func_button() {
  QPushButton *button = (QPushButton *)sender();

  bool validfunc = calc_valid_.ValidFunc(result_code_.toStdString());

  if (validfunc) LineInput(button->text() + '(', button->whatsThis() + '(');
}

void MainWindow::simp_math_button() {}

void MainWindow::on_cred_Button_clicked() {}

void MainWindow::ConnectsRelise() {
  //  Кнопки с цифрами
  connect(ui_->push_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui_->push_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui_->push_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui_->push_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui_->push_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui_->push_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui_->push_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui_->push_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui_->push_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui_->push_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  //  Кнопка Х
  connect(ui_->push_X, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  //  Рабочие кнопки
  connect(ui_->push_AC, SIGNAL(clicked()), this, SLOT(AC_button()));
  connect(ui_->push_AC_2, SIGNAL(clicked()), this, SLOT(C_button()));
  connect(ui_->push_ravno, SIGNAL(clicked()), this, SLOT(EqualsButton()));
  connect(ui_->push_graf, SIGNAL(clicked()), this, SLOT(graf_button()));
  //  Тригонометрия
  connect(ui_->push_cos, SIGNAL(clicked()), this, SLOT(func_button()));
  connect(ui_->push_sin, SIGNAL(clicked()), this, SLOT(func_button()));
  connect(ui_->push_tan, SIGNAL(clicked()), this, SLOT(func_button()));
  connect(ui_->push_acos, SIGNAL(clicked()), this, SLOT(func_button()));
  connect(ui_->push_asin, SIGNAL(clicked()), this, SLOT(func_button()));
  connect(ui_->push_atan, SIGNAL(clicked()), this, SLOT(func_button()));
  connect(ui_->push_log, SIGNAL(clicked()), this, SLOT(func_button()));
  connect(ui_->push_ln, SIGNAL(clicked()), this, SLOT(func_button()));
  connect(ui_->push_sqrt, SIGNAL(clicked()), this, SLOT(func_button()));
  //  Простые операции
  connect(ui_->push_plus, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui_->push_minus, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui_->push_mult, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui_->push_div, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui_->push_mod, SIGNAL(clicked()), this, SLOT(simp_math_button()));
  connect(ui_->push_stepen, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  //  Скобки
  connect(ui_->push_scobka, SIGNAL(clicked()), this, SLOT(skobki()));
  //  Точка  TODO
  connect(ui_->push_dot, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  //  Input lines
}
