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



#ifndef CONVERTER_H
#define CONVERTER_H

#include <QObject>
#include <QtGui>

class converter : public QObject
{
Q_OBJECT
public:
    converter();

    virtual converter* createNewInstance();
    virtual void startConversion(QByteArray* data, QString target, int mode);
    QList<QString> getModes();
    virtual QString getExtensionForMode(int mode);

signals:
        void conversionFinished();

protected:
        QList<QString> _modes;
};

#endif // CONVERTER_H
