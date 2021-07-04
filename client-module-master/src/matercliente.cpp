#include "matercliente.h"
#include "ui_matercliente.h"

MaterCliente::MaterCliente(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MaterCliente)
{
    ui->setupUi(this);
    dll = new DLL<Cliente*>();
    setConstraints();
    loadFile();
    setNumclientes();
    //  CadastrarCliente();

}

MaterCliente::~MaterCliente()
{
    delete ui;
}

void MaterCliente::CadastrarCliente()
{
    Cliente* cliente = nullptr;
    QString dadosCliente = "";

    string logradouro = ui->leLogradouro->text().toStdString();
    string setor      = ui->leSetor->text().toStdString();
    string cidade     = ui->leCidade->text().toStdString();
    string estado     = ui->leEstado->text().toStdString();
    string telefone   = ui->leTelefone->text().toStdString();
    string email      = ui->leEmail->text().toStdString();

    dadosCliente =  "| Logradouro     | " + ui->leLogradouro->text() + '\n';
    dadosCliente += "| Setor          | " + ui->leSetor->text()      + '\n';
    dadosCliente += "| Cidade         | " + ui->leCidade->text()     + '\n';
    dadosCliente += "| UF             | " + ui->leEstado->text()     + '\n';
    dadosCliente += "| Telefone       | " + ui->leTelefone->text()   + '\n';
    dadosCliente += "| Email          | " + ui->leEmail->text()      + '\n';

    if (ui->rbClienteFisico->isEnabled()) {
        string cpf        = ui->leCpf->text().toStdString();
        string nome       = ui->leNome->text().toStdString();
        string celular    = ui->leCelular->text().toStdString();

        dadosCliente += "| Cpf            | " + QString::fromStdString(cpf)     + '\n';
        dadosCliente += "| Nome           | " + QString::fromStdString(nome)    + '\n';
        dadosCliente += "| Celular        | " + QString::fromStdString(celular) + '\n';

        cliente = new Fisico(logradouro,setor,cidade,estado,telefone,email,cpf,nome,celular);
    }
    else {
        string cnpj        = ui->leCnpj->text().toStdString();
        string razaoSocial = ui->leRazaoSocial->text().toStdString();
        string nomeContato = ui->leNomeContato->text().toStdString();

        dadosCliente += "| Cnpj           | " + QString::fromStdString(cnpj)        + '\n';
        dadosCliente += "| Razao Social   | " + QString::fromStdString(razaoSocial) + '\n';
        dadosCliente += "| Nome Contato   | " + QString::fromStdString(nomeContato) + '\n';

        cliente = new Juridico(logradouro,setor,cidade,estado,telefone,email,cnpj,razaoSocial,nomeContato);
    } cout << "Dados do cliente:\n" << dadosCliente.toStdString() << endl;

    QMessageBox msgBox;
    msgBox.setText("Confirme os dados do cliente.");
    msgBox.setInformativeText(dadosCliente);
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    confirmarCadastro(msgBox.exec(),cliente);
}

void MaterCliente::confirmarCadastro(int opc, Cliente* novoCliente)
{
    QMessageBox msgBox;
    QString msg;
    switch (opc) {
    case QMessageBox::Cancel:  msg = "Operação cancelada!";break;
    default:
        msg = "Cliente cadastrado com sucesso!";
        dll->pushBack(novoCliente);break;
    }

    msgBox.setText(msg);
    msgBox.exec();
    clearLineEdits();
    cout << "Cadastrou cliente: \n";
    dll->show();
}

void MaterCliente::ListarCliente()
{

}

void MaterCliente::removerCliente()
{

}

void MaterCliente::consultarCliente()
{

}

bool MaterCliente::validarCpf(const string & cpf)
{
    return valid(cpf);
}

void MaterCliente::loadFile()
{
    Cliente* cliente = nullptr;
    ifstream clienteFile;
    clienteFile.open("Clientes.csv");

    if (clienteFile.is_open()) { // arquivo foi aberto
        if (!clienteFile.eof()) { // arquivo não está em branco

            string codigo="",logradouro="",setor="",cidade="",estado="";
            string telefone="",email="",cpf="",nome="",celular="";
            string cnpj= "",razaoSocial="",nomeContato="",linha="";
            getline(clienteFile,linha); // RETIRA O NOME DOS CAMPOS

            while (getline(clienteFile,linha)) {
                stringstream ss(linha);
                getline(ss,codigo,',');
                getline(ss,logradouro,',');
                getline(ss,setor, ','  );
                getline(ss,cidade,',');
                getline(ss,estado,',');
                getline(ss,telefone,',');
                getline(ss,email,',');
                getline(ss,cpf,',');
                getline(ss,nome,',');
                getline(ss,celular,',');
                getline(ss,cnpj,',');
                getline(ss,razaoSocial,',');
                getline(ss,nomeContato,',');
                // Insere os dados do arquivo na lista
                if (!cpf.compare("-")) {
                    cliente = new Juridico(logradouro,setor,cidade,estado,telefone,
                                               email,cnpj,razaoSocial,nomeContato);
                }
                dll->pushBack(new Fisico(logradouro,setor,cidade,estado,telefone,
                                                            email,cpf,nome,celular));
                cout << "Load file\n";
                cout << (dll->front());
            }
        }
    }
    else {
        ofstream clienteFile("Clientes.csv"); // Cria um arquivo, caso não exista um
        clienteFile <<  "Código,Logradouro,Setor,Cidade,Estado,Telefone,Email,";
        clienteFile <<  "Cpf,Nome,Celular,";
        clienteFile <<  "Cnpj,Razão Social,Nome Contato" << endl;
    }
    cout << "Depois de Carregar arquivo\n";
    dll->show();
    clienteFile.close();
}

void MaterCliente::saveFile()

{
    cout << "Antes de salvar arquivo\n";
    dll->show();
    ofstream clienteFile;
    setNumclientes();
    clienteFile.open("Clientes.csv");
    clienteFile <<  "Código,Logradouro,Setor,Cidade,Estado,Telefone,Email,";
    clienteFile <<  "Cpf,Nome,Celular,";
    clienteFile <<  "Cnpj,Razão Social,Nome Contato" << endl;
    Cliente* cliente  = nullptr;
    while (!dll->empty()) {
        cout << "Front: \n" << dll->front() << endl;
        cliente = dll->front();
        clienteFile << cliente->getLogradouro() << ',';
        clienteFile << cliente->getSetor()      << ',';
        clienteFile << cliente->getCidade()     << ',';
        clienteFile << cliente->getEstado()     << ',';
        clienteFile << cliente->getTelefone()   << ',';
        clienteFile << cliente->getEmail()      << ',';

        if (typeid (*(cliente)) == typeid (Fisico)) {
            clienteFile << dynamic_cast<Fisico*>(cliente)->getCpf()      << ',';
            clienteFile << dynamic_cast<Fisico*>(cliente)->getNome()     << ',';
            clienteFile << dynamic_cast<Fisico*>(cliente)->getCelular()  << ",";
            clienteFile << "-,-,-" << endl;
        }
        else {
            clienteFile << "-,-,-";
            clienteFile << dynamic_cast<Juridico*>(cliente)->getCnpj()         << ',';
            clienteFile << dynamic_cast<Juridico*>(cliente)->getRazaoSocial()  << ',';
            clienteFile << dynamic_cast<Juridico*>(cliente)->getNomeContato()  << ',' << endl;
        }

        dll->popFront();
    }
    clienteFile.close();
}

void MaterCliente::setNumclientes()
{
    ifstream input;
    ofstream output;
    input.open("numcliente.txt");

    if (input.is_open()) { // Arquivo existe
        unsigned int count =  input.peek() - '0';
        if ( count < Cliente::numCliente) { // Programa está finalizando
            ofstream output("numcliente.txt",ios::out);
            output << Cliente::numCliente;
        }
        else { // Programa está inicializando
            Cliente::numCliente = count;
        }
    }
    else { // Arquivo não exite
        ofstream output("numcliente.txt",ios::out);
        output << 0;
    }

    input.close();
    output.close();
}

void MaterCliente::clearLineEdits()
{
    //  ui->leCodigo->clear();
    ui->leLogradouro->clear();
    ui->leSetor->clear();
    ui->leCidade->clear();
    ui->leEstado->clear();
    ui->leTelefone->clear();
    ui->leEmail->clear();
    if (ui->rbclienteMode->isEnabled()) {
        ui->leCpf->clear();
        ui->leNome->clear();
        ui->leCelular->clear();
    }
    else {
        ui->leCnpj->clear();
        ui->leNomeContato->clear();
        ui->leRazaoSocial->clear();
    }
    ui->leLogradouro->setFocus();
    ui->leLogradouro->setCursorPosition(0);
}
// Pendente
void MaterCliente::setConstraints()
{

    //  QRegExp constraintCod("^(0-9)$");


    //  QRegExp constraintLogradouro("^(0-9a-zA-Z)$");
    //  validLogradouro = new QRegExpValidator(constraintLogradouro,this);
    //  ui->leLogradouro->setValidator(validLogradouro);

    //  QRegExp constraintSetor("^(a-zA-Z)$");
    //  validSetor = new QRegExpValidator(constraintSetor,this);
    //  ui->leSetor->setValidator(validEmail);

    //  QRegExp constraintCidade("^(a-zA-Z)$");
    //  validCidade = new QRegExpValidator(constraintCidade,this);
    //  ui->leCidade->setValidator(validCidade);

    //  QRegExp constraintEstado("^(a-zA-Z)$");
    //  validEstado= new QRegExpValidator(constraintEstado,this);
    //  ui->leEstado->setValidator(validEstado);

    //  QRegExp constraintTelefone("^(0-9)$");
    //  validTelefone = new QRegExpValidator(constraintTelefone,this);
    //  ui->leTelefone->setValidator(validTelefone);

    //  QRegExp constraintEmail("^[a-zA-Z0-9_-]+(?:\\.[a-zA-Z0-9_-]+)*@(?:(\[[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.)|(([a-zA-Z0-9\\-]+\\.)+))([a-zA-Z]{2,4}|[0-9]{1,3})(\\]?)$");
    //  validEmail = new QRegExpValidator(constraintEmail,this);
    //  ui->leEmail->setValidator(validEmail);

    //  QRegExp constraintCpf("^(0-9)$");
    //  validCpf = new QRegExpValidator(constraintCpf,this);
    //  ui->leCpf->setValidator(validCpf);

    //  QRegExp constraintNome("^(a-zA-Z)$");
    //  validNome = new QRegExpValidator(constraintNome,this);
    //  ui->leNome->setValidator(validNome);

    //  QRegExp constraintCelular("^(0-9)$");
    //  validCelular = new QRegExpValidator(constraintCelular,this);
    //  ui->leCelular->setValidator(validCelular);

}

void MaterCliente::closeEvent(QCloseEvent * e)
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Alerta");
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("Deseja encerrar o programa?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);

    if (msgBox.exec() == QMessageBox::Yes) {
        e->accept();
        saveFile();
    }
    else {
        e->ignore();
    }
}

void MaterCliente::setClientMode(bool enable)
{
    ui->leCelular->setEnabled(enable);
    ui->leCpf->setEnabled(enable);
    ui->leNome->setEnabled(enable);

    ui->lblCelular->setEnabled(enable);
    ui->lblCpf->setEnabled(enable);
    ui->lblNome->setEnabled(enable);

    ui->leCnpj->setEnabled(!enable);
    ui->leRazaoSocial->setEnabled(!enable);
    ui->leNomeContato->setEnabled(!enable);

    ui->lblCnpj->setEnabled(!enable);
    ui->lblRazaoSocial->setEnabled(!enable);
    ui->lblNomeContato->setEnabled(!enable);
}

void MaterCliente::on_btnCadastrar_clicked()
{
    CadastrarCliente();

}

void MaterCliente::on_rbClienteFisico_clicked()
{
    setClientMode(true);
}

void MaterCliente::on_rbClienteJuridico_clicked()
{
    setClientMode(false);
}
