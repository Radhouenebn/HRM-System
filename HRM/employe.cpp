#include "employe.h"
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QSqlQuery>
#include <QMessageBox>

employe::employe(QWidget *parent):QDialog(parent)
{       QLabel *etat;
        QLabel *label_2;
        QLabel *label_3;
        QLabel *label_4;
        QLabel *label_5;
        QLabel *label_6;
        QLabel *label_7;
        QLabel *label_8;
        QLabel *label_9;
        QLabel *label_10;
        QLabel *label_11;
        /**************/
                setFixedSize(600,500);
                this->setWindowIcon(QIcon("logo.png"));
                ajouter = new QPushButton ("Ajouter",this);
                ajouter->setObjectName(QStringLiteral("ajouter"));
                ajouter->setGeometry(QRect(220, 420,70,20));
                annuler = new QPushButton ("Annuler",this);
                annuler->setObjectName(QStringLiteral("annuler"));
                annuler->setGeometry(QRect(310,420,70,20));
                etat= new QLabel (this);
                etat->setObjectName(QStringLiteral("etat"));
                etat->setGeometry(QRect(30, 80, 47, 13));
                label_2 = new QLabel (this);
                label_2->setObjectName(QStringLiteral("label_2"));
                label_2->setGeometry(QRect(30, 120, 47, 13));
                label_3 = new QLabel (this);
                label_3->setObjectName(QStringLiteral("label_3"));
                label_3->setGeometry(QRect(30, 150, 47, 13));
                label_4 = new QLabel (this);
                label_4->setObjectName(QStringLiteral("label_4"));
                label_4->setGeometry(QRect(30, 180, 47, 13));
                label_5 = new QLabel (this);
                label_5->setObjectName(QStringLiteral("label_5"));
                label_5->setGeometry(QRect(30, 210, 47, 13));
                label_6 = new QLabel (this);
                label_6->setObjectName(QStringLiteral("label_6"));
                label_6->setGeometry(QRect(30, 240, 61, 16));
                label_7 = new QLabel (this);
                label_7->setObjectName(QStringLiteral("label_7"));
                label_7->setGeometry(QRect(30, 270, 77, 13));
                mr = new QRadioButton (this);
                mr->setObjectName(QStringLiteral("mr"));
                mr->setGeometry(QRect(180, 80, 82, 17));
                mme = new QRadioButton (this);
                mme->setObjectName(QStringLiteral("mme"));
                mme->setGeometry(QRect(290, 80, 82, 17));
                mlle = new QRadioButton (this);
                mlle->setObjectName(QStringLiteral("mlle"));
                mlle->setGeometry(QRect(420, 80, 82, 17));
                label_8 = new QLabel (this);
                label_8->setObjectName(QStringLiteral("label_8"));
                label_8->setGeometry(QRect(30, 330, 47, 13));
                label_9 = new QLabel (this);
                label_9->setObjectName(QStringLiteral("label_9"));
                label_9->setGeometry(QRect(30, 360, 101, 16));
                CIN = new QLineEdit (this);
                CIN->setObjectName(QStringLiteral("CIN"));
                CIN->setGeometry(QRect(152, 120, 321, 20));
                nom = new QLineEdit (this);
                nom->setObjectName(QStringLiteral("nom"));
                nom->setGeometry(QRect(152, 150, 321, 20));
                prenom = new QLineEdit (this);
                prenom->setObjectName(QStringLiteral("prenom"));
                prenom->setGeometry(QRect(152, 180, 321, 20));
                adresse = new QLineEdit (this);
                adresse->setObjectName(QStringLiteral("adresse"));
                adresse->setGeometry(QRect(152, 210, 321, 20));
                mail = new QLineEdit (this);
                mail->setObjectName(QStringLiteral("mail"));
                mail->setGeometry(QRect(152, 240, 321, 20));
                tel = new QLineEdit (this);
                tel->setObjectName(QStringLiteral("tel"));
                tel->setGeometry(QRect(150, 270, 321, 20));
                poste = new QLineEdit (this);
                poste->setObjectName(QStringLiteral("poste"));
                poste->setGeometry(QRect(150, 300, 321, 20));
                salaire = new QLineEdit (this);
                salaire->setObjectName(QStringLiteral("salaire"));
                salaire->setGeometry(QRect(150, 330, 321, 20));
                date = new QDateEdit (this);
                date->setObjectName(QStringLiteral("date"));
                date->setGeometry(QRect(150, 360, 110, 22));
                label_10 = new QLabel (this);
                label_10->setObjectName(QStringLiteral("label_10"));
                label_10->setGeometry(QRect(300, 360, 47, 13));
                lieu = new QLineEdit (this);
                lieu->setObjectName(QStringLiteral("lieu"));
                lieu->setGeometry(QRect(340, 360, 131, 20));
                label_11 = new QLabel (this);
                label_11->setObjectName(QStringLiteral("label_11"));
                label_11->setGeometry(QRect(30, 300, 71, 16));
                textEdit = new QTextEdit (this);
                textEdit->setObjectName(QStringLiteral("textEdit"));
                textEdit->setGeometry(QRect(20, 20, 201, 31));
                textEdit->setFrameShape(QFrame::NoFrame);
                textEdit->setFrameShadow(QFrame::Plain);
                textEdit->setReadOnly(true);
                textEdit->setCursorWidth(0);
                    modifier = new QPushButton ("Modifier",this);
                    modifier->setObjectName(QStringLiteral("modifier"));
                    modifier->setGeometry(QRect(220, 420,70,20));
                    modifier->setText("Modifier");
                /************************/
                        this->setWindowTitle("Ajout");
                        etat->setText("Etat civil:");
                        label_2->setText("CIN:");
                        label_3->setText("nom:");
                        label_4->setText("Prénom:");
                        label_5->setText("Adresse:");
                        label_6->setText("E-mail:");
                        label_7->setText("Télephone:");
                        mr->setText("Mr");
                        mme->setText("Mme");
                        mlle->setText("Mlle");
                        label_8->setText("Salaire:");
                        label_9->setText("Date de naissance:");
                        label_10->setText("Lieu:");
                        label_11->setText("Poste:");
                        textEdit->setHtml("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
                "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
                "p, li { white-space: pre-wrap; }\n"
                "</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
                "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#055f04;\">Nouvel employ\303\251:</span></p></body></html>");
                QObject::connect(annuler,SIGNAL(clicked()),this,SLOT(close()));
                QObject::connect(ajouter,SIGNAL(clicked()),this,SLOT(ajouter_employe()));
                QObject::connect(modifier,SIGNAL(clicked()),this,SLOT(modifier_employe()));
}
employe::~employe()
{
    delete(this);
}
void employe::ajouter_employe()
{
  Cin=CIN->text();
  Nom=nom->text();
  Prenom=prenom->text();
  Adresse=adresse->text();
  Mail=mail->text();
  Salaire=salaire->text();
  Lieu=lieu->text();
  Tel=tel->text();
  Poste=poste->text();
  if(mr->isChecked())
      Etat="Monsieur";
  if (mme->isChecked())
      Etat="Madame";
  if (mlle->isChecked())
      Etat="Mademoiselle";
  Date = date->date().toString("dd MM yyyy");
  QSqlQuery ajout;
  if (ajout.exec("INSERT INTO EmployeeInfo (CIN,Nom,Prénom,Adresse,Mail,Poste,'Etat civil','Date de naissance','Lieu de naissance',Salaire,Téléphone) VALUES ('"+Cin+"','"+Nom+"','"+Prenom+"','"+Adresse+"','"+Mail+"','"+Poste+"','"+Etat+"','"+Date+"','"+Lieu+"','"+Salaire+"','"+Tel+"')"))
    {
      QMessageBox msgBox(QMessageBox::Information,"Succés","Ajout avec succés !");
              QPalette palette;
              palette.setColor(QPalette::Background, QColor("silver"));
              msgBox.setPalette(palette);
              msgBox.exec();
    }
  else
  {
      QMessageBox msgBox(QMessageBox::Warning,"Warning","Ajout echoué !");
              QPalette palette;
              palette.setColor(QPalette::Background, QColor("silver"));
              msgBox.setPalette(palette);
              msgBox.exec();
  }
}
void employe::modifier_employe()
{
    Cin=CIN->text();
    Nom=nom->text();
    Prenom=prenom->text();
    Adresse=adresse->text();
    Mail=mail->text();
    Salaire=salaire->text();
    Lieu=lieu->text();
    Tel=tel->text();
    Poste=poste->text();
    if(mr->isChecked())
        Etat="Monsieur";
    if (mme->isChecked())
        Etat="Madame";
    if (mlle->isChecked())
        Etat="Mademoiselle";
    Date = date->date().toString("dd/MM/yyyy");
    QSqlQuery modif;
    if (modif.exec("UPDATE EmployeeInfo SET Nom='"+Nom+"',Prénom='"+Prenom+"',Adresse='"+Adresse+"',Mail='"+Mail+"',Poste='"+Poste+"','Etat civil'='"+Etat+"','Date de naissance'='"+Date+"','Lieu de naissance'='"+Lieu+"',Salaire='"+Salaire+"',Téléphone='"+Tel+"' where CIN='"+Cin+"'"))
      {
        QMessageBox msgBox(QMessageBox::Information,"Succés","Modification avec succés !");
                QPalette palette;
                palette.setColor(QPalette::Background, QColor("silver"));
                msgBox.setPalette(palette);
                msgBox.exec();
      }
    else
    {
        QMessageBox msgBox(QMessageBox::Warning,"Warning","Modification echouée !");
                QPalette palette;
                palette.setColor(QPalette::Background, QColor("silver"));
                msgBox.setPalette(palette);
                msgBox.exec();
    }

}
