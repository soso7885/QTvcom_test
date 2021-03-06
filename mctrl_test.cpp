#include "mainwindow.h"
#include "ui_mainwindow.h"

void Tester::DTRhandle(bool set)
{
	mctrlCheck();

	if(serial->isOpen()){
		if(set){
			serial->setRequestToSend(true);
		}else{
			serial->setRequestToSend(false);
		}
	}else{
		qDebug("com %d: Serial port is not open %s(%d)", com, __func__, __LINE__);
	}
}

void Tester::RTShandle(bool set)
{
	mctrlCheck();

	if(serial->isOpen()){
		if(set){
			serial->setDataTerminalReady(false);
		}else{
			serial->setDataTerminalReady(true);
		}
	}else{
		qDebug("com %d: Serial port is not open %s(%d)", com, __func__, __LINE__);
	}
}
	
void Tester::mctrlCheck(void)
{
	int res;
	/*
	 * must wait for serial pin 
	 * signal handle done.
	*/
	QThread::currentThread()->sleep(1);
	
	res = serial->pinoutSignals();

	if(res & QSerialPort::DataTerminalReadySignal){
		mctrlRes.dtr = true;	
	}else{
		mctrlRes.dtr = false;
	}
	
	if(res & QSerialPort::DataCarrierDetectSignal){
		mctrlRes.dcd = true;
	}else{
		mctrlRes.dcd = false;
	}
	
	if(res & QSerialPort::DataSetReadySignal){
		mctrlRes.dsr = true;
	}else{
		mctrlRes.dsr = false;
	}
	
	if(res & QSerialPort::RingIndicatorSignal){
		mctrlRes.ri = true;
	}else{
		mctrlRes.ri = false;
	}
	
	if(res & QSerialPort::RequestToSendSignal){
		mctrlRes.rts = true;
	}else{
		mctrlRes.rts = false;
	}
	
	if(res & QSerialPort::ClearToSendSignal){
		mctrlRes.cts = true;
	}else{
		mctrlRes.cts = false;
	}
	// must RTS == CTS	
	if(mctrlRes.rts ^ mctrlRes.cts){
		SERIAL_CREATE_ERRMSG("RTS != CTS\nround: ", mctrlRes.round);
	// must DTR == DCD == DSR == RI
	}else if(mctrlRes.dtr ^ 
		mctrlRes.dcd ^ 
		mctrlRes.dsr ^
		mctrlRes.ri){
		SERIAL_CREATE_ERRMSG("DTR != DCD != DSR != RI\nround: ", mctrlRes.round);
	}else{
		emit OKUpdate(com);
	}

	emit mcrtrlResUpdate(&mctrlRes, com);
	mctrlRes.round++;
	/*
	 * To handle the events in event Q
	 * I think it's maybe called the currentThread()->sleep(1);
	 * function, the `close` signal is stored in event Q,
	*/
	QCoreApplication::processEvents();
}

void Tester::mctrlTest(void)
{
	serial->setDataTerminalReady(false);
	serial->setRequestToSend(false);
	mctrlRes.round = 1;

	connect(serial, SIGNAL(requestToSendChanged(bool)), this, SLOT(RTShandle(bool)));
	connect(serial, SIGNAL(dataTerminalReadyChanged(bool)), this, SLOT(DTRhandle(bool)));

	serial->setDataTerminalReady(true);	// test Entry
}
	



