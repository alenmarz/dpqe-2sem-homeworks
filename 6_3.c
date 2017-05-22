#include <stdio.h>
#include <stdlib.h>
#define N 10

int * array() {
    int * arr = (int*) malloc(sizeof(int) * N);
    int i;
    for (i = 0; i < N; i++)
        arr[i] = i;
    return arr;
}

int main() {
    int n = N;
    int i;
    int * a = array();
    for (i = 0; i < N; i++)
        printf("[%d] = %d\n", i, a[i]);
    return 0;
}

/*
0000000000400546 <array>:
  400546:	55                   	push   rbp
  400547:	48 89 e5             	mov    rbp,rsp
  40054a:	48 83 ec 10          	sub    rsp,0x10
  40054e:	bf 28 00 00 00       	mov    edi,0x28
  400553:	e8 e8 fe ff ff       	call   400440 <malloc@plt>
  400558:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax ;указатель на массив
  40055c:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [rbp-0x4],0x0
  400563:	eb 1d                	jmp    400582 <array+0x3c>
  400565:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
  400568:	48 98                	cdqe   
  40056a:	48 8d 14 85 00 00 00 	lea    rdx,[rax*4+0x0]
  400571:	00 
  400572:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
  400576:	48 01 c2             	add    rdx,rax
  400579:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
  40057c:	89 02                	mov    DWORD PTR [rdx],eax
  40057e:	83 45 fc 01          	add    DWORD PTR [rbp-0x4],0x1
  400582:	83 7d fc 09          	cmp    DWORD PTR [rbp-0x4],0x9
  400586:	7e dd                	jle    400565 <array+0x1f>
  400588:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10] ;указатель передается через rax
  40058c:	c9                   	leave  
  40058d:	c3                   	ret    

000000000040058e <main>:
  40058e:	55                   	push   rbp
  40058f:	48 89 e5             	mov    rbp,rsp
  400592:	48 83 ec 10          	sub    rsp,0x10
  400596:	c7 45 f8 0a 00 00 00 	mov    DWORD PTR [rbp-0x8],0xa
  40059d:	b8 00 00 00 00       	mov    eax,0x0
  4005a2:	e8 9f ff ff ff       	call   400546 <array>
  4005a7:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
  4005ab:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [rbp-0x4],0x0
  4005b2:	eb 2e                	jmp    4005e2 <main+0x54>
  4005b4:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
  4005b7:	48 98                	cdqe   
  4005b9:	48 8d 14 85 00 00 00 	lea    rdx,[rax*4+0x0]
  4005c0:	00 
  4005c1:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
  4005c5:	48 01 d0             	add    rax,rdx
  4005c8:	8b 10                	mov    edx,DWORD PTR [rax]
  4005ca:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
  4005cd:	89 c6                	mov    esi,eax
  4005cf:	bf 74 06 40 00       	mov    edi,0x400674
  4005d4:	b8 00 00 00 00       	mov    eax,0x0
  4005d9:	e8 32 fe ff ff       	call   400410 <printf@plt>
  4005de:	83 45 fc 01          	add    DWORD PTR [rbp-0x4],0x1
  4005e2:	83 7d fc 09          	cmp    DWORD PTR [rbp-0x4],0x9
  4005e6:	7e cc                	jle    4005b4 <main+0x26>
  4005e8:	b8 00 00 00 00       	mov    eax,0x0
  4005ed:	c9                   	leave  
  4005ee:	c3                   	ret    
  4005ef:	90                   	nop
*/
