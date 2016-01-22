#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	/* COM1 button connect*/
	connect(ui->startButton1, SIGNAL(clicked()), 
		this, SLOT(startButton1_clicked()));
	connect(ui->closeButton1, SIGNAL(clicked()), 
		this, SLOT(closeButton1_clicked()));
	/* COM2 button connect*/
	connect(ui->startButton2, SIGNAL(clicked()),
		this, SLOT(startButton2_clicked()));
	connect(ui->closeButton2, SIGNAL(clicked()),
		this, SLOT(closeButton2_clicked()));
	/* COM3 button connect */
	connect(ui->startButton3, SIGNAL(clicked()),
		this, SLOT(startButton3_clicked()));
	connect(ui->closeButton3, SIGNAL(clicked()),
		this, SLOT(closeButton3_clicked()));
	/* COM4 button connect*/
	connect(ui->startButton4, SIGNAL(clicked()),
		this, SLOT(startButton4_clicked()));
	connect(ui->closeButton4, SIGNAL(clicked()),
		this, SLOT(closeButton4_clicked()));
	/* COM5 button connect*/
	connect(ui->startButton5, SIGNAL(clicked()),
		this, SLOT(startButton5_clicked()));
	connect(ui->closeButton5, SIGNAL(clicked()),
		this, SLOT(closeButton5_clicked()));
	/* COM6 button connect*/
	connect(ui->startButton6, SIGNAL(clicked()),
		this, SLOT(startButton6_clicked()));
	connect(ui->closeButton6, SIGNAL(clicked()),
		this, SLOT(closeButton6_clicked()));
	/* COM7 button connect*/
	connect(ui->startButton7, SIGNAL(clicked()),
		this, SLOT(startButton7_clicked()));
	connect(ui->closeButton7, SIGNAL(clicked()),
		this, SLOT(closeButton7_clicked()));
	/* COM8 button connect*/
	connect(ui->startButton8, SIGNAL(clicked()),
		this, SLOT(startButton8_clicked()));
	connect(ui->closeButton8, SIGNAL(clicked()),
		this, SLOT(closeButton8_clicked()));
	/* COM9 button connect*/
	connect(ui->startButton9, SIGNAL(clicked()),
		this, SLOT(startButton9_clicked()));
	connect(ui->closeButton9, SIGNAL(clicked()),
		this, SLOT(closeButton9_clicked()));
	/* COM10 button connect*/
	connect(ui->startButton10, SIGNAL(clicked()),
		this, SLOT(startButton10_clicked()));
	connect(ui->closeButton10, SIGNAL(clicked()),
		this, SLOT(closeButton10_clicked()));
	/* COM11 button connect*/
	connect(ui->startButton11, SIGNAL(clicked()),
		this, SLOT(startButton11_clicked()));
	connect(ui->closeButton11, SIGNAL(clicked()),
		this, SLOT(closeButton11_clicked()));
	/* COM12 button connect*/
	connect(ui->startButton12, SIGNAL(clicked()),
		this, SLOT(startButton12_clicked()));
	connect(ui->closeButton12, SIGNAL(clicked()),
		this, SLOT(closeButton12_clicked()));
	/* COM13 button connect*/
	connect(ui->startButton13, SIGNAL(clicked()),
		this, SLOT(startButton13_clicked()));
	connect(ui->closeButton13, SIGNAL(clicked()),
		this, SLOT(closeButton13_clicked()));
	/* COM14 button connect*/
	connect(ui->startButton14, SIGNAL(clicked()),
		this, SLOT(startButton14_clicked()));
	connect(ui->closeButton14, SIGNAL(clicked()),
		this, SLOT(closeButton14_clicked()));
	/* COM15 button connect*/
	connect(ui->startButton15, SIGNAL(clicked()),
		this, SLOT(startButton15_clicked()));
	connect(ui->closeButton15, SIGNAL(clicked()),
		this, SLOT(closeButton15_clicked()));
	/* COM16 button connect*/
	connect(ui->startButton16, SIGNAL(clicked()),
		this, SLOT(startButton16_clicked()));
	connect(ui->closeButton16, SIGNAL(clicked()),
		this, SLOT(closeButton16_clicked()));
	/*
	 * To advoid Com port name empty
	 * XXX: Maybe can combine with buttonSwitch
	*/
	connect(ui->comName1, SIGNAL(textChanged(const QString)), 
				this, SLOT(startEnable1()));	
	connect(ui->comName2, SIGNAL(textChanged(const QString)), 
				this, SLOT(startEnable2()));	
	connect(ui->comName3, SIGNAL(textChanged(const QString)), 
				this, SLOT(startEnable3()));	
	connect(ui->comName4, SIGNAL(textChanged(const QString)), 
				this, SLOT(startEnable4()));	
	connect(ui->comName5, SIGNAL(textChanged(const QString)), 
				this, SLOT(startEnable5()));	
	connect(ui->comName6, SIGNAL(textChanged(const QString)), 
				this, SLOT(startEnable6()));	
	connect(ui->comName7, SIGNAL(textChanged(const QString)), 
				this, SLOT(startEnable7()));	
	connect(ui->comName8, SIGNAL(textChanged(const QString)), 
				this, SLOT(startEnable8()));	
	connect(ui->comName9, SIGNAL(textChanged(const QString)), 
				this, SLOT(startEnable9()));	
	connect(ui->comName10, SIGNAL(textChanged(const QString)), 
				this, SLOT(startEnable10()));	
	connect(ui->comName11, SIGNAL(textChanged(const QString)), 
				this, SLOT(startEnable11()));	
	connect(ui->comName12, SIGNAL(textChanged(const QString)), 
				this, SLOT(startEnable12()));	
	connect(ui->comName13, SIGNAL(textChanged(const QString)), 
				this, SLOT(startEnable13()));	
	connect(ui->comName14, SIGNAL(textChanged(const QString)), 
				this, SLOT(startEnable14()));	
	connect(ui->comName15, SIGNAL(textChanged(const QString)), 
				this, SLOT(startEnable15()));	
	connect(ui->comName16, SIGNAL(textChanged(const QString)), 
				this, SLOT(startEnable16()));	
	/*
	 * To wakeup the EndChar editer
	*/
	connect(ui->test1, SIGNAL(currentTextChanged(const QString)),
				this, SLOT(checkEnableEC1()));
	connect(ui->test2, SIGNAL(currentTextChanged(const QString)),
				this, SLOT(checkEnableEC2()));
	connect(ui->test3, SIGNAL(currentTextChanged(const QString)),
				this, SLOT(checkEnableEC3()));
	connect(ui->test4, SIGNAL(currentTextChanged(const QString)),
				this, SLOT(checkEnableEC4()));
	connect(ui->test5, SIGNAL(currentTextChanged(const QString)),
				this, SLOT(checkEnableEC5()));
	connect(ui->test6, SIGNAL(currentTextChanged(const QString)),
				this, SLOT(checkEnableEC6()));
	connect(ui->test7, SIGNAL(currentTextChanged(const QString)),
				this, SLOT(checkEnableEC7()));
	connect(ui->test8, SIGNAL(currentTextChanged(const QString)),
				this, SLOT(checkEnableEC8()));
	connect(ui->test9, SIGNAL(currentTextChanged(const QString)),
				this, SLOT(checkEnableEC9()));
	connect(ui->test10, SIGNAL(currentTextChanged(const QString)),
				this, SLOT(checkEnableEC10()));
	connect(ui->test11, SIGNAL(currentTextChanged(const QString)),
				this, SLOT(checkEnableEC11()));
	connect(ui->test12, SIGNAL(currentTextChanged(const QString)),
				this, SLOT(checkEnableEC12()));
	connect(ui->test13, SIGNAL(currentTextChanged(const QString)),
				this, SLOT(checkEnableEC13()));
	connect(ui->test14, SIGNAL(currentTextChanged(const QString)),
				this, SLOT(checkEnableEC14()));
	connect(ui->test15, SIGNAL(currentTextChanged(const QString)),
				this, SLOT(checkEnableEC15()));
	connect(ui->test16, SIGNAL(currentTextChanged(const QString)),
				this, SLOT(checkEnableEC16()));

	startButton[0] = ui->startButton1;
	startButton[1] = ui->startButton2;
	startButton[2] = ui->startButton3;
	startButton[3] = ui->startButton4;
	startButton[4] = ui->startButton5;
	startButton[5] = ui->startButton6;
	startButton[6] = ui->startButton7;
	startButton[7] = ui->startButton8;
	startButton[8] = ui->startButton9;
	startButton[9] = ui->startButton10;
	startButton[10] = ui->startButton11;
	startButton[11] = ui->startButton12;
	startButton[12] = ui->startButton13;
	startButton[13] = ui->startButton14;
	startButton[14] = ui->startButton15;
	startButton[15] = ui->startButton16;

	testMod[0] = ui->test1;
	testMod[1] = ui->test2;
	testMod[2] = ui->test3;
	testMod[3] = ui->test4;
	testMod[4] = ui->test5;
	testMod[5] = ui->test6;
	testMod[6] = ui->test7;
	testMod[7] = ui->test8;
	testMod[8] = ui->test9;
	testMod[9] = ui->test10;
	testMod[10] = ui->test11;
	testMod[11] = ui->test12;
	testMod[12] = ui->test13;
	testMod[13] = ui->test14;
	testMod[14] = ui->test15;
	testMod[15] = ui->test16;

	ascIIButton[0] = ui->ascIIButton1;
	ascIIButton[1] = ui->ascIIButton2;
	ascIIButton[2] = ui->ascIIButton3;
	ascIIButton[3] = ui->ascIIButton4;
	ascIIButton[4] = ui->ascIIButton5;
	ascIIButton[5] = ui->ascIIButton6;
	ascIIButton[6] = ui->ascIIButton7;
	ascIIButton[7] = ui->ascIIButton8;
	ascIIButton[8] = ui->ascIIButton9;
	ascIIButton[9] = ui->ascIIButton10;
	ascIIButton[10] = ui->ascIIButton11;
	ascIIButton[11] = ui->ascIIButton12;
	ascIIButton[12] = ui->ascIIButton13;
	ascIIButton[13] = ui->ascIIButton14;
	ascIIButton[14] = ui->ascIIButton15;
	ascIIButton[15] = ui->ascIIButton16;

	hexButton[0] = ui->hexButton1;
	hexButton[1] = ui->hexButton2;
	hexButton[2] = ui->hexButton3;
	hexButton[3] = ui->hexButton4;
	hexButton[4] = ui->hexButton5;
	hexButton[5] = ui->hexButton6;
	hexButton[6] = ui->hexButton7;
	hexButton[7] = ui->hexButton8;
	hexButton[8] = ui->hexButton9;
	hexButton[9] = ui->hexButton10;
	hexButton[10] = ui->hexButton11;
	hexButton[11] = ui->hexButton12;
	hexButton[12] = ui->hexButton13;
	hexButton[13] = ui->hexButton14;
	hexButton[14] = ui->hexButton15;
	hexButton[15] = ui->hexButton16;

	ecLineEdit[0] = ui->ecLineEdit1;
	ecLineEdit[1] = ui->ecLineEdit2;
	ecLineEdit[2] = ui->ecLineEdit3;
	ecLineEdit[3] = ui->ecLineEdit4;
	ecLineEdit[4] = ui->ecLineEdit5;
	ecLineEdit[5] = ui->ecLineEdit6;
	ecLineEdit[6] = ui->ecLineEdit7;
	ecLineEdit[7] = ui->ecLineEdit8;
	ecLineEdit[8] = ui->ecLineEdit9;
	ecLineEdit[9] = ui->ecLineEdit10;
	ecLineEdit[10] = ui->ecLineEdit11;
	ecLineEdit[11] = ui->ecLineEdit12;
	ecLineEdit[12] = ui->ecLineEdit13;
	ecLineEdit[13] = ui->ecLineEdit14;
	ecLineEdit[14] = ui->ecLineEdit15;
	ecLineEdit[15] = ui->ecLineEdit16;
}

MainWindow::~MainWindow()
{
	delete ui;
}

