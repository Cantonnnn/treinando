//sem main
No *busca(No *raiz, int x)
{
    if (raiz == NULL)
        return NULL;

    if (x == raiz->chave)
        return raiz;

    if (x < raiz->chave)
        return busca(raiz->esq, x);

    return busca(raiz->dir, x);
}

No *insere(No *raiz, int x)
{
    if (raiz == NULL)
    {
        No *novo = malloc(sizeof(No));

        novo->chave = x;
        novo->esq = NULL;
        novo->dir = NULL;

        return novo;
    }

    if (x < raiz->chave)
        raiz->esq = insere(raiz->esq, x);

    else if (x > raiz->chave)
        raiz->dir = insere(raiz->dir, x);

    return raiz;
}