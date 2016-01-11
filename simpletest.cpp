#include "mainwindow.h"
#include "ui_mainwindow.h"

QTextStream stdo(stdout);

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
	/* Initial End */
	
	do{
		/* Write data */
		if(serial.isWritable()){
			tRes.txlen = serial.write(txbuf);
			if(tRes.txlen < 0){
				stdo << QObject::tr("Write failed, error %1").arg(serial.errorString()) << endl;
				closeSerialPort();
				break;
			}
			if(tRes.txlen != txbuf.size()){
				stdo << QObject::tr("txlen(%1) != %2").arg(tRes.txlen).arg(txbuf.size()) << endl;
				continue;
			}
			if(!serial.waitForBytesWritten(WRITEWAITTIME)){
				stdo << QObject::tr("Write data timeout, error %1").arg(serial.errorString()) << endl;
				closeSerialPort();
				break;
			}
		}
		/* Read data */
		if(serial.isReadable()){
			printf("In readabele\n");
			rxbuf = serial.readAll();	// appoint the read buffer
			do{
				rxbuf.append(serial.readAll());		// read data
			}while(serial.waitForReadyRead(READWAITTIME));
		
			printf("Out of do-while\n");	
			if(serial.error() == QSerialPort::ReadError){
				printf("error\n");
				stdo << QObject::tr("Failed to read data, error %1").arg(serial.errorString());
				closeSerialPort();	
				break;
			}
			if(serial.error() == QSerialPort::TimeoutError && rxbuf.isEmpty()){
				printf("timout error\n");
				stdo << QObject::tr("Read timeout and read nothing (%1)").arg(serial.errorString());
				closeSerialPort();
				break;
			}
			tRes.rxlen = rxbuf.size();
		}

		if(tRes.txlen == TXDATALEN && tRes.rxlen == TXDATALEN){
			tRes.round++;
	//		portOKStatus();
	//		updateResult(&tRes);
			tRes.txlen = 0;
			tRes.rxlen = 0;
		}
	}while(tRes.round < 10);
//	}while(0);
}	

		
				
	


