#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <string>
using namespace std;
class Cliente
{
  friend ostream &operator<<(ostream&, const Cliente&);
  friend istream &operator>>(istream&,Cliente&);
private:
    unsigned int codigo;
    string logradouro;
    string setor;
    string cidade;
    string estado;
    string telefone;
    string email;

protected:
    void setCod(unsigned int);
public:


    static unsigned int numCliente;
    // Default
    Cliente() :codigo(0),logradouro(""),setor(""),
               cidade(""),estado(""),
               telefone(""),email("") { }

    // Parametrizado
    Cliente(const string&,
            const string&, const string&,
            const string&, const string&,
            const string&);

    // Cópia
    Cliente(const Cliente&);

    virtual ~ Cliente() { }

    void setCod();
    unsigned int getCod() const;     
    void   setLogradouro(const string&);
    string getLogradouro() const; 
    void   setSetor(const string&);
    string getSetor() const; 
    void   setCidade(const string&);
    string getCidade() const; 
    void   setEstado(const string&);
    string getEstado() const; 
    void   setTelefone(const string&);
    string getTelefone() const; 
    void   setEmail(const string&);
    string getEmail() const;
    bool   operator==(const Cliente&);
    bool   operator!=(const Cliente&);
    bool   operator>(const  Cliente&);
    bool   operator>=(const Cliente&);
    bool   operator<(const  Cliente&);
    bool   operator<=(const Cliente&);

    virtual bool valida(string&)=0;
};

#endif
