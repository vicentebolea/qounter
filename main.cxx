#include "moc_mainWidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget widget;
    MainWidget main(&widget);

    widget.show();
    widget.setFixedSize(632,451);
    return app.exec();
}
