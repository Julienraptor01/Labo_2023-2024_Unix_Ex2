/********************************************************************************
** Form generated from reading UI file 'mywindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWINDOW_H
#define UI_MYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_2;
    QLineEdit *lineEditMotDePasse;
    QLineEdit *lineEditNom;
    QPushButton *pushButtonLogout;
    QLabel *label;
    QPushButton *pushButtonLogin;
    QCheckBox *checkBoxNouveau;
    QLabel *label_3;
    QLineEdit *lineEditResultat;
    QLabel *label_4;
    QTableWidget *tableWidgetClients;
    QPushButton *pushButtonAfficheFichier;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MyWindow)
    {
        if (MyWindow->objectName().isEmpty())
            MyWindow->setObjectName(QString::fromUtf8("MyWindow"));
        MyWindow->resize(800, 334);
        centralwidget = new QWidget(MyWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(210, 10, 131, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(12);
        label_2->setFont(font);
        lineEditMotDePasse = new QLineEdit(centralwidget);
        lineEditMotDePasse->setObjectName(QString::fromUtf8("lineEditMotDePasse"));
        lineEditMotDePasse->setGeometry(QRect(328, 10, 111, 25));
        lineEditMotDePasse->setFont(font);
        lineEditMotDePasse->setAlignment(Qt::AlignCenter);
        lineEditNom = new QLineEdit(centralwidget);
        lineEditNom->setObjectName(QString::fromUtf8("lineEditNom"));
        lineEditNom->setGeometry(QRect(68, 10, 131, 25));
        lineEditNom->setFont(font);
        lineEditNom->setAlignment(Qt::AlignCenter);
        pushButtonLogout = new QPushButton(centralwidget);
        pushButtonLogout->setObjectName(QString::fromUtf8("pushButtonLogout"));
        pushButtonLogout->setEnabled(false);
        pushButtonLogout->setGeometry(QRect(560, 10, 91, 25));
        pushButtonLogout->setFont(font);
        pushButtonLogout->setStyleSheet(QString::fromUtf8("background-color:rgb(252, 175, 62)"));
        pushButtonLogout->setCheckable(false);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(18, 10, 64, 21));
        label->setFont(font);
        pushButtonLogin = new QPushButton(centralwidget);
        pushButtonLogin->setObjectName(QString::fromUtf8("pushButtonLogin"));
        pushButtonLogin->setGeometry(QRect(460, 10, 91, 25));
        pushButtonLogin->setFont(font);
        pushButtonLogin->setStyleSheet(QString::fromUtf8("background-color:rgb(138, 226, 52)"));
        checkBoxNouveau = new QCheckBox(centralwidget);
        checkBoxNouveau->setObjectName(QString::fromUtf8("checkBoxNouveauClient"));
        checkBoxNouveau->setGeometry(QRect(670, 10, 111, 23));
        checkBoxNouveau->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 60, 161, 21));
        label_3->setFont(font);
        lineEditResultat = new QLineEdit(centralwidget);
        lineEditResultat->setObjectName(QString::fromUtf8("lineEditResultat"));
        lineEditResultat->setGeometry(QRect(180, 60, 591, 25));
        lineEditResultat->setFont(font);
        lineEditResultat->setReadOnly(true);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 120, 171, 17));
        label_4->setFont(font);
        tableWidgetClients = new QTableWidget(centralwidget);
        tableWidgetClients->setObjectName(QString::fromUtf8("tableWidgetClients"));
        tableWidgetClients->setGeometry(QRect(20, 140, 751, 151));
        pushButtonAfficheFichier = new QPushButton(centralwidget);
        pushButtonAfficheFichier->setObjectName(QString::fromUtf8("pushButtonAfficheFichier"));
        pushButtonAfficheFichier->setGeometry(QRect(590, 110, 181, 25));
        pushButtonAfficheFichier->setFont(font);
        pushButtonAfficheFichier->setStyleSheet(QString::fromUtf8("background-color:rgb(216, 250, 249)"));
        MyWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MyWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MyWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MyWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MyWindow->setStatusBar(statusbar);

        retranslateUi(MyWindow);

        QMetaObject::connectSlotsByName(MyWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MyWindow)
    {
        MyWindow->setWindowTitle(QApplication::translate("MyWindow", "Gestion d'un fichier binaire d'utilisateurs", nullptr));
        label_2->setText(QApplication::translate("MyWindow", "Mot de passe :", nullptr));
        pushButtonLogout->setText(QApplication::translate("MyWindow", "Logout", nullptr));
        label->setText(QApplication::translate("MyWindow", "Nom :", nullptr));
        pushButtonLogin->setText(QApplication::translate("MyWindow", "Login", nullptr));
        checkBoxNouveau->setText(QApplication::translate("MyWindow", "Nouveau", nullptr));
        label_3->setText(QApplication::translate("MyWindow", "Resultat du login :", nullptr));
        label_4->setText(QApplication::translate("MyWindow", "Contenu du fichier :", nullptr));
        pushButtonAfficheFichier->setText(QApplication::translate("MyWindow", "Afficher", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyWindow: public Ui_MyWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWINDOW_H
