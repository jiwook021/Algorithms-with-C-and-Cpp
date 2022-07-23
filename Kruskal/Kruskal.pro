TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ALGraphKruskal.c \
        ArrayBaseStack.c \
        DLinkedList.c \
        KruskalMain.c \
        PriorityQueue.c \
        UsefulHeap.c

HEADERS += \
    ALEdge.h \
    ALGraphKruskal.h \
    ArrayBaseStack.h \
    DLinkedList.h \
    PriorityQueue.h \
    UsefulHeap.h
