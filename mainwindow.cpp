#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	/* COM port 1 */
	connect(ui->startButton1, SIGNAL(clicked()), 
		this, SLOT(startButton1_clicked()));
	connect(ui->closeButton1, SIGNAL(clicked()), 
		this, SLOT(closeButton1_clicked()));
	/* COM port 2 */
	connect(ui->startButton2, SIGNAL(clicked()),
		this, SLOT(startButton2_clicked()));
	connect(ui->closeButton2, SIGNAL(clicked()),
		this, SLOT(closeButton2_clicked()));
}

MainWindow::~MainWindow()
{
	delete ui;
}
 
void MainWindow::initTester(int com)
{
	// TODO : Maybe check input argument first !
	QThread *thread = new QThread;			// new a QThread 
	Tester *tester = new Tester(ui, com);	// new Tester

	tester->moveToThread(thread);			// combine thread
	connect(thread, SIGNAL(started()), tester, SLOT(startTest()));	// connect started to startTest
	connect(tester, SIGNAL(finished()), thread, SLOT(quit()));
	connect(tester, SIGNAL(finished()), tester, SLOT(deleteLater()));
	connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
	/* Status signal connection !! */
	connect(tester, SIGNAL(openUpdate(int)), this, SLOT(openPortUpdate(int)));
	connect(tester, SIGNAL(closeUpdate(int)), this, SLOT(closePortUpdate(int)));
	connect(tester, SIGNAL(OKUpdate(int)), this, SLOT(OKPortUpdate(int)));
	connect(tester, SIGNAL(errUpdate(int, QString)), this, SLOT(errPortUpdate(int, QString)));
	connect(tester, SIGNAL(resUpdate(struct testResult*, int)), this, SLOT(resPortUpdate(struct testResult*, int)));
	
	/* Button switch */
	connect(tester, SIGNAL(buttonUpdate(int, bool)), this, SLOT(buttonSwitch(int, bool)));

	this->testerVect[com-1] = tester;
	qDebug() << "Create ComPort" << com;
	qDebug() << "new class tester :" << tester;
	qDebug() << "Create thread :" << thread;

	/* Start to VCOM Test */
	thread->start();
}

void MainWindow::closeTester(int com)
{
	testerVect[com-1]->isRunning = 0;
	ui->statusBar->showMessage(QString("Closing COM%1 ...")
								.arg(com)); 
}

void MainWindow::openPortUpdate(int com)
{
	openPortStatus(com);	
}

void MainWindow::closePortUpdate(int com)
{
	closePortStatus(com);
}

void MainWindow::OKPortUpdate(int com)
{
	portOKStatus(com);
}

void MainWindow::errPortUpdate(int com, QString errMsg)
{
	portErrStatus(com, errMsg);
}

void MainWindow::resPortUpdate(struct testResult *tRes, int com)
{
	updateResult(tRes, com);
}


