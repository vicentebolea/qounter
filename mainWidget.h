#include "ui_qounter.h"
#include <QtCore/QDate>

class MainWidget: public QWidget {
  Q_OBJECT
  public:
    MainWidget(QWidget* parent) : QWidget(parent)
    {
      ui.setupUi(this);
      this->connect(ui.StartDateEdit, SIGNAL(dateChanged(const QDate&)), this, SLOT(onDateChanged(const QDate&)));
      this->connect(ui.EndateEdit, SIGNAL(dateChanged(const QDate&)), this, SLOT(onDateChanged(const QDate&)));
      this->connect(ui.daysFromNow, SIGNAL(valueChanged(int)), this, SLOT(onDateChanged(int)));

      ui.StartDateEdit->setDate(QDate::currentDate());
      ui.EndateEdit->setDate(QDate::currentDate());
    }

  public slots:

    void onDateChanged(int value)
    {
      auto newDate = ui.StartDateEdit->date().addDays(value);

      ui.EndateEdit->setDate(newDate);
    }
    void onDateChanged(const QDate& newDate)
    {
      auto begin = ui.StartDateEdit->date();
      auto end = ui.EndateEdit->date();

      if (begin > end)
      {
        ui.result->setText("ERROR: End date should be after begin date.");
        return;
      }


      auto result = begin.daysTo(end);
      ui.result->setText("");
      ui.daysFromNow->setValue(result);
    }

  private:
    Ui::Form ui;
};
