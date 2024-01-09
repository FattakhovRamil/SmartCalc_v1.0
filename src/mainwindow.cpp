#include "mainwindow.h"

#include <QDoubleValidator>

#include "ui_mainwindow.h"

//#include "QLabel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  sWindow = new creditWindow();
  dWindow = new depositWindow();
  ui->result_show->setText("");
  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_AC, SIGNAL(clicked()), this, SLOT(del_all()));
  connect(ui->pushButton_C, SIGNAL(clicked()), this, SLOT(del_last_char()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_br_l, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_br_r, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_del, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_min, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_ravno, SIGNAL(clicked()), this, SLOT(calculate()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_step, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_ymno, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_X, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->action_credit, &QAction::triggered, this,
          &MainWindow::openCreditWindow);
  connect(ui->action_depoz, &QAction::triggered, this,
          &MainWindow::openDepositWindow);
  connect(ui->action_graph, &QAction::triggered, this,
          &MainWindow::openGraphWindow);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::openCreditWindow() {
  sWindow->show();  // Показываем второе окно
  this->close();    // Закрываем основное окно
  dWindow->close();
}

void MainWindow::openDepositWindow() {
  dWindow->show();  // Показываем второе окно
  this->close();    // Закрываем основное окно
  sWindow->close();
}

void MainWindow::openGraphWindow() {
  this->show();      // Показываем второе окно
  dWindow->close();  // Закрываем основное окно
  sWindow->close();
}

void MainWindow::digits_numbers() {
  QPushButton *button = (QPushButton *)sender();
  QString new_label;
  // new_label = ui->result_show->text() + button->text());
  new_label = QString(ui->result_show->text() + button->text());
  ui->result_show->setText(new_label);
}

void MainWindow::del_all() {
  ui->result_show->setText("");
  ui->result_ansver->setText("");
}

void MainWindow::del_last_char() {
  QString new_label = ui->result_show->text();
  new_label.chop(1);
  ui->result_show->setText(new_label);
  ui->result_ansver->setText("");
}

void MainWindow::calculate() {
  char str[255] = "";
  QString new_label = ui->result_show->text();
  QByteArray bytes =
      new_label.toLocal8Bit();  // получить локально-совместимую кодировку
  qstrncpy(str, bytes.data(), sizeof(str));
  double x = ui->lineEdit_x->text().toDouble();
  double ansver_qt = 0;
  if (!calcul(str, x, &ansver_qt)) {
    ui->result_ansver->setText(QString::number(ansver_qt, 'g', 10));
  } else {
    ui->result_ansver->setText("Ошибка");
  }
}

void MainWindow::on_pushButton_grah_clicked() {
  x = QVector<double>();
  y = QVector<double>();
  ui->widget->clearGraphs();
  char str[255] = "";
  QString new_label = ui->result_show->text();
  QByteArray bytes =
      new_label.toLocal8Bit();  // получить локально-совместимую кодировку
  qstrncpy(str, bytes.data(), sizeof(str));
  h = ui->lineEdit_h->text().toDouble();
  xBegin = -100;
  xEnd = 100 + h;
  ui->widget->xAxis->setRange(ui->lineEdit_x_l->text().toDouble(),
                              ui->lineEdit_x_r->text().toDouble());
  ui->widget->yAxis->setRange(ui->lineEdit_y_l->text().toDouble(),
                              ui->lineEdit_y_r->text().toDouble());
  X = xBegin;
  N = (xEnd - xBegin) / h + 2;
  double x1 = ui->lineEdit_x->text().toDouble();
  double ansver_qt = 0;
  if (!calcul(str, x1, &ansver_qt)) {
    ui->result_ansver->setText(QString::number(ansver_qt, 'g', 10));
    for (X = xBegin; X <= xEnd; X += h) {
      calcul(str, X, &ansver_qt);
      x.push_back(X);
      calcul(str, X, &ansver_qt);
      y.push_back(ansver_qt);
    }
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x, y);
    ui->widget->graph(0)->setPen(QColor(50, 50, 50, 255));
    ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->widget->graph(0)->setScatterStyle(
        QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
    ui->widget->replot();
  } else {
    ui->result_ansver->setText("Ошибка");
  }
}
