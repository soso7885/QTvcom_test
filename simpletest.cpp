#include "mainwindow.h"
#include "ui_mainwindow.h"

void Tester::simpleTest(void)
{
	int i;	
	int res = 0;
	struct testResult tRes;
	QByteArray txbuf;
	QByteArray rxbuf;

	/* Initial */
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
	tRes.ecerr = 0;
	isRunning = 1;
	/* Initial End */
	do{
		/* Write data */
		if(serial.isWritable()){
			tRes.txlen = serial.write(txbuf);
			if(tRes.txlen < 0){
				SERIAL_CREATE_ERRMSG("Write failed\n");
				break;
			}
			if(tRes.txlen != txbuf.size()){
				qDebug() << "txlen" << tRes.txlen << "!= 1024";
				continue;
			}
			if(!serial.waitForBytesWritten(WRITEWAITTIME)){
				SERIAL_CREATE_ERRMSG("Write timeout\n");
				break;
			}
		}
		/* Read data */
		if(serial.isReadable()){
			rxbuf = serial.readAll();	// appoint the read buffer
		
			do{
				rxbuf.append(serial.readAll());		// read data
			}while(serial.waitForReadyRead(READWAITTIME));
		
			if(serial.error() == QSerialPort::ReadError){
				SERIAL_CREATE_ERRMSG("Read failed\n");
				break;
			}
			if(serial.error() == QSerialPort::TimeoutError && rxbuf.isEmpty()){
				SERIAL_CREATE_ERRMSG("Read timeout\n");
				break;
			}
			/* Data compare */
			res = QString::compare(rxbuf, txbuf);
			if(res){
				SERIAL_CREATE_ERRMSG("Data incorrect, round: ", tRes.round);
			}
			tRes.rxlen = rxbuf.size();
		}

		if(tRes.txlen == TXDATALEN && tRes.rxlen == TXDATALEN){
			tRes.round++;
			qDebug("Com %d, Round %d", com, tRes.round);
			if(!res){
				emit OKUpdate(com);
			}
		}
		emit resUpdate(&tRes, com);
	}while(isRunning);
	
	emit closeUpdate(com);
	closeSerialPort();
	freeResrc();
	delete this;	
}	

		
				
	


