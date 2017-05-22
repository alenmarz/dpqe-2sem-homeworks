#include <stdio.h>



int main() {
	float a = 1.0;
	int b = 1;
	char c = '1';
	double d = 1.0;
	return 0;
}

/*
00000000004004b6 <main>:
  4004b6:	55                   	push   rbp
  4004b7:	48 89 e5             	mov    rbp,rsp
  4004ba:	8b 05 b4 00 00 00    	mov    eax,DWORD PTR [rip+0xb4]        # 400574 <_IO_stdin_used+0x4>
  4004c0:	89 45 fc             	mov    DWORD PTR [rbp-0x4],eax
  4004c3:	c7 45 f8 01 00 00 00 	mov    DWORD PTR [rbp-0x8],0x1
  4004ca:	c6 45 f7 31          	mov    BYTE PTR [rbp-0x9],0x31
  4004ce:	48 b8 00 00 00 00 00 	movabs rax,0x3ff0000000000000
  4004d5:	00 f0 3f 
  4004d8:	48 89 45 e8          	mov    QWORD PTR [rbp-0x18],rax
  4004dc:	b8 00 00 00 00       	mov    eax,0x0
  4004e1:	5d                   	pop    rbp
  4004e2:	c3                   	ret    
  4004e3:	66 2e 0f 1f 84 00 00 	nop    WORD PTR cs:[rax+rax*1+0x0]
  4004ea:	00 00 00 
  4004ed:	0f 1f 00             	nop    DWORD PTR [rax]
*/
