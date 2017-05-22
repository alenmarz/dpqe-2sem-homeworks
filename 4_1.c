#include <stdio.h>

int main() {
    int a = 1;
    if (a > 0)
        a++;
    else
        a--;
    return 0;
}

/*
00000000004004b6 <main>:
    4004b6: 55                      push   rbp
    4004b7: 48 89 e5                mov    rbp,rsp
    4004ba: c7 45 fc 01 00 00 00    mov    DWORD PTR [rbp-0x4],0x1
    4004c1: 83 7d fc 00             cmp    DWORD PTR [rbp-0x4],0x0
    4004c5: 7e 06                   jle    4004cd <main+0x17>
    4004c7: 83 45 fc 01             add    DWORD PTR [rbp-0x4],0x1
    4004cb: eb 04                   jmp    4004d1 <main+0x1b>
    4004cd: 83 6d fc 01             sub    DWORD PTR [rbp-0x4],0x1
    4004d1: b8 00 00 00 00          mov    eax,0x0
    4004d6: 5d                      pop    rbp
    4004d7: c3                      ret    
    4004d8: 0f 1f 84 00 00 00 00    nop    DWORD PTR [rax+rax*1+0x0]
    4004df: 00 

*/
