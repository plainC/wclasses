#ifdef EXPAND_C

#include "WjsonObject.h"

#include <ctype.h>

#define Expect(ch) \
    do { if (W_CALLV(reader,peek) != Ch) return NULL; } while (0)
#define Accept(Ch) \
    do { if (W_CALLV(reader,getc) != Ch) return NULL; } while (0)
#define Peek() \
    W_CALLV(reader,peek)
#define Next() \
    (W_CALLV(reader,getc),1)

static struct WjsonValue* parse_string(struct Wreader* reader);
static struct WjsonValue* parse_int(struct Wreader* reader);
static struct WjsonValue* parse_object(struct Wreader* reader);
static struct WjsonValue* parse_array(struct Wreader* reader);

static struct WjsonValue*
parse_value(struct Wreader* reader)
{
    char ch;
    if (Peek() == '\"')
        return parse_string(reader);
    else if (Peek() == '{')
        return parse_object(reader);
    else if (Peek() == '[')
        return parse_array(reader);
    else
        return parse_int(reader);
}

static struct WjsonValue*
parse_object(struct Wreader* reader)
{
    struct WjsonObject* obj = W_NEW(WjsonObject);
    char ch;
    Accept('{');
    do {
        struct WjsonValueString* field = (void*) parse_string(reader);
        Accept(':');
        struct WjsonValue* value = parse_value(reader);
        W_CALL(obj,add_member)(field->value, value);

    } while (Peek() == ',' && Next());
    Accept('}');
    return W_OBJECT_AS(obj,WjsonValue);
}

static struct WjsonValue*
parse_array(struct Wreader* reader)
{
printf("ARRAY\n");
}

static struct WjsonValue*
parse_string(struct Wreader* reader)
{
    char buf[256]={0};
    size_t pos=0;
    char ch = W_CALLV(reader,getc);
    if (ch != '\"')
        return NULL;
    while (W_CALLV(reader,peek) != '\"')
        buf[pos++] = W_CALLV(reader,getc);
    W_CALLV(reader,getc);
printf("STRING\n");
    return W_NEW(WjsonValueString, .value = strdup(buf));
}

static struct WjsonValue*
parse_int(struct Wreader* reader)
{
    char buf[256]={0};
    char ch;
    size_t pos = 0;
    while (isdigit(ch = W_CALLV(reader,getc)))
        buf[pos++] = ch;
printf("INT\n");
    return W_NEW(WjsonValueInt, .value = atoi(buf));
}

M__parse
{
    char ch = W_CALLV(reader,peek);
printf("ch='%c'\n", ch);
    if (ch == '{')
        self->value = parse_object(reader);
    else if (ch == '[')
        self->value = parse_array(reader);
    else if (ch == '\"')
        self->value = parse_string(reader);
    else
        self->value = parse_int(reader);
}

METHOD(WjsonDocument,public,int,write,(struct Wwriter* writer))
{
    W_CALL(self->value,write)(writer);
}

#endif

