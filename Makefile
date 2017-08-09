CXXFLAGS= -Wall -Wextra -pedantic -std=c++11 -g
LIBS= -L./lib -lrubik

INCLUDE= ./include
BIN=./bin
DIR_LIBS=./lib
SRC=./src
OBJ=./obj

all: resolution searchBugs fixBugs

resolution: $(OBJ)/resolution.o $(DIR_LIBS)/librubik.a
	g++ -o $(BIN)/Rubik $< $(LIBS)

searchBugs: $(OBJ)/searchBugs.o $(DIR_LIBS)/librubik.a
	g++ -o $(BIN)/searchBugs $< $(LIBS)

fixBugs:  $(OBJ)/fixBugs.o $(DIR_LIBS)/librubik.a
	g++ -o $(BIN)/fixBugs $< $(LIBS)



$(OBJ)/resolution.o: $(SRC)/resolution.cpp
	g++ -c -I$(INCLUDE) $(CXXFLAGS) -o $@ $<

$(OBJ)/searchBugs.o: $(SRC)/searchBugs.cpp
	g++ -c -I$(INCLUDE) $(CXXFLAGS) -o $@ $<

$(OBJ)/fixBugs.o: $(SRC)/fixBugs.cpp
	g++ -c -I$(INCLUDE) $(CXXFLAGS) -o $@ $<



$(OBJ)/defineRubik.o: $(SRC)/defineRubik.cpp $(INCLUDE)/defineRubik.h
	g++ -c -I$(INCLUDE) $(CXXFLAGS) -o $@ $<


################################################

$(DIR_LIBS)/librubik.a: $(OBJ)/defineRubik.o
	$(AR) rvs $@ $^

################################################

documentation:
	doxygen doc/doxys/Doxyfile


clean:
	@ echo "Cleaning..."
	rm -f $(OBJ)/*.o $(DIR_LIBS)/lib*.a ./doc/html/*
	find . -regex ".*~" -exec rm -r {} \; # Auxiliary files


mrproper: clean
	rm -f $(BIN)/*

.PHONY: clean mrproper all
