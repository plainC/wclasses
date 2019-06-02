#ifdef EXPAND_C

CONSTRUCT(WreaderMemory)
{
    self->pos = 0;
}

METHOD(WreaderMemory,public,char,getc)
{
    return self->ptr[self->pos++];
}

METHOD(WreaderMemory,public,char,peek)
{
    return self->ptr[self->pos];
}

METHOD(WreaderMemory,public,size_t,read,(char* buf, size_t size))
{
    size_t b = 0;
    while (self->pos < self->size && b < size)
        buf[b++] = self->ptr[self->pos++];
    return b;
}

#endif

