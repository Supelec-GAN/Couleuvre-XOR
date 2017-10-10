TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES +=  sources/main.cpp \
    sources/neuronlayer.cpp \
    sources/neuronalnetwork.cpp

HEADERS += \
    headers/neuronlayer.hpp \
    headers/neuronalnetwork.hpp
