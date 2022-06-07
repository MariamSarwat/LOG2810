/////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Titre:		 Travail pratique #2 - Automate.h
/// Date:		 2 avril 2019
/// Auteurs:	 Mariam Sarwat (1928777), Yasmina Abou-Nakkoul (1897266) et Stéphanie Mansour (1935595)
////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef Automate_h
#define Automate_h
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Automate {
    
public:
	Automate();
	
	vector<string> getMPValide() const;
	vector<string> getPCValide() const;
	vector<string> getporte_correspondante() const;
	vector<string> getmot_de_passe() const;
	vector<string> getmpValide() const;
	string getNomPorte() const;
	multimap<char, pair<char, char>> getRegles() const;

	void setPorteNom(string nom);
    
	void ajoutEtatTerminal(char etat);
    void genererAutomate(string fichier);
	vector<string> ouvrirPorte(string fichier);
    void valideMotDePasse(vector<string> mpAValider, vector<string> pcAValider, multimap<char, pair<char, char>> reglesLangue);

private:
    vector<string> porte_correspondante;
	vector<string> mot_de_passe;
	vector<char> etat_terminaux;
	multimap<char, pair<char, char>> regles;
    vector<multimap<char, pair<char, char>>> compare;
	vector<string> mpValide;
    vector<string> pcValide;
	string porte;
};

#endif
