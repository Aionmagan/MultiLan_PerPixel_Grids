CC = gcc 
LIBS = -lSDL2 -lSDL2main
OBJS = main.c
TARGET = Grid

all: 
	$(CC) $(OBJS) -o $(TARGET) $(LIBS)

$(TARGET):
	$(CC) $(OBJS) -o $(TARGET) $(LIBS)

clean: 
	rm -f $(TARGET)	

run: 
	./$(TARGET)
