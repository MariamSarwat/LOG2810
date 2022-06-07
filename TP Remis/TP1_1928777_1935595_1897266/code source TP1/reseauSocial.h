/////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Titre:		 Travail pratique #1 -reseauSocial.h
/// Date:		 3 mars 2019
/// Auteurs:	 Mariam Sarwat (1928777), Yasmina Abou-Nakkoul (1897266) et Stéphanie Mansour (1935595)
////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef reseauSocial_h
#define reseauSocial_h

#include <iomanip>  
#include "individu.h"
#include "relation.h"

using namespace std;

class ReseauSocial {
public:
    ReseauSocial();
    
    vector<Individu> getIndividus () const;
    vector<Relation> getRelations () const;

    bool creerReseauSocial(string fichierIndiv, string fichierRelat);

	void afficherIndividus();
	void afficherRelations(); 
	void afficherReseauSocial(vector <Relation> relations);

private:
    vector <Individu> individus_;
	vector <Relation> relationsIndividus_;
};
#endif
