#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QImage>
#include "ffwebcam.h"
#include <list>

namespace Ui {
class MainWindow;
}

class MainWindow: public QMainWindow {
   Q_OBJECT
public:
   explicit MainWindow(QWidget *parent = 0);
   ~MainWindow();   
signals:
   void newServerFrame(AVFrame* frame);
private slots:
   void onCameraFrame(AVFrame* frame);
   void onRemoteFrame(AVFrame* frame);
   void on_pushButtonStartReceive_clicked();
   void on_pushButtonStartSend_clicked();

   void on_buttonCall_clicked();

   void on_buttonSendFile_clicked();

private:
   Ui::MainWindow *ui;
   Server* server;
   Client* camera;
   Client* remote;
   SwsContext* cameraToServer;
   SwsContext* cameraToLocal;
   SwsContext* remoteToLocal;
};

#endif // MAINWINDOW_H
