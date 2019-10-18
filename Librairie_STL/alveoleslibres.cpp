#include "alveoleslibres.h"
#include "math.h"

/**
 * @brief Alveoleslibres::Alveoleslibres
 * @param _nbRangees
 * @param _nbColonnes
 */

Alveoleslibres::Alveoleslibres(const int _nbRangees, const int _nbColonnes):
    nbRangees (_nbRangees),
    nbColonnes (_nbColonnes)
{
    for (int i = 1; i <= nbRangees*nbColonnes; i++)
    {
        push_back(i);
    }
}

/**
 * @brief Alveoleslibres::Reserver
 * @param _rangee
 * @param _colonne
 * @return
 */

bool Alveoleslibres::Reserver(int &_rangee, int &_colonne)
{
    bool retour = false;
    int numAlveole = back();
    if(!empty())
    {
        _rangee = ((numAlveole - 1) /(nbColonnes) + 1);
        _colonne = ((numAlveole - 1) %(nbColonnes) + 1);
        pop_back();
        retour = true;
        numAlveole = _colonne*_rangee;
    }
    return retour;

}

/**
 * @brief Alveoleslibres::Liberer
 * @param _rangee
 * @param _colonne
 */

void Alveoleslibres::Liberer(const int _rangee, const int _colonne)
{
    int numAlveole;

    numAlveole = (_rangee - 1)*nbColonnes+_colonne;
    push_back(numAlveole);
}

/**
 * @brief Alveoleslibres::Visualisez
 */

void Alveoleslibres::Visualisez()
{
    vector<int>::iterator alveole;
    for (alveole = begin(); alveole != end(); alveole++)
    {
         cout << *alveole << " ";
    }
    cout << endl;

}
