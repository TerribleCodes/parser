#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define idLength 20

typedef enum { ID, PLUS, STAR, LPAREN, RPAREN, END, ERROR } Token;

typedef struct { 
    char id[idLength]; 
    Token token; 
} Symbol;

Symbol symbolTable[256]; // Array Data structure
int symbolCount = 0;

void addSymbol(char *id, Token token);
Token getNextToken(char **input);
void printSymbolTable();
void printIndent(int level);

void addSymbol(char *id, Token token) {
    strncpy(symbolTable[symbolCount].id, id, idLength);
    symbolTable[symbolCount].token = token;
    symbolCount++;
}

Token getNextToken(char **input) {
    while (isspace(**input)) (*input)++;
    if (isdigit(**input) || isalpha(**input)) {
        char id[idLength];
        int len = 0;
        while (isdigit(**input) || isalpha(**input)) {
            id[len++] = **input;
            (*input)++;
        }
        id[len] = '\0';
        addSymbol(id, ID);
        return ID;
    }
    char op[2] = { **input, '\0' };
    switch (**input) {
        case '+': (*input)++; addSymbol(op, PLUS); return PLUS;
        case '*': (*input)++; addSymbol(op, STAR); return STAR;
        case '(': (*input)++; addSymbol(op, LPAREN); return LPAREN;
        case ')': (*input)++; addSymbol(op, RPAREN); return RPAREN;
        case '\0': return END;
        default: return ERROR;
    }
}

void printSymbolTable() {
    for (int i = 0; i < symbolCount; i++) {
        printf("ID: %s, Token: ", symbolTable[i].id);
        switch (symbolTable[i].token) {
            case ID: printf("ID\n"); break;
            case PLUS: printf("PLUS\n"); break;
            case STAR: printf("STAR\n"); break;
            case LPAREN: printf("LPAREN\n"); break;
            case RPAREN: printf("RPAREN\n"); break;
            case END: printf("END\n"); break;
            case ERROR: printf("ERROR\n"); break;
        }
    }
}

void printIndent(int level) {
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
}

int main() {
    char input[100];
    char *p;
    int choice;

    printf("---Simulated Lexical Analyzer and Parser---\n===Please make sure input.txt file contains the string. Otherwise insert the string manualy with choice 2===\nEnter 1 to read from the text file, 2 to enter a string and 3 to exit the program: ");
    scanf("%d", &choice);
    getchar();

    if (choice == 1) {
        printf("Opening the file\n");
        FILE *file = fopen("input.txt", "rb");
        if (file == NULL) {
            printf("Error opening file\n");
            return 1;
        }
        fgets(input, sizeof(input), file);
        fclose(file);
        input[strcspn(input, "\n")] = '\0';
        p = input;
    } else if (choice == 2) {
        printf("Enter a string to parse: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        p = input;
    } else if(choice == 3){
        exit;
    } else {
        printf("Invalid choice\n");
        return 1;
    }

    /*parseE(&p, 0);
    if (*p == '\0') {
        printf("\nInput is valid\n");
    } else {
        printf("\nError: unexpected character '%c'\n", *p);       
    }
    printSymbolTable();*/
    return 0;
}
