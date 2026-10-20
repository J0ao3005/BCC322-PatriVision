#include "VistoriaImpl.h"

VistoriaImpl::VistoriaImpl(const QString& id, const QString& edificacao, const QString& tipo,
                           double confianca, const QString& coords)
    : m_id(id), m_edificacao(edificacao), m_tipoPatologia(tipo),
      m_confianca(confianca), m_coordenadas(coords), m_homologada(false) {}

QString VistoriaImpl::getId() const { return m_id; }
QString VistoriaImpl::getEdificacao() const { return m_edificacao; }
QString VistoriaImpl::getTipoPatologia() const { return m_tipoPatologia; }
double VistoriaImpl::getConfianca() const { return m_confianca; }
QString VistoriaImpl::getCoordenadas() const { return m_coordenadas; }
QString VistoriaImpl::getParecer() const { return m_parecer; }
void VistoriaImpl::setParecer(const QString& parecer) { m_parecer = parecer; }
bool VistoriaImpl::isHomologada() const { return m_homologada; }
void VistoriaImpl::setHomologada(bool status) { m_homologada = status; }
