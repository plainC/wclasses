#define CLASS WstringRope
#define NO_CONSTRUCT

#define WstringRope__define \
    VAR(read,struct wstring_buffer*,bufs) \
    METHOD(WstringRope,public,void,prepend,(const char* buf, size_t len)) \
    METHOD(WstringRope,public,void,append,(const char* buf, size_t len)) \
    /**/
