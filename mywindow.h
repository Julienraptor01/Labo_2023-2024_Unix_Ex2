#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MyWindow; }
QT_END_NAMESPACE

class MyWindow : public QMainWindow
{
    Q_OBJECT

public:
    MyWindow(QWidget *parent = nullptr);
    ~MyWindow();

    void setNom(const char *Text);
    const char *getNom();
    void setMotDePasse(const char *Text);
    const char *getMotDePasse();
    int isNouveauChecked();
    void setResultat(const char *Text);
    void ajouteTupleTableUtilisateurs(const char *nom, int hash);
    void videTableUtilisateurs();

private slots:
    void on_pushButtonLogin_clicked();
    void on_pushButtonAfficheFichier_clicked();

private:
    Ui::MyWindow *ui;

    char _nom[20];
    char _motDePasse[20];
};
#endif // MYWINDOW_H
