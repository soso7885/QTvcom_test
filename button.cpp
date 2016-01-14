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

void MainWindow::closeButton1_clicked(void)
{
	closeTester(COM1);
}

void MainWindow::closeButton2_clicked(void)
{
	closeTester(COM2);
}

void MainWindow::buttonSwitch(int num, bool able)
{   
	switch(num){
		case COM1:
			able?	ui->startButton1->setEnabled(true) : 
					ui->startButton1->setEnabled(false); 
			break;                                        
		case COM2:
			able?	ui->startButton2->setEnabled(true):
					ui->startButton2->setEnabled(false);
			break;
	}
}   



