#include <stdio.h>
#include <fstream>
#include <iostream>
#include <dirent.h>
 
using namespace std;

int Parser::openFile(string filename){
        ifstream fichier(filename, ios::in);  // on ouvre le fichier en lecture
 
        if(fichier)  // si l'ouverture a réussi
        {       
                string ligne;
                while(getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
                {
                        cout << ligne << endl;  // on l'affiche
                }
                fichier.close();  // on ferme le fichier
                return 1;
        }
        else{  // sinon
                cerr << "Impossible d'ouvrir le fichier !" << endl;
                return 0;
        }
}