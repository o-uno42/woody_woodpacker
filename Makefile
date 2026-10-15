CC = clang
CFLAGS += -m64

SRCS = woody_woodpacker.c parsing.c encryption.c
OBJS = $(SRCS:.c=.o)

EXECUTABLE = woody_woodpacker
HEADER = woody_woodpacker.h

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(EXECUTABLE)

re: fclean all