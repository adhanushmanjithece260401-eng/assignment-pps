#include <stdio.h>

/* returns 0=GREEN 1=AMBER 2=RED 3=INDETERMINATE 4=INVALID */
int classify(int o, int p) {
    if ((o != -1 && (o < 0 || o > 100)) || (p != -1 && (p < 0 || p > 300)))
        return 4;                               /* invalid value */
    if (o == -1 && p == -1)
        return 3;                               /* unreadable pair */
    if ((o != -1 && o < 90) || (p != -1 && p > 130))
        return 2;                               /* red first */
    if ((o != -1 && o < 95) || (p != -1 && p > 110))
        return 1;                               /* then amber */
    if (o != -1 && p != -1)
        return 0;                               /* green needs both readings */
    return 3;
}

int main() {
    int shifts, n, s, i, o, p, c;
    int run, best, reds;

    printf("Number of shifts: ");
    scanf("%d", &shifts);

    for (s = 1; s <= shifts; s++) {
        printf("Shift %d - number of records: ", s);
        scanf("%d", &n);
        run = 0; best = 0; reds = 0;

        for (i = 1; i <= n; i++) {
            printf("Oxygen and pulse: ");
            scanf("%d %d", &o, &p);
            c = classify(o, p);

            if (c == 4) {
                printf("  Invalid record, ignored\n");
                continue;                       /* counts do not change */
            }
            if (c == 2) {
                printf("  RED\n");
                reds++; run++;
                if (run > best) best = run;
            } else {
                if (c == 1) printf("  AMBER\n");
                else if (c == 0) printf("  GREEN\n");
                else printf("  INDETERMINATE\n");
                run = 0;                        /* streak broken */
            }
        }
        printf("Shift %d: total red = %d, longest red streak = %d\n", s, reds, best);
    }
    return 0;
}
