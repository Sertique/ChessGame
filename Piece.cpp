#include "Piece.hpp"
#include "EchiquierT.hpp"

using namespace std;


// Méthodes courantes du Roi:

Piece::Piece() {}

Piece::Piece(Echiquier *echiquier, int coordonneeXDeDepart, string lettrePiece, string couleurPiece, string iconPiece, bool laPiecePeutSauterParDessusLesAutres) : m_coordonneeXDeDepart(coordonneeXDeDepart) , m_lettrePiece(lettrePiece), m_couleurPiece(couleurPiece) , m_iconPiece(iconPiece), m_echiquier(echiquier), m_peutSauterParDessusLesPieces(laPiecePeutSauterParDessusLesAutres)
{
  unsigned int lignePiecesBlanche = 0;
  unsigned int lignePiecesNoire = 7;

  m_coordonneeXActuelle = coordonneeXDeDepart;

  if (m_lettrePiece == "p")
  {
  lignePiecesBlanche = 1;
  lignePiecesNoire = 6;
  }

  if (couleurPiece == "w") /* BLANC => w(hite) */
  {
    m_coordonneeYDeDepart = lignePiecesBlanche;
    m_coordonneeYActuelle = lignePiecesBlanche;
  } else if (couleurPiece == "b") /* NOIR => b(lack) */
  {

    m_coordonneeYDeDepart = lignePiecesNoire;
    m_coordonneeYActuelle = lignePiecesNoire;
  } else {
    cout << "Probleme de couleur pour la piece " << m_lettrePiece << endl;
  }

echiquier->modifierCasePiece(m_coordonneeXActuelle, m_coordonneeYActuelle, this);
}

void Piece::deplacement(int xApres, int yApres) 
{
  int avantX(m_coordonneeXActuelle);
  int avantY(m_coordonneeYActuelle);
  /* m_echiquier.verificationSiLaPiecePeutPasser(avantX, avantY, xApres, yApres, m_peutSauterParDessusLesPieces) =>  VERIFICATION SI LA VOIE EST LIBRE QUI RETURN FALSE SI CE N'EST PAS LE CAS ET TRUE LA VOIE EST LIBRE */

  if (0 <= xApres and xApres <= 7 and 0 <= yApres and yApres <= 7 and m_echiquier->get_Cases(xApres, yApres) == nullptr /*and m_echiquier->verificationSiLaPiecePeutPasser(avantX, avantY, xApres, yApres, m_peutSauterParDessusLesPieces)*/)
  {
    m_coordonneeXActuelle = xApres;
    m_coordonneeYActuelle = yApres;
    m_echiquier->modifierCasePiece(xApres, yApres, this);
    m_echiquier->viderCasePiece(avantX, avantY);
  } else if (0 <= xApres and xApres <= 7 and 0 <= yApres and yApres <= 7 and m_echiquier->get_Cases(xApres, yApres)->getCouleur() != m_couleurPiece /*and m_echiquier->verificationSiLaPiecePeutPasser(avantX, avantY, xApres, yApres, m_peutSauterParDessusLesPieces)*/){
    m_coordonneeXActuelle = xApres;
    m_coordonneeYActuelle = yApres;
    m_echiquier->modifierCasePiece(xApres, yApres, this);
    m_echiquier->viderCasePiece(avantX, avantY);
  } else if (0 <= xApres and xApres <= 7  and 0 <= yApres and yApres <= 7 and m_echiquier->get_Cases(xApres, yApres)->getCouleur() == m_couleurPiece /*and m_echiquier->verificationSiLaPiecePeutPasser(avantX, avantY, xApres, yApres, m_peutSauterParDessusLesPieces)*/)
  {
    cout << "Une pièce alliée est sur la case d'arrivée." << endl;
  } else {
    cout << "Mouvement impossible." << endl;
  }
}

bool Piece::verifMouvTour(int xApres, int yApres, int xAvant, int yAvant)
{ /*            deplacement sur ligne                                     deplacement sur colonne */
  int diffX(abs(xApres - xAvant));
  int diffY(abs(yApres - yAvant));

  return ( (xApres < 0 or  xApres > 0) and yApres == 0 ) or ( (yApres < 0 or yApres > 0) and xApres == 0 );
}

bool Piece::verifMouvFou(int xAvant, int yAvant, int xApres, int yApres)
{
  return ( abs(xApres - xAvant) == abs(yApres - yAvant) );
}


// GETTEUR
string Piece::getLettrePiece()
{
  return m_lettrePiece;
}

string Piece::getCouleur()
{
  return m_couleurPiece;
}

int Piece::getCoordonneeXDeDepart()
{
  return m_coordonneeXDeDepart;
}

int Piece::getCoordonneeYDeDepart()
{
  return m_coordonneeYDeDepart;
}

int Piece::getCoordonneeXActuelle()
{
  return m_coordonneeXActuelle;
}

int Piece::getCoordonneeYActuelle()
{
  return m_coordonneeYActuelle;
}

string Piece::getLigneActuelle()
{
  return to_string(m_coordonneeYActuelle + 1);
}

string Piece::getIconPiece()
{
  return m_iconPiece;
}

// ROI :
Roi::Roi() : Piece(){}
Roi::Roi(Echiquier *echiquierStockagePiece, int coordonneeXDeDepart, string couleurPiece) : Piece(echiquierStockagePiece, coordonneeXDeDepart, "K", couleurPiece, "", false), m_peutRoquer(true)
{}

unsigned int Roi::deplacement(int xApres, int yApres)
{
  if (verifMouvRoi(xApres, yApres))
  {
    Piece::deplacement(xApres, yApres);
    m_peutRoquer = false; /* Faire un fonction qui fasse le déplacement spéciale du roque */
    return 0;
  } else {
    return 1;
  }
}

bool Roi::verifMouvRoi(int xApres, int yApres)
{
  int diffX(abs(xApres - m_coordonneeXActuelle));
  cout << diffX << endl << xApres << endl << m_coordonneeXActuelle << endl;
  int diffY(abs(yApres - m_coordonneeYActuelle));
  cout << diffY << endl << yApres << endl << m_coordonneeYActuelle << endl;

  return ( (diffX == 1 or diffX == 0) and (diffY == 1 or diffY == 0) );
}

// REINE :
Dame::Dame() : Piece() {}

Dame::Dame(Echiquier *echiquierStockagePiece, int coordonneeXDeDepart, string couleurPiece) : Piece(echiquierStockagePiece, coordonneeXDeDepart, "Q", couleurPiece, "󰡚" /*""*/, false)
{}

unsigned int Dame::deplacement(int xApres, int yApres)
{
  int xAvant(m_coordonneeXActuelle); /* ==================== PROBLEME DE RECHERCHE INFINIE (POSSIBLEMENT DE LA PIECE) +++++++++++++++++++++++*/
  int yAvant(m_coordonneeYActuelle);
  /*                               deplacement en diagonale */
  if ( verifMouvTour(xApres, yApres, xAvant, yAvant) or verifMouvFou(xAvant, yAvant, xApres, yApres) )
  {
    Piece::deplacement(xApres, yApres);
    return 0;
  } else {
    return 1;
  }
}

// CAVALIER :
Cavalier::Cavalier() : Piece() {}

Cavalier::Cavalier(Echiquier *echiquierStockagePiece, int coordonneeXDeDepart, string couleurPiece) : Piece(echiquierStockagePiece, coordonneeXDeDepart, "N", couleurPiece, "", true)
{}

unsigned int Cavalier::deplacement(int xApres, int yApres)
{/*         A                                           B                                           C                                             D                                     E */
  if ( verifMouvCavalier(xApres, yApres))
  {
    Piece::deplacement(xApres, yApres);
    return 0;
  } else {
    return 1;
  }
}

bool Cavalier::verifMouvCavalier(int xApres, int yApres)
{
  int diffX(abs(xApres - m_coordonneeXActuelle));
  int diffY(abs(yApres - m_coordonneeYActuelle));

  return ( diffX == 1 and diffY == 2 ) or (diffX == 2 and diffY == 1 ) or (diffX == 2 and diffY == -1 ) or ( diffX == 1 and diffY == -2 ) or ( diffX == -1 and diffY == -2 ) or ( diffX == -2 and diffY == -1 ) or ( diffX == -2 and diffY == 1 ) or (diffX == -1 and diffY == 2 );
}




/* Servira peut-être un jour : */
void Piece::deplacementBOT(int directionX, int directionY) 
{
  int avantX(m_coordonneeXActuelle);
  int avantY(m_coordonneeYActuelle);
  int xApres(m_coordonneeXActuelle + directionX);
  int yApres(m_coordonneeYActuelle + directionY);
  /* m_echiquier.verificationSiLaPiecePeutPasser(avantX, avantY, xApres, yApres, m_peutSauterParDessusLesPieces) =>  VERIFICATION SI LA VOIE EST LIBRE QUI RETURN FALSE SI CE N'EST PAS LE CAS ET TRUE LA VOIE EST LIBRE */

  if (0 <= xApres and xApres <= 7 and 0 <= yApres and yApres <= 7 and m_echiquier->get_Cases(xApres, yApres) == nullptr and m_echiquier->verificationSiLaPiecePeutPasser(avantX, avantY, xApres, yApres, m_peutSauterParDessusLesPieces))
  {
    m_coordonneeXActuelle = xApres;
    m_coordonneeYActuelle = yApres;
    m_echiquier->modifierCasePiece(xApres, yApres, this);
    m_echiquier->viderCasePiece(avantX, avantY);
  } else if (0 <= xApres and xApres <= 7 and 0 <= yApres and yApres <= 7 and m_echiquier->get_Cases(xApres, yApres)->getCouleur() != m_couleurPiece and m_echiquier->verificationSiLaPiecePeutPasser(avantX, avantY, xApres, yApres, m_peutSauterParDessusLesPieces)){
    m_coordonneeXActuelle = xApres;
    m_coordonneeYActuelle = yApres;
    m_echiquier->modifierCasePiece(xApres, yApres, this);
    m_echiquier->viderCasePiece(avantX, avantY);
  } else if (0 <= xApres and xApres <= 7  and 0 <= yApres and yApres <= 7 and m_echiquier->get_Cases(xApres, yApres)->getCouleur() == m_couleurPiece and m_echiquier->verificationSiLaPiecePeutPasser(avantX, avantY, xApres, yApres, m_peutSauterParDessusLesPieces))
  {
    cout << "Une pièce alliée est sur la case d'arrivée." << endl;
  } else {
    cout << "Mouvement impossible." << endl;
  }
}
