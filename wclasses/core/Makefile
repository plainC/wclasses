CFLAGS =                                   \
	-I .                               \
	-I ..                              \
	-g                                 \
	-fPIC                              \

SRCS    =             \
	Wreader.c     \
	WreaderMemory.c     \
	Wwriter.c     \
	WwriterMemory.c     \

OBJS    = $(patsubst %.c,%.o,$(SRCS)) Wexceptions.o

CLASSES = $(wildcard *_class.h)
GEN_C   = $(patsubst %_class.h,%.c,$(CLASSES))
GEN_H   = $(patsubst %.c,%.h,$(SRCS))


source: classes.wobject
	../../wondermacros/tools/wobject -c classes.wobject

lib: libwstd_core.a

*.o: *.c *.h

libwstd_core.a: $(OBJS)
	ar r $@ $^
	ranlib $@

clean:
	rm -f *.o libwstd_core.a *.gch $(NAME) $(CLASSES) $(GEN_C) $(GEN_H) classes.h forward_declare.h
