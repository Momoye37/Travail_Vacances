#ifndef MENU_H
#define MENU_H
#include <string>
#include <algorithm>

using namespace std;

class Menu
{
    private:
        const string nom; ///Désigne le nom du fichier
        string * options; ///Représente un tableau de chaînes de caractères implémentées sous la forme de string.
                          ///Ce tableau sera alloué dynamiquement en fonction du nombre de lignes du fichier.
        int nbOptions; ///Contient le nombre d'options du Menu
        int longueurMax; ///Taille de la plus grande chaîne contenue dans le tableau
    public:
        Menu(const string &_nom);
        ~Menu();
        int Afficher();
        static void AttendreAppuiTouche();
};
class ErreurCreation
{
private:
    int codeErreur;
    string message;
public:
    ErreurCreation(int _codeErreur, string _message);
    int ObtenirCodeErreur() const;
    string ObtenirDescription() const;
};
class ErreurIndice
{
private:
    int codeErreur;
    string message;
public:
    ErreurIndice(int _codeErreur, string _message);
    int ObtenirCodeErreur() const;
    string ObtenirDescription() const;
};

#endif // MENU_H
