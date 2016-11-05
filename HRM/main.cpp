#include "employe.h"
#include "accueil.h"
#include "login.h"
#include <QApplication>
#include <QObject>
#include <QPushButton>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QString locale = QLocale::system().name().section('_', 0, 0);
    QTranslator translator;
    translator.load(QString("qt_") + locale,
    QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    app.installTranslator(&translator);
    login *l;
    l = new login();
    l->show();
    return app.exec();
}

