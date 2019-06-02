#include "wclasses.h"
#include <wondermacros/array/dynamic_array.h>

int add(struct w_context* context)
{
    int sum=0;
    for (int i=0; i < context->nargs; i++)
        sum += *((int*) context->args[i]);

    return sum;
}

static inline struct w_context*
w_bind(int nargs, ...)
{
    struct w_context* context = malloc(sizeof(struct w_context) + sizeof(void*)*nargs);
    context->nargs = nargs;
    va_list ap;
    va_start(ap, nargs);
    for (int i=0; i < nargs; i++) {
        context->args[i] = malloc(sizeof(int));
        *(((int*) context->args[i])) = va_arg(ap, int);
    }
    va_end(ap);

    return context;
}

int main()
{
    W_TRY {
#if 0
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

        const char* jsonStr = "{\"foo\":\"42\"}";
        struct Wreader* reader = W_NEW(WreaderMemory, .ptr=jsonStr, .size=strlen(jsonStr));

        struct WjsonDocument* doc = W_NEW(WjsonDocument);
        W_CALL(doc,parse)(reader);

//        W_CALL(doc,add_member)("goo", W_NEW(WjsonValueInt, .value = 142));
//        W_CALL(doc,add_member)("x", W_NEW(WjsonValueString, .value = "abc"));

//        struct WjsonValue* vv = W_CALL(doc,get)("foo");
        char buffer[512]={0};
        struct Wwriter* writer = W_NEW(WwriterMemory, .ptr = buffer, .size=512);
        W_CALL(doc,write)(writer);
        printf("doc='%s'\n", buffer);



        struct WstringRope* rope = W_NEW(WstringRope);
        W_CALL(rope,append)("/",1);
        W_CALL(rope,append)("home",4);
        W_CALL(rope,append)("/",1);
        W_CALL(rope,append)("wondermacros",12);
        W_CALL(rope,append)("/",1);
        W_CALL(rope,append)("Projects",8);
        printf("Length: %d\n", W_CALLV(rope,length));

        iter = W_CALL(rope,begin)(NULL);
        while (W_CALLV(iter,has_next)) {
            size_t size;
            const struct WstringChunk* chunk = W_CALL(iter,get)(&size);
            printf("%.*s", chunk->size, chunk->str);
            W_CALLV(iter,next);
        }
        printf("\n");
#endif

       struct WbindI* lazy = W_NEW(WbindI, .func = add, .context = w_bind(3, 1, 2, 3));
       printf("value=%d\n", W_CALLV(lazy,eval));
   }
    W_CATCH_ALL {
        W_EXCEPTION_FPRINTF(stdout);
    }
}
