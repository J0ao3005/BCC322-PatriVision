#include <QApplication>
#include "MainWindow.h"
#include "IPatriVisionService.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    IPatriVisionService* service = IPatriVisionService::createService();
    MainWindow w(service);
    w.show();
    int ret = a.exec();
    delete service;
    return ret;
}
