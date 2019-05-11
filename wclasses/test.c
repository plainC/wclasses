#include "wclasses.h"

int main()
{
    struct WstringRope* rope = W_NEW(WstringRope);

    W_CALL(rope,append)("Eka",3);
    W_CALL(rope,prepend)("Toka",4);
    W_CALL(rope,append)("Kolmas",6);

    W_FOR_STRING_ROPE(node,rope)
        printf("%s", node->buf);
    printf("\n");

    W_CALL_VOID(rope,free);


    struct Wstring* s = W_NEW(Wstring, .c_str = "Foo");
    printf("at[1]='%c'\n", W_CALL(s,at)(1));
    W_CALL_VOID(s,free);
}
