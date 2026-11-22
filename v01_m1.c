#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1024

/* fgets o'qigan satr oxiridagi '\n' ni olib tashlaydi */
static void remove_newline(char *s) {
    size_t n = strlen(s);
    if (n > 0 && s[n - 1] == '\n') {
        s[n - 1] = '\0';
    }
}

/* Satrdagi unli harflar (a, e, i, o, u - katta va kichik) sonini qaytaradi */
static int count_vowels(const char *s) {
    int count = 0;
    for (; *s != '\0'; s++) {
        if (isalpha((unsigned char)*s)) {
            int c = tolower((unsigned char)*s);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                count++;
            }
        }
    }
    return count;
}

int main(void) {
    char line[MAX_LEN];

    printf("Satrni kiriting: ");
    if (fgets(line, sizeof(line), stdin) == NULL) {
        fprintf(stderr, "Xatolik: satr o'qib bo'lmadi\n");
        return 1;
    }
    remove_newline(line);

    printf("Satr: \"%s\"\n", line);
    printf("Unli harflar soni: %d\n", count_vowels(line));
    return 0;
}
