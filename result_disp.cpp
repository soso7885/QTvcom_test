#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::openPortStatus(int num)
{
	ui->treeWidget->topLevelItem(num-1)->setText(1, "Open");
}

void MainWindow::closePortStatus(int num)
{
	ui->treeWidget->topLevelItem(num-1)->setText(1, "Close");
}

void MainWindow::portOKStatus(int num)
{
	ui->treeWidget->topLevelItem(num-1)->setText(2, "OK");
}

void MainWindow::portErrStatus(int num, QString errMsg)
{
	ui->treeWidget->topLevelItem(num-1)->setText(2, errMsg);
}

void MainWindow::updateResult(struct testResult *tRes, int num)
{
	ui->treeWidget->topLevelItem(num-1)->child(0)->setText(1, QString::number(tRes->round));
	ui->treeWidget->topLevelItem(num-1)->child(1)->setText(1, QString::number(tRes->txlen));
	ui->treeWidget->topLevelItem(num-1)->child(2)->setText(1, QString::number(tRes->rxlen));
}

