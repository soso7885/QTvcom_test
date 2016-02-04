#include "mainwindow.h"
#include "ui_mainwindow.h"

void Tester::packByCharTest(void)
{
	int i;
	/*-------------- Initial txbuf -----------*/
	if(pInfo.ecTestMode == ASCII){  // ASCII
		txbuf.resize(ASCII_TXDATALEN);
		for(i = 0; i < ASCII_TXDATALEN; i++){
			if(i == 0){
				txbuf[i] = '!';
			}else{
				txbuf[i] = txbuf[i-1] + 1;
			}
		}
	}else{	// HEX
		txbuf.resize(HEX_TXDATALEN);
		for(i = 0; i < HEX_TXDATALEN; i++){
			txbuf[i] = i;
		}
	}
	tRes.txlen = 0;
	tRes.rxlen = 0;
	tRes.round = 0;
	tRes.err = 0;
	tRes.ecerr = 0;
	/*-----------------------------------------*/
	bufFlush();
	connect(serial, SIGNAL(readyRead()), this, SLOT(readHandle()));
	connect(serial, SIGNAL(readChannelFinished()), this, SLOT(result()));
	connect(serial, SIGNAL(bytesWritten(qint64)), this, SLOT(writeHandle()));
	
	writeAll();
}
