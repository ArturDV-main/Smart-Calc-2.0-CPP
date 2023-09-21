#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QDoubleValidator>
#include "../s21_calc_controller.h"
#include "../s21_calc_valid_model.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr, s21::CalcController * calc_controller = nullptr);
  ~MainWindow();
 private:
  s21::CalcValid calc_valid;
  s21::CalcController * calc_;
  Ui::MainWindow *ui;
  QDoubleValidator *double_valid_;
  double x_begin_, x_end_, h_;
  QVector<double> x_{}, y_{};
  QString result_code_;
  void ConnectsRelise();
  void DoubleValidInit();
//  void LineEditEvent(QString key); // TODO
 protected:
  void keyPressEvent(QKeyEvent * event) override;

 private slots:
  void digits_numbers();
  void AC_button();
  void func_button();
  void equals_button();
  void simp_math_button();
  void graf_button();
  void skobki();
  void x_button_push();
  void on_cred_Button_clicked();
  void on_line_X_cursorPositionChanged();
  void on_line_X_from_cursorPositionChanged();
  void on_line_X_to_cursorPositionChanged();
  void on_line_Y_from_cursorPositionChanged();
  void on_line_Y_to_cursorPositionChanged();
};
#endif  // MAINWINDOW_H
