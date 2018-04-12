//Pat Wongwiset
//nw9ca
//linkedlist.c
//11/15/17

#include <stdio.h>

#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};

int main() {
  int numInput;
  struct node *n = malloc(sizeof(struct node));
  n->data = 0;
  n->next = NULL;
  printf("Enter how many values to input :");
scanf("%d", &numInput);
 int i = 1;
 while(i < numInput + 1){
   int k;
   printf("Enter value %d", i);
   printf(": ");
   scanf("%d",&k);
   struct node *temp = malloc(sizeof(struct node));
   temp->data = k;
   temp->next = n->next;
   n->next = temp;
   i++;
 }
 
 while(n->next != NULL){
   struct node  *temp = malloc(sizeof(struct node));
   struct node  *new_temp = malloc(sizeof(struct node));
   temp = n->next;
   new_temp = temp->next;
   printf("%d", temp->data);
   printf("\n");
   free(temp);
   n->next = new_temp;
 }
 free(n);

 return 0;
}
