TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle

QT += widgets
QT += core

SOURCES +=  sources/main.cpp \
    sources/neuronlayer.cpp \
    sources/neuralnetwork.cpp \
    sources/functions.cpp \
    headers/neuralnetwork.inl \
    sources/teacher.cpp \
    sources/gui.cpp \
    sources/gui_secondaire.cpp

HEADERS += \
    headers/neuronlayer.hpp \
    headers/neuralnetwork.hpp \
    headers/functions.hpp \
    headers/teacher.hpp \
    headers/CSVFile.h \
    headers/gui.hpp \
    headers/gui_secondaire.h
