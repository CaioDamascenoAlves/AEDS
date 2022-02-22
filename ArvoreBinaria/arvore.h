#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED


typedef struct item{
    int chave;
}TItem;

typedef struct celula{
    TItem item;
    struct celula *pai;
    struct celula *esq;
    struct celula *dir;
    struct celula*prox;
}TCelula;

typedef struct arvore{
    TCelula *raiz;
}TArvore;

typedef struct pilha{
    TCelula * fundo;
    TCelula *topo;
    int tamanho;
}TPilha;

void Iniciar(TCelula **no);
TCelula *criaNo(TItem Item);
void Inserir(TCelula **x, TCelula *pai, TItem Item);
TCelula* Pesquisar(TCelula *x, TItem Item);
void Central(TCelula *x);
void Central_Iterativa(TCelula *x);
void PreOrdem(TCelula *x);
void PreOrdem_Iterativa(TCelula *x);
void PosOrdem(TCelula *x);
void PosOrdem_Iterativo(TCelula *x);
void Tree_Search(TCelula *x);

void PercursoAlternativo(TCelula *x);
TCelula* Minimo(TCelula *x);
TCelula* Maximo(TCelula *x);
TCelula* Sucessor(TCelula *x);
TCelula* Predecessor(TCelula *x);
void Transplante(TArvore *Arvore, TCelula **u, TCelula **v);
void Retirar(TArvore *Arvore, TCelula **z);
// cabecalho Pilha
void FPVazia(TPilha *Pilha);
int Vazia(TPilha Pilha);
void Empilhar(TItem x,TPilha *Pilha);
void Desempilhar(TPilha *Pilha,TItem *Item);
void Imprimir(TPilha *Pilha);
void Liberar(TPilha *Pilha);

#endif // ARVORE_H_INCLUDED
