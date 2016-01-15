#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QtCore>
#include <QMessageBox>
#include <QApplication>
#include <QTextStream>
#include <QString>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QThread>
#include <QVector>
#include <stdio.h>
#include <QDebug>

#define COM1	1
#define COM2	2

#define TXDATALEN		1024
#define WRITEWAITTIME	1000
#define READWAITTIME	1000


namespace Ui{
	class MainWindow;
}

struct port_info{
	QString name;
	int BaudRate;
};

struct testResult{
	qint64 txlen;
	qint64 rxlen;
	int round;
	int err;
};

/*------------------------------------------------*/
class Tester : public QObject
{
	Q_OBJECT

private:
	int num;	// which ComPort is running
	Ui::MainWindow *ui;
	struct port_info pInfo;
	QSerialPort serial;

// TODO for inhome_test
//	int test;
	void inHomeTest(void);

	int openSerialPort(void);
	void closeSerialPort(void);
	int takePortInfo(void);
	void freeResrc(void);

public:
	explicit Tester(Ui::MainWindow *ui, int num);
	~Tester(void);
	
	/* Main thread will use it to close child thread */
	bool isRunning;

	void simpleTest(void);

public slots:
	void startTest(void);

signals:
	void finished(void);
	void error(QString err);

	void openUpdate(int num);
	void closeUpdate(int num);
	void OKUpdate(int num);
	void errUpdate(int num, QString errMsg);
	void resUpdate(struct testResult *tRes, int num);
	
	void buttonUpdate(int num, bool able);
};


class MainWindow : public QMainWindow
{
	Q_OBJECT

private:
	Ui::MainWindow *ui;
	Tester *testerVect[16];

	void initTester(int num);
	void closeTester(int num);

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow(void);

	void openPortStatus(int num);
	void closePortStatus(int num);
	void portOKStatus(int num);
	void portErrStatus(int num, QString errMsg);
	void updateResult(struct testResult *tRes, int num);

private slots:
	void startButton1_clicked(void);
	void closeButton1_clicked(void);
	
	void startButton2_clicked(void);
	void closeButton2_clicked(void);

public slots:
	void openPortUpdate(int num);
	void closePortUpdate(int num);
	void OKPortUpdate(int num);
	void errPortUpdate(int num, QString errMsg);
	void resPortUpdate(struct testResult *tRes, int num);

	void buttonSwitch(int num, bool able);

};

#endif
