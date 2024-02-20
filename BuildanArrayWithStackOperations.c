#include <stdlib.h>
#include <string.h>

char** buildArray(int* target, int targetSize, int n, int* returnSize) {
    char** targetArray = (char**)malloc(2 * n * sizeof(char*));

    size_t current = -1;
    size_t internalCounter = 1;
    for (size_t i = 0; i < targetSize; i++) {
        while (internalCounter < target[i]) {
            current++;
            targetArray[current] = (char*)calloc(5, sizeof(char));
            strncpy(targetArray[current], "Push", 4);

            current++;
            targetArray[current] = (char*)calloc(5, sizeof(char));
            strncpy(targetArray[current], "Pop", 4);

            internalCounter++;
        }

        current++;
        targetArray[current] = (char*)calloc(5, sizeof(char));
        strncpy(targetArray[current], "Push", 4);

        if (target[targetSize - 1] == internalCounter) {
            break;
        }

        internalCounter++;
    }

    *returnSize = current + 1;
    return targetArray;
}
