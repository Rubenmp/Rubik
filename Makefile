CXXFLAGS= -Wall -Wextra -pedantic -std=c++11 -g
LIBS= -L./lib -lrubik

INCLUDE= ./include
BIN=./bin
DIR_LIBS=./lib
SRC=./src
OBJ=./obj

all: resolution searchErrors fixErrors


resolution: $(OBJ)/resolution.o $(DIR_LIBS)/librubik.a
	g++ -o $(BIN)/Rubik $< $(LIBS)

searchErrors: $(OBJ)/searchErrors.o $(DIR_LIBS)/librubik.a
	g++ -o $(BIN)/searchErrors $< $(LIBS)

fixErrors:  $(OBJ)/fixErrors.o $(DIR_LIBS)/librubik.a
	g++ -o $(BIN)/fixErrors $< $(LIBS)




$(OBJ)/resolution.o: $(SRC)/resolution.cpp
	g++ -c -I$(INCLUDE) $(CXXFLAGS) -o $@ $<

$(OBJ)/searchErrors.o: $(SRC)/searchErrors.cpp
	g++ -c -I$(INCLUDE) $(CXXFLAGS) -o $@ $<

$(OBJ)/fixErrors.o: $(SRC)/fixErrors.cpp
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
	find . -regex ".*~" -exec rm -r {} \;


mrproper: clean
	rm -f $(BIN)/*

.PHONY: clean mrproper all
