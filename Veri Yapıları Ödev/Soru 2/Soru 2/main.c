#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int x;
    struct node *next;
}node;

//ekleme yapan fonksiyon
node *ekle(node *r, int x){
    if(r==NULL || r->x>x){
        node *iter=(node*)malloc(sizeof(node));
        iter->x=x;
        iter->next=r;
        r=iter;
    }
    else{
    node *iter=(node*)malloc(sizeof(node));
    node *p=r;
    while (p->next!=NULL && x>p->next->x)
        p=p->next;
    iter->x=x;
    iter->next=p->next;
    p->next=iter;
    }
    return r;
}

//Yazan fonksiyon
void print(node *r){
    node *temp=r;
    while (temp!=NULL){
        printf("%d\n",temp->x);
        temp=temp->next;
    }
}

void main(){
    srand(time(NULL));
    node *root=NULL;
    for (int i = 0; i <100; i++){
        root=ekle(root,rand());
    }
    print(root);
}
