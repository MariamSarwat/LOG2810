/////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Titre:		 Travail pratique #1 - individu.cpp
/// Date:		 3 mars 2019
/// Auteurs:	 Mariam Sarwat (1928777), Yasmina Abou-Nakkoul (1897266) et Stéphanie Mansour (1935595)
/// Description: Cette classe permet de creer un individu qui possede comme attribut un couleur de 
///				 cheveux, de yeux et un departement.
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "individu.h"

Individu::Individu() {
    nom_ = "";
    cheveux_ = "";
    yeux_ = "";
    genie_ = "";
}

string Individu::getNom() const {
    return nom_;
}

string Individu::getCheveux() const {
    return cheveux_;
}

string Individu::getYeux() const {
    return yeux_;
}

string Individu::getGenie() const {
    return genie_;
}

void Individu::setNom( string nom) {
    nom_ = nom;
}

void Individu::setCheveux( string cheveux) {
    cheveux_ = cheveux;
}

void Individu::setYeux( string yeux) {
    yeux_ = yeux;
}

void Individu::setGenie( string genie) {
    genie_ = genie;
}
