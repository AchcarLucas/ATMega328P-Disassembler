# ATMega328P-Disassembler

Um disassembler simples para o conjunto de instruções AVR do ATMega328P, escrito em C++.

## O que ele faz

- Lê arquivos Intel HEX (`.hex`) gerados para o ATMega328P
- Identifica opcodes de 16 e 32 bits
- Traduz cada instrução para assembly AVR legível
- Inclui um conjunto de testes internos para validar instruções chave

## Por que este projeto

Este projeto é útil para:
- Aprender a estrutura de opcodes AVR
- Validar decodificação de instruções do ATMega328P
- Estudar o funcionamento de um desassemblador simples em C++

## Estrutura do repositório

- `src/`
  - `main.cpp` — fluxo principal de leitura, teste e desassemblagem
  - `readhex.cpp` — parser de arquivo Intel HEX
- `headers/`
  - `instructions.h` — implementa a decodificação `E_*` e a busca de instruções
  - `init.h` — cadastro de máscaras, verificadores e handlers de instrução
  - `opcode.h` — definições de máscaras e macros de opcode AVR
  - `test.h` — testes unitários para instruções
- `test_file/` — exemplos de HEX gerados a partir de sketches Arduino
- `docs/` — documentos de referência usados durante o desenvolvimento
- `ATMega328P-Disassembler.cbp` — projeto Code::Blocks opcional

## Como compilar

A forma mais direta é com `g++`:

```bash
cd /home/achcarlucas/Documentos/Documentos\ -\ Lucas/GitHub/ATMega328P-Disassembler
g++ -I headers src/main.cpp src/readhex.cpp -o disassembler
```

> Observação: o projeto também inclui um arquivo de configuração do Code::Blocks se preferir usar essa IDE.

## Como executar

Basta rodar:

```bash
./disassembler
```

O binário, por padrão, lê o arquivo `test_file/blink/build/blink.hex`.

Se quiser testar outro arquivo, altere a linha correspondente em `src/main.cpp`:

```cpp
// bin = readHexFile("test_file/empty/build/empty.hex");
```

## Recursos implementados

- Suporte a instruções AVR `16-bit` e `32-bit`
- Handler `E_*` para cada opcode válido
- Saída textual no formato de assembly
- Testes automáticos que mostram `PASSED` para cada opcode verificado

## Notas técnicas

- O parse de HEX é feito em `headers/readhex.h` / `src/readhex.cpp`
- A decodificação usa `std::bitset` para manipular bits do opcode
- Os handlers produzem a string de assembly em `inst::mnemonic_assembly`
- A lógica de busca de instruções está em `headers/instructions.h`

## Licença

Licenciado sob a GNU GPL v3.

## Referências

- ATMega328P Datasheet
- AVR Instruction Set Manual
- Intel HEX format

