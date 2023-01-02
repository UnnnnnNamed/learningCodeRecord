#include <QApplication>
#include <QPushButton>
#include "widget.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    widget w;
    w.show();
    return QApplication::exec();
}
