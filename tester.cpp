#include "mainwindow.h"
#include "ui_mainwindow.h"                     
/*
 * To collect all the port 
 * infomaiton on UI
*/
Tester::Tester(Ui::MainWindow *ui, int com) 
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
		// OPEN-CLOSE test's test round ++ in his testing function
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
	qDebug("Delete COM%d", com);
	if(timer != NULL){
		delete timer;	// only open-close test should delete
	}
	qDebug() << "Free tester class :" << this;	
	delete serial;
}
 
void Tester::startTest(void)                         
{          
	if(openSerialPort() == -1){                      
		freeResrc();
	}else{
		emit openUpdate(com);
		/* Start VCOM test */
		switch(pInfo.testMode){
			case SIMPLE_TEST:
				simpleTest();
				break;
			case OPENCLOSE_TEST:
				openCloseTest();
				break;
			case PACKBYCHAR_TEST:
				packByCharTest();
				break;
			case MCTRL_TEST:
				mctrlTest();
				break;
			default:
				qDebug("Test mode select WRONG !!");
				return;
		}
	}
}

void Tester::bufFlush(void)
{
	QByteArray flushBuf;

	if(serial->isOpen()){
		flushBuf.resize(TXDATALEN);
		flushBuf = serial->readAll();
	
		do{
			flushBuf.append(serial->read(serial->bytesAvailable()));
		}while(serial->bytesAvailable() != 0);

		qDebug("Flush %d byte", flushBuf.size());
	}else{
		qDebug("com %d: Serial port is not open %s(%d)", com, __func__, __LINE__);
	}
}
		

void Tester::readHandle(void)
{
	if(serial->isOpen()){
		rxbuf.resize(TXDATALEN);
		rxbuf = serial->readAll();

		do{
			rxbuf.append(serial->read(serial->bytesAvailable()));
        }while(serial->bytesAvailable() != 0);

		tRes.rxlen += rxbuf.size();
		emit serial->readChannelFinished();
	}else{
		qDebug("com %d: Serial port is not open %s(%d)", com, __func__, __LINE__);
	}
}

void Tester::writeAll(void)
{
	qint64 tmp;
	qint64 total = 0;
	qint64 hopeWrite;

	if(pInfo.testMode == PACKBYCHAR_TEST){
		if(pInfo.ecTestMode == ASCII){
			hopeWrite = ASCII_TXDATALEN;
		}else{
			hopeWrite = HEX_TXDATALEN;
		}
	}else{
		hopeWrite = TXDATALEN;
	}

	do{
		tmp = serial->write(txbuf);
		total += tmp;
	}while(total != hopeWrite);

	tRes.txlen += total;
}
		
void Tester::writeHandle(void)
{
	if(serial->isOpen()){
		writeAll();
	}else{
		qDebug("com %d: Serial port is not open %s(%d)", com, __func__, __LINE__);
	}
}

int Tester::compared(void)
{
	int i;
	char *res;
	char err[32];

	// XXX: too ugly
	if(pInfo.testMode == PACKBYCHAR_TEST){
		unsigned char ec = pInfo.ec;
		for(i = 0; i < rxbuf.size()-1; i++){
			if(qAbs((unsigned char)rxbuf.at(i+1) -
				(unsigned char )rxbuf.at(i)) != 1){
				if(pInfo.ecTestMode == ASCII){
					/*
				 	* In ASCII mode,
				 	* don't check the last of
				 	* character in testing string '!'
					*/
					if((unsigned char)rxbuf.at(i+1) > '!' &&
						(unsigned char)rxbuf.at(i) >= '!')
					{
						sprintf(err, "Data mess:\n(%d)<%c , %c>",
									i, rxbuf.at(i), rxbuf.at(i+1));
						qDebug() << rxbuf;
						res = err;
						tRes.err++;
						SERIAL_CREATE_ERRMSG(res, tRes.round);
						return -1;
					}
				}else{
					/*
				 	* In Hex mode
				 	* don't check the last of
				 	* testing number 255
					*/
					if((unsigned char)rxbuf.at(i) != 255){
						sprintf(err, "Data mess:\n(%d)<%#02x , %#02x>",
								i, (unsigned char)rxbuf.at(i),
								(unsigned char)rxbuf.at(i+1));
						res = err;
						tRes.err++;
						SERIAL_CREATE_ERRMSG(res, tRes.round);
						return -1;
					}
				}
			}
		}
		if((unsigned char)rxbuf.at(rxbuf.size()-1) != ec){
			if(pInfo.ecTestMode == ASCII){		// ASCII
				sprintf(err, "End char err\n<%c , %c>",
					(unsigned char)rxbuf.at(rxbuf.size()-1), ec);
			}else{	// Hex
				sprintf(err, "End char err\n<%#02x , %#02x>",
					(unsigned char)rxbuf.at(rxbuf.size()-1), ec);
			}
			res = err;
			SERIAL_CREATE_ERRMSG(res, tRes.round);
			tRes.ecerr++;
			return -1;
		}
	}else{
		/*
		 * for simple test, open-close test check
		*/	
		for(i = 0; i < rxbuf.size()-1; i++){
			if(qAbs((unsigned char)rxbuf.at(i+1) - 
				(unsigned char )rxbuf.at(i)) != 1){
				if((unsigned char)rxbuf.at(i+1) > '!' &&
					(unsigned char)rxbuf.at(i) >= '!')
				{
					tRes.err++;
					qDebug("Data mess:(%d)<%x , %x>\n", i, rxbuf.at(i), rxbuf.at(i+1));
					snprintf(err, 32, "Data mess:\n(%d)<%c , %c>", 
							i, rxbuf.at(i), rxbuf.at(i+1));
					res = err;
					SERIAL_CREATE_ERRMSG(res, tRes.round);
				
					return -1;
				}
			}
		}
	}
	return 0;
}
	
void Tester::result(void)
{
	if(serial->isOpen()){
		if(compared() == 0){
			if(tRes.err == 0){
				emit OKUpdate(com);
			}
		}
		if(pInfo.testMode == SIMPLE_TEST){
			tRes.round = tRes.rxlen/TXDATALEN;
			emit resUpdate(&tRes, com);
		}else if(pInfo.testMode == OPENCLOSE_TEST){
			emit resUpdate(&tRes, com);
		}else if(pInfo.testMode == PACKBYCHAR_TEST){
			if(pInfo.ecTestMode == ASCII){
				tRes.round = tRes.rxlen/ASCII_TXDATALEN;
			}else{
				tRes.round = tRes.rxlen/HEX_TXDATALEN;
			}
			emit resUpdateInDataPack(&tRes, com);
		}else{
			// other test mode result
		}
	}else{
		qDebug("com %d: Serial port is not open %s(%d)", com, __func__, __LINE__);
	}
}

void Tester::terminate(void)
{
	if(serial->isOpen()){
		qDebug("In COM%d terminate", com);
		emit buttonUpdate(com, 1);
		closeSerialPort();
		freeResrc();
		/*
		 * As long as you're careful, 
		 * it's OK for an object to commit 
		 * suicide (delete this).
		*/
		delete this;
	}else{
		qDebug("com %d: Serial port is not open %s(%d)", com, __func__, __LINE__);
	}
}

