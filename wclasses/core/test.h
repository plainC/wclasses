W_TEST_GROUP(Wreader)
W_TEST_GROUP(WreaderMemory)

W_TEST(reader,
    char* array = "Foobar";

    struct Wreader* reader = W_NEW(WreaderMemory, .ptr = array, .pos = 0, .size = 6);
    int ch;
    int i=0;
    while ((ch = W_CALLV(reader,getc)) != EOF) {
        W_TEST_ASSERT(ch == array[i++], "No match");
    }

    W_TEST_ASSERT(i==6, "i does not match");
)
