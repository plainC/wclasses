#ifdef EXPAND_C

CONSTRUCT(WstringChunk)
{
    /* If size is not given but a string is, count the string length. */
    if (self->str && !self->size)
        self->size = strlen(self->str);
}

FINALIZE(WstringChunk)
{
    /* We have ownership only if buffer size is non-zero. */
    if (self->buf_size)
        free(self->str);
}

METHOD(WstringChunk,public,size_t,length)
{
    return self->size;
}

METHOD(WstringChunk,public,struct WstringBase*,append,(const char* buf, size_t size))
{
    if (self->size + size > self->buf_size)
        self->str = realloc(self->str, self->size + size);
    strncpy(self->str + self->size, buf, size);
    self->size += size;

    return W_OBJECT_AS(self, WstringBase);
}

METHOD(WstringChunk,public,struct WstringBase*,prepend,(const char* buf, size_t len))
{
    return W_OBJECT_AS(self, WstringBase);
}

METHOD(WstringChunk,public,struct Witerator*,begin,(struct Witerator* iter))
{
    if (!iter)
        iter = W_NEW(WiteratorPointer,
            .first = (void*) self->str,
            .last = W_REF_VOID_PTR(self->str, self->size-1),
            .elem_size = 1
        );

    return iter;
}

#endif

