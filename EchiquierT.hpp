#ifndef DEF_ECHIQUIERT
#define DEF_ECHIQUIERT

#include <string>
#include <cmath>
#include <vector>
#include <utility>
#include <iterator>
#include "Piece.hpp"

class Piece;

class Echiquier
{
  public:
    Echiquier();
    /*~Echiquier(); si un jour j'en ai besoin*/
    void afficherCases();
    void afficherPiece();
    void afficherJeu();
    void initialiserEchiquierAAfficher();
    Piece *get_Cases(unsigned int x, unsigned int y);
    void modifierCasePiece(unsigned int x, unsigned int y, Piece *pieceConcernee);
    void viderCasePiece(unsigned int x, unsigned int y);
    bool verificationSiLaPiecePeutPasser(unsigned int xAvant, unsigned int yAvant, unsigned int xApres, unsigned int yApres, bool laPieceSauteParDessusLesAutres);
    bool verifSiCaseExiste(int xTest, int yTest);
    bool getVerifLettre(std::string verifX);
    bool getVerifLettre(char verifX);
    bool verifContientEgal(std::string const& verifEgal);
    bool verificationSiContientPiece(int X, int Y);
    bool toutesDirectionsBannies(bool directionsBannies[]);

    std::string verifExiste();

    void partieADeuxHumains();
    void recuperationNotationMouvement(bool& joueurMat, std::string& coupJouer, std::string& pieceJouee, std::string& colonneArrivee, std::string& ligneArrivee, std::string& verifX, std::string& verifEchecOuMat, std::string& disctinctionOrigine, std::string& secondDistinctionOrigine, std::string& verifPromotion, std::string& piecePromu, bool& notationCorrecte);
    void changerDeJoueur();
    std::string getCouleurJoueur();
    void initCouleurBot(std::string couleur);
    int conversionLettreInt(std::string lettreAConvertir);
    int conversionChiffreInt(std::string chiffreAConvertir);
    
    Piece* recherchePiecePossible(std::string pieceJouee, int xArrivee, int yArrivee, std::string distinctionOrigine, std::string couleur); /* Pour vérifier chaque coordonnées des diffs pièces, utiliser des paires. */
    bool verificationEchec(int x, int y, std::string couleurPiece);
    std::pair<int, int> rechercheRoi(std::string couleurRoi);

    /* void accederCaseLettre(int x, int y);
    Piece* accederCasePieces(int x, int y);
    Piece& accederCasePieces2(int x, int y); */

  private:

    std::string m_echiquierCasesLettres[8][8];
    Piece *m_echiquierPieces[8][8];
    std::string m_echiquierAffichageJeu[8][8];
    Piece *m_piecesBlanches[16];
    Piece *m_piecesNoires[16];
    Piece *m_tourBlanches[10];
    Piece *m_tourNoires[10]; // 10 places dans le cas d'une promotion de tous les pions en tour (peu probable mais au cas où)
    
    std::string m_affichageLettresEchiquierCoteBlanc;
    std::string m_affichageLettresEchiquierCoteNoir;
    std::string m_espaceEntreChaqueCase;

    std::string m_couleurBlanc;
    std::string m_couleurNoir;
    std::string m_sautDeLigneEchiquier;
    std::string m_dernierSautDeLigne;
    std::string m_coteJoueur;
    std::string m_coteAdversaire;
    bool m_modeFonctionnel;

    std::pair<int, int> mouvRoyaute[8];
    std::pair<int, int> mouvCava[8];
    std::pair<int, int> mouvTour[4];
    std::pair<int, int> mouvFou[4];
    std::pair<int, int> mouvPion[8];

    Roi m_roiBlanc;
    Roi m_roiNoir;
    Dame m_dameBlanche;
    Dame m_dameNoire;
    
    Cavalier m_cavalierBlancA;
    Cavalier m_cavalierBlancB;
    Cavalier m_cavalierNoirA;
    Cavalier m_cavalierNoirB;
};


#endif // DEF_ECHIQUIERT
