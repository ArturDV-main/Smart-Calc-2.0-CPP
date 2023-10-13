#ifndef CREDIT_H
#define CREDIT_H

#include <QDialog>
#include <math.h>

namespace Ui {
class Credit;
}

class Credit : public QDialog
{
    Q_OBJECT

public:
    explicit Credit(QWidget *parent = nullptr);
    ~Credit();

private slots:

    void on_credcalc_Button_clicked();

    void on_sumcredit_cursorPositionChanged();

    void on_srokcredit_cursorPositionChanged();

    void on_percentcredit_cursorPositionChanged();

private:
    Ui::Credit *ui;

};


#endif // CREDIT_H