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
			int previousDocId = -1;
            int codeErreur =parser.openFile(dossier+"/"+lecture->d_name);
            if(strcmp(lecture->d_name,".")!=0 and strcmp(lecture->d_name,"..")!=0){
			if(codeErreur == 0){
				// file successfully read
				
				Parser::Token tok = parser.getNextToken();
				while(tok.docId != -1)
				{
					
					if(previousDocId != tok.docId){
						//pause when we begin a new doc, only for debug
						cout << "press enter to continue" <<endl;
						getchar();
					}
					previousDocId = tok.docId;
					cout << "token : docId " << tok.docId << " - word " << tok.word << endl;
					tok = parser.getNextToken();
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