#include "admin.h"
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
admin::admin(QWidget *parent):QDialog(parent)
{
    QLabel *user;

    setFixedSize(600,500);
    this->setWindowIcon(QIcon("logo.png"));
    ajouter = new QPushButton ("Ajouter",this);
    ajouter->setObjectName(QStringLiteral("ajouter"));
    ajouter->setGeometry(QRect(220, 420,70,20));
    annuler = new QPushButton ("Annuler",this);
    annuler->setObjectName(QStringLiteral("annuler"));
    annuler->setGeometry(QRect(310,420,70,20));
    modifier = new QPushButton ("Modifier",this);
    modifier->setObjectName(QStringLiteral("modifier"));
    modifier->setGeometry(QRect(220, 420,70,20));
    modifier->setText("Modifier");
    old_pass = new QLabel (this);
    old_pass->setObjectName(QStringLiteral("old_pass"));
    old_pass->setGeometry(QRect(70, 330, 110, 13));
    old_pass->setText("Ancien mot de passe:");
    user = new QLabel (this);
    user->setObjectName(QStringLiteral("user"));
    user->setGeometry(QRect(70, 150, 77, 13));
    pass = new QLabel (this);
    pass->setObjectName(QStringLiteral("pass"));
    pass->setGeometry(QRect(70, 210, 77, 13));
    verif_pass = new QLabel (this);
    verif_pass->setObjectName(QStringLiteral("verif_pass"));
    verif_pass->setGeometry(QRect(70, 270, 110, 13));
    username = new QLineEdit (this);
    username->setObjectName(QStringLiteral("username"));
    username->setGeometry(QRect(212, 150, 221, 20));
    password = new QLineEdit (this);
    password->setObjectName(QStringLiteral("password"));
    password->setGeometry(QRect(212, 210, 221, 20));
    password->setEchoMode(QLineEdit::Password);
    verif_password = new QLineEdit (this);
    verif_password->setObjectName(QStringLiteral("verif_password"));
    verif_password->setGeometry(QRect(212, 270, 221, 20));
    verif_password->setEchoMode(QLineEdit::Password);

    textEdit = new QTextEdit (this);
    textEdit->setObjectName(QStringLiteral("textEdit"));
    textEdit->setGeometry(QRect(20, 20, 201, 31));
    textEdit->setFrameShape(QFrame::NoFrame);
    textEdit->setFrameShadow(QFrame::Plain);
    textEdit->setReadOnly(true);
    textEdit->setCursorWidth(0);

    this->setWindowTitle("Ajout");
    user->setText("Identifiant:");
    pass->setText("Mot de passe:");
    verif_pass->setText("Retapez mot de passe:");
    textEdit->setHtml("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#055f04;\">Nouvel administrateur:</span></p></body></html>");
    QObject::connect(annuler,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(ajouter,SIGNAL(clicked()),this,SLOT(ajouter_admin()));
    QObject::connect(modifier,SIGNAL(clicked()),this,SLOT(modifier_admin()));

}
admin::~admin()
{
    delete(this);
}
void admin::ajouter_admin()
{
    Username=username->text();
    Password=password->text();
    Verif_password=verif_password->text();
    if (Password==Verif_password)
    {
        QSqlQuery ajout;
        if (ajout.exec("INSERT INTO admin (user,password) VALUES ('"+Username+"','"+Password+"')"))
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
    else
       {
        QMessageBox msgBox(QMessageBox::Warning,"Warning","Mots de passe ne sont pas identiques !");
                QPalette palette;
                palette.setColor(QPalette::Background, QColor("silver"));
                msgBox.setPalette(palette);
                msgBox.exec();
        }
}
void admin::modifier_admin()
{
    Username=username->text();
    Password=password->text();
    Verif_password=verif_password->text();
    if (Password==Verif_password)
    {QSqlQuery modif;
    if (modif.exec("UPDATE admin SET user='"+Username+"',password='"+Password+"' where user='"+Username+"'"))
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
    else
    {
        QMessageBox msgBox(QMessageBox::Warning,"Warning","Mots de passe ne sont pas identiques !");
                QPalette palette;
                palette.setColor(QPalette::Background, QColor("silver"));
                msgBox.setPalette(palette);
                msgBox.exec();
    }
}
