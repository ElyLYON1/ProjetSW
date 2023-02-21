#ifndef _IMAGE_H
#define _IMAGE_H
#include <iostream>
#include <cassert>
#include "Pixel.h"
using namespace std;

class Image
{
    private :
    unsigned int dimx,dimy;
    Pixel * tab;

    public:
    Image();
    Image(unsigned int x,unsigned int y);
    Image(const Image &p);


    ~Image();


    Pixel getPix(const unsigned int &x, const unsigned  int &y) const ;
    void setPix(unsigned int x,unsigned int y,const Pixel &couleur);
    void AfficheStatImage()const;
    void dessinerRectangle( const unsigned int &xmin,const unsigned int &xmax,const  unsigned int &ymin,const unsigned int &ymax,const Pixel &couleur);
    void effacer(const Pixel &couleur);

    void testRegression ();
    void testConstructeursValide();
    void testConstructeursInvalide();
    void testfonction();

    void sauver(const string &filename) const;
    void ouvrir(const string &filename);
    void afficherConsole();
    };

#endif
