#ifndef CREDIT_H
#define CREDIT_H

#include <math.h>

#include <QDialog>
#include <vector>

#include "../s21_calc_controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Credit;
}
QT_END_NAMESPACE
class Credit : public QDialog {
  Q_OBJECT
  enum ForData { summa = 0, srok, percent };
  enum ForItog { monthly = 0, itog, pereplata };

 public:
  explicit Credit(s21::CalcController *calc_controller = nullptr,
                  QWidget *parent = nullptr);
  ~Credit();

 private slots:

  void on_credcalc_Button_clicked();

  void on_sumcredit_cursorPositionChanged();

  void on_srokcredit_cursorPositionChanged();

  void on_percentcredit_cursorPositionChanged();

 private:
  s21::CalcController *calc_;
  Ui::Credit *ui;
};

#endif  // CREDIT_H