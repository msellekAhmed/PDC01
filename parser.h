#include<string>
#include <vector>  

#ifndef __PARSER_H_INCLUDED__
#define __PARSER_H_INCLUDED__



class Parser{
	
	public:
		struct Token {
			int docId;
			std::string word;
		};
                std::vector<std::string>v;
                Token getNextToken();
		int openFile(std::string filename);
        struct Doc {
			int docId;
			std::string text;
		};
                std::vector<Doc>docs;
};

#endif 