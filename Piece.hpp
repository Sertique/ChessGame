#ifndef DEF_PIECE
#define DEF_PIECE

#include <iostream>
#include <string>
#include <cmath>

class Echiquier;

class Piece
{
  public:
    Piece();
    Piece(Echiquier *echiquier, int coordonneeXDeDepart, std::string lettrePiece, std::string couleurPiece, std::string iconPiece, bool laPiecePeutSauterParDessusLesAutres);
    void modifCoordonneX(int nouvelleCoordonneX);
    void modifCoordonneY(int nouvelleCoordonneY);
    void deplacementBOT(int directionX, int directionY);
    void deplacement(int xArrivee, int yArrivee);

    /*GETEUR*/
    std::string getLettrePiece();
    std::string getIconPiece();
    std::string getCouleur();
    int getCoordonneeXDeDepart();
    int getCoordonneeYDeDepart();
    int getCoordonneeXActuelle();
    int getCoordonneeYActuelle();

    std::string getColonneActuelle();
    std::string getLigneActuelle();

    bool verifMouvTour(int xApres, int yApres, int xAvant, int yAvant);
    bool verifMouvFou(int xAvant, int yAvant, int xApres, int yApres);
  
  protected:
    Echiquier *m_echiquier;

    std::string m_nomPiece;
    std::string m_lettrePiece;
    std::string m_iconPiece;
    std::string m_couleurPiece;
    int m_coordonneeXDeDepart;
    int m_coordonneeYDeDepart;
    int m_coordonneeXActuelle;
    int m_coordonneeYActuelle;
    bool m_peutSauterParDessusLesPieces;
};

class Roi : public Piece
{
  public:
    Roi(); /* permet de déclarer la pièce dans à un moment précis dans l'initialisation */
    Roi(Echiquier *echiquierStockagePiece, int coordonneeXDeDepart, std::string couleurPiece);
    unsigned int deplacement(int xApres, int yApres); /* => Faire en sorte d'appeler la fonction déplacement mère mais de limiter les déplacement de la Pièce */
    bool verifMouvRoi(int xApres, int yApres);
  private:
    bool m_peutRoquer;
};

class Dame : public Piece
{
  public:
    Dame();
    Dame(Echiquier *echiquierStockagePiece, int coordonneeXDeDepart, std::string couleurPiece);
    unsigned int deplacement(int xApres, int yApres);
};

class Cavalier : public Piece
{
  public:
    Cavalier();
    Cavalier(Echiquier *echiquierStockagePiece, int coordonneeXDeDepart, std::string couleurPiece);
    unsigned int deplacement(int xApres, int yApres);
    bool verifMouvCavalier(int xApres, int yApres);
};

#endif // DEF_PIECE
