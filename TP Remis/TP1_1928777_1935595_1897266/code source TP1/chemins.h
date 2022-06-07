/////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Titre:		 Travail pratique #1 - chemins.h
/// Date:		 3 mars 2019
/// Auteurs:	 Mariam Sarwat (1928777), Yasmina Abou-Nakkoul (1897266) et Stéphanie Mansour (1935595)
////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef chemins_h
#define chemins_h

#include <stdio.h>
#include <limits.h>
#include "guessWho.h"

using namespace std;

class Chemins {
    
public:
    Chemins();
    
    vector<Individu> getIndividus() const;
    vector<Relation> getRelationsRestantes() const;
    void trouverChaineContacts(vector<Individu> vecteur, vector<Relation> vecteur1, Individu myst1, Individu myst2);
	int minDistance(int dist[], bool sptSet[]);
    
private:
    vector<Individu> individus_;
    vector<Relation> relationsRestantes_;
    
    Individu mystere1;
    Individu mystere2;
};

#endif
