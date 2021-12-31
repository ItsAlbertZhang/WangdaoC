//
//  5_GetOnce.c
//  5_GetOnce
//
//  Created by 雨轩 on 2021/12/31.
//
//  仅出现一次的数的数量n最大为3.原因:
//  当n=4时,按位运算有可能无法找出出现一次的数.下面构造这样一种情况.
//  对于任意的二进制数x,均可表示为无穷多对数的异或运算结果.
//  假设x为1010.其可以作为0000与1010的异或运算结果,也可以作为1111与0101的运算结果.
//  由于 x^x == 0 恒成立,又异或满足结合律与交换律,因此对于0000,1010,1111,0101这组二进制数,遍历异或的结果为0.
//  将这组数据放入100个数的数组中,原数组为50个数且每个数均出现两次.则这104个数的遍历异或结果为0.
//  此时位运算无法找出任何一个仅出现1次的数,该法失效.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RANDMAX 10000

void GetOnce1(int *arr, int len, int *ret) {
    *ret = 0;
    for(int i = 0; i < len; i++) {
        *ret ^= arr[i];
    }
}

void GetOnce2(int *arr, int len, int *ret) {
    int x = 0;
    for(int i = 0; i < len; i++) {
        x ^= arr[i];
    }
    int y = 1;
    while((x|y) != x) {
        y = y<<1;
    }
    ret[0] = 0;  ret[1] = 0;
    for(int i = 0; i < len; i++) {
        if(arr[i] & y) {
            ret[0] ^= arr[i];
        } else {
            ret[1] ^= arr[i];
        }
    }
}

void GetOnce3(int *arr, int len, int *ret) {
    int x = 0;
    for(int i = 0; i < len; i++) {
        x ^= arr[i];
    }
    int y = 1;
    while((x|y) != x) {
        y = y<<1;
    }
    ret[0] = 0;  ret[1] = 0;
    for(int i = 0; i < len; i++) {
        if(arr[i] & y) {
            ret[0] ^= arr[i];
        } else {
            ret[1] ^= arr[i];
        }
    }
    //GetOnce2 Copy
    //按遍历异或结果的最低位(即y的最低位)进行划分,最低位为1的与num1异或,为0的与num2异或.
    //num1与num2中一定有且仅有一个为某个只出现一次的数.
    //其余两个只出现一次的数与y的按位与结果一定与上面那一个不同.
    int isret0 = 0;
    for(int i = 0; i < len; i++) {
        if(arr[i] == ret[0]) {
            isret0 = 1;
            break;
        }
    }   //num1是否是单个的那个只出现一次的数.
    
    x = 0;
    for(int i = 0; i < len; i++) {
        if(((arr[i] & y) != y) == isret0) {
            //如果isret0是1,则让所有与y在y位不同的数组元素参与异或运算.
            //当arr[i]&y的结果不为其自身时,说明其在y位与y不同.
            x ^= arr[i];
        }
    }
    int z = 1;
    while((x|z) != x) {
        z = z<<1;
    }
    int ret1 = 0, ret2 = 0;
    for(int i = 0; i < len; i++) {
        if((arr[i] & y) != y) {
            if(arr[i] & z) {
                ret1 ^= arr[i];
            } else {
                ret2 ^= arr[i];
            }
        }
    }
    
    if(isret0) {
        ret[1] = ret1;
    } else {
        ret[0] = ret1;
    }
    ret[2] = ret2;
//    if(isnum1) {
//        int x = 0;
//        for(int i = 0; i < len; i++) {
//            if((arr[i] & y) == 0) {
//                x ^= arr[i];
//            }
//        }
//        int z = 1;
//        while((x|z) != x) {
//            z = z<<1;
//        }
//        *num2 = 0; *num3 = 0;
//        for(int i = 0; i < len; i++) {
//            if((arr[i] & y) == 0) {
//                if(arr[i] & z) {
//                    *num2 ^= arr[i];
//                } else {
//                    *num3 ^= arr[i];
//                }
//            }
//        }
//    } else {
//        int x = 0;
//        for(int i = 0; i < len; i++) {
//            if((arr[i] & y)) {
//                x ^= arr[i];
//            }
//        }
//        int z = 1;
//        while((x|z) != x) {
//            z = z<<1;
//        }
//        *num1 = 0; *num3 = 0;
//        for(int i = 0; i < len; i++) {
//            if((arr[i] & y)) {
//                if(arr[i] & z) {
//                    *num1 ^= arr[i];
//                } else {
//                    *num3 ^= arr[i];
//                }
//            }
//        }
//    }
}

int main(int argc, const char * argv[]) {
    int len = 0, n = 0;
    printf("请依次输入数组长度与出现一次的数的个数,中间以空格或回车隔开.\n");
    scanf("%d %d", &len, &n);
    int arr[len];
    for(int i = 0; i < len; i++) {
        arr[i] = 0;
    }
    int beg[n], ret[n];
    printf("请依次输入这些出现一次的数的值, 中间以空格或回车隔开.\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &beg[i]);
    }
    int randnumber;
    // 按时间重新播种
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; ) {
//        srand((unsigned)time(NULL));
        do {
            randnumber = rand() % RANDMAX;
        } while(randnumber < (RANDMAX / 10));
        if(arr[randnumber % len] == 0) {
            arr[randnumber % len] = beg[i];
            i++;
        }
    }
    for(int i = 0; i < (len - n) / 2; i++) {
//        srand((unsigned)time(NULL));
        do {
            randnumber = rand() % RANDMAX;
        } while(randnumber < (RANDMAX / 10));
        int temp = randnumber;
        for(int cnt = 2; cnt > 0; cnt--) {
//            srand((unsigned)time(NULL));
            do {
                randnumber = rand() % RANDMAX;
            } while(randnumber < (RANDMAX / 10));
            while(arr[randnumber % len] != 0) {
                randnumber++;
            }
            arr[randnumber % len] = temp;
        }
    }
    printf("生成的数组如下:\n");
    for(int i = 0; i < len; i++) {
        printf("%5d", arr[i]);
        if((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
    printf("\n");
    switch (n) {
        case 1:
            GetOnce1(arr, len, ret);
            break;
        case 2:
            GetOnce2(arr, len, ret);
            break;
        case 3:
            GetOnce3(arr, len, ret);
            break;
        default:
            break;
    }
    printf("只出现一次的数有:\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t", ret[i]);
    }
    return 0;
}
