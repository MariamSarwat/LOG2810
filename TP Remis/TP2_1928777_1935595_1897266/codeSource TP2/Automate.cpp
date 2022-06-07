/////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Titre:		 Travail pratique #2 - Automate.cpp
/// Date:		 2 avril 2019
/// Auteurs:	 Mariam Sarwat (1928777), Yasmina Abou-Nakkoul (1897266) et Stéphanie Mansour (1935595)
/// Description: Cette classe permet......
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Automate.h"
using namespace std;

Automate::Automate() {}

multimap<char, pair<char, char>> Automate::getRegles() const {
	return regles;
}

vector<string> Automate::getMPValide() const{
    return mpValide;
}

vector<string> Automate::getPCValide() const{
    return pcValide;
}

void Automate::setPorteNom(string nom) {
	porte = nom;
}

vector<string> Automate::getporte_correspondante() const {
	return porte_correspondante;
}

vector<string> Automate::getmot_de_passe() const {
	return mot_de_passe;
}

vector<string> Automate::getmpValide() const {
	return mpValide;
}

string Automate::getNomPorte() const {
	return porte;
}

//Permet d'ajouter un symbole terminal dans un vector etat_terminaux
void Automate::ajoutEtatTerminal(char etat){
    etat_terminaux.clear();
    etat_terminaux.push_back(etat);
}

//Lecture d'un fichier porte qui permet d'initialiser nos attributs avec les valeurs correspondants
void Automate::genererAutomate(string fichier){
    ifstream file(fichier);
    char lettre_sorti;
    char etat_prochain;
    string mot_passe;
    string porte;
    char etat_courant;
    char y = 'i';

    porte_correspondante.clear();
    mot_de_passe.clear();
    etat_terminaux.clear();
    regles.clear();
    mpValide.clear();
    pcValide.clear();

    if (!file.fail()) {
        while (!ws(file).eof()) {
            file >> etat_courant >> lettre_sorti >> etat_prochain;
            
			//Permet de trouver les symbole terminaux dans nos productions
            if(lettre_sorti == '!')
                y = etat_courant;
            if (etat_prochain == '_' || etat_prochain == y)
                etat_terminaux.push_back(lettre_sorti);

            if (etat_courant == ';') {
                do {
                    file >> mot_passe >> porte;
                    porte_correspondante.push_back(porte);
                    mot_de_passe.push_back(mot_passe);
                } while (!ws(file).eof());
            }
            else {
                regles.insert(pair<char, pair<char, char>>(etat_courant, make_pair(lettre_sorti, etat_prochain)));
            }
        }
    }
	else 
		cout << "\nIl y a eu une erreur dans la lecture du fichier " << fichier << endl;
}

//Fonction qui permet de valider les mots de passes retrouver dans un fichier porte.
void Automate::valideMotDePasse(vector<string> mpAValider, vector<string> pcAValider, multimap<char, pair<char, char>> reglesLangue){
	mpValide.clear();
    pcValide.clear();
    char nextEtat = 'S';
    bool nextStateFound = true;

    for (int j = 0; j < mpAValider.size(); j++){
        nextEtat = 'S';
        for (int i = 0; i < etat_terminaux.size(); i++) {
            unsigned long length_word = mpAValider[j].length();
            if ((mpAValider[j][length_word - 1] == etat_terminaux[i]) || mpAValider[j] == "vide") {
                if (mpAValider[j].size() > 1) {
                    for (int k = 0; k < mpAValider[j].length(); k++) {
                        nextStateFound = true;
                        for (auto findS : reglesLangue) {
                            if (findS.first == nextEtat && nextStateFound) {
                                if ((findS.second.first == mpAValider[j][k] )|| (mpAValider[j][k] == 'v' && mpAValider[j][k+1] == 'i' && mpAValider[j][k+2] == 'd' && mpAValider[j][k+3] == 'e' && findS.second.first == '!')) {
                                    if (mpAValider[j][k] == 'v')
                                        k+= 3;
                                    if (( k == (mpAValider[j].length()-1) && findS.second.first == etat_terminaux[i]) || ( mpAValider[j] == "vide" && findS.second.first == '!')){
										//Initialisation des vecteur de mot de passe et porte correspondantes valide avec les mdp valider
                                        mpValide.push_back(mpAValider[j]);
                                        pcValide.push_back(pcAValider[j]);
                                    }
                                    nextEtat = findS.second.second;
                                    nextStateFound = false;
                                }
                            }
                        }
                    }
                } else {
                    mpValide.push_back(mpAValider[j]);
                    pcValide.push_back(pcAValider[j]);
                }
            }
        }
    }
}

//Fonction qui fait appel a generer automate et valider mot de passe 
vector<string> Automate::ouvrirPorte(string fichier){
    genererAutomate(fichier);
    valideMotDePasse(mot_de_passe, porte_correspondante, regles);
    return mpValide;
}
