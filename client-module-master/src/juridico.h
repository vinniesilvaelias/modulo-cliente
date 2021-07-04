#ifndef JURIDICO_H
#define JURIDICO_H

#include <string>

#include "cliente.h"

using std::string;

class Juridico: public Cliente
{
  friend ostream &operator<<(ostream&, const Juridico&);
private:
    string cnpj;
    string razaoSocial;
    string nomeContato;
public:
    Juridico():cnpj(""),razaoSocial(""),nomeContato("") { }
                
    Juridico(const string&,
             const string&, const string&,
             const string&, const string&,
             const string&, const string&,
             const string&, const string&);

    Juridico(const Juridico&);
    Juridico(const Cliente&);
    ~Juridico();
    void setCnpj(const string&);
    string getCnpj() const;
    void setRazaoSocial(const string&);
    string getRazaoSocial() const;
    void setNomeContato(const string&);
    string getNomeContato() const;
    bool valida(string &) override;
};
#endif
