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
	ui->treeWidget->topLevelItem(com-1)->setForeground(1, QBrush(QColor(0, 255, 0)));
}

void MainWindow::portErrStatus(int com, QString errMsg)
{
	ui->treeWidget->topLevelItem(com-1)->setText(1, "Error");
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

