#include "mainwindow.h"
#include "ui_mainwindow.h"
                                        
Tester::Tester(Ui::MainWindow *ui, int com) :
		serial(this)
{     
	this->com = com;  
	this->ui = ui;
	
	switch(com){
		case COM1:
			this->ui_comPortName = ui->comName1;
			this->ui_baudRate = ui->baudRate1;
			this->ui_testMod = ui->test1;
			this->ui_ascIIButton = ui->ascIIButton1;
			this->ui_hexButton = ui->hexButton1;
			this->ui_ecEditer = ui->ecLineEdit1;
			break;
		case COM2:
			this->ui_comPortName = ui->comName2;
			this->ui_baudRate = ui->baudRate2;
			this->ui_testMod = ui->test2;
			this->ui_ascIIButton = ui->ascIIButton2;
			this->ui_hexButton = ui->hexButton2;
			this->ui_ecEditer = ui->ecLineEdit2;
			break;
		case COM3:
			this->ui_comPortName = ui->comName3;
			this->ui_baudRate = ui->baudRate3;
			this->ui_testMod = ui->test3;
			this->ui_ascIIButton = ui->ascIIButton3;
			this->ui_hexButton = ui->hexButton3;
			this->ui_ecEditer = ui->ecLineEdit3;
			break;
		case COM4:
			this->ui_comPortName = ui->comName4;
			this->ui_baudRate = ui->baudRate4;
			this->ui_testMod = ui->test4;
			this->ui_ascIIButton = ui->ascIIButton4;
			this->ui_hexButton = ui->hexButton4;
			this->ui_ecEditer = ui->ecLineEdit4;
			break;
		case COM5:
			this->ui_comPortName = ui->comName5;
			this->ui_baudRate = ui->baudRate5;
			this->ui_testMod = ui->test5;
			this->ui_ascIIButton = ui->ascIIButton5;
			this->ui_hexButton = ui->hexButton5;
			this->ui_ecEditer = ui->ecLineEdit5;
			break;
		case COM6:
			this->ui_comPortName = ui->comName6;
			this->ui_baudRate = ui->baudRate6;
			this->ui_testMod = ui->test6;
			this->ui_ascIIButton = ui->ascIIButton6;
			this->ui_hexButton = ui->hexButton6;
			this->ui_ecEditer = ui->ecLineEdit6;
			break;
		case COM7:
			this->ui_comPortName = ui->comName7;
			this->ui_baudRate = ui->baudRate7;
			this->ui_testMod = ui->test7;
			this->ui_ascIIButton = ui->ascIIButton7;
			this->ui_hexButton = ui->hexButton7;
			this->ui_ecEditer = ui->ecLineEdit7;
			break;
		case COM8:
			this->ui_comPortName = ui->comName8;
			this->ui_baudRate = ui->baudRate8;
			this->ui_testMod = ui->test8;
			this->ui_ascIIButton = ui->ascIIButton8;
			this->ui_hexButton = ui->hexButton8;
			this->ui_ecEditer = ui->ecLineEdit8;
			break;
		case COM9:
			this->ui_comPortName = ui->comName9;
			this->ui_baudRate = ui->baudRate9;
			this->ui_testMod = ui->test9;
			this->ui_ascIIButton = ui->ascIIButton9;
			this->ui_hexButton = ui->hexButton9;
			this->ui_ecEditer = ui->ecLineEdit9;
			break;
		case COM10:
			this->ui_comPortName = ui->comName10;
			this->ui_baudRate = ui->baudRate10;
			this->ui_testMod = ui->test10;
			this->ui_ascIIButton = ui->ascIIButton10;
			this->ui_hexButton = ui->hexButton10;
			this->ui_ecEditer = ui->ecLineEdit10;
			break;
		case COM11:
			this->ui_comPortName = ui->comName11;
			this->ui_baudRate = ui->baudRate11;
			this->ui_testMod = ui->test11;
			this->ui_ascIIButton = ui->ascIIButton11;
			this->ui_hexButton = ui->hexButton11;
			this->ui_ecEditer = ui->ecLineEdit11;
			break;
		case COM12:
			this->ui_comPortName = ui->comName12;
			this->ui_baudRate = ui->baudRate12;
			this->ui_testMod = ui->test12;
			this->ui_ascIIButton = ui->ascIIButton12;
			this->ui_hexButton = ui->hexButton12;
			this->ui_ecEditer = ui->ecLineEdit12;
			break;
		case COM13:
			this->ui_comPortName = ui->comName13;
			this->ui_baudRate = ui->baudRate13;
			this->ui_testMod = ui->test13;
			this->ui_ascIIButton = ui->ascIIButton13;
			this->ui_hexButton = ui->hexButton13;
			this->ui_ecEditer = ui->ecLineEdit13;
			break;
		case COM14:
			this->ui_comPortName = ui->comName14;
			this->ui_baudRate = ui->baudRate14;
			this->ui_testMod = ui->test14;
			this->ui_ascIIButton = ui->ascIIButton14;
			this->ui_hexButton = ui->hexButton14;
			this->ui_ecEditer = ui->ecLineEdit14;
			break;
		case COM15:
			this->ui_comPortName = ui->comName15;
			this->ui_baudRate = ui->baudRate15;
			this->ui_testMod = ui->test15;
			this->ui_ascIIButton = ui->ascIIButton15;
			this->ui_hexButton = ui->hexButton15;
			this->ui_ecEditer = ui->ecLineEdit15;
			break;
		case COM16:
			this->ui_comPortName = ui->comName16;
			this->ui_baudRate = ui->baudRate16;
			this->ui_testMod = ui->test16;
			this->ui_ascIIButton = ui->ascIIButton16;
			this->ui_hexButton = ui->hexButton16;
			this->ui_ecEditer = ui->ecLineEdit16;
			break;
		default:
			qDebug("Critical ERROR !!!");
	}
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
