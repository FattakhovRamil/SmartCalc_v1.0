#ifndef CREDITWINDOW_H
#define CREDITWINDOW_H

#include <QStandardItemModel>
#include <QWidget>

namespace Ui {
class creditWindow;
}

class creditWindow : public QWidget {
  Q_OBJECT

 public:
  explicit creditWindow(QWidget *parent = 0);
  ~creditWindow();
  void credit_calc();
 signals:
  void firstWindow();  // Сигнал для первого окна на открытие

 public slots:
  // Слот-обработчик нажатия кнопки
  void on_pushButton_clicked();

 private slots:

  void on_result_calc_clicked();

 private:
  Ui::creditWindow *ui;
  QStandardItemModel *model;
};

#endif  // CREDITWINDOW_H
