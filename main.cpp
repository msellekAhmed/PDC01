#include <stdio.h>
#include <fstream>
#include <iostream>
#include <dirent.h>
#include<string>
#include "parser.h"
 
using namespace std;

int main( int argc, const char* argv[] )
{
    Parser parser;
        DIR *rep;
        string dossier="Fichiers";
        rep = opendir(dossier.c_str());
        struct dirent *lecture;
 
        while ((lecture = readdir(rep))) {
                parser.openFile(dossier+"/"+lecture->d_name);
                //parser.getNextToken();
        }
        return 0;
}