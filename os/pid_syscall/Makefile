CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = pid_syscall

all: $(TARGET)

$(TARGET): pid_syscall.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)

