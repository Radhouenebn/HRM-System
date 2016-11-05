#ifndef LOGIN
#define LOGIN
#include <QMainWindow>
#include <QtGui>
#include <QSqlDatabase>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QStatusBar>
#include <qcombobox.h>

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();
    QPushButton *connect_bt;
    QPushButton *exit;
    QSqlDatabase mydb;
    QString who;

private slots:

    void on_connect_clicked();

    void on_exit_clicked();

private:
QLineEdit * lineEdit_username;
QLineEdit * lineEdit_password;
};
#endif // LOGIN

