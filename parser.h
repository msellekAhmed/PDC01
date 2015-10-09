#include <string>
#include <vector>

#ifndef __PARSER_H_INCLUDED__
#define __PARSER_H_INCLUDED__

class Parser{
	
	public:
		struct Token {
			int docId;
			std::string word;
		};
		Parser();
		Token getNextToken();
		int openFile(std::string filename);
	private:
		std::vector<std::string> words;
};

#endif 