#ifndef FISICO_H
#define FISICO_H

#include <iostream>

#include <algorithm>

#include "cliente.h"

using std::string;

class Fisico: public Cliente
{
  friend ostream &operator<<(ostream&, const Fisico&);
//  friend istream &operator>>(istream&,Fisico&);
private:
    string  cpf;
    string  nome;
    string celular;

    void split(string& data);
    int quoc(int sum);
    int mult(char n1,int n2);
    char getDigit(string data);
    bool valid(string data);
    
public:
    Fisico():cpf(""),nome(""),celular("") { }

    Fisico(const string&,
           const string&, const string&,
           const string&, const string&,
           const string&, const string&,
           const string&, const string&);

    Fisico(const Fisico&);
    Fisico(const Cliente&);
    ~Fisico();
    void   setCpf(const string&);
    string getCpf() const;
    void   setNome(const string&);
    string getNome() const;
    void   setCelular(const string&);
    string getCelular() const;
    bool valida(string &) override;


























};

#endif
