#include <stdio.h>
#include <stdlib.h>

void createFile(const char *filename) {
    FILE *file = fopen(filename, "w"); 
    if (file == NULL) {
        perror("Error creating file");
        exit(1);
    }
    fprintf(file, "Hello, this is a newly created file.\n");
    fclose(file);
    printf("File created successfully.\n");
}

void readFile(const char *filename) {
    FILE *file = fopen(filename, "r"); 
    if (file == NULL) {
        perror("Error reading file");
        exit(1);
    }
    char ch;
    printf("Reading file contents:\n");
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);
}

void writeFile(const char *filename) {
    FILE *file = fopen(filename, "w"); 
    if (file == NULL) {
        perror("Error writing to file");
        exit(1);
    }
    fprintf(file, "This is new content written into the file.\n");
    fclose(file);
    printf("Data written successfully.\n");
}

void appendFile(const char *filename) {
    FILE *file = fopen(filename, "a"); 
    if (file == NULL) {
        perror("Error appending to file");
        exit(1);
    }
    fprintf(file, "This is appended content.\n");
    fclose(file);
    printf("Data appended successfully.\n");
}

int main() {
    const char *filename = "sample.txt";

    createFile(filename);
    readFile(filename);
    writeFile(filename);
    readFile(filename);
    appendFile(filename);
    readFile(filename);

    return 0;
}
