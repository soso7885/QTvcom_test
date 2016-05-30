#include "mainwindow.h"
#include "ui_mainwindow.h"

void Tester::openCloseTest(void)
{
	timer = new QTimer(this);
	/*------------- Initial -----------------*/
	txbuf.resize(TXDATALEN);
	for(int i = 0; i < TXDATALEN; i++){
		if(i == 0){
			txbuf[i] = '!';
		}else{
			txbuf[i] = txbuf[i-1] + 1;
			if(txbuf[i] > '}'){
				txbuf[i] = '!';
			}
		}
	}

	tRes.txlen = 0;
	tRes.rxlen = 0;
	tRes.round = 1;
	tRes.err = 0;
	/*---------------------------------------*/
	bufFlush();	
	connect(serial, SIGNAL(readyRead()), this, SLOT(readHandle()));
	connect(serial, SIGNAL(readChannelFinished()), this, SLOT(result()));
	connect(serial, SIGNAL(bytesWritten(qint64)), this, SLOT(writeHandle()));
	connect(timer, SIGNAL(timeout()), this, SLOT(ocTestClose()));	
	timer->start(80*1000);	// 10sec
	writeAll();
}

void Tester::ocTestClose(void)
{
	qDebug("CLose !!!!");
	closeSerialPort();
	ocTestOpen();
}
	
void Tester::ocTestOpen(void)
{
	qDebug("Open !!!!");
	if(serial->open(QIODevice::ReadWrite)){
		serial->setBaudRate(pInfo.BaudRate);
		serial->setDataBits(QSerialPort::Data8);
		serial->setParity(QSerialPort::NoParity);
		serial->setStopBits(QSerialPort::OneStop);
		serial->setFlowControl(QSerialPort::NoFlowControl);
		emit openUpdate(com);
		bufFlush();
		connect(serial, SIGNAL(readyRead()), this, SLOT(readHandle()));
		connect(serial, SIGNAL(readChannelFinished()), this, SLOT(result()));
		connect(serial, SIGNAL(bytesWritten(qint64)), this, SLOT(writeHandle()));
		tRes.round++;
		timer->start(80*1000);
		writeAll();
	}else{
		qDebug("ocTestOpen Error !");
	}
}
	

