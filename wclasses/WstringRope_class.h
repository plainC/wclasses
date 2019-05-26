#define CLASS WstringRope
#define SUPER WstringBase
#define NO_CONSTRUCT

#define WstringRope__define \
    /* Inherits: WstringBase */ \
    WstringBase__define \
    \
    VAR(private,struct WslistContainer*,list) \
    OVERRIDE(WstringRope,append) \
    OVERRIDE(WstringRope,prepend) \
    OVERRIDE(WstringRope,length) \
    OVERRIDE(WstringRope,begin) \
    /**/
