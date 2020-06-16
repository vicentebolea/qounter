UIC ?= uic-qt5
MOC ?= moc-qt5

all: qounter

ui: qounter.ui
	$(UIC) qounter.ui > ui_qounter.h

moc_mainWidget.h: mainWidget.h
	$(MOC) mainWidget.h > moc_mainWidget.h

qounter: main.cxx moc_mainWidget.h ui
	$(CXX) -o qounter main.cxx -g -fPIC `pkg-config --cflags Qt5Core` `pkg-config --libs Qt5Core Qt5Widgets Qt5Gui`

install:
	cp -v qounter /usr/local/bin/
	cp -v qounter.desktop /usr/local/share/applications/
	cp -v qountericon.png /usr/local/share/icons/hicolor/96x96/apps/
