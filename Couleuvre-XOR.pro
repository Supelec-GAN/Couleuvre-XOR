TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES +=  sources/main.cpp \
    sources/neuronlayer.cpp \
    sources/neuralnetwork.cpp \
    sources/functions.cpp \
    headers/neuralnetwork.inl

HEADERS += \
    headers/neuronlayer.hpp \
    headers/neuralnetwork.hpp \
    headers/functions.hpp
