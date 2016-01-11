#include <stdio.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	connect(ui->startButton1, SIGNAL(clicked()), 
		this, SLOT(startButton_clicked()));
	connect(ui->closeButton1, SIGNAL(clicked()), 
		this, SLOT(closeButton_clicked()));
}

MainWindow::~MainWindow()
{
//	closeSerialPort();
	delete ui;
}

Tester::Tester(Ui::MainWindow *ui):serial(this)
{
	
	this->ui = ui;
	this->test = 1;
}

Tester::~Tester(void)
{
	/* TODO: free the QThread resource */
}

void Tester::startTest(void)
{
	printf("Cretae Thread success!!!\n");

	if(openSerialPort() == -1){
		//FIXME
//		QMessageBox::critical(MainWindow(), "Error", pInfo.serial.errorString());
	}else{
		printf("Open Port success !\n");
		simpleTest();
	}
//	inHomeTest();
	
	emit finished();
}	

void MainWindow::startButton_clicked(void)
{
	//TODO: Maybe check input argument first !
	QThread *thread = new QThread;		// new a QThread 
	Tester *tester = new Tester(ui);	// new Tester

	tester->moveToThread(thread);				// combine thread
	connect(thread, SIGNAL(started()), tester, SLOT(startTest()));	// connect started to startTest
	connect(tester, SIGNAL(finished()), thread, SLOT(quit()));
	connect(tester, SIGNAL(finished()), tester, SLOT(deleteLater()));
	connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
	/* Start to VCOM Test */
	thread->start();
}

void MainWindow::closeButton_clicked(void)
{
//	closeSerialPort();
}


