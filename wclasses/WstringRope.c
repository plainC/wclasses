#include "forward_declare.h"
#include "WstringRope.h"
#include "WstringRope_class.h"
#include <wondermacros/objects/x/class_start.h>

#define M__append METHOD(WstringRope,public,void,append,(const char* buf, size_t len))
#define M__prepend METHOD(WstringRope,public,void,prepend,(const char* buf, size_t len))
#define EXPAND_C
#include "WstringRope_impl.c"

#include <wondermacros/objects/x/class_end.h>
