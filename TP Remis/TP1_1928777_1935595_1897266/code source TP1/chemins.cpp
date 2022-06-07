/////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Titre:		 Travail pratique #1 - chemins.cpp
/// Date:		 3 mars 2019
/// Auteurs:	 Mariam Sarwat (1928777), Yasmina Abou-Nakkoul (1897266) et Stéphanie Mansour (1935595)
/// Description: Cette classe permet de trouver le chemins le plus court entre les deux personnes 
///				 mysteres.
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "chemins.h"

Chemins::Chemins(){}

vector<Individu> Chemins::getIndividus() const {
    return individus_;
}
vector<Relation> Chemins::getRelationsRestantes() const {
    return relationsRestantes_;
}

int Chemins::minDistance(int dist[], bool sptSet[]) {
	// Initialise la valeur minimum a un maximum
	int min = INT_MAX;
	int min_index = 0;

	for (int v = 0; v < 50; v++) {
		if (sptSet[v] == false && dist[v] <= min) {
			min = dist[v];
			min_index = v;
		}
	}
	return min_index;
}

void Chemins::trouverChaineContacts(vector<Individu> vecteur, vector<Relation> vecteur1, Individu mystere1, Individu mystere2) {
	
    individus_ = vecteur;
	relationsRestantes_ = vecteur1;
    
    int const tailleMatrice = 50;
    // initialisation de la chaine de contacts
    vector <string> chaine;
	int matr[tailleMatrice][tailleMatrice] = { 0 };
	// crŽation de la matrice de relations restantes entre tous les individus
    for (int i = 0; i < individus_.size(); i++) {
		int j = 0;
		while (j < relationsRestantes_.size()) {
			if (individus_[i].getNom() == relationsRestantes_[j].getIndividusA().getNom()) {
				int k = 0;
				while (k < individus_.size()) {
					if (individus_[k].getNom() == relationsRestantes_[j].getIndividusB().getNom()) {
						matr[i][k] = relationsRestantes_[j].getRelation();
						matr[k][i] = relationsRestantes_[j].getRelation();
					}
					k++;
				}
			}
			j++;
		}
	}
    // affectation de la source au premier personnage mystere
	int source = 0;
	for (int i = 0; i < individus_.size(); i++) {
        if (individus_[i].getNom() == mystere1.getNom()) {
            source = i;
            i = 1000;
        }
	}
    // dist est le tableau contenant les cožts totaux des relations
	int dist[50];
    // sptSet permettra de determiner si la relation a dŽjˆ ŽtŽ prise en compte
	bool sptSet[50];

	// Initialise tout les distances a un nombre tres grand et stpSet[] comme faux
	for (int i = source; i < 50; i++) {
		dist[i] = INT_MAX;
		sptSet[i] = false;
	}
	// distance entre mystere1 et mystere1 est toujours egale a 0
	dist[source] = 0;

	//On retrouve le chemin le plus court 
    int f = 0;
    for (int i = 0; i < individus_.size(); i++) {
        if (individus_[i].getNom() == mystere2.getNom()) {
            f = i;
            i = 1000;
        }
    }

    for (int count = source; count < tailleMatrice - 1; count++) {
		// Choisir la distance minimum des vecteur pas encore toucher.
		int u = minDistance(dist, sptSet);
        sptSet[u] = true;
		
        for (int v = 0; v < individus_.size(); v++) {
            chaine.push_back(individus_[source].getNom());
            
            if (!sptSet[v] && matr[u][v] && dist[u] != INT_MAX && dist[u] + matr[u][v] < dist[v]) {
                dist[v] = dist[u] + matr[u][v];
            }
        }
    }
	if (dist[f] != INT_MAX) {
		chaine[f] += (" ==> " + individus_[f].getNom());
		cout << chaine[f] << endl;
	}
	else cout << "Il n'exite pas de chemin entre les deux individus mysteres";
}
