#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include <QLabel>
#include <QInputDialog>
#include <QMessageBox>
#include <QSqlQuery>
#include <QTableView>
#include <QTextEdit>
#include <QSqlQueryModel>
#include "accueil.h"
#include "login.h"
#include "employe.h"
#include "admin.h"
#include<QStyle>

accueil::accueil(QWidget *parent) :QMainWindow(parent)
{
    this->setFixedSize(700,600);
    this->setWindowTitle("Accueil");
    this->setStyleSheet("background-color: #EDB228;");
    this->setWindowIcon(QIcon("logo.png"));
    /**************************/
        QAction *actionQuitter;
        QAction *actionDeconnecter;
        QAction *actionAjouter;
        QAction *actionSupprimer;
        QAction *actionModifier;
        QAction *actionConsulter_la_liste;
        QAction *actionAjouter_2;
        QAction *actionSupprimer_2;
        QAction *actionModifier_2;
        QAction *actionConsulter_la_liste_2;
        QWidget *centralwidget;
        QLabel *logo;
        QTextEdit *title;
        QMenuBar *menubar;
        QMenu *menuGestion_des_personnels;
        QStatusBar *statusbar;
        /*************************/
                this->setObjectName(QStringLiteral("accueil"));
                this->setWindowModality(Qt::WindowModal);
                actionAjouter = new QAction(this);
                actionAjouter->setObjectName(QStringLiteral("actionAjouter"));
                actionSupprimer = new QAction(this);
                actionSupprimer->setObjectName(QStringLiteral("actionSupprimer"));
                actionModifier = new QAction(this);
                actionModifier->setObjectName(QStringLiteral("actionModifier"));
                actionConsulter_la_liste = new QAction(this);
                actionConsulter_la_liste->setObjectName(QStringLiteral("actionConsulter_la_liste"));
                actionAjouter_2 = new QAction(this);
                actionAjouter_2->setObjectName(QStringLiteral("actionAjouter_2"));
                actionSupprimer_2 = new QAction(this);
                actionSupprimer_2->setObjectName(QStringLiteral("actionSupprimer_2"));
                actionModifier_2 = new QAction(this);
                actionModifier_2->setObjectName(QStringLiteral("actionModifier_2"));
                actionConsulter_la_liste_2 = new QAction(this);
                actionConsulter_la_liste_2->setObjectName(QStringLiteral("actionConsulter_la_liste_2"));
                actionDeconnecter = new QAction(this);
                actionDeconnecter->setObjectName(QStringLiteral("actionDeconnecter"));
                actionQuitter = new QAction(this);
                actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
                centralwidget = new QWidget(this);
                centralwidget->setObjectName(QStringLiteral("centralwidget"));

                title = new QTextEdit(this);
                title->setObjectName(QStringLiteral("title"));
                title->setGeometry(QRect(70, 100, 581, 150));
                title->setFrameShape(QFrame::NoFrame);
                title->setHtml("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
                "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
                "p, li { white-space: pre-wrap; }\n"
                "</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
                "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe Print'; font-size:28pt; color:#aa007f;\">Interface de Gestion de Ressources Humaines</span></p></body></html>");
                title->setCursorWidth(0);
                this->setCentralWidget(centralwidget);
                menubar = new QMenuBar(this);
                menubar->setObjectName(QStringLiteral("menubar"));
                menubar->setGeometry(QRect(0, 0, 800, 21));
                menubar->setDefaultUp(false);

                menuGestion_des_personnels = new QMenu(menubar);
                menuGestion_des_personnels->setObjectName(QStringLiteral("menuGestion_des_personnels"));
                menuGestion_des_administrateurs = new QMenu(menubar);
                menuGestion_des_administrateurs->setObjectName(QStringLiteral("menuGestion_des_administrateurs"));
                this->setMenuBar(menubar);
                statusbar = new QStatusBar(this);
                statusbar->setObjectName(QStringLiteral("statusbar"));
                this->setStatusBar(statusbar);
                menuGestion_des_personnels->setStyleSheet("QMenu { background-color:qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 #F2EFEF, stop: 1 #333333);}");
                menuGestion_des_administrateurs->setStyleSheet("QMenu { background-color:qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 #F2EFEF, stop: 1 #333333);}");
                menubar->setStyleSheet("QMenuBar { spacing: 8 px;padding: 2 px 4 px;background: transparent;border-radius: 4 px; background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 lightgray);}");
                menubar->addAction(menuGestion_des_personnels->menuAction());
                menubar->addAction(menuGestion_des_administrateurs->menuAction());
                menubar->addAction(actionDeconnecter);
                menubar->addAction(actionQuitter);
                menuGestion_des_personnels->addAction(actionAjouter);
                menuGestion_des_personnels->addAction(actionSupprimer);
                menuGestion_des_personnels->addAction(actionModifier);
                menuGestion_des_personnels->addAction(actionConsulter_la_liste);

                menuGestion_des_administrateurs->addAction(actionAjouter_2);
                menuGestion_des_administrateurs->addAction(actionSupprimer_2);
                menuGestion_des_administrateurs->addAction(actionModifier_2);
                menuGestion_des_administrateurs->addAction(actionConsulter_la_liste_2);

                logo = new QLabel(this);
                logo->setObjectName(QStringLiteral("logo"));
                logo->setGeometry(QRect(260, 350, 231, 141));
                logo->setPixmap(QPixmap(QString::fromUtf8("logo.jpg")));
                /********************************************/
                        actionAjouter->setText("Ajouter");
                        actionSupprimer->setText("Supprimer");
                        actionModifier->setText("Modifier");
                        actionConsulter_la_liste->setText("Consulter la liste");
                        actionAjouter_2->setText("Ajouter");
                        actionSupprimer_2->setText("Supprimer");
                        actionModifier_2->setText("Modifier");
                        actionConsulter_la_liste_2->setText("Consuler la liste");
                        actionQuitter->setText("     Quitter     ");
                        actionDeconnecter->setText("  Déconnexion  ");
                        /*textEdit->setHtml("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
                "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
                "p, li { white-space: pre-wrap; }\n"
                "</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
                "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:36pt; font-style:italic; color:#0000ff;\">Bienvenu</span></p></body></html>"); */
                        menuGestion_des_personnels->setTitle(" Gestion   des   personnels   ");
                        menuGestion_des_administrateurs->setTitle(" Gestion   des   administrateurs ");
                        //menuLogout->setTitle("  Déconnexion  ");
                        //menuQuitter->setTitle("     Quitter     ");
                        /*******************************************/

                        QObject::connect(actionQuitter,SIGNAL(triggered()),this,SLOT(close()));
                        QObject::connect(actionDeconnecter,SIGNAL(triggered()),this,SLOT(on_Deconnecter_triggered()));
                        QObject::connect(actionAjouter,SIGNAL(triggered()),this,SLOT(on_ajout_triggered()));
                        QObject::connect(actionModifier,SIGNAL(triggered()),this,SLOT(on_modif_triggered()));
                        QObject::connect(actionSupprimer,SIGNAL(triggered()),this,SLOT(on_supp_triggered()));
                        QObject::connect(actionConsulter_la_liste,SIGNAL(triggered()),this,SLOT(on_consulter_triggered()));
                        QObject::connect(actionAjouter_2,SIGNAL(triggered()),this,SLOT(on_ajout_admin_triggered()));
                        QObject::connect(actionModifier_2,SIGNAL(triggered()),this,SLOT(on_modif_admin_triggered()));
                        QObject::connect(actionSupprimer_2,SIGNAL(triggered()),this,SLOT(on_supp_admin_triggered()));
                        QObject::connect(actionConsulter_la_liste_2,SIGNAL(triggered()),this,SLOT(on_consulter_admin_triggered()));
}

accueil::~accueil()
{
    delete (this);
}
void accueil::on_Deconnecter_triggered()
{
    login* h;
    h = new login();
    this->close();
    h->show();
}
void accueil::on_ajout_triggered()
{
    employe *a;
    a = new employe();
    delete a->modifier;
    a->show();
}
void accueil::on_modif_triggered()

{
    QInputDialog * modiff= new QInputDialog();
    modiff->setStyleSheet("QWidget { background-color: silver; }");
    code_cin = modiff->getText(this,"CIN","Entrer un CIN:");
    if (!code_cin.isEmpty())
    {
    QSqlQuery verif;
   if (verif.exec("select * from EmployeeInfo where cin='"+code_cin+"'"))
  { if (verif.next())
   {
       employe * f;
       f= new employe();
       f->textEdit->setHtml("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#055f04;\">Mis à jour d\'un employ\303\251:</span></p></body></html>");
       f->textEdit->setGeometry(QRect(20, 20, 251, 31));
       f->setWindowTitle("Modification");
       delete f->ajouter;
       (f->CIN)->setText(verif.value(0).toString());
       f->CIN->setEnabled(false);
       (f->nom)->setText(verif.value(1).toString());
       (f->prenom)->setText(verif.value(2).toString());
       (f->adresse)->setText(verif.value(3).toString());
       (f->mail)->setText(verif.value(4).toString());
       (f->tel)->setText(verif.value(10).toString());
       (f->poste)->setText(verif.value(5).toString());
       (f->lieu)->setText(verif.value(8).toString());
       (f->salaire)->setText(verif.value(9).toString());
       (f->date)->setDate(QDate::fromString(verif.value(7).toString(),"dd/MM/yyyy"));
       QString etat= verif.value(6).toString();
       if (etat == "Monsieur")
           (f->mr)->setChecked(true);
       else if (etat == "Madame")
           (f->mme)->setChecked(true);
       else
           (f->mlle)->setChecked(true);
       f->show();
   }
   else
   {
       QMessageBox msgBox(QMessageBox::Warning,"Warning","Employé introuvable !");
               QPalette palette;
               palette.setColor(QPalette::Background, QColor("silver"));
               msgBox.setPalette(palette);
               msgBox.exec();
   }
   }
   }
    else if (code_cin.isEmpty())
    {
        QMessageBox msgBox(QMessageBox::Warning,"Warning","CIN vide !");
                QPalette palette;
                palette.setColor(QPalette::Background, QColor("silver"));
                msgBox.setPalette(palette);
                msgBox.exec();

    }
    else
    {
        modiff->close();
    }
}
void accueil::on_supp_triggered()
{
    code_cin = QInputDialog::getText(this, "CIN", "Entrer un CIN:");
    QSqlQuery verif;
    if (verif.exec("select * from EmployeeInfo where cin='"+code_cin+"'"))
   {
        if (verif.next())
            {  int reponse = QMessageBox::question(this, "Confirmation", "Supprimer <b>"+verif.value(1).toString()+" "+verif.value(2).toString()+"</b> ,êtes-vous vraiment sûr ?",QMessageBox::Yes | QMessageBox::No);
              if (reponse == QMessageBox::Yes)
                 {    QSqlQuery supp;
                if (supp.exec("delete from EmployeeInfo where cin='"+code_cin+"'"))
                   {
                    QMessageBox::information(this, "Succés", "Suppression réussite !");
                   }
                else
                {
                    QMessageBox::warning(this, "Echec", "Suppression echouée !");
                }
              }
            }
            else
            {
                QMessageBox msgBox(QMessageBox::Warning,"Warning","Employé introuvable !");
                        QPalette palette;
                        palette.setColor(QPalette::Background, QColor("silver"));
                        msgBox.setPalette(palette);
                        msgBox.exec();
            }
   }

}
void accueil::on_consulter_triggered()
{
    cons = new QWidget();
    cons->setWindowIcon(QIcon("logo.png"));
    actualiser = new QPushButton(cons);
    annuler = new QPushButton(cons);
    actualiser->setGeometry(QRect(200, 430,90,25));
    actualiser->setText("Actualiser");
    annuler->setGeometry(QRect(310,430,90,25));
    annuler->setText("Annuler");
    cons->setFixedSize(600,500);
    cons->setWindowTitle("Consultation de la liste");
    table = new QTableView(cons);
    table->setGeometry(QRect(35, 90, 531, 311));
    title = new QTextEdit(cons);
    title->setHtml("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
    "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
    "p, li { white-space: pre-wrap; }\n"
    "</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
    "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#055f04;\">Liste des employ\303\251s:</span></p></body></html>");
    title->setGeometry(QRect(20, 20, 201, 31));
    title->setFrameShape(QFrame::NoFrame);
    title->setFrameShadow(QFrame::Plain);
    title->setReadOnly(true);
    title->setCursorWidth(0);
   a = new login();
   modal = new QSqlQueryModel();
   qry = new QSqlQuery(a->mydb);
   qry->prepare("select * from EmployeeInfo");
   qry->exec();
   modal->setQuery(*qry);
   table->setModel(modal);

   cons->show();
   QObject::connect(annuler,SIGNAL(clicked()),cons,SLOT(close()));
   QObject::connect(actualiser,SIGNAL(clicked()),this,SLOT(on_consulter_triggered()));
}

void accueil::on_ajout_admin_triggered()
{
    admin *a;
    a = new admin();
    delete a->modifier;
    delete a->old_pass;
    a->show();
}
void accueil::on_modif_admin_triggered()
{
   user = QInputDialog::getText(this, "Identifiant", "Entrer un identifiant:");
   QSqlQuery verif;
   if (verif.exec("select * from admin where user='"+user+"'"))
  { if (verif.next())
   {
       admin * f;
       f= new admin();
       f->textEdit->setHtml("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#055f04;\">Mis à jour d\'un administrateur:</span></p></body></html>");
       f->textEdit->setGeometry(QRect(20, 20, 271, 31));
       f->setWindowTitle("Modification");
       delete f->ajouter;
       f->old_password = new QLineEdit(f);
       f->old_password->setObjectName(QStringLiteral("old_password"));
       f->old_password->setGeometry(QRect(212, 210, 221, 20));

       f->password->setGeometry(QRect(212, 270, 221, 20));
       f->verif_password->setGeometry(QRect(212, 330, 221, 20));
       f->old_pass->setGeometry(QRect(70, 210, 110, 13));
       f->pass->setGeometry(QRect(70, 270, 115, 13));
       f->pass->setText("Nouveau mot de passe:");
       f->verif_pass->setGeometry(QRect(70, 330, 110, 13));
       (f->username)->setText(verif.value(0).toString());
       (f->old_password)->setText(verif.value(1).toString());
       f->username->setEnabled(false);
       f->old_password->setEnabled(false);
         f->show();
   }
   else
   {
       QMessageBox msgBox(QMessageBox::Warning,"Warning","Administrateur introuvable !");
               QPalette palette;
               palette.setColor(QPalette::Background, QColor("silver"));
               msgBox.setPalette(palette);
               msgBox.exec();
   }
   }
 }
  void accueil::on_supp_admin_triggered()
    {
       user = QInputDialog::getText(this, "Administrateur", "Entrer un identifiant:");
       QSqlQuery verif;
       if (verif.exec("select * from admin where user='"+user+"'"))
      { if (verif.next())
       {  int reponse = QMessageBox::question(this, "Confirmation", "Supprimer <b>"+user+"</b> ,êtes-vous vraiment sûr ?",QMessageBox::Yes | QMessageBox::No);
         if (reponse == QMessageBox::Yes )
            { if (user != "root")
            {
             QSqlQuery supp;
           if (supp.exec("delete from admin where user='"+user+"'"))
              {
               QMessageBox::information(this, "Succés", "Suppression réussite !");
              }
           else
           {
               QMessageBox::warning(this, "Echec", "Suppression echouée !");
           }
         }
             else
             {
                QMessageBox::warning(this, "Echec", "Suppression du super administrateur est impossible !");
             }
         }
       }
       else
       {
           QMessageBox msgBox(QMessageBox::Warning,"Warning","Administrateur introuvable !");
                   QPalette palette;
                   palette.setColor(QPalette::Background, QColor("silver"));
                   msgBox.setPalette(palette);
                   msgBox.exec();
       }
    }
}
   void accueil::on_consulter_admin_triggered()
    {
       cons1 = new QWidget();
       cons1->setWindowIcon(QIcon("logo.png"));
       actualiser = new QPushButton(cons1);
       annuler = new QPushButton(cons1);
       actualiser->setGeometry(QRect(200, 430,90,25));
       actualiser->setText("Actualiser");
       annuler->setGeometry(QRect(310,430,90,25));
       annuler->setText("Annuler");
       cons1->setFixedSize(600,500);
       cons1->setWindowTitle("Consultation de la liste");
       table = new QTableView(cons1);
       table->setGeometry(QRect(35, 90, 531, 311));
       QTextEdit *title = new QTextEdit(cons1);
       title->setHtml("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
       "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
       "p, li { white-space: pre-wrap; }\n"
       "</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
       "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#055f04;\">Liste des administrateurs:</span></p></body></html>");
       title->setGeometry(QRect(20, 20, 231, 31));
       title->setFrameShape(QFrame::NoFrame);
       title->setFrameShadow(QFrame::Plain);
       title->setReadOnly(true);
       title->setCursorWidth(0);
       a = new login();
       modal = new QSqlQueryModel();
       qry = new QSqlQuery(a->mydb);
       qry->prepare("select * from admin");
       qry->exec();
       modal->setQuery(*qry);
       table->setModel(modal);
       table->setEditTriggers(0);
       table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

       cons1->show();
       QObject::connect(annuler,SIGNAL(clicked()),cons1,SLOT(close()));
       QObject::connect(actualiser,SIGNAL(clicked()),this,SLOT(on_consulter_admin_triggered()));
    }


