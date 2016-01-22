#include "mainwindow.h"
#include "ui_mainwindow.h"

void compareData(QByteArray rxbuf, struct testResult *tRes, 
				struct port_info *pInfo, char *err)
{
	int i;
	unsigned char ec = pInfo->ec;
	
	for(i = 0; i < rxbuf.size()-1; i++){
		if(qAbs((unsigned char)rxbuf.at(i+1) - 
			(unsigned char )rxbuf.at(i)) != 1){
			if(pInfo->ecTestMode == ASCII){
				/* 
				 * In ASCII mode, 
				 * don't check the last of 
				 * haracter in testing string '~' 
				*/
				if((unsigned char)rxbuf.at(i) != '~'){
					sprintf(err, "Data mess:\n(%d)<%c , %c>", i, rxbuf.at(i), rxbuf.at(i+1));
					tRes->err++;
					return;
				}
			}else{
				/*
				 * In HEX mode,
				 * don't check the 
				 * last of testing number
				*/
				if((unsigned char)rxbuf.at(i) != 255){
					sprintf(err, "Data mess:\n(%d)<%#02x , %#02x>", i,
							(unsigned char)rxbuf.at(i),(unsigned char)rxbuf.at(i+1));
					tRes->err++;
					return;
				}
			}
		}
	}
	
	if((unsigned char)rxbuf.at(rxbuf.size()-1) != ec){
		if(pInfo->ecTestMode == ASCII){		// ASCII
			sprintf(err, "End char err\n<%c , %c>",
			(unsigned char)rxbuf.at(rxbuf.size()-1), ec);
		}else{	// Hex
			sprintf(err, "End char err\n<%#02x , %#02x>",
				(unsigned char)rxbuf.at(rxbuf.size()-1), ec);
		}
		tRes->ecerr++;
		
		return;
	}
	
	memset(err, 0, 32);
}

void Tester::packByCharTest(void)
{
	int i;
	struct testResult tRes;
	char err[32];
	char *res;
	QByteArray txbuf;
	QByteArray rxbuf;

	/* Initial */
	if(pInfo.ecTestMode == ASCII){	// ASCII
		txbuf.resize(ASCII_TXDATALEN);
		for(i = 0; i < ASCII_TXDATALEN; i++){
			if(i == 0){
				txbuf[i] = '!';
			}else{
				txbuf[i] = txbuf[i-1] + 1;
			}
		}
	}
	
	if(pInfo.ecTestMode == HEXADECIMA){	// HEX
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
			compareData(rxbuf, &tRes, &pInfo, err);
			res = err;
			if(*res != 0){
				SERIAL_CREATE_ERRMSG(res, tRes.round);
			}
			tRes.rxlen = rxbuf.size();
		}

		if(rxbuf.size() > 0){
			qDebug("Com %d, Round %d", com, tRes.round);
			if(*res == 0){
				emit OKUpdate(com);
			}
			emit resUpdateInDataPack(&tRes, com);
			tRes.round++;
		}
	}while(isRunning);

	emit closeUpdate(com);
	closeSerialPort();
	freeResrc();
	delete this;
}


