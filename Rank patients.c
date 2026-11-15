#include <stdio.h>

int main() {
    int id[40], sev[40], arr[40];
    int n, m = 0, i, j, k, a, b, c, dup, best, t;

    printf("How many records (max 40)? ");
    scanf("%d", &n);
    if (n < 0 || n > 40) { printf("Bad count\n"); return 0; }

    for (i = 0; i < n; i++) {
        printf("ID severity arrival: ");
        scanf("%d %d %d", &a, &b, &c);

        dup = 0;
        for (k = 0; k < m; k++)
            if (id[k] == a) dup = 1;            /* duplicate ID: first one wins */

        if (a > 0 && b >= 0 && b <= 100 && c > 0 && dup == 0) {
            id[m] = a; sev[m] = b; arr[m] = c;
            m++;
        } else {
            printf("  Record rejected\n");
        }
    }

    if (m == 0) { printf("No valid referrals.\n"); return 0; }

    /* selection sort: higher severity first, then earlier arrival */
    for (i = 0; i < m - 1; i++) {
        best = i;
        for (j = i + 1; j < m; j++) {
            if (sev[j] > sev[best] ||
               (sev[j] == sev[best] && arr[j] < arr[best]))
                best = j;
        }
        if (best != i) {                        /* swap ALL three arrays */
            t = id[i];  id[i] = id[best];   id[best] = t;
            t = sev[i]; sev[i] = sev[best]; sev[best] = t;
            t = arr[i]; arr[i] = arr[best]; arr[best] = t;
        }
    }

    for (i = 0; i < m; i++)
        printf("%d. ID %d  severity %d  arrival %d\n", i + 1, id[i], sev[i], arr[i]);
    return 0;
}
