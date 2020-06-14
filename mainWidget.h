#include "ui_qounter.h"
#include <QtCore/QDate>
#include <QtCore/QSignalMapper>

class MainWidget: public QWidget {
  Q_OBJECT
  public:
    MainWidget(QWidget* parent) : QWidget(parent)
    {
      ui.setupUi(this);
      this->connect(ui.StartDateEdit, SIGNAL(dateChanged(const QDate&)), this, SLOT(onDateChanged(const QDate&)));
      this->connect(ui.EndateEdit, SIGNAL(dateChanged(const QDate&)), this, SLOT(onDateChanged(const QDate&)));
      this->connect(ui.daysFromNow, SIGNAL(valueChanged(int)), this, SLOT(onDateChanged(int)));

      QSignalMapper* signalMapper = new QSignalMapper(this);
      this->connect(ui.StartTodayPushButton, SIGNAL(pressed()), signalMapper, SLOT(map()));
      this->connect(ui.EndTodayPushButton, SIGNAL(pressed()), signalMapper, SLOT(map()));

      signalMapper->setMapping(ui.StartTodayPushButton, 0);
      signalMapper->setMapping(ui.EndTodayPushButton, 1);

      this->connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(onTodayPessed(int)));

      ui.StartDateEdit->setDate(QDate::currentDate());
      ui.EndateEdit->setDate(QDate::currentDate());
    }

  public slots:
    void onTodayPessed(int selection)
    {
      switch (selection) {
        case 0:
          ui.StartDateEdit->setDate(QDate::currentDate());
          break;

        case 1:
          ui.EndateEdit->setDate(QDate::currentDate());
          break;
      }
    }

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
