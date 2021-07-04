#ifndef MATERCLIENTE_H
#define MATERCLIENTE_H

#include <QMainWindow>

#include <QMessageBox>

#include <QRegExpValidator>

#include <QCloseEvent>

#include <fstream>

#include <sstream>

#include <typeinfo>

#include "dll.h"

#include "cliente.h"

#include "fisico.h"

#include "juridico.h"

#include "validacpf.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MaterCliente; }
QT_END_NAMESPACE

class MaterCliente : public QMainWindow
{
  Q_OBJECT

public:
  MaterCliente(QWidget *parent = nullptr);
  ~MaterCliente();
  void CadastrarCliente();
  void ListarCliente();
  void removerCliente();
  void consultarCliente();

private slots:
  void on_btnCadastrar_clicked();

  void on_rbClienteFisico_clicked();

  void on_rbClienteJuridico_clicked();

private:
  Ui::MaterCliente *ui;
  DLL<Cliente*>* dll;
//  QRegExpValidator* validCod;
//  QRegExpValidator* validLogradouro;
//  QRegExpValidator* validSetor;
//  QRegExpValidator* validCidade;
//  QRegExpValidator* validEstado;
//  QRegExpValidator* validTelefone;
//  QRegExpValidator* validEmail;
//  QRegExpValidator* validCpf;
//  QRegExpValidator* validNome;
//  QRegExpValidator* validCelular;
  bool validarCpf(const string&);
  void loadFile(); // Carregar dados do arquivo Cliente.cvs para lista
  void saveFile(); // Salvar dados da lista para o arquivo Cliente.cvs
  void setNumclientes(); // Carrega a quantidade de clientes
  void confirmarCadastro(int, Cliente * );
  void clearLineEdits();
  void setConstraints();
  void closeEvent(QCloseEvent*);
  void setClientMode(bool);
};
#endif // MATERCLIENTE_H
