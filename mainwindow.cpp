#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	/* COM1 button connect*/
	connect(ui->startButton1, SIGNAL(clicked()), 
		this, SLOT(startButton1_clicked()));
	connect(ui->closeButton1, SIGNAL(clicked()), 
		this, SLOT(closeButton1_clicked()));
	/* COM2 button connect*/
	connect(ui->startButton2, SIGNAL(clicked()),
		this, SLOT(startButton2_clicked()));
	connect(ui->closeButton2, SIGNAL(clicked()),
		this, SLOT(closeButton2_clicked()));
	/* COM3 button connect */
	connect(ui->startButton3, SIGNAL(clicked()),
		this, SLOT(startButton3_clicked()));
	connect(ui->closeButton3, SIGNAL(clicked()),
		this, SLOT(closeButton3_clicked()));
	/* COM4 button connect*/
	connect(ui->startButton4, SIGNAL(clicked()),
		this, SLOT(startButton4_clicked()));
	connect(ui->closeButton4, SIGNAL(clicked()),
		this, SLOT(closeButton4_clicked()));
	/* COM5 button connect*/
	connect(ui->startButton5, SIGNAL(clicked()),
		this, SLOT(startButton5_clicked()));
	connect(ui->closeButton5, SIGNAL(clicked()),
		this, SLOT(closeButton5_clicked()));
	/* COM6 button connect*/
	connect(ui->startButton6, SIGNAL(clicked()),
		this, SLOT(startButton6_clicked()));
	connect(ui->closeButton6, SIGNAL(clicked()),
		this, SLOT(closeButton6_clicked()));
	/* COM7 button connect*/
	connect(ui->startButton7, SIGNAL(clicked()),
		this, SLOT(startButton7_clicked()));
	connect(ui->closeButton7, SIGNAL(clicked()),
		this, SLOT(closeButton7_clicked()));
	/* COM8 button connect*/
	connect(ui->startButton8, SIGNAL(clicked()),
		this, SLOT(startButton8_clicked()));
	connect(ui->closeButton8, SIGNAL(clicked()),
		this, SLOT(closeButton8_clicked()));
	/* COM9 button connect*/
	connect(ui->startButton9, SIGNAL(clicked()),
		this, SLOT(startButton9_clicked()));
	connect(ui->closeButton9, SIGNAL(clicked()),
		this, SLOT(closeButton9_clicked()));
	/* COM10 button connect*/
	connect(ui->startButton10, SIGNAL(clicked()),
		this, SLOT(startButton10_clicked()));
	connect(ui->closeButton10, SIGNAL(clicked()),
		this, SLOT(closeButton10_clicked()));
	/* COM11 button connect*/
	connect(ui->startButton11, SIGNAL(clicked()),
		this, SLOT(startButton11_clicked()));
	connect(ui->closeButton11, SIGNAL(clicked()),
		this, SLOT(closeButton11_clicked()));
	/* COM12 button connect*/
	connect(ui->startButton12, SIGNAL(clicked()),
		this, SLOT(startButton12_clicked()));
	connect(ui->closeButton12, SIGNAL(clicked()),
		this, SLOT(closeButton12_clicked()));
	/* COM13 button connect*/
	connect(ui->startButton13, SIGNAL(clicked()),
		this, SLOT(startButton13_clicked()));
	connect(ui->closeButton13, SIGNAL(clicked()),
		this, SLOT(closeButton13_clicked()));
	/* COM14 button connect*/
	connect(ui->startButton14, SIGNAL(clicked()),
		this, SLOT(startButton14_clicked()));
	connect(ui->closeButton14, SIGNAL(clicked()),
		this, SLOT(closeButton14_clicked()));
	/* COM15 button connect*/
	connect(ui->startButton15, SIGNAL(clicked()),
		this, SLOT(startButton15_clicked()));
	connect(ui->closeButton15, SIGNAL(clicked()),
		this, SLOT(closeButton15_clicked()));
	/* COM16 button connect*/
	connect(ui->startButton16, SIGNAL(clicked()),
		this, SLOT(startButton16_clicked()));
	connect(ui->closeButton16, SIGNAL(clicked()),
		this, SLOT(closeButton16_clicked()));
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


