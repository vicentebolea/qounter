all: qounter

ui: qounter.ui
	uic-qt5 qounter.ui > ui_qounter.h

moc_mainWidget.h: mainWidget.h
	moc-qt5 mainWidget.h > moc_mainWidget.h

qounter: main.cxx moc_mainWidget.h ui
	g++ main.cxx -fPIC -I/usr/include/qt5/ -lQt5Core -lQt5Widgets -lQt5Gui
