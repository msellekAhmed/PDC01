#include <stdio.h>
#include <fstream>
#include <iostream>
#include <dirent.h>
 
using namespace std;

int main( int argc, const char* argv[] )
{
        DIR *rep;
 
        rep = opendir("Fichiers");
        struct dirent *lecture;
 
        while ((lecture = readdir(rep))) {
                printf("%s\n", lecture->d_name);
                // ton traitement
        }
        return 0;
}



int openfile(){
        ifstream fichier("latimes/la010189", ios::in);  // on ouvre le fichier en lecture
 
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