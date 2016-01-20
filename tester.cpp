#include "mainwindow.h"
#include "ui_mainwindow.h"
                                        
Tester::Tester(Ui::MainWindow *ui, int com) :
		serial(this)
{     
	this->com = com;  
	this->ui = ui;
}   

Tester::~Tester(void)                                
{
	qDebug() << "Free tester class :" << this;	
}
 
void Tester::startTest(void)                         
{                                                    
    if(openSerialPort() == -1){                      
		freeResrc();
	}else{
		emit openUpdate(com);
		/* Start VCOM test */
		if(pInfo.testMode == SIMPLE_TEST){
			simpleTest();
		}else if(pInfo.testMode == OPENCLOSE_TEST){
			openCloseTest();
		}else if(pInfo.testMode == PACKBYCHAR_TEST){
			packByCharTest();
		}else{
			qDebug("Test mode select WRONG !!");
			return;
		}
	}
}

