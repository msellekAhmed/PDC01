#include <stdio.h>
#include <fstream>
#include <iostream>
#include <dirent.h>
#include "parser.h"

using namespace std;

int Parser::openFile(string filename) {
    char ch;
    int i;
    ifstream fichier(filename, ios::in); // on ouvre le fichier en lecture

    if (fichier) // si l'ouverture a réussi
    {
        string ligne;
        while (getline(fichier, ligne)) // tant que l'on peut mettre la ligne dans "contenu"
        {
            /*ch = fgetc(*fichier);
            if (ch == EOF)
                break;

            if (ch == '<') {
                i = 0;
                continue;
            } else if (!i && ch == '>') {
                i = 1;
                continue;
            }

            if (i)*/ v.push_back(ligne);
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