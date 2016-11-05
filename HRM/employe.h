#ifndef EMPLOYE
#define EMPLOYE
#include <QDialog>
#include <QString>
#include <QLineEdit>
#include <QDateEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QTextEdit>
using namespace std;
class employe : public QDialog
{
    Q_OBJECT

public:
    explicit employe(QWidget *parent = 0);
    ~employe();
     QTextEdit *textEdit;
     QPushButton *ajouter;
     QPushButton *modifier;
     QLineEdit *CIN,*nom,*prenom,*adresse,*mail,*tel,*poste,*lieu,*salaire;
      QDateEdit *date;
      QRadioButton *mr,*mme,*mlle;
private slots:
    void ajouter_employe();
    void modifier_employe();
private:
    QPushButton *annuler;
    QString Cin,Nom,Prenom,Adresse,Mail,Tel,Poste,Lieu,Date,Salaire,Etat;
};
#endif // EMPLOYE

