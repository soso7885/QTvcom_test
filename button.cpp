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
		default:
			qDebug() << "ERROR, no such ComPort" << com;
	}
}   



