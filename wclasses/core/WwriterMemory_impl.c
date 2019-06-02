#ifdef EXPAND_C

CONSTRUCT(WwriterMemory)
{
    if (!self->start && self->ptr)
        self->start = self->ptr;
    else if (self->start && !self->ptr)
        self->ptr = self->start;
}

METHOD(WwriterMemory,public,int,putc,(char ch))
{
    *self->ptr++ = ch;
}

METHOD(WwriterMemory,public,int,cat,(const char* str))
{
    while (*str)
        *self->ptr++ = *str++;
}

METHOD(WwriterMemory,public,int,append,(const char* str, size_t size))
{
    for (size_t i=0; i < size; i++)
        *self->ptr++ = *str++;
}

METHOD(WwriterMemory,public,void,clear)
{
    self->ptr = self->start;
    *self->ptr = '\0';
}

#endif

