/**
 * Used by cmake in a try_compile() statement
 * to see if capabilities are supported
 * */

#if !__has_feature(capabilities)
#error "Does not support capabilities"
#endif

int main() { return 0; }