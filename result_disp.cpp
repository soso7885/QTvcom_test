#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::openPortStatus(void)
{
	ui->treeWidget->topLevelItem(0)->setText(1, "Open");
}

void MainWindow::closePortStatus(void)
{
	ui->treeWidget->topLevelItem(0)->setText(1, "Close");
}

void MainWindow::portOKStatus(void)
{
	ui->treeWidget->topLevelItem(0)->setText(2, "OK");
}

void MainWindow::portErrStatus(void)
{
	ui->treeWidget->topLevelItem(0)->setText(2, "Error");
}

void MainWindow::updateResult(struct testResult *tRes)
{
	ui->treeWidget->topLevelItem(0)->child(0)->setText(1, QString::number(tRes->round));
	ui->treeWidget->topLevelItem(0)->child(1)->setText(1, QString::number(tRes->txlen));
	ui->treeWidget->topLevelItem(0)->child(2)->setText(1, QString::number(tRes->rxlen));
//	ui->treeWidget->update();
}

