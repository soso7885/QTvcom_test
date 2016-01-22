#include <mainwindow.h>
#include <ui_mainwindow.h>

int detectTestMode(QString testmode, struct port_info *pInfo)
{
	if(!QString::compare(testmode, QString(SIMPLE))){
		pInfo->testMode = SIMPLE_TEST;
		qDebug("Select Simple test");
	}else if(!QString::compare(testmode, QString(OPENCLOSE))){
		pInfo->testMode = OPENCLOSE_TEST;
		qDebug("Select Open-Close test");
	}else if(!QString::compare(testmode, QString(PACKBYCHAR))){
		pInfo->testMode = PACKBYCHAR_TEST;
		qDebug("Select Pack by character test");
	}else{
		qDebug("Error ! no such test mode");
		return -1;
	}
	
	return 0;
}

int Tester::takePortInfo(void)
{
	QString tmp;

	pInfo.BaudRate = ui_baudRate->currentText().toInt();
	pInfo.name = ui_comPortName->text();
	tmp = ui_testMod->currentText();
	if(detectTestMode(tmp, &pInfo) == -1){
		return -1;
	}
	/* if pack by char , get infomation from UI */
	if(pInfo.testMode == PACKBYCHAR_TEST){
		if(ui_ascIIButton->isChecked()){
			pInfo.ecTestMode = ASCII;
			memcpy(&pInfo.ec, ui_ecEditer->text().toStdString().c_str(), 
					sizeof(unsigned char));
			qDebug("with ASCII");
		}
		if(ui_hexButton->isChecked()){
			pInfo.ecTestMode = HEXADECIMA;
			bool ok;
			pInfo.ec = (unsigned char)ui_ecEditer->text().toUInt(&ok, 16);
			qDebug("with Hexadecima");
		}
	}
	qDebug() << "Open ComPort" << com;
	
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
	QThread::currentThread()->sleep(1);
	qDebug() << "The closing thread :" << QThread::currentThread();   
	QThread::currentThread()->quit();
}

