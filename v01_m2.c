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

/* Satrni joyida teskari aylantiradi (qo'shimcha massivsiz) */
void reverse(char *s) {
    size_t len = strlen(s);
    if (len < 2) {
        return;
    }
    char *left = s;
    char *right = s + len - 1;
    while (left < right) {
        char tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }
}

int main(void) {
    char line[MAX_LEN];

    printf("Satrni kiriting: ");
    if (fgets(line, sizeof(line), stdin) == NULL) {
        fprintf(stderr, "Xatolik: satr o'qib bo'lmadi\n");
        return 1;
    }
    remove_newline(line);

    printf("Asl satr:     %s\n", line);
    reverse(line);
    printf("Teskari satr: %s\n", line);
    return 0;
}
