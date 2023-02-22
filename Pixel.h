#ifndef _PIXEL_H
#define _PIXEL_H
#include <iostream>
#include <cassert>

using namespace std;

class Pixel
{
private:
    unsigned char r, g, b;

public:
    /// @brief Constructeurs par défaut de PIXEL.Initialisé à 0 =couleur noir.
    Pixel();

    /// @brief Constructeur par copie.Les attributs du PIXEL sont remplacés par ceux du PIXEL en paramètre.
    Pixel(const Pixel &p);

    /// @brief Constructeurs avec paramètre qui prend les valeurs entière RGB des 3 paramètres.Entre 0 et 255.
    Pixel(unsigned char red, unsigned char green, unsigned char blue);

    /// @brief accesseur qui renvoi la composante r,rouge du PIXEL
    unsigned char getRouge() const;

    /// @brief accesseur qui renvoi la composante g,verte du PIXEL
    unsigned char getVert() const;

    /// @brief accesseur qui renvoi la composante b,bleu du PIXEL
    unsigned char getBleu() const;

    /// @brief accesseur qui renvoi la composante g,verte du PIXEL
    void setVert(unsigned char green);

    /// @brief accesseur qui renvoi la composante b,bleu du PIXEL
    void setBleu(unsigned char blue);

    /// @brief accesseur qui renvoi la composante r,rouge du PIXEL
    void setRouge(unsigned char red);

    /// @brief Affiche dans la console les attributs r,g,b du PIXEL
    void AfficheStat() const;

    /// @brief Surcharge de l'opérateur == pour comparer les attributs du PIXEL avec celui en paramètre. 
    /// @return booléen
    bool operator==(Pixel p);

    /// @brief Surcharge de l'opérateur = pour remplacer les attributs du PIXEL par ceux deu PIXEL en paramètre.
    /// @return Renvoi un PIXEL.
    Pixel &operator=(const Pixel &p);
};

#endif
