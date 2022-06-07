/////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Titre:		 Travail pratique #1 -reseauSocial.cpp
/// Date:		 3 mars 2019
/// Auteurs:	 Mariam Sarwat (1928777), Yasmina Abou-Nakkoul (1897266) et Stéphanie Mansour (1935595)
/// Description: Cette classe permet de lire un fichier d'individus et de relations afin d'etablir un
///              reseau social entre les individus.
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "reseauSocial.h"

ReseauSocial::ReseauSocial() {}

vector<Individu> ReseauSocial::getIndividus() const {
    return individus_;
}

vector<Relation> ReseauSocial::getRelations() const {
    return relationsIndividus_;
}

/* Fonction pour la lecture des fichiers qui permet la creation du reseau social */
bool ReseauSocial::creerReseauSocial(string fichierIndiv, string fichierRelat) {
	Individu tempI;
	Relation tempR;
	ifstream fileIndiv(fichierIndiv);
	ifstream fileR(fichierRelat);

	bool fichiersOuverts = false;

	if (!fileIndiv.fail() && !fileR.fail()) {
		fichiersOuverts = true;
		while (!ws(fileIndiv).eof()) {
			string nom, cheveux, yeux, genie;
			fileIndiv >> nom >> cheveux >> yeux >> genie;
			tempI.setNom(nom);
			tempI.setCheveux(cheveux);
			tempI.setYeux(yeux);
			tempI.setGenie(genie);

			individus_.push_back(tempI);
		}

		while (!ws(fileR).eof()) {
			string nomA, nomB;
			int relation;
			fileR >> nomA >> relation >> nomB;

			for (int i = 0; i < individus_.size(); i++) {
				if (individus_[i].getNom() == nomA)
					tempR.setIndividusA(individus_[i]);
			}

			tempR.setRelation((relation));

			for (int i = 0; i < individus_.size(); i++) {
				if (individus_[i].getNom() == nomB)
					tempR.setIndividusB(individus_[i]);
			}
			relationsIndividus_.push_back(tempR);
		}
	}
	else cout << "\nUn ou les deux fichiers n'ont pas pus etre ouvert. \n";
	return fichiersOuverts;
}

void ReseauSocial::afficherIndividus() {
	for (int i = 0; i < individus_.size(); i++) {
		cout << left << setw(15) << individus_[i].getNom()
			 << left << setw(5) << individus_[i].getCheveux()
			 << left << setw(5) << individus_[i].getYeux()
			 << individus_[i].getGenie() << left << setw(5) << endl;
	}
}

void ReseauSocial::afficherRelations() {
	for (int i = 0; i < relationsIndividus_.size(); i++) {
		cout << left << setw(15) << relationsIndividus_[i].getIndividusA().getNom()
			 << left << setw(10) << relationsIndividus_[i].getRelation()
			 << relationsIndividus_[i].getIndividusB().getNom() << left << setw(15) << endl;
	}
}

void ReseauSocial::afficherReseauSocial(vector <Relation> relations) {
	for (int i = 0; i < relations.size(); i++) {
		if (relations[i].getRelation() != 0) {
			cout << "(" << left << setw(15) << relations[i].getIndividusA().getNom() 
				<< left << setw(15) << relations[i].getIndividusB().getNom() << " ("
				<< relations[i].getRelation() << left << setw(5) << ") )"  << endl;
		}
	}
}

