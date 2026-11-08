#define KIND 2
#define VALUE 4
#undef VALUE
#define VALUE 5
#define SCALE(n) \
    ((n) * VALUE)
#define KEEP_CALL __attribute__((noinline))

#if KIND == 2
KEEP_CALL int pilot_macros(int n) {
    return SCALE(n) + 1;
}
#else
#include "pilot_missing_inactive.h"
#error the inactive branch must not reach the compiler
#endif
