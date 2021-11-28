#include "ReverseLink.h"

List Initial(){
    List list = (List)malloc(sizeof(node));
    list->data=0;
    list->next=NULL;//头节点 记录元素个数
    return list;
}

void Insert(List list,int data){
    //在头部插入
    List NewNode = (List)malloc(sizeof(node));
    NewNode->data = data;
    NewNode->next = list->next;
    list->next = NewNode;
    list->data++;//节点数量增加
}


void Traverse(List list){
    List temp = list->next;//如果list为const则temp不安全
    for(int i=0;i<list->data;i++,temp=temp->next){
        printf("%d ",temp->data);
    }
    putc('\n',stdout);
}

void Reverse(List list){
    if(list->data<=1){
        return;//为空或者无需反转 只有一个元素
    }
    List Pre = list;
    List Node = Pre->next;
    List Next = Node->next;
    while(Next!=NULL){
        Node->next = Pre;
        Pre = Node;
        Node = Next;
        Next = Next->next;
    }
    Node->next = Pre;
    list->next = Node;//更改头节点的指向
}

void Reverse_K(List list,int k){
    if(list->data<=1||k<=0){
        //无需反转
        return;
    }
    //如果反转的节点数比总数多或者相等 直接进行全反转
    if(k>=list->data){
        Reverse(list);
        return;
    }
    else{
        List Pre = list;
        List Node = Pre->next;
        List Next = Node->next;
        //记录反转次数
        for(int i=0;i<k-1;i++){
            Node->next = Pre;
            Pre = Node;
            Node = Next;
            Next = Next->next;
        }
        Node->next = Pre;//!!!!!!!注意循环结束后的状态 实际上是差一个node的指向的
        //由于不是全反转 next不可能为null 而next为原来的头节点的next应该指向的节点
        list->next->next = Next;
        list->next=Node;//更改头节点的指向
    }
}