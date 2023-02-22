#ifndef _IMAGE_H
#define _IMAGE_H
#include "Pixel.h"
#include <SDL2/SDL_ttf.h>


class Image
{
private:
    unsigned int dimx, dimy;
    Pixel *tab;

    // Variable SDL

    SDL_Surface *m_surface;
    SDL_Texture *m_texture;
    bool m_haschanged;
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    TTF_Font *m_font;

    // image de l'écran
    SDL_Surface *m_image;
    SDL_Texture *m_text2;

    /// @brief Affiche a l'écran et intéragit en fonction des actions sur le clavier et des conditions
    void afficherBoucle();


    /// @brief Initialise SDL. Crée une fenetre de dimension donnée en paramètre.
    /// Initialise ensuite le rendu de l'image dans la fenetre.
    /// Et la texture, la surface afficher
    void afficherInit(const unsigned int & dimx,const unsigned int &dimy);

    /// @brief Supprime tout ce qui a été crée et quitte la fenetre SDL
    void afficherDetruit();

public:
    /// @brief Constructeurs pas défaut qui crée une image vide. Sans dimension
    Image();

    /// @brief Constructeurs avec paramètre. Une image de la dimension des paramètres.
    /// @param x Un entier positif qui correspond a la dimension en largeur de l'image
    /// @param y Un entier positif qui correspond a la dimension en hauteur de l'image
    Image(unsigned int x, unsigned int y);/// Constructeurs avec paramètre. Une image de la dimension des paramètres.

    /// @brief Constructeurs par copie. Il prend la dimension et les pixels de l'image en paramètre.
    /// @param p Une Image passé en paramètre par donnée qui sera recopié. 
    Image(const Image &p); 

    ///Destructeurs
    ~Image();

    /// @brief Fonctions qui récupère un pixel d'une image.
    /// @param x Entier positif qui détermine la largeur du pixel recherché
    /// @param y Entier positif qui détermine la hauteur du pixel recherché
    /// @return L'adresse d'un Pixel de l'Image.
    Pixel &getPix(const unsigned int &x, const unsigned int &y) const;

    /// @brief Fonctions qui change la couleur d'un Pixel de l'Image.
    /// @param x Entiers positif ,hauteur de l'Image
    /// @param y Entiers positif ,largeur de l'Image
    /// @param couleur Un Pixel qui remplacera le Pixel correspondant aux dimensions données
    void setPix(unsigned int x, unsigned int y, const Pixel &couleur);

    /// @brief Procédure qui affiche chaque Pixel de l'Image et ses composantes RGB
    void AfficheStatImage() const;

    /// @brief Change la couleur des Pixels d'une Image avec les dimensions de debut et de fin en paramètre ainsi que la couleur
    void dessinerRectangle(const unsigned int &xmin, const unsigned int &xmax, const unsigned int &ymin, const unsigned int &ymax, const Pixel &couleur);

    /// @brief Colorie l'Image entièrement par la couleur en paramètre
    void effacer(const Pixel &couleur);


    /// @brief Fonctions de test :

    /// @brief Fonctions qui test si les constructeurs sont valide.
    void testConstructeursValide();

    /// @brief Fonction qui test les assertions des constructeurs avec des valeurs incorrectes
    void testConstructeursInvalide();

    /// @brief Fonction qui test les fonctionnalités des classes.
    void testfonction();

    /// @brief Fonction qui appel toutes les fonctions de test ensemble.
    void testRegression();

    void testRegressionBis();

    /// @brief Fonctions qui enregistre une image dans un fichier donné en paramètre
    void sauver(const string &filename) const;

    /// @brief L'image devient le fichier qu'elle a ouvert
    void ouvrir(const string &filename);

    /// @brief Affiche dans la console une image
    void afficherConsole();

    /// @brief Affichage SDL avec 3 fonctions. Initialisation , Boucle , Destruction
    void afficher();
};

#endif
