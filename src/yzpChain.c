#include "yzpChain.h"



 


void cDelete(struct chain* ch){
    chainNode* thisNode=ch->head;
    chainNode* nextNode=ch->head->next;
    for(int i=0;i<ch->len-1;i++){
        free(thisNode);
        thisNode=nextNode;
        nextNode=thisNode->next;
    }
    free(ch);
    return;
}

void cAppend(struct chain* ch, nodeType nValue){
    chainNode* thisNode=ch->head;
    for(int i=0;i<ch->len-1;i++){
        thisNode=thisNode->next;
    }
    if(thisNode->next==NULL){
        thisNode->next=(chainNode*)malloc(sizeof(chainNode));
        thisNode->next->value=nValue;
        thisNode->next->next=NULL;
        ch->len+=1;
    }
    return;
}

nodeType cGetValue(struct chain* ch,int i){
    if(i<ch->len){
        chainNode* thisNode=ch->head;
        for(int j=0;j<i;j++){
            thisNode=thisNode->next;
        }
        return thisNode->value;
    }
    return 0xFFFF;
}

void cDeleteNode(struct chain* ch,int i){
    if(i<ch->len){
        chainNode* thisNode=ch->head;
        chainNode* delNode=ch->head;
        if(i==0){
            thisNode=ch->head->next;
            free(ch->head);
            ch->head=thisNode;
        }
        else{
            for(int j=0;j<i-1;j++){
                thisNode=thisNode->next;
            }
            delNode=thisNode->next;
            thisNode->next=delNode->next;
            free(delNode);
        }
        ch->len-=1;
    }
    return;
}

nodeType* cGetValuePointer(struct chain* ch,int i){
    if(i<ch->len){
        chainNode* thisNode=ch->head;
        for(int j=0;j<i;j++){
            thisNode=thisNode->next;
        }
        return &(thisNode->value);
    }
    return NULL;
}

void cAssignmentValue(struct chain* ch,int i,nodeType nValue){
    if(i<ch->len){
        chainNode* thisNode=ch->head;
        for(int j=0;j<i;j++){
            thisNode=thisNode->next;
        }
        thisNode->value=nValue;
    }
    return;
}

chain *newChain(int mlen){//创建任意长度的链表，用完必须删除。mlen为新建链表的长度
    chain* newchain;
    newchain=malloc(sizeof(chain));

    newchain->AssignmentValue=cAssignmentValue;
    newchain->GetValuePointer=cGetValuePointer;
    newchain->GetValue=cGetValue;
    newchain->deleteChain=cDelete;
    newchain->append=cAppend;
    newchain->deleteNode=cDeleteNode;

    newchain->head=(chainNode*)malloc(sizeof(chainNode));
    chainNode* thisNode=newchain->head;
    for(int i=0;i<mlen-1;i++){
        thisNode->next=(chainNode*)malloc(sizeof(chainNode));
        thisNode->value=0;
        thisNode=thisNode->next;
    }
    thisNode->value=0;
    thisNode->next=NULL;
    newchain->len=mlen;
    return newchain;
}