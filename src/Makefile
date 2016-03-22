CFLAGS := -fPIC -c -O3 -g -Wall -Werror
CC := gcc
MAJOR := 0
MINOR := 1
NAME := libdvbparse_plugin
SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)  
INCLUDE := -I../include
VERSION := $(MAJOR).$(MINOR)

.PHONY: clean $(SRCS)

$(NAME).so:$(OBJS)
	ld -shared -soname $@.$(MAJOR) -o $@.$(MAJOR).$(MINOR) $(OBJS) -lc
	ln -s ./$@.$(MAJOR).$(MINOR) ./$@.$(MAJOR)
	ln -s ./$@.$(MAJOR)   ./$@
	cp -avf $(NAME)* ../lib
.c.o:
	$(CC) $(CFLAGS) $(INCLUDE)  $< -o $@

clean:
	$(RM) *.o *.so*
