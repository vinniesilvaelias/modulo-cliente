/********************************************************************************
** Form generated from reading UI file 'matercliente.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATERCLIENTE_H
#define UI_MATERCLIENTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MaterCliente
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tabCadastrar;
    QGridLayout *gridLayout_2;
    QHBoxLayout *rbclienteMode;
    QRadioButton *rbClienteFisico;
    QRadioButton *rbClienteJuridico;
    QHBoxLayout *dados;
    QVBoxLayout *lDados;
    QLabel *lblLogradouro;
    QLabel *lblSetor;
    QLabel *lblCidade;
    QLabel *lblEstado;
    QLabel *lblTelefone;
    QLabel *lblEmail;
    QLabel *lblCpf;
    QLabel *lblNome;
    QLabel *lblCelular;
    QLabel *lblCnpj;
    QLabel *lblRazaoSocial;
    QLabel *lblNomeContato;
    QVBoxLayout *leDados;
    QLineEdit *leLogradouro;
    QLineEdit *leSetor;
    QLineEdit *leCidade;
    QLineEdit *leEstado;
    QLineEdit *leTelefone;
    QLineEdit *leEmail;
    QLineEdit *leCpf;
    QLineEdit *leNome;
    QLineEdit *leCelular;
    QLineEdit *leCnpj;
    QLineEdit *leRazaoSocial;
    QLineEdit *leNomeContato;
    QPushButton *btnCadastrar;
    QWidget *tabConsultar;
    QWidget *tabListar;
    QWidget *tabRemover;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MaterCliente)
    {
        if (MaterCliente->objectName().isEmpty())
            MaterCliente->setObjectName(QString::fromUtf8("MaterCliente"));
        MaterCliente->resize(800, 600);
        centralwidget = new QWidget(MaterCliente);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabCadastrar = new QWidget();
        tabCadastrar->setObjectName(QString::fromUtf8("tabCadastrar"));
        gridLayout_2 = new QGridLayout(tabCadastrar);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        rbclienteMode = new QHBoxLayout();
        rbclienteMode->setObjectName(QString::fromUtf8("rbclienteMode"));
        rbClienteFisico = new QRadioButton(tabCadastrar);
        rbClienteFisico->setObjectName(QString::fromUtf8("rbClienteFisico"));

        rbclienteMode->addWidget(rbClienteFisico);

        rbClienteJuridico = new QRadioButton(tabCadastrar);
        rbClienteJuridico->setObjectName(QString::fromUtf8("rbClienteJuridico"));

        rbclienteMode->addWidget(rbClienteJuridico);


        gridLayout_2->addLayout(rbclienteMode, 0, 0, 1, 1);

        dados = new QHBoxLayout();
        dados->setObjectName(QString::fromUtf8("dados"));
        lDados = new QVBoxLayout();
        lDados->setObjectName(QString::fromUtf8("lDados"));
        lblLogradouro = new QLabel(tabCadastrar);
        lblLogradouro->setObjectName(QString::fromUtf8("lblLogradouro"));

        lDados->addWidget(lblLogradouro);

        lblSetor = new QLabel(tabCadastrar);
        lblSetor->setObjectName(QString::fromUtf8("lblSetor"));

        lDados->addWidget(lblSetor);

        lblCidade = new QLabel(tabCadastrar);
        lblCidade->setObjectName(QString::fromUtf8("lblCidade"));

        lDados->addWidget(lblCidade);

        lblEstado = new QLabel(tabCadastrar);
        lblEstado->setObjectName(QString::fromUtf8("lblEstado"));

        lDados->addWidget(lblEstado);

        lblTelefone = new QLabel(tabCadastrar);
        lblTelefone->setObjectName(QString::fromUtf8("lblTelefone"));

        lDados->addWidget(lblTelefone);

        lblEmail = new QLabel(tabCadastrar);
        lblEmail->setObjectName(QString::fromUtf8("lblEmail"));

        lDados->addWidget(lblEmail);

        lblCpf = new QLabel(tabCadastrar);
        lblCpf->setObjectName(QString::fromUtf8("lblCpf"));
        lblCpf->setEnabled(false);

        lDados->addWidget(lblCpf);

        lblNome = new QLabel(tabCadastrar);
        lblNome->setObjectName(QString::fromUtf8("lblNome"));
        lblNome->setEnabled(false);

        lDados->addWidget(lblNome);

        lblCelular = new QLabel(tabCadastrar);
        lblCelular->setObjectName(QString::fromUtf8("lblCelular"));
        lblCelular->setEnabled(false);

        lDados->addWidget(lblCelular);

        lblCnpj = new QLabel(tabCadastrar);
        lblCnpj->setObjectName(QString::fromUtf8("lblCnpj"));
        lblCnpj->setEnabled(false);

        lDados->addWidget(lblCnpj);

        lblRazaoSocial = new QLabel(tabCadastrar);
        lblRazaoSocial->setObjectName(QString::fromUtf8("lblRazaoSocial"));
        lblRazaoSocial->setEnabled(false);

        lDados->addWidget(lblRazaoSocial);

        lblNomeContato = new QLabel(tabCadastrar);
        lblNomeContato->setObjectName(QString::fromUtf8("lblNomeContato"));
        lblNomeContato->setEnabled(false);

        lDados->addWidget(lblNomeContato);


        dados->addLayout(lDados);

        leDados = new QVBoxLayout();
        leDados->setObjectName(QString::fromUtf8("leDados"));
        leLogradouro = new QLineEdit(tabCadastrar);
        leLogradouro->setObjectName(QString::fromUtf8("leLogradouro"));

        leDados->addWidget(leLogradouro);

        leSetor = new QLineEdit(tabCadastrar);
        leSetor->setObjectName(QString::fromUtf8("leSetor"));

        leDados->addWidget(leSetor);

        leCidade = new QLineEdit(tabCadastrar);
        leCidade->setObjectName(QString::fromUtf8("leCidade"));

        leDados->addWidget(leCidade);

        leEstado = new QLineEdit(tabCadastrar);
        leEstado->setObjectName(QString::fromUtf8("leEstado"));

        leDados->addWidget(leEstado);

        leTelefone = new QLineEdit(tabCadastrar);
        leTelefone->setObjectName(QString::fromUtf8("leTelefone"));

        leDados->addWidget(leTelefone);

        leEmail = new QLineEdit(tabCadastrar);
        leEmail->setObjectName(QString::fromUtf8("leEmail"));

        leDados->addWidget(leEmail);

        leCpf = new QLineEdit(tabCadastrar);
        leCpf->setObjectName(QString::fromUtf8("leCpf"));
        leCpf->setEnabled(false);

        leDados->addWidget(leCpf);

        leNome = new QLineEdit(tabCadastrar);
        leNome->setObjectName(QString::fromUtf8("leNome"));
        leNome->setEnabled(false);

        leDados->addWidget(leNome);

        leCelular = new QLineEdit(tabCadastrar);
        leCelular->setObjectName(QString::fromUtf8("leCelular"));
        leCelular->setEnabled(false);

        leDados->addWidget(leCelular);

        leCnpj = new QLineEdit(tabCadastrar);
        leCnpj->setObjectName(QString::fromUtf8("leCnpj"));
        leCnpj->setEnabled(false);

        leDados->addWidget(leCnpj);

        leRazaoSocial = new QLineEdit(tabCadastrar);
        leRazaoSocial->setObjectName(QString::fromUtf8("leRazaoSocial"));
        leRazaoSocial->setEnabled(false);

        leDados->addWidget(leRazaoSocial);

        leNomeContato = new QLineEdit(tabCadastrar);
        leNomeContato->setObjectName(QString::fromUtf8("leNomeContato"));
        leNomeContato->setEnabled(false);

        leDados->addWidget(leNomeContato);


        dados->addLayout(leDados);


        gridLayout_2->addLayout(dados, 1, 0, 1, 1);

        btnCadastrar = new QPushButton(tabCadastrar);
        btnCadastrar->setObjectName(QString::fromUtf8("btnCadastrar"));

        gridLayout_2->addWidget(btnCadastrar, 2, 0, 1, 1);

        tabWidget->addTab(tabCadastrar, QString());
        tabConsultar = new QWidget();
        tabConsultar->setObjectName(QString::fromUtf8("tabConsultar"));
        tabWidget->addTab(tabConsultar, QString());
        tabListar = new QWidget();
        tabListar->setObjectName(QString::fromUtf8("tabListar"));
        tabWidget->addTab(tabListar, QString());
        tabRemover = new QWidget();
        tabRemover->setObjectName(QString::fromUtf8("tabRemover"));
        tabWidget->addTab(tabRemover, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MaterCliente->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MaterCliente);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MaterCliente->setMenuBar(menubar);
        statusbar = new QStatusBar(MaterCliente);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MaterCliente->setStatusBar(statusbar);

        retranslateUi(MaterCliente);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MaterCliente);
    } // setupUi

    void retranslateUi(QMainWindow *MaterCliente)
    {
        MaterCliente->setWindowTitle(QCoreApplication::translate("MaterCliente", "MaterCliente", nullptr));
        rbClienteFisico->setText(QCoreApplication::translate("MaterCliente", "Cliente F\303\255sico", nullptr));
        rbClienteJuridico->setText(QCoreApplication::translate("MaterCliente", "Cliente Jur\303\255dico", nullptr));
        lblLogradouro->setText(QCoreApplication::translate("MaterCliente", "Logradouro", nullptr));
        lblSetor->setText(QCoreApplication::translate("MaterCliente", "Setor", nullptr));
        lblCidade->setText(QCoreApplication::translate("MaterCliente", "Cidade", nullptr));
        lblEstado->setText(QCoreApplication::translate("MaterCliente", "Estado", nullptr));
        lblTelefone->setText(QCoreApplication::translate("MaterCliente", "Telefone", nullptr));
        lblEmail->setText(QCoreApplication::translate("MaterCliente", "Email", nullptr));
        lblCpf->setText(QCoreApplication::translate("MaterCliente", "Cpf", nullptr));
        lblNome->setText(QCoreApplication::translate("MaterCliente", "Nome", nullptr));
        lblCelular->setText(QCoreApplication::translate("MaterCliente", "Celular", nullptr));
        lblCnpj->setText(QCoreApplication::translate("MaterCliente", "Cnpj", nullptr));
        lblRazaoSocial->setText(QCoreApplication::translate("MaterCliente", "Raz\303\243o Social", nullptr));
        lblNomeContato->setText(QCoreApplication::translate("MaterCliente", "Nome Contato", nullptr));
        leLogradouro->setText(QString());
        leSetor->setText(QString());
        leCidade->setText(QString());
        leEstado->setText(QString());
        leTelefone->setText(QString());
        leEmail->setText(QString());
        leCpf->setText(QString());
        leNome->setText(QString());
        btnCadastrar->setText(QCoreApplication::translate("MaterCliente", "Cadastrar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabCadastrar), QCoreApplication::translate("MaterCliente", "Cadastrar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabConsultar), QCoreApplication::translate("MaterCliente", "Consultar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabListar), QCoreApplication::translate("MaterCliente", "Listar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabRemover), QCoreApplication::translate("MaterCliente", "Remover", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MaterCliente: public Ui_MaterCliente {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATERCLIENTE_H
