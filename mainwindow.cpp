#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCloseEvent>
#include <QListWidgetItem>
#include <eventlistwidgetitem.h>

MainWindow::MainWindow(Reminder *r, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(r, SIGNAL(showSettingsWindow()), this, SLOT(show()));
    connect(this, SIGNAL(settingsChanged()), r, SLOT(rereadsettings()));
    connect(ui->listWidget, SIGNAL(currentRowChanged(int)), ui->stackedWidget, SLOT(setCurrentIndex(int)));

    //Засиделся
    EventListWidgetItem *nt = new EventListWidgetItem(this);
    nt->setEventName("Заработался");
    nt->setIconPath(":/icon/seeting.png");
    QListWidgetItem *it = new QListWidgetItem();
    it->setSizeHint(QSize(0, nt->height()));
    ui->eventList->addItem(it);
    ui->eventList->setItemWidget(it,nt);

    nt = new EventListWidgetItem(this);
    nt->setEventName("Пора домой");
    nt->setIconPath(":/icon/work_time.png");
    it = new QListWidgetItem();
    it->setSizeHint(QSize(0, nt->height()));
    ui->eventList->addItem(it);
    ui->eventList->setItemWidget(it,nt);

    nt = new EventListWidgetItem(this);
    nt->setEventName("Хватит сидеть в интернете");
    nt->setIconPath(":/icon/internet.png");
    it = new QListWidgetItem();
    it->setSizeHint(QSize(0, nt->height()));
    ui->eventList->addItem(it);
    ui->eventList->setItemWidget(it,nt);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    event->ignore();
    hide();
}
