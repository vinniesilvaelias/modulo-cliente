#include "cliente.h"

unsigned int Cliente::numCliente = 0;

ostream &operator<<(ostream & output, const Cliente &client)
{
  output << "| Cod        | " << client.codigo     << endl
         << "| Logradouro | " << client.logradouro << endl
         << "| Setor      | " << client.setor      << endl
         << "| Cidade     | " << client.cidade     << endl
         << "| Estado     | " << client.estado     << endl
         << "| Telefone   | " << client.telefone   << endl
         << "| Email      | " << client.email      << endl;

  return output;
}

istream &operator>>(istream & input, Cliente &client)
{
  cin.ignore();
  getline(input,client.logradouro);
  getline(input,client.setor);
  getline(input,client.cidade);
  getline(input,client.estado);
  getline(input,client.telefone);
  getline(input,client.email);
  return input;
}

void Cliente::setCod(unsigned int value)
{
  codigo = value;
}

Cliente::Cliente(const string& logradouro, const string& setor,
                 const string& cidade,const string& estado,
                 const string& telefone,const string& email)
{
  setCod();
  setLogradouro(logradouro);
  setSetor(setor);
  setCidade(cidade);
  setEstado(estado);
  setTelefone(telefone);
  setEmail(email);
}

Cliente::Cliente(const Cliente & cliente)
{
    codigo = cliente.codigo;
    logradouro = cliente.logradouro;
    setor = cliente.setor;
    cidade = cliente.cidade;
    estado = cliente.estado;
    telefone = cliente.telefone;
    email = cliente.email;
}


void Cliente::setCod()
{
    codigo = ++numCliente;
}

unsigned int Cliente::getCod() const
{
    return codigo;
}

void Cliente::setLogradouro(const string& value)
{
    logradouro = value;
}

string Cliente::getLogradouro() const
{
    return logradouro;
}

void Cliente::setSetor(const string& value)
{
    setor = value;
}

string Cliente::getSetor() const
{
    return setor;
}

void Cliente::setCidade(const string& value)
{
    cidade = value;
}

string Cliente::getCidade() const
{
    return cidade;
}

void Cliente::setEstado(const string& value)
{
    estado = value;
}

string Cliente::getEstado() const
{
    return estado;
}

void Cliente::setTelefone(const string& value)
{
    telefone = value;    
}

string Cliente::getTelefone() const
{
    return telefone;
}

void Cliente::setEmail(const string& value)
{ 
 // validar a existencia de .com e @
//    bool valid = value.find('@',0);
    email = value;
}

string Cliente::getEmail() const
{
    return email;
}

bool Cliente::operator==(const Cliente& value)
{
    return codigo == value.codigo;
}

bool Cliente::operator!=(const Cliente& value)
{
    return ! (codigo == value.codigo);
}

bool Cliente::operator>(const Cliente& value)
{
    return codigo >  value.codigo;
}

bool Cliente::operator>=(const Cliente& value)
{
    return !(codigo < value.codigo);
}

bool Cliente::operator<(const Cliente& value)
{
    return codigo <  value.codigo;
}

bool Cliente::operator<=(const Cliente& value)
{
    return !(codigo > value.codigo);
}
