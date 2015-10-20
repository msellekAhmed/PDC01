#include<string>
#include <vector>  
#include<boost/tokenizer.hpp>

#ifndef __PARSER_H_INCLUDED__
#define __PARSER_H_INCLUDED__

class Parser{
	
	public:
		Parser();
		struct Token {
			int docId;
			std::string word;
		};
		/*
			throw an exception if the parser is not correctly initialized (no file input given for example)
		*/
		Token getNextToken();
				
		/*
			return 0 if sucess, 1 if the file cannot be opened, 2 if the file is not correctly formated
		*/
		int openFile(std::string filename);
		
	protected:
        struct Doc {
			int docId;
			std::string text;
		};
		std::vector<std::string>v;
        std::vector<Doc>docs;
		std::vector<Doc>::iterator docsIt;
		boost::tokenizer<> tokenizer;
		boost::tokenizer<>::iterator tokIterator;

};

#endif 