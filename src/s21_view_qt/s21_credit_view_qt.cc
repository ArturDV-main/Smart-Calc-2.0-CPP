#include "s21_credit_view_qt.h"

#include "ui_s21_credit_view_qt.h"

Credit::Credit(s21::CalcController *calc_controller, QWidget *parent)
    : QDialog(parent), calc_(calc_controller), ui_(new Ui::Credit) {
  ui_->setupUi(this);
  connect(ui_->credcalc_Button, SIGNAL(clicked()), this, SLOT(OnCredcalcButtonClicked()));
  DoubleValidInit();
}

void Credit::DoubleValidInit() {
  double_valid_.setLocale(QLocale::English);
  double_valid_.setNotation(QDoubleValidator::StandardNotation);
  ui_->srokcredit->setValidator(&double_valid_);
  ui_->percentcredit->setValidator(&double_valid_);
  ui_->sumcredit->setValidator(&double_valid_);
}

Credit::~Credit() { delete ui_; }

void Credit::OnCredcalcButtonClicked() {
  std::array<double, 3> data;
  data[summa] = ui_->sumcredit->text().toDouble();
  data[srok] = ui_->srokcredit->text().toInt();
  data[percent] = ui_->percentcredit->text().toDouble();
  std::array<double, 3> itog_array;
  std::vector<double> itog_vector;
  if (ui_->annuit->isChecked()) {
    try {
      calc_->CalcCredit(data);
      itog_array = calc_->GetCredit();
      ui_->label_7->setText(QString::number(itog_array[summa]));
      ui_->label_6->setText(QString::number(itog_array[pereplata]));
      ui_->textBrowser->setText("Ежемесячный платеж - " + QString::number(itog_array[monthly], 'g', 12) + " рублей");
    } catch (const std::exception &e) {
      ui_->textBrowser->setText(e.what());
    }
  } else if (ui_->differen->isChecked()) {
    ui_->textBrowser->clear();
    try {
      calc_->DifferenCalc(data);
      itog_vector = calc_->GetDifferent();
      for (int i = 0; i < data[srok]; i++) {
        QString qmonth = QString::number(itog_vector[monthly], 'g', 12);
        QString qi = QString::number(i + 1);
        ui_->textBrowser->setText(ui_->textBrowser->toPlainText() + qi +
                                 "-й месяц: " + qmonth + "руб." + '\n');
      }
      QString qsum = QString::number(itog_vector[itog], 'g', 12);
      QString qover = QString::number(itog_vector[pereplata], 'g', 12);
      ui_->label_7->setText(qsum);
      ui_->label_6->setText(qover);
    } catch (const std::exception &e) {
      ui_->textBrowser->setText(e.what());
    }
  }
}

