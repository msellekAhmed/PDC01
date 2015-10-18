#include <stdio.h>
#include <fstream>
#include <iostream>
#include <dirent.h>
#include "parser.h"

using namespace std;

int Parser::openFile(string filename) {
    string ch;
    string doc;
    string text;
    int add;
    ifstream fichier(filename, ios::in); // on ouvre le fichier en lecture

    if (fichier) // si l'ouverture a réussi
    {
        // on vide le vecteur de docs à chaque fichier 
        docs.clear();
        
        string ligne;
        while (getline(fichier, ligne)) 
        {
            ch = ligne.substr(0,1);
            doc = ligne.substr(0,7);
            
            if (doc=="<DOCID>"){
                // créer une nouvelle structure doc
                // ajouter le doc dans docs
                // remplir doc.docid dans la struct du doc
                // doc.text=null
                add=0;
            }
            else if (ch == "<") {
                add = 0;
            } 
            else {
                add = 1;
            }

            if (add==1){
                //Doc.text=text+ligne
            }
        }
     }
        fichier.close(); // on ferme le fichier
        //lecture du vecteur
        /*for (int i = 0; i != v.size(); i++)
        {
            std::cout << v[i] << std::endl;
        }*/
        return 1;
    } else {
        //cerr << "Impossible d'ouvrir le fichier !" << endl;
        return 0;
    }
}

/*Parser::Token Parser::getNextToken(){
    
}*/