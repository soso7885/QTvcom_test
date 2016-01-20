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
	/*
	 * To advoid Com port name empty
	 * XXX: Maybe can combine with buttonSwitch
	*/
	connect(ui->comName1, SIGNAL(textChanged(const QString)), 
				this, SLOT(startEnable1()));	
	connect(ui->comName2, SIGNAL(textChanged(const QString)), 
				this, SLOT(startEnable2()));	
	connect(ui->comName3, SIGNAL(textChanged(const QString)), 
				this, SLOT(startEnable3()));	
	connect(ui->comName4, SIGNAL(textChanged(const QString)), 
				this, SLOT(startEnable4()));	
	connect(ui->comName5, SIGNAL(textChanged(const QString)), 
				this, SLOT(startEnable5()));	
	connect(ui->comName6, SIGNAL(textChanged(const QString)), 
				this, SLOT(startEnable6()));	
	connect(ui->comName7, SIGNAL(textChanged(const QString)), 
				this, SLOT(startEnable7()));	
	connect(ui->comName8, SIGNAL(textChanged(const QString)), 
				this, SLOT(startEnable8()));	
	connect(ui->comName9, SIGNAL(textChanged(const QString)), 
				this, SLOT(startEnable9()));	
	connect(ui->comName10, SIGNAL(textChanged(const QString)), 
				this, SLOT(startEnable10()));	
	connect(ui->comName11, SIGNAL(textChanged(const QString)), 
				this, SLOT(startEnable11()));	
	connect(ui->comName12, SIGNAL(textChanged(const QString)), 
				this, SLOT(startEnable12()));	
	connect(ui->comName13, SIGNAL(textChanged(const QString)), 
				this, SLOT(startEnable13()));	
	connect(ui->comName14, SIGNAL(textChanged(const QString)), 
				this, SLOT(startEnable14()));	
	connect(ui->comName15, SIGNAL(textChanged(const QString)), 
				this, SLOT(startEnable15()));	
	connect(ui->comName16, SIGNAL(textChanged(const QString)), 
				this, SLOT(startEnable16()));	
}

MainWindow::~MainWindow()
{
	delete ui;
}
 
void MainWindow::initTester(int com)
{
	ui->statusBar->showMessage(QString("Opening COM%1 ..."). arg(com));

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
	connect(tester, SIGNAL(errUpdate(int, QString)), this, 
					SLOT(errPortUpdate(int, QString)));
	connect(tester, SIGNAL(resUpdate(struct testResult*, int)), this, 
					SLOT(resPortUpdate(struct testResult*, int)));
	
	/* Button switch */
	connect(tester, SIGNAL(buttonUpdate(int, bool)), this, SLOT(buttonHandle(int, bool)));
	
	/* Open Port error signal */
	connect(tester, SIGNAL(openErrUpdate(QString)), this, SLOT(openPortErr(QString)));

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

void MainWindow::openPortErr(QString errMsg)
{
	QMessageBox::critical(this, "Error", errMsg);
	ui->statusBar->showMessage("Open Port error...");
}

void MainWindow::startEnable1(void)
{
	return buttonSwitch(COM1, BUTTON_ENABLE);
}

void MainWindow::startEnable2(void)
{
	return buttonSwitch(COM2, BUTTON_ENABLE);
}

void MainWindow::startEnable3(void)
{
	return buttonSwitch(COM3, BUTTON_ENABLE);
}

void MainWindow::startEnable4(void)
{
	return buttonSwitch(COM4, BUTTON_ENABLE);
}

void MainWindow::startEnable5(void)
{
	return buttonSwitch(COM5, BUTTON_ENABLE);
}

void MainWindow::startEnable6(void)
{
	return buttonSwitch(COM6, BUTTON_ENABLE);
}

void MainWindow::startEnable7(void)
{
	return buttonSwitch(COM7, BUTTON_ENABLE);
}

void MainWindow::startEnable8(void)
{
	return buttonSwitch(COM8, BUTTON_ENABLE);
}

void MainWindow::startEnable9(void)
{
	return buttonSwitch(COM9, BUTTON_ENABLE);
}

void MainWindow::startEnable10(void)
{
	return buttonSwitch(COM10, BUTTON_ENABLE);
}

void MainWindow::startEnable11(void)
{
	return buttonSwitch(COM11, BUTTON_ENABLE);
}

void MainWindow::startEnable12(void)
{
	return buttonSwitch(COM12, BUTTON_ENABLE);
}

void MainWindow::startEnable13(void)
{
	return buttonSwitch(COM13, BUTTON_ENABLE);
}

void MainWindow::startEnable14(void)
{
	return buttonSwitch(COM14, BUTTON_ENABLE);
}

void MainWindow::startEnable15(void)
{
	return buttonSwitch(COM15, BUTTON_ENABLE);
}

void MainWindow::startEnable16(void)
{
	return buttonSwitch(COM16, BUTTON_ENABLE);
}

