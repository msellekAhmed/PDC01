#include <stdio.h>
#include <fstream>
#include <iostream>
#include <dirent.h>
#include "parser.h"

using namespace std;

int Parser::openFile(string filename) {
    string ch;
    string doc;
    int add;
    ifstream fichier(filename, ios::in); // on ouvre le fichier en lecture

    if (fichier) // si l'ouverture a réussi
    {
        string ligne;
        while (getline(fichier, ligne)) // tant que l'on peut mettre la ligne dans "contenu"
        {
            ch = ligne.substr(0,1);
            doc = ligne.substr(0,7);
            //std::cout << doc << std::endl;
            if (ch == "<" and doc!="<DOCID>") {
                add = 0;
            } 
            else {
                add = 1;
            }

            if (add==1){ v.push_back(ligne);}
        }
        fichier.close(); // on ferme le fichier
        for (int i = 0; i != v.size(); i++)
        {
            std::cout << v[i] << std::endl;
        }
        return 1;
    } else { // sinon
        cerr << "Impossible d'ouvrir le fichier !" << endl;
        return 0;
    }
}