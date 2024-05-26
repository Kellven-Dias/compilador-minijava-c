#include "scanner.h"

class Parser
{
    private:
        Scanner* scanner;
        Token* ltoken;
        SymbolTable* globalST;
        SymbolTable* currentST;

        void advance();
        void match(int);
        void initSimbolTable();

        void Program();
        void MainClass();
        void ClassDeclaration();
        void VarDeclaration();
        void MethodDeclaration();
        void Params();
        void Type();
        void Statement();
        void Expression();
        void RelExpression();
        void AddExpression();
        void MultExpression();
        void UnExpression();
        void PrimExpression();
        void ExpressionsList();

        void error(string);

    public:
        Parser(string);

        void run();
};
