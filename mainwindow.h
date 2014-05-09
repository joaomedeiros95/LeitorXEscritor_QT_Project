#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "thread1.h"
#include "thread2.h"
#include "semaforo.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int rc;
    Semaforo *sem1;
    Semaforo *sem2;
    Thread1 *thread1;
    Thread2 *thread2;
    Thread1 *thread11;
    Thread1 *thread12;
    Thread1 *thread13;
    Thread1 *thread14;
    bool escritor;

protected:
    void paintEvent(QPaintEvent *e);

private slots:
    void on_pushButton_clicked();

    void on_actionSobre_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
