CC = g++

OBJ = Perceptron.o main.o

INC = -I libgraph/include/
LIB = -L libgraph/lib/ -lgraph 

.cc.o:
	$(CC) -c $< $(INC) $(LIB) 

all:$(OBJ)
	$(CC) $(OBJ) -o run $(INC) $(LIB) 

bird:
	$(CC) Flappy_bird.cc $(INC) $(LIB) -o bird

clean:
	rm -f *.o run bird
