#include <stdio.h>
bool isCircularSentence(char* sentence) {
    if (sentence[0] != sentence[strlen(sentence) - 1])
        return false;
    for (int i = 0; i <= strlen(sentence); i++) {
        if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1])
            return false;
    }
    return true;
}
