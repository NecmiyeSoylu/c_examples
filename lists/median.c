/* listenin ortanca elemnını kesip başa ve sona ekleyen fonksiyonu yazınız */
#include <stdio.h>
#include <stdlib.h>
struct number
{
    int number;
    struct number *next;
};
typedef struct number num;
num* f(num *head);//şeref konuğumuz
num* find_median(num *head);
num* find_last(num *head);
int numberOf_list(num *head);
void show_list(num *head);
int main()
{
    num *head, *p;
    int n;
    head=(num*)malloc(sizeof(num));
    p=head;
    printf("lşstenin elemanlarını giriniz\ndurdurmak icin -1 giriniz\n");
    while(1)
    {
        scanf("%d",&n);
        if(n!=-1)
        {
            p->next=(num*)malloc(sizeof(num));
            p=p->next;
            p->number=n;
        }
        
        else break;
    }
    p->next=NULL;
    show_list(head->next);  
    head=f(head->next);
    show_list(head);
    return 0;
}
num* f(num *head)
{
    num *p, *first, *last, *q;
    p=find_median(head);
    first=p->next;
    last=p->next;
    p->next=p->next->next;
    first->next=head;
    head=first;
    printf("%d",head->next->number);
    q=find_last(head);
    //q->next=last;
    //q->next->next=NULL;
    printf("%d",head->next->number);
    return head;
}
num* find_median(num* head)
{
    int n, i;
    num *p=head;
    n=numberOf_list(head);
    n=n/2;//ortancadan bir önceki elemanı bulmak istiyorum.
    for(i=1;i<n;i++) p=p->next;
    return p;
}
num* find_last(num *head)
{
    num *p=head;
    while(p->next!=NULL) p=p->next;
    
    return p;
}
int numberOf_list(num *head)
{
    int counter=0;
    num *p=head;
    while(p!=NULL)
    {
        p=p->next;
        counter++;
    }
    return counter;
}
void show_list(num *head)
{
    num *p=head;
    printf("\nliste  ");
    while(p!=NULL)
    {
        printf("%d ",p->number);
        p=p->next;
    }
}