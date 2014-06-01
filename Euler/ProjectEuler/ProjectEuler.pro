CONFIG -= debug_and_release debug
CONFIG += release

# Add more folders to ship with the application, here
folder_01.source = qml/ProjectEuler
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp funcs.h \
    ../Problems/1/pje1.c \
    ../Problems/2/pje2.c \
    ../Problems/3/pje3.c \
    ../Problems/4/pje4.c \
    ../Problems/5/pje5.c \
    ../Problems/6/pje6.c \
    ../Problems/7/pje7.c \
    ../Problems/8/pje8.c \
    ../Problems/9/pje9.c \
    ../Problems/10/pje10.cpp \
    ../Problems/11/pje11.cpp \
    ../Problems/12/pje12.cpp

# Please do not modify the following two lines. Required for deployment.
include(qmlapplicationviewer/qmlapplicationviewer.pri)
qtcAddDeployment()
