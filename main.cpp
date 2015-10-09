#include <stdio.h>
#include <fstream>
#include <iostream>
#include <dirent.h>
#include "parser.h"
 
using namespace std;

int main( int argc, const char* argv[] )
{
    Parser parser;
        DIR *rep;
 
        rep = opendir("Fichiers");
        struct dirent *lecture;
 
        while ((lecture = readdir(rep))) {
                printf("%s\n", lecture->d_name);
                parser.openFile(lecture->d_name);
        }
        return 0;
}