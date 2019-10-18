#include <iostream>
#include <string>
#include <menu.h>
#include <alveoleslibres.h>

using namespace std;

enum CHOIX_MENU
{
    OPTION_1 = 1,
    OPTION_2,
    QUITTER
};

/**
 * @brief main
 * @return
 */

int main()
{
        int choix;
        int rangee;
        int colonne;
        Alveoleslibres uneAlveole(2,5);
        Menu leMenu("menu.txt");
        do
        {
            choix = leMenu.Afficher();
            switch(choix){
                case OPTION_1:
                    cout << "Vous avez choisi de réserver une alvéole" << endl;
                    if(uneAlveole.Reserver(rangee,colonne))
                    {
                        cout << "L'alvéole réservée est située rangée " << rangee << " et colonne " << colonne << endl;
                    }else
                    {
                        cout << "Il n'y a pas d'alvéole disponible" << endl;
                    }
                    uneAlveole.Visualisez();
                    Menu::AttendreAppuiTouche();
                    break;
                case OPTION_2:
                    cout << "Vous avez choisi de libérer une alvéole" << endl;
                    cin >> rangee;
                    cin >> colonne;
                    uneAlveole.Liberer(rangee,colonne);
                    uneAlveole.Visualisez();
                    Menu::AttendreAppuiTouche();
                    break;
            }
        }while(choix != QUITTER);
    return 0;
}

