#ifndef S21_VIEW_QT_H_
#define S21_VIEW_QT_H_

#include <QDoubleValidator>
#include <QMainWindow>
#include <QVector>
#include <exception>

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
  MainWindow(QWidget *parent = nullptr,
             s21::CalcController *calc_controller = nullptr);
  ~MainWindow();

 private:
  s21::CalcValid calc_valid_;
  s21::CalcController *calc_;
  Ui::MainWindow *ui_;
  QDoubleValidator *double_valid_;
  double x_begin_, x_end_, h_;
  QVector<double> x_{}, y_{};
  QString result_code_;
  bool calc_done_{};
  bool error_{};
  void ConnectsRelise();
  void DoubleValidInit();
  void LineEditEvent(char key);  // TODO
  void BackspaseLogic();
  void LineInput(QString str);

 protected:
  void keyPressEvent(QKeyEvent *event) override;

 private slots:
  void digits_numbers();
  void AC_button();
  void C_button();
  void func_button();
  void EqualsButton();
  void EqualsLogic();
  void simp_math_button();
  void graf_button();
  void skobki();
  void x_button_push();
  void on_cred_Button_clicked();
};
#endif  // S21_VIEW_QT_H_
