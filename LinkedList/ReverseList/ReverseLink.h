//
// Created by ���� on 2021/11/28.
//

#ifndef REVERSELINK_REVERSELINK_H
#define REVERSELINK_REVERSELINK_H

/*
 * ����Pre��Node��Next����ָ�����ƶ��Ĺ������������ķ�ת
 * �����ڽ���K����תʱ��Ҫ�ж�K�ĺϷ��ԡ�������
 * ��K����תʱʵ����Ҫ���k-1�η�ת����Ϊ�׸��ڵ㣨Pre���Ѿ�Ĭ���Ƿ�ת������
 * ͬʱ��ѭ��������Ӧ����node->next = Pre �Ĳ���
 * ע��߽������Ƿ�ת����Ĺؼ�����
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

void Reverse(List list);//ֻ�ں�������ʱ���ã�

void Reverse_K(List list,int k);//��ת�����е�k���ڵ�


#endif //REVERSELINK_REVERSELINK_H
