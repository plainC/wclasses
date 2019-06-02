CFLAGS =                                   \
	-I .                               \
	-I ..                              \
        -g                                 \

CLASSES = $(wildcard *_class.h)
SRCS    = $(patsubst %_class.h,%.c,$(CLASSES))
C_SRCS  = $(patsubst %.c,%_impl.c,$(SRCS))
HEADERS = $(patsubst %.c,%.h,$(SRCS))
OBJS    = $(patsubst %.c,%.o,$(SRCS))

all: iterator json main unit_tests

main: build_src Wexceptions.o test

iterator:
	cd iterator && make all
json:
	cd json && make all

build_src: classes.wobject
	../wondermacros/tools/wobject -c classes.wobject

Wexceptions.o: Wexceptions.c
	cc -c Wexceptions.c

test: $(OBJS) test.o
	cc -o test test.o $(OBJS) \
	Wexceptions.o iterator/libwstd_iterator.a json/libwstd_json.a

unit_tests:
	gcc -o unit_tests -I. unit_tests.c Wexceptions.c iterator/libwstd_iterator.a

$(OBJS): Wexceptions.c $(SRCS) $(HEADERS) $(CLASSES) $(C_SRCS)
	cc -c $(CFLAGS) test.c $^

clean:
	cd iterator && make clean
	cd json && make clean
	rm -f $(OBJS) $(CLASSES) $(SRCS) $(HEADERS) \
	classes.h forward_declare.h *.gch *.o test unit_tests
