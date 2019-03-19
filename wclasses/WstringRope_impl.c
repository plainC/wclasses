#ifdef EXPAND_C

FINALIZE(WstringRope)
{
}

M__append
{
    struct wstring_buffer* b = malloc(sizeof(struct wstring_buffer));
    b->buf = buf;
    b->size = len;
    b->next = b;

    W_CSLIST_APPEND(struct wstring_buffer, self->bufs, b);
}

M__prepend
{
    struct wstring_buffer* b = malloc(sizeof(struct wstring_buffer));
    b->buf = buf;
    b->size = len;
    b->next = b;

    W_CSLIST_PREPEND(struct wstring_buffer, self->bufs, b);
}

#endif

