#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <QProcess>
#include <QString>
#include <QFileDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QStringList>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_server_push_clicked()
{
    QString port = ui->input_port->toPlainText();
    QString serverip = ui->input_ip->toPlainText();
    string cmd = "./server "+serverip.toStdString()+" "+port.toStdString();
    system("gcc -o server server.c");
    system("./server");
    ui->server_display->setText("A server has already started!");
}

void MainWindow::on_pushButton_clicked()
{
    QString directory = QFileDialog::getOpenFileName(this, tr("Open Directory"),
          "");

    ui->DIR->setText(directory);
}

void MainWindow::on_pushButton_2_clicked()
{
    QString directory = ui->DIR->toPlainText();
    QString port = ui->port->toPlainText();
    QString serverip = ui->server_ip->toPlainText();
    string cmd = "./client "+directory.toStdString()+" "+serverip.toStdString()+" "+port.toStdString();
    system("gcc -o client client.c `mysql_config --cflags --libs`");
    system(cmd.c_str());
}
