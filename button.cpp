#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::startButton1_clicked(void)
{
	initTester(COM1); 
}
    
void MainWindow::startButton2_clicked(void)
{
	initTester(COM2);
}

void MainWindow::startButton3_clicked(void)
{
	initTester(COM3);
}

void MainWindow::startButton4_clicked(void)
{
	initTester(COM4);
}

void MainWindow::startButton5_clicked(void)
{
	initTester(COM5);
}

void MainWindow::startButton6_clicked(void)
{
	initTester(COM6);
}

void MainWindow::startButton7_clicked(void)
{
	initTester(COM7);
}

void MainWindow::startButton8_clicked(void)
{
	initTester(COM8);
}

void MainWindow::startButton9_clicked(void)
{
	initTester(COM9);
}

void MainWindow::startButton10_clicked(void)
{
	initTester(COM10);
}

void MainWindow::startButton11_clicked(void)
{
	initTester(COM11);
}

void MainWindow::startButton12_clicked(void)
{
	initTester(COM12);
}

void MainWindow::startButton13_clicked(void)
{
	initTester(COM13);
}

void MainWindow::startButton14_clicked(void)
{
	initTester(COM14);
}

void MainWindow::startButton15_clicked(void)
{
	initTester(COM15);
}

void MainWindow::startButton16_clicked(void)
{
	initTester(COM16);
}
/*-----------------------------------------------*/
void MainWindow::closeButton1_clicked(void)
{
	closeTester(COM1);
}

void MainWindow::closeButton2_clicked(void)
{
	closeTester(COM2);
}

void MainWindow::closeButton3_clicked(void)
{
	closeTester(COM3);
}

void MainWindow::closeButton4_clicked(void)
{
	closeTester(COM4);
}

void MainWindow::closeButton5_clicked(void)
{
	closeTester(COM5);
}

void MainWindow::closeButton6_clicked(void)
{
	closeTester(COM6);
}

void MainWindow::closeButton7_clicked(void)
{
	closeTester(COM7);
}

void MainWindow::closeButton8_clicked(void)
{
	closeTester(COM8);
}

void MainWindow::closeButton9_clicked(void)
{
	closeTester(COM9);
}

void MainWindow::closeButton10_clicked(void)
{
	closeTester(COM10);
}

void MainWindow::closeButton11_clicked(void)
{
	closeTester(COM11);
}

void MainWindow::closeButton12_clicked(void)
{
	closeTester(COM12);
}

void MainWindow::closeButton13_clicked(void)
{
	closeTester(COM13);
}

void MainWindow::closeButton14_clicked(void)
{
	closeTester(COM14);
}

void MainWindow::closeButton15_clicked(void)
{
	closeTester(COM15);
}

void MainWindow::closeButton16_clicked(void)
{
	closeTester(COM16);
}
/*------------------------------------------------*/
void MainWindow::buttonSwitch(int com, bool able)
{  
	return startButton[com-1]->setEnabled(able);
}  

void MainWindow::buttonHandle(int com, bool able)
{
	return buttonSwitch(com, able);
} 
	
void MainWindow::ECediterSwitch(int com)
{
	QString tmp;
	
	tmp = testMod[com-1]->currentText();
	if(!QString::compare(tmp, QString(PACKBYCHAR))){
		ascIIButton[com-1]->setEnabled(true);
		hexButton[com-1]->setEnabled(true);
		ecLineEdit[com-1]->setEnabled(true);
	}else{
		ascIIButton[com-1]->setEnabled(false);
		hexButton[com-1]->setEnabled(false);
		ecLineEdit[com-1]->setEnabled(false);
		ecLineEdit[com-1]->clear();
		// TODO: find out setAutoExclusive is for what!
		hexButton[com-1]->setAutoExclusive(false);
		hexButton[com-1]->setChecked(false);
		hexButton[com-1]->setAutoExclusive(true);
		ascIIButton[com-1]->setAutoExclusive(false);
		ascIIButton[com-1]->setChecked(false);
		ascIIButton[com-1]->setAutoExclusive(true);
	}
}
	
