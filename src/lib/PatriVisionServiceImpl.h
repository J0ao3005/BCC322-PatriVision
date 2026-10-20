#ifndef PATRIVISIONSERVICEIMPL_H
#define PATRIVISIONSERVICEIMPL_H

#include "IPatriVisionService.h"

class PatriVisionServiceImpl : public IPatriVisionService {
private:
    QList<IVistoria*> m_vistorias;
    int m_contador;

public:
    PatriVisionServiceImpl();
    virtual ~PatriVisionServiceImpl() override;

    bool autenticarUsuario(const QString& email, const QString& senha) override;
    IVistoria* capturarEExecutarInferencia(const QString& edificacao, const QString& gps) override;
    bool homologarEInserirParecer(const QString& idVistoria, const QString& parecer) override;
    QString exportarLaudoPadronizado(const QString& idVistoria) const override;
    QString exportarGeoJSON() const override;
    QList<IVistoria*> listarVistorias() const override;
};

#endif // PATRIVISIONSERVICEIMPL_H
