#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int i_rand(int min, int max) {
    return rand() % (max - min + 1) + min;
}

double d_rand(double min, double max) {
    double r = (double)rand() / RAND_MAX;
    return r * (max - min) + min;
}

struct liczba {
    char point;
    union data {
        int i;
        double d;
    } value;
};

void struct_prn(struct liczba *tab, int n) {
    for (int k = 0; k < n; k++) {
        printf("%c: ", (tab + k)->point);
        if ((tab + k)->point == 'i') {
            printf("%d\n", (tab + k)->value.i);
        }
        else {
            printf("%f\n", (tab + k)->value.d);
        }
    }
}

int cmpr(const void *a, const void *b) {
    struct liczba *el_a = (struct liczba *)a;
    struct liczba *el_b = (struct liczba *)b;
    
    if (el_a->point == el_b->point) {
        if (el_a->point == 'i') {
            return (el_a->value.i - el_b->value.i);
        }
        else {
            return (el_a->value.d > el_b->value.d) - (el_a->value.d < el_b->value.d);
        }
    }
    else if ((el_a->point == 'i') && (el_b->point == 'd')) {
        return -1;
    }
    else {
        return 1;
    }
}

int main(void) {
    srand(time(0));
    int n = i_rand(10, 20);
    struct liczba tab[n];

    for (int k = 0; k < n; k++) {
        int c = i_rand(1, 2);
        if (c == 1) {
            tab[k].point = 'i';
            tab[k].value.i = i_rand(-5, 5);
        }
        else {
            tab[k].point = 'd';
            tab[k].value.d = d_rand(-5, 5);
        }
    }

    struct_prn(tab, n);

    FILE *fp = fopen("C:/tekst/plik.dat", "wb");
    fwrite(tab, sizeof(struct liczba), n, fp);
    fclose(fp);

    FILE *fb = fopen("C:/tekst/plik.dat", "rb");
    fseek(fb, 0, SEEK_END);
    int size_tab = ftell(fb);
    fseek(fb, 0, SEEK_SET);

    printf("size tab: %d, n: %d\n", size_tab, n);
    struct liczba TAB[size_tab / sizeof(struct liczba)];

    for (int i = 0; i < size_tab / sizeof(struct liczba); i++) {
        fread(TAB + i, sizeof(struct liczba), 1, fb);
    }

    fclose(fb);

    struct_prn(TAB, n);

    qsort(TAB, n, sizeof(struct liczba), cmpr);

    printf("\nAfter sorting:\n");
    struct_prn(TAB, n);

    return 0;
}