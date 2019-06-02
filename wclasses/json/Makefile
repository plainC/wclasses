CFLAGS =                                   \
	-I .                               \
	-I ..                              \
	-g                                 \
	-fPIC                              \

NAME    = libwstd_json.a

SRCS    =                  \
	WjsonArray.c       \
	WjsonDocument.c    \
	WjsonObject.c      \
	WjsonValue.c       \
	WjsonValueBool.c   \
	WjsonValueFloat.c  \
	WjsonValueInt.c    \
	WjsonValueString.c \

OBJS    = $(patsubst %.c,%.o,$(SRCS))

CLASSES = $(wildcard *_class.h)
GEN_C   = $(patsubst %_class.h,%.c,$(CLASSES))
GEN_H   = $(patsubst %.c,%.h,$(SRCS))


source: classes.wobject
	../../wondermacros/tools/wobject -c classes.wobject

lib: $(NAME)

*.o: *.c *.h

$(NAME): $(OBJS)
	ar r $@ $^
	ranlib $@

clean:
	rm -f *.o *.gch $(NAME) $(CLASSES) $(GEN_H) $(GEN_C) classes.h forward_declare.h
