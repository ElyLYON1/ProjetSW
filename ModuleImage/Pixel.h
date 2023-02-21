#ifndef _PIXEL_H
#define _PIXEL_H
#include <iostream>
#include <cassert>


using namespace std;

class Pixel
{
    private :
    unsigned char r,g,b;

    public:
    Pixel();
    Pixel(const Pixel &p);
    Pixel(unsigned char red,unsigned char green,unsigned char blue);

    unsigned char getRouge()const;
   unsigned char getVert()const;
   unsigned char getBleu()const;

    void setVert(unsigned char green);
    void setBleu(unsigned char blue);
    void setRouge(unsigned char red);
   void AfficheStat()const;

    bool operator ==(const Pixel &p);
    Pixel& operator=(const Pixel &p);
};


#endif
