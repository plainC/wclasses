#ifndef W_CLASSES_MACROS
#define W_CALSSES_MACROS

#define W_DYNAMIC_ARRAY_GET_ITERATOR(array,pos) (         \
    (array) ?                                             \
        W_NEW(WiteratorPointer,                           \
            .first = &array[pos],                         \
            .last = &array[W_DYNAMIC_ARRAY_SIZE(array)-1] \
        ) :                                               \
        NULL                                              \
    )

#endif
