#include "forward_declare.h"
#include "Wstring.h"
#include "Wstring_class.h"
#include <wondermacros/objects/x/class_start.h>

#define M__push_back METHOD(Wstring,public,struct Wstring*,push_back,(char ch))
#define M__compare METHOD(Wstring,public,int,compare,(struct Wstring* str))
#define M__ends_with METHOD(Wstring,public,int,ends_with,(char* str, size_t size))
#define M__erase METHOD(Wstring,public,struct Wstring*,erase,(int first, int last))
#define M__front METHOD(Wstring,public,char,front)
#define M__pop_back METHOD(Wstring,public,char,pop_back)
#define M__find METHOD(Wstring,public,int,find,(const char* str, int pos))
#define M__uc METHOD(Wstring,public,struct Wstring*,uc)
#define M__rfind METHOD(Wstring,public,int,rfind,(const char* str, int pos))
#define M__starts_with METHOD(Wstring,public,int,starts_with,(char* str, size_t size))
#define M__insert METHOD(Wstring,public,struct Wstring*,insert,(int pos, char* str, size_t size))
#define M__stoll METHOD(Wstring,public,int64_t,stoll)
#define M__at METHOD(Wstring,public,char,at,(int pos))
#define M__stol METHOD(Wstring,public,int32_t,stol)
#define M__substr METHOD(Wstring,public,const char*,substr,(int first, int count))
#define M__find_last_not_of METHOD(Wstring,public,const char*,find_last_not_of,(const char* chars, size_t size))
#define M__lc METHOD(Wstring,public,struct Wstring*,lc)
#define M__clear METHOD(Wstring,public,struct Wstring*,clear)
#define M__find_first_of METHOD(Wstring,public,const char*,find_first_of,(const char* chars, size_t size))
#define M__find_first_not_of METHOD(Wstring,public,const char*,find_first_not_of,(const char* chars, size_t size))
#define M__stoull METHOD(Wstring,public,uint64_t,stoull)
#define M__stoul METHOD(Wstring,public,uint32_t,stoul)
#define M__find_last_of METHOD(Wstring,public,const char*,find_last_of,(const char* chars, size_t size))
#define M__hash32 METHOD(Wstring,public,uint32_t,hash32)
#define M__replace METHOD(Wstring,public,struct Wstring*,replace,(int first, int last, char* str, size_t size))
#define M__back METHOD(Wstring,public,char,back)
#define M__hash64 METHOD(Wstring,public,uint64_t,hash64)
#define EXPAND_C
#include "Wstring_impl.c"

#include <wondermacros/objects/x/class_end.h>
