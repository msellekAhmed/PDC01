#include <iostream>
#include "parser.h"

int main( int argc, const char* argv[] )
{
	std::cout << "Hello World";
	Parser parser;
	Parser::Token token;
	for(int i =0 ; i<40 ; ++i){
		token = parser.getNextToken();
		std::cout <<"doc: "<< token.docId << "  word: "<< token.word << std::endl;
	}
	std::cin.get();
}