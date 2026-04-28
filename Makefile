CC = clang

CFLAGS = -Wall -Wextra -Werror -Wsign-compare -Wshadow -g

TARGET = Multi-Hello-World-Linux-x64

SRCS = main.c data.c utils.c hash.c config.c

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)

