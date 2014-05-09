#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <iostream>
#include <QtCore>
#include <QDebug>
#include "sobre.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    thread1 = new Thread1(this);
    thread2 = new Thread2(this);
    thread11 = new Thread1(this);
    thread12 = new Thread1(this);
    thread13 = new Thread1(this);
    thread14 = new Thread1(this);

    rc = 0;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter paint(this);
    QPen penblack(Qt::black);

    penblack.setWidth(3);
    paint.setPen(penblack);

    paint.drawLine (QPointF (15, 30), QPointF (65, 30));
    paint.drawLine (QPointF (65, 30), QPointF (65, 80));
    paint.drawLine (QPointF (15, 80), QPointF (65, 80));
    paint.drawLine (QPointF (15, 30), QPointF (15, 80));

    paint.drawLine (QPointF (65, 30), QPointF (115, 30));
    paint.drawLine (QPointF (115, 30), QPointF (115, 80));
    paint.drawLine (QPointF (65, 80), QPointF (115, 80));
    paint.drawLine (QPointF (65, 30), QPointF (65, 80));

    paint.drawLine (QPointF (115, 30), QPointF (165, 30));
    paint.drawLine (QPointF (165, 30), QPointF (165, 80));
    paint.drawLine (QPointF (115, 80), QPointF (165, 80));
    paint.drawLine (QPointF (115, 30), QPointF (115, 80));

    paint.drawLine (QPointF (165, 30), QPointF (215, 30));
    paint.drawLine (QPointF (215, 30), QPointF (215, 80));
    paint.drawLine (QPointF (165, 80), QPointF (215, 80));
    paint.drawLine (QPointF (165, 30), QPointF (165, 80));

    paint.drawLine (QPointF (215, 30), QPointF (265, 30));
    paint.drawLine (QPointF (265, 30), QPointF (265, 80));
    paint.drawLine (QPointF (215, 80), QPointF (265, 80));
    paint.drawLine (QPointF (215, 30), QPointF (215, 80));

    if(!escritor)
        paint.fillRect(325, 79, 10, 10, Qt::red);
    else
        paint.fillRect(325, 79, 10, 10, Qt::green);

    for(int i = 1; i <= rc; i++) {
        paint.fillRect((i - 1) * 50 + 15, 30, 50, 50, Qt::red);
    }

    update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    sem1 = new Semaforo(1234, 1, IPC_CREAT|0600);
    sem2 = new Semaforo(1235, 1, IPC_CREAT|0600);

    thread2->setSem1(sem1);
    thread2->setSem2(sem2);
    thread2->setNum(&escritor, &rc);

    thread2->start(QThread::LowestPriority);

    while(!thread2->isFinished()) {
        QCoreApplication::processEvents();
        switch(rc) {
        case 0:
            thread1->setSem1(sem1);
            thread1->setSem2(sem2);
            thread1->setNum(&rc);
            thread1->start();
            break;
        case 1:
            thread11->setSem1(sem1);
            thread11->setSem2(sem2);
            thread11->setNum(&rc);
            thread11->start();
            break;
        case 2:
            thread12->setSem1(sem1);
            thread12->setSem2(sem2);
            thread12->setNum(&rc);
            thread12->start();
            break;
        case 3:
            thread13->setSem1(sem1);
            thread13->setSem2(sem2);
            thread13->setNum(&rc);
            thread13->start();
            break;
        case 4:
            thread14->setSem1(sem1);
            thread14->setSem2(sem2);
            thread14->setNum(&rc);
            thread14->start();
            break;
        }
        sleep(1);
    }
}

void MainWindow::on_actionSobre_triggered()
{
    Sobre sobre;
    sobre.setModal(true);
    sobre.exec();
}
