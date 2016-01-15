#include <mainwindow.h>
#include <ui_mainwindow.h>

int Tester::takePortInfo(void)
{
	switch(com){
		case COM1:
			pInfo.BaudRate = ui->comboBox1->currentText().toInt();
			pInfo.name = ui->comName1->text();
			qDebug("ComPort 1 open");
			break;
		
		case COM2:
			pInfo.BaudRate = ui->comboBox2->currentText().toInt();
			pInfo.name = ui->comName2->text();
			qDebug("ComPort 2 open");
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
		ui->statusBar->showMessage("Open port error");
		emit buttonUpdate(com, 1);
		freeResrc();
		return -1;
	}
	/*
	 * XXX
	 * Suppose the modification about UI should in MainWindow,
	 * but it's hard to new struct `pInfo` and get `Port info`
	 * in MainWindow at the same time
	*/
	ui->statusBar->showMessage(QString("Connected to %1, BaudRate %2.")
								.arg(pInfo.name).arg(pInfo.BaudRate));
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

