#ifndef FICHIER_UTILISATEUR_H
#define FICHIER_UTILISATEUR_H

#define FICHIER_UTILISATEURS "out/utilisateurs.dat"

typedef struct
{
	char nom[20];
	int hash;
} UTILISATEUR;

int estPresent(const char *nom);
int hash(const char *motDePasse);
void ajouteUtilisateur(const char *nom, const char *motDePasse);
int verifieMotDePasse(int pos, const char *motDePasse);
int listeUtilisateurs(UTILISATEUR *vecteur);

#endif
