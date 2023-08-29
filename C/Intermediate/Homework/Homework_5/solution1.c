#include <stdio.h>

unsigned int countOdd(const char fileName[]) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 0;
    }

    unsigned int count = 0;
    int num;
    while (fscanf(file, "%d", &num) == 1) {
        if (num % 2 != 0) {
            count++;
        }
    }

    fclose(file);
    return count;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 0;
    }

    const char *fileName = argv[1];
    unsigned int oddCount = countOdd(fileName);
    printf("Total odd numbers: %u\n", oddCount);
    return 0;
}