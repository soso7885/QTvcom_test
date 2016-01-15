#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::openPortStatus(int com)
{
	ui->treeWidget->topLevelItem(com-1)->setText(1, "Open");
}

void MainWindow::closePortStatus(int com)
{
	ui->treeWidget->topLevelItem(com-1)->setText(1, "Close");
}

void MainWindow::portOKStatus(int com)
{
	ui->treeWidget->topLevelItem(com-1)->setText(2, "OK");
}

void MainWindow::portErrStatus(int com, QString errMsg)
{
	ui->treeWidget->topLevelItem(com-1)->setText(2, errMsg);
}

void MainWindow::updateResult(struct testResult *tRes, int com)
{
	ui->treeWidget->topLevelItem(com-1)->child(0)->setText(1, QString::number(tRes->round));
	ui->treeWidget->topLevelItem(com-1)->child(1)->setText(1, QString::number(tRes->txlen));
	ui->treeWidget->topLevelItem(com-1)->child(2)->setText(1, QString::number(tRes->rxlen));
	ui->treeWidget->topLevelYtem(com-1)->child(3)->setText(1, QString::number(tRes->err));
}

