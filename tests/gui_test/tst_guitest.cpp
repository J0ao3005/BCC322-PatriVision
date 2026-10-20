#include <QtTest>
#include <QApplication>
#include "MainWindow.h"
#include "IPatriVisionService.h"

class GuiTest : public QObject {
    Q_OBJECT
private slots:
    void cenariosBDD_Sprint1() {
        // GIVEN: Inspetor abre a interface do PatriVision
        IPatriVisionService* service = IPatriVisionService::createService();
        MainWindow janela(service);
        janela.show();

        // WHEN: Preenche credenciais e clica em ENTRAR
        QTest::keyClicks(janela.editEmail, "inspetor@ufop.edu.br");
        QTest::keyClicks(janela.editSenha, "123456");
        QTest::mouseClick(janela.btnLogin, Qt::LeftButton);

        // THEN: Login validado com sucesso
        QCOMPARE(janela.lblStatusLogin->text(), QString("Autenticado com sucesso!"));

        // WHEN: Aciona captura e inferencia Edge AI
        QTest::mouseClick(janela.btnCapturarIA, Qt::LeftButton);

        // THEN: Vistoria registrada com 94.5% de confianca e homologada pelo Engenheiro
        QCOMPARE(janela.tabelaVistorias->rowCount(), 1);
        QTest::keyClicks(janela.editParecer, "Parecer tecnico aprovado conforme normas IPHAN.");
        QTest::mouseClick(janela.btnHomologarELaudo, Qt::LeftButton);
        QCOMPARE(janela.tabelaVistorias->item(0, 4)->text(), QString("Homologada (Laudo Emitido)"));

        delete service;
    }
};

QTEST_MAIN(GuiTest)
#include "tst_guitest.moc"
