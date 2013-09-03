export CC = g++
INCPATH = -I"$(CURDIR)/Ekiis" -I"$(CURDIR)/Ekiis/Event" -I"$(CURDIR)"
LIBS = -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window -lGL -lGLU -lGLEW -lBox2D #-L/usr/local/lib
DEFINE =
export FLAGS = -g -std=c++0x -fexpensive-optimizations -o3  $(INCPATH) $(LIBS) $(DEFINES)
export TOP := $(CURDIR)
#$(abspath $(dir $(lastword $(MAKEFILE_LIST))))
export OBJ_DIR = $(TOP)/obj

SRC = $(wildcard *.c*)
OBJ = $(SRC:.cpp=.o) $(SRC:*.cpp=.o)

SUBDIRS = Ekiis obj

export EXEC = ekiis

CLEANDIRS = $(SUBDIRS:%=clean-%)


.PHONY: subdirs $(SUBDIRS)
.PHONY: subdirs $(CLEANDIRS)

all: $(OBJ) subdirs

subdirs: $(SUBDIRS)
     
$(SUBDIRS):
	$(MAKE) -C $@


.cpp.o:
	$(CC) $(FLAGS) -o $@ -c $^;
	@mv $@ obj

.c.o :
	$(CC) $(FLAGS) -o $@ -c $^;
	@mv $@ obj


clean: $(CLEANDIRS)

$(CLEANDIRS): 
	$(MAKE) -C $(@:clean-%=%) clean
	@rm -f *.o
	@rm -f $(EXEC)
