#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define DELIM " "

#define IN_LEN 64
#define LIST_LEN 4

#define CMD_PUSH "push"

#define MSG_UNKNOWN_CMD "Unknown command!\n"
#define MSG_MISSING_NUM "You must provide a number!\n"
#define MSG_LIST_FULL   "List is full!\n"

void get_string(char * target, size_t len) {
    fgets(target, len, stdin);
    size_t inlen = strlen(target);
    if (target[inlen-1] == '\n') target[inlen-1] = '\0';
    else while (getchar() != '\n');
}

void print_list(int * list, size_t len) {
    for(size_t i = 0; i < len; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

bool is_numeric(char * str, size_t len) {
    for (size_t i = 0; i < len; i++) {
        if (str[i] < '0' || str[i] > '9') return false;
    }
    return true;
}

int main() {
    char input[IN_LEN];
    int list[LIST_LEN];
    size_t first_free_index = 0;

    while(1) {
        get_string(input, IN_LEN);
        char * p_tok = strtok(input, DELIM);
        if (p_tok == NULL) continue;

        if (strcmp(p_tok, CMD_PUSH) == 0) {
            p_tok = strtok(NULL, DELIM);
            if (p_tok == NULL) {
                printf(MSG_MISSING_NUM);
                continue;
            }
            if (first_free_index >= LIST_LEN) {
                printf(MSG_LIST_FULL);
                continue;
            }
            if (!is_numeric(p_tok, strlen(p_tok))) {
                printf(MSG_MISSING_NUM);
                continue;
            }
            list[first_free_index] = strtol(p_tok, NULL, 10);
            first_free_index++;
            print_list(list, first_free_index);
        }
        else {
            printf(MSG_UNKNOWN_CMD);
        }
    }

    return 0;
}