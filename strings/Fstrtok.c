/* strtok deneem */
#include <stdio.h>
#include <string.h>
int main()
{
    char a[]="bu gun gunlerden pazartesi :)";
    char *p;
    int i,k=0;
    p=strtok(a," ");
    printf("\n%s",p);
    while(p!=NULL)
    {
        p=strtok(NULL," ");
        printf("\n%s",p);
    }   
    return 0;
}