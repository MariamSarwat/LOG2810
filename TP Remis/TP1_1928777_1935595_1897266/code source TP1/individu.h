/////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Titre:		 Travail pratique #1 - individu.h
/// Date:		 3 mars 2019
/// Auteurs:	 Mariam Sarwat (1928777), Yasmina Abou-Nakkoul (1897266) et Stéphanie Mansour (1935595)
////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef individu_h
#define individu_h

#include <string>
#include <iostream>

using namespace std;

class Individu {
public:
    
    Individu();
    
    string getNom() const;
    string getCheveux() const;
    string getYeux() const;
    string getGenie() const;
    
    void setNom(string nom);
    void setCheveux(string cheveux);
    void setYeux(string yeux);
    void setGenie(string genie);
    
private:
    string nom_;
    string cheveux_;
    string yeux_;
    string genie_;
};
#endif 
