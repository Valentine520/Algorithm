//
// Created by 周龙 on 2021/11/28.
//
#include "ReverseLink.h"
int main() {
    List list = Initial();
    for(int i=10;i>=0;i--){
        Insert(list,i);
    }
    Traverse(list);
    Reverse_K(list,9);
    Traverse(list);
    return 0;
}
