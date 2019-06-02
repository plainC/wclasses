W_TEST_GROUP(Iterator)
W_TEST_GROUP(Iterator: Dynamic Array)

W_TEST(Empty: Begin index=0,
    int* array = NULL;

    struct Witerator* iter = W_DYNAMIC_ARRAY_GET_ITERATOR(array,0);
    int t=1;
    while (W_CALLV(iter,has_next)) {
        size_t size;
        const int* p = W_CALL(iter,get)(&size);
        W_TEST_ASSERT(t == *p, "Value mismatch");
        ++t;

        W_CALLV(iter,next);
    }
    W_TEST_ASSERT(t == 1, "Value mismatch");
)

W_TEST(10 elements: Begin index=0,
    int* array = NULL;
    W_DYNAMIC_ARRAY_PUSH(array, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

    struct Witerator* iter = W_DYNAMIC_ARRAY_GET_ITERATOR(array,0);
    int t=1;
    while (W_CALLV(iter,has_next)) {
        size_t size;
        const int* p = W_CALL(iter,get)(&size);
        W_TEST_ASSERT(t == *p, "Value mismatch");
        ++t;

        W_CALLV(iter,next);
    }
    W_TEST_ASSERT(t == 11, "Value mismatch");
)

W_TEST(10 elements: Begin index=5,
    int* array = NULL;
    W_DYNAMIC_ARRAY_PUSH(array, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

    struct Witerator* iter = W_DYNAMIC_ARRAY_GET_ITERATOR(array,5);
    int t=6;
    while (W_CALLV(iter,has_next)) {
        size_t size;
        const int* p = W_CALL(iter,get)(&size);
        W_TEST_ASSERT(t == *p, "Value mismatch");
        ++t;

        W_CALLV(iter,next);
    }
    W_TEST_ASSERT(t == 11, "Value mismatch");
)

W_TEST(10 elements: Begin index=11,
    int* array = NULL;
    W_DYNAMIC_ARRAY_PUSH(array, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

    struct Witerator* iter = W_DYNAMIC_ARRAY_GET_ITERATOR(array,11);
    int t=1;
    while (W_CALLV(iter,has_next)) {
        size_t size;
        const int* p = W_CALL(iter,get)(&size);
        W_TEST_ASSERT(t == *p, "Value mismatch");
        ++t;

        W_CALLV(iter,next);
    }
    W_TEST_ASSERT(t == 1, "Value mismatch");
)
