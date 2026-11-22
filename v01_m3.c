#include <stdio.h>
#include <string.h>

#define MAX_LEN 1024

/* fgets o'qigan satr oxiridagi '\n' ni olib tashlaydi */
static void remove_newline(char *s) {
    size_t n = strlen(s);
    if (n > 0 && s[n - 1] == '\n') {
        s[n - 1] = '\0';
    }
}

/*
 * in_name faylining har bir qatorini fgets bilan o'qiydi,
 * qatorlar sonini va eng uzun qatorni out_name fayliga fprintf bilan yozadi.
 * Muvaffaqiyatli bo'lsa 0, xatolikda 1 qaytaradi.
 * Faraz: har bir qator MAX_LEN - 1 belgidan oshmaydi.
 */
static int process_file(const char *in_name, const char *out_name) {
    FILE *in = fopen(in_name, "r");
    if (in == NULL) {
        perror(in_name);
        return 1;
    }

    FILE *out = fopen(out_name, "w");
    if (out == NULL) {
        perror(out_name);
        fclose(in);
        return 1;
    }

    char line[MAX_LEN];
    char longest[MAX_LEN] = "";
    size_t longest_len = 0;
    int line_count = 0;

    while (fgets(line, sizeof(line), in) != NULL) {
        remove_newline(line);
        line_count++;

        size_t len = strlen(line);
        if (len > longest_len) {
            longest_len = len;
            strcpy(longest, line);
        }
    }

    fprintf(out, "Qatorlar soni: %d\n", line_count);
    fprintf(out, "Eng uzun qator (%zu belgi): %s\n", longest_len, longest);

    fclose(in);
    fclose(out);
    return 0;
}

int main(void) {
    if (process_file("input.txt", "output.txt") != 0) {
        return 1;
    }
    printf("Natija output.txt fayliga yozildi.\n");
    return 0;
}
