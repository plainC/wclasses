#ifdef EXPAND_C

#include <wondermacros/math/min.h>
#include <ctype.h>

#define GROW(Size)                                                       \
    do {                                                                 \
        if (self->capacity > self->size + (Size)) {                      \
            self->c_str = realloc(self->c_str, self->size + (Size) + 1); \
            if (!self->c_str) ;                                          \
            self->capacity = self->size + (Size) + 1;                    \
        }                                                                \
    } while (0)


CONSTRUCT(Wstring)
{
    if (self->c_str && (!self->size || !self->capacity)) {
        self->c_str = strdup(self->c_str);
        self->size = strlen(self->c_str);
        self->capacity = self->size+1;
    }
}

FINALIZE(Wstring)
{
    free((void*) self->c_str);
}

METHOD(Wstring,public,struct WstringBase*,append,(const char* str, size_t size))
{
    GROW(size);

    strncpy(self->c_str + self->size, str, size);
    self->size += size;

    return W_OBJECT_AS(self, WstringBase);
}

METHOD(Wstring,public,struct WstringBase*,prepend,(const char* str, size_t size))
{
    GROW(size);

    memmove(self->c_str + size, self->c_str, self->size);
    strncpy(self->c_str, str, size);

    return W_OBJECT_AS(self, WstringBase);
}

static int
str_iter_has_next(struct Witerator* self)
{
    return 0;
}

static void*
str_iter_get(struct Witerator* self, size_t* size)
{
}

static void
str_iter_next(struct Witerator* self)
{
}

METHOD(Wstring,public,struct Witerator*,begin,(struct Witerator* iter))
{
    return iter;
}

M__starts_with
{
    return strncmp(self->c_str, str, size) == 0;
}

M__ends_with
{
    return self->size >= size ? strncmp(self->c_str+self->size-size-1, str, size) == 0 : 0;
}

M__front
{
    return self->size ? self->c_str[0] : '\0';
}

M__back
{
    return self->size ? self->c_str[self->size-1] : '\0';
}

M__hash32
{
}

M__hash64
{
}

M__replace
{
    if (first > last)
        W_THROW(W_ERROR_CODE_OUT_OF_RANGE,
            "Wstring::replace: first greater than last (%d vs %d)", first, last);

    size_t orig_len = last - first + 1;
    if (orig_len < size) {
        GROW(size-orig_len);
    }
}

M__empty
{
    return self->size == 0;
}

M__find
{
    const char* s = strstr(self->c_str, str);
    return s == NULL ? -1 : s - self->c_str;
}

M__rfind
{
    size_t size = strlen(str);
    for (int pos=self->size-1-size; pos>=0; --pos)
        if (strncmp(self->c_str+pos, str, size) == 0)
            return pos;

    return -1;
}

M__find_first_of
{
}

M__find_last_of
{
}

M__find_first_not_of
{
}

M__find_last_not_of
{
}

M__uc
{
    for (int i=0; i < self->size; i++)
        self->c_str[i] = toupper(self->c_str[i]);

    return W_OBJECT_AS(self, Wstring);
}

M__lc
{
    for (int i=0; i < self->size; i++)
        self->c_str[i] = tolower(self->c_str[i]);

    return W_OBJECT_AS(self, Wstring);
}

M__compare
{
    return strcmp(self->c_str, str->c_str);
}

M__stoul
{
    return strtoul(self->c_str, NULL, 10);
}

M__stol
{
    return strtol(self->c_str, NULL, 10);
}

M__stoull
{
    const char* s = self->c_str;
    while (isspace(*s))
        ++s;
    int neg = *s == '-';
    if (neg)
        ++s; // FIXME: Exception

    return (uint64_t) strtoull(s, 0, 0);
}

M__stoll
{
    const char* s = self->c_str;
    while (isspace(*s++));
    int neg = *s == '-';
    if (neg)
        ++s;

    unsigned long long value = strtoull(s, 0, 0);
    if (value > INT64_MAX)
        return 0; // FIXME: Exception

    return neg ? -(value - 1) - 1 : value;
}

M__push_back
{
    GROW(4);

    self->c_str[self->size++] = ch;
}

M__pop_back
{
    if (self->size) {
        char ch = self->c_str[--self->size];
        if (!self->size) {
            free((void*) self->c_str);
            self->size = self->capacity = 0;
        }
        return ch;
    } else
        return '\0';
}

METHOD(Wstring,public,size_t,length)
{
    return self->size;
}

M__insert
{
    GROW(size);

    memmove(self->c_str + pos + size, self->c_str + pos, size);
    strncpy(self->c_str + pos, str, size);
    return W_OBJECT_AS(self, Wstring);
}

M__erase
{
    if (last < first); // FIXME: exception
    memmove(self->c_str + first, self->c_str + last, last - first + 1);
    self->size -= last - first - 1;
}

M__at
{
    return pos < self->size ? self->c_str[pos] : '\0';
}

M__substr
{
    if (first >= self->size)
        return NULL;

    return strndup(self->c_str + first, W_MIN(count, self->size-first));
}

M__clear
{
    free((void*) self->c_str);
    self->capacity = self->size = 0;
}

#endif

