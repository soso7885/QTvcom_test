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
	int com;	// which ComPort is running
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
	explicit Tester(Ui::MainWindow *ui, int com);
	~Tester(void);
	
	/* Main thread will use it to close child thread */
	bool isRunning;

	void simpleTest(void);

public slots:
	void startTest(void);

signals:
	void finished(void);
	void error(QString err);

	void openUpdate(int com);
	void closeUpdate(int com);
	void OKUpdate(int com);
	void errUpdate(int com, QString errMsg);
	void resUpdate(struct testResult *tRes, int com);
	
	void buttonUpdate(int com, bool able);
};


class MainWindow : public QMainWindow
{
	Q_OBJECT

private:
	Ui::MainWindow *ui;
	Tester *testerVect[16];

	void initTester(int com);
	void closeTester(int com);

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow(void);

	void openPortStatus(int com);
	void closePortStatus(int com);
	void portOKStatus(int com);
	void portErrStatus(int com, QString errMsg);
	void updateResult(struct testResult *tRes, int com);

private slots:
	void startButton1_clicked(void);
	void closeButton1_clicked(void);
	
	void startButton2_clicked(void);
	void closeButton2_clicked(void);

public slots:
	void openPortUpdate(int com);
	void closePortUpdate(int com);
	void OKPortUpdate(int com);
	void errPortUpdate(int com, QString errMsg);
	void resPortUpdate(struct testResult *tRes, int com);

	void buttonSwitch(int com, bool able);

};

#endif
