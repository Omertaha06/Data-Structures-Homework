#include <stdio.h>
#include <stdlib.h>

 struct n{
    int x;
    struct n *next;
};
typedef struct n node;

//Baþa ekleyen fonksiyon
node *eklebas(node *r,int c){
    node *temp=(node *)malloc(sizeof(node));
    temp->x=c;
    temp->next=r;
    r=temp;
    return r;
};
//Sona ekleyen fonksiyon
node *ekleson(node *r,int c){
    if(r==NULL){
    r=eklebas(r,c);}
    else{
        node * p = r;
        while(p->next != NULL){
            p=p->next;
        }
        node *temp=(node *)malloc(sizeof(node));
        temp->x=c;
        temp->next=p->next;
        p->next=temp;
    }
    return r;
}
//yazdýran fonksiyon
void yaz(node* r){
    while(r!=NULL){
        printf("%d\n",r->x);
        r=r->next;
    }
}

int main(){
    node *root=NULL;
    printf("Lutfen bir sayi giriniz");
    int x;
    scanf("%d",&x);
    while(x != -1){

        if(x%2==0){
            root=ekleson(root,x);
        }
        else{
            root=eklebas(root,x);
        }
    printf("Lutfen bir sayi daha giriniz");
         scanf("%d",&x);
    }
yaz(root);

}
