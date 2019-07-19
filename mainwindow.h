#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "geral.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    std::list<funcionario> funcionarios;
    std::list<cliente> clientes;
    std::list<administrador> administradores;

private slots:

    void on_rbtCliente_pressed();

    void on_rbtFuncionario_pressed();

    void on_cbxFuncionario_currentTextChanged(const QString &arg1);

    void on_buttonBox_accepted();

    void imprimirArq(bool);

    void on_buttonBox_rejected();

private:
    Ui::MainWindow *ui;
public slots:
    void showBusca();
};


#endif // MAINWINDOW_H
