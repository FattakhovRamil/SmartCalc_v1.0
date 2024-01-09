#include "depositWindow.h"

#include "mainwindow.h"
#include "s21_smartCalc.h"
#include "ui_depositWindow.h"

depositWindow::depositWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::depositWindow) {
  ui->setupUi(this);
  // ui->anny->setChecked(true);

  // model = new QStandardItemModel(3, 5, this);
}

depositWindow::~depositWindow() { delete ui; }

void depositWindow::on_pushButton_clicked() {
  this->close();       // Закрываем окно
  emit firstWindow();  // И вызываем сигнал на открытие главного окна
}

void depositWindow::on_result_calc_clicked() {
  double sum_vkald = ui->sum_deposit->text().toDouble();
  int srok = ui->srok_deposit->text().toInt();
  double prosent_stavka = ui->prosent_stavka->text().toDouble();
  double nalog_stavka = ui->nalog_stavka->text().toDouble();
  int period_viplat =
      ui->comboBox_period_viplat
          ->currentIndex();  // через какое время выплатить в месяцах
  if (period_viplat != 2) {
    if (period_viplat == 0) {
      period_viplat = 1;
    } else {
      period_viplat = 3;
    }
  }
  int capit_prosentov =
      0;  // добавление дохода в основную сумму, 0 - вкл, 1 - выкл
  int year_or_month = ui->comboBox->currentIndex();
  if (year_or_month == 0) {
    srok *= 12;
  }
  if (ui->checkBox->checkState()) {
    capit_prosentov = 1;
  }
  int spisok_poplneni_date = ui->comboBox_spisok_popol->currentIndex() + 1;
  int spisok_cnaty_date = ui->comboBox_spisok_snatiy->currentIndex() + 1;
  if (spisok_poplneni_date != 1) {
    spisok_poplneni_date = ui->comboBox_spisok_popol->currentIndex() * 3;
  }
  if (spisok_cnaty_date != 1) {
    spisok_cnaty_date = ui->comboBox_spisok_snatiy->currentIndex() * 3;
  }
  double spisok_poplneni =
      ui->spisok_poplneni->text().toDouble();  // сколько пополняю ежемесяечно;
  double spisok_cnaty =
      ui->spisok_cnaty->text().toDouble();  // сколько снимаю ежемесяечно;
  double nacislen_prosenty = 0;
  double sum_nalog = 0;
  double sum_end = 0;
  int flag = deposit_calc(sum_vkald, srok, prosent_stavka, nalog_stavka,
                          period_viplat, capit_prosentov, spisok_poplneni,
                          spisok_cnaty, &nacislen_prosenty, &sum_nalog,
                          &sum_end, spisok_poplneni_date, spisok_cnaty_date);
  if (flag == 0) {
    printf("Ошибка");
  } else {
    ui->nacislen_prosenty->setText(QString::number(nacislen_prosenty));
    ui->sum_nalog->setText(QString::number(sum_nalog));
    ui->sum_end->setText(QString::number(sum_end));
  }
}
