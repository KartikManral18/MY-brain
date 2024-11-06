#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
}*first=NULL;
void create(int a[],int n){
    struct node* t,*last;
    first=(struct node*)malloc(sizeof(struct node));
    first->data=a[0];
    first->next=first->prev=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=(struct node*)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        
        last=t;
    }
}
int count(struct node *p){
    int count =0;
    while(p){
        count++;
        p=p->next;
    }
    return count;
}
void insertatpos(struct node* p,int pos,int x){
    struct node*t;
     t=(struct node*)malloc(sizeof(struct node));
        t->data=x;
     if(pos <0 ||pos >count(p))
        return ;
    if(pos==0){
        t->next=first;
        t->prev =NULL;
        first->prev=t;
        first =t;
    }
    else{
        for(int i=0;i<pos-1;i++){
            p=p->next;
        }
        t->prev=p;
        t->next=p->next;
        if(p->next)p->next->prev=t;
        p->next=t;
    }
}
void deleteanode(struct node *p,int pos){
    struct node* q;
    int x=-1,i;
    if(pos<1 || pos>count(p))
        return;
    if(pos==1){
        q=first;
        first=first->next;
        if(first)first->prev=NULL;
        free (q);
    }
    else{
        for(i =0;i<pos-1;i++)
            p=p->next;
        p->prev->next=p->next;
        if(p->next)p->next->prev=p->prev;
        x=p->data;
        free(p);
    }
}

void display(struct node* p){
    while(p){
        printf("%d\t",p->data);
        p=p->next;
    }
    
}
int main(){
    int a[]={1,2,3,4,5,6,7,8,9,10};
    create(a,10);
    display(first);
    printf("\n");
     insertatpos(first,5,20);
     display(first);
     printf("\n");
    deleteanode(first,5);
     display(first);
return 0;
}
