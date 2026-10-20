/**
 * @file IVistoria.h
 * @brief Interface pura da entidade Vistoria do sistema PatriVision.
 */
#ifndef IVISTORIA_H
#define IVISTORIA_H

#include <QString>

class IVistoria {
public:
    virtual ~IVistoria() {}
    virtual QString getId() const = 0;
    virtual QString getEdificacao() const = 0;
    virtual QString getTipoPatologia() const = 0;
    virtual double getConfianca() const = 0;
    virtual QString getCoordenadas() const = 0;
    virtual QString getParecer() const = 0;
    virtual void setParecer(const QString& parecer) = 0;
    virtual bool isHomologada() const = 0;
    virtual void setHomologada(bool status) = 0;
};

#endif // IVISTORIA_H
