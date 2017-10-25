TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES +=  sources/main.cpp \
    sources/neuronlayer.cpp \
    sources/neuralnetwork.cpp \
    sources/functions.cpp \
    headers/neuralnetwork.inl \
    sources/teacher.cpp \
    sources/datacollector.cpp \
    sources/dataset.cpp \
    sources/utility.cpp

HEADERS += \
    headers/neuronlayer.hpp \
    headers/neuralnetwork.hpp \
    headers/functions.hpp \
    headers/teacher.hpp \
    headers/CSVFile.h \
    headers/datacollector.hpp \
    headers/dataset.hpp \
    headers/utility.hpp

INCLUDEPATH += D:\Users\Kvykv\Projet\C++
