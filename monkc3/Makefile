CC = gcc
CFLAGS = -std=gnu11 -Wall -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -Wno-unknown-pragmas -g -Iruntime -Istdlib -Iplatform -Iapp
LDFLAGS = -lpthread -lm

RUNTIME_SRC = $(wildcard runtime/*.c)
STDLIB_SRC = $(wildcard stdlib/*.c)
PLATFORM_SRC = $(wildcard platform/*.c)
APP_SRC = $(wildcard app/*.c)

RUNTIME_OBJ = $(RUNTIME_SRC:.c=.o)
STDLIB_OBJ = $(STDLIB_SRC:.c=.o)
PLATFORM_OBJ = $(PLATFORM_SRC:.c=.o)
APP_OBJ = $(APP_SRC:.c=.o)

ALL_OBJ = $(RUNTIME_OBJ) $(STDLIB_OBJ) $(PLATFORM_OBJ) $(APP_OBJ)

TARGET = monkc3_demo

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(ALL_OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(ALL_OBJ) $(TARGET)