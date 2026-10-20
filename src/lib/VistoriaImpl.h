#ifndef VISTORIAIMPL_H
#define VISTORIAIMPL_H

#include "IVistoria.h"

class VistoriaImpl : public IVistoria {
private:
    QString m_id;
    QString m_edificacao;
    QString m_tipoPatologia;
    double m_confianca;
    QString m_coordenadas;
    QString m_parecer;
    bool m_homologada;

public:
    VistoriaImpl(const QString& id, const QString& edificacao, const QString& tipo,
                 double confianca, const QString& coords);
    virtual ~VistoriaImpl() override {}

    QString getId() const override;
    QString getEdificacao() const override;
    QString getTipoPatologia() const override;
    double getConfianca() const override;
    QString getCoordenadas() const override;
    QString getParecer() const override;
    void setParecer(const QString& parecer) override;
    bool isHomologada() const override;
    void setHomologada(bool status) override;
};

#endif // VISTORIAIMPL_H
