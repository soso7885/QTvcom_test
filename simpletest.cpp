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
				emit errUpdate(num, *err);
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
				emit errUpdate(num, *err);
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
				emit errUpdate(num, *err);
				delete err;
				break;
			}
			if(serial.error() == QSerialPort::TimeoutError && rxbuf.isEmpty()){
				QString *err = new QString;
				*err = "Read timeout: ";
				err->append(serial.errorString());
				qDebug() << *err;
				emit errUpdate(num, *err);
				delete err;
				break;
			}
			tRes.rxlen = rxbuf.size();
		}

		if(tRes.txlen == TXDATALEN && tRes.rxlen == TXDATALEN){
			tRes.round++;
			qDebug("Com %d, Round %d", num, tRes.round);
			emit OKUpdate(num);
		}

		emit resUpdate(&tRes, num);
	}while(isRunning);
	
	emit closeUpdate(num);
	/* FIXME
	 * For segmention fault in QThread(error 4 in libQt5Gui.so.5.2.1)
	 * while closing, I think `freeResrc` is too quick to free itself
	 * while the main thread haven't hadle signal yet, so add the `wait()`.
	 * Unfortunately, it doesn't fix that, but it truly reduce the incidence
	*/
	QThread::currentThread()->wait();
	closeSerialPort();
	freeResrc();
	// XXX
	delete this;	
}	

		
				
	


