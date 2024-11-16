#include <stdio.h>
#include <stdlib.h>
#include "yzpChain.h"






int main(int, char**)
{
    chain *ch1=newChain(10);
    ch1->append(ch1,51);
    *ch1->GetValuePointer(ch1,6)=99;
    ch1->AssignmentValue(ch1,7,88);
    ch1->deleteNode(ch1,8);
    for(int i=0;i<ch1->len;i++){
        printf("%d\n",ch1->GetValue(ch1,i));
    }
    ch1->deleteChain(ch1);
    while(1);
    return 0;
}
