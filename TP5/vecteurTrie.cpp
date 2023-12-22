/// TP5 Tris et Complexit�
/// 2022-2023
/// fichier vecteurTrie.cpp

#include <iostream>
#include "vecteurTrie.h"
#include "outils.h"

using namespace std;

/// Initialisation en fonction des parametres choisis par l'utilisateur
void VecteurTrie::initVecteur(int nbVal, Ordre ordr, int valMax)
{
    /// supprimer les �l�ments du vecteur utilis� pour le tri pr�c�dent
    _v.clear(); /// ou bien _v.resize(0);

    /// g�n�ration d'un vecteur de nvVal entiers compris entre 0 et valMax
    vecteurAlea(_v, nbVal, 0, valMax);

    /// on le met dans l'ordre souhait�
    int cptEcritTmp=0, cptCompTmp=0; /// n�cessaires pour l'appel des fonctions de tri
    switch (ordr)
    {
    case ALEA : break;
    case CROISSANT: triSelection(cptEcritTmp, cptCompTmp); break;
    case DECROISSANT : triSelectionInverse(cptEcritTmp, cptCompTmp); break;
    default : throw(string("initVecteur : ERREUR critere de tri inconnu")); break;
    }
}

/// Affichage d'un vecteur d'entiers.
void VecteurTrie::afficher()const
{
    for (int i=0 ; i<_v.size() ; i++)
    {
        cout << _v[i] << " ";
        /// m�thode at() non n�cessaire car pas d'acc�s erron� possible ici
    }
    cout << endl;
}

/// Applique l'algorithme de tri choisi par l'utilisateur.
/// Compte le nombre d'�critures (dans le vecteur) et de comparaisons (entre �l�ments du vecteur).
void VecteurTrie::trier(Algo alg, int & cptEcrit, int & cptComp)
{
    switch (alg)
    {
    case SELECTION :
        cout << "\n... Tri SELECTION ... " << endl;
        triSelection(cptEcrit, cptComp);
        break;
    case BULLE :
        cout << "\n... Tri BULLES ... " << endl;
        triBulles(cptEcrit, cptComp);
        break;
    case BULLE_OPT :
        cout << "\n... Tri BULLES_OPT ... " << endl;
        triBullesOpt(cptEcrit, cptComp);
        break;
    case RAPIDE:
        cout << "\n... Tri RAPIDE ... " << endl;
        triRapide(cptEcrit, cptComp);
        break;
    default :
        break;
    }
}

/// Echange deux positions dans un vecteur.
void VecteurTrie::echanger(int ind1, int ind2, int & cptEcrit)
{
    int tmp = _v.at(ind1);
    _v.at(ind1) = _v.at(ind2);
    _v.at(ind2) = tmp ;
    /// 1 �change compte pour 2 �critures (on compte les �critures sur le vecteur)
    cptEcrit+=2;
}

/****** TRI SELECTION ******/

/// Recherche pour chaque case l'element qui doit y etre affecte et y place cet element.
/// Ordre : du plus petit au plus grand.
void VecteurTrie::triSelection(int & cptEcrit, int & cptComp)
{
    int indDuMin ;
    for (int pos=0; pos<_v.size()-1; pos++)
    {
        indDuMin = selection(pos, _v.size()-1, cptEcrit, cptComp);
        if(indDuMin != pos)
        {
            echanger(pos, indDuMin, cptEcrit);
        }
    }
}

/// Recherche pour chaque case l'element qui doit y etre affecte et y place cet element.
/// Ordre : du plus grand au plus petit.
void VecteurTrie::triSelectionInverse(int & cptEcrit, int & cptComp)
{
    int indDuMax ;
    for (int pos=0; pos<_v.size()-1; pos++)
    {
        indDuMax = selectionMax(pos, _v.size()-1, cptEcrit, cptComp);
        if(indDuMax != pos)
        {
            echanger(pos, indDuMax, cptEcrit);
        }
    }
}

///Recherche l'indice de l'�l�ment minimum entre indDebut et indFin.
int VecteurTrie::selection(int indDebut, int indFin, int & cptEcrit, int & cptComp)
{
    int indDuMin = indDebut;
    for (int ind=indDebut+1; ind<=indFin; ind++)
    {
        cptComp++;
        if (_v.at(indDuMin) > _v.at(ind))
        {
            indDuMin=ind;
        }
    }
    return(indDuMin);
}

///Recherche l'indice de l'�l�ment maximum entre indDebut et indFin
int VecteurTrie::selectionMax(int indDebut, int indFin, int & cptEcrit, int & cptComp)
{
    int indDuMax = indDebut;
    for (int ind=indDebut+1; ind<=indFin; ind++)
    {
        cptComp++;
        if (_v.at(indDuMax) < _v.at(ind))
        {
            indDuMax=ind;
        }
    }
    return(indDuMax);
}

/****** TRI RAPIDE ******/

/// Ex�cution du tri rapide
void VecteurTrie::triRapide(int & cptEcrit, int & cptComp)
{
    triRapideAux(0, _v.size()-1, cptEcrit, cptComp);
}

/// Partitionne le vecteur et appelle r�cursivement la proc�dure triRapideAux sur la partie gauche et la partie droite du vecteur.
void VecteurTrie::triRapideAux(int debut, int fin, int & cptEcrit, int & cptComp)
{
    if (debut<fin) /// cas d'arr�t pour la r�cursivit�
    {
        int pivot = partitionner(debut, fin, cptEcrit, cptComp); /// division du tableau
        triRapideAux(debut, pivot-1, cptEcrit, cptComp); /// trie partie 1
        triRapideAux(pivot+1, fin, cptEcrit, cptComp); /// trie partie 2
    }
}

/// Partitionnement du vecteur (�l�ments inf�rieurs � un pivot � sa gauche et �l�ments sup�rieurs � sa droite).
/// Retourne l'indice du pivot.
int VecteurTrie::partitionner(int debut, int fin, int & cptEcrit,int & cptComp)
{
    int compteur = debut;
    int pivot = _v.at(debut);
    int i;

    for (i=debut+1; i<=fin; i++)
    {
        cptComp++;
        if (_v.at(i) < pivot) /// si �l�ment inf�rieur au pivot
        {
            compteur++; /// incr�mente compteur cad la place finale du pivot
            echanger(compteur, i, cptEcrit); /// �l�ment positionn�
        }
    }
    echanger(compteur, debut, cptEcrit); /// le pivot est plac�
    return compteur; /// et sa position est retourn�e
}

/****** TRI BULLE ==> � faire ******/

void VecteurTrie::triBulles(int & cptEcrit, int & cptComp)
{
    /// � vous
    size_t lastIndex = _v.size() - 2; 
    while (lastIndex != 1) {
        for (size_t i = 0; i < lastIndex; ++i) {
            _v[i]   = std::min(_v[i], _v[i+1]);
            _v[i+1] = std::max(_v[i], _v[i+1]);
            cptEcrit += 2;
            cptComp += 2;
        }
        --lastIndex;
    }
}

/****** TRI BULLE OPTIMISE ==> � faire ******/

void VecteurTrie::triBullesOpt(int & cptEcrit, int & cptComp)
{
    /// � vous
    int i, fin = _v.size(), finTemp;
    while (fin > 1) {
        ++cptComp;
        finTemp = 1;
        for (size_t i = 1; i < fin-1; ++i) {
            if (_v[i-1] > _v[i]) {
                int temp = _v[i-1];
                _v[i-1] = _v[i];
                ++cptEcrit;
                _v[i] = temp;
                ++cptEcrit;
                finTemp = i;
            }
            ++cptComp;
        }
        fin = finTemp;
    }
    ++cptComp;
}
