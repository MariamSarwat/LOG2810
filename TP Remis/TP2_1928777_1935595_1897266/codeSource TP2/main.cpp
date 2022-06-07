/////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Titre:		 Travail pratique #2 -main.cpp
/// Date:		 2 avril 2019
/// Auteurs:	 Mariam Sarwat (1928777), Yasmina Abou-Nakkoul (1897266) et Stéphanie Mansour (1935595)
/// Description: Le main permet de faire le lien entre nos classes et le menu.
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Automate.h"
#include "Boss.h"

using namespace std;

int main() {
	Automate automate;
	Boss boss(automate);
	bool optionA = false;
    bool fichiersChanges = false;

	string fichier;
	char option = ' ';
    char reponseFichiers = ' ';
    string porte;
    //int index = 0;
    vector<string> portesChoisis, porteActuel;

	while(true) {
        int index = 0;
		cout << "SVP choisir une des option suivantes :" << endl;
		cout << "  a  -  Entrer dans le labyrinthe" << endl
			 << "  b  -  Ouvrir une porte" << endl
			 << "  c  -  Afficher le chemin parcouru" << endl
			 << "  d  -  Quitter \n \n";

		cin >> option;
		
		switch (option) {
		
		case 'a':
            cout << "Avez vous changé les fichiers originaux? (O/N)" << endl;
            cin >> reponseFichiers;
            if (reponseFichiers == 'O')
                fichiersChanges = true;
			boss.fillPorte();
            boss.remplirGouffre();
            boss.videMdpFinal();
			boss.videMdpBossAffichage();
            porteActuel.clear();
			boss.videCheminPris();
            porte = "Porte1";
			automate.ouvrirPorte(porte + ".txt");

            porteActuel.push_back(porte);
            portesChoisis.push_back(porte);
            boss.afficherLeCheminParcouru(porteActuel);
            
            optionA = true;
            cout << endl;
            break;

		case 'b':
			if (optionA) {
                porteActuel.clear();
                if (automate.getMPValide().size() == 0) {
                    optionA = false;
                    cout << "\nVous devez retourner a l'option a comme vous etes tombes dans un gouffre" << endl << endl;
                    break;
                }
                else {
                    for (int i = 0; i < automate.getPCValide().size(); i++){
                        if (automate.getPCValide()[i] == "Boss")
                            index = i;
                    }
                    // politique de décision: si nous avons passé par un grouffre plus de 3 fois et que les fichiers sont inchangés, nous ne passerons plus par ce gouffre.
                    if (index == 0){
                        for (int i = 0; i < automate.getPCValide().size(); i++){
                            for (int j = 0; j < 20; j++){
                                string porteLive = "Porte"+ std::to_string(j+1);
                                if (porteLive == automate.getPCValide()[i]){
                                    do index = rand() % (automate.getMPValide().size());
                                    while (boss.getGouffre()[j] >= 3 && fichiersChanges);
                                }
                            }
                        }
                    }
                }
                boss.setMdpFinal(automate.getMPValide()[index]);
				boss.setMdpBossAffichage(automate.getMPValide()[index]);
                
				porte = automate.getPCValide()[index];
                
                if (porte == "Boss")
                    boss.affronterBoss("Boss.txt", boss.getmdpFinal());
                else {
                    boss.setCheminPris(porte);
					automate.ouvrirPorte(porte + ".txt");
                }
					
                porteActuel.push_back(porte);
                portesChoisis.push_back(porte);
                
                boss.afficherLeCheminParcouru(porteActuel);
			}
				
			else cout << "\nVous devez entrer le labyrinthe en premier (option a)" << endl << endl;
			break;

		case 'c':
			if (optionA) 
                boss.afficherLeCheminParcouru(portesChoisis);              
			else cout << "\nVous devez entrer le labyrinthe en premier (option a)" << endl << endl;
			break;

		case 'd':
			cout << "\nVous avez choisi de quitter le programme. Merci!" << endl << endl;
			system("pause");
			exit(0);

		default:
			while (option != 'a' && option != 'b' && option != 'c' && option != 'd') {
				cout << "\nVous avez entré une option invalide. SVP choisir une autre option." << endl << endl;
				cin >> option;
			}
			break;
		}
	} 
}

