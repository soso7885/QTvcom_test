#include "mainwindow.h"
#include "ui_mainwindow.h"
 
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
	connect(tester, SIGNAL(resUpdateInDataPack(struct testResult*, int)), this,
					SLOT(resPortUpdateInDataPackTest(struct testResult*, int)));
	connect(tester, SIGNAL(mcrtrlResUpdate(struct mctrlResult*, int)), this,
					SLOT(resMctrlUpdate(struct mctrlResult*, int)));
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
	if(testerVect[com-1] != NULL){
		testerVect[com-1]->isRunning = 0;
		ui->statusBar->showMessage(QString("Closing COM%1 ...")
									.arg(com)); 
	}
}

void MainWindow::openPortUpdate(int com)
{
	return openPortStatus(com);	
}

void MainWindow::closePortUpdate(int com)
{
	return closePortStatus(com);
}

void MainWindow::OKPortUpdate(int com)
{
	return portOKStatus(com);
}

void MainWindow::errPortUpdate(int com, QString errMsg)
{
	return portErrStatus(com, errMsg);
}

void MainWindow::resPortUpdate(struct testResult *tRes, int com)
{
	return updateResult(tRes, com);
}

void MainWindow::resPortUpdateInDataPackTest(struct testResult *tRes, int com)
{
	return updateResultInDataPackTest(tRes, com);
}

void MainWindow::resMctrlUpdate(struct mctrlResult *mctrlRes, int com)
{
	return updateResultMctrl(mctrlRes, com);
}

void MainWindow::openPortErr(QString errMsg)
{
	QMessageBox::critical(this, "Error", errMsg);
	ui->statusBar->showMessage("Open Port error...");
}
/*---------------------------------------------------------*/
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
/*---------------------------------------------*/
void MainWindow::checkEnableEC1(void)
{
	return ECediterSwitch(COM1);
}

void MainWindow::checkEnableEC2(void)
{
	return ECediterSwitch(COM2);
}

void MainWindow::checkEnableEC3(void)
{
	return ECediterSwitch(COM3);
}

void MainWindow::checkEnableEC4(void)
{
	return ECediterSwitch(COM4);
}

void MainWindow::checkEnableEC5(void)
{
	return ECediterSwitch(COM5);
}

void MainWindow::checkEnableEC6(void)
{
	return ECediterSwitch(COM6);
}

void MainWindow::checkEnableEC7(void)
{
	return ECediterSwitch(COM7);
}

void MainWindow::checkEnableEC8(void)
{
	return ECediterSwitch(COM8);
}

void MainWindow::checkEnableEC9(void)
{
	return ECediterSwitch(COM9);
}

void MainWindow::checkEnableEC10(void)
{
	return ECediterSwitch(COM10);
}

void MainWindow::checkEnableEC11(void)
{
	return ECediterSwitch(COM11);
}

void MainWindow::checkEnableEC12(void)
{
	return ECediterSwitch(COM12);
}

void MainWindow::checkEnableEC13(void)
{
	return ECediterSwitch(COM13);
}

void MainWindow::checkEnableEC14(void)
{
	return ECediterSwitch(COM14);
}

void MainWindow::checkEnableEC15(void)
{
	return ECediterSwitch(COM15);
}

void MainWindow::checkEnableEC16(void)
{
	return ECediterSwitch(COM16);
}

