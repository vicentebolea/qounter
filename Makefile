UIC ?= uic-qt5
MOC ?= moc-qt5
LRELEASE ?= lrelease-qt5

all: qounter translations/lang_es_ES.qm
test: qounter_test

ui_qounter.h: qounter.ui
	$(UIC) -tr QObject::tr qounter.ui > ui_qounter.h

qounter-moc.h: qounter.h
	$(MOC) qounter.h > qounter-moc.h

qounter_test-moc.h: qounter-moc.h qounter_test.h
	$(MOC) qounter_test.h > qounter_test-moc.h

qounter: main.cxx qounter.h ui_qounter.h qounter-moc.h
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

qounter_test: qounter_test-moc.h qounter_test.cxx
	$(CXX) -std=c++14 -o qounter_test qounter_test.cxx -g -fPIC `pkg-config --cflags Qt5Core Qt5Test Qt5Gui` `pkg-config --libs Qt5Core Qt5Widgets Qt5Gui Qt5Test`

clean:
	rm -f qounter_test-moc.h qounter-moc.h ui_qounter.h qounter qounter_test translations/lang_es_ES.qm

