TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES +=  sources/main.cpp \
    sources/neuronlayer.cpp \
    sources/neuralnetwork.cpp

HEADERS += \
    headers/neuronlayer.hpp \
    headers/neuralnetwork.hpp
