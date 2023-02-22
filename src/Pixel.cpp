#include <iostream>
#include <cassert>

#include "Pixel.h"

Pixel::Pixel():r(0),g(0),b(0){}
Pixel::Pixel(unsigned char red,unsigned char green,unsigned char blue) : r(red), g(green), b(blue)
{
    assert(0 <= red && red <= 255 && 0 <= green && green <= 255 && 0 <= blue && blue <= 255);

}
Pixel::Pixel(const Pixel &p):r(p.r),g(p.g),b(p.b)
{
}

unsigned char Pixel:: getRouge()const
{
    return r;
}
unsigned char Pixel::getVert()const
{
    return g;

}

unsigned char Pixel::getBleu()const
{
    return b;
}

void Pixel::setRouge(unsigned char red)
{
     r=red;
     assert(0<=red && red<=255);
}

void Pixel::setVert(unsigned char green)
{
     g=green;
     assert(0<=green && green<=255);
}

void Pixel::setBleu(unsigned char blue)
{
     b = blue;
     assert(0 <= blue && blue <= 255);
}

void Pixel::AfficheStat()const
{
    std::cout<<"composante rouge : "<<r<<std::endl;
    std::cout<<"composante verte : "<<g<<std::endl;
    std::cout<<"composante bleu : "<<b<<std::endl;


}
bool Pixel::operator ==(const Pixel &p)
{
    return(r==p.r && g==p.g && b==p.b);

}

Pixel& Pixel:: operator=(const Pixel &p)
{
    this->r = p.r;
    this->g = p.g;
    this->b = p.b;

    return *this;
}