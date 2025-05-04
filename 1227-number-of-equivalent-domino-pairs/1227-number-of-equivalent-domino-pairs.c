#include <stdio.h>
#include <stdlib.h>

void sortDomino(int* domino) {
    if (domino[0] > domino[1]) {
        int temp = domino[0];
        domino[0] = domino[1];
        domino[1] = temp;
    }
}

int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize) {
     int** keys = (int**)malloc(dominoesSize * sizeof(int*));
    int* count = (int*)malloc(dominoesSize * sizeof(int));
    int keyCount = 0;
    int maxCount = 0;

    for (int i = 0; i < dominoesSize; i++) {
        sortDomino(dominoes[i]);

        int found = 0;
        for (int key = 0; key < keyCount; key++) {
            if (dominoes[i][0] == keys[key][0] && dominoes[i][1] == keys[key][1]) {
                count[key]++;
                found = 1;
                break;
            }
        }
        
        if (!found) {
            keys[keyCount] = (int*)malloc(2 * sizeof(int));
            keys[keyCount][0] = dominoes[i][0];
            keys[keyCount][1] = dominoes[i][1];
            count[keyCount] = 1;
            keyCount++;
        }
    }

    for (int i = 0; i < keyCount; i++) {
        if (count[i] > 1) {
            maxCount += (count[i] * (count[i] - 1)) / 2;
        }
    }

    for (int i = 0; i < keyCount; i++) {
        free(keys[i]);
    }
    free(keys);
    free(count);

    return maxCount;
}