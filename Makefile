IDIR = ./include
CC=g++
CFLAGS=-I$(IDIR) -ftest-coverage -fprofile-arcs

ODIR = ./obj
SRC = ./src

LIBS=-lm

_DEPS = num_romanos.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = num_romanos.o teste_num_romanos_main.o teste_num_romanos.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SRC)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) 

teste_num_romano: $(OBJ)
	g++ -o $@ $^ $(CFLAGS) $(LIBS)
	./teste_num_romano
	mv ./obj/*.gcda ./
	mv ./obj/*.gcno ./
	gcov teste_num_romanos.gcno
	rm ./catch.hpp.gcov
	rm ./*.gcda
	rm ./*.gcno

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 