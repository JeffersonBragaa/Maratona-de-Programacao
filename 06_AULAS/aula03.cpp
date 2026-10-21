/*
   Memoria estatica:
   - O tamanho e definido previamente.
   - Exemplos: vetores e matrizes.

   Memoria dinamica - lista encadeada:
   - Cada no armazena um dado e um ponteiro para o proximo no.

       [dado | proximo] -> [dado | proximo] -> [dado | NULL]

   Para adicionar um novo no:
   1. Aloco memoria para ele.
   2. Percorro a lista ate encontrar o ultimo no.
   3. Faço o ultimo no apontar para o novo.
   4. Faço o novo no apontar para NULL.
*/


#include <bits/stdc++.h>


typedef struct sno
{
    int valor;
    struct sno *prox;
    
}no;

void imprimir(no *lista)
{
    while (lista != NULL)
    {
        std::cout << lista->valor << " -> ";
        lista = lista->prox;
    }

    std::cout << "NULL\n";
}

void inserir(no **lista, int valor)
{
    no *novo = new no;
    novo->valor = valor;
    novo->prox = NULL;

    if (*lista == NULL)
    {
        *lista = novo;
        return;
    }

    no *atual = *lista;
    while (atual->prox != NULL)
    {
        atual = atual->prox;
    }

    atual->prox = novo;
}

int main(){
    no *lista = NULL;

    inserir(&lista, 10);
    inserir(&lista, 20);
    inserir(&lista, 30);

    imprimir(lista);

return 0;
}