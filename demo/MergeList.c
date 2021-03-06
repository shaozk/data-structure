#include "include\SqList.h"

// void MergeList_Sq(SqList *La, SqList* Lb, SqList *Lc) {
//     // Lc的长度为La与Lb之和
//     Lc->length = La->length + Lb->length;
//     int a = 0, b = 0;
//     for(int i = 0; i < Lc->length; i++){
//         while(a < La->length && b < Lb->length){
//             if(La->data[a] > Lb->data[b]) {
//                 Lc->data[i] = Lb->data[b];
//                 i++;
//                 a++;
//             } else {
//                 Lc->data[i] = La->data[a];
//                 i++;
//                 b++;
//             }
//         }
//         if(a >= La->length - 1) {
//             Lc->data[i] = Lb->data[b];
//             i++;b++;
//         }
//         if(b >= Lb->length - 1) {
//             Lc->data[i] = La->data[a];
//             i++;a++;
//         }

//     }
// }

void main(){
    int aArr[5] = {1,3,5,7,9};
    int bArr[5] = {2,4,6,8,10};
    printf("hello\n");
    // PrintArr(bArr, 5);
    PrintArr(aArr, 5);
    SqList *La = InitList(bArr, 5);
    PrintList(*La);
}