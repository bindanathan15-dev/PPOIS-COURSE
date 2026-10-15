#ifndef SET_H
#define SET_H

#include <string>
#include <vector>
#include <iostream>

class Set {
private:
    bool isSubSet;                 // Indique si cet ?l?ment est un sous-ensemble (True) ou un atome (False)
    std::string atom;              // Contient la lettre/valeur si c'est un ?l?ment simple (ex: "a")
    std::vector<Set> elements;     // Contient la liste des ?l?ments si c'est un sac/ensemble

    // Fonction interne de nettoyage automatique
    void removeDuplicates();

public:
    // 1. Constructeurs (Boutons de fabrication)
    Set();                         // Cr?e un ensemble vide : {}
    Set(std::string singleAtom);   // Cr?e un ?l?ment de base simple (Atome)

    // 2. Op?rations de base de l'?nonc?
    bool isEmpty() const;          // V?rifie si l'ensemble est vide
    int cardinality() const;       // D?termine le nombre d'?l?ments uniques (Taille)
    void addElement(const Set& element);    // Ajoute un ?l?ment (en ?vitant les doublons)
    void removeElement(const Set& element); // Retire un ?l?ment du sac

    // 3. V?rification d'appartenance (Surcharge des crochets [])
    bool operator[](const Set& element) const;

    // 4. Op?rations ensemblistes (Union +, Intersection *, Diff?rence -)
    Set operator+(const Set& other) const;  // Union
    Set& operator+=(const Set& other);

    Set operator*(const Set& other) const;  // Intersection
    Set& operator*=(const Set& other);

    Set operator-(const Set& other) const;  // Diff?rence
    Set& operator-=(const Set& other);

    // 5. Fonctions sp?ciales exig?es par la BSUIR
    Set powerSet() const;          // Construit l'ensemble des parties (Power Set)
    static Set fromString(const std::string& str); // L'analyseur r?cursif de texte

    // 6. Fen?tre d'affichage pour la console
    std::string toString() const;
};

#endif // SET_H
