#include <stdio.h>
#include <string.h>
#include "biblioteca.h"

void inicializar_lista(Lista *ptr_lista){
    ptr_lista->tam = 0;
}

int lista_cheia(Lista *ptr_lista){
    return ptr_lista->tam == MAX;
}

void inserir_livro(Lista *ptr_lista){
    if(lista_cheia(ptr_lista)){
        printf("lista cheia\n");
    }
    else{
        Livro novo_livro;

        printf("Digite o codigo do livro:\n");
        scanf("%d", &novo_livro.codigo);
        getchar();

        printf("Digite o nome do livro:\n");
        fgets(novo_livro.nome, 50, stdin);
        strtok(novo_livro.nome, "\n");

        printf("Digite o genero do livro:\n");
        fgets(novo_livro.genero, 20, stdin);
        strtok(novo_livro.genero, "\n");

        ptr_lista->livros[ptr_lista->tam] = novo_livro;
        ptr_lista->tam++;
        printf("%s inserido com sucesso!", novo_livro.nome);
    }
}

void remover_livro(Lista *ptr_lista, int codigo){
    int i, encontrado = 0;
    
    if(ptr_lista->tam == 0){
        printf("lista esta vazia, sem livros para remover");
    }
    
    for(i = 0; i < ptr_lista->tam; i++){
        if(ptr_lista->livros[i].codigo == codigo){
            encontrado = 1;
            break;
        }
    }

    if(encontrado){
        for(int j = i; j < ptr_lista->tam - 1; j++){
            ptr_lista->livros[j] = ptr_lista->livros[j + 1];
        }
        ptr_lista->tam--;
        printf("livro removido com sucesso\n");
    }
    else{
        printf("livro nao encontrado\n");
    }
}

void exibir_lista(Lista *ptr_lista){
    if(ptr_lista->tam == 0){
        printf("a lista esta vazia");
    }
    else{
        printf("=================== listas de livros cadastrados ===================\n");
        for(int i = 0; i < ptr_lista->tam; i++){
            printf("nome do livro: %s\n", ptr_lista->livros[i].nome);
            printf("codigo do livro: %d\n", ptr_lista->livros[i].codigo);
            printf("genero do livro: %s", ptr_lista->livros[i].genero);
            printf("\n");
        }
        printf("=========================== fim da lista ===========================\n");
    }
}

