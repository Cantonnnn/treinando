//sem main
No *remover(No *raiz, int x)
{
    if (raiz == NULL)
        return NULL;

    if (x < raiz->chave)
    {
        raiz->esq = remover(raiz->esq, x);
    }
    else if (x > raiz->chave)
    {
        raiz->dir = remover(raiz->dir, x);
    }
    else
    {
        // Encontramos o nó

        // Caso 1: não possui filhos
        if (raiz->esq == NULL && raiz->dir == NULL)
        {
            free(raiz);
            return NULL;
        }

        // Caso 2: possui apenas filho direito
        if (raiz->esq == NULL)
        {
            No *temp = raiz->dir;
            free(raiz);
            return temp;
        }

        // Caso 2: possui apenas filho esquerdo
        if (raiz->dir == NULL)
        {
            No *temp = raiz->esq;
            free(raiz);
            return temp;
        }

        // Caso 3: possui dois filhos
        No *temp = raiz->dir;

        while (temp->esq != NULL)
            temp = temp->esq;

        raiz->chave = temp->chave;

        raiz->dir = remover(raiz->dir, temp->chave);
    }

    return raiz;
}