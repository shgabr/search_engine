GCC=/usr/bin/g++
GCC_FLAGS= -c -std=c++11
CODE_HOME=.
BIN=$(CODE_HOME)
OBJECTS=$(CODE_HOME)/obj
SOURCES=$(CODE_HOME)/sources
HEADERS=$(CODE_HOME)/headers
INCLUDES= -I $(CODE_HOME)/headers

$(BIN)/webpage: $(OBJECTS)/URL.o $(OBJECTS)/WebPage.o $(OBJECTS)/main.o
	$(GCC) $(OBJECTS)/URL.o $(OBJECTS)/WebPage.o $(OBJECTS)/main.o -o $(BIN)/webpage

$(OBJECTS)/main.o: $(SOURCES)/main.cpp
	$(GCC) $(GCC_FLAGS)  $(INCLUDES) $(SOURCES)/main.cpp -o $(OBJECTS)/main.o

$(OBJECTS)/WebPage.o: $(SOURCES)/WebPage.cpp
	$(GCC) $(GCC_FLAGS)  $(INCLUDES) $(SOURCES)/WebPage.cpp -o $(OBJECTS)/WebPage.o

$(OBJECTS)/URL.o: $(SOURCES)/URL.cpp
	$(GCC) $(GCC_FLAGS)  $(INCLUDES) $(SOURCES)/URL.cpp -o $(OBJECTS)/URL.o

fullwebpage: ./Full_webpage.cpp
	$(GCC) $(GCC_FLAGS) ./Full_webpage.cpp -o $(BIN)/fullwebpage



clean:
	rm -rf ./bin/* ./obj/*
