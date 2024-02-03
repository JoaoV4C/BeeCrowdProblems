// Joao Victor Alves Cerqueira - 20/03/2022
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100001

typedef struct node{
  char caracter;
  struct node* next;
}Node;

void add(Node** head, Node** last, Node** insert,Node** insert_previous, char c, int* aux){
  Node* element = malloc(sizeof(Node));
  element->caracter = c;
  
  if (*head == NULL){ 
    element->next = NULL;
    *head = element;
    *last = element;
    *insert = *last;
    *aux = 0;
  }
  else if(*aux == 0){
    element->next = NULL;
    (*last)->next = element;
    *last = element;
    *insert = *last;
  }
  else if(*aux == 1){
    element->next = *head;
    *head = element;
    *insert = (*head)->next;
    *insert_previous = *head;
    *aux = 2;
  }
  else{
    element->next = *insert;
    (*insert_previous)->next = element;
    *insert = element->next;
    *insert_previous = element;
  }
}

void show(Node** head){
  Node* element = *head;
  while(element){
    printf("%c", element->caracter);
    element = element->next;
  }
  printf("\n");
}

int main(){
  char line[MAX];
  while(scanf("%s", line)!= EOF){
    Node* head = NULL;
    Node* last = NULL;
    Node* insert_previous = NULL;
    Node* insert = head;
    int aux = 0;
    
    for(int i = 0; line[i] != '\0'; i++){
      if(line[i]=='['){
        insert = head;
        insert_previous = NULL;
        aux = 1;
      }
      else if(line[i]==']'){
        insert = last;
        insert_previous = NULL;
        aux = 0;
      }
      else{
        add(&head, &last, &insert, &insert_previous, line[i], &aux);
      }
    }
    show(&head);
  }
  return 0;
}