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

    vector() : vector(0) {}
    vector(size_t size) {
        c = size + 1;
        dati = new int[c];
        n = size;
    }
    // Costruttore di copia
    vector(const vector &other) : vector(other.n) {
        for (size_t i = 0; i < n; ++i) {
            dati[i] = other.dati[i];
        }
    }
    // Costruttore di move
    vector(vector &&other) noexcept { 
        c = other.c;
        n = other.n;
        dati = other.dati;
        other.dati = nullptr;
    }
    // Operatore assegnamento
    vector& operator=(const vector &other) {
        if (other.n > c) {
            delete[] dati;
            c = other.n + 1;
            dati = new int[c];
        }
        n = other.n;
        for (size_t i = 0; i < n; ++i) {
            dati[i] = other.dati[i];
        }
        return *this;
    }
    // Operatore move assignment
    vector& operator=(vector &&other) {
        delete[] dati;
        c = other.c;
        n = other.n;
        dati = other.dati;
        other.dati = nullptr;
        return *this;
    }
    ~vector() {
        delete[] dati;
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

vector leggi_vettore(const char *filename)
{
    vector v;
    FILE *fin = fopen(filename, "r");
    if (fin == NULL) {
        return v;
    }
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
    return v;
}

int main(int argc, char *argv[])
{
    int x = 5;
    int y = 7;
    int z = -2;

    z = (y = x);



    if (argc != 3) {
        return 1;
    }

    vector v;
    v = leggi_vettore(argv[1]); 
    if (v.size() == 0) {
        return 1;
    }

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
