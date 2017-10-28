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
    sources/application.cpp \
    sources/dataset.cpp \
    sources/datacollector.cpp \
    sources/utility.cpp \
    sources/errorcollector.cpp \
    sources/statscollector.cpp

HEADERS += \
    headers/neuronlayer.hpp \
    headers/neuralnetwork.hpp \
    headers/functions.hpp \
    headers/teacher.hpp \
    headers/CSVFile.h \
    headers/application.hpp \
    headers/dataset.hpp \
    headers/utility.hpp \
    headers/datacollector.hpp \
    headers/errorcollector.hpp \
    headers/statscollector.hpp
