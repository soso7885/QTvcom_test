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
//#include <QDebug>
#include <QBrush>

#define COM1	1
#define COM2	2
#define COM3	3
#define COM4	4
#define COM5	5
#define COM6	6
#define COM7	7
#define COM8	8
#define COM9	9
#define COM10	10
#define COM11	11
#define COM12	12
#define COM13	13
#define COM14	14
#define COM15	15
#define COM16	16

#define SIMPLE_TEST	17
#define RECONN_TEST	18

#define TXDATALEN		1024
#define WRITEWAITTIME	1000
#define READWAITTIME	1000

#define err1(head)			\
	do{	QString *err = new QString;			\
		*err = head;						\
		err->append(serial.errorString());	\
		qDebug() << *err;					\
		emit errUpdate(com, *err);			\
		delete err;	}while(0);

#define err2(head, round)	\
	do{	QString *err = new QString;				\
		*err = head;							\
		err->append(QString::number(round));\
		qDebug() << *err;					\
		emit errUpdate(com, *err);			\
		delete err; }while(0);

#define ERRMSG_OVRLD(_1, _2, func, ...)		func

/*
 * WARNING !!
 * <Request>
 * 	Only the member of Tester can use it
 * <HowToUse>
 *	argument count == 1, means read/write failed,
 *	argument count == 2, means data wrong
*/
#define SERIAL_CREATE_ERRMSG(args...)	ERRMSG_OVRLD(args, err2, err1)(args)

namespace Ui{
	class MainWindow;
}

struct port_info{
	QString name;
	int BaudRate;
	int testMode;
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
	Ui::MainWindow *ui;
	struct port_info pInfo;
	QSerialPort serial;
	int com;	// To decide which ComPort is running

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
	void reconnTest(void);

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
	void openErrUpdate(QString errMsg);
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

	void startButton3_clicked(void);
	void closeButton3_clicked(void);
	
	void startButton4_clicked(void);
	void closeButton4_clicked(void);

	void startButton5_clicked(void);
	void closeButton5_clicked(void);

	void startButton6_clicked(void);
	void closeButton6_clicked(void);

	void startButton7_clicked(void);
	void closeButton7_clicked(void);

	void startButton8_clicked(void);
	void closeButton8_clicked(void);

	void startButton9_clicked(void);
	void closeButton9_clicked(void);

	void startButton10_clicked(void);
	void closeButton10_clicked(void);

	void startButton11_clicked(void);
	void closeButton11_clicked(void);

	void startButton12_clicked(void);
	void closeButton12_clicked(void);

	void startButton13_clicked(void);
	void closeButton13_clicked(void);

	void startButton14_clicked(void);
	void closeButton14_clicked(void);

	void startButton15_clicked(void);
	void closeButton15_clicked(void);

	void startButton16_clicked(void);
	void closeButton16_clicked(void);
	/* XXX: combine with buttonSwitch */
	void startEnable1(void);
	void startEnable2(void);
	void startEnable3(void);
	void startEnable4(void);
	void startEnable5(void);
	void startEnable6(void);
	void startEnable7(void);
	void startEnable8(void);
	void startEnable9(void);
	void startEnable10(void);
	void startEnable11(void);
	void startEnable12(void);
	void startEnable13(void);
	void startEnable14(void);
	void startEnable15(void);
	void startEnable16(void);

public slots:
	void openPortUpdate(int com);
	void closePortUpdate(int com);
	void OKPortUpdate(int com);
	void errPortUpdate(int com, QString errMsg);
	void resPortUpdate(struct testResult *tRes, int com);

	void buttonSwitch(int com, bool able);

	void openPortErr(QString errMsg);
};

#endif
