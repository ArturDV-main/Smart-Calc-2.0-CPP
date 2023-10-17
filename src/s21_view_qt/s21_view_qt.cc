#include "s21_view_qt.h"

#include "./ui_s21_view_qt.h"
#include "s21_credit_view_qt.h"

MainWindow::MainWindow(QWidget *parent, s21::CalcController *calc_controller)
    : QMainWindow(parent), calc_(calc_controller), ui_(new Ui::MainWindow) {
  ui_->setupUi(this);
  ConnectsRelise();
  DoubleValidInit();
  ui_->widget_graf->addGraph();
}

MainWindow::~MainWindow() { delete ui_; }

void MainWindow::DoubleValidInit() {
  double_valid_.setLocale(QLocale::English);
  double_valid_.setNotation(QDoubleValidator::StandardNotation);
  ui_->line_X->setValidator(&double_valid_);
  ui_->line_X_from->setValidator(&double_valid_);
  ui_->line_X_to->setValidator(&double_valid_);
  ui_->line_Y_from->setValidator(&double_valid_);
  ui_->line_Y_to->setValidator(&double_valid_);
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

void MainWindow::LineEditEvent(const char key) {
  QString tmp_str("1234567890-+*/.");
  if (tmp_str.contains(key)) {
    LineInput((QString)key);
  } else if (key == '(' || key == ')') {
    Skobki();
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
    ACButton();
  } else if (result_code_.back() == 'M') {
    for (int i = 3; i > 0; i--) {
      ui_->result->backspace();
    }
    result_code_.chop(1);
  } else if (result_code_.back() == '(') {
    if (result_code_.size() > 1) {
      size_t t = TrigonCheck();
      if (t > 1) result_code_.chop(1);
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

size_t MainWindow::TrigonCheck() const noexcept {
  size_t count = 0;
  QString ch3 = "@ABM";
  QString ch4 = "CDEF";
  if (ch3.contains(result_code_.at(result_code_.size() - 2)))
    count = 3;
  else if (ch4.contains(result_code_.at(result_code_.size() - 2)))
    count = 4;
  else if (result_code_.at(result_code_.size() - 2) == 'H')
    count = 5;
  else if (result_code_.at(result_code_.size() - 2) == 'G')
    count = 2;
  return count;
}

void MainWindow::EqualsButton() { EqualsLogic(); }

void MainWindow::EqualsLogic() {
  if (error_ || ui_->result->text().isEmpty()) {
    ACButton();
  } else {
    try {
      calc_->StartCalc(result_code_.toStdString(),
                       ui_->line_X->text().toDouble());
      ui_->result->setText(QString::number(calc_->GetResult(), 'g', 15));
      result_code_ = ui_->result->text();
    } catch (const std::exception &e) {
      ACButton();
      error_ = true;
      ui_->result->setText(e.what());
    }
  }
  calc_done_ = true;
}

void MainWindow::XButtonPush() {}

void MainWindow::DigitNumbers() {
  if (error_) ACButton();
  QPushButton *button = (QPushButton *)sender();
  LineInput(button->text());
}

//  Умные скобки, ставится та скобка, которая должна быть
void MainWindow::Skobki() {
  if (calc_done_ || error_) ACButton();
  int valid_line = calc_valid_.SmartBracket(
      result_code_.toStdString());  //  Валидация скобки
  if (valid_line == s21::CalcValid::closed) {
    LineInput(")");
  } else if (valid_line == s21::CalcValid::opened) {
    LineInput("(");
  }
}

void MainWindow::ACButton() {
  ui_->result->setText("");
  result_code_ = "";
  calc_->Reset();
  calc_done_ = false;
  error_ = false;
  ui_->widget_graf->replot();
}

void MainWindow::CButton() { BackspaseLogic(); }

void MainWindow::GrafButton() {
  if (error_ || ui_->result->text().isEmpty())
    ACButton();
  else if (ui_->result->text() != '0') {
    x_.clear();
    y_.clear();
    h_ = 0.03;
    x_begin_ = ui_->line_X_from->text().toDouble();
    x_end_ = ui_->line_X_to->text().toDouble();
    double Y_from = ui_->line_Y_from->text().toDouble();
    double X_from = ui_->line_Y_to->text().toDouble();
    ui_->widget_graf->xAxis->setRange(x_begin_, x_end_);
    ui_->widget_graf->yAxis->setRange(Y_from, X_from);
    try {
      for (x2_ = x_begin_; x2_ <= x_end_; x2_ += h_) {  //  Заполняем координаты
        x_.push_back(x2_);
        calc_->StartCalc(result_code_.toStdString(), x2_);
        y_.push_back(calc_->GetResult());  //  Формула для заполнения у
      }
      ui_->widget_graf->graph(0)->addData(x_, y_);
      calc_done_ = true;
    } catch (const std::exception &e) {
      ui_->result->setText(e.what());
      error_ = true;
    }
    ui_->widget_graf->replot();
    ui_->widget_graf->graph(0)->data()->clear();
    //  Очищаем координаты
  }
}

void MainWindow::FuncButton() {
  if (calc_done_ || error_) ACButton();
  QPushButton *button = (QPushButton *)sender();
  bool validfunc = calc_valid_.ValidFunc(result_code_.toStdString());
  if (validfunc) LineInput(button->text() + '(', button->whatsThis() + '(');
}

void MainWindow::SimpMathButton() {
  if (error_) ACButton();
  QPushButton *button = (QPushButton *)sender();
  if (button->text() == "mod") {
    LineInput(button->text(), "M");
  } else {
    LineInput(button->text());
  }
}

void MainWindow::OnCredButtonClicked() {
  Credit credit_okno(calc_);
  credit_okno.setModal(true);
  credit_okno.exec();
}

void MainWindow::ConnectsRelise() {
  //  Кнопки с цифрами
  connect(ui_->push_0, SIGNAL(clicked()), this, SLOT(DigitNumbers()));
  connect(ui_->push_1, SIGNAL(clicked()), this, SLOT(DigitNumbers()));
  connect(ui_->push_2, SIGNAL(clicked()), this, SLOT(DigitNumbers()));
  connect(ui_->push_3, SIGNAL(clicked()), this, SLOT(DigitNumbers()));
  connect(ui_->push_4, SIGNAL(clicked()), this, SLOT(DigitNumbers()));
  connect(ui_->push_5, SIGNAL(clicked()), this, SLOT(DigitNumbers()));
  connect(ui_->push_6, SIGNAL(clicked()), this, SLOT(DigitNumbers()));
  connect(ui_->push_7, SIGNAL(clicked()), this, SLOT(DigitNumbers()));
  connect(ui_->push_8, SIGNAL(clicked()), this, SLOT(DigitNumbers()));
  connect(ui_->push_9, SIGNAL(clicked()), this, SLOT(DigitNumbers()));
  //  Кнопка Х
  connect(ui_->push_X, SIGNAL(clicked()), this, SLOT(DigitNumbers()));
  //  Рабочие кнопки
  connect(ui_->push_AC, SIGNAL(clicked()), this, SLOT(ACButton()));
  connect(ui_->push_AC_2, SIGNAL(clicked()), this, SLOT(CButton()));
  connect(ui_->push_ravno, SIGNAL(clicked()), this, SLOT(EqualsButton()));
  connect(ui_->push_graf, SIGNAL(clicked()), this, SLOT(GrafButton()));
  //  Тригонометрия
  connect(ui_->push_cos, SIGNAL(clicked()), this, SLOT(FuncButton()));
  connect(ui_->push_sin, SIGNAL(clicked()), this, SLOT(FuncButton()));
  connect(ui_->push_tan, SIGNAL(clicked()), this, SLOT(FuncButton()));
  connect(ui_->push_acos, SIGNAL(clicked()), this, SLOT(FuncButton()));
  connect(ui_->push_asin, SIGNAL(clicked()), this, SLOT(FuncButton()));
  connect(ui_->push_atan, SIGNAL(clicked()), this, SLOT(FuncButton()));
  connect(ui_->push_log, SIGNAL(clicked()), this, SLOT(FuncButton()));
  connect(ui_->push_ln, SIGNAL(clicked()), this, SLOT(FuncButton()));
  connect(ui_->push_sqrt, SIGNAL(clicked()), this, SLOT(FuncButton()));
  //  Простые операции
  connect(ui_->push_plus, SIGNAL(clicked()), this, SLOT(SimpMathButton()));
  connect(ui_->push_minus, SIGNAL(clicked()), this, SLOT(SimpMathButton()));
  connect(ui_->push_mult, SIGNAL(clicked()), this, SLOT(SimpMathButton()));
  connect(ui_->push_div, SIGNAL(clicked()), this, SLOT(SimpMathButton()));
  connect(ui_->push_mod, SIGNAL(clicked()), this, SLOT(SimpMathButton()));
  connect(ui_->push_stepen, SIGNAL(clicked()), this, SLOT(SimpMathButton()));
  //  Скобки
  connect(ui_->push_scobka, SIGNAL(clicked()), this, SLOT(Skobki()));
  //  Точка
  connect(ui_->push_dot, SIGNAL(clicked()), this, SLOT(DigitNumbers()));
  //  Input lines
  connect(ui_->cred_Button, SIGNAL(clicked()), this,
          SLOT(OnCredButtonClicked()));
}
