#ifndef __WCLASSES_H
#define __WCLASSES_H

#define W_OBJECT_CAST_TO_VOID

#include <wondermacros/exceptions/exceptions.h>
#include "core/Wexceptions.h"

extern W_EXCEPTION_TYPE w_exception_stack[64];
extern W_EXCEPTION_TYPE* w_exception_ptr;


#ifndef WDEBUG_EXPAND
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <wondermacros/list/cslist.h>
# include <wondermacros/array/dynamic_array.h>
#endif
# include <wondermacros/objects/api.h>

struct WslistContainer {
    struct WslistContainer* next;
    void* box[0];
};

struct WjsonValue;
struct WjsonObjectMap { const char* key; struct WjsonValue* value; };

struct w_context {
    int nargs;
    void* args[0];
};

typedef void (*wbind_void_func)(int nargs, ...);
typedef void* (*wbind_voidptr_func)(int nargs, ...);
typedef int (*wbind_int_func)(struct w_context* context);
typedef double (*wbind_double_func)(int nargs, ...);

#include "core/forward_declare.h"
#include "iterator/forward_declare.h"
#include "json/forward_declare.h"
#include "string/forward_declare.h"

#include "core/classes.h"
#include "iterator/classes.h"
#include "json/classes.h"
#include "string/classes.h"
#include "Wmacros.h"

#define W_FOR_STRING_ROPE(node,rope) \
    W_CSLIST_FOR_EACH(struct wstring_buffer, node, (rope)->bufs) \

#endif

