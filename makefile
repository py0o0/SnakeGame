CC=g++
TARGET=snakegame
OBJECTS=main.cpp 


$(TARGET):$(OBJECTS)
	-std=c++20 $(CC) -o $(TARGET) $(OBJECTS) -lncurses 
