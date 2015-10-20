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
		string s = "This is,  a test";
		boost::tokenizer<> tok(s);
		cout << "test tokenization" <<endl;
		for(boost::tokenizer<>::iterator beg=tok.begin(); beg!=tok.end();++beg){
		   cout << *beg << "\n";
		}
		cout << "press enter" <<endl;
		getchar();
        
		while ((lecture = readdir(rep))) {
                parser.openFile(dossier+"/"+lecture->d_name);
                //parser.getNextToken();
        }
		cout << "press enter" <<endl;
		getchar();
        return 0;
}