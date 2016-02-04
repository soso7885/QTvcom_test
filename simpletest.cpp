#include "mainwindow.h"
#include "ui_mainwindow.h"

void Tester::simpleTest(void)
{
	int i;
	/*-------------- Initial txbuf -----------*/
	txbuf.resize(TXDATALEN);
	for(i = 0; i < TXDATALEN; i++){
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
	tRes.round = 0;
	tRes.err = 0;
	/*---------------------------------------*/
	bufFlush();
	connect(serial, SIGNAL(readyRead()), this, SLOT(readHandle()));
	connect(serial, SIGNAL(readChannelFinished()), this, SLOT(result()));
	connect(serial, SIGNAL(bytesWritten(qint64)), this, SLOT(writeHandle()));

	writeAll();
}
		
				
	


