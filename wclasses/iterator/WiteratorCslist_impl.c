#ifdef EXPAND_C

CONSTRUCT(WiteratorCslist)
{
    self->ptr = self->first;
    self->flag = 1;
}

METHOD(WiteratorCslist,public,const void*,get,(size_t* size))
{
    return self->ptr->box;
}

METHOD(WiteratorCslist,public,int,has_next)
{
    return self->ptr && (self->flag || self->ptr != self->first);
}

METHOD(WiteratorCslist,public,void,next)
{
    self->ptr = self->ptr->next;
    self->flag = 0;
}

#endif

