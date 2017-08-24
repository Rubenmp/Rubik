CXXFLAGS= -Wall -Wextra -pedantic -std=c++11 -g
LIBS= -L./lib -lrubik

INCLUDE= ./include
BIN=./bin
DIR_LIBS=./lib
SRC=./src
OBJ=./obj

all: Rubik searchBugs

Rubik: $(OBJ)/Rubik.o $(DIR_LIBS)/librubik.a
	g++ -o $(BIN)/Rubik $< $(LIBS)

searchBugs: $(OBJ)/searchBugs.o $(DIR_LIBS)/librubik.a
	g++ -o $(BIN)/searchBugs $< $(LIBS)



$(OBJ)/Rubik.o: $(SRC)/Rubik.cpp
	g++ -c -I$(INCLUDE) $(CXXFLAGS) -o $@ $<

$(OBJ)/searchBugs.o: $(SRC)/searchBugs.cpp
	g++ -c -I$(INCLUDE) $(CXXFLAGS) -o $@ $<



$(OBJ)/defineRubik.o: $(SRC)/defineRubik.cpp $(INCLUDE)/defineRubik.h
	g++ -c -I$(INCLUDE) $(CXXFLAGS) -o $@ $<


################################################

$(DIR_LIBS)/librubik.a: $(OBJ)/defineRubik.o
	$(AR) rvs $@ $^

################################################

documentation:
	doxygen doc/doxys/Doxyfile

test:
	./bin/Rubik ./data/example.dat

clean:
	@ echo "Cleaning..."
	rm -f $(OBJ)/*.o $(DIR_LIBS)/lib*.a ./doc/html/*
	find . -regex ".*~" -exec rm -r {} \; # Auxiliary files


mrproper: clean
	rm -f $(BIN)/*

.PHONY: clean mrproper all
