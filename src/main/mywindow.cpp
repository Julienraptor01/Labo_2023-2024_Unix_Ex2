#include "mywindow.h"
#include "ui_mywindow.h"

#include "FichierUtilisateur.h"

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

MyWindow::MyWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MyWindow)
{
	ui->setupUi(this);

	ui->tableWidgetClients->setColumnCount(2);
	ui->tableWidgetClients->setRowCount(0);
	QStringList labelsTableClients;
	labelsTableClients << "Nom" << "Hash du mot de passe";
	ui->tableWidgetClients->setHorizontalHeaderLabels(labelsTableClients);
	ui->tableWidgetClients->setSelectionMode(QAbstractItemView::NoSelection);
	ui->tableWidgetClients->horizontalHeader()->setVisible(true);
	ui->tableWidgetClients->horizontalHeader()->setDefaultSectionSize(300);
	ui->tableWidgetClients->horizontalHeader()->setStretchLastSection(true);
	ui->tableWidgetClients->verticalHeader()->setVisible(false);
	ui->tableWidgetClients->horizontalHeader()->setStyleSheet("background-color: lightyellow");

	//if the file does not exist, create it
	int fd = open(FICHIER_UTILISATEURS, O_WRONLY | O_CREAT, 0644);
	if (fd != -1)
		::close(fd);
}

MyWindow::~MyWindow()
{
	delete ui;
}

void MyWindow::setNom(const char *Text)
{
	if (strlen(Text) == 0)
	{
		ui->lineEditNom->clear();
		return;
	}
	ui->lineEditNom->setText(Text);
}

const char *MyWindow::getNom()
{
	strcpy(_nom, ui->lineEditNom->text().toStdString().c_str());
	return _nom;
}

void MyWindow::setMotDePasse(const char *Text)
{
	if (strlen(Text) == 0)
	{
		ui->lineEditMotDePasse->clear();
		return;
	}
	ui->lineEditMotDePasse->setText(Text);
}

const char *MyWindow::getMotDePasse()
{
	strcpy(_motDePasse, ui->lineEditMotDePasse->text().toStdString().c_str());
	return _motDePasse;
}

bool MyWindow::isNouveauChecked()
{
	if (ui->checkBoxNouveau->isChecked())
		return true;
	return false;
}

void MyWindow::setResultat(const char *Text)
{
	if (strlen(Text) == 0)
	{
		ui->lineEditResultat->clear();
		return;
	}
	ui->lineEditResultat->setText(Text);
}

void MyWindow::ajouteTupleTableUtilisateurs(const char *nom, int hash)
{
	char Hash[20];
	sprintf(Hash, "%d", hash);

	int nbLignes = ui->tableWidgetClients->rowCount();
	nbLignes++;
	ui->tableWidgetClients->setRowCount(nbLignes);
	ui->tableWidgetClients->setRowHeight(nbLignes - 1, 10);

	QTableWidgetItem *item = new QTableWidgetItem;
	auto flags = item->flags();
	flags.setFlag(Qt::ItemIsEditable, false).setFlag(Qt::ItemIsSelectable, false);
	item->setFlags(flags);
	item->setTextAlignment(Qt::AlignCenter);
	item->setText(nom);
	ui->tableWidgetClients->setItem(nbLignes - 1, 0, item);

	item = new QTableWidgetItem;
	flags = item->flags();
	flags.setFlag(Qt::ItemIsEditable, false).setFlag(Qt::ItemIsSelectable, false);
	item->setFlags(flags);
	item->setTextAlignment(Qt::AlignCenter);
	item->setText(Hash);
	ui->tableWidgetClients->setItem(nbLignes - 1, 1, item);
}

void MyWindow::videTableUtilisateurs()
{
	ui->tableWidgetClients->setRowCount(0);
}

void MyWindow::on_pushButtonLogin_clicked()
{
	//char nom[20], motDePasse[20];
	char nom[20] = {0}, motDePasse[20] = {0};
	bool nouvelUtilisateur = isNouveauChecked();
	strcpy(nom, getNom());
	strcpy(motDePasse, getMotDePasse());
	int pos = estPresent(nom);
	printf("Clic sur bouton LOGIN : --%s--%s--%d--\n", nom, motDePasse, nouvelUtilisateur);
	if (nouvelUtilisateur)
	{
		if (pos != 0)
		{
			setResultat("Utilisateur déjà existant !");
			return;
		}
		ajouteUtilisateur(nom, motDePasse);
		setResultat("Nouvel utilisateur créé : bienvenue !");
		return;
	}
	if (pos == 0)
	{
		setResultat("Utilisateur inconnu…");
		return;
	}
	if (!verifieMotDePasse(pos, motDePasse))
	{
		setResultat("Mot de passe incorrect !");
		return;
	}
	setResultat("Re-bonjour cher utilisateur !");
}

void MyWindow::on_pushButtonAfficheFichier_clicked()
{
	printf("Clic sur bouton AFFICHER\n");
	struct stat st;
	if (stat(FICHIER_UTILISATEURS, &st) == -1)
	return;
	int numberOfUsers = st.st_size / (sizeof(char) * 20 + sizeof(int));
	UTILISATEUR *vecteur = new UTILISATEUR[numberOfUsers];
	listeUtilisateurs(vecteur);
	videTableUtilisateurs();
	for (int i = 0; i < numberOfUsers; i++)
		ajouteTupleTableUtilisateurs(vecteur[i].nom, vecteur[i].hash);
	delete[] vecteur;
}
