#include "s21_credit_view_qt.h"
#include "ui_s21_credit_view_qt.h"

Credit::Credit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Credit)
{
    ui->setupUi(this);
}

Credit::~Credit()
{
    delete ui;
}

void Credit::on_credcalc_Button_clicked() {

    double summa, itog, pereplata, monthly , percent;
    int srok ;

    summa=ui->sumcredit->text().toDouble();
    srok=ui->srokcredit->text().toInt();
    percent=ui->percentcredit->text().toDouble();


    if (ui->annuit->isChecked()) {

        percent = percent / 1200;
        monthly = summa * (percent*pow((1+percent),srok)/(pow((1+percent), srok)-1));
        itog = monthly*srok;
        pereplata = itog - summa;

        QString qsum = QString::number(itog);
        QString qmonth = QString::number(monthly);
        QString qover = QString::number(pereplata);

        ui->label_7->setText(qsum);
        ui->label_6->setText(qover);
        ui->textBrowser->setText("Ежемесячный платеж - "+qmonth +" рублей");
    } else if (ui->differen->isChecked()) {
        itog = 0;
        ui->textBrowser->clear();
        int debt_sum = summa / srok;
        for (int i = 1; i <= srok; i++) {
            monthly = (summa * percent / 100 * 31/365) + debt_sum;
            QString qmonth = QString::number(monthly);
            QString qi = QString::number(i);
            ui->textBrowser->setText(ui->textBrowser->toPlainText() + qi+"-й месяц: "+ qmonth + "руб." + '\n');
            summa -= debt_sum;
            itog += monthly;
        }
        pereplata = itog - debt_sum * srok;
        QString qsum = QString::number(itog, 'g', 10);
        QString qover = QString::number(pereplata, 'g', 10);
        ui->label_7->setText(qsum);
        ui->label_6->setText(qover);
    }
}

void Credit::on_sumcredit_cursorPositionChanged()
{
    QByteArray ba = (ui->sumcredit->text()).toLocal8Bit();

    const char *c_str2 = ba.data(); //  Преобразование в str* для СИ

    int valid;

    // valid = super_valid(1000000000000, 0, c_str2); //  Валидация операции

    if(valid) {

        QString new_lable = ui->sumcredit->text();

        ui->sumcredit_2->setText(new_lable);

    } else {

        QString new_lable = ui->sumcredit_2->text();

        ui->sumcredit->setText(new_lable);

    }
}


void Credit::on_srokcredit_cursorPositionChanged()
{
    QByteArray ba = (ui->srokcredit->text()).toLocal8Bit();

    const char *c_str2 = ba.data(); //  Преобразование в str* для СИ

    int valid;

    // valid = super_valid(480, 0, c_str2); //  Валидация операции

    if(valid) {

        QString new_lable = ui->srokcredit->text();

        ui->srokcredit_2->setText(new_lable);

    } else {

        QString new_lable = ui->srokcredit_2->text();

        ui->srokcredit->setText(new_lable);

    }
}


void Credit::on_percentcredit_cursorPositionChanged()
{
    QByteArray ba = (ui->percentcredit->text()).toLocal8Bit();

    const char *c_str2 = ba.data(); //  Преобразование в str* для СИ

    int valid;

    // valid = super_valid(150, 0, c_str2); //  Валидация операции

    if(valid) {

        QString new_lable = ui->percentcredit->text();

        ui->percentcredit_2->setText(new_lable);

    } else {

        QString new_lable = ui->percentcredit_2->text();

        ui->percentcredit->setText(new_lable);

    }
}
