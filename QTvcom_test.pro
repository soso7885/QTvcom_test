######################################################################
# Automatically generated by qmake (3.0) ?? 1? 11 18:17:00 2016
######################################################################

TEMPLATE = app
TARGET = QVcomTest
INCLUDEPATH += .

QT += core
QT += widgets
QT += gui
QT += serialport

#######################
#
# QT_NO_DEBUG_OUTPUT
# with no qDebug output
#
########################
DEFINES += QT_NO_DEBUG_OUTPUT

# Input
HEADERS += mainwindow.h
FORMS += mainwindow.ui
SOURCES +=  main.cpp            \
			mainwindow_init.cpp	\
            mainwindow.cpp      \
            simpletest.cpp      \
			button.cpp			\
            result_disp.cpp     \
            port_behavior.cpp   \
			tester.cpp			\
			open_close_test.cpp		\
			pack_by_char_test.cpp	\
			mctrl_test.cpp		\
