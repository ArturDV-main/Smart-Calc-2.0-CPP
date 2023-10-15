#include "s21_credit_view_qt.h"

#include "ui_s21_credit_view_qt.h"

Credit::Credit(s21::CalcController *calc_controller, QWidget *parent)
    : QDialog(parent), calc_(calc_controller), ui(new Ui::Credit) {
  ui->setupUi(this);
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
    } catch (const std::exception &e) {
      ui->textBrowser->setText(e.what());
    }
    QString qsum = QString::number(itog_array[summa]);
    QString qmonth = QString::number(itog_array[monthly]);
    QString qover = QString::number(itog_array[pereplata]);
    ui->label_7->setText(qsum);
    ui->label_6->setText(qover);
    ui->textBrowser->setText("Ежемесячный платеж - " + qmonth + " рублей");
  } else if (ui->differen->isChecked()) {
    ui->textBrowser->clear();
    try {
      calc_->DifferenCalc(data);
      itog_vector = calc_->GetDifferent();
    } catch (const std::exception &e) {
      ui->textBrowser->setText(e.what());
    }

    for (int i = 0; i < data[srok]; i++) {
      QString qmonth = QString::number(itog_vector[monthly]);
      QString qi = QString::number(i + 1);
      ui->textBrowser->setText(ui->textBrowser->toPlainText() + qi +
                               "-й месяц: " + qmonth + "руб." + '\n');
    }
    QString qsum = QString::number(itog_vector[itog], 'g', 10);
    QString qover = QString::number(itog_vector[pereplata], 'g', 10);
    ui->label_7->setText(qsum);
    ui->label_6->setText(qover);
  }
}

void Credit::on_sumcredit_cursorPositionChanged() {
  QByteArray ba = (ui->sumcredit->text()).toLocal8Bit();

  const char *c_str2 = ba.data();  //  Преобразование в str* для СИ

  int valid = 1;

  // valid = super_valid(1000000000000, 0, c_str2); //  Валидация операции

  if (valid) {
    QString new_lable = ui->sumcredit->text();

    ui->sumcredit_2->setText(new_lable);

  } else {
    QString new_lable = ui->sumcredit_2->text();

    ui->sumcredit->setText(new_lable);
  }
}

void Credit::on_srokcredit_cursorPositionChanged() {
  QByteArray ba = (ui->srokcredit->text()).toLocal8Bit();

  const char *c_str2 = ba.data();  //  Преобразование в str* для СИ

  int valid = 1;

  // valid = super_valid(480, 0, c_str2); //  Валидация операции

  if (valid) {
    QString new_lable = ui->srokcredit->text();

    ui->srokcredit_2->setText(new_lable);

  } else {
    QString new_lable = ui->srokcredit_2->text();

    ui->srokcredit->setText(new_lable);
  }
}

void Credit::on_percentcredit_cursorPositionChanged() {
  QByteArray ba = (ui->percentcredit->text()).toLocal8Bit();

  const char *c_str2 = ba.data();  //  Преобразование в str* для СИ

  int valid = 1;

  // valid = super_valid(150, 0, c_str2); //  Валидация операции

  if (valid) {
    QString new_lable = ui->percentcredit->text();

    ui->percentcredit_2->setText(new_lable);

  } else {
    QString new_lable = ui->percentcredit_2->text();

    ui->percentcredit->setText(new_lable);
  }
}
