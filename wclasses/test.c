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
}

