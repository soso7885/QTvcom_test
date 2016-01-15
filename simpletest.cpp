#include "mainwindow.h"
#include "ui_mainwindow.h"

void Tester::simpleTest(void)
{
	int i;
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
	isRunning = 1;
	/* Initial End */
	
	do{
		/* Write data */
		if(serial.isWritable()){
			tRes.txlen = serial.write(txbuf);
			if(tRes.txlen < 0){
				QString *err = new QString;
				*err = "Write failed: ";
				err->append(serial.errorString());
				qDebug() << *err;
				emit errUpdate(com, *err);
				delete err;
				break;
			}
			if(tRes.txlen != txbuf.size()){
				qDebug() << "txlen" << tRes.txlen << "!= 1024";
				continue;
			}
			if(!serial.waitForBytesWritten(WRITEWAITTIME)){
				QString *err = new QString;
				*err = "Write timeout: ";
				err->append(serial.errorString());
				qDebug() << *err;
				emit errUpdate(com, *err);
				delete err;
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
				QString *err = new QString;
				*err = "Read failed: ";
				err->append(serial.errorString());
				qDebug() << *err;
				emit errUpdate(com, *err);
				delete err;
				break;
			}
			if(serial.error() == QSerialPort::TimeoutError && rxbuf.isEmpty()){
				QString *err = new QString;
				*err = "Read timeout: ";
				err->append(serial.errorString());
				qDebug() << *err;
				emit errUpdate(com, *err);
				delete err;
				break;
			}
			/* Data compare */
			tRes.err = memcmp(rxbuf.data(), txbuf.data(), TXDATALEN);
			if(tRes.err != 0){
				QString *err = new QString;
				*err = "Data incorrect, round: ";
				err->append(QString::number(round));
				qDebug() << *err;
				emit errUpdate(com, *err);
				delete err;
			}
			tRes.rxlen = rxbuf.size();
		}

		if(tRes.txlen == TXDATALEN && tRes.rxlen == TXDATALEN){
			tRes.round++;
			qDebug("Com %d, Round %d", com, tRes.round);
			if(tRes.err == 0){
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

		
				
	


