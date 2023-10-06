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
  if (tmp_str.contains(char(key))) {
    LineInput((QString)key);
  } else {
    // BackspaseLogic();
  }
}

void MainWindow::LineInput(QString str) {
  QString tmp_str("-+*/");
  if ((ui_->result->text() == "0" || (calc_done_ && !tmp_str.contains(str)) ||
       error_) &&
      !(str == '.'))
    ui_->result->setText(str);
  else
    ui_->result->setText(ui_->result->text() + str);
  calc_done_ = false;
  error_ = false;
}

void MainWindow::BackspaseLogic() {
  if (ui_->result->text() == "0")
    return;
  else if (ui_->result->text().size() == 1 || error_ || calc_done_) {
    error_ = false;
    calc_done_ = false;
    ui_->result->setText("0");
  } else
    ui_->result->backspace();
}

void MainWindow::EqualsButton() { EqualsLogic(); }

void MainWindow::EqualsLogic() {
  if (error_) {
    ui_->result->setText("0");
    error_ = false;
    return;
  }
  try {
    calc_->StartCalc(ui_->result->text().toStdString(),
                     ui_->line_X->text().toDouble());
    ui_->result->setText(QString::number(calc_->GetResult(), 'g', 15));
  } catch (const std::exception &e) {  // TODO
    ui_->result->setText(e.what());
    error_ = true;
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
  QString new_lable;

  //  Преобразование в str* для СИ
  QByteArray ba = (ui_->result->text()).toLocal8Bit();

  const char *c_str2 = ba.data();  //  Преобразование в str* для СИ

  int valid_line = calc_valid_.SmartBracket(c_str2);  //  Валидация скобки

  if (valid_line == true) {  //  Если валидация вернула Тру, ставим закрывающую
    new_lable = ')';
  } else if (valid_line == false) {  //  Если Фолс, открывающую
    new_lable = '(';
  }

  //  Если Эррор, установка скобки запрещена
  if (ui_->result->text() == "0" && valid_line != 2) {
    //  Запись в строку для передачи в бэкЭнд

    ui_->result->setText(new_lable);  //  Запись для вывода на экран

  } else if (valid_line != 2) {
    //  Запись в строку для передачи в бэкЭнд

    //  Запись для вывода на экран
    ui_->result->setText(ui_->result->text() + new_lable);
  }
}

void MainWindow::AC_button() {
  ui_->result->setText("0");
  calc_->Reset();
}

void MainWindow::C_button() { BackspaseLogic(); }

void MainWindow::graf_button() {}

void MainWindow::func_button() {}

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
