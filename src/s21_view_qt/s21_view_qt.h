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
  QDoubleValidator double_valid_;

  //  for QCustomplot
  double x_begin_, x_end_, h_;
  QVector<double> x_{}, y_{};

  //  cod on enum from model
  QString result_code_{};
  QString reserv_{};
  bool calc_done_ = false;
  bool error_ = false;

  void ConnectsRelise();
  void DoubleValidInit();
  void LineEditEvent(char key);  // TODO
  void BackspaseLogic();
  void LineInput(QString str, QString code_str = 0);
  size_t TrigonCheck();

 protected:
  void keyPressEvent(QKeyEvent *event) override;

 private slots:
  void DigitNumbers();
  void ACButton();
  void CButton();
  void FuncButton();
  void EqualsButton();
  void EqualsLogic();
  void SimpMathButton();
  void GrafButton();
  void Skobki();
  void XButtonPush();
  void OnCredButtonClicked();
};
#endif  // S21_VIEW_QT_H_
