#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#define MAX 100

typedef struct{
    int codigo;
    char nome[50];
    char genero[20];
} Livro;

typedef struct{
    Livro livros[MAX];
    int tam;
} Lista;

void inicializar_lista(Lista *ptr_lista);
int lista_cheia(Lista *ptr_lista);
void inserir_livro(Lista *ptr_lista);
void remover_livro(Lista *ptr_lista, int codigo);
void exibir_lista(Lista *ptr_lista);

#endif