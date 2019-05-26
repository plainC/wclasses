#include "wclasses.h"
#include <wondermacros/array/dynamic_array.h>

int main()
{
    W_TRY {
        struct Wstring* s = W_NEW(Wstring, .c_str = "Foo");
        printf("at[1]='%c'\n", W_CALL(s,at)(1));
        W_CALL_VOID(s,free);

        struct Wstring* s_i = W_NEW(Wstring, .c_str = "1234567890123456789");
        uint64_t v = W_CALL_VOID(s_i,stoull);
        printf("%llu\n", v);

        W_CALL(s,replace)(1,1, "xx",2);


        struct WstringChunk* c1 = W_NEW(WstringChunk, .str = "foobar");
        printf("%d\n", W_CALLV(c1,length));
        struct Witerator* iter = W_CALL(c1,begin)(NULL);
        while (W_CALLV(iter,has_next)) {
            size_t size;
            const char* p = W_CALL(iter,get)(&size);
            printf("%c", *p);
            W_CALLV(iter,next);
        }
        printf("\n");

        struct point { int x; int y; };
        struct point* array = NULL;
        W_DYNAMIC_ARRAY_PUSH(array, ((struct point) { 1, 2 }));
        W_DYNAMIC_ARRAY_PUSH(array, ((struct point) { 7, 5 }));
        iter = W_DYNAMIC_ARRAY_GET_ITERATOR(array,0);
        while (W_CALLV(iter,has_next)) {
            size_t size;
            const struct point* p = W_CALL(iter,get)(&size);
            printf("%d,%d\n", p->x, p->y);
            W_CALLV(iter,next);
        }

        struct WstringBase* str = W_NEW(WstringChunk, .str = "{\"foo\":42}");
        struct WjsonObject* doc = W_NEW(WjsonObject);
        W_CALL(doc,add_member)("foo", W_NEW(WjsonValueInt, .value = 42));
        W_CALL(doc,add_member)("goo", W_NEW(WjsonValueInt, .value = 142));

        struct WjsonValue* vv = W_CALL(doc,get)("goo");
        printf("%lld\n", W_OBJECT_AS(vv,WjsonValueInt)->value);
    }
    W_CATCH_ALL {
        W_EXCEPTION_FPRINTF(stdout);
    }
}
