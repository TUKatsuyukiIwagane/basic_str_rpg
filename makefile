CC = gcc #specify compiler

TARGET = game #name of output file
SRCS = game.c battle.c

$(TARGET): $(SRCS)
	$(CC) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)