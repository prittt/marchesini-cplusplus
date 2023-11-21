#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

int cmpint(const void *a, const void *b)
{
    const int *pa = reinterpret_cast<const int *>(a);
    const int *pb = reinterpret_cast<const int *>(b);

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

    vector() : vector(0) {
        printf("Costruttore di default\n");
    }
    vector(size_t size) {
        printf("Costruttore con parametro size_t size=%zu\n", size);
        c = size + 1;
        dati = reinterpret_cast<int*>(malloc(c * sizeof(int)));
        if (dati == NULL) {
            exit(1); // Aiuto!
        }
        n = size;
    }
    // Costruttore di copia
    vector(const vector &other) : vector(other.n) {
        printf("Costruttore di copia\n");
        memcpy(dati, other.dati, n*sizeof(int));
    }
    // Operatore assegnamento
    void operator=(const vector &other) {
        printf("Operatore assegnamento\n");
        // if (this == &other) { // Check self assignment
        //     return;
        // }
        if (other.n > c) {
            free(dati);
            c = other.n + 1;
            dati = reinterpret_cast<int*>(malloc(c * sizeof(int)));
            if (dati == NULL) {
                exit(1); // Aiuto!
            }
        }
        n = other.n;
        memcpy(dati, other.dati, n*sizeof(int));
    }
    ~vector() {
        printf("Distruttore\n");
        free(dati);
    }
    void push_back(int val) {
        if (n == c) {
            c = c * 2;
            int *tmp = reinterpret_cast<int*>(realloc(dati, c * sizeof(int)));
            if (tmp == NULL) {
                exit(1); // Aiuto!
            }
            dati = tmp;
        }
        dati[n] = val;
        ++n;
    }
    void sort() {
        qsort(dati, n, sizeof(int), cmpint);
    }
    size_t size() const {
        return n;
    }
    int at(size_t pos) const {
        assert(pos < n);
        return dati[pos];
    }
    const int& operator[](size_t pos) const {
        return dati[pos];
    }
    int& operator[](size_t pos) {
        return dati[pos];
    }
};

int main(int argc, char *argv[])
{
    if (argc != 3) {
        return 1;
    }

    FILE *fin = fopen(argv[1], "r");
    if (fin == NULL) {
        return 1;
    }

    vector v; 

    while(1) {
        // Leggi
        int num;
        int res = fscanf(fin,"%d", &num);
        // Controlla
        if (res != 1) {
            break;
        }
        // Usa
        v.push_back(num);
    }
    fclose(fin);

    v.sort();

    FILE *fout = fopen(argv[2], "w");
    if (fout == NULL) {
        return 1;
    }
    for (size_t i = 0; i < v.size(); ++i) {
        fprintf(fout, "%d\n", v[i]);
    }
    fclose(fout);

    return 0;
}
