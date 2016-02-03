CC    = gcc
FLAGS = -Wall -O3
TARGET = fltr
PREFIX = $(DESTDIR)/usr/local
BINDIR = $(PREFIX)/bin

all: fltr.c
	$(CC) $(FLAGS) fltr.c -o $(TARGET)

install: all
	install -D $(TARGET) $(BINDIR)/$(TARGET)

clean:
	$(RM) fltr
