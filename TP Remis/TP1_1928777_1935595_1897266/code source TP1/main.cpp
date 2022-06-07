/////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Titre:		 Travail pratique #1 -main.cpp
/// Date:		 3 mars 2019
/// Auteurs:	 Mariam Sarwat (1928777), Yasmina Abou-Nakkoul (1897266) et Stéphanie Mansour (1935595)
/// Description: Le main permet de faire le lien entre nos classes et le menu.
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "guessWho.h"
#include "chemins.h"

using namespace std;

void AfficherResultat(ReseauSocial reseau, GuessWho guess, Chemins ch) {
	//afficher sous-graph caract desirable
	cout << endl;
	reseau.afficherReseauSocial(guess.getRelation());
	cout << endl;

	//meilleur chaine
	ch.trouverChaineContacts(reseau.getIndividus(), guess.getRelation(), guess.getMystere1(), guess.getMystere2()); 
	cout << endl;

	//nombre question posee
	cout << "\nNous vous avons demande " << guess.getNbQuestion() << " questions avant de deviner vos 2 individus mysteres" << endl;

	//nom des individus trouves
	cout << "\nLes deux individus mysteres trouves etaient " << guess.getIndividuRestant()[0].getNom() << " et " << guess.getIndividuRestant()[1].getNom() << endl;

	// noms des individus qui n'ont pas ete devines
	if (guess.getMystere1().getNom() != guess.getIndividuRestant()[0].getNom() && guess.getMystere2().getNom() != guess.getIndividuRestant()[1].getNom())
		cout << "\nNous n'avons pas pu deviner " << guess.getMystere1().getNom() << " et " << guess.getMystere2().getNom() << endl;
	else if (guess.getMystere1().getNom() != guess.getIndividuRestant()[0].getNom())
		cout << "\nNous n'avons pas pu deviner " << guess.getMystere1().getNom() << endl;
	else if (guess.getMystere2().getNom() != guess.getIndividuRestant()[1].getNom())
		cout << "\nNous n'avons pas pu deviner " << guess.getMystere2().getNom() << endl;

	//3 caracteristiques indesirables
	cout << "\nLes 3 caracteristiques choisis etaitent : " << endl;
	for (int i = 0; i < 3; i++)
		cout << i + 1 << ". " << guess.getCategorie()[i] << " " << guess.getCharacIndes()[i] << endl;
	cout << endl;

}

int main() {
	ReseauSocial reseau;
    GuessWho guess;
	Chemins ch;

	bool optionA = false;
	bool optionC = false;

	string individusFichier, relationFichier;
	char option = ' ';

	while(true) {
		cout << "SVP choisir une des option suivantes :" << endl;
		cout << "  a  -  Creer le reseau social" << endl
			 << "  b  -  Afficher le reseau social" << endl
			 << "  c  -  Jouer a qui est-ce?" << endl
			 << "  d  -  Afficher le resultat" << endl
			 << "  e  -  Quitter \n \n";

		cin >> option;
		
		switch (option) {
			
			case 'a':
				cout << "\nSVP entrer le nom de votre fichier d'individus (en incluant l'extension \".txt\")." << endl;
				cin >> individusFichier;

				cout << "\nSVP entrer le nom de votre fichier de relations (en incluant l'extension \".txt\")." << endl;
				cin >> relationFichier;

				if (reseau.creerReseauSocial(individusFichier, relationFichier))
					optionA = true;
				
				cout << endl;
				break;

			case 'b':
				if (optionA) {
					cout << "\nVoici les donnees retrouve dans " << individusFichier << endl << "\n";
					reseau.afficherIndividus();

					cout << "\nVoici les donnees retrouve dans " << relationFichier << endl << "\n";
					reseau.afficherRelations();

					cout << "\nVoici le reseau social " << endl << "\n";
					reseau.afficherReseauSocial(reseau.getRelations());
					cout << endl;
				}
				
				else cout << "\nVous devez creer le reseau social en premier (option a)" << endl;
				break;

			case 'c':
				if (optionA) {
					cout << endl;
                    guess.devinette(reseau.getIndividus());
					guess.identifierIndividus(reseau.getIndividus());
					guess.enleverArcsIndesirables(reseau.getRelations());
					cout << endl;
                }
                
				else cout << "\nVous devez creer le reseau social en premier (option a)" << endl;

				optionC = true;
				break;

			case 'd':
				if (optionC)
					AfficherResultat(reseau, guess, ch);

				else cout << "\nVous devez jouer a qui est-ce en premier (option c)" << endl;
				break;

			case 'e':
				cout << "\nVous avez choisi de quitter le programme. Merci!" << endl;
				cout << "\nVous avez choisi a quitter le program. Merci!" << endl;
				system("pause");
				exit(0);

			default:
				while (option != 'a' && option != 'b' && option != 'c' && option != 'd' && option != 'e') {
					cout << "\nVous avez entré une option invalide. SVP choisir une autre option." << endl;
					cin >> option;
				}
				break;
		}
	} 
}

