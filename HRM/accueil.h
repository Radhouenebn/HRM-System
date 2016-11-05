#ifndef ACCUEIL
#define ACCUEIL
#include <QMainWindow>
#include <QtGui>
#include <QString>
#include <QTableView>
#include <QPushButton>
#include <QSqlQuery>
#include <QTextEdit>
#include <QSqlQueryModel>
#include "login.h"


class accueil : public QMainWindow
{
    Q_OBJECT

public:
    explicit accueil(QWidget *parent = 0);
    ~accueil();
    QMenu *menuGestion_des_administrateurs;
private slots:
    void on_Deconnecter_triggered();
    void on_ajout_triggered();
    void on_modif_triggered();
    void on_supp_triggered();
    void on_consulter_triggered();
    void on_ajout_admin_triggered();
    void on_modif_admin_triggered();
    void on_supp_admin_triggered();
    void on_consulter_admin_triggered();
private:
QString code_cin;
QString user;
QPushButton *actualiser;
QSqlQuery *qry;
QTableView *table;
QWidget *cons,*cons1;
QTextEdit *title;
QPushButton *annuler;
QSqlQueryModel * modal;
login *a;
};

#endif // ACCUEIL

