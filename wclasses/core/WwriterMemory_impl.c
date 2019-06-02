#ifdef EXPAND_C

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
}

#endif

