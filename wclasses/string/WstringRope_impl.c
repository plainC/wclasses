#ifdef EXPAND_C

#include <wondermacros/array/dynamic_array.h>

FINALIZE(WstringRope)
{
}

METHOD(WstringRope,public,struct WstringBase*,append,(const char* buf, size_t len))
{
    struct WslistContainer* container = malloc(sizeof(struct WslistContainer) + sizeof(struct WstringChunk));
    struct WstringChunk* chunk = (struct WstringChunk*) container->box;
    container->next = container;
    chunk->klass = W_CLASS(WstringChunk);
    chunk->str = (void*) buf;
    chunk->size = len;
    chunk->buf_size = 0;

    W_CSLIST_APPEND(struct WslistContainer, self->list, container);
    return W_OBJECT_AS(self, WstringBase);
}

METHOD(WstringRope,public,struct WstringBase*,prepend,(const char* buf, size_t len))
{
    struct WslistContainer* container = malloc(sizeof(struct WslistContainer) + sizeof(struct WstringChunk));
    struct WstringChunk* chunk = (struct WstringChunk*) container->box;
    container->next = container;
    chunk->str = (void*) buf;
    chunk->size = len;
    chunk->buf_size = 0;

    W_CSLIST_PREPEND(struct WslistContainer, self->list, container);
    return W_OBJECT_AS(self, WstringBase);
}

METHOD(WstringRope,public,size_t,length)
{
    size_t length = 0;
    W_CSLIST_FOR_EACH(struct WslistContainer, container, self->list)
        length += ((struct WstringChunk*) container->box)->size;
    return length;
}

METHOD(WstringRope,public,struct Witerator*,begin,(struct Witerator* iter))
{
    return W_NEW(WiteratorCslist, .first = self->list->next);
}

#endif
