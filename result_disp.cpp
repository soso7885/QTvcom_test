#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::openPortStatus(int com)
{
	ui->treeWidget->topLevelItem(com-1)->setText(2, "Open");
}

void MainWindow::closePortStatus(int com)
{
	ui->treeWidget->topLevelItem(com-1)->setText(2, "Close");
}

void MainWindow::portOKStatus(int com)
{
	ui->treeWidget->topLevelItem(com-1)->setText(1, "OK");
	// Green
	ui->treeWidget->topLevelItem(com-1)->setForeground(1, QBrush(QColor(0, 255, 0)));
}

void MainWindow::portErrStatus(int com, QString errMsg)
{
	ui->treeWidget->topLevelItem(com-1)->setText(1, "Error");
	// Red
	ui->treeWidget->topLevelItem(com-1)->setForeground(1, QBrush(QColor(255, 0, 0)));
	ui->treeWidget->topLevelItem(com-1)->child(5)->setText(1, errMsg);
}

void MainWindow::updateResult(struct testResult *tRes, int com)
{
	ui->treeWidget->topLevelItem(com-1)->child(0)->setText(1, QString::number(tRes->round));
	ui->treeWidget->topLevelItem(com-1)->child(1)->setText(1, QString::number(tRes->txlen));
	ui->treeWidget->topLevelItem(com-1)->child(2)->setText(1, QString::number(tRes->rxlen));
}

void MainWindow::updateResultInDataPackTest(struct testResult *tRes, int com)
{
	ui->treeWidget->topLevelItem(com-1)->child(0)->setText(1, QString::number(tRes->round));
	ui->treeWidget->topLevelItem(com-1)->child(1)->setText(1, QString::number(tRes->txlen));
	ui->treeWidget->topLevelItem(com-1)->child(2)->setText(1, QString::number(tRes->rxlen));
	ui->treeWidget->topLevelItem(com-1)->child(3)->setText(1, QString::number(tRes->err));
	ui->treeWidget->topLevelItem(com-1)->child(4)->setText(1, QString::number(tRes->ecerr));
}

void MainWindow::updateResultMctrl(struct mctrlResult *mctrlRes, int com)
{
	bool dtr = mctrlRes->dtr;
	bool rts = mctrlRes->rts;
	bool cts = mctrlRes->cts;
	bool dcd = mctrlRes->dcd;
	bool dsr = mctrlRes->dsr;
	bool ri = mctrlRes->ri;
	QTreeWidgetItem *DTR = ui->treeWidget->topLevelItem(com-1)->child(6)->child(0);
	QTreeWidgetItem *RTS = ui->treeWidget->topLevelItem(com-1)->child(6)->child(1);
	QTreeWidgetItem *CTS = ui->treeWidget->topLevelItem(com-1)->child(6)->child(2);
	QTreeWidgetItem *DCD = ui->treeWidget->topLevelItem(com-1)->child(6)->child(3);
	QTreeWidgetItem *DSR = ui->treeWidget->topLevelItem(com-1)->child(6)->child(4);
	QTreeWidgetItem *RNG = ui->treeWidget->topLevelItem(com-1)->child(6)->child(5);
	
	ui->treeWidget->topLevelItem(com-1)->child(0)->setText(1,
										 QString::number(mctrlRes->round));
	
	if(dtr){
		DTR->setText(1, "O");
		DTR->setForeground(1, QBrush(QColor(0, 255, 0)));
	}else{
		DTR->setText(1, "X");
		DTR->setForeground(1, QBrush(QColor(255, 0, 0)));
	}

	if(rts){
		RTS->setText(1, "O");
		RTS->setForeground(1, QBrush(QColor(0, 255, 0)));
	}else{
		RTS->setText(1, "X");
		RTS->setForeground(1, QBrush(QColor(255, 0, 0)));
	}

	if(cts){
		CTS->setText(1, "O");
		CTS->setForeground(1, QBrush(QColor(0, 255, 0)));
	}else{
		CTS->setText(1, "X");
		CTS->setForeground(1, QBrush(QColor(255, 0, 0)));
	}

	if(dcd){
		DCD->setText(1, "O");
		DCD->setForeground(1, QBrush(QColor(0, 255, 0)));
	}else{
		DCD->setText(1, "X");
		DCD->setForeground(1, QBrush(QColor(255, 0, 0)));
	}

	if(dsr){
		DSR->setText(1, "O");
		DSR->setForeground(1, QBrush(QColor(0, 255, 0)));
	}else{
		DSR->setText(1, "X");
		DSR->setForeground(1, QBrush(QColor(255, 0, 0)));
	}

	if(ri){
		RNG->setText(1, "O");
		RNG->setForeground(1, QBrush(QColor(0, 255, 0)));
	}else{
		RNG->setText(1, "X");
		RNG->setForeground(1, QBrush(QColor(255, 0, 0)));
	}
}
