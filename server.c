#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main() {
    FILE* csvFile = fopen("²Ä¤@²Õ.csv", "r"); // Replace "example.csv" with your CSV file name

    if (csvFile == NULL) {
        perror("Error opening file");
        return 1;
    }

    char currentLine[MAX_LINE_LENGTH];

    // Read and process the CSV file line by line
    while (fgets(currentLine, sizeof(currentLine), csvFile) != NULL) {
        // Tokenize the current line using a comma as the delimiter
        char* token = strtok(currentLine, ",");

        // Process each token (column) in the current line
        while (token != NULL) {
            // Do something with the token (e.g., print it)
            printf("%s", token);

            // Get the next token
            token = strtok(NULL, ",");
        }

        // Move to the next line
        printf("\n");
    }

    fclose(csvFile);

    return 0;
}
