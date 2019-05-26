#ifdef EXPAND_C

CONSTRUCT(WiteratorPointer)
{
    if (!self->ptr)
        self->ptr = self->first;
    if (!self->elem_size)
        self->elem_size = sizeof(void*);
}

METHOD(WiteratorPointer,public,const void*,get,(size_t* size))
{
    return self->ptr;
}

METHOD(WiteratorPointer,public,int,has_next)
{
    return self->ptr && self->ptr <= self->last;
}

METHOD(WiteratorPointer,public,void,next)
{
    self->ptr = W_REF_VOID_PTR(self->ptr, self->elem_size);
}

#endif

