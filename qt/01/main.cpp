#include "src/widget.h"
#include "src/dialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    Dialog dialog;
    dialog.show();
    return a.exec();
}
