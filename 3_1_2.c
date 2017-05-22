#include <stdio.h>
#define N 10

float sum(float * array) {
    int i;
    float result = 0;
    for (i = 0; i < N; i++)
        result += array[i];
    return result;
}

int main() {
    float arr[N];
    int i;
    for (i = 0; i < N; i++)
        arr[i] = 1.0 + i;
    printf("%f\n", sum(arr) + 1);
    return 0;
}

/*
0000000000400506 <sum>:
  400506:	55                   	push   rbp
  400507:	48 89 e5             	mov    rbp,rsp
  40050a:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi     ;указатель на массив передается через rdi
  40050e:	8b 05 48 01 00 00    	mov    eax,DWORD PTR [rip+0x148]        # 40065c <_IO_stdin_used+0xc>
  400514:	89 45 f8             	mov    DWORD PTR [rbp-0x8],eax
  400517:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [rbp-0x4],0x0
  40051e:	eb 2c                	jmp    40054c <sum+0x46>
  400520:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
  400523:	48 98                	cdqe   
  400525:	48 8d 14 85 00 00 00 	lea    rdx,[rax*4+0x0]
  40052c:	00 
  40052d:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
  400531:	48 01 d0             	add    rax,rdx
  400534:	f3 0f 10 00          	movss  xmm0,DWORD PTR [rax]
  400538:	f3 0f 10 4d f8       	movss  xmm1,DWORD PTR [rbp-0x8]
  40053d:	f3 0f 58 c8          	addss  xmm1,xmm0
  400541:	66 0f 7e c8          	movd   eax,xmm1
  400545:	89 45 f8             	mov    DWORD PTR [rbp-0x8],eax
  400548:	83 45 fc 01          	add    DWORD PTR [rbp-0x4],0x1
  40054c:	83 7d fc 09          	cmp    DWORD PTR [rbp-0x4],0x9
  400550:	7e ce                	jle    400520 <sum+0x1a>
  400552:	8b 45 f8             	mov    eax,DWORD PTR [rbp-0x8]
  400555:	89 45 e4             	mov    DWORD PTR [rbp-0x1c],eax
  400558:	f3 0f 10 45 e4       	movss  xmm0,DWORD PTR [rbp-0x1c]    ;возвращается значение через xmm0
  40055d:	5d                   	pop    rbp
  40055e:	c3                   	ret    

000000000040055f <main>:
  40055f:	55                   	push   rbp
  400560:	48 89 e5             	mov    rbp,rsp
  400563:	48 83 ec 30          	sub    rsp,0x30
  400567:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [rbp-0x4],0x0
  40056e:	eb 2b                	jmp    40059b <main+0x3c>
  400570:	66 0f ef c0          	pxor   xmm0,xmm0
  400574:	f2 0f 2a 45 fc       	cvtsi2sd xmm0,DWORD PTR [rbp-0x4]
  400579:	f2 0f 10 0d df 00 00 	movsd  xmm1,QWORD PTR [rip+0xdf]        # 400660 <_IO_stdin_used+0x10>
  400580:	00 
  400581:	f2 0f 58 c1          	addsd  xmm0,xmm1
  400585:	f2 0f 5a d0          	cvtsd2ss xmm2,xmm0
  400589:	66 0f 7e d0          	movd   eax,xmm2
  40058d:	8b 55 fc             	mov    edx,DWORD PTR [rbp-0x4]
  400590:	48 63 d2             	movsxd rdx,edx
  400593:	89 44 95 d0          	mov    DWORD PTR [rbp+rdx*4-0x30],eax
  400597:	83 45 fc 01          	add    DWORD PTR [rbp-0x4],0x1
  40059b:	83 7d fc 09          	cmp    DWORD PTR [rbp-0x4],0x9
  40059f:	7e cf                	jle    400570 <main+0x11>
  4005a1:	48 8d 45 d0          	lea    rax,[rbp-0x30]
  4005a5:	48 89 c7             	mov    rdi,rax
  4005a8:	e8 59 ff ff ff       	call   400506 <sum>
  4005ad:	f3 0f 5a c0          	cvtss2sd xmm0,xmm0
  4005b1:	bf 58 06 40 00       	mov    edi,0x400658
  4005b6:	b8 01 00 00 00       	mov    eax,0x1
  4005bb:	e8 20 fe ff ff       	call   4003e0 <printf@plt>
  4005c0:	b8 00 00 00 00       	mov    eax,0x0
  4005c5:	c9                   	leave  
  4005c6:	c3                   	ret    
  4005c7:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
  4005ce:	00 00 
*/
