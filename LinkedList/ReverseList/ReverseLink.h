//
// Created by 周龙 on 2021/11/28.
//

#ifndef REVERSELINK_REVERSELINK_H
#define REVERSELINK_REVERSELINK_H

/*
 * 借助Pre、Node、Next三个指针在移动的过程中完成链表的反转
 * 其中在进行K个反转时需要判断K的合法性、合理性
 * 在K个反转时实际上要完成k-1次反转，因为首个节点（Pre）已经默认是反转过的了
 * 同时在循环结束后应该做node->next = Pre 的操作
 * 注意边界条件是反转链表的关键所在
 */


#include <stdio.h>
#include <stdlib.h>
typedef struct list{
    int data;
    struct list *next;
}node,*List;

List Initial();

void Insert(List list,int data);

void Delete(List list,int data);

void Traverse(List list);

void Reverse(List list);//只在函数定义时有用？

void Reverse_K(List list,int k);//反转链表中的k个节点


#endif //REVERSELINK_REVERSELINK_H
