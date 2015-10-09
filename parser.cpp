#include "parser.h"
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

Parser::Parser(){
	
	words.push_back("I");
	words.push_back("am");
	words.push_back("the");
	words.push_back("best");
	words.push_back("chocolat");
	words.push_back("tennis");
	words.push_back("boat");
	words.push_back("defragmentation");
	words.push_back("open-minded");
	words.push_back("door");
	
}


Parser::Token Parser::getNextToken(){
	int wordId = rand() % words.size();
	Parser::Token token;
	token.word = words[wordId];
	token.docId = rand() % 4  + 1;
	return token;
}
		
		
int Parser::openFile(std::string filename){
	
	return 0;
}