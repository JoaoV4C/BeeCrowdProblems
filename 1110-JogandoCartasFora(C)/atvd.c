// Joao Victor Alves Cerqueira - 24/03/2022
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int card;
    struct node* next;
}node;

void add(node** head, node** last, int num){
    node* element = malloc(sizeof(node));
    element->card = num;
    element->next = NULL;
    if(!*head){
        *head = element;
        *last = element;
    }
    else{
        (*last)->next = element;
        *last = element;
    }
}

int remover(node** head, node** last){
    node* aux = (*head)->next;
    int removed_card = (*head)->card;
    free(*head);
    *head = aux->next;
    (*last)->next = aux;
    *last = aux;
    (*last)->next = NULL;
    return removed_card;
}

int main(void){
    node* head = NULL;
    node* last = NULL;
    int num_cards, removed_card;

    while(scanf("%d", &num_cards) != EOF){
        if(num_cards > 0){
            for(int i = 0; i < num_cards; i++){
                add(&head, &last, i + 1);
            }
            printf("Discarded cards:");
            while(num_cards != 1){
                removed_card = remover(&head, &last);
                if(num_cards == 2){
                    printf(" %d", removed_card);
                }
                else{
                    printf(" %d,", removed_card);
                }
                num_cards--;
            }
            printf("\nRemaining card: %d\n", last->card);
        }
    }
}