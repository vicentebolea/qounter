#include "qounter-moc.h"
#include <QtCore/QString>
#include <QtCore/QTranslator>
#include <QtWidgets/QMessageBox>
#include <iostream>
#include <QtCore/QDebug>

#define TRANSLATIONS_PATH "/usr/local/share/Qounter/translations/"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  if (QLocale::system().language() != QLocale::English)
  {
    QString file = "lang_es_ES";
    QTranslator *translator =new QTranslator;
    bool result = translator->load(QLocale::system(), file, ".", TRANSLATIONS_PATH, ".qm");
    if (!result)
    {
      qDebug("Unable to load language translation files");
    }
    app.installTranslator(translator);
  }

  Qounter main;
  main.show();
  main.setFixedSize(632,451);

  return app.exec();
}
