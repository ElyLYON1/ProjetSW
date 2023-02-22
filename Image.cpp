#include <cassert>
#include "Image.h"
#include "Pixel.h"
#include <fstream>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

Image::Image() : dimx(0), dimy(0), tab(nullptr)
{
}

Image::Image(unsigned int x, unsigned int y) : dimx(x), dimy(y), tab(new Pixel[x * y]) // j'avais fais le new dans le corps du constructeur
{
    assert(x >= 0 && y >= 0);
}

Image::Image(const Image &p) : dimx(p.dimx), dimy(p.dimy), tab(new Pixel[p.dimx * p.dimy])
{
    assert(dimx == p.dimx && dimy == p.dimy && tab != p.tab);

    for (unsigned int i = 0; i < dimx; i++)
    {
        for (unsigned int j = 0; j < dimy; j++)
        {
            tab[j * dimx + i] = p.tab[j * dimx + i];
           assert(tab[j * dimx + i] == p.tab[j * dimx + i]);
        }
    }
}

Image::~Image()
{
    cout << "Suppresion de l'image";

    delete[] tab;
    dimx = 0;
    dimy = 0;
}


Pixel &Image::getPix(const unsigned int &x, const unsigned int &y) const
{
    assert(x >= 0 && x <= dimx);
    assert(y >= 0 && y <= dimy);

    return tab[y * dimx + x];
}
void Image::setPix(unsigned int x, unsigned int y, const Pixel &couleur)
{
    assert(x >= 0 && x <=dimx);
    assert(y >= 0 && y <= dimy);

    tab[y * dimx + x] = couleur;
}

void Image::dessinerRectangle(const unsigned int &xmin, const unsigned int &ymin, const unsigned int &xmax, const unsigned int &ymax, const Pixel &couleur)
{
    assert(xmin >= 0);
    assert(xmin <= xmax);
    assert(ymin >= 0);
    assert(ymin <= ymax);

    for (unsigned int i = xmin; i <= xmax; i++)
    {

        for (unsigned int j = ymin; j <= ymax; j++)
        {
            setPix(i, j, couleur);
        }
    }
}
void Image::effacer(const Pixel &couleur)
{
    dessinerRectangle(0, 0, dimx, dimy, couleur);
}

void Image::AfficheStatImage() const
{
    std::cout << "Largeur : " << dimx << std::endl;
    std::cout << "Hauteur : " << dimy << std::endl;
    for (unsigned int y = 0; y < dimy; ++y)
    {
        for (unsigned int x = 0; x < dimx; ++x)
        {
            const Pixel &p = getPix(x, y);
            p.AfficheStat();
        }
    }
}
void Image::sauver(const string &filename) const
{
    

    ofstream fichier(filename.c_str());
    assert(fichier.is_open());

    fichier << "P3" << endl;
    fichier << dimx << " " << dimy << endl;
    fichier << "255" << endl;

    for (unsigned int y = 0; y < dimy; ++y)
    {
        for (unsigned int x = 0; x < dimx; ++x)
        {
            Pixel pix = getPix(x, y);
            fichier << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << " ";
        }
    }

    cout << "Sauvegarde de l'image " << filename << " ... OK\n";
    fichier.close();
}

void Image::ouvrir(const string &filename)
{
    ifstream fichier(filename.c_str());
    assert(fichier.is_open());

    unsigned int r, g, b;
    string mot;

    fichier >> mot >> dimx >> dimy >> mot;
    assert(dimx > 0 && dimy > 0);

    if (tab != NULL)
        delete[] tab;

    tab = new Pixel[dimx * dimy];

    for (unsigned int y = 0; y < dimy; ++y)
    {
        for (unsigned int x = 0; x < dimx; ++x)
        {
            fichier >> r >> g >> b;
            getPix(x, y).setRouge((unsigned char)r);
            getPix(x, y).setVert((unsigned char)g);
            getPix(x, y).setBleu((unsigned char)b);
        }
    }
    fichier.close();
    cout << "Lecture de l'image " << filename << " ... OK\n";
}

void Image::afficherConsole()
{
    cout << dimx << " " << dimy << endl;
    for (unsigned int y = 0; y < dimy; ++y)
    {
        for (unsigned int x = 0; x < dimx; ++x)
        {
            const Pixel &pix = getPix(x, y);
            cout << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << " ";
        }
        cout << endl;
    }
}

/// @brief J'ai decouper le test de regression en différents tests 
void Image::testRegression()
{

    testConstructeursValide();
    testConstructeursInvalide();
    testfonction();
}

// Première fonction du test de régression.
//  Vérification des valeurs des différents constructeurs

void Image::testConstructeursValide()
{
    Image ImDefaut; // Appel du constructeur par défaut (Image noire)
    assert(ImDefaut.dimx == 0 && ImDefaut.dimy == 0 && ImDefaut.tab == nullptr);

    Image ImPara(36, 20); // Appel du constructeur avec des paramètres
    assert(ImPara.dimx == 36 && ImPara.dimy == 20 && ImPara.tab != nullptr);

    Image ImGrande(3000, 2000); // Appel du constructeur avec des paramètres
    assert(ImGrande.dimx == 3000 && ImGrande.dimy == 2000 && ImGrande.tab != nullptr);

    Image ImCopie(ImPara); // Appel du constructeur de copie
    assert(ImCopie.dimx == ImPara.dimx && ImCopie.dimy == ImPara.dimy && ImCopie.tab != ImPara.tab);

    // Création d'une Image avec un pointeur
    Image *ImPtr = new Image(5, 5);
    assert(ImPtr->dimx == 5 && ImPtr->dimy == 5);

    delete ImPtr;

        Pixel blanc(255, 255, 255);

    // Vérifier la création d'un PIXEL avec paramètres.
    assert(blanc.getRouge() == 255);
    assert(blanc.getBleu() == 255);
    assert(blanc.getVert() == 255);

    // Vérification de la création du PIXEL par défaut qui est noir
    Pixel noir;
    assert(noir.getRouge() == 0 && noir.getBleu() == 0 && noir.getVert() == 0);

    //  création d'une IMAGE 15x10
    Image ImTest(15, 10);

    assert(ImTest.dimx == 15 && ImTest.dimy == 10 && ImTest.tab != nullptr);

    // Création d'un deuxième PIXEL Blanc
    Pixel Blanc2(255, 255, 255);

    // Vérification de la surcharge de l'opérateur == avec deux PIXELS
    //  On vérifie que le résultat du booléen est le meme.
    //  Entre l'opérateur et la comparaison des  3 composantes d'un Pixel(Toutes les comparaisons)

    assert((noir == blanc) == ((noir.getBleu() == blanc.getBleu())&( noir.getRouge() == blanc.getRouge())&(noir.getVert() == blanc.getVert())));


    // on vérifie la fonction getPix. Une Image par défaut est noir.
    //assert(ImTest.getPix(15, 10) == noir);

    // Vérifier la fonction setPixel()
    ImTest.setPix(5, 7, blanc);
   assert(ImTest.getPix(5, 7) == blanc);
}

// Deuxième fonction de régression.
// Test des assertions  des constructeurs

void Image::testConstructeursInvalide()
{
    // Image ImValide(78,35);
    // Constructeurs valide pour etre le paramètre du constructeur par copie
    try
    {
        Image ImNégatif(-2, 20); // Appel du constructeur avec des paramètres
    }
    catch (const std::exception &e)
    {
        std::cout << "erreur pour la création d'une image négative " << e.what() << '\n';
    }

    try
    {
        Image ImTropGrande(500000000, 1);
    }
    catch (const std::exception &e)
    {
        std::cout << "erreur pour la création d'une grande image " << e.what() << '\n';
    }
}

void Image::testfonction()
{
    Pixel blanc(255, 255, 255);

    // Vérifier la création d'un PIXEL avec paramètres.
    assert(blanc.getRouge() == 255);
    assert(blanc.getBleu() == 255);
    assert(blanc.getVert() == 255);

    // Vérification de la création du PIXEL par défaut qui est noir
    Pixel noir;
    assert(noir.getRouge() == 0 && noir.getBleu() == 0 && noir.getVert() == 0);

    //  création d'une IMAGE 15x10
    Image ImTest(15, 10);

    assert(ImTest.dimx == 15 && ImTest.dimy == 10 && ImTest.tab != nullptr);

    // Création d'un deuxième PIXEL Blanc
    Pixel Blanc2(255, 255, 255);

    // Vérification de la surcharge de l'opérateur == avec deux PIXELS
    //  On vérifie que le résultat du booléen est le meme.
    //  Entre l'opérateur et la comparaison des  3 composantes d'un Pixel(Toutes les comparaisons)

    assert((noir == blanc) == ((noir.getBleu() == blanc.getBleu())&( noir.getRouge() == blanc.getRouge())&(noir.getVert() == blanc.getVert())));


    // on vérifie la fonction getPix. Une Image par défaut est noir.
    assert(ImTest.getPix(15, 10) == noir);

    // Vérifier la fonction setPixel()
    ImTest.setPix(5, 7, blanc);
    assert(ImTest.getPix(5, 7) == blanc);
}

void Image::afficherBoucle()
{
    SDL_Event events;
    bool quit = false;

    // tant que ce n'est pas la fin ...
    while (!quit)
    {

        // tant qu'il y a des evenements à traiter (cette boucle n'est pas bloquante)
        while (SDL_PollEvent(&events))
        {
            ///Si il appuie sur quitter ou sur échappe
            if (events.type == SDL_QUIT || events.type == SDLK_ESCAPE)
                quit = true; // Si l'utilisateur a clique sur la croix de fermeture
            else if (events.type == SDL_KEYDOWN)
            {
                switch (events.key.keysym.scancode)
                {
                case SDL_SCANCODE_ESCAPE:
                case SDL_SCANCODE_Q:
                    quit = true;
                    break;
                default:
                    break;
                }
            }
        }

        //Actualisation
        // on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)
        SDL_RenderPresent(m_renderer);
    }
}



void Image::afficherInit(const unsigned int & dimx,const unsigned int &dimy)
{
   

    // Creation de la fenetre
    m_window = SDL_CreateWindow("Image", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimx, dimy, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (m_window == NULL)
    {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(m_renderer, 160, 160, 160, 255);

    // IMAGES
    sauver("../data/image1.ppm");

    m_image = IMG_Load("../data/image_aff.ppm");


    m_text2 = SDL_CreateTextureFromSurface(m_renderer, m_image);

    SDL_RenderPresent(m_renderer);
}

void Image::afficherDetruit()
{
    TTF_Quit();
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void Image::afficher()
{
    afficherInit(200,200);
    afficherBoucle();
    afficherDetruit();
}
