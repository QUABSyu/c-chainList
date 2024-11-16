#include <stdio.h>
#include <stdlib.h>





#define nodeType int//链表节点主值数据类型

typedef struct chainNode//链表节点定义
{
    /* data */
    nodeType value;
    struct chainNode* next;
}chainNode;

 typedef struct chain//链表对象定义
 {
    /* data */
    chainNode* head;//指向链表头
    int len;//保存链表长度
    nodeType (*GetValue)(struct chain* ch, int i);//获取第i个节点的值
    nodeType* (*GetValuePointer)(struct chain* ch,int i);//获取第i个节点的值的指针
    void (*deleteNode)(struct chain* ch, int i);//删除第i个节点
    void (*AssignmentValue)(struct chain* ch,int i,nodeType nValue);//给第i个节点赋新值
    void (*deleteChain)(struct chain* ch);//删除链表
    void (*append)(struct chain* ch, nodeType nValue);//追加元素
 }chain;


chain *newChain(int mlen);//创建任意长度的链表，用完必须删除。mlen为新建链表的长度



/*int main(int, char**)使用例
{
    chain *ch1=newChain(10);创建长度为10的链表
    ch1->append(ch1,51);追加一个结点值为51
    *ch1->GetValuePointer(ch1,6)=99;获取第六个节点值的指针，并修改值为99
    ch1->AssignmentValue(ch1,7,88);修改第七个节点值为88
    ch1->deleteNode(ch1,8);删除第八个节点
    for(int i=0;i<ch1->len;i++){
        printf("%d\n",ch1->GetValue(ch1,i));遍历链表将值打印出来
    }
    ch1->deleteChain(ch1);删除链表，避免内存泄漏
    return 0;
}*/