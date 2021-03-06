#include "include\SqList.h"

/**
 * 顺序表的合并
 * 算法步骤：
 * 1.创建一个表长为m+n的空表Lc
 * 2.
 * @param La
 * @param Lb
 * @param Lc
 * @return
 */
Status MergeList_Sq(SqList *La, SqList* Lb, SqList *Lc) {
     // Lc的长度为La与Lb之和
     Lc->length = La->length + Lb->length;
     int a = 0, b = 0;
     for(int i = 0; i < Lc->length; i++){
         while(a < La->length && b < Lb->length){
             if(La->data[a] > Lb->data[b]) {
                 Lc->data[i] = Lb->data[b];
                 i++;
                 a++;
             } else {
                 Lc->data[i] = La->data[a];
                 i++;
                 b++;
             }
         }
         if(a >= La->length - 1) {
             Lc->data[i] = Lb->data[b];
             i++;b++;
         }
         if(b >= Lb->length - 1) {
             Lc->data[i] = La->data[a];
             i++;a++;
         }
     }
     return TRUE;
}

int main(){
    int aArr[5] = {1,3,5,7,9};
    int bArr[5] = {2,4,6,8,10};
    SqList *La = InitList(), *Lb = InitList(), *Lc = InitList();
    for(int i = 0; i < 5; i++) {
        La->data[i] = aArr[i]; La->length++;
        Lb->data[i] = bArr[i]; Lb->length++;
    }
    printf("a"); PrintList(La);
    printf("b"); PrintList(Lb);

    //
    MergeList_Sq(La, Lb, Lc);
    printf("c"); PrintList(Lc);
    return 0;
}