#ifndef ROULEAU_H
#define ROULEAU_H
#include <string>

using namespace std;

class Rouleau
{
public:
    Rouleau(const string _reference, const int _diametre);
    void AffecterAlveole(const int _rangee, const int _colonne);
    void ObtenirLocalisation(int &_rangee, int &_colonne);
    bool operator < (const Rouleau _autreRouleau);
    int operator - (const Rouleau _autreRouleau);
    void Visualisez();
private:
    string reference;
    int diametre;
    int rangee;
    int colonne;
};

#endif // ROULEAU_H
