#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_FILA 5

// Struct da peça
typedef struct {
    int id;
    char tipo;
} Peca;

// Struct da fila circular
typedef struct {
    Peca fila[TAM_FILA];
    int inicio;
    int fim;
    int tamanho;
} FilaCircular;

// Gera uma peça aleatória com tipo e ID
Peca gerarPeca(int id) {
    char tipos[] = {'I', 'O', 'T', 'L'};
    Peca nova;
    nova.id = id;
    nova.tipo = tipos[rand() % 4];
    return nova;
}

// Inicializa a fila com 5 peças
void inicializarFila(FilaCircular *f) {
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
    for (int i = 0; i < TAM_FILA; i++) {
        f->fila[f->fim] = gerarPeca(i + 1);
        f->fim = (f->fim + 1) % TAM_FILA;
        f->tamanho++;
    }
}

// Verifica se a fila está cheia
int filaCheia(FilaCircular *f) {
    return f->tamanho == TAM_FILA;
}

// Verifica se a fila está vazia
int filaVazia(FilaCircular *f) {
    return f->tamanho == 0;
}

// Insere uma nova peça no final da fila
void enqueue(FilaCircular *f, int *idCounter) {
    if (filaCheia(f)) {
        printf("Fila cheia! Não é possível inserir nova peça.\n");
        return;
    }
    f->fila[f->fim] = gerarPeca((*idCounter)++);
    f->fim = (f->fim + 1) % TAM_FILA;
    f->tamanho++;
}

// Remove a peça da frente da fila
void dequeue(FilaCircular *f) {
    if (filaVazia(f)) {
        printf("Fila vazia! Não há peça para jogar.\n");
        return;
    }
    printf("Jogando peça %c (ID %d)\n", f->fila[f->inicio].tipo, f->fila[f->inicio].id);
    f->inicio = (f->inicio + 1) % TAM_FILA;
    f->tamanho--;
}

// Exibe o estado atual da fila
void mostrarFila(FilaCircular *f) {
    printf("\nFila de Peças:\n");
    int idx = f->inicio;
    for (int i = 0; i < f->tamanho; i++) {
        printf("Posição %d: Peça %c (ID %d)\n", i + 1, f->fila[idx].tipo, f->fila[idx].id);
        idx = (idx + 1) % TAM_FILA;
    }
}

// Função principal com menu
int main() {
    // Desafio Tetris Stack
    // Tema 3 - Integração de Fila e Pilha
    // Este código inicial serve como base para o desenvolvimento do sistema de controle de peças.
    // Use as instruções de cada nível para desenvolver o desafio.

    // 🧩 Nível Novato: Fila de Peças Futuras
    //
    // - Crie uma struct Peca com os campos: tipo (char) e id (int).
    // - Implemente uma fila circular com capacidade para 5 peças.
    // - Crie funções como inicializarFila(), enqueue(), dequeue(), filaCheia(), filaVazia().
    // - Cada peça deve ser gerada automaticamente com um tipo aleatório e id sequencial.
    // - Exiba a fila após cada ação com uma função mostrarFila().
    // - Use um menu com opções como:
    //      1 - Jogar peça (remover da frente)
    //      0 - Sair
    // - A cada remoção, insira uma nova peça ao final da fila.

    srand(time(NULL));
    FilaCircular fila;
    int idCounter = TAM_FILA + 1;
    int opcao;

    inicializarFila(&fila);

    do {
        printf("\n--- Menu ---\n");
        printf("1 - Jogar peça\n");
        printf("3 - Visualizar fila\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                dequeue(&fila);
                enqueue(&fila, &idCounter); // Reinsere nova peça
                break;
            case 3:
                mostrarFila(&fila);
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}


