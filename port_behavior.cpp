#include <mainwindow.h>
#include <ui_mainwindow.h>

int Tester::openSerialPort(void)
{           
	switch (num){
		case COM1:
			pInfo.BaudRate = ui->comboBox1->currentText().toInt();
			pInfo.name = ui->comName1->text();
			qDebug() << "COM1 open";
			break;
		
		case COM2:
			pInfo.BaudRate = ui->comboBox2->currentText().toInt();
			pInfo.name = ui->comName2->text();
			qDebug() << "COM2 open";
			break;
		
		default:
			qDebug() << "ERROR, No such ComPort" << num;
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
		emit buttonUpdate(num, 1);
		freeResrc();
		return -1;
	}

	ui->statusBar->showMessage(QString("Connected to %1, BaudRate %2.")
								.arg(pInfo.name).arg(pInfo.BaudRate));
	emit buttonUpdate(num, 0);

	return 0;
}

void Tester::closeSerialPort(void)
{
	serial.close();
	emit buttonUpdate(num, 1);
	// XXX
	ui->statusBar->showMessage("Closing connection....");
}
	
void Tester::freeResrc(void)
{
	// XXX
	qDebug() << "The closing thread :" << QThread::currentThread();   
	QThread::currentThread()->quit();
	QThread::currentThread()->wait();
}


