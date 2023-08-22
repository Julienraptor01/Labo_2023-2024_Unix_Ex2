#ifndef FICHIER_UTILISATEUR_H
#define FICHIER_UTILISATEUR_H

#define FICHIER_UTILISATEURS "utilisateurs.dat"

// Pour le fichier des utilisateurs
typedef struct
{
  char  nom[20];
  int   hash;
} UTILISATEUR;

int estPresent(const char* nom);
// retourne -1 en cas d'erreur
//           0 si pas trouve
//           la position (1,2,3, ...) dans le fichier si trouve

int hash(const char* motDePasse);
// calcul le hash du mot de passe = (somme des codes ASCII) % 97

void ajouteUtilisateur(const char* nom, const char* motDePasse);
// ajoute un nouvel utilisateur à la fin du fichier
// crée le fichier su celui-ci n'existe pas

int verifieMotDePasse(int pos, const char* motDePasse);
// reçoit la position de l'utilisateur obligatoirement présent dans le fichier et un mot de passe
// retourne 1 si le mot de passe est correct
//          0 sinon
//         -1 en cas d'erreur 

int listeUtilisateurs(UTILISATEUR *vecteur);
// reçoit l'adresse d'un vecteur d'utilisateurs suffisament grand pour recevoir le contenu du fichier
// retourne le nombre d'utilisateurs présents dans le fichier
//          -1 si le fichier n'existe pas

#endif
