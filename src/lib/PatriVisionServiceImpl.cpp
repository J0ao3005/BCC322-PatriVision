#include "PatriVisionServiceImpl.h"
#include "VistoriaImpl.h"

PatriVisionServiceImpl::PatriVisionServiceImpl() : m_contador(1) {}

PatriVisionServiceImpl::~PatriVisionServiceImpl() {
    qDeleteAll(m_vistorias);
}

bool PatriVisionServiceImpl::autenticarUsuario(const QString& email, const QString& senha) {
    return (!email.trimmed().isEmpty() && senha.length() >= 4);
}

IVistoria* PatriVisionServiceImpl::capturarEExecutarInferencia(const QString& edificacao, const QString& gps) {
    QString id = QString("PAT20261008-0%1").arg(m_contador++);
    IVistoria* nova = new VistoriaImpl(id, edificacao, "Fissura", 94.5, gps);
    m_vistorias.append(nova);
    return nova;
}

bool PatriVisionServiceImpl::homologarEInserirParecer(const QString& idVistoria, const QString& parecer) {
    for (IVistoria* v : m_vistorias) {
        if (v->getId() == idVistoria) {
            v->setParecer(parecer);
            v->setHomologada(true);
            return true;
        }
    }
    return false;
}

QString PatriVisionServiceImpl::exportarLaudoPadronizado(const QString& idVistoria) const {
    for (IVistoria* v : m_vistorias) {
        if (v->getId() == idVistoria) {
            return QString("LAUDO PDF | ID: %1 | Bem: %2 | Parecer: %3")
                .arg(v->getId(), v->getEdificacao(), v->getParecer());
        }
    }
    return QString();
}

QString PatriVisionServiceImpl::exportarGeoJSON() const {
    return QString("{ \"type\": \"FeatureCollection\", \"totalFeatures\": %1 }").arg(m_vistorias.size());
}

QList<IVistoria*> PatriVisionServiceImpl::listarVistorias() const {
    return m_vistorias;
}

IPatriVisionService* IPatriVisionService::createService() {
    return new PatriVisionServiceImpl();
}
