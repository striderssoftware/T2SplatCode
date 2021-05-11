APPNAME = splay

OFILES = Test.o

ALLDEP = Makefile

CC = g++
CCFLAGS = -g -Wall -pedantic -std=c++17
CXXFLAGS =
INCL += $(shell sdl2-config --cflags)
LDFLAGS =
LIBS = -lSDL2

# A makefile comment                                           

$(APPNAME): $(ALLDEP) $(OFILES)
	$(CC) $(CCFLAGS) $(CXXFLAGS) $(OFILES) -o $(APPNAME)  $(LDFLAGS) $(LIBS)

%.o: %.cpp
	$(CC) $(CCFLAGS) $(CXXFLAGS) $(INCL) -c -o $@ $<

clean:
	rm -f *.o *~  $(APPNAME)


