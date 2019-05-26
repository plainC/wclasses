CFLAGS =                                   \
	-I .                               \
	-I ..                              \
        -g                                 \

CLASSES = $(wildcard *_class.h)
SRCS    = $(patsubst %_class.h,%.c,$(CLASSES))
C_SRCS  = $(patsubst %.c,%_impl.c,$(SRCS))
HEADERS = $(patsubst %.c,%.h,$(SRCS))
OBJS    = $(patsubst %.c,%.o,$(SRCS))

all: build_src Wexceptions.o test

build_src: classes.wobject
	../wondermacros/tools/wobject -c classes.wobject

Wexceptions.o: Wexceptions.c
	cc -c Wexceptions.c

test: $(OBJS) test.o
	cc -o test test.o $(OBJS) Wexceptions.o

$(OBJS): Wexceptions.c $(SRCS) $(HEADERS) $(CLASSES) $(C_SRCS)
	cc -c $(CFLAGS) test.c $^

clean:
	rm -f test $(OBJS) *.gch *.o
