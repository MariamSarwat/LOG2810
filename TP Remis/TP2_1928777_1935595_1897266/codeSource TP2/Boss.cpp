/////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Titre:		 Travail pratique #2 - Automate.cpp
/// Date:		 2 avril 2019
/// Auteurs:	 Mariam Sarwat (1928777), Yasmina Abou-Nakkoul (1897266) et Stéphanie Mansour (1935595)
/// Description: Cette classe permet......
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Boss.h"
using namespace std;
Boss::Boss(Automate autom){
	automate = autom;
    passeParBoss = false;
}

void Boss::fillPorte() {
	porte.clear();
	for (int i = 1; i < 21; i++) {
		string number = to_string(i);
		automate.setPorteNom("Porte" + number);
		automate.ouvrirPorte("Porte" + number + ".txt");
		porte.push_back(automate);
	}
}


void Boss::videMdpFinal(){
    mdpFinal = "";
}

string Boss::getmdpFinal() const {
    return mdpFinal;
}

void Boss::setMdpFinal(string mdp) {
	mdpFinal += mdp;
}

void Boss::videMdpBossAffichage() {
	mdpBossAffichage = "";
}

void Boss::remplirGouffre(){
    for (int i = 0; i < porte.size(); i++) {
        gouffre.push_back(0);
    }
}

void Boss::setMdpBossAffichage(string mdp) {
	if (mdp != "vide")
		mdpBossAffichage += mdp;
}

void Boss::videCheminPris() {
	cheminPris.clear();
	cheminPris.push_back("Porte1");
}

vector<string> Boss::getCheminPris() const {
	return cheminPris;
}

vector<int> Boss::getGouffre() const{
    return gouffre;
}

void Boss::setCheminPris(string porte) {
	cheminPris.push_back(porte);
}

void Boss::affronterBoss(string fichier, string mdp){
    passeParBoss = true;
    vector <string> chemin;
    string porteCourante;
    string porteProchaine;
    ifstream fileBoss(fichier);
    theSame = true;

    if (!fileBoss.fail()) {
        while (!ws(fileBoss).eof()) {
            fileBoss >> porteCourante;
            if (porteCourante != "Boss")
                chemin.push_back(porteCourante);
        }

		for (int i = 0; i < chemin.size(); i++) {
			if (chemin[i] != cheminPris[i])
				theSame = false;
		}

        if (theSame) {
            int compteEtatCourant = 0;
            int compteEtatTerminal = 1;
            char etat_courant, lettre_sortie, etat_prochain;
            bool premierePorte = true;
			
			for (int i = 0; i < chemin.size(); i++) {
                bool multimapVrai = true;
				for (int h = 0; h < porte.size(); h++) {
                    if (chemin[i] == cheminPris[i] && multimapVrai) {
                        if (chemin [i] == porte[h].getNomPorte()){
                            multimapVrai = false;
                            // cherche le nombre de cles uniques dans le multimap
                            vector<char>cles;
                            multimap<char, pair<char, char>> reglesCopie = porte[h].getRegles();
                            for (auto it = reglesCopie.begin(), end = reglesCopie.end(); it != end; it = reglesCopie.upper_bound(it->first)) {
                                compteEtatCourant++;
                                cles.push_back(it->first); 
                            }
                            //Modifie le langage pour qu'il puisse convenir ˆ la concatŽnation des
                            //automates lors de l'affrontement du boss.
                            for (auto findS : reglesCopie) {
                                int difference = compteEtatCourant - compteEtatTerminal;
                                lettre_sortie = findS.second.first;
                                etat_prochain = findS.second.second;
                                if (findS.first != 'S') {
                                    if (difference - 1 != 0) {
                                        for (int i = 0; i < difference; i++) {
                                            if (findS.first == cles[i]) {
                                                etat_courant = '0' + (compteEtatTerminal + i + 1);
                                            }
                                        }
                                    }
                                    else {
                                        etat_courant = '0' + compteEtatCourant;
                                    }
                                    if (findS.second.second == '_' || findS.second.second == 'S') {
                                        if (i != chemin.size() - 1)
                                            etat_prochain = '0' + (compteEtatCourant + 1);
                                        else automate.ajoutEtatTerminal(lettre_sortie);
                                    } else {
                                        for (int i = 0; i < cles.size(); i++) {
                                            if (findS.second.second == cles[i]) {
                                                int index = i + compteEtatTerminal + 1;
                                                etat_prochain = '0' + index;
                                            }
                                        }
                                    }
                                }
                                else {
                                    if (premierePorte)
                                        etat_courant = findS.first;
                                    else
                                        etat_courant = '0' + compteEtatTerminal;
                                    if (findS.second.second == '_' || findS.second.second == 'S') {
                                        if (i != chemin.size() - 1)
                                            etat_prochain = '0' + (compteEtatCourant + 1);
                                        else automate.ajoutEtatTerminal(lettre_sortie);
                                    }else {
                                        for (int i = 0; i < cles.size(); i++) {
                                            if (findS.second.second == cles[i]) {
                                                int index = i + compteEtatTerminal + 1;
                                                etat_prochain = '0' + index;
                                            }
                                        }
                                    }
                                }
                                langageFinal.insert(pair<char, pair<char, char>>(etat_courant, make_pair(lettre_sortie, etat_prochain)));
                            }
                            compteEtatTerminal += cles.size();
                            premierePorte = false;
                        }
					}
                }
			}
            vector<string> motDePasseFinal;
            vector<string> porteFinale;
            motDePasseFinal.push_back(mdp);
            porteFinale.push_back("Boss");
            automate.valideMotDePasse(motDePasseFinal, porteFinale, langageFinal);
		}
		else
			cout << "Desole, le chemin pris est faux!" << endl;
    }
}
// affichage du chemin parcouru suivant le format de l'ŽnoncŽ
void Boss::afficherLeCheminParcouru(vector<string> porteChoisi){
    passeParBoss = true;
    bool porteValide = false;
    for (int i = 0; i < porteChoisi.size(); i++){
		if (porteChoisi[i] == "Boss") {
			cout << "\nEvenement Boss\n" << endl;
			cout << "\ta. ";
			for (int j = 0; j < cheminPris.size(); j++)
				cout << cheminPris[j] << " ";

			cout << "\n\n\tb.";
			if(theSame){
				cout << "Voici le nouveau mot de passe : " << mdpBossAffichage;
				cout << "\n\t  Le nouveau language est : { \n";

                for (auto langage : langageFinal)
					cout << "\t\t" << langage.first << " -> " << langage.second.first << langage.second.second << ", ";
				cout << " }";
			}
			else
                cout << mdpFinal << " P= {...}";
			cout << "\n\n\tc. ";
            
			if (theSame && automate.getmpValide()[0] == mdpFinal)
				cout << "Vous avez vaincu le Boss " << endl << endl;
			else
				cout << "Le Boss vous a vaincu, SVP retourner a la Porte1 (soit l'option a)" << endl << endl;
		}
		for (int h = 0; h < porte.size(); h++) {
			if (porte[h].getNomPorte() == porteChoisi[i]) {
				cout << "\nEvenement Porte" << endl << endl
					<< "\ta. " << porteChoisi[i] << endl << endl << "\tb. ";
				for (int k = 0; k < porte[h].getmot_de_passe().size(); k++) {
					porteValide = false;
					cout << "{" << porte[h].getmot_de_passe()[k] << ", " << porte[h].getporte_correspondante()[k] << ", ";
					for (int j = 0; j < porte[h].getmpValide().size(); j++) {
						if (porte[h].getmot_de_passe()[k] == porte[h].getmpValide()[j] && !porteValide) {
							cout << "valide";
							porteValide = true;
                        }
					}
                    if (!porteValide){
						cout << "non valide";
                    }
					if (porte[h].getmot_de_passe().size() - 1 == k)
						cout << "}" << endl << endl;
					else
						cout << "}, ";
				}
				cout << "\tc. ";
                if (porte[h].getmpValide().size() == 0){
                    gouffre[h]++;
                    cout << gouffre[h];
					cout << "Cette porte est un gouffre, retour a la Porte 1" << endl << endl;
                } else
					cout << "Cette porte n'est pas un gouffre" << endl << endl;
			}
		}
    }
}
