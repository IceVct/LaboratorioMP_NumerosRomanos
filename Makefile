IDIR = ./include
CC=g++
CFLAGS=-I$(IDIR)

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

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 