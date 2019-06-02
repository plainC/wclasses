#ifdef EXPAND_C

#include <stdio.h>

CONSTRUCT(WreaderMemory)
{
    self->pos = 0;
}

METHOD(WreaderMemory,public,int,getc)
{
    return self->pos < self->size ? self->ptr[self->pos++] : EOF;
}

METHOD(WreaderMemory,public,int,peek)
{
    return self->pos < self->size ? self->ptr[self->pos] : EOF;
}

METHOD(WreaderMemory,public,size_t,read,(char* buf, size_t size))
{
    size_t b = 0;
    while (self->pos < self->size && b < size)
        buf[b++] = self->ptr[self->pos++];

    return b;
}

#endif

