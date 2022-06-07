/////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Titre:		 Travail pratique #1 -guessWho.h
/// Date:		 3 mars 2019
/// Auteurs:	 Mariam Sarwat (1928777), Yasmina Abou-Nakkoul (1897266) et Stéphanie Mansour (1935595)
////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef guessWho_h
#define guessWho_h

#include "reseauSocial.h"

using namespace std;

class GuessWho {
public:
    GuessWho();

    Individu getMystere1() const;
    Individu getMystere2() const;
	vector<Individu> getIndividuRestant() const;
	vector<Relation> getRelation() const;
	int getNbQuestion() const;
	vector<string> getCharacIndes();
	vector<string> getCategorie();

	void setNbQuestion(int nbQuestion);
	void setMystere1(Individu mystere1);
    void setMystere2(Individu mystere2);

    void devinette(vector<Individu> vecteur);
    void afficherListeRestant(string reponse);
    void demanderQuestion(string question);
    void yeux(string charact, bool type);
    void departement(string charact, bool type);
    void cheveux(string charact, bool type);
    
	void identifierIndividus(vector<Individu> vecteur);
	void enleverArcsIndesirables(vector<Relation> vecteur);
	void afficherCaractere(string charact, string categorie);

private:
    Individu mystere1_;
    Individu mystere2_;
   
	vector<Individu> individuRestant_;
	vector<Relation> relation_;
	vector<string> characIndes_;
	vector<string> categorie_;

	string reponse_;
	int nbQuestion_;
	bool MysteresTrouvee_;
};
#endif
