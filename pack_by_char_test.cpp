#include "mainwindow.h"
#include "ui_mainwindow.h"

QString compareData(QByteArray rxbuf, struct testResult *tRes, 
				unsigned char ec)
{
	int i;
	QString err;
	
	for(i = 0; i < rxbuf.size(); i++){
		if(qAbs((unsigned char)rxbuf.at(i+1) - 
			(unsigned char )rxbuf.at(i)) != 1
			&& (unsigned char)rxbuf.at(i) != TXDATALEN_IN_PACK-1){
			tRes->err++;
			err = "Data error\n";
			printf("%x | %x\n", (unsigned char)rxbuf.at(i+1),
								(unsigned char)rxbuf.at(i));
			return err;
		}
	}
	
	if((unsigned char)rxbuf.at(rxbuf.size()-1) != ec){
		tRes->ecerr++;
		err = "End char error\n";
		return err; 
	}
	
	return "";
}

void Tester::packByCharTest(void)
{
	int i;
	struct testResult tRes;
	QString err;
	QByteArray txbuf;
	QByteArray rxbuf;

	/* Initial */
	txbuf.resize(TXDATALEN_IN_PACK);
	for(i = 0; i < TXDATALEN_IN_PACK; i++){
		txbuf[i] = i;
	}
	tRes.txlen = 0;
	tRes.rxlen = 0;
	tRes.round = 0;
	tRes.err = 0;
	tRes.ecerr = 0;
	isRunning = 1;
	/* Initial End */
	
	do{
		if(serial.isWritable()){
			tRes.txlen = serial.write(txbuf);
			if(tRes.txlen < 0){
				SERIAL_CREATE_ERRMSG("Write failed:\n");
				break;
			}
			if(tRes.txlen != txbuf.size()){
				qDebug() << "txlen" << tRes.txlen << "!= 1024";
				continue;
			}
			if(!serial.waitForBytesWritten(WRITEWAITTIME)){
				SERIAL_CREATE_ERRMSG("Write timeout:\n");
				break;
			}
		}
		/* Read data */
		if(serial.isReadable()){
			rxbuf = serial.readAll();   // appoint the read buffer

			do{
				rxbuf.append(serial.readAll());	 // read data
			}while(serial.waitForReadyRead(READWAITTIME));

			if(serial.error() == QSerialPort::ReadError){
				SERIAL_CREATE_ERRMSG("Read failed:\n");
				break;
			}
			if(serial.error() == QSerialPort::TimeoutError && rxbuf.isEmpty()){
				SERIAL_CREATE_ERRMSG("Read timeout:\n");
				break;
			}
			/* Data compare */
		//	err = compareData(rxbuf, &tRes, pInfo.ec);
			err = compareData(rxbuf, &tRes, 0xf1);
			if(!err.isEmpty()){
				qDebug()<<err;
				SERIAL_CREATE_ERRMSG("Data incorrect, round: ", tRes.round);
			}
			tRes.rxlen = rxbuf.size();
		}

		if(tRes.txlen == TXDATALEN_IN_PACK){
			tRes.round++;
			qDebug("Com %d, Round %d", com, tRes.round);
			if(err.isEmpty()){
				emit OKUpdate(com);
			}
			emit resUpdate(&tRes, com);
		}
		/* sleep 1 sec */
		QThread::currentThread()->sleep(1);

	}while(isRunning);

	emit closeUpdate(com);
	closeSerialPort();
	freeResrc();
	delete this;
}


