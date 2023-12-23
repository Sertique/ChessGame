#include "EchiquierT.hpp"
#include "Piece.hpp"

using namespace std;

/* Initialise l'échiquier. Les couleurs sont constantes.
 * La première partie (1*) demande au(x) joueur(s) quel mode est choisi est agit en conséquence. 
 * En cas de mode non fonctionnel, la valeur 0 permet de passer rapidement à la fin du script.
 * La seconde partie (2*) initialise la couleur des joueurs actifs, elle ne fonctionne que pour un joueur face à un bot.
 * La troisième partie (3*) initialise l'échiquier, celui-ci est représenté dans la "./fiche-projet.txt".
 */

Echiquier::Echiquier() : m_couleurBlanc("w") , m_couleurNoir("b"), m_espaceEntreChaqueCase("      "), m_sautDeLigneEchiquier("\n\n\n"), m_dernierSautDeLigne("\n\n")
{
  //Initialise toutes les cases à nullptr pour simplifier l'écriture du programme.
  for (int i(0) ; i < 8 ; i++)
  {
    for (int j(0) ; j < 8 ; j++)
    {
      m_echiquierPieces[i][j] = nullptr;
    }
  }

  m_roiBlanc = Roi(this, 4, m_couleurBlanc);
  m_roiNoir = Roi(this, 4, m_couleurNoir);
  m_dameBlanche = Dame(this, 3, m_couleurBlanc);
  m_dameNoire = Dame(this, 3, m_couleurNoir);
  
  m_cavalierBlancA = Cavalier(this, 1, m_couleurBlanc);
  m_cavalierBlancB = Cavalier(this, 6, m_couleurBlanc);
  m_cavalierNoirA = Cavalier(this, 1, m_couleurNoir);
  m_cavalierNoirB = Cavalier(this, 6, m_couleurNoir);
  
  

  // Range les pièces dans les bons tableaux pour les trouver facilement. => pour l'instant c'est inutile =======>>>>>> il faut les initialiser dans l'échiquier */
  m_piecesBlanches[0] = &m_roiBlanc;  

  m_piecesNoires[0] = &m_roiNoir;

  
  /* pair.first => x ; pair.second => y */
  /* mouvCava */
    mouvCava[0] = pair<int, int> (1, 2);
    mouvCava[1] = pair<int, int> (2, 1);
    mouvCava[2] = pair<int, int> (2, -1);
    mouvCava[3] = pair<int, int> (1, -2);
    mouvCava[4] = pair<int, int> (-1, -2);
    mouvCava[5] = pair<int, int> (-2, -1);
    mouvCava[6] = pair<int, int> (-2, 1);
    mouvCava[7] = pair<int, int> (-1, 2);
  /* mouvTour :  Multiplier les valeurs du tableaux par le nb de case parcourues */
    mouvTour[0] = pair<int, int> (0, 1);
    mouvTour[1] = pair<int, int> (1, 0);
    mouvTour[2] = pair<int, int> (0, -1);
    mouvTour[3] = pair<int, int> (-1, 0);
  /* mouvFou :  Multiplier les valeurs du tableaux par le nb de case parcourues */
    mouvFou[0] = pair<int, int> (1, 1);
    mouvFou[1] = pair<int, int> (1, -1);
    mouvFou[2] = pair<int, int> (-1, -1);
    mouvFou[3] = pair<int, int> (-1, 1);
  /* mouvRoyaute */
    mouvRoyaute[0] = mouvTour[0]; /*mouvRoyaute[0] = pair<int, int> (0, 1);*/
    mouvRoyaute[1] = mouvTour[1]; /*mouvRoyaute[1] = pair<int, int> (1, 0);*/
    mouvRoyaute[2] = mouvTour[2];
    mouvRoyaute[3] = mouvTour[3];
    mouvRoyaute[4] = mouvFou[0];
    mouvRoyaute[5] = mouvFou[1];
    mouvRoyaute[6] = mouvFou[2];
    mouvRoyaute[7] = mouvFou[3];
  /* mouvPion */
    mouvPion[0] = mouvTour[0];
    mouvPion[1] = mouvTour[2];
    mouvPion[2] = mouvFou[0];
    mouvPion[3] = mouvFou[1];
    mouvPion[4] = mouvFou[2];
    mouvPion[5] = mouvFou[3];
    mouvPion[6] = pair<int, int> (0, 2);
    mouvPion[7] = pair<int, int> (0, -2); /* Si le pion n'a jamais avancé */

  m_affichageLettresEchiquierCoteBlanc = "\n" + m_espaceEntreChaqueCase + " A " + m_espaceEntreChaqueCase + "B " + m_espaceEntreChaqueCase + "C " + m_espaceEntreChaqueCase + "D " + m_espaceEntreChaqueCase + "E " + m_espaceEntreChaqueCase + "F " + m_espaceEntreChaqueCase + "G " + m_espaceEntreChaqueCase + "H\n";

  m_affichageLettresEchiquierCoteNoir = "\n" + m_espaceEntreChaqueCase + " H " + m_espaceEntreChaqueCase + "G " + m_espaceEntreChaqueCase + "F " + m_espaceEntreChaqueCase + "E " + m_espaceEntreChaqueCase + "D " + m_espaceEntreChaqueCase + "C " + m_espaceEntreChaqueCase + "B " + m_espaceEntreChaqueCase + "A\n";
  

  string modeChoisi;
  string const casePaire("XX");
  string const caseImpaire("OO");
  m_coteJoueur = m_couleurBlanc;
  m_coteAdversaire = m_couleurNoir;
  string lettreCase;
  string couleur;
  
  
 /*(3*)*/

  for (int i(0) ; i < 8 ; i++)
  {
    for (int j(0) ; j < 8 ; j++)
    {
      if (i % 2 == 0 && j % 2 == 0)
      {
        lettreCase = casePaire;
      } else if (i % 2 == 0 && j % 2 == 1)
      {
        lettreCase = caseImpaire;
      } else if (i % 2 == 1 && j % 2 == 0)
      {
        lettreCase = caseImpaire;
      } else if (i % 2 == 1 && j % 2 == 1)
      {
        lettreCase = casePaire;
      }
      
      m_echiquierCasesLettres[i][j] = lettreCase;
    }
  }

  /*(1*)*/
  cout << "Quel mode choisissez-vous ? (2BOT / HvsBot / HvsH)" << endl;
  cin >> modeChoisi;

  if (modeChoisi == "2BOT")
  {
    cout << "Ne fonctionne pas encore. Relancez le programme." << endl;
    m_modeFonctionnel = false;
  } else if (modeChoisi == "HvsBot")
  {
    cout << "Quelle couleur (BLANC ou NOIR) ?" << endl;
    cin >> couleur;
    initCouleurBot(couleur);
    cout << "Ne fonctionne pas encore. Relancez le programme." << endl;
    m_modeFonctionnel = false;
  } else if (modeChoisi == "HvsH" or modeChoisi == "t")
  {
    cout << "Les blancs commencent. Bonne partie." << endl;
    m_modeFonctionnel = true;
    partieADeuxHumains();
  } else 
  {
    cout << "Le mode demandé est mal écrit, réessayez après avoir relancé le programme." << endl;
    m_modeFonctionnel = false;
  }

  
}

void Echiquier::afficherCases()
{
  if (m_modeFonctionnel)
  {
    cout << "O => case blanche\nX => case noire\n\nCôté "<< m_coteAdversaire << "\n\n";
    if (m_coteJoueur == m_couleurBlanc)
    {
      for (int y(7) ; y >= 0 ; y--)
      {
        cout << y + 1 ;

        for (int x(0) ; x <= 7 ; x++)
        {
          cout << m_espaceEntreChaqueCase  << m_echiquierCasesLettres[x][y];
        }
      if (y == 0)
       {
          cout << m_dernierSautDeLigne;
       } else {
         cout << m_sautDeLigneEchiquier;
       }
      }
      cout << m_affichageLettresEchiquierCoteBlanc;
      
    } else if (m_coteJoueur == m_couleurNoir)
    {
      for (int y(0) ; y <= 7 ; y++)
      {
        cout << y + 1 ;
        for (int x(7) ; x >= 0 ; x--)
        {
          cout << m_espaceEntreChaqueCase << m_echiquierCasesLettres[x][y];
        }
        if (y == 7)
       {
          cout << m_dernierSautDeLigne;
       } else {
         cout << m_sautDeLigneEchiquier;
       }
      
      }
      cout << m_affichageLettresEchiquierCoteNoir;
    }
  
    cout << "\nCôté " << m_coteJoueur << endl;

  }
}

void Echiquier::afficherJeu()
{
  if (m_modeFonctionnel)
  {
   initialiserEchiquierAAfficher();
   cout << "O => case blanche\nX => case noire\n\nCôté "<< m_coteAdversaire << "\n\n";
   if (m_coteJoueur == m_couleurBlanc)
   {
     for (int y(7) ; y >= 0 ; y--)
     {
       cout << y + 1 ;

       for (int x(0) ; x <= 7 ; x++)
       {
         cout << m_espaceEntreChaqueCase << m_echiquierAffichageJeu[x][y];
       }
      if (y == 0)
       {
          cout << m_dernierSautDeLigne;
       } else {
         cout << m_sautDeLigneEchiquier;
       }
     }
     cout << m_affichageLettresEchiquierCoteBlanc;
     
   } else if (m_coteJoueur == m_couleurNoir)
   {
     for (int y(0) ; y <= 7 ; y++)
     {
       cout << y + 1 ;
       for (int x(7) ; x >= 0 ; x--)
       {
        cout << m_espaceEntreChaqueCase << m_echiquierAffichageJeu[x][y];
       }
       if (y == 7)
       {
          cout << m_dernierSautDeLigne;
       } else {
         cout << m_sautDeLigneEchiquier;
       }
      
       
     }
     cout << m_affichageLettresEchiquierCoteNoir;
  } 
  
   cout << "\nCôté " << m_coteJoueur << endl;
  }
}

void Echiquier::initialiserEchiquierAAfficher()
{
  string lettreCouleur;
  for (int x(0) ; x < 8 ; x++)
  {
    for (int y(0) ; y < 8 ; y++)
    {
      if (verificationSiContientPiece(x, y))
      {
        if (m_echiquierPieces[x][y]->getCouleur() == m_couleurBlanc)
        {
          lettreCouleur = m_couleurBlanc;
        } else if (m_echiquierPieces[x][y]->getCouleur() == m_couleurNoir)
        {
          lettreCouleur = m_couleurNoir;
        }

        m_echiquierAffichageJeu[x][y] = m_echiquierPieces[x][y]->getIconPiece() + lettreCouleur;
      }
      else {
        m_echiquierAffichageJeu[x][y] = m_echiquierCasesLettres[x][y];
      }
    }
  }
}

bool Echiquier::verificationSiContientPiece(int X, int Y)
{
  if (m_echiquierPieces[X][Y] == nullptr)
  {
    return false;
  } else {
    return true;
  } 
}

void Echiquier::initCouleurBot(string couleur)
  {
        /*(2*)*/
  if (couleur == m_couleurBlanc)
  {
    /* UNIQUEMENT SI C'EST FACE A UN BOT */
    m_coteJoueur = m_couleurBlanc; // Blanc 
    m_coteAdversaire = m_couleurNoir; // Noir 
  } else if (couleur == m_couleurNoir)
  {
    m_coteJoueur = m_couleurNoir; // Noir
    m_coteAdversaire = m_couleurBlanc; // Blanc

  }
}


Piece* Echiquier::get_Cases(unsigned int x, unsigned int y)
{
  return m_echiquierPieces[x][y]; /* Là */
}

void Echiquier::viderCasePiece(unsigned int x, unsigned int y) 
{
  m_echiquierPieces[x][y] = nullptr; 
}


void Echiquier::modifierCasePiece(unsigned int x, unsigned int y, Piece *pieceConcernee)
{
  m_echiquierPieces[x][y] = pieceConcernee; 
}

bool Echiquier::verificationSiLaPiecePeutPasser(unsigned int xAvant, unsigned int yAvant, unsigned int xApres, unsigned int yApres, bool laPieceSauteParDessusLesAutres)
{
  if (laPieceSauteParDessusLesAutres)
  {
    return true;
  } else {
    int differenceX(yAvant - yApres);
    int differenceY(yAvant - yApres);
    cout << "Test :\n" << differenceX << endl << differenceY << endl; /* Pour tester d'où vient le problème */

    bool vide(true);
    if (differenceX > 0 and differenceY == 0)
    {
      for (int i(1) ; i < differenceX ; i++) /* S'arrête avant la case d'arrivée  --- Mouvement ligne*/
      {
        if (m_echiquierPieces[xAvant + i][yAvant] != nullptr)
        {
          vide = false;
        }
      }
    } else if (differenceX < 0 and differenceY == 0) /* Mouvement ligne */
    {
      for (int i(-1) ; i > differenceX ; i--)
      {
        if (m_echiquierPieces[xAvant + i][yApres] != nullptr)
        {
          vide = false;
        }
      }
    } else if (differenceX == 0 and differenceY > 0) /* Mouvement colonne */
    {
      for (int i(1) ; i < differenceY ; i++)
      {
        if (m_echiquierPieces[xAvant][yAvant + i] != nullptr)
        {
          vide = false;
        }
      }
    } else if (differenceX == 0 and differenceY < 0) /* Mouvement colonne */
    {
      for (int i(-1) ; i > differenceY ; i--)
      {
        if (m_echiquierPieces[xAvant][yAvant + i] != nullptr)
        {
          vide = false;
        }
      }
    } else if (differenceX > 0 and differenceY > 0)
    {
      for (int i(1) ; i < differenceX ; i++)
      {
        if (m_echiquierPieces[xAvant + i][yAvant + i] != nullptr)
        {
          vide = false;
        }
      }
    } else if (differenceX < 0 and differenceY < 0)
    {
      for (int i(-1) ; i > differenceX ; i--)
      {
        if (m_echiquierPieces[xAvant + i][yAvant + i] != nullptr)
        {
          vide = false;
        }
      }
    } else if (differenceX < 0 and differenceY > 0)
    {
      for (int i(-1) ; i > differenceX ; i--)
      {
        if (m_echiquierPieces[xAvant + i][yAvant - i] != nullptr)
        {
          vide = false;
        }
      }
    } else if (differenceX > 0 and differenceY < 0)
    {
      for (int i(1) ; i < differenceX ; i++)
      {
        if (m_echiquierPieces[xAvant + i][yAvant - i] != nullptr)
        {
          vide = false;
        }
      }
    } else {
      vide = false;
    }


    if (vide)
    {
      return true;
    } else {
      return false;
    }
  }
}



int Echiquier::conversionLettreInt(string lettreAConvertir)
{
  if (lettreAConvertir == "a")
  {
    return 0;
  } else if (lettreAConvertir == "b")
  {
    return 1;
  } else if (lettreAConvertir == "c")
  {
    return 2;
  } else if (lettreAConvertir == "d")
  {
    return 3;
  } else if (lettreAConvertir == "e")
  {
    return 4;
  } else if (lettreAConvertir == "f")
  {
    return 5;
  } else if (lettreAConvertir == "g")
  {
    return 6;
  } else if (lettreAConvertir == "h")
  {
    return 7;
  } else {
    return -1;
  }
}

int Echiquier::conversionChiffreInt(string chiffreAConvertir)
{
  if (chiffreAConvertir == "1")
  {
    return 0;
  } else if (chiffreAConvertir == "2")
  {
    return 1;
  } else if (chiffreAConvertir == "3")
  {
    return 2;
  } else if (chiffreAConvertir == "4")
  {
    return 3;
  } else if (chiffreAConvertir == "5")
  {
    return 4;
  } else if (chiffreAConvertir == "6")
  {
    return 5;
  } else if (chiffreAConvertir == "7")
  {
    return 6;
  } else if (chiffreAConvertir == "8")
  {
    return 7;
  } else {
    return -1;
  }
}

string Echiquier::getCouleurJoueur()
{
  if (m_coteJoueur == m_couleurBlanc)
  {
    return "blanc";
  }
  return "noir";
}

void Echiquier::changerDeJoueur()
{
  if (m_modeFonctionnel)
  {
    string stockTemporaire = m_coteJoueur;
    m_coteJoueur = m_coteAdversaire;
    m_coteAdversaire = stockTemporaire;
  }
}

bool Echiquier::verifSiCaseExiste(int xTest, int yTest)
{
  return (xTest < 8 and yTest < 8 and xTest >= 0 and yTest >= 0);
}

bool Echiquier::toutesDirectionsBannies(bool directionsBannies[])
{
  for (int i(0) ; i < 8 ; i++)
  {
    if (!directionsBannies[i])
    {
      return false;
    }
  }
  return true;
}

pair<int, int> Echiquier::rechercheRoi(string couleurRoi)
{
  Piece* roiAVerifier;
  int x;
  int y;

  for (int i(0) ; i < 8 ; i++)
  {
    for (int j(0) ; j < 8 ; j++)
    {
      if (m_echiquierPieces[i][j]->getCouleur() == couleurRoi && m_echiquierPieces[i][j]->getLettrePiece() == "K")
      {
        roiAVerifier = m_echiquierPieces[i][j];
        x = i;
        y = j;
        goto finRecherche;
      }
    }
  }
  finRecherche:
  {
    return pair<int, int> (x, y);
  }

  return pair<int, int> (-1, -1); /* Si le roi n'existe pas (dans le doute). */
}

bool Echiquier::verificationEchec(int x, int y, string couleurPiece) /* Exemple : pair<int, int> coorRoi(rechercheRoi(m_couleurNoir)); verificationEchec(coorRoi.first, coorRoi.second); */
{
  Piece* caseAVerifier(m_echiquierPieces[x][y]);
  string couleurAdverse;
  int xTest;
  int yTest;
  Piece* caseVerifiee;
  vector<Piece*> piecePossible;
  int nbPieceTypeCorrect(0);
  bool directionsBannies[8] = {false, false, false, false, false, false, false, false};

  if (couleurPiece  == m_couleurBlanc)
  {
    couleurAdverse = m_couleurNoir;
  } else 
  {
    couleurAdverse = m_couleurBlanc;
  }
  
  for (int i(0) ; i < 8 ; i++) /* Applique le déplacement du cavalier */
    {
      xTest = x + mouvCava[i].first;
      yTest = y + mouvCava[i].second;

      if (verifSiCaseExiste(xTest, yTest)) /* Permet de vérifier si la case vérifiée existe. */
      {
        caseVerifiee = m_echiquierPieces[xTest][yTest];
        if (caseVerifiee != nullptr && caseVerifiee->getLettrePiece() == "N" && caseVerifiee->getCouleur() == couleurAdverse)
        {
          piecePossible.push_back(caseVerifiee);
          nbPieceTypeCorrect++;
        }
      }
    }

  while (!toutesDirectionsBannies(directionsBannies))
  {
    
  }

  /* Faire la vérification pour les autres pièces. => bannir les directions bloquées par une pièce (alliée ou adverse) / Appliquer tous les types de mouvements et vérifier si le mouvement correspond à la pièce trouver */

  return false;
}




Piece* Echiquier::recherchePiecePossible(string lettrePieceJouee, int xArrivee, int yArrivee, string disctinctionOrigine, string couleur) /* Trouve une pièce donnée à partir d'une case d'arrivée donnée */
{
  
    vector<Piece*> piecePossible;
    Piece* caseVerifiee;
    int xTest;
    int yTest;
    unsigned int nbPieceTypeCorrect(0);
    bool directionBannie[8] = {false, false, false, false, false, false, false, false};
    unsigned int c(0);
    unsigned int ctour(0);

  if (lettrePieceJouee == "K")
  {
    for (int i(0) ; i < 8 ; i++)
    {
      xTest = xArrivee + mouvRoyaute[i].first;
      yTest = yArrivee + mouvRoyaute[i].second;
      
      if (verifSiCaseExiste(xTest, yTest))
      {
        caseVerifiee = m_echiquierPieces[xTest][yTest];
        if (caseVerifiee != nullptr && caseVerifiee->getCouleur() == couleur && caseVerifiee->getLettrePiece() == lettrePieceJouee)
        {
          piecePossible.push_back(caseVerifiee);
          nbPieceTypeCorrect++;
        }
      } 
    }
  } else if (lettrePieceJouee == "Q")
  {
    while (!toutesDirectionsBannies(directionBannie))
    {
      c %= 8;
      if (c == 0)
      {
        ctour++;
      }
      xTest = xArrivee + ctour * mouvRoyaute[c].first;
      yTest = yArrivee + ctour * mouvRoyaute[c].second;

      if (verifSiCaseExiste(xTest, yTest) && !directionBannie[c])
      {
        /*cout << xTest << " : " << yTest << " = " << verifSiCaseExiste(xTest, yTest) << endl;*/
        caseVerifiee = m_echiquierPieces[xTest][yTest];
        if (caseVerifiee != nullptr && caseVerifiee->getLettrePiece() == lettrePieceJouee && caseVerifiee->getCouleur() == couleur)
        {
          piecePossible.push_back(caseVerifiee);
          directionBannie[c] = true;
          nbPieceTypeCorrect++;
          /*cout << c << " est banni." << endl;*/
        } else if (caseVerifiee != nullptr)
        {
          directionBannie[c] = true;
          /*cout << c << " est banni." << endl;*/
        }
      } else if (!directionBannie[c] && !verifSiCaseExiste(xTest, yTest))
      {
        /*cout << c << " ban" << endl;*/
        directionBannie[c] = true;
      }
      c++;
    }
  } else if (lettrePieceJouee == "R")
  {
    while (!toutesDirectionsBannies(directionBannie))
    {
      c %= 8;
      if (c == 0)
      {
        ctour++;
      }
      xTest = xArrivee + ctour * mouvTour[c].first;
      yTest = yArrivee + ctour * mouvTour[c].second;

      if (verifSiCaseExiste(xTest, yTest) && !directionBannie[c])
      {
        caseVerifiee = m_echiquierPieces[xTest][yTest];
        if (caseVerifiee != nullptr && caseVerifiee->getLettrePiece() == lettrePieceJouee && caseVerifiee->getCouleur() == couleur)
        {
          piecePossible.push_back(caseVerifiee);
          directionBannie[c] = true;
          nbPieceTypeCorrect++;
        } else if (caseVerifiee != nullptr)
      {
        directionBannie[c] = true;
      }
      } else if (!directionBannie[c] && !verifSiCaseExiste(xTest, yTest))
      {
        directionBannie[c] = true;
      }
      c++;
    }
  } else if (lettrePieceJouee == "B")
  {
    while (!toutesDirectionsBannies(directionBannie))
    {
      c %= 8;
      if (c == 0)
      {
        ctour++;
      }
      xTest = xArrivee + ctour * mouvFou[c].first;
      yTest = yArrivee + ctour * mouvFou[c].second;

      if (verifSiCaseExiste(xTest, yTest) && !directionBannie[c])
      {
        caseVerifiee = m_echiquierPieces[xTest][yTest];
        if (caseVerifiee != nullptr && caseVerifiee->getLettrePiece() == lettrePieceJouee && caseVerifiee->getCouleur() == couleur)
        {
          piecePossible.push_back(caseVerifiee);
          directionBannie[c] = true;
          nbPieceTypeCorrect++;
        } else if (caseVerifiee != nullptr)
        {
          directionBannie[c] = true;
        }
      } else if (!directionBannie[c] && !verifSiCaseExiste(xTest, yTest))
      c++;
    }
  } else if (lettrePieceJouee == "N")
  {
    for (int i(0) ; i < 8 ; i++) /* Applique le déplacement du cavalier */
    {
      xTest = xArrivee + mouvCava[i].first;
      yTest = yArrivee + mouvCava[i].second;

      if (verifSiCaseExiste(xTest, yTest)) /* Permet de vérifier si la case vérifiée existe. */
      {
        caseVerifiee = m_echiquierPieces[xTest][yTest];
        if (caseVerifiee != nullptr && caseVerifiee->getLettrePiece() == lettrePieceJouee && caseVerifiee->getCouleur() == couleur)
        {
          piecePossible.push_back(caseVerifiee);
          nbPieceTypeCorrect++;
        }
      }
    }
  } else if (lettrePieceJouee == "p")
  {
    if (couleur == m_couleurBlanc)
    {
      directionBannie[1] = true;
      directionBannie[3] = true;
      directionBannie[4] = true;
      directionBannie[7] = true;
    } else if (couleur == m_couleurNoir)
    {
      directionBannie[0] = true;
      directionBannie[2] = true;
      directionBannie[5] = true;
      directionBannie[6] = true;
    }
    for (int i(0) ; i < 8 ; i++)
    {
      xTest = xArrivee + mouvPion[i].first;
      yTest = yArrivee + mouvPion[i].second;

      if (verifSiCaseExiste(xTest, yTest) && !directionBannie[c])
      {
        caseVerifiee = m_echiquierPieces[xTest][yTest];
        if (caseVerifiee != nullptr && caseVerifiee->getLettrePiece() == lettrePieceJouee && caseVerifiee->getCouleur() == couleur)
        {
          piecePossible.push_back(caseVerifiee);
          nbPieceTypeCorrect++;
        }
      }
    }
  }
  /* Fin de la récupération des pièces possibles */

  /* Permet de renvoyer la pièce en fonction des pièces récupérés par piecePossible */

  if (nbPieceTypeCorrect == 1)
  {
    return piecePossible[0];

  } else if (nbPieceTypeCorrect > 1)
  {
    for (int i(0) ; i < piecePossible.size() ; i++)
    { /*                                                                          Verifiee la lettre de distinction */
      if (piecePossible[i]->getLigneActuelle() == disctinctionOrigine || piecePossible[i]->getCoordonneeYActuelle() == conversionChiffreInt(disctinctionOrigine)) 
      {
        return piecePossible[i];
      } else {
        cout << "Problème de distinction de l'origine de la pièce." << endl;
        return 0;
      }
    }
  } 

  cout << "Pièce recherchée introuvable." << endl;
  return 0;
}

bool Echiquier::getVerifLettre(string verifX)
{
  return verifX == "a" || verifX == "b" || verifX == "c" || verifX == "d" || verifX == "e" || verifX == "f" || verifX == "g" || verifX == "h" || verifX == "1" || verifX == "2" or verifX == "3" or verifX == "4" or verifX == "5" or verifX == "6" or verifX == "7" or verifX == "8";
}

bool Echiquier::getVerifLettre(char verifX)
{
  return verifX == 'a' || verifX == 'b' or verifX == 'c' or verifX == 'd' or verifX == 'e' or verifX == 'f' or verifX == 'g' or verifX == 'h' or verifX == '1' or verifX == '2' or verifX == '3' or verifX == '4' or verifX == '5' or verifX == '6' or verifX == '7' or verifX == '8';
}

bool Echiquier::verifContientEgal(string const& verifEgal)
{
  for (int i(0) ; i < verifEgal.size() ; i++)
  {
    if (verifEgal[i] == '=')
    {
      return true;
    }
  }
  return false;
}

void Echiquier::recuperationNotationMouvement(bool& joueurMat, string& coupJouer, string& pieceJouee, string& colonneArrivee, string& ligneArrivee, string& verifX, string& verifEchecOuMat, string& disctinctionOrigine, string& secondeDistinctionOrigine, string& verifPromotion, string& piecePromu, bool& notationCorrecte) /* à modifier */
{
  notationCorrecte = false;
  coupJouer.erase();
  pieceJouee.erase();
  colonneArrivee.erase();
  ligneArrivee.erase();
  disctinctionOrigine.erase();
  secondeDistinctionOrigine.erase();
  verifX.erase();
  verifEchecOuMat.erase();
  verifPromotion.erase();
  piecePromu.erase();
  
  
  while (!notationCorrecte) { // Pour la notation.
  cout << "Au joueur " << getCouleurJoueur() << " de jouer." << endl;
  cin >> coupJouer;

  

  if (coupJouer == "fin")
  {
    joueurMat = true;
    notationCorrecte = true;
  } else if (coupJouer == "O-O" or coupJouer == "O-O-O")
  {
    /* Appliquer le roque. */
    notationCorrecte = true;
  } else if (getVerifLettre(coupJouer[0])) /* Si la pièce est un pion */
  {
    pieceJouee = "p";
    disctinctionOrigine = coupJouer[0];
    verifX = coupJouer[1];
    secondeDistinctionOrigine.erase();

    switch (coupJouer.size())
    {
      case 3:
        ligneArrivee = coupJouer[1];
        colonneArrivee = coupJouer[2];
        notationCorrecte = true;
      case 4:
        verifEchecOuMat = coupJouer[3];
        if (verifEchecOuMat == "+" || verifEchecOuMat == "#")
        {
          colonneArrivee = coupJouer[1];
          ligneArrivee = coupJouer[2];
          notationCorrecte = true;
        } else if (verifX == "x")
        {
          colonneArrivee = coupJouer[2];
          ligneArrivee = coupJouer[3];
          notationCorrecte = true;
        }
        break;
      case 5:
        verifEchecOuMat = coupJouer[4];
        if ((verifPromotion = coupJouer[3]) == "=")
        {
          colonneArrivee = coupJouer[1];
          ligneArrivee = coupJouer[2];
          piecePromu = coupJouer[4];
          verifEchecOuMat.erase();
          notationCorrecte = true;
        } else if (verifX == "x" && (verifEchecOuMat == "+" || verifEchecOuMat == "#"))
        {
          colonneArrivee = coupJouer[2];
          ligneArrivee = coupJouer[3];
          verifPromotion.erase();
          notationCorrecte = true;
        }
        break;
      case 6:
        verifEchecOuMat = coupJouer[5];
        verifPromotion = coupJouer[4];
        if (verifX == "x" && verifPromotion == "=")
        {
          colonneArrivee = coupJouer[2];
          ligneArrivee = coupJouer[3];
          piecePromu = coupJouer[5];
          verifEchecOuMat.erase();
          notationCorrecte = true;
        } else if ((verifEchecOuMat == "+" || verifEchecOuMat == "#") && verifPromotion == "=")
        {
          colonneArrivee = coupJouer[1];
          ligneArrivee = coupJouer[2];
          piecePromu = coupJouer[4];
          verifX.erase();
          notationCorrecte = true;
        }
        break;
      case 7:
        colonneArrivee = coupJouer[2];
        ligneArrivee = coupJouer[3];
        verifPromotion = coupJouer[4];
        piecePromu = coupJouer[5];
        verifEchecOuMat = coupJouer[6];
        break;
      default:
        cout << "Mauvaise notation." << endl;
    }
  } else { /* Si la pièce n'est pas un pion */
    pieceJouee = coupJouer[0];

    switch (coupJouer.size()) {
      case 3: 
        colonneArrivee = coupJouer[1];
        ligneArrivee = coupJouer[2];
        notationCorrecte = true;
        break;
      case 4:
        verifEchecOuMat = coupJouer[3];
        verifX = coupJouer[1];
        if (verifEchecOuMat == "+" or verifEchecOuMat == "#")
        {
          colonneArrivee = coupJouer[1];
          ligneArrivee = coupJouer[2];
          notationCorrecte = true;
        } else {
          colonneArrivee = coupJouer[2];
          ligneArrivee = coupJouer[3];
          notationCorrecte = true;
        }
        if (verifX != "x" and getVerifLettre(verifX))
        {
          disctinctionOrigine = verifX;
          notationCorrecte = true;
        }
        break;
      case 5:
        verifEchecOuMat = coupJouer[4];
        verifX = coupJouer[1];
        if (verifEchecOuMat != "+" or verifEchecOuMat != "#")
        {
          disctinctionOrigine = coupJouer[1];
          verifX = coupJouer[2];
          colonneArrivee = coupJouer[3];
          ligneArrivee = coupJouer[4];
          verifEchecOuMat.erase();
          notationCorrecte = true;

        } else if (verifX == "x")
        {
          colonneArrivee = coupJouer[2];
          ligneArrivee = coupJouer[3];
          notationCorrecte = true;
      } else if (verifX != "x" and getVerifLettre(verifX))
        {
          disctinctionOrigine = verifX;
          verifX.erase();
          colonneArrivee = coupJouer[2];
          ligneArrivee[3];
          notationCorrecte = true;
        }
        break;
      case 6:
        disctinctionOrigine = coupJouer[1];
        verifX = coupJouer[2];
        colonneArrivee = coupJouer[3];
        ligneArrivee = coupJouer[4];
        verifEchecOuMat = coupJouer[5];
        notationCorrecte = true;
        break;
      default:
        cout << "Mauvaise notation." << endl;
      } // Fin du switch.
    } // Fin du else.
  }
}


void Echiquier::partieADeuxHumains()
{
  m_coteJoueur = m_couleurBlanc;
  bool joueurMat(false);
  string coupJouer;
  string pieceJouee;
  string colonneArrivee; // Lettre de la colonne d'arrivée.
  string ligneArrivee; // Nombre de la ligne d'arrivée.
  string verifX;
  string verifEchecOuMat;
  string disctinctionOrigine; // Si deux pièces peuvent aller au même endroit.
  string secondeDistinctionOrigine;
  string verifPromotion;
  string piecePromu;
  bool notationCorrecte;
  bool verifPieceCorrecte(false);


  afficherJeu();
  cout << "Tapez \"fin\" pour stopper le programme." << endl;

  while (!joueurMat)
  {
    verifPieceCorrecte = false;
    while (!verifPieceCorrecte)
    {
      recuperationNotationMouvement(joueurMat, coupJouer, pieceJouee, colonneArrivee, ligneArrivee, verifX, verifEchecOuMat, disctinctionOrigine, secondeDistinctionOrigine, verifPromotion, piecePromu, notationCorrecte);
      Piece* pieceADeplacer = recherchePiecePossible(pieceJouee, conversionLettreInt(colonneArrivee), conversionChiffreInt(ligneArrivee), disctinctionOrigine, m_coteJoueur); /* Ne prends pas en compte la seconde disctinction origine */

      if (pieceADeplacer != 0)
      {
        cout << pieceADeplacer << endl;
        pieceADeplacer->deplacement(conversionLettreInt(colonneArrivee), conversionChiffreInt(ligneArrivee)); /* Le problème vient de là */
        verifPieceCorrecte = true;
      } else if (joueurMat)
      {
        verifPieceCorrecte = true;
      }
    }

  changerDeJoueur();
  afficherJeu();

  }
}

  // Vérification si la lecture des coups fonctionne :
  /*cout << "Pièce jouée : " << pieceJouee << endl << " Si x : " << verifX << endl << "colonneArrivee : " << colonneArrivee << endl << "ligneArrivee : " << ligneArrivee << endl << 
    "Disction de l'origine : " << disctinctionOrigine << endl << "Si échec ou mat : " << verifEchecOuMat << endl;*/
