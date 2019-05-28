#ifdef EXPAND_C

#include <wondermacros/array/dynamic_array.h>

METHOD(WjsonArray,public,int,write,(struct Wwriter* writer))
{
    W_CALL(writer,putc)('[');
    int count=0;
    W_DYNAMIC_ARRAY_FOR_EACH(struct WjsonValue*, elem, self->elems) {
        if (count++)
            W_CALL(writer,putc)(',');
        W_CALL(elem,write)(writer);
    }
    W_CALL(writer,putc)(']');
}

M__push_back
{
    W_DYNAMIC_ARRAY_PUSH(self->elems, elem);
}

#endif

