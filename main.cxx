#include "moc_mainWidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget widget;
    MainWidget main(&widget);

    widget.show();
    return app.exec();
}
