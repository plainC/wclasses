#ifdef EXPAND_C

M__append
{
    return NULL;
}

M__prepend
{
    return NULL;
}

M__begin
{
    return NULL;
}

M__length
{
    return 0;
}

M__empty
{
    return W_CALLV(self,length) == 0;
}

#endif

