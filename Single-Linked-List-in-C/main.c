#include <stdio.h>


struct node{
//Data Part of node
 int data;
//Pointer part of node
 struct node*next;
};


//Function for new Node
struct node* createnode(int data){
  struct node*Newnode = (struct node*)malloc(sizeof(struct  node));
  Newnode -> data = data;
  Newnode -> next = NULL;
  return Newnode;
}

//Insert at begining
void insertbeg(struct Node** head, int data){
  struct node* Newnode = createnode(data);
  Newnode -> next = *head;
  *head = Newnode;
}

//Insert After Given
void insertaf(struct node* prevnode, int data){
  if (prevnode == NULL){
    printf("No list \n");
    return;
  }
  struct node* Newnode =  createnode(data);
  Newnode -> next = prevnode -> next;
  prevnode -> next = Newnode;
}

//Insert at end
void insertend(struct node** head, int data){
  struct node* Newnode = createnode(data);
  if (*head == NULL){
    *head = Newnode;
    return;
  }
  struct node* lastnode = *head;
  while (lastnode -> next != NULL){
    lastnode = lastnode -> next;
  }
  lastnode -> next = Newnode;
}

//Delete Node from given Key (key is data)
void deletenode(struct node** head, int key){
  struct node*temp = *head;
  struct node*prev = NULL;

  if (temp != NULL && temp ->data == key){
    *head = temp -> next;
    free(temp);
    return;
  }
  while (temp != NULL && temp -> data != key){
    prev = temp;
    temp = temp -> next;
  }

  if(temp == NULL){
    printf("Node with that key not found \n", key);
    return;
  }

  prev -> next = temp -> next;
  free(temp);
}

//Print list
void printlist(struct node* head){
  struct node* temp = head;
  while (temp != NULL){
    printf("%d ", temp -> data);
    temp = temp -> next;
  }
  printf("\n");
}

int main(void) {
  struct node* head = NULL;

  //Element in List
  insertend(&head, 10);
  insertbeg(&head, 5);
  insertend(&head, 20);
  insertaf(head, 15);

  printf("List:");
  printlist(head);

  deletenode(&head, 10);

  printf("List:");
  printlist(head);

  //memory cleanup free all node
  while (head != NULL){
    struct node* temp = head;
    head = head -> next;
    free(temp);
  }
  return 0;
}