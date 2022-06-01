//
// Created by Joel Watson on 1:Jun:22.
//




#include "lexer.h"




namespace jayci {

    lexer::lexer (  ) {

    }




    vector<Token> lexer::parse ( const string &sourceCode ) {
        vector<Token>   tokens ;

        Token           current_token ;

        // we're doing a standard state machine.
        for ( char c : sourceCode ) {
            if ( isdigit(c) || c == '.' || c == 'f' )
            {
                if ( current_token.type != TokenType::FRACTURED_LITERAL && (c == '.' || c == 'f') ) {
                    current_token.type = TokenType::FRACTURED_LITERAL ;
                }
                else if ( current_token.type != TokenType::INTEGER_LITERAL) {
                    current_token.type = TokenType::INTEGER_LITERAL ;
                }
                current_token.text.append (1 , c) ;
            }
            else if ( c == '{' ) {

            }
            else if ( c == '}' ) {

            }
            else if ( c == '(' ) {

            }
            else if ( c == ')' ) {

            }
            else if ( c == '[' ) {

            }
            else if ( c == ']' ) {

            }
            else if ( c == '<' ) {

            }
            else if ( c == '>' ) {

            }
            else if ( c == ';' ) {

            }
            else if ( c == '{' ) {

            }
            else if ( c == '{' ) {

            }
            else if ( c == '{' ) {

            }
        }

        return tokens ;
    }

} // jayci







// Running code on the fly to enable full customization of the compilation process.

/*
 *
 * NOTE:    to ensure safety, one may not use these preprocs to mod any original compiler components.
 *              so instead when one wants to mod the compiler will copy the whole of itself to a new directory.
 *              then any modding will be
 *              to specify the directory use (#extend set dir = "<dirname>").
 *
 *
 * #extend safe     -- allows some extensions of compilation process, you can add tokens,
 *                  ---- add a way to parse it, and finally, add what the end generated cpp
 *                  ---- file looks like. #extend is the safest option.
 *
 * #extend inject   -- inject code into a specific place. allows the modification of anything.
 *
 * #extend new      -- makes a new file to compile.
 *
 * #entend scrap    -- makes a copy of the original and rewrites the whole file.
 */

#include <fstream>
#include <string>
#include <cstdlib>

int some_execute_function(const std::string& code)
{
    const std::string dynamic_filename("dynamic.cpp");
    const std::string dynamic_executable("./dynamic.out");
    std::ofstream dynamic(dynamic_filename);
    dynamic << "#include <iostream>\n"
            << "#include <cstdlib>\n"
            << "int main(){\n"
            << code << ";\n"
            << "return EXIT_SUCCESS;\n"
            << "}\n";
    dynamic.close();

    const std::string build_command("g++ -std=c++14 -O2 -Wall -pedantic -pthread " + dynamic_filename + " -o " + dynamic_executable);
    bool it_didnt_compile = system(build_command.c_str());
    if(it_didnt_compile)
    {
        return EXIT_FAILURE;
    }
    else
    {
        return system(dynamic_executable.c_str());
    }
}

int main()
{
    std::string code_string = "std::cout << \"Hello World!!\\\n\";";
    return some_execute_function(code_string);
}
