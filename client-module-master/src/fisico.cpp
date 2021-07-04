#include "fisico.h"

ostream &operator<<(ostream & output, const Fisico &fisico)
{
  output << "| Cod        | " << fisico.getCod()        << endl
         << "| Logradouro | " << fisico.getLogradouro() << endl
         << "| Setor      | " << fisico.getSetor()      << endl
         << "| Cidade     | " << fisico.getCidade()     << endl
         << "| Estado     | " << fisico.getEstado()     << endl
         << "| Telefone   | " << fisico.getTelefone()   << endl
         << "| Email      | " << fisico.getEmail()      << endl
         << "| Cpf        | " << fisico.cpf             << endl
         << "| Nome       | " << fisico.nome            << endl
         << "| Celular    | " << fisico.celular         << endl;

  return output;
}
Fisico::Fisico( const string& logradouro,
                const string& setor,  const string& cidade,
                const string& estado, const string& telefone,
                const string& email,  const string& cpf,
                const string& nome,   const string&celular)

    : Cliente(logradouro,setor,cidade,estado,telefone,email)
{
    setCpf(cpf);
    setNome(nome);    
    setCelular(celular);
}

Fisico::Fisico(const Fisico & fisico)
  : Cliente(fisico.getLogradouro(),fisico.getSetor(),
    fisico.getCidade(),fisico.getCidade(),
    fisico.getEstado(),fisico.getEmail())
{
    cpf = fisico.cpf;
    nome = fisico.nome;
    celular = fisico.celular;
    setCod(fisico.getCod());
}

Fisico::Fisico(const Cliente & cliente)
  : Cliente(cliente)
{

}

Fisico::~Fisico()
{

}

void Fisico::setCpf(const string& value)
{
    cpf = value;
}
string Fisico::getCpf() const 
{
    return cpf;
}
void Fisico::setNome(const string& value)
{
    nome = value;
}
string Fisico::getNome() const 
{
    return nome;
}
void Fisico::setCelular(const string& value)
{
    celular = value;
}
string Fisico::getCelular() const
{
  return celular;
}
void Fisico::split(string& data)
{
  string str = "";
  for (auto i: data)
  {
  if (isdigit(i)) str += i;
  }
  data = str;
}

int Fisico::quoc(int sum)
{
  sum %= 11;
  return (sum < 2) ? 0: 11-sum;
}

int Fisico::mult(char n1,int n2)
{
  return (n1-'0') * n2;
}

char Fisico::getDigit(string data)
{
  reverse(data.begin(),data.end());
  int sum = 0, count = 2;
  for (auto i: data)
  {
    sum += mult(i,count);
    count++;
  }
  sum = quoc(sum) + '0';
  return sum;
}

bool Fisico::valida(string &cpf)
{
  split(cpf);
  if (cpf.length() != 11)
  {
    return false;
  }
  int checkDigits = stoi(cpf.substr(9,2));
  string str = cpf.substr(0,9);
  str += getDigit(str);
  str += getDigit(str);
  int result = stoi(str.substr(9,2));
  return checkDigits == result;
}
