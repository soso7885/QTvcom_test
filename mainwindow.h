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
};

void closeSerialPort(void);


//void simpleTest(QSerialPort *serial);
//void inHomeTest(int test);

class MainWindow : public QMainWindow
{
	Q_OBJECT

private:
	Ui::MainWindow *ui;

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow(void);

	void openPortStatus(void);
	void closePortStatus(void);
	void portOKStatus(void);
	void portErrStatus(void);
	void updateResult(struct testResult *tRes);

private slots:
	void startButton_clicked(void);
	void closeButton_clicked(void);
/*	
	void openPortStatus(void);
	void closePortStatus(void);
	void portOKStatus(void);
	void portErrStatus(void);
	void updateResult(struct testResult *tRes);
*/
};

class Tester : public QObject
{
	Q_OBJECT

private:
	Ui::MainWindow *ui;
	struct port_info pInfo;
	QSerialPort serial;
	
// FIXME for inhome_test
	int test;
	
	void inHomeTest(void);
	void simpleTest(void);
	int openSerialPort(void);
	void closeSerialPort(void);

public:
	explicit Tester(Ui::MainWindow *ui);
	~Tester(void);

public slots:
	void startTest(void);

signals:
	void finished(void);
	void error(QString err);

};

#endif
