#include "Catch2/catch_test_macros.hpp"
#include "Catch2/benchmark/catch_benchmark_all.hpp"

#define TEST_NAME "Random indirect call (32 instruction types)"
#define OPERATIONS_H "Operations_32.h"
namespace a32
{
#include "TestTemplate.h"
}
#undef TEST_NAME
#undef OPERATIONS_H

#define TEST_NAME "Random indirect call (64 instruction types)"
#define OPERATIONS_H "Operations_64.h"
namespace a64
{
#include "TestTemplate.h"
}
#undef TEST_NAME
#undef OPERATIONS_H

#define TEST_NAME "Random indirect call (128 instruction types)"
#define OPERATIONS_H "Operations_128.h"
namespace a128
{
#include "TestTemplate.h"
}
#undef TEST_NAME
#undef OPERATIONS_H
