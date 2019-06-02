W_TEST_GROUP(WjsonValue)

W_TEST(WjsonValueInt,
    struct WjsonValue* v = W_NEW(WjsonValueInt, .value = 42);

    char buffer[32];
    struct Wwriter* writer = W_NEW(WwriterMemory, .ptr = buffer, .size=32);
    W_TEST_ASSERT(0 == W_CALL(v,write)(writer), "Unable to write");
    W_TEST_ASSERT(0 == strcmp(buffer, "42"), "string does not match");
)

W_TEST(WjsonValueFloat,
    struct WjsonValue* v = W_NEW(WjsonValueFloat, .value = 3.14);

    char buffer[32];
    struct Wwriter* writer = W_NEW(WwriterMemory, .ptr = buffer, .size=32);
    W_TEST_ASSERT(0 == W_CALL(v,write)(writer), "Unable to write");
    W_TEST_ASSERT(0 == strcmp(buffer, "3.14"), "string does not match");
)

W_TEST(WjsonValueBool,
    struct WjsonValue* f = W_NEW(WjsonValueBool, .value = 0);
    struct WjsonValue* t = W_NEW(WjsonValueBool, .value = 1);

    char buffer[32];
    struct Wwriter* writer = W_NEW(WwriterMemory, .ptr = buffer, .size=32);
    W_TEST_ASSERT(0 == W_CALL(t,write)(writer), "Unable to write");
    W_TEST_ASSERT(0 == strcmp(buffer, "true"), "true string does not match");

    W_CALLV(writer,clear);
    W_TEST_ASSERT(0 == W_CALL(f,write)(writer), "Unable to write");
    W_TEST_ASSERT(0 == strcmp(buffer, "false"), "false string does not match");
)

W_TEST(WjsonValueString,
    struct WjsonValue* v = W_NEW(WjsonValueString, .value = "foobar");

    char buffer[32];
    struct Wwriter* writer = W_NEW(WwriterMemory, .ptr = buffer, .size=32);
    W_TEST_ASSERT(0 == W_CALL(v,write)(writer), "Unable to write");
    W_TEST_ASSERT(0 == strcmp(buffer, "\"foobar\""), "string does not match");
)

W_TEST(WjsonObject,
    struct WjsonObject* v = W_NEW(WjsonObject);

    W_CALL(v,add_member)("x", W_NEW(WjsonValueInt, .value = 42));
    W_CALL(v,add_member)("y", W_NEW(WjsonValueInt, .value = 12));

    char buffer[32];
    struct Wwriter* writer = W_NEW(WwriterMemory, .ptr = buffer, .size=32);
    W_TEST_ASSERT(0 == W_CALL(v,write)(writer), "Unable to write");
    W_TEST_ASSERT(0 == strcmp(buffer, "{\"x\":42,\"y\":12}"), "string does not match");
)

