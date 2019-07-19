#include "ui_buscar.h"
#include "ui_ui_buscar.h"
#include <QMessageBox>

ui_buscar::ui_buscar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ui_buscar)
{
    ui->setupUi(this);
}

ui_buscar::~ui_buscar()
{
    delete ui;
}
void ui_buscar::cria( std::list<cliente> &clientes, std::list<funcionario> &funcionarios, std::list<administrador> &administradores)
{
    this->clientes = clientes;
    this->funcionarios = funcionarios;
    this->administradores = administradores;
}

void ui_buscar::on_buttonBox_accepted()
{
    QMessageBox me;
    int cod = ui->txtCodigo->text().toInt();
    bool verifica = false;

    switch (ui->cbxOpcoes->currentIndex()) {
    case 1:
    {
        cliente cli("","","",0,0);
        //busca(clientes,cod);
        //typeid(clientes);
        /*typename*/ std::list<cliente>::iterator iterador;

        for( iterador = clientes.begin(); iterador != clientes.end() || verifica == true; iterador++) {
            if(iterador->getCod() == cod){
                cli = *iterador;
                verifica = true;
                me.information(this,"Busca","Cliente encontrado",me.Accepted);
            }
        }
        me.information(this,"Busca","Cliente não encontrado",me.Accepted);

    }break;
    case 2:
    {
        administrador cli("","","","",0);
        std::list<administrador>::iterator iterador;

        for( iterador = administradores.begin(); iterador != administradores.end() || verifica == true; iterador++) {
            if(iterador->getCod() == cod){
                cli = *iterador;
                verifica = true;
                me.information(this,"Busca","Administrador encontrado",me.Accepted);
            }
        }
        me.information(this,"Busca","Administrador não encontrado",me.Accepted);
    }break;
    case 3:
    {
        funcionario cli("","","",0);
        std::list<funcionario>::iterator iterador;

        for( iterador = funcionarios.begin(); iterador != funcionarios.end() || verifica == true; iterador++) {
            if(iterador->getCod() == cod){
                cli = *iterador;
                verifica = true;
                me.information(this,"Busca","Funcionario encontrado",me.Accepted);
            }
        }
        me.information(this,"Busca","Funcionario não encontrado",me.Accepted);
    }break;
    default:
        me.information(this,"Busca","Nenhuma opção selecionada",me.Accepted);
        break;
    }

}
