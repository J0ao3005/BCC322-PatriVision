# PatriVision - BCC322 (Engenharia de Software I)
Sistema de Detecção Automatizada de Patologias em Edificações Históricas (Sprint 1).

## Estrutura Arquitetural (Qt / C++)
- `include/`: Interfaces puras (classes abstratas) desacopladas.
- `src/lib/`: Implementação concreta dos serviços compilada como biblioteca dinâmica (DLL / .so).
- `src/app/`: Camada de Interface Gráfica do Usuário (GUI em Qt Widgets).
- `tests/gui_test/`: Testes automatizados de interface gráfica com `QtTest` (BDD).
- `Doxyfile`: Configuração para geração de documentação automatizada via Doxygen.
