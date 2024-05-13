#include "parser.h"
#include <iostream>

string* vet;

void print(Token*);
void allocVetor();
void freeVetor();

int main(int argc, char* argv[]) {
    string input;


    // L� uma linha de entrada
    getline(cin, input);

    // Cria um objeto Scanner com a entrada fornecida
    Scanner* scanner = new Scanner(input);

    // Aloca o vetor de strings para mapear os tokens
    allocVetor();

    //Parser* parser = new Parser(input);
    //parser->run();
    Token* t;

    do {
        // Obt�m o pr�ximo token do scanner
        t = scanner->nextToken();

        // Imprime o token
        print(t);
    } while (t->name != END_OF_FILE);

    // Libera a mem�ria alocada para o scanner
    delete scanner;
    //delete parser;
    // Libera a mem�ria alocada para o vetor de strings
    freeVetor();

    return 0;
}

// Aloca o vetor de strings para mapear os tokens
void allocVetor() {
    vet = new string[END_OF_FILE + 1];

    vet[UNDEF] = "UNDEF";
    vet[ID] = "ID";
    vet[NUMBER] = "NUMBER";
    vet[PLUS] = "PLUS";
    vet[MINUS] = "MINUS";
    vet[MULT] = "MULT";
    vet[DIV] = "DIV";
    vet[ASSIGN] = "ASSIGN";
    vet[EQ] = "EQ";
    vet[NOT] = "NOT";
    vet[NE] = "NE";
    vet[LESS] = "LESS";
    vet[LE] = "LE";
    vet[GT] = "GT";
    vet[GE] = "GE";
    vet[AND] = "AND";
    vet[L_PAREN] = "L_PAREN";
    vet[R_PAREN] = "R_PAREN";
    vet[L_BRACKET] = "L_BRACKET";
    vet[R_BRACKET] = "R_BRACKET";
    vet[L_BRACE] = "L_BRACE";
    vet[R_BRACE] = "R_BRACE";
    vet[SEMICOLON] = "SEMICOLON";
    vet[QUOTE] = "QUOTE";
    vet[DOT] = "DOT";
    vet[COMMA] = "COMMA";
    vet[BOOLEAN] = "BOOLEAN"; // PR
    vet[CLASS] = "CLASS"; // PR
    vet[ELSE] = "ELSE"; // PR
    vet[EXTENDS] = "EXTENDS"; // PR
    vet[FALSE] = "FALSE"; // PR
    vet[IF] = "IF"; // PR
    vet[INT] = "INT"; // PR
    vet[LENGTH] = "LENGTH"; // PR
    vet[MAIN] = "MAIN"; // PR
    vet[NEW] = "NEW"; // PR
    vet[PUBLIC] = "PUBLIC"; // PR
    vet[RETURN] = "RETURN"; // PR
    vet[STATIC] = "STATIC"; // PR
    vet[STRING] = "STRING"; // PR
    vet[SYSTEM_OUT_PRINTLN] = "SYSTEM_OUT_PRINTLN"; // PR
    vet[THIS] = "THIS"; // PR
    vet[TRUE] = "TRUE"; // PR
    vet[VOID] = "VOID"; // PR
    vet[WHILE] = "WHILE"; // PR
    vet[END_OF_FILE] = "END_OF_FILE";
}

// Libera a mem�ria alocada para o vetor de strings
void freeVetor() {
    delete[] vet;
}

// Imprime o token
void print(Token* t) {
    std::cout << vet[t->name];

    // Se o atributo do token n�o for UNDEF, imprime o atributo
    if (t->attribute != UNDEF)
        std::cout << "(" << vet[t->attribute] << ")";

    std::cout << " ";
}

