#include <stdio.h>

void init() {
    int a = 1;
    char b = '1';
    float c = 1.0;
}

int main() {
    init;
    return 0;
}

/*
00000000004004b6 <init>:
  4004b6:	55                   	push   rbp
  4004b7:	48 89 e5             	mov    rbp,rsp
  4004ba:	c7 45 fc 01 00 00 00 	mov    DWORD PTR [rbp-0x4],0x1
  4004c1:	c6 45 fb 31          	mov    BYTE PTR [rbp-0x5],0x31
  4004c5:	8b 05 99 00 00 00    	mov    eax,DWORD PTR [rip+0x99]        # 400564 <_IO_stdin_used+0x4>
  4004cb:	89 45 f4             	mov    DWORD PTR [rbp-0xc],eax
  4004ce:	5d                   	pop    rbp
  4004cf:	c3                   	ret
*/
