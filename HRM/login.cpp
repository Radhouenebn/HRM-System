#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include <QApplication>
#include "login.h"
#include "accueil.h"
#include <QMainWindow>
#include <QWidget>
#include <QMessageBox>
#include <QSqlQuery>
#include <QString>
#include <Qapplication>
#include <QLineEdit>
#include <QComboBox.h>
#include <QComboBox>
#include <QMenu>
#include <QIcon>
#include "qcombobox.h"
login::login(QWidget *parent) :QMainWindow(parent)
{
    QWidget *centralWidget;
        QLabel *logo;
        QLabel *label_2;
        QLabel *label_3;
        QPushButton *connect_bt;
        QPushButton *exit;
        QTextEdit *title;
        QStatusBar *statusBar;
       this->resize(691, 759);
        centralWidget = new QWidget(this);
                centralWidget->setObjectName(QStringLiteral("centralWidget"));
                logo = new QLabel(centralWidget);
                logo->setObjectName(QStringLiteral("logo"));
                logo->setGeometry(QRect(260, 400, 231, 141));
                logo->setPixmap(QPixmap(QString::fromUtf8("logo.jpg")));
                label_2 = new QLabel(centralWidget);
                label_2->setText("Identifiant:");
                label_2->setObjectName(QStringLiteral("label_2"));
                label_2->setGeometry(QRect(160, 210, 61, 16));
                label_3 = new QLabel(centralWidget);
                label_3->setText("Mot de passe:");
                label_3->setObjectName(QStringLiteral("label_3"));
                label_3->setGeometry(QRect(160, 260, 71, 16));
                lineEdit_username = new QLineEdit(centralWidget);
                lineEdit_username->setObjectName(QStringLiteral("lineEdit_username"));
                lineEdit_username->setGeometry(QRect(260, 210, 211, 20));
                lineEdit_username->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
                lineEdit_password = new QLineEdit(centralWidget);
                lineEdit_password->setObjectName(QStringLiteral("lineEdit_password"));
                lineEdit_password->setGeometry(QRect(260, 260, 211, 20));
                lineEdit_password->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
                lineEdit_password->setEchoMode(QLineEdit::Password);
                connect_bt = new QPushButton("Connecter",centralWidget);
                connect_bt->setObjectName(QStringLiteral("login"));
                connect_bt->setGeometry(QRect(290, 310, 75, 26));
                connect_bt->setCursor(QCursor(Qt::PointingHandCursor));
                connect_bt->setMouseTracking(false);
                connect_bt->setAcceptDrops(false);
                connect_bt->setAutoFillBackground(false);
                connect_bt->setStyleSheet(QLatin1String("font: 75 10pt \"Sylfaen\";\n" "background-color: rgb(149, 149, 149);"));
                QObject::connect(connect_bt,SIGNAL(clicked()),this,SLOT(on_connect_clicked()));
                exit = new QPushButton("Quitter",centralWidget);
                exit->setObjectName(QStringLiteral("quitter"));
                exit->setGeometry(QRect(380, 310, 75, 26));
                exit->setCursor(QCursor(Qt::PointingHandCursor));
                exit->setMouseTracking(false);
                exit->setStyleSheet(QLatin1String("font: 75 10pt \"Sylfaen\";\n" "background-color: rgb(149, 149, 149);"));
                exit->setAutoDefault(false);
                exit->setFlat(false);
                QObject::connect(exit,SIGNAL(clicked(bool)),this,SLOT(on_exit_clicked()));
                title = new QTextEdit(centralWidget);
                title->setObjectName(QStringLiteral("title"));
                title->setGeometry(QRect(70, 30, 581, 150));

                title->setFrameShape(QFrame::NoFrame);
                this->setCentralWidget(centralWidget);
                statusBar = new QStatusBar(this);
                statusBar->setObjectName(QStringLiteral("statusBar"));
                this->setStatusBar(statusBar);
                /*****************/
                title->setHtml("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
                "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
                "p, li { white-space: pre-wrap; }\n"
                "</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
                "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe Print'; font-size:28pt; color:#aa007f;\">Interface de Gestion de Ressources Humaines</span></p></body></html>");
                /*****************/
                connect_bt->setDefault(true);
                exit->setDefault(false);
                this->setWindowIcon(QIcon("logo.png"));

                QMetaObject::connectSlotsByName(connect_bt);
    this->setFixedSize(700,600);
    this->setWindowTitle("Login");
    this->setStyleSheet("background-color: #EDB228;");
     mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("database.db");
    if(!mydb.open())
        statusBar->showMessage("Failed ");
    else
        statusBar->showMessage("Success");
}

login::~login()
{
    delete (this);
}

void login::on_connect_clicked()
{
    QString username=lineEdit_username->text();
    QString password=lineEdit_password->text();
    if (mydb.isOpen())
                {
                    QSqlQuery qry;
                    if (qry.exec("select * from admin where user='"+username+"'and password='"+password+"'"))
                      { if(qry.next())

                        {
                            accueil *fenetre ;
                            fenetre= new accueil();
                            this->close();
                            if (username != "root")
                            (fenetre->menuGestion_des_administrateurs)->setEnabled(false);
                            fenetre->show();
                        }
                    else
                        {
                            QMessageBox msgBox(QMessageBox::Warning,"Warning","Username or password are false !");
                                    QPalette palette;
                                    palette.setColor(QPalette::Background, QColor("silver"));
                                    msgBox.setPalette(palette);
                                    msgBox.exec();

                        }
                       }

                }

}

void login::on_exit_clicked()
{
    this->close();
}
