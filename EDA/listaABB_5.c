//sem main
typedef struct no {
    int chave;
    struct no *esq;
    struct no *dir;
} No;

No *sucessor(No *raiz, int x)
{
    No *atual = raiz;
    No *candidato = NULL;

    while (atual != NULL) {

        if (x < atual->chave) {
            candidato = atual;
            atual = atual->esq;
        }
        else if (x > atual->chave) {
            atual = atual->dir;
        }
        else {
            // Encontrou x
            if (atual->dir != NULL) {
                // O sucessor é o menor da subárvore direita
                No *p = atual->dir;

                while (p->esq != NULL)
                    p = p->esq;

                return p;
            }

            // Não tem filho direito.
            // Nesse caso, o candidato é o sucessor.
            return candidato;
        }
    }

    // x não pertence à árvore
    return NULL;
}