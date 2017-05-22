#include <stdio.h>

int main() {
    int a = 0;
    switch (a) {
        case -1: a--; break;
        case 1: a++; break;
        default: printf("I'm sorry...\n");
    }
    return 0;
}

/*
0000000000400506 <main>:
  400506:	55                   	push   rbp
  400507:	48 89 e5             	mov    rbp,rsp
  40050a:	48 83 ec 10          	sub    rsp,0x10
  40050e:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [rbp-0x4],0x0
  400515:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
  400518:	83 f8 ff             	cmp    eax,0xffffffff
  40051b:	74 07                	je     400524 <main+0x1e>
  40051d:	83 f8 01             	cmp    eax,0x1
  400520:	74 08                	je     40052a <main+0x24>
  400522:	eb 0c                	jmp    400530 <main+0x2a>
  400524:	83 6d fc 01          	sub    DWORD PTR [rbp-0x4],0x1
  400528:	eb 10                	jmp    40053a <main+0x34>
  40052a:	83 45 fc 01          	add    DWORD PTR [rbp-0x4],0x1
  40052e:	eb 0a                	jmp    40053a <main+0x34>
  400530:	bf d4 05 40 00       	mov    edi,0x4005d4
  400535:	e8 a6 fe ff ff       	call   4003e0 <puts@plt>
  40053a:	b8 00 00 00 00       	mov    eax,0x0
  40053f:	c9                   	leave  
  400540:	c3                   	ret    
  400541:	66 2e 0f 1f 84 00 00 	nop    WORD PTR cs:[rax+rax*1+0x0]
  400548:	00 00 00 
  40054b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
*/
