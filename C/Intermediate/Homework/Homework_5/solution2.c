#include <stdio.h>
#include <string.h>

unsigned int countMatching(const char fileName[], const char match[]) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 0;
    }

    unsigned int count = 0;
    char line[100]; // Assuming a maximum line length of 100 characters

    while (fgets(line, sizeof(line), file) != NULL) {
        // Remove the trailing newline character, if present
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        if (strcmp(line, match) == 0) {
            count++;
        }
    }

    fclose(file);
    return count;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <file_name> <match_string>\n", argv[0]);
        return 0;
    }

    const char *fileName = argv[1];
    const char *matchString = argv[2];

    unsigned int matchingCount = countMatching(fileName, matchString);
    printf("Total matching strings: %u\n", matchingCount);

    return 0;
}