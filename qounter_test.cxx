#include <QCoreApplication>
#include <QtTest/QtTest>
#include <QtCore/qanimationgroup.h>
#include "qounter_test-moc.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  TestQounter m;

  QTest::qExec( &m );
}
