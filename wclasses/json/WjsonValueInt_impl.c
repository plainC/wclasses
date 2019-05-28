#ifdef EXPAND_C

METHOD(WjsonValueInt,public,int,write,(struct Wwriter* writer))
{
    char buf[32];
    sprintf(buf, "%lld", self->value);
    W_CALL(writer,cat)(buf);
}

#endif

