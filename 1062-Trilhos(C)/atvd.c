// Joao Victor Alves Cerqueira - 27/03/2022
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int vagao;
    struct node* next;
}node;

void add(node** head, int num){
   node* element = (node*)malloc(sizeof(node));
   element->vagao = num;
   element->next = *head;
   *head = element;
}

void remover(node** head){
    node* aux = (*head)->next;
    free(*head);
    *head = aux;
}

int main(){
    int qtd_vagoes = 1, aux,vagoes[1001];
    while(qtd_vagoes != 0){
        aux = 0;
        scanf("%d", &qtd_vagoes);
        while(aux == 0 && qtd_vagoes != 0){
            node* head = NULL;
            int num_vagao, maior_num = 0;
            int i, j, k;

            for(k = 0; k < qtd_vagoes; k++){
                scanf("%d", &vagoes[k]);
                if(vagoes[0] == 0){
                    printf("\n");
                    aux = 1;
                    break;
                }
            }

            if(aux == 0){
                for(i = 0;i < qtd_vagoes; i++){
                    num_vagao = vagoes[i];
                    if(head){
                        int compare = head->vagao;
                        if(num_vagao > compare){
                            for(j = maior_num + 1; j <= num_vagao; j++){
                                add(&head, j);
                            }
                            maior_num = num_vagao;
                            remover(&head);
                        }
                        else if(num_vagao == compare){
                            remover(&head);
                        }
                        else{
                            fflush(stdin);
                            break;
                        }
                    }
                    else{
                        for(j = maior_num + 1; j <= num_vagao; j++){
                            add(&head, j);
                        }
                        maior_num = num_vagao;
                        remover(&head);
                    }
                }
                if(!head){
                    printf("Yes\n");
                }
                else{
                    printf("No\n");
                }
            }
            
        }
    }
    return 0;
}