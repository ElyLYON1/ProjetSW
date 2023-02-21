#include <iostream>
#include <cassert>
using namespace std;

#include "Pixel.h"
int main ()
{
    Pixel p1;
    Pixel p2(25,55,127);

    p1.AfficheStat();
    p2.AfficheStat(); // test de doxygen , je cherche a verifier les constructeurs par copie et par défaut

    p1.setVert(20);
    p1.AfficheStat();

    return 0;
}
