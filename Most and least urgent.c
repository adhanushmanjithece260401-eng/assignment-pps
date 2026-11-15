#include <stdio.h>

int main() {
    int n, i, s, count = 0;
    int max = 0, min = 0;
    int maxFirst = 0, maxLast = 0, minFirst = 0, minLast = 0;

    printf("How many cases? ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("Score %d: ", i);
        scanf("%d", &s);

        if (s == 9999)              /* excluded, skip it */
            continue;

        if (count == 0) {           /* first valid score */
            max = s;  min = s;
            maxFirst = maxLast = i;
            minFirst = minLast = i;
        } else {
            if (s > max) { max = s; maxFirst = i; maxLast = i; }
            else if (s == max) { maxLast = i; }

            if (s < min) { min = s; minFirst = i; minLast = i; }
            else if (s == min) { minLast = i; }
        }
        count++;
    }

    if (count == 0)
        printf("No valid case.\n");
    else {
        printf("Most urgent  = %d (first at %d, last at %d)\n", max, maxFirst, maxLast);
        printf("Least urgent = %d (first at %d, last at %d)\n", min, minFirst, minLast);
    }
    return 0;
}
