#include "menu.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include<stdio.h>
#include <string.h>



/**
 * @brief Menu::Menu
 * @details Constructeur de la classe Menu
 * @param _nom nom du fichier à ouvrir
 */
Menu::Menu(const string &_nom):nom(_nom), longueurMax(0)
{

    ifstream leFichier(nom.c_str());

    if(!leFichier .is_open())
    {
        cerr << "Erreur lors de l'ouverture du fichier";
        nbOptions=0;
    }else
    {
        nbOptions = static_cast<int>(count(istreambuf_iterator<char>(leFichier),istreambuf_iterator<char>(),'\n'));
        leFichier.seekg(0,ios::beg);
        options = new string [nbOptions];
        for(int i=0;i<nbOptions;i++)
        {
            getline(leFichier,options[i]);
            if(static_cast<int>(options[i].length())>longueurMax)
            {
                longueurMax = static_cast<int>(options[i].length());
            }
        }
    }
}

/**
 * @brief Menu::~Menu
 * @details Destructeur
 */

Menu::~Menu()
{
    delete [] options;
}

/**
 * @brief Menu::Afficher
 * @return
 */

int Menu::Afficher()
{
    int choix;
        bool passage=false;
        do{
            system("clear");
            cout << "+" << setfill('-') << setw(7) << "+" << setfill('-') << setw(longueurMax+11) << "+" << endl;
            for (int i=0; i<nbOptions; i++)
            {
                cout << "|" << setw(6) << setfill(' ') << i+1 << "| " << setw(16) << options[i] << setfill(' ') << setw(longueurMax-6) << "|" << endl;
            }
            cout << "+" << setfill('-') << setw(7) << "+" << setfill('-') << setw(longueurMax+11) << "+" << endl;
            cout << endl;

            if(passage==false)
            {
                cout << "Entrez un nombre entre 1 et 3 : ";
                passage=true;
            }else{
                cout << "Entrer un nombre entre 1"<< " et " << nbOptions << ": ";
            }
            if(!(cin>>choix))
            {
                cin.clear();
                cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
                choix=-1;
            }
        }while((choix<1) || (choix>nbOptions));

        return choix;
}

/**
 * @brief Menu::AttendreAppuiTouche
 */

void Menu::AttendreAppuiTouche()
{
    string uneChaine;
        cout << endl << "Appuyer sur la touche Entrée pour continuer ...";
        getline(cin,uneChaine);
        cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
        system("clear");
}
