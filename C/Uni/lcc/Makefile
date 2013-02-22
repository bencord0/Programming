# Wedit Makefile for project jeff
SRCDIR=d:\documents\computing\programming\c\uni
CFLAGS=-I"C:\lcc\include"  -g2 
CC=$(LCCROOT)\bin\lcc.exe
LINKER=$(LCCROOT)\bin\lcclnk.exe
OBJS=\
	jeff.obj

LIBS=
EXE=jeff.exe

$(EXE):	$(OBJS) Makefile
	$(LINKER)  -subsystem console -o $(SRCDIR)\lcc\jeff.exe $(OBJS) $(LIBS)

# Build jeff.c
JEFF_C=\

jeff.obj: $(JEFF_C) $(SRCDIR)\jeff.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\jeff.c

link:
	$(LINKER)  -subsystem console -o $(SRCDIR)\lcc\jeff.exe $(OBJS) $(LIBS)

clean:
	del $(OBJS) jeff.exe
