#pragma once

#include <QDialog>
#include <QtConcurrentRun>
#include <QFuture>
#include <QAbstractSocket>
#include "ffmpeg.h"

namespace Ui { class CallScreen; }

class CallScreen : public QDialog {
Q_OBJECT
public:
   explicit CallScreen( QString contactName, QString contactURI, QString localURI
                      , QAbstractSocket* socket, QWidget *parent = 0);
   ~CallScreen();
private slots:
   void rejectCall();
   void onSocketError(QAbstractSocket::SocketError);
private:
   Ui::CallScreen *ui;
   Input *remote, *camera, *microphone;
   Output *server;
   QAbstractSocket* socket;
};
