#ifdef EXPAND_C

METHOD(WjsonValueFloat,public,int,write,(struct Wwriter* writer))
{
    char buf[64];
    sprintf(buf, "%g", self->value);
    W_CALL(writer,cat)(buf);
}

#endif

