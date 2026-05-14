CC      = cc
CFLAGS  = -Wall -Wno-unused-variable -O2
TARGET  = catch_him
SRC     = main.c
HEADERS = compat.h header.h display_screen.h settup.h move.h bomb.h item.h

$(TARGET): $(SRC) $(HEADERS)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: run clean
