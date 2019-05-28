#ifdef EXPAND_C

METHOD(WjsonValueBool,public,int,write,(struct Wwriter* writer))
{
    W_CALL(writer,cat)(self->value ? "true" : "false");
}

#endif

