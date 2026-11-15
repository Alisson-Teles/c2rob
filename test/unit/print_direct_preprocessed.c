#define FORMAT "argc = %u\n"
#define VALUE 0x10U
extern int printf(const char *fmt, ...);
int main(void) { printf(FORMAT, VALUE); return 0; }
