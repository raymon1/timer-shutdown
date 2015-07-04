#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>


int time_seconds;
bool running=false;
QString s;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->setInterval(1000);
    timer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    ui->pushButton_2->setEnabled(true);
    ui->pushButton->setEnabled(false);

    time_seconds = (ui->sb_hr->value()*60 + ui->sb_m->value())*60 + ui->sb_s->value();
    running = true;

}

void MainWindow::on_pushButton_2_clicked()
{
    running = false;
    ui->pushButton_2->setEnabled(false);
    ui->pushButton->setEnabled(true);
    running = false;
    ui->l_t->setText("00:00:00");
}

void MainWindow::update()
{
    if(time_seconds>=0 && running)
    {
        s = QString::number(time_seconds/3600);
        s+=":";
        s += QString::number((time_seconds%3600)/60);
       
        s+=":";
        s += QString::number((time_seconds%3600)%60);
        ui->l_t->setText(s);

        if(time_seconds==0 && running)
             system("c:\\windows\\system32\\shutdown /s /t 2 \n\n");

            
        time_seconds--;
    }
}

