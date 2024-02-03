//Joao Victor Alves Cerqueira - 19/03/2022
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100001

typedef struct node{
  char caracter[MAX];
  struct node* next;
}Node;

void add(Node** head, Node** last, int insert, char* string){
  Node* element = malloc(sizeof(Node));
  strcpy(element->caracter, string);
  
  if (*head == NULL) { 
    element->next = NULL;
    *head = element;
    *last = element;
  }
  else if(insert == 0){
    element->next = *head;
    *head = element;
  }
  else{
    element->next = NULL;
    (*last)->next = element;
    *last = element;
  }
}

void show(Node** head){
  Node* element = *head;
  while(element){
    printf("%s", element->caracter);
    element = element->next;
  }
  printf("\n");
}

int main(){
  char line[MAX];
  while(scanf("%s", line)!= EOF){
    Node* head = NULL;
    Node* last = NULL;
    char buffer[MAX] = "";
    int insert = 0;
    
    for(int i = 0; line[i] != '\0'; i++){
      if(line[i]=='['){
        if(strcmp(buffer, "")!= 0){
          add(&head, &last, insert, buffer);
          strcpy(buffer, "");
        }
        insert = 0;
      }
      else if(line[i]==']'){
        if(strcmp(buffer, "")!= 0){
          add(&head, &last, insert, buffer);
          strcpy(buffer, "");
        }
        insert = 1;
      }
      else{
        strncat(buffer,&line[i],1);
      }
    }
    if(strcmp(buffer, "")!= 0){
      add(&head, &last, insert, buffer);
    }
    show(&head);
  }
  return 0;
}