UIC ?= uic-qt5
MOC ?= moc-qt5
LRELEASE ?= lrelease-qt5

all: qounter translations/lang_es_ES.qm

ui_qounter.h: qounter.ui
	$(UIC) -tr QObject::tr qounter.ui > ui_qounter.h

moc_mainWidget.h: mainWidget.h
	$(MOC) mainWidget.h > moc_mainWidget.h

qounter: main.cxx moc_mainWidget.h ui_qounter.h
	$(CXX) -std=c++14 -o qounter main.cxx -g -fPIC `pkg-config --cflags Qt5Core` `pkg-config --libs Qt5Core Qt5Widgets Qt5Gui`

install:
	mkdir -p /usr/local/share/qounter
	cp -v qounter /usr/local/bin/
	mkdir -p /usr/local/share/applications
	cp -v qounter.desktop /usr/local/share/applications/
	mkdir -p /usr/local/share/icons/hicolor/96x97/apps
	cp -v qountericon.png /usr/local/share/icons/hicolor/96x96/apps/
	cp -rv translations   /usr/local/share/qounter/

translations/lang_es_ES.qm:
	$(LRELEASE) translations/lang_es_ES.ts

clean:
	rm -f moc_mainWidget.h ui_qounter.h qounter translations/lang_es_ES.qm


