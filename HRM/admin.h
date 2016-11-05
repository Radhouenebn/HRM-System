#ifndef ADMIN
#define ADMIN
#include <QDialog>
#include <QString>
#include <QLineEdit>
#include <QDateEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QTextEdit>
#include <QLabel>
using namespace std;
class admin : public QDialog
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = 0);
    ~admin();
    QTextEdit *textEdit;
     QPushButton *ajouter;
     QPushButton *modifier;
      QLineEdit *username,*password,*verif_password,*old_password;
      QLabel *old_pass, *pass, *verif_pass;
private slots:
    void ajouter_admin();
    void modifier_admin();
private:
    QPushButton *annuler;
    QString Username,Password,Verif_password;
};
#endif // admin



