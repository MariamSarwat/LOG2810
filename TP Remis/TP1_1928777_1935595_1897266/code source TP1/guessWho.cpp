/////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Titre:		 Travail pratique #1 -guessWho.cpp
/// Date:		 3 mars 2019
/// Auteurs:	 Mariam Sarwat (1928777), Yasmina Abou-Nakkoul (1897266) et Stéphanie Mansour (1935595)
/// Description: Cette classe permet de trouver les 2 personnes mysteres a laquelles l'adversaire 
///              pense afin de retrouver la meilleur chaine de contacts entre eux.
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "guessWho.h"

GuessWho::GuessWho(){}

Individu GuessWho::getMystere1() const {
	return mystere1_;
}

Individu GuessWho::getMystere2() const{
	return mystere2_;
}

int GuessWho::getNbQuestion() const {
	return nbQuestion_;
}

vector<Individu> GuessWho::getIndividuRestant() const {
	return individuRestant_;
}

vector<Relation> GuessWho::getRelation() const {
	return relation_;
}

vector<string> GuessWho::getCharacIndes() {
	return characIndes_;
}

vector<string> GuessWho::getCategorie() {
	return categorie_;
}

void GuessWho::setMystere1(Individu mystere1){
	mystere1_ = mystere1;
}

void GuessWho::setMystere2(Individu mystere2){
	mystere2_ = mystere2;
}

void GuessWho::setNbQuestion(int nbQuestion) {
	nbQuestion_ = nbQuestion;
}

void GuessWho::demanderQuestion(string question) {
	do {
		cout << "\n" << question << endl;
		cin >> reponse_;
		afficherListeRestant(reponse_);
	} while (reponse_ != "N" && reponse_ != "n" && reponse_ != "O" && reponse_ != "o" && reponse_ != "U" && reponse_ != "u");
	nbQuestion_++;
}

void GuessWho::yeux(string charact, bool type){
	for (int i = 0; i < individuRestant_.size(); i++) {
		if (type) {
			if (individuRestant_[i].getYeux() != charact) {
				individuRestant_.erase(individuRestant_.begin() + i);
				i--;
			}
		}
		else {
			if (individuRestant_[i].getYeux() == charact) {
				individuRestant_.erase(individuRestant_.begin() + i);
				i--;
			}
		}
	}
}

void GuessWho::departement(string charact, bool type){
	for (int i = 0; i < individuRestant_.size(); i++) {
		if (type) {
			if (individuRestant_[i].getGenie() != charact) {
				individuRestant_.erase(individuRestant_.begin() + i);
				i--;
			}
		}
		else {
			if (individuRestant_[i].getGenie() == charact) {
				individuRestant_.erase(individuRestant_.begin() + i);
				i--;
			}
		}
	}
}

void GuessWho::cheveux(string charact, bool type){
	for (int i = 0; i < individuRestant_.size(); i++) {
		if (type) {
			if (individuRestant_[i].getCheveux() != charact) {
				individuRestant_.erase(individuRestant_.begin() + i);
				i--;
			}
		}
		else {
			if (individuRestant_[i].getCheveux() == charact) {
				individuRestant_.erase(individuRestant_.begin() + i);
				i--;
			}
		}

	}
}

void GuessWho::devinette(vector<Individu> vecteur){
    string caracteristique1, caracteristique2;
	int question = 1;
	bool pourUneSeul = false;
    bool questionnement = true;

	setNbQuestion(0);
	individuRestant_ = vecteur;

    cout << "Les reponses possibles sont: O pour \"Oui pour les deux\", N pour \"Non pour les deux\" et U pour \"Oui pour un seul\" " << endl;
    
    while (questionnement) {
        switch (question) {
            case 1:
				demanderQuestion("Les individus mystere ont-ils les cheveux noirs?");

                if (reponse_ == "O" || reponse_=="o") {
					cheveux("N", true);
					question = 4;
                    break;
                }

                else if(reponse_ == "N" || reponse_=="n") {
					cheveux("N", false);
                    question = 2;
                    break;
                }

                else if(reponse_ == "U" || reponse_=="u") {
                    pourUneSeul = true;
                    caracteristique1="N"; // aurait pu etre mystere 2
                    question = 2;
                    break;
                }

            case 2:
				demanderQuestion("Les individus mystere ont-ils les cheveux roux?");

				if (reponse_=="O" || reponse_=="o") {
					cheveux("R",true);
					question = 4;
                    break;
                }

                else if(reponse_ == "N" || reponse_=="n") {

					cheveux("R", false);
                    question = 3;
                    break;

                } 
				
				else if (reponse_ == "U" || reponse_=="u") {
                    if(pourUneSeul == true){
                       caracteristique2 ="R";
                            for(int i=0; i<individuRestant_.size(); i++){
								if (individuRestant_[i].getCheveux() != caracteristique1 && individuRestant_[i].getCheveux() != caracteristique2) {
									individuRestant_.erase(individuRestant_.begin() + i);
									i--;
								}
                            }
                            question = 4;
                            break;
                    }
                    caracteristique1 = "R";
                    pourUneSeul = true;
                    question = 3;
                    break;
                }

            case 3:
				demanderQuestion("Les individus mystere ont-ils les cheveux blonds?");

                if (reponse_=="O" || reponse_=="o") {
					cheveux("B",true);
					question = 4;
                    break;
                }
				 
                else if(reponse_=="N" || reponse_=="n") {
					cheveux("B", false);
                    question = 4;
                    break;
                }

                else if (reponse_ == "U" || reponse_=="u") {
                    if(pourUneSeul == true){
                        caracteristique2 = "B";
                        for(int i=0; i<individuRestant_.size(); i++){
							if (individuRestant_[i].getCheveux() != caracteristique1 && individuRestant_[i].getCheveux() != caracteristique2) {
								individuRestant_.erase(individuRestant_.begin() + i);
								i--;
							}
                        }
                        question = 4;
                        break;
                    }
                }
                question = 4;
                break;
            
			case 4:
                pourUneSeul = false;

				demanderQuestion("Les individus mystere ont-ils les yeux bleux?");
                
                if (reponse_ == "O" || reponse_=="o") {
					yeux("B",true);
					question = 8;
                    break;
                }

                else if(reponse_ == "N" || reponse_=="n") {
					yeux("B", false);
                    question = 5;
                    break;
                }

                else if(reponse_ == "U" || reponse_=="u"){
                    pourUneSeul = true;
                    caracteristique1 = "B"; // aurait pu etre mystere 2
                    question = 5;
                    break;
                }

            case 5:
				demanderQuestion("Les individus mystere ont-ils les yeux verts?");

                if (reponse_ == "O" || reponse_=="o") {
					yeux("V",true);
					question = 8;
                    break;
                }
				 
                else if(reponse_ == "N" || reponse_=="n") {
					yeux("V", false);
                    question = 6;
                    break;
                }

                else if (reponse_ == "U" || reponse_=="u") {
                    if(pourUneSeul == true){
                        caracteristique2 = "V";
                        for(int i=0; i<individuRestant_.size(); i++){
                            if (individuRestant_[i].getYeux() != caracteristique1 && individuRestant_[i].getYeux() != caracteristique2) {
                                individuRestant_.erase(individuRestant_.begin() + i);
                                i--;
                            }
                        }
                        question = 8;
                        break;
                    }
                    caracteristique1 = "V";
                    pourUneSeul = true;
                    question = 6;
                    break;
                }

            case 6:
				demanderQuestion("Les individus mystere ont-ils les yeux noirs?");
                
                if (reponse_ == "O" || reponse_=="o") {
					yeux("N", true);
					question = 8;
                    break;
                }

                else if(reponse_ == "N" || reponse_=="n") {
					yeux("N", false);
                    question = 7;
                    break;
                }

                else if (reponse_ == "U" || reponse_=="u") {
                    if(pourUneSeul == true){
                        caracteristique2 = "N";
                        for(int i=0; i<individuRestant_.size(); i++){
                            if (individuRestant_[i].getYeux() != caracteristique1 && individuRestant_[i].getYeux() != caracteristique2) {
                                individuRestant_.erase(individuRestant_.begin() + i);
                                i--;
                            }
                        }
                        question = 8;
                        break;
                    }
                    caracteristique1 = "N";
                    pourUneSeul = true;
                    question = 7;
                    break;
                }

            case 7:
				demanderQuestion("Les individus mystere ont-ils les yeux gris?");

                if (reponse_=="O" || reponse_=="o") {
					yeux("G", true);
					question = 8;
                    break;
                }

                else if(reponse_=="N" || reponse_=="n") {
					yeux("G", false);
                    question = 8;
                    break;
                }

                else if (reponse_ == "U" || reponse_=="u") {
                    if(pourUneSeul == true){
                        caracteristique2 = "G";
                        for(int i=0; i<individuRestant_.size(); i++){
                            if (individuRestant_[i].getYeux() != caracteristique1 && individuRestant_[i].getYeux() != caracteristique2) {
                                individuRestant_.erase(individuRestant_.begin() + i);
                                i--;
                            }
                        }
                        question = 8;
                        break;
                    }
                }

            case 8:
                pourUneSeul = false;
				demanderQuestion("Les individus mystere sont-ils en genie Informatique?");

                if (reponse_ == "O" || reponse_=="o") {
					departement("GI",true);
                    questionnement = false; //permet a finalement sortir du switch case
                    break;
                }
                
                else if(reponse_ == "N" || reponse_=="n") {
					departement("GI", false);
                    question = 9;
                    break;
                }
                
                else if(reponse_ == "U" || reponse_=="u") {
                    pourUneSeul = true;
                    caracteristique1 = "GI"; 
                    question = 9;
                    break;
                }

            case 9:
				demanderQuestion("Les individus mystere sont-ils en genie Electrique?");

                if (reponse_ == "O" || reponse_=="o") {
					departement("GE",true);
					questionnement = false;
                    break;
                } 

                else if(reponse_ == "N" || reponse_=="n") {
					departement("GE", false);
                    question = 10;
                    break;
                }

                else if (reponse_ == "U" || reponse_=="u") {
                    if(pourUneSeul == true){
                        caracteristique2 = "GE";
                        for(int i=0; i<individuRestant_.size(); i++){
                            if (individuRestant_[i].getGenie() != caracteristique1 && individuRestant_[i].getGenie() != caracteristique2) {
                                individuRestant_.erase(individuRestant_.begin() + i);
                                i--;
                            }
                        }
                        questionnement = false;
                        break;
                    }
                    caracteristique1 = "GE";
                    pourUneSeul = true;
                    question = 10;
                    break;
                }

            case 10:
				demanderQuestion("Les individus mystere sont-ils en genie Physique?");

                if (reponse_ == "O" || reponse_=="o") {
					departement("GP",true);
					questionnement = false;
                    break;
                }

                else if(reponse_ == "N" || reponse_=="n") {
					departement("GP", false);
                    question = 11;
                    break;
                }

                else if (reponse_ == "U" || reponse_=="u") {
                    if(pourUneSeul == true){
                        caracteristique2 = "GP";
                        for(int i=0; i<individuRestant_.size(); i++){
                            if (individuRestant_[i].getGenie() != caracteristique1 && individuRestant_[i].getGenie() != caracteristique2) {
                                individuRestant_.erase(individuRestant_.begin() + i);
                                i--;
                            }
                        }
                        questionnement = false;
                        break;
                    }
                    caracteristique1 = "GP";
                    pourUneSeul = true;
                    question = 11;
                    break;
                }

            case 11:
				demanderQuestion("Les individus mystere sont-ils en genie Chimique?");

                if (reponse_ == "O" || reponse_=="o") {
					departement("GC",true);
					questionnement = false;
                    break;
                }

                else if(reponse_ == "N" || reponse_=="n") {
					departement("GC", false);
                    question = 12;
                    break;
                }

                else if (reponse_ == "U" || reponse_=="u") {
                    if(pourUneSeul == true){
                        caracteristique2 = "GC";
                        for(int i=0; i<individuRestant_.size(); i++){
                            if (individuRestant_[i].getGenie() != caracteristique1 && individuRestant_[i].getGenie() != caracteristique2) {
                                individuRestant_.erase(individuRestant_.begin() + i);
                                i--;
                            }
                        }
                        questionnement = false;
                        break;
                    }
                    caracteristique1 = "GC";
                    pourUneSeul = true;
                    question = 12;
                    break;
                }

            case 12:
				demanderQuestion("Les individus mystere sont-ils en genie Aerospatial?");

                if (reponse_ == "O" || reponse_=="o") {
					departement("GA", true);
					questionnement = false;
                    break;
                }

                else if(reponse_ == "N" || reponse_=="n") {
					departement("GA", false);
                    question = 13;
                    break;
                }

                else if (reponse_ == "U" || reponse_=="u") {
                    if(pourUneSeul == true){
                        caracteristique2 = "GA";
                        for(int i=0; i<individuRestant_.size(); i++){
                            if (individuRestant_[i].getGenie() != caracteristique1 && individuRestant_[i].getGenie() != caracteristique2) {
                                individuRestant_.erase(individuRestant_.begin() + i);
                                i--;
                            }
                        }
                        questionnement = false;
                        break;
                    }
                    caracteristique1 = "GA";
                    pourUneSeul = true;
                    question = 13;
                    break;
                }

            case 13:
				demanderQuestion("Les individus mystere sont-ils en genie Mecanique?");

                if (reponse_ == "O" || reponse_=="o") {
					departement("GM",true);
					questionnement = false;
                    break;
                }

                else if(reponse_ == "N" || reponse_=="n") {
					departement("GM", false);
                    question = 14;
                    break;
                }
				 
                else if (reponse_ == "U" || reponse_=="u") {
                    if(pourUneSeul == true){
                        caracteristique2 = "GM";
                        for(int i=0; i<individuRestant_.size(); i++){
                            if (individuRestant_[i].getGenie() != caracteristique1 && individuRestant_[i].getGenie() != caracteristique2) {
                                individuRestant_.erase(individuRestant_.begin() + i);
                                i--;
                            }
                        }
                        questionnement = false;
                        break;
                    }
                    caracteristique1 = "GM";
                    pourUneSeul = true;
                    question = 14;
                    break;
                }

            case 14:
				demanderQuestion("Les individus mystere sont-ils en genie Biomedical?");

                if (reponse_ == "O" || reponse_=="o") {
					departement("GB",true);
					questionnement = false;
                    break;
                }

                else if(reponse_ == "N" || reponse_=="n") {
					departement("GB", false);
                    question = 15;
                    break;
                }

                else if (reponse_ == "U" || reponse_=="u") {
                    if(pourUneSeul == true){
                        caracteristique2 = "GB";
                        for(int i=0; i<individuRestant_.size(); i++){
                            if (individuRestant_[i].getGenie() != caracteristique1 && individuRestant_[i].getGenie() != caracteristique2) {
                                individuRestant_.erase(individuRestant_.begin() + i);
                                i--;
                            }
                        }
                        questionnement = false;
                        break;
                    }
                    caracteristique1 = "GB";
                    pourUneSeul = true;
                    question = 15;
                    break;
                }

            case 15:
				demanderQuestion("Les individus mystere sont-ils en genie Industriel?");

                if (reponse_ == "O" || reponse_=="o"){
					departement("GInd", false);
					questionnement = false;
                    break;
                }

                else if(reponse_ == "N" || reponse_=="n") {
					departement("GInd", false);
                    questionnement = false; 
                    break;
                }

                else if (reponse_ == "U" || reponse_ == "u"){
                    if(pourUneSeul == true){
                        caracteristique2 = "GInd";
                        for(int i=0; i<individuRestant_.size(); i++){
                            if (individuRestant_[i].getGenie() != caracteristique1 && individuRestant_[i].getGenie() != caracteristique2) {
                                individuRestant_.erase(individuRestant_.begin() + i);
                                i--;
                            }
                        }
                    }
                    questionnement = false;
                    break;
                }
        }//switch case
    }//while true
}

void GuessWho::afficherListeRestant(string reponse) {
	if (reponse == "s") {
		cout << "\nPersonne restante:\n" << endl;
		for (int i = 0; i < individuRestant_.size(); i++) {
			cout << individuRestant_[i].getNom() << endl;
		}
		cout << "\n";
	}
}

void GuessWho::identifierIndividus(vector<Individu> vecteur){
	string reponse, nomMystere1, nomMystere2, nomMystere;
	int mystereFaux; 
	bool mystere1Trouvee = false;
	bool mystere2Trouvee = false;
	bool mystere = false;
	MysteresTrouvee_ = false;
	cout << "\nAfin de trouver les personnes mysteres nous avons pose " << nbQuestion_ << " question(s)" << endl;
	
	if (individuRestant_.size() != 0 && individuRestant_.size() != 1) {
		MysteresTrouvee_ = true;
		setMystere1(individuRestant_[0]);
		setMystere2(individuRestant_[1]);

		cout << "\nSVP repondez: O pour \"Oui pour les deux\", N pour \"Non pour les deux\" ou U pour \"Oui pour un seul\" " << endl;

		cout << "\nLes individus mysteres etaient-ils " << getMystere1().getNom() << " et " << getMystere2().getNom() << "?" << endl;
		cin >> reponse;

		if (reponse == "N" || reponse == "n") {
			do {
				cout << "\nEntrez le nom de vos deux individus mysteres " << endl;
				cin >> nomMystere1 >> nomMystere2;
				for (int i = 0; i < vecteur.size(); i++) {
					if (nomMystere1 == vecteur[i].getNom() && !mystere1Trouvee) {
						setMystere1(vecteur[i]);
						mystere1Trouvee = true;
					}
					if (nomMystere2 == vecteur[i].getNom() && !mystere2Trouvee) {
						setMystere2(vecteur[i]);
						mystere2Trouvee = true;
					}
				}

				if (!mystere1Trouvee || !mystere2Trouvee)
					cout << "\nLe nom d'un ou des deux personne mysteres entrer est invalide. SVP assurez vus d'entrer des noms valides" << endl;
			} while (!mystere1Trouvee || !mystere2Trouvee);

		}

		else if (reponse == "U" || reponse == "u") {
			do {
				cout << "\nIndiquez 1 si la premiere personne mystere est faux et 2 si c'est la deuxieme" << endl;
				cin >> mystereFaux;
				cout << "\nEntrez le nom du personne mystere " << endl;
				cin >> nomMystere;

				for (int i = 0; i < vecteur.size(); i++) {
					if (nomMystere == vecteur[i].getNom()) {
						if (mystereFaux == 1) 
							setMystere1(vecteur[i]);
						else 
							setMystere2(vecteur[i]);
						mystere = true;
					}
				}
				if (!mystere)
					cout << "\nLe nom entrer est invalide. SVP assurez vus d'entrer un nom valide" << endl;

			} while (!mystere);
		}
	}

	else if (individuRestant_.size() == 0)
		cout << "\nIl n'y pas d'individus avec les caracteristique indiques dans votre fichier de relation" << endl;
	
	else if (individuRestant_.size() == 1) {
		setMystere1(individuRestant_[0]);
		cout << "\nIl existe seulement " << getMystere1().getNom() << " qui possede les caracteristiques indiques" << endl; 
	}
}

void GuessWho::enleverArcsIndesirables(vector<Relation> vecteurRelation) {
	string categorie, caracteristique;
	relation_ = vecteurRelation;
	if (MysteresTrouvee_) {
		for (int k = 0; k < 3; k++) {
			do {
				cout << "\nIndiquez la categorie correspondant a votre caracteristique indesirable : C -> cheveux, Y -> yeux ou G -> genie " << endl;
				cin >> categorie;
			} while (categorie != "G" && categorie != "Y" && categorie != "C" && categorie != "g" && categorie != "y" && categorie != "c");

			if (categorie == "C" || categorie == "c") {
				do {
					cout << "\nChoissisez parmi les caracteristique suivantes (SVP en majuscule) : N -> noir, R -> roux, B -> blond ou M -> marron" << endl;
					cin >> caracteristique;
				} while (caracteristique != "N" && caracteristique != "R" && caracteristique != "B" && caracteristique != "M");

				for (int i = 0; i < relation_.size(); i++) {
					if (relation_[i].getIndividusA().getCheveux() == caracteristique && relation_[i].getIndividusB().getCheveux() == caracteristique) {
						if (getMystere1().getNom() != relation_[i].getIndividusA().getNom() && getMystere1().getNom() != relation_[i].getIndividusB().getNom()
							&& getMystere2().getNom() != relation_[i].getIndividusA().getNom() && getMystere2().getNom() != relation_[i].getIndividusB().getNom())

							relation_[i].setRelation(0);
					}
				}
			}

			if (categorie == "Y" || categorie == "y") {
				do {
					cout << "\nChoissisez parmi les caracteristique suivantes (SVP en majuscule) : B -> bleu, V -> vert, N -> noir, M -> marron ou G -> gris" << endl;
					cin >> caracteristique;
				} while (caracteristique != "B" && caracteristique != "V" && caracteristique != "N" && caracteristique != "M" && caracteristique != "G");

				for (int i = 0; i < relation_.size(); i++) {
					if (relation_[i].getIndividusA().getYeux() == caracteristique && relation_[i].getIndividusB().getYeux() == caracteristique) {
						if (getMystere1().getNom() != relation_[i].getIndividusA().getNom() && getMystere1().getNom() != relation_[i].getIndividusB().getNom()
							&& getMystere2().getNom() != relation_[i].getIndividusA().getNom() && getMystere2().getNom() != relation_[i].getIndividusB().getNom())

							relation_[i].setRelation(0);
					}
				}
			}

			if (categorie == "G" || categorie == "g") {
				do {
					cout << "\nChoissisez parmi les caracteristique suivantes (SVP en majuscule) : I -> génie informatique, E -> génie électrique, P -> génie physique, C -> génie chimique, A -> génie aérospatial, M -> génie mécanique, B -> génie biomédical, ID -> génie industriel ou ER -> génie énergétique " << endl;
					cin >> caracteristique;
				} while (caracteristique != "I" && caracteristique != "E" && caracteristique != "P" && caracteristique != "C" && caracteristique != "A" && caracteristique != "M" && caracteristique != "B" && caracteristique != "ID" && caracteristique != "ER");

				for (int i = 0; i < relation_.size(); i++) {
					if (relation_[i].getIndividusA().getGenie() == caracteristique && relation_[i].getIndividusB().getGenie() == caracteristique) {
						if (getMystere1().getNom() != relation_[i].getIndividusA().getNom() && getMystere1().getNom() != relation_[i].getIndividusB().getNom()
							&& getMystere2().getNom() != relation_[i].getIndividusA().getNom() && getMystere2().getNom() != relation_[i].getIndividusB().getNom())

							relation_[i].setRelation(0);
					}
				}
			}
			afficherCaractere(caracteristique, categorie);
		}
	}
	else cout << "\nSVP rejouer Qui est-ce? en ayant 2 personnes mysteres en tete" << endl;
}

void GuessWho::afficherCaractere(string charact, string categorie) {
	if (categorie == "C" || categorie == "c") {
		categorie_.push_back("Cheveux");
		if (charact == "N")
			characIndes_.push_back("Noir");
		else if(charact == "R")
			characIndes_.push_back("Roux");
		else if(charact == "B")
			characIndes_.push_back("Blond");
		else 
			characIndes_.push_back("Marron");
	}

	if (categorie == "Y" || categorie == "y") {
		categorie_.push_back("Yeux");
		if (charact == "B")
			characIndes_.push_back("Bleu");
		else if (charact == "V")
			characIndes_.push_back("Vert");
		else if (charact == "N")
			characIndes_.push_back("Noir");
		else if (charact == "M")
			characIndes_.push_back("Marron");
		else 
			characIndes_.push_back("Gris");
	}

	if (categorie == "G" || categorie == "g") {
		categorie_.push_back("Departement");
		if (charact == "I")
			characIndes_.push_back("Genie Informatique");
		else if (charact == "E")
			characIndes_.push_back("Genie Electrique");
		else if (charact == "P")
			characIndes_.push_back("Genie Physique");
		else if (charact == "C")
			characIndes_.push_back("Genie Chimique");
		else if (charact == "A")
			characIndes_.push_back("Genie Aerospatial");
		else if (charact == "M")
			characIndes_.push_back("Genie Mecanique");
		else if (charact == "B")
			characIndes_.push_back("Genie Biomedical");
		else if (charact == "ID")
			characIndes_.push_back("Genie Industriel");
		else 
			characIndes_.push_back("Genie Energetique");
	}
}