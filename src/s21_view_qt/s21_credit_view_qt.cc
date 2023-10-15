#include "s21_credit_view_qt.h"

#include "ui_s21_credit_view_qt.h"

Credit::Credit(s21::CalcController *calc_controller, QWidget *parent)
    : QDialog(parent), calc_(calc_controller), ui(new Ui::Credit) {
  ui->setupUi(this);
  DoubleValidInit();
}

void Credit::DoubleValidInit() {
  double_valid_.setNotation(QDoubleValidator::StandardNotation);
  ui->srokcredit->setValidator(&double_valid_);
  ui->percentcredit->setValidator(&double_valid_);
  ui->sumcredit->setValidator(&double_valid_);
}

Credit::~Credit() { delete ui; }

void Credit::on_credcalc_Button_clicked() {
  std::array<double, 3> data;
  data[summa] = ui->sumcredit->text().toDouble();
  data[srok] = ui->srokcredit->text().toInt();
  data[percent] = ui->percentcredit->text().toDouble();
  std::array<double, 3> itog_array;
  std::vector<double> itog_vector;
  if (ui->annuit->isChecked()) {
    try {
      calc_->CalcCredit(data);
      itog_array = calc_->GetCredit();
      ui->label_7->setText(QString::number(itog_array[summa]));
      ui->label_6->setText(QString::number(itog_array[pereplata]));
      ui->textBrowser->setText("Ежемесячный платеж - " + QString::number(itog_array[monthly], 'g', 12) + " рублей");
    } catch (const std::exception &e) {
      ui->textBrowser->setText(e.what());
    }
  } else if (ui->differen->isChecked()) {
    ui->textBrowser->clear();
    try {
      calc_->DifferenCalc(data);
      itog_vector = calc_->GetDifferent();
      for (int i = 0; i < data[srok]; i++) {
        QString qmonth = QString::number(itog_vector[monthly], 'g', 12);
        QString qi = QString::number(i + 1);
        ui->textBrowser->setText(ui->textBrowser->toPlainText() + qi +
                                 "-й месяц: " + qmonth + "руб." + '\n');
      }
      QString qsum = QString::number(itog_vector[itog], 'g', 10);
      QString qover = QString::number(itog_vector[pereplata], 'g', 12);
      ui->label_7->setText(qsum);
      ui->label_6->setText(qover);
    } catch (const std::exception &e) {
      ui->textBrowser->setText(e.what());
    }
  }
}

