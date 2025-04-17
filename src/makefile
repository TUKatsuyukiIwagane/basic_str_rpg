CC = gcc #specify compiler

TARGET = game #name of output file
SRCS = game.c battle.c character.c effect_command.c player.c levelup.c #srcfile

$(TARGET): $(SRCS)
	$(CC) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)