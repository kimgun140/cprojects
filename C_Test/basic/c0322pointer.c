#include<stdio.h>

int main()
{
    int urn[5] = {100, 200, 300, 400, 500};
    int* ptr1; // &urn[0] ->&urn[1] ->&urn[0] 100
    int* ptr2; // &urn[2] ->&urn[1] ->&urn[2] 300
    int* ptr3; // &urn[0] + 4 -> &urn[4] 500

    ptr1 = urn;
    ptr2 = &urn[2];
    ptr3 = ptr1 + 4;//1 &urn[4]

    printf("ptr1= %d,ptr2= %d,ptr3= %d\n",*(ptr1),*(ptr2),*(ptr3));
    
    //ptr1 + 4; // 2 계산 출력 500
    printf("ptr1 + 4 = %d\n",*(ptr1 + 4));
    //*(ptr1 +3);//3 계산 출력 &urn[3] 400
    printf("ptr1 + 3 = %d\n",*(ptr1 + 3));
    //ptr1++; //4 &urn[0] 100
    printf("ptr1++ = %d\n",*(ptr1++));
    //ptr2--; //5 &urn[2] 300
    printf("ptr2-- = %d\n",*(ptr2--));
    //--ptr1; //6 &urn[0] 100
    printf("--ptr1 = %d\n",*(--ptr1));
    //++ptr2; //7 &urn[2] 300
    printf("++ptr2 = %d\n",*(++ptr2));
    //ptr2 - ptr1;//8 계산 출력 2
    printf("ptr2 - ptr1 = %d\n",ptr2 - ptr1);
    //ptr3 - 2; //9 계산 출력 &urn[2] 300
    printf("ptr3 - 2 = %d\n", *(ptr3 - 2));
    //연산을 수행후 ptr1, ptr2, ptr3의 주소를 * (역참조) 했을 때의 값은?
    printf("ptr1= %d,ptr2= %d,ptr3= %d\n",*ptr1,*ptr2,*ptr3);
    return 0;
}