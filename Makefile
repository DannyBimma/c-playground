CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11
LDFLAGS = 
TARGET = grand_prix_predictor
SRCS = grand_prix_predictor.c
OBJS = $(SRCS:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)