#include "mainwindow.h"                                                                                                                                                               
#include "ui_mainwindow.h"
                                        
Tester::Tester(Ui::MainWindow *ui):serial(this)      
{       
	this->ui = ui;
	this->test = 1;
}   

Tester::~Tester(void)                                
{
	qDebug() << "Free tester class :" << this;	
}
 
void Tester::startTest(void)                         
{                                                    
    if(openSerialPort() == -1){                      
		QMessageBox::critical(0, "Error", serial.errorString());
	}else{
		emit openUpdate();
		/* Start VCOM test */
		simpleTest();
	}
//  inHomeTest();
}

