CC = g++
EXEC_NAME = projet
OBJ_FILES = main.o Image.o Pixel.o
CFLAGS = -Wall -ggdb
MAIN = mainExemple
CLASS1 = Pixel
CLASS2 = Image


all: $(EXEC_NAME)

$(EXEC_NAME):  $(CLASS1).o $(CLASS2).o $(MAIN).o
	$(CC)  $(CLASS1).o $(CLASS2).o $(MAIN).o -o $(EXEC_NAME)

$(CLASS1).o: $(CLASS1).h $(CLASS1).cpp
	$(CC) $(CFLAGS) -c $(CLASS1).cpp 

$(CLASS2).o: $(CLASS2).cpp $(CLASS2).h 
	$(CC) $(CFLAGS) -c $(CLASS2).cpp


$(MAIN).o: $(MAIN).cpp
	$(CC) $(CFLAGS) $(MAIN).cpp

clean:
	rm $(OBJ_FILES)