/*
    ClipGrab³
    Copyright (C) Philipp Schmieder
    http://clipgrab.de
    feedback [at] clipgrab [dot] de

    This file is part of ClipGrab.
    ClipGrab is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    
    ClipGrab is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with ClipGrab.  If not, see <http://www.gnu.org/licenses/>.
*/



#include <QtGui/QApplication>
#include <QTranslator>
#include "mainwindow.h"
#include "clipgrab.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QCoreApplication::setOrganizationName("Philipp Schmieder");
    QCoreApplication::setOrganizationDomain("http://clipgrab.de");
    QCoreApplication::setApplicationName("ClipGrab³");
    QSplashScreen splash(QPixmap(":/img/splash.png"), Qt::FramelessWindowHint&&Qt::Widget);
    splash.setMask(QPixmap(":/img/splash.png").mask());
    splash.show();

    QString locale = QLocale::system().name();
    QTranslator translator;
    translator.load(QString(":/lng/clipgrab_") + locale);
    app.installTranslator(&translator);

    ClipGrab cg;
    MainWindow w;
    w.cg = &cg;
    w.init();
    w.show();
    splash.finish(w.centralWidget());
    return app.exec();
}
