#include <stdio.h>

/* returns category 0=LOW 1=MEDIUM 2=HIGH, or -1 on failure */
int assess(int score, int *adj, int *valid) {
    int temp, cat;

    if (adj == NULL || valid == NULL)   /* check pointers first */
        return -1;
    if (score < 0 || score > 100)       /* check input */
        return -1;

    temp = score * 3 / 2;               /* intermediate result (local) */

    if (temp < 60) cat = 0;
    else if (temp < 100) cat = 1;
    else if (temp <= 140) cat = 2;
    else return -1;                     /* fails AFTER temp was computed */

    *adj = temp;                        /* update caller only at the end */
    *valid = 1;
    return cat;
}

int main() {
    int score, adj = -777, valid = -1, cat;

    printf("Enter score (0-100): ");
    scanf("%d", &score);

    cat = assess(score, &adj, &valid);

    if (cat == -1)
        printf("Assessment failed. adj = %d, valid = %d (unchanged)\n", adj, valid);
    else
        printf("Category = %d, adjusted score = %d, valid = %d\n", cat, adj, valid);
    return 0;
}
