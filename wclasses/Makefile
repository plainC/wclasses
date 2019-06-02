CFLAGS =                                   \
	-I .                               \
	-I ..                              \
        -g                                 \

CLASSES = $(wildcard *_class.h)
SRCS    = $(patsubst %_class.h,%.c,$(CLASSES))
C_SRCS  = $(patsubst %.c,%_impl.c,$(SRCS))
HEADERS = $(patsubst %.c,%.h,$(SRCS))
OBJS    = $(patsubst %.c,%.o,$(SRCS))

all: sources libs unit_tests

libs:
	cd core && make lib
	cd json && make lib
	cd iterator && make lib
	cd string && make lib

sources:
	cd core && make source
	cd iterator && make source
	cd json && make source
	cd string && make source

test: $(OBJS) test.o
	cc -o test test.o $(OBJS) \
	core/libwstd_core.a iterator/libwstd_iterator.a json/libwstd_json.a

unit_tests:
	gcc -o unit_tests -I. unit_tests.c core/libwstd_core.a iterator/libwstd_iterator.a

$(OBJS): core/libwstd_core.a $(SRCS) $(HEADERS) $(CLASSES) $(C_SRCS)
	cc -c $(CFLAGS) test.c $^

clean:
	cd core && make clean
	cd iterator && make clean
	cd json && make clean
	cd string && make clean
	rm -f $(OBJS) $(CLASSES) $(SRCS) $(HEADERS) \
	classes.h forward_declare.h *.gch *.o test unit_tests
