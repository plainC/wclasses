#ifdef EXPAND_C

#define W_EQUAL(a,b) (strcmp(a,b)==0)

/* Djb2 by Dan Bernstein */
#define W_HASH(key,hash)                     \
    do {                                     \
        const char* W_ID(str) = (key);       \
        hash = 5381;                         \
        int c;                               \
        while (c = *W_ID(str)++)             \
            hash = ((hash << 5) + hash) + c; \
    } while (0)

#include <wondermacros/array/hash_table.h>

CONSTRUCT(WjsonObject)
{
}

M__add_member
{
    W_HASH_TABLE_PUSH(struct WjsonObjectMap, self->members, name, value);
    return W_OBJECT_AS(self,WjsonObject);
}

M__get
{
    W_HASH_TABLE_FOR_EACH_MATCH(struct WjsonObjectMap, map, self->members, name)
        return map->value;
}

M__get_ptr
{
    W_HASH_TABLE_FOR_EACH_MATCH(struct WjsonObjectMap, map, self->members, name)
        return &map->value;
}

#endif
