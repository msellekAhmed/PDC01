#include <stdio.h>
#include <fstream>
#include <iostream>
#include <dirent.h>
#include<string>
#include "parser.h"
#include<boost/tokenizer.hpp>

using namespace std;

int main( int argc, const char* argv[] )
{
    Parser parser;
	DIR *rep;
	string dossier="Fichiers";
	rep = opendir(dossier.c_str());
	struct dirent *lecture;
	while ((lecture = readdir(rep))) {
            int codeErreur =parser.openFile(dossier+"/"+lecture->d_name);
            if(strcmp(lecture->d_name,".")!=0 and strcmp(lecture->d_name,"..")!=0){
			if(codeErreur == 0){
				// file successfully read
				for(int i = 0 ; i < 20 ; ++i){
					try
					{
						Parser::Token tok = parser.getNextToken();
						cout << "token : docId " << tok.docId << " - word " << tok.word << endl;
					}
					catch (int e)
					{
						cout << "Error reading a token from parser. Error num " << e << endl;
					}	
					
				}
			} else {
                            cerr<<codeErreur;
                        }
        }
	}
	cout << "press enter" <<endl;
	getchar();
	return 0;
}