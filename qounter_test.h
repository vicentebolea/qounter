#include "qounter-moc.h"

#define QT_WIDGETS_LIB
#include <QtWidgets/QtWidgets>
#include <QtTest/qtestmouse.h>

class TestQounter: public Qounter
{
    Q_OBJECT
private slots:
    void testSetToday();
};

void TestQounter::testSetToday()
{
  this->show();
  this->setFixedSize(632,451);

  QTest::mouseClick(ui.StartTodayPushButton, Qt::LeftButton);
  QTest::mouseClick(ui.EndTodayPushButton, Qt::LeftButton);

  QCOMPARE(ui.StartDateEdit->date(), QDate::currentDate());
  QCOMPARE(ui.EndateEdit->date(), QDate::currentDate());
}
