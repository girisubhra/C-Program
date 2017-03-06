############################################################################
#TCP Server  Makefile						
#TO BUILD: make all
#TO CLEAN: make clean
#Version : 1.0
#AUTHOR  : SUBHRA PRAKASH GIRI
##############################################################################

CURDIR = $(PWD)
CC		= gcc
DEFS 		=  
CFLAGS 		= -g -c -o 
OBJDIR 		= $(CURDIR)/obj
SRCDIR 		= $(CURDIR)/src
HDRDIR 		= $(CURDIR)/hdr
TARGET 		= Server
INCLUDE     = -I$(HDRDIR) 
####################################################################
SOURCES=$(SRCDIR)/server.c \
	$(SRCDIR)/wrapper.c 

OBJS=$(SOURCES:.c=.o)

.c.o: $(SOURCES) 
	$(CC) -Wall $(CFLAGS) $@ $(INCLUDE) $< $(DEFS)

TARGET: $(OBJS)
	$(CC) -Wall $(INCLUDE) -o $(TARGET) $(SRCDIR)/*.o
	mv $(SRCDIR)/*.o $(OBJDIR)

clean:
	rm -f $(TARGET)
	rm -f $(OBJDIR)/*.o
	rm -f $(SRCDIR)/*.o
