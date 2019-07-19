#ifndef UI_BUSCAR_H
#define UI_BUSCAR_H
#include "geral.h"

#include <QDialog>

namespace Ui {
class ui_buscar;
}

class ui_buscar : public QDialog
{
    Q_OBJECT

public:
    explicit ui_buscar(QWidget *parent = 0);
    ~ui_buscar();
    std::list<cliente> clientes;
    std::list<funcionario> funcionarios;
    std::list<administrador> administradores;
    void cria( std::list<cliente> &clientes, std::list<funcionario> &funcionarios, std::list<administrador> &administradores);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ui_buscar *ui;
};

#endif // UI_BUSCAR_H
