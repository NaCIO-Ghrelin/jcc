//
// Created by Joel Watson on 1:Jun:22.
//




#pragma once




#include <string>
#include <vector>




#ifndef JCC_LEXER_H
#define JCC_LEXER_H




namespace jayci {

    using namespace std;



    enum TokenType {
        END_OF_TOKEN_STREAM,
        WHITE_SPACE,            // '\t' or ' '
        SINGLE_LINE_COMMENT,    // single line comment starting with '~~'

        INTEGER_LITERAL,
        FRACTURED_LITERAL,
        STRING_LITERAL,

        OPERATOR,
    };


    struct Token {
    public:
        enum TokenType type     {TokenType::WHITE_SPACE};
        string text             {""};
        size_t start_column     {0};
        size_t end_column       {0};
        size_t start_line       {0};
        size_t end_line         {0};
    };




    class lexer {
    public:
        lexer();

        vector<Token> parse ( const string &sourceCode );
    };

} // jayci




#endif //JCC_LEXER_H
