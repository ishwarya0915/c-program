#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
    char filename[256];
    FILE *fp;
    int c;
    long long chars = 0;
    long long words = 0;
    long long lines = 0;
    int in_word = 0;
    int last_char = 0;

    printf("Enter filename: ");
    if (scanf("%255s", filename) != 1) {
        fprintf(stderr, "No filename provided.\n");
        return 1;
    }

    fp = fopen(filename, "rb"); /* binary mode avoids translations on some systems */
    if (!fp) {
        perror("fopen");
        return 1;
    }

    while ((c = fgetc(fp)) != EOF) {
        chars++;
        if (c == '\n') lines++;
        if (!isspace((unsigned char)c)) {
            if (!in_word) {
                words++;
                in_word = 1;
            }
        } else {
            in_word = 0;
        }
        last_char = c;
    }

    /* If file not empty and last char wasn't newline, count the last line */
    if (chars > 0 && last_char != '\n') lines++;

    fclose(fp);

    printf("Characters: %lld\n", chars);
    printf("Words     : %lld\n", words);
    printf("Lines     : %lld\n", lines);

    return 0;
}
