#include "config.h"
#include "FastMalloc.h"

#include <limits>
#include <string.h>
#include <pthread.h>

namespace WTF {

void* fastAlignedMalloc(size_t alignment, size_t size)
{
    ASSERT_IS_WITHIN_LIMIT(size);
    void* p = nullptr;
    posix_memalign(&p, alignment, size);
    if (UNLIKELY(!p))
        CRASH();
    return p;
}

void* tryFastAlignedMalloc(size_t alignment, size_t size)
{
    FAIL_IF_EXCEEDS_LIMIT(size);
    void* p = nullptr;
    posix_memalign(&p, alignment, size);
    return p;
}

void fastAlignedFree(void* p)
{
    free(p);
}

} // namespace WTF
