CFLAGS =                                   \
	-I .                               \
	-I ..                              \
        -g                                 \
	-fPIC                              \

CLASSES = $(wildcard *_class.h)
SRCS    = $(patsubst %_class.h,%.c,$(CLASSES))
C_SRCS  = $(patsubst %.c,%_impl.c,$(SRCS))
HEADERS = $(patsubst %.c,%.h,$(SRCS))
OBJS    = $(patsubst %.c,%.o,$(SRCS))

all: build_src libwstd_iterator.a

build_src: classes.wobject
	../../wondermacros/tools/wobject -c classes.wobject

$(OBJS): $(SRCS) $(HEADERS) $(CLASSES) $(C_SRCS)
	cc -c $(CFLAGS) $^

libwstd_iterator.a: $(OBJS)
	ar r $@ $^
	ranlib $@

clean:
	rm -f $(OBJS) *.gch *.o
