/////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Titre:		 Travail pratique #2 - Automate.h
/// Date:		 2 avril 2019
/// Auteurs:	 Mariam Sarwat (1928777), Yasmina Abou-Nakkoul (1897266) et Stéphanie Mansour (1935595)
////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef Boss_h
#define Boss_h
#include "Automate.h"

using namespace std;

class Boss {
    
public:
    Boss(Automate automate);

    void setMdpFinal(string mdp);
	void setCheminPris(string porte);
    void setMdpBossAffichage(string mdp);
	
	string getmdpFinal() const;
	vector<string> getCheminPris() const;
    vector<int> getGouffre() const;

	void videCheminPris();
	void videMdpBossAffichage();
	void videMdpFinal();
    void remplirGouffre();
	
	void fillPorte();

	void affronterBoss(string fichier, string mdp);
	void afficherLeCheminParcouru(vector<string> porteChoisi);

private:
    multimap<char, pair<char,char>> langageFinal;
    string mdpFinal;
	vector<Automate> porte;
	Automate automate;
	vector<string> cheminPris;
	bool theSame;
	string mdpBossAffichage;
    bool passeParBoss;
    vector<int> gouffre;
};

#endif
