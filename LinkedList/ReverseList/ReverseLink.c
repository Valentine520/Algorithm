#include "ReverseLink.h"

List Initial(){
    List list = (List)malloc(sizeof(node));
    list->data=0;
    list->next=NULL;//ͷ�ڵ� ��¼Ԫ�ظ���
    return list;
}

void Insert(List list,int data){
    //��ͷ������
    List NewNode = (List)malloc(sizeof(node));
    NewNode->data = data;
    NewNode->next = list->next;
    list->next = NewNode;
    list->data++;//�ڵ���������
}


void Traverse(List list){
    List temp = list->next;//���listΪconst��temp����ȫ
    for(int i=0;i<list->data;i++,temp=temp->next){
        printf("%d ",temp->data);
    }
    putc('\n',stdout);
}

void Reverse(List list){
    if(list->data<=1){
        return;//Ϊ�ջ������跴ת ֻ��һ��Ԫ��
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
    list->next = Node;//����ͷ�ڵ��ָ��
}

void Reverse_K(List list,int k){
    if(list->data<=1||k<=0){
        //���跴ת
        return;
    }
    //�����ת�Ľڵ����������������� ֱ�ӽ���ȫ��ת
    if(k>=list->data){
        Reverse(list);
        return;
    }
    else{
        List Pre = list;
        List Node = Pre->next;
        List Next = Node->next;
        //��¼��ת����
        for(int i=0;i<k-1;i++){
            Node->next = Pre;
            Pre = Node;
            Node = Next;
            Next = Next->next;
        }
        Node->next = Pre;//!!!!!!!ע��ѭ���������״̬ ʵ�����ǲ�һ��node��ָ���
        //���ڲ���ȫ��ת next������Ϊnull ��nextΪԭ����ͷ�ڵ��nextӦ��ָ��Ľڵ�
        list->next->next = Next;
        list->next=Node;//����ͷ�ڵ��ָ��
    }
}