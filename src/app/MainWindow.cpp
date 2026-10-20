#include "MainWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QHeaderView>

MainWindow::MainWindow(IPatriVisionService* service, QWidget *parent)
    : QMainWindow(parent), m_service(service) {
    setWindowTitle("PatriVision - Inspecao Patrimonial IA (Sprint 1)");
    resize(820, 520);

    m_stack = new QStackedWidget(this);
    setCentralWidget(m_stack);

    QWidget* pageLogin = new QWidget();
    QVBoxLayout* layoutLogin = new QVBoxLayout(pageLogin);
    editEmail = new QLineEdit();
    editEmail->setPlaceholderText("E-mail:");
    editSenha = new QLineEdit();
    editSenha->setPlaceholderText("Senha:");
    editSenha->setEchoMode(QLineEdit::Password);
    btnLogin = new QPushButton("ENTRAR");
    lblStatusLogin = new QLabel("Aguardando autenticacao...");

    layoutLogin->addWidget(new QLabel("<h2>PatriVision - Login</h2>"));
    layoutLogin->addWidget(editEmail);
    layoutLogin->addWidget(editSenha);
    layoutLogin->addWidget(btnLogin);
    layoutLogin->addWidget(lblStatusLogin);
    m_stack->addWidget(pageLogin);

    QWidget* pageMain = new QWidget();
    QVBoxLayout* layoutMain = new QVBoxLayout(pageMain);

    QGroupBox* boxCaptura = new QGroupBox("Captura, Inferencia (Edge AI) e GPS");
    QHBoxLayout* layoutCap = new QHBoxLayout(boxCaptura);
    editEdificacao = new QLineEdit("Igreja Matriz");
    editGps = new QLineEdit("-20.3856, -43.5032, 1150.5m");
    btnCapturarIA = new QPushButton("Capturar Foto e Executar Deteccao (Edge AI)");
    layoutCap->addWidget(editEdificacao);
    layoutCap->addWidget(editGps);
    layoutCap->addWidget(btnCapturarIA);

    tabelaVistorias = new QTableWidget(0, 5);
    tabelaVistorias->setHorizontalHeaderLabels({"ID", "Edificacao", "Patologia", "Confianca", "Status"});
    tabelaVistorias->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QGroupBox* boxLaudo = new QGroupBox("Homologacao e Emissao de Laudo Tecnico");
    QVBoxLayout* layoutLaudo = new QVBoxLayout(boxLaudo);
    editParecer = new QTextEdit();
    btnHomologarELaudo = new QPushButton("Homologar Vistoria e Exportar Laudo (PDF / GeoJSON)");
    lblStatusGeral = new QLabel("Pronto.");
    layoutLaudo->addWidget(editParecer);
    layoutLaudo->addWidget(btnHomologarELaudo);
    layoutLaudo->addWidget(lblStatusGeral);

    layoutMain->addWidget(boxCaptura);
    layoutMain->addWidget(tabelaVistorias);
    layoutMain->addWidget(boxLaudo);
    m_stack->addWidget(pageMain);

    connect(btnLogin, &QPushButton::clicked, this, &MainWindow::onLoginClicked);
    connect(btnCapturarIA, &QPushButton::clicked, this, &MainWindow::onCapturarClicked);
    connect(btnHomologarELaudo, &QPushButton::clicked, this, &MainWindow::onHomologarClicked);
}

MainWindow::~MainWindow() {}

void MainWindow::onLoginClicked() {
    if (m_service->autenticarUsuario(editEmail->text(), editSenha->text())) {
        lblStatusLogin->setText("Autenticado com sucesso!");
        m_stack->setCurrentIndex(1);
    } else {
        lblStatusLogin->setText("Erro: Credenciais invalidas.");
    }
}

void MainWindow::onCapturarClicked() {
    IVistoria* v = m_service->capturarEExecutarInferencia(editEdificacao->text(), editGps->text());
    int row = tabelaVistorias->rowCount();
    tabelaVistorias->insertRow(row);
    tabelaVistorias->setItem(row, 0, new QTableWidgetItem(v->getId()));
    tabelaVistorias->setItem(row, 1, new QTableWidgetItem(v->getEdificacao()));
    tabelaVistorias->setItem(row, 2, new QTableWidgetItem(v->getTipoPatologia()));
    tabelaVistorias->setItem(row, 3, new QTableWidgetItem(QString::number(v->getConfianca()) + "%"));
    tabelaVistorias->setItem(row, 4, new QTableWidgetItem("Pendente"));
    lblStatusGeral->setText("Bounding Box [Fissura 94.5%] registrada!");
}

void MainWindow::onHomologarClicked() {
    if (tabelaVistorias->rowCount() == 0) return;
    int row = tabelaVistorias->rowCount() - 1;
    QString id = tabelaVistorias->item(row, 0)->text();
    if (m_service->homologarEInserirParecer(id, editParecer->toPlainText())) {
        tabelaVistorias->item(row, 4)->setText("Homologada (Laudo Emitido)");
        lblStatusGeral->setText("Laudo PDF e GeoJSON exportados para " + id);
    }
}
