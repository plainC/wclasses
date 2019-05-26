#ifdef EXPAND_C

#include <wondermacros/array/dynamic_array.h>


FINALIZE(WstringRope)
{
    W_FOR_STRING_ROPE(node, self) {
        free(node);
    }
}

METHOD(WstringRope,public,struct WstringBase*,append,(const char* buf, size_t len))
{
    struct wstring_buffer* b = malloc(sizeof(struct wstring_buffer));
    b->buf = buf;
    b->size = len;
    b->next = b;

    W_CSLIST_APPEND(struct wstring_buffer, self->bufs, b);
    return W_OBJECT_AS(self, WstringBase);
}

METHOD(WstringRope,public,struct WstringBase*,prepend,(const char* buf, size_t len))
{
    struct wstring_buffer* b = malloc(sizeof(struct wstring_buffer));
    b->buf = buf;
    b->size = len;
    b->next = b;

    W_CSLIST_PREPEND(struct wstring_buffer, self->bufs, b);
    return W_OBJECT_AS(self, WstringBase);
}



METHOD(WstringRope,public,struct Witerator*,begin,(struct Witerator* iter))
{
    return iter;
}

#endif
