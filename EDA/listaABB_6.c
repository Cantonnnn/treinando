//sem main
typedef struct no {
    int chave;
    int posicao;
    struct no *esq;
    struct no *dir;
} No;

//a)
int contador = 1;

inserirPosicoes(raiz, &contador);

void inserirPosicoes(No *raiz, int *contador)
{
    if (raiz == NULL)
        return;

    inserirPosicoes(raiz->esq, contador);

    raiz->posicao = *contador;
    (*contador)++;

    inserirPosicoes(raiz->dir, contador);
}

//b)

No *buscarPosicao(No *raiz, int posicao)
{
    if (raiz == NULL)
        return NULL;

    if (raiz->posicao == posicao)
        return raiz;

    No *resultado;

    resultado = buscarPosicao(raiz->esq, posicao);

    if (resultado != NULL)
        return resultado;

    return buscarPosicao(raiz->dir, posicao);
}