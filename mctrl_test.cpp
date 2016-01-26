#include "mainwindow.h"
#include "ui_mainwindow.h"

void Tester::mctrlTest(void)
{
	int opt;
	int res;
	struct mctrlResult mctrlRes;
	
	mctrlRes.round = 0;
	isRunning = 1;
	
	do{
		opt = mctrlRes.round % 6;
		do{
			switch(opt){
				case 0:
					serial.setRequestToSend(true);
					break;
				case 1:
					serial.setRequestToSend(false);
					break;
				case 2:
					serial.setDataTerminalReady(true);
					break;
				case 3:
					serial.setDataTerminalReady(false);
					break;
				case 4:
					serial.setRequestToSend(true);
					serial.setDataTerminalReady(true);
					break;
				case 5:
					serial.setRequestToSend(false);
					serial.setDataTerminalReady(false);
					break;
			}	
			QThread::currentThread()->sleep(2);
		}while(0);
	
		res = serial.pinoutSignals();

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
			SERIAL_CREATE_ERRMSG("RTS != CTS, round: ", mctrlRes.round);
		// must DTR == DCD == DSR == RI
		}else if(mctrlRes.dtr ^ 
			mctrlRes.dcd ^ 
			mctrlRes.dsr ^
			mctrlRes.ri){
			SERIAL_CREATE_ERRMSG("DTR != DCD != DSR != RI, round: ", mctrlRes.round);
		}else{
			emit OKUpdate(com);
		}
		
		emit mcrtrlResUpdate(&mctrlRes, com);
		mctrlRes.round++;
	}while(isRunning);
	
	emit closeUpdate(com);
	closeSerialPort();
	freeResrc();
	delete this;
}
	
	



