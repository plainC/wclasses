CFLAGS =                                   \
	-I .                               \
	-I ..                              \
        -g                                 \

CLASSES = $(wildcard *_class.h)
SRCS    = $(patsubst %_class.h,%.c,$(CLASSES))
C_SRCS  = $(patsubst %.c,%_impl.c,$(SRCS))
HEADERS = $(patsubst %.c,%.h,$(SRCS))
OBJS    = $(patsubst %.c,%.o,$(SRCS))

all: build_src

build_src: classes.wobject
	../../wondermacros/tools/wobject -c classes.wobject

$(OBJS): $(SRCS) $(HEADERS) $(CLASSES) $(C_SRCS)
	cc -c $(CFLAGS) $^

libwstd_json.a: $(OBJS)
	ar r $@ $^
	ranlib $@

clean:
	rm -f $(OBJS) *.gch *.o
