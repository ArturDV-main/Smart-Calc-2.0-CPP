QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

macx:ICON = $${PWD}/smartcalc.icns

SOURCES += \
    ../main.cc \
    ../s21_calc_controller.cc \
    ../s21_calc_model.cc \
    ../s21_calc_valid_model.cc \
    qcustomplot.cpp \
    s21_credit_view_qt.cc \
    s21_view_qt.cc

HEADERS += \
    ../s21_calc_controller.h \
    ../s21_calc_model.h \
    ../s21_calc_valid_model.h \
    qcustomplot.h \
    s21_credit_view_qt.h \
    s21_view_qt.h

FORMS += \
    s21_credit_view_qt.ui \
    s21_view_qt.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    palette.xml \
    palette2.xml
