#ifndef W_MACROS_ITERATOR__H
#define W_MACROS_ITERATOR__H

#define W_DYNAMIC_ARRAY_GET_ITERATOR(array,pos) (                  \
    (array) && (pos) >= 0 && (pos) < W_DYNAMIC_ARRAY_SIZE(array) ? \
        W_NEW(WiteratorPointer,                                    \
            .first = &array[pos],                                  \
            .last = &array[W_DYNAMIC_ARRAY_SIZE(array)-1],         \
            .elem_size = sizeof(array[0])                          \
        ) :                                                        \
        W_NEW(WiteratorEmpty)                                      \
    )

#endif

