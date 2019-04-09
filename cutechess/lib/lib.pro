TEMPLATE = lib
TARGET = cutechess
QT = core
DESTDIR = $$PWD

!win32-msvc* {
	QMAKE_CXXFLAGS += -Wextra -Wshadow
}

include(libexport.pri)
include(src/src.pri)
include(components/json/src/json.pri)
include(3rdparty/fathom/src/tb.pri)
include(res/res.pri)

OBJECTS_DIR = .obj
MOC_DIR = .moc
RCC_DIR = .rcc

LIBS += -L$$system(python3 -c \'from distutils import sysconfig; print(sysconfig.get_config_var(\"LIBDIR\"))\')
LIBS += $$system(python3 -c \'from distutils import sysconfig; print(sysconfig.get_config_var(\"BLDLIBRARY\"))\')
INCLUDEPATH += $$system(python3 -c \'from distutils import sysconfig; print(sysconfig.get_config_var(\"INCLUDEPY\"))\')
