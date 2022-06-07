/////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Titre:		 Travail pratique #1 - relation.cpp
/// Date:		 3 mars 2019
/// Auteurs:	 Mariam Sarwat (1928777), Yasmina Abou-Nakkoul (1897266) et Stéphanie Mansour (1935595)
/// Description: Cette classe permet d'etablir une relation entre un individu A et un individu B.
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "relation.h"

Relation::Relation() {
}

Individu Relation::getIndividusA() const {
	return individusA_;
}

int Relation::getRelation() const {
	return relation_;
}

Individu Relation::getIndividusB() const {
	return individusB_;
}

void Relation::setIndividusA(Individu individu) {
	individusA_ = individu;
}

void Relation::setRelation(int relation) {
	relation_ = relation;
}

void Relation::setIndividusB(Individu individu) {
	individusB_ = individu;
}

