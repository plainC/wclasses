#define CLASS WstringRope
#define SUPER WstringBase
#define NO_CONSTRUCT

#define WstringRope__define \
    /* Inherits: WstringBase */ \
    WstringBase__define \
    \
    VAR(read,struct wstring_buffer*,bufs) \
    OVERRIDE(WstringRope,append) \
    OVERRIDE(WstringRope,prepend) \
    OVERRIDE(WstringRope,begin) \
    /**/
