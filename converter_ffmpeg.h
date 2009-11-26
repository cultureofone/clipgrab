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



#ifndef CONVERTER_FFMPEG_H
#define CONVERTER_FFMPEG_H

#include "converter.h"

class ffmpegThread : public QThread
{
    public:
    QByteArray data;
    QString ffmpegCall;
    void run()
    {
        qDebug() << data.size();
        QObject* parent = new QObject;
        ffmpeg = new QProcess(parent);
        ffmpeg->start(ffmpegCall);
        ffmpeg->waitForStarted(5000);
        ffmpeg->write(data, data.size());
        ffmpeg->closeWriteChannel();
        ffmpeg->waitForBytesWritten(-1);
        ffmpeg->waitForFinished(-1);
        qDebug() << ffmpeg->readAll() << ffmpeg->readAllStandardError();
    };
    QProcess* ffmpeg;
};

class converter_ffmpeg : public converter
{
Q_OBJECT
public:
    converter_ffmpeg();

    converter* createNewInstance();
    void startConversion(QByteArray* data, QString target, int mode);
    QString getExtensionForMode(int mode);
    ffmpegThread ffmpeg;

public slots:
    void emitFinished();
};

#endif // CONVERTER_FFMPEG_H
