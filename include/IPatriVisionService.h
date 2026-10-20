/**
 * @file IPatriVisionService.h
 * @brief Interface pura dos servicos do PatriVision e Factory Method.
 */
#ifndef IPATRIVISIONSERVICE_H
#define IPATRIVISIONSERVICE_H

#include "IVistoria.h"
#include <QList>
#include <QString>

class IPatriVisionService {
public:
    virtual ~IPatriVisionService() {}

    virtual bool autenticarUsuario(const QString& email, const QString& senha) = 0;
    virtual IVistoria* capturarEExecutarInferencia(const QString& edificacao, const QString& gps) = 0;
    virtual bool homologarEInserirParecer(const QString& idVistoria, const QString& parecer) = 0;
    virtual QString exportarLaudoPadronizado(const QString& idVistoria) const = 0;
    virtual QString exportarGeoJSON() const = 0;
    virtual QList<IVistoria*> listarVistorias() const = 0;

    static IPatriVisionService* createService();
};

#endif // IPATRIVISIONSERVICE_H