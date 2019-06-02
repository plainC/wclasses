#ifdef EXPAND_C

CONSTRUCT(WiteratorEmpty)
{
}

METHOD(WiteratorEmpty,public,const void*,get,(size_t* size))
{
    return NULL;
}

METHOD(WiteratorEmpty,public,int,has_next)
{
    return 0;
}

METHOD(WiteratorEmpty,public,void,next)
{
}

#endif

