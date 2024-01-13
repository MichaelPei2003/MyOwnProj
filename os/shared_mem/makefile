CC = gcc
CFLAGS = -Wall -Wextra

all: sender receiver

sender: sender.c common.h
	$(CC) $(CFLAGS) -o sender sender.c -lrt

receiver: receiver.c common.h
	$(CC) $(CFLAGS) -o receiver receiver.c -lrt

clean:
	rm -f sender receiver
