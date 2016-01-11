#include <stdio.h>
#include <unistd.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"

//void MainWindow::inhomeTest(int a)
void Tester::inHomeTest(void)
{
	ui->treeWidget->topLevelItem(0)->setText(1, "In Home testing");
	ui->treeWidget->topLevelItem(0)->setText(2, "In Home testing");

	do{
		printf("It's the %d times\n", test);
		test++;
		// update the ui
		sleep(1);

		ui->treeWidget->topLevelItem(0)->child(0)->setText(2, QString::number(test));
		ui->treeWidget->topLevelItem(0)->child(1)->setText(2, QString::number(test-1));
		QCoreApplication::processEvents();
	}while(1);
}
