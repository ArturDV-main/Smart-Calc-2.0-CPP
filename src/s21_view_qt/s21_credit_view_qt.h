#ifndef CREDIT_H
#define CREDIT_H

#include <math.h>

#include <QDialog>
#include <vector>
#include <QDoubleValidator>

#include "../s21_calc_controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Credit;
}
QT_END_NAMESPACE
class Credit : public QDialog {
  Q_OBJECT
  enum ForData { summa = 0, srok, percent };
  enum ForItog { itog = 0, pereplata, monthly };

 public:
  explicit Credit(s21::CalcController *calc_controller = nullptr,
                  QWidget *parent = nullptr);
  void DoubleValidInit();
  ~Credit();

 private slots:

  void on_credcalc_Button_clicked();

 private:
  QDoubleValidator double_valid_;
  s21::CalcController *calc_;
  Ui::Credit *ui;
};

#endif  // CREDIT_H
