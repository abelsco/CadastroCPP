#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    /*std::list<funcionario> funcionarios;
    std::list<cliente> clientes;
    std::list<administrador> administradores;*/

    w.show();

    return a.exec();
}
