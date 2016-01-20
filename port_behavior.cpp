#include <mainwindow.h>
#include <ui_mainwindow.h>

int detectTestMode(QString testmode, struct port_info *pInfo)
{
	if(QString::compare(testmode, 
			QString("Simple test")) == 0){
		pInfo->testMode = SIMPLE_TEST;
		qDebug("Select Simple test");
		return 0;
	}else if(QString::compare(testmode, 
			QString("Open-Close test")) == 0){
		pInfo->testMode = OPENCLOSE_TEST;
		qDebug("Select Open-Close test");
		return 0;
	}else if(QString::compare(testmode,
			QString("Pack by char test")) == 0){
		pInfo->testMode = PACKBYCHAR_TEST;
		qDebug("Select Pack by char test");
		return 0;
	}
	qDebug("Error ! no such test mode");
	return -1;
}

int Tester::takePortInfo(void)
{
	QString tmp;

	switch(com){
		case COM1:
			pInfo.BaudRate = ui->baudRate1->currentText().toInt();
			pInfo.name = ui->comName1->text();
			tmp = ui->test1->currentText();
			if(detectTestMode(tmp, &pInfo) == -1){
				return -1;
			}
			qDebug("ComPort 1 open");
			break;		
		case COM2:
			pInfo.BaudRate = ui->baudRate2->currentText().toInt();
			pInfo.name = ui->comName2->text();
			tmp = ui->test2->currentText();
			if(detectTestMode(tmp, &pInfo) == -1){
				return -1;
			}
			qDebug("ComPort 2 open");
			break;
		case COM3:
			pInfo.BaudRate = ui->baudRate3->currentText().toInt();
			pInfo.name = ui->comName3->text();
			tmp = ui->test3->currentText();
			if(detectTestMode(tmp, &pInfo) == -1){
				return -1;
			}
			qDebug("ComPort 3 open");
			break;
		case COM4:
			pInfo.BaudRate = ui->baudRate4->currentText().toInt();
			pInfo.name = ui->comName4->text();
			tmp = ui->test4->currentText();
			if(detectTestMode(tmp, &pInfo) == -1){
				return -1;
			}
			qDebug("ComPort 4 open");
			break;
		case COM5:
			pInfo.BaudRate = ui->baudRate5->currentText().toInt();
			pInfo.name = ui->comName5->text();
			tmp = ui->test5->currentText();
			if(detectTestMode(tmp, &pInfo) == -1){
				return -1;
			}
			qDebug("ComPort 5 open");
			break;
		case COM6:
			pInfo.BaudRate = ui->baudRate6->currentText().toInt();
			pInfo.name = ui->comName6->text();
			tmp = ui->test6->currentText();
			if(detectTestMode(tmp, &pInfo) == -1){
				return -1;
			}
			qDebug("ComPort 6 open");
			break;
		case COM7:
			pInfo.BaudRate = ui->baudRate7->currentText().toInt();
			pInfo.name = ui->comName7->text();
			tmp = ui->test7->currentText();
			if(detectTestMode(tmp, &pInfo) == -1){
				return -1;
			}
			qDebug("ComPort 7 open");
			break;
		case COM8:
			pInfo.BaudRate = ui->baudRate8->currentText().toInt();
			pInfo.name = ui->comName8->text();
			tmp = ui->test8->currentText();
			if(detectTestMode(tmp, &pInfo) == -1){
				return -1;
			}
			qDebug("ComPort 8 open");
			break;
		case COM9:
			pInfo.BaudRate = ui->baudRate9->currentText().toInt();
			pInfo.name = ui->comName9->text();
			tmp = ui->test9->currentText();
			if(detectTestMode(tmp, &pInfo) == -1){
				return -1;
			}
			qDebug("ComPort 9 open");
			break;
		case COM10:
			pInfo.BaudRate = ui->baudRate10->currentText().toInt();
			pInfo.name = ui->comName10->text();
			tmp = ui->test10->currentText();
			if(detectTestMode(tmp, &pInfo) == -1){
				return -1;
			}
			qDebug("ComPort 10 open");
			break;
		case COM11:
			pInfo.BaudRate = ui->baudRate11->currentText().toInt();
			pInfo.name = ui->comName11->text();
			tmp = ui->test11->currentText();
			if(detectTestMode(tmp, &pInfo) == -1){
				return -1;
			}
			qDebug("ComPort 11 open");
			break;
		case COM12:
			pInfo.BaudRate = ui->baudRate12->currentText().toInt();
			pInfo.name = ui->comName12->text();
			tmp = ui->test12->currentText();
			if(detectTestMode(tmp, &pInfo) == -1){
				return -1;
			}
			qDebug("ComPort 12 open");
			break;
		case COM13:
			pInfo.BaudRate = ui->baudRate13->currentText().toInt();
			pInfo.name = ui->comName13->text();
			tmp = ui->test13->currentText();
			if(detectTestMode(tmp, &pInfo) == -1){
				return -1;
			}
			qDebug("ComPort 13 open");
			break;
		case COM14:
			pInfo.BaudRate = ui->baudRate14->currentText().toInt();
			pInfo.name = ui->comName14->text();
			tmp = ui->test14->currentText();
			if(detectTestMode(tmp, &pInfo) == -1){
				return -1;
			}
			qDebug("ComPort 14 open");
			break;
		case COM15:
			pInfo.BaudRate = ui->baudRate15->currentText().toInt();
			pInfo.name = ui->comName15->text();
			tmp = ui->test15->currentText();
			if(detectTestMode(tmp, &pInfo) == -1){
				return -1;
			}
			qDebug("ComPort 15 open");
			break;
		case COM16:
			pInfo.BaudRate = ui->baudRate16->currentText().toInt();
			pInfo.name = ui->comName16->text();
			tmp = ui->test16->currentText();
			if(detectTestMode(tmp, &pInfo) == -1){
				return -1;
			}
			qDebug("ComPort 16 open");
			break;
		default:
			qDebug("ERROR ! No such ComPort %d", com);
			return -1;
	}
	return 0;
}

int Tester::openSerialPort(void)
{
	if(takePortInfo() == -1){
		return -1;
	}
	
	serial.setPortName(pInfo.name);
	
	if(serial.open(QIODevice::ReadWrite)){
		serial.setBaudRate(pInfo.BaudRate);
		serial.setDataBits(QSerialPort::Data8);
		serial.setParity(QSerialPort::NoParity);
		serial.setStopBits(QSerialPort::OneStop);
		serial.setFlowControl(QSerialPort::NoFlowControl);
	}else{
		qDebug("Open Port error");
		emit openErrUpdate(serial.errorString());
		emit buttonUpdate(com, 1);
		return -1;
	}
	
	emit buttonUpdate(com, 0);
	return 0;
}

void Tester::closeSerialPort(void)
{
	serial.close();
	emit buttonUpdate(com, 1);
}
	
void Tester::freeResrc(void)
{
	qDebug() << "The closing thread :" << QThread::currentThread();   
	QThread::currentThread()->quit();
	QThread::currentThread()->wait();
}

