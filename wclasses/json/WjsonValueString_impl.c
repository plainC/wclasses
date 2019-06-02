#ifdef EXPAND_C

METHOD(WjsonValueString,public,int,write,(struct Wwriter* writer))
{
    W_CALL(writer,putc)('\"');
    W_CALL(writer,cat)(self->value);
    W_CALL(writer,putc)('\"');
    return 0;
}

#endif

