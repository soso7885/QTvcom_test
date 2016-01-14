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
	delete ui;
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
	/* Status signal connection !! */
	connect(tester, SIGNAL(openUpdate()), this, SLOT(openPortUpdate()));
	connect(tester, SIGNAL(closeUpdate()), this, SLOT(closePortUpdate()));
	connect(tester, SIGNAL(OKUpdate()), this, SLOT(OKPortUpdate()));
	connect(tester, SIGNAL(resUpdate(struct testResult*)), this, SLOT(resPortUpdate(struct testResult*)));

	this->testerVect[0] = tester;
	qDebug() << "new class tester :" << tester;
	qDebug() << "Main thread :" << QThread::currentThreadId();
	qDebug() << "Create sub thread :" << thread;

	/* Start to VCOM Test */
	thread->start();
}

void MainWindow::closeButton_clicked(void)
{
	testerVect[0]->isRunning = 0;
}

void MainWindow::openPortUpdate(void)
{
	openPortStatus();	
}

void MainWindow::closePortUpdate(void)
{
	closePortStatus();
}

void MainWindow::OKPortUpdate(void)
{
	portOKStatus();
}

void MainWindow::resPortUpdate(struct testResult *tRes)
{
	updateResult(tRes);
}
