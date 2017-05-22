#include <stdio.h>
#define N 10

int sum(int * array) {
    int i;
    int result = 0;
    for (i = 0; i < N; i++)
        result += array[i];
    return result;
}

int main() {
    int arr[N];
    int i;
    for (i = 0; i < N; i++)
        arr[i] = i;
    int Sum = sum(arr);
    return 0;
}

/*
00000000004004b6 <sum>:
  4004b6:	55                   	push   rbp
  4004b7:	48 89 e5             	mov    rbp,rsp
  4004ba:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
  4004be:	c7 45 f8 00 00 00 00 	mov    DWORD PTR [rbp-0x8],0x0
  4004c5:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [rbp-0x4],0x0
  4004cc:	eb 1d                	jmp    4004eb <sum+0x35>
  4004ce:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
  4004d1:	48 98                	cdqe   
  4004d3:	48 8d 14 85 00 00 00 	lea    rdx,[rax*4+0x0]
  4004da:	00 
  4004db:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
  4004df:	48 01 d0             	add    rax,rdx
  4004e2:	8b 00                	mov    eax,DWORD PTR [rax]
  4004e4:	01 45 f8             	add    DWORD PTR [rbp-0x8],eax
  4004e7:	83 45 fc 01          	add    DWORD PTR [rbp-0x4],0x1
  4004eb:	83 7d fc 09          	cmp    DWORD PTR [rbp-0x4],0x9
  4004ef:	7e dd                	jle    4004ce <sum+0x18>
  4004f1:	8b 45 f8             	mov    eax,DWORD PTR [rbp-0x8]  ;значение возвращается через eax
  4004f4:	5d                   	pop    rbp
  4004f5:	c3                   	ret    

00000000004004f6 <main>:
  4004f6:	55                   	push   rbp
  4004f7:	48 89 e5             	mov    rbp,rsp
  4004fa:	48 83 ec 30          	sub    rsp,0x30
  4004fe:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [rbp-0x4],0x0  ;i = 0
  400505:	eb 10                	jmp    400517 <main+0x21>
  400507:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
  40050a:	48 98                	cdqe   
  40050c:	8b 55 fc             	mov    edx,DWORD PTR [rbp-0x4]
  40050f:	89 54 85 d0          	mov    DWORD PTR [rbp+rax*4-0x30],edx
  400513:	83 45 fc 01          	add    DWORD PTR [rbp-0x4],0x1
  400517:	83 7d fc 09          	cmp    DWORD PTR [rbp-0x4],0x9
  40051b:	7e ea                	jle    400507 <main+0x11>
  40051d:	48 8d 45 d0          	lea    rax,[rbp-0x30]           ;указатель на начало массива
  400521:	48 89 c7             	mov    rdi,rax                  ;аргумент передается через rdi
  400524:	e8 8d ff ff ff       	call   4004b6 <sum>
  400529:	89 45 f8             	mov    DWORD PTR [rbp-0x8],eax
  40052c:	b8 00 00 00 00       	mov    eax,0x0
  400531:	c9                   	leave  
  400532:	c3                   	ret    
  400533:	66 2e 0f 1f 84 00 00 	nop    WORD PTR cs:[rax+rax*1+0x0]
  40053a:	00 00 00 
  40053d:	0f 1f 00             	nop    DWORD PTR [rax]

*/
