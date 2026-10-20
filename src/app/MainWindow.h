#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>
#include <QTextEdit>
#include <QLabel>
#include <QStackedWidget>
#include "IPatriVisionService.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(IPatriVisionService* service, QWidget *parent = nullptr);
    ~MainWindow();

    QLineEdit* editEmail;
    QLineEdit* editSenha;
    QPushButton* btnLogin;
    QLabel* lblStatusLogin;

    QLineEdit* editEdificacao;
    QLineEdit* editGps;
    QPushButton* btnCapturarIA;
    QTableWidget* tabelaVistorias;

    QTextEdit* editParecer;
    QPushButton* btnHomologarELaudo;
    QLabel* lblStatusGeral;

private slots:
    void onLoginClicked();
    void onCapturarClicked();
    void onHomologarClicked();

private:
    IPatriVisionService* m_service;
    QStackedWidget* m_stack;
};

#endif // MAINWINDOW_H
