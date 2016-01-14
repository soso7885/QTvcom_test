#include <mainwindow.h>
#include <ui_mainwindow.h>

int Tester::openSerialPort(void)
{           
	pInfo.BaudRate = ui->comboBox->currentText().toInt();
	pInfo.name = ui->comName1->text(); 
	serial.setPortName(pInfo.name);
	
	if(serial.open(QIODevice::ReadWrite)){
		serial.setBaudRate(pInfo.BaudRate);
		serial.setDataBits(QSerialPort::Data8);
		serial.setParity(QSerialPort::NoParity);
		serial.setStopBits(QSerialPort::OneStop);
		serial.setFlowControl(QSerialPort::NoFlowControl);
	}else{
		ui->statusBar->showMessage("Open port error");
		ui->startButton1->setEnabled(true);
		return -1;
	}

	ui->statusBar->showMessage(QString("Connected to %1, BaudRate %2.")
								.arg(pInfo.name).arg(pInfo.BaudRate));
	ui->startButton1->setEnabled(false);

	return 0;
}

void Tester::closeSerialPort(void)
{
	serial.close();
//	emit closeUpdate();
	ui->startButton1->setEnabled(true);
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


