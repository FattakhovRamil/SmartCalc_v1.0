#include "creditWindow.h"

#include "mainwindow.h"
#include "s21_smartCalc.h"
#include "ui_creditWindow.h"

creditWindow::creditWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::creditWindow) {
  ui->setupUi(this);
  ui->anny->setChecked(true);

  model = new QStandardItemModel(3, 5, this);
}

creditWindow::~creditWindow() { delete ui; }

void creditWindow::on_pushButton_clicked() {
  this->close();       // Закрываем окно
  emit firstWindow();  // И вызываем сигнал на открытие главного окна
}

void creditWindow::on_result_calc_clicked() {
  double sum_credit = ui->sum_credit->text().toDouble();
  int srok_credit = ui->srok_credit->text().toInt();
  double prosent_stavka = ui->prosent_stavka->text().toDouble();
  int year_or_month = ui->comboBox->currentIndex();
  int type_of_loan = 0;
  if (ui->anny->isChecked()) {
    type_of_loan = 0;  // если 0 не нажат анн, то диф 1
  } else {
    type_of_loan = 1;
  }
  double separate_payment = 0;
  double separate_payment_1 = 0;  //  платеж в месяц/год
  double overpayment = 0;         // переплата по кредиту
  double total_payout = 0;        // общая выплатаÎ
  int flag = credit_calc_c(sum_credit, srok_credit, year_or_month,
                           prosent_stavka, type_of_loan, &separate_payment,
                           &separate_payment_1, &overpayment, &total_payout);
  if (flag == 0) {
    printf("Ошибка");
  } else {
    if (type_of_loan) {
      ui->separate_payment->setText(QString::number(separate_payment) + "..." +
                                    QString::number(separate_payment_1));
      ui->overpayment->setText(QString::number(overpayment));
      ui->total_payout->setText(QString::number(total_payout));
    } else {
      ui->separate_payment->setText(QString::number(separate_payment));
      ui->overpayment->setText(QString::number(overpayment));
      ui->total_payout->setText(QString::number(total_payout));
    }
  }
}
