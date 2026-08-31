#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* createNode(int data){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
     if (newnode==NULL){
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    newnode->data=data;
    newnode-> next=NULL;
    return newnode; 
};
void insertatfirst(struct Node** head, int data){
struct Node* newnode = createNode(data);
newnode->next=*head;
*head=newnode;
}
void insertatlast(struct Node** head, int data){
    struct Node* newnode = createNode(data);
    if(*head==NULL){
        *head=newnode;
        return ;
    }
    struct Node* temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}
void insert(struct Node** head,int data,int position){
    struct Node* newnode= createNode(data);
    if(position==0){
     insertatfirst(head,data);
     return;
    }
    struct Node*temp =*head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
}
newnode->next=temp->next;
temp->next=newnode;}
void print(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main(){
    struct Node* head=NULL;
    insertatfirst(&head,80);
     insertatlast(&head,60);
    
    insert(&head,90,2);
    
    printf("linked list after addingyour given data");
    print(head);
}