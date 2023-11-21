#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int cmpint(const void *a, const void *b)
{
    const int *pa = a;
    const int *pb = b;

    //return (*pa > *pb) - (*pa < *pb);

    if (*pa < *pb) {
        return -1;
    }
    else if (*pa == *pb) {
        return 0;
    }
    else {
        return 1;
    }
}

struct vector {
    size_t c; // capacità allocata
    int *dati;
    size_t n;
};
void vector_costruttore(struct vector *this) {
    this->c = 1;
    this->dati = malloc(this->c * sizeof(int));
    if (this->dati == NULL) {
        exit(1); // Aiuto!
    }
    this->n = 0;
}
void vector_distruttore(struct vector *this) {
    free(this->dati);
}
void vector_push_back(struct vector *this, int val) {
        if (this->n == this->c) {
            this->c = this->c * 2;
            int *tmp = realloc(this->dati, this->c * sizeof(int));
            if (tmp == NULL) {
                exit(1); // Aiuto!
            }
            this->dati = tmp;
        }
        this->dati[this->n] = val;
        ++this->n;
}
void vector_sort(struct vector *this) {
    qsort(this->dati, this->n, sizeof(int), cmpint);
}
size_t vector_size(const struct vector *this) {
    return this->n;
}
int vector_at(const struct vector *this, size_t pos) {
    assert(pos < this->n);
    return this->dati[pos];
}
struct vector *new_vector(void) {
    struct vector *x = malloc(sizeof(struct vector));
    vector_costruttore(x);
    return x;
}
void delete_vector(struct vector *this) {
    vector_distruttore(this);
    free(this);
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        return 1;
    }

    FILE *fin = fopen(argv[1], "r");
    if (fin == NULL) {
        return 1;
    }

    struct vector *v = new_vector();

    while(1) {
        // Leggi
        int num;
        int res = fscanf(fin,"%d", &num);
        // Controlla
        if (res != 1) {
            break;
        }
        // Usa
        vector_push_back(v, num);
    }
    fclose(fin);

    vector_sort(v);

    FILE *fout = fopen(argv[2], "w");
    if (fout == NULL) {
        return 1;
    }
    for (size_t i = 0; i < vector_size(v); ++i) {
        fprintf(fout, "%d\n", vector_at(v, i));
    }
    fclose(fout);

    delete_vector(v);
    return 0;
}