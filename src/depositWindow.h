#ifndef DEPOSITWINDOW_H
#define DEPOSITWINDOW_H

#include <QStandardItemModel>
#include <QWidget>

namespace Ui {
class depositWindow;
}

class depositWindow : public QWidget {
  Q_OBJECT

 public:
  explicit depositWindow(QWidget *parent = 0);
  ~depositWindow();
  void credit_calc();
 signals:
  void firstWindow();

 public slots:
  void on_pushButton_clicked();

 private slots:

  void on_result_calc_clicked();

 private:
  Ui::depositWindow *ui;
  QStandardItemModel *model;
};

#endif  // DEPOSITWINDOW_H
