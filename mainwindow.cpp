#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "geral.h"
#include <fstream>
#include <QMessageBox>
#include "ui_buscar.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_rbtCliente_pressed()
{
    ui->txtNome->setEnabled(true);
    ui->txtEmail->setEnabled(true);
    ui->txtProduto->setEnabled(true);
    ui->txtPreco->setEnabled(true);
    ui->txtCpf->setEnabled(false);
    ui->txtSenha->setEnabled(false);
    ui->cbxFuncionario->setEnabled(false);

}
void MainWindow::showBusca()
{
    ui_buscar *busca = new ui_buscar();
    busca->cria(clientes,funcionarios,administradores);
    busca->show();
}

void MainWindow::on_rbtFuncionario_pressed()
{
    ui->txtNome->setEnabled(true);
    ui->txtEmail->setEnabled(true);
    ui->txtProduto->setEnabled(false);
    ui->txtPreco->setEnabled(false);
    ui->txtCpf->setEnabled(true);
    ui->txtSenha->setEnabled(false);
    ui->cbxFuncionario->setEnabled(true);

}

void MainWindow::on_cbxFuncionario_currentTextChanged(const QString &arg1)
{

    if(arg1.toStdString() == "Administrador"){
        ui->txtSenha->setEnabled(true);
        return;
    }
    ui->txtSenha->setEnabled(false);
}

void MainWindow::imprimirArq(bool)
{
    std::ifstream arq("banco.txt");
    char pegar;
    QString banco;

    while(arq.get(pegar))
        banco.push_back(QChar(pegar));
    ui->txeBanco->setText(banco);
}

void MainWindow::on_buttonBox_accepted()
{
    std::ofstream arq("banco.txt",std::ios::app);
    QString nome,email,produto,cpf,senha;
    double preco = 0 ;

    if(ui->rbtCliente->isChecked())
    {
        if( ui->txtProduto->text().isEmpty() || ui->txtNome->text().isEmpty() || ui->txtEmail->text().isEmpty() || ui->txtPreco->text().isEmpty()){
            QMessageBox me;
            me.information(ui->centralWidget,"ATENCAO","POR FAVOR PREENCHA OS DADOS ANTES DE PROSEGUIR",me.Accepted);
            return;
        }

        nome = ui->txtNome->text();
        email = ui->txtEmail->text();
        produto = ui->txtProduto->text();
        preco = ui->txtPreco->text().toDouble();

        cliente *cli = new cliente(nome.toStdString(),email.toStdString(),produto.toStdString(),clientes.size()+1,preco);
        //clientes.insere(*cli);

        clientes.push_front(*cli);
        cli->cadastro(arq);
        imprimirArq(true);
    }
    else if(ui->rbtFuncionario->isChecked())
    {
        if(ui->cbxFuncionario->currentText() == "Funcionario")
        {
            if(ui->txtCpf->text().isEmpty() || ui->txtNome->text().isEmpty() || ui->txtEmail->text().isEmpty()){
                QMessageBox me;
                me.information(ui->centralWidget,"ATENCAO","POR FAVOR PREENCHA OS DADOS ANTES DE PROSEGUIR",me.Accepted);
                return;
            }
            nome = ui->txtNome->text();
            email = ui->txtEmail->text();
            cpf = ui->txtCpf->text();

            //funcionario *fun = new funcionario(nome.toStdString(),email.toStdString(),cpf.toStdString(),cod);
            funcionario *fun = new funcionario(nome.toStdString(),email.toStdString(),cpf.toStdString(),funcionarios.size()+1);
            //funcionarios.insere(*fun);
            funcionarios.push_back(*fun);
            fun->cadastro(arq);
            imprimirArq(true);
        }
        else if(ui->cbxFuncionario->currentText() == "Administrador")
        {
            if(ui->txtCpf->text().isEmpty() || ui->txtSenha->text().isEmpty() || ui->txtNome->text().isEmpty() || ui->txtEmail->text().isEmpty()){
                QMessageBox me;
                me.information(ui->centralWidget,"ATENCAO","POR FAVOR PREENCHA OS DADOS ANTES DE PROSEGUIR",me.Accepted);
                return;
            }
            nome = ui->txtNome->text();
            email = ui->txtEmail->text();
            cpf = ui->txtCpf->text();
            senha = ui->txtSenha->text();
            administrador *adi = new administrador(nome.toStdString(),email.toStdString(),cpf.toStdString(),senha.toStdString(),administradores.size()+1);
            //administradores.insere(*adi);
            administradores.push_back(*adi);
            adi->cadastro(arq);
            imprimirArq(true);
        }
        else
        {
            QMessageBox me;
            me.information(ui->centralWidget,"ATENCAO","SELECIONE UMA OPCAO",me.Accepted);
        }
    }
    /*ui->txtCpf->setText("");
    ui->txtEmail->setText("");
    ui->txtSenha->setText("");
    ui->txtProduto->setText("");
    ui->txtNome->setText("");
    ui->txtPreco->setText("");*/
}

void MainWindow::on_buttonBox_rejected()
{
    this->close();
}
