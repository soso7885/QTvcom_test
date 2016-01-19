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
	switch(com){
		case COM1:
			able?	ui->startButton1->setEnabled(true) : 
					ui->startButton1->setEnabled(false); 
			break;                                        
		case COM2:
			able?	ui->startButton2->setEnabled(true):
					ui->startButton2->setEnabled(false);
			break;
		case COM3:
			able?	ui->startButton3->setEnabled(true):
					ui->startButton3->setEnabled(false);
			break;		
		case COM4:
			able?	ui->startButton4->setEnabled(true):
					ui->startButton4->setEnabled(false);
			break;
		case COM5:
			able?	ui->startButton5->setEnabled(true):
					ui->startButton5->setEnabled(false);
			break;
		case COM6:
			able?	ui->startButton6->setEnabled(true):
					ui->startButton6->setEnabled(false);
			break;
		case COM7:
			able?	ui->startButton7->setEnabled(true):
					ui->startButton7->setEnabled(false);
			break;
		case COM8:
			able?	ui->startButton8->setEnabled(true):
					ui->startButton8->setEnabled(false);
			break;
		case COM9:
			able?	ui->startButton9->setEnabled(true):
					ui->startButton9->setEnabled(false);
			break;
		case COM10:
			able?	ui->startButton10->setEnabled(true):
					ui->startButton10->setEnabled(false);
			break;
		case COM11:
			able?	ui->startButton11->setEnabled(true):
					ui->startButton11->setEnabled(false);
			break;
		case COM12:
			able?	ui->startButton12->setEnabled(true):
					ui->startButton12->setEnabled(false);
			break;
		case COM13:
			able?	ui->startButton13->setEnabled(true):
					ui->startButton13->setEnabled(false);
			break;
		case COM14:
			able?	ui->startButton14->setEnabled(true):
					ui->startButton14->setEnabled(false);
			break;
		case COM15:
			able?	ui->startButton15->setEnabled(true):
					ui->startButton15->setEnabled(false);
			break;
		case COM16:
			able?	ui->startButton16->setEnabled(true):
					ui->startButton16->setEnabled(false);
			break;
		default:
			qDebug() << "ERROR, no such ComPort" << com;
	}
}   



