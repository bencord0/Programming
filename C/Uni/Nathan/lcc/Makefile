# Wedit Makefile for project steve
SRCDIR=d:\documents\computing\programming\c\uni\nathan
CFLAGS=-I"C:\lcc\include"  -g2 
CC=$(LCCROOT)\bin\lcc.exe
LINKER=$(LCCROOT)\bin\lcclnk.exe
OBJS=\
	steve.obj

LIBS=
EXE=steve.exe

$(EXE):	$(OBJS) Makefile
	$(LINKER)  -subsystem console -o $(SRCDIR)\lcc\steve.exe $(OBJS) $(LIBS)

# Build steve.c
STEVE_C=\

steve.obj: $(STEVE_C) $(SRCDIR)\steve.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\steve.c

link:
	$(LINKER)  -subsystem console -o $(SRCDIR)\lcc\steve.exe $(OBJS) $(LIBS)

clean:
	del $(OBJS) steve.exe
