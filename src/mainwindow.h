#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QVector>

#include "creditWindow.h"
#include "depositWindow.h"
extern "C" {
#include "s21_smartCalc.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  double xBegin, xEnd, h, X;
  int N;
  QVector<double> x, y;
  // creditWindow *mMyNewWindow;
  creditWindow *sWindow;

  depositWindow *dWindow;

 private slots:
  void digits_numbers();
  void del_all();
  void del_last_char();
  void calculate();
  void on_pushButton_grah_clicked();
  void openCreditWindow();
  void openDepositWindow();
  void openGraphWindow();
};

#endif  // MAINWINDOW_H
