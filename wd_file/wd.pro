TEMPLATE	= app
LANGUAGE	= C++

CONFIG	+= qt warn_on release

LIBS	+= -L./lib -lxml2 /users/ems/open2000e/lib/libodb_apiall_lib.so

INCLUDEPATH	+= ./include/libxml2 /usr/local/corba/include/

HEADERS	+= Data.h \
	ThreadRun.h

SOURCES	+= main.cpp \
	Data.cpp \
	ThreadRun.cpp

FORMS	= Mainform.ui

IMAGES	= Data.bmp

unix {
  UI_DIR = .ui
  MOC_DIR = .moc
  OBJECTS_DIR = .obj
}




