#include "FichierUtilisateur.h"

#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int estPresent(const char *nom)
{
	int fd = open(FICHIER_UTILISATEURS, O_RDONLY);
	if (fd == -1)
		return -1;
	int pos = 0;
	bool found = false;
	char buffer[20];
	while (read(fd, buffer, sizeof(buffer)) > 0)
	{
		pos++;
		if (strcmp(buffer, nom) == 0)
		{
			found = true;
			break;
		}
		lseek(fd, sizeof(int), SEEK_CUR);
	}
	close(fd);
	return found ? pos : 0;
}

int hash(const char *motDePasse)
{
	// don't use this in real code pls fr, you can make collisions just by thinking 2 seconds
	// Ex : "a" and "aaaaa" have the same hash value of 0
	// Ex : "ab" and "ca" have the same hash value of 2
	// Here's a list of the 97 shortest passwords in json
	// See hashcracker.sh if you need to crack a hash
	int sum = 0;
	for (int i = 0; i < (int)strlen(motDePasse); i++)
		sum += (int)motDePasse[i] * (i + 1);
	return sum % 97;
}

void ajouteUtilisateur(const char *nom, const char *motDePasse)
{
	int hashValue = hash(motDePasse);
	int fd = open(FICHIER_UTILISATEURS, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd == -1)
		return;
	write(fd, nom, sizeof(char) * 20);
	write(fd, &hashValue, sizeof(hashValue));
	close(fd);
}

int verifieMotDePasse(int pos, const char *motDePasse)
{
	int fd = open(FICHIER_UTILISATEURS, O_RDONLY);
	if (fd == -1)
		return -1;
	lseek(fd, (pos - 1) * (sizeof(char) * 20 + sizeof(int)) + sizeof(char) * 20, SEEK_SET);
	int hashValue;
	read(fd, &hashValue, sizeof(hashValue));
	close(fd);
	return hash(motDePasse) == hashValue;
}

int listeUtilisateurs(UTILISATEUR *vecteur)
{
	int fd = open(FICHIER_UTILISATEURS, O_RDONLY);
	if (fd == -1)
		return -1;
	int pos = 0;
	char buffer[20];
	while (read(fd, buffer, sizeof(buffer)) > 0)
	{
		strcpy(vecteur[pos].nom, buffer);
		read(fd, &vecteur[pos].hash, sizeof(int));
		pos++;
	}
	close(fd);
	return pos;
}
