inline ull mul_mod(ull x,ull y,ull p){
    ull ret = 0;
    __asm__("movq %1,%%rax\n imulq %2\n idivq %3\n":"=d"(ret):"m"(x),"m"(y),"m"(p):"%rax");
    return ret;
}
inline ull mul_mod(ull a,ull b,ull m){
    ull r;
    __asm__("mulq %2\n\tdivq %3":"=&d"(r),"+a"(a):"rm"(b),"rm"(m):"cc");
    return r;
}