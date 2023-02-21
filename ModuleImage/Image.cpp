#include <cassert>
#include "Image.h"

Image::Image():dimx(0),dimy(0),tab (nullptr)
{
}

Image::Image(unsigned int x, unsigned int y):dimx(x),dimy(y),tab(new Pixel [x*y] )  //j'avais fais le new dans le corps du constructeur
{
    assert(x>=0 && y>=0);
}

Image::Image(const Image &p):dimx(p.dimx),dimy(p.dimy),tab(new Pixel[p.dimx * p.dimy])
{

    for (unsigned int i = 0; i < dimx; i++) {
        for (unsigned int j = 0; j < dimy; j++) {
            tab[j * dimx + i] = p.tab[j * dimx + i];
        }
    }
}


Image::~Image()
{
    cout<<"Suppresion de l'image";

    delete [] tab;
    dimx=0;
    dimy=0;
}

/* Pixel Image::getPixel(unsigned int x,unsigned int y) const
{
    return tab[y*dimx+x];

}

*/
 Pixel Image::getPix(const unsigned int &x, const unsigned  int &y) const
{
    assert(x >= 0 && x < dimx);
    assert(y >= 0 && y < dimy);

    return tab[y * dimx + x];
}
void Image::setPix(unsigned int x, unsigned int y, const Pixel &couleur)
{
    assert(x >= 0 && x < dimx);
    assert(y >= 0 && y < dimy);

    tab[y * dimx + x] = couleur;
}



void Image:: dessinerRectangle( const unsigned int &xmin,const unsigned int &xmax,const  unsigned int &ymin,const unsigned int &ymax,const Pixel &couleur)
{
    assert(xmin>=0 && xmin <=dimx);
    assert(xmax>=0 && xmax <=dimx);
    assert(xmax>=xmin);

    assert(ymin>=0 && ymin <=dimy);
    assert(ymax>=0 && ymax <=dimy);
    assert(ymax>=ymin);



    for(unsigned int i=xmin;i<=xmax;i++)
    {


        for(unsigned int j=ymin;j<=ymax;j++)
    {
        setPix(i,j,couleur);

    }

}
}
void Image::effacer(const Pixel &couleur)
{
    dessinerRectangle(0,0,dimx,dimy,couleur);

}


void Image::AfficheStatImage() const
{
    std::cout<<"Largeur : "<<dimx<<std::endl;
    std::cout<<"Hauteur : "<<dimy<<std::endl;
       for (unsigned int y = 0; y < dimy; ++y) {
        for (unsigned int x = 0; x < dimx; ++x) {
            const Pixel& p = getPix(x, y);
            p.AfficheStat();
        }
    }

}
/*
void Image::testRegression ()
{
    Image I1;
    Image I2(36,20);
    Pixel p1;
    Pixel p2(25,10,67);
    I1.getPix(-10,10);
    I1.getPix('65',10);
    I2.getPix(0,0);
try
{
        I2.getPix(5000000000, 1);
        assert()

}
catch(const std::exception& e)
{
    std::cout<<"erreur " << e.what() << '\n';
}

    I1.setPix(1,-2,p1);
    I2.setPix(1,22,p2);



}

    void Image:: testConstructeursValide()
{
    Image I1; // Appel du constructeur par défaut
    assert(I1.dimx == 0 && I1.dimy == 0 && I1.tab == nullptr);

    Image I2(36,20); // Appel du constructeur avec des paramètres
    assert(I2.dimx == 36 && I2.dimy == 20 && I2.tab != nullptr);

    Image I3(I2); // Appel du constructeur de copie
    assert(I3.dimx == I2.dimx && I3.dimy == I2.dimy && I3.tab != I2.tab);
}
    void Image::testConstructeursInvalide()
{


    Image I2(-2,20); // Appel du constructeur avec des paramètres
    assert(I2.dimx == -2 && I2.dimy == 20 && I2.tab != nullptr);

    Image I3(I2); // Appel du constructeur de copie
    assert(I3.dimx == I2.dimx && I3.dimy == I2.dimy && I3.tab != I2.tab);

    Image I4(5000000000,1);
    assert(I4.dimx == 5000000000 && I4.dimy == 1 && I4.tab != nullptr);
}

void Image::testfonction()
{
    Pixel blanc(255, 255, 255);

    // Vérifier la création d'un pixel blanc
    assert(blanc.getRouge() == 255 && blanc.getBleu() == 255 && blanc.getVert() == 255);

    // Vérifier la création d'une image 15x10
    Image I5(15, 10);
    assert(I5.dimx == 15 && I5.dimy == 10 && I5.tab != nullptr);

    // Vérifier la fonction setPixel() et getPixel()
    I5.setPix(5, 7, blanc);
    assert(I5.getPix(5, 7) == blanc);

    // Vérifier qu'un pixel par défaut est bien noir
    Pixel noir;
    assert(I5.getPix(0, 0) == noir);
}
*/