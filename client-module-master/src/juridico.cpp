#include "juridico.h"


ostream &operator<<(ostream & output, const Juridico &juridico)
{
  output << "| Cod                | " << juridico.getCod()        << endl
         << "| Logradouro         | " << juridico.getLogradouro() << endl
         << "| Setor              | " << juridico.getSetor()      << endl
         << "| Cidade             | " << juridico.getCidade()     << endl
         << "| Estado             | " << juridico.getEstado()     << endl
         << "| Telefone           | " << juridico.getTelefone()   << endl
         << "| Email              | " << juridico.getEmail()      << endl
         << "| Cnpj               | " << juridico.cnpj            << endl
         << "| Razao Social       | " << juridico.razaoSocial     << endl
         << "| Nome Contato       | " << juridico.nomeContato     << endl;

  return output;
}

Juridico::Juridico(const string& logradouro,
                   const string& setor,  const string& cidade,
                   const string& estado, const string& telefone,
                   const string& email,  const string& cnpj,
                   const string& razaoSocial,const string&nomeContato)
    : Cliente(logradouro,setor,cidade,estado,telefone,email)
{
    setCnpj(cnpj);
    setRazaoSocial(razaoSocial);
    setNomeContato(nomeContato);
}

Juridico::Juridico(const Juridico &juridico)
  : Cliente(juridico.getLogradouro(),juridico.getSetor(),
            juridico.getCidade(),juridico.getCidade(),
            juridico.getEstado(),juridico.getEmail())
{
  cnpj = juridico.cnpj;
  razaoSocial = juridico.razaoSocial;
  nomeContato = juridico.nomeContato;
}

Juridico::Juridico(const Cliente &cliente)
  :Cliente(cliente)
{

}

Juridico::~Juridico()
{

}

void Juridico::setCnpj(const string& value)
{
    cnpj = value;
}

string Juridico::getCnpj() const
{
    return cnpj;
}

void Juridico::setRazaoSocial(const string& value)
{
    razaoSocial = value;
}

string Juridico::getRazaoSocial() const
{
    return razaoSocial;
}

void Juridico::setNomeContato(const string& value)
{
    nomeContato = value;
}

string Juridico::getNomeContato() const
{
  return nomeContato;
}

bool Juridico::valida(string &)
{
  return true;
}
