#ifndef __WCLASSES_H
#define __WCLASSES_H

#define W_OBJECT_CAST_TO_VOID

#include <wondermacros/exceptions/exceptions.h>
#include "Wexceptions.h"

extern W_EXCEPTION_TYPE w_exception_stack[64];
extern W_EXCEPTION_TYPE* w_exception_ptr;


#ifndef WDEBUG_EXPAND
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <wondermacros/list/cslist.h>
#endif
# include <wondermacros/objects/api.h>

struct wstring_buffer {
  const char* buf;
  size_t size;
  struct wstring_buffer* next;
};

#include "forward_declare.h"
#include "classes.h"

#define W_FOR_STRING_ROPE(node,rope) \
    W_CSLIST_FOR_EACH(struct wstring_buffer, node, (rope)->bufs) \

#endif

