#include <stdio.h>

int main() {
    int a = 0, i;
    for (i = 0; i < 5; i++)
        a++;
    while (a > 0)
        a--;
    do
        a++;
    while (a < 5);
    printf("%d\n", a);
    return 0;
}

/*
0000000000400506 <main>:
  400506:	55                   	push   rbp
  400507:	48 89 e5             	mov    rbp,rsp
  40050a:	48 83 ec 10          	sub    rsp,0x10
  40050e:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [rbp-0x4],0x0
  400515:	c7 45 f8 00 00 00 00 	mov    DWORD PTR [rbp-0x8],0x0
  40051c:	eb 08                	jmp    400526 <main+0x20>
  40051e:	83 45 fc 01          	add    DWORD PTR [rbp-0x4],0x1
  400522:	83 45 f8 01          	add    DWORD PTR [rbp-0x8],0x1
  400526:	83 7d f8 04          	cmp    DWORD PTR [rbp-0x8],0x4
  40052a:	7e f2                	jle    40051e <main+0x18>
  40052c:	eb 04                	jmp    400532 <main+0x2c>
  40052e:	83 6d fc 01          	sub    DWORD PTR [rbp-0x4],0x1
  400532:	83 7d fc 00          	cmp    DWORD PTR [rbp-0x4],0x0
  400536:	7f f6                	jg     40052e <main+0x28>
  400538:	83 45 fc 01          	add    DWORD PTR [rbp-0x4],0x1
  40053c:	83 7d fc 04          	cmp    DWORD PTR [rbp-0x4],0x4
  400540:	7e f6                	jle    400538 <main+0x32>
  400542:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
  400545:	89 c6                	mov    esi,eax
  400547:	bf e4 05 40 00       	mov    edi,0x4005e4
  40054c:	b8 00 00 00 00       	mov    eax,0x0
  400551:	e8 8a fe ff ff       	call   4003e0 <printf@plt>
  400556:	b8 00 00 00 00       	mov    eax,0x0
  40055b:	c9                   	leave  
  40055c:	c3                   	ret    
  40055d:	0f 1f 00             	nop    DWORD PTR [rax]
*/
