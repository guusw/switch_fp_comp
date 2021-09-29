#define OPERATION(_x) _x,
enum Op
{
#include OPERATIONS_H
    Last,
};
#undef OPERATION

#define OPERATION(_x)                                  \
    inline void execOp##_x(size_t &a, size_t &b)       \
    {                                                  \
        a = a + b + size_t(_x);                        \
        b = size_t(_x) * 2;                            \
    }                                                  \
    inline void execOpInline##_x(size_t &a, size_t &b) \
    {                                                  \
        a = a + b + size_t(_x);                        \
        b = size_t(_x) * 2;                            \
    }
#include OPERATIONS_H
#undef OPERATION

TEST_CASE(TEST_NAME)
{

    srand(101);
    Op seq[2 << 14]; // 2<<14 == 32768
    size_t numOps = sizeof(seq) / sizeof(Op);
    for (int i = 0; i < numOps; i++)
    {
        seq[i] = Op(rand() % (size_t)Op::Last);
    }

    size_t a = 0;
    size_t b = 0;

    BENCHMARK("Switch Inline")
    {
        for (int i = 0; i < numOps; i++)
        {
            Op currentOp = seq[i];

            switch (currentOp)
            {
#define OPERATION(_x)           \
    case _x:                    \
        execOpInline##_x(a, b); \
        break;
#include OPERATIONS_H
#undef OPERATION
            default:
                CHECK(false);
                break;
            }
        }
    };

    printf("\n");
    printf("a == %d\n", a);
    printf("b == %d\n", b);

    a = 0;
    b = 0;

    struct OperationInfo
    {
        size_t garabage;
        Op operation;
        void (*exec)(size_t &, size_t &);
    };
    OperationInfo opInfos[size_t(Op::Last)] = {
#define OPERATION(_x) {0, _x, &execOp##_x},
#include OPERATIONS_H
#undef OPERATION
    };

    BENCHMARK("Function table")
    {
        for (int i = 0; i < numOps; i++)
        {
            Op currentOp = seq[i];
            OperationInfo &opInfo = opInfos[size_t(currentOp)];
            opInfo.exec(a, b);
        }
    };

    printf("\n");
    printf("a == %d\n", a);
    printf("b == %d\n", b);
}
