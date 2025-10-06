# 🌍 Super Trunfo: Desafio Final - Geopolítico em C

Um jogo de cartas baseado no clássico Super Trunfo, onde as cartas são países e os atributos são dados geopolíticos calculados. Este projeto é uma implementação em linguagem C focada em estruturas de dados, funções e lógica de comparação.

---

## ✨ Funcionalidades Principais

O programa permite a comparação de dois países (cartas) com base em seis atributos calculados.

- **Cadastro Dinâmico:** O usuário insere o **Nome**, **População**, **Área** e **PIB** de duas "cartas" (países).
- **Cálculo de Atributos:** O sistema calcula automaticamente:
    - **Densidade Demográfica** (`População / Área`)
    - **PIB per capita** (`PIB / População`)
    - **Super Poder** (Um atributo sintético, ponderando os demais).
- **Modo Desafio:** O usuário escolhe **dois atributos diferentes** para comparação. A soma dos valores de cada carta nos atributos escolhidos define o vencedor final.
- **Regra Especial:** O atributo **Densidade Demográfica** é o único em que **o menor valor vence** (indicando países menos lotados).

---

## 🛠️ Tecnologias Utilizadas

| Tecnologia | Descrição |
| :--- | :--- |
| **C Language** | Linguagem principal de desenvolvimento. |
| **`stdio.h`** | Biblioteca padrão para entrada e saída de dados. |
| **`string.h`** | Manipulação de strings, usada para limpar caracteres. |
| **Structs** | Utilização da estrutura `Carta` para organizar os dados geopolíticos de cada país. |

---

## 🚀 Como Executar

Para compilar e rodar este projeto, você precisará de um compilador C (como GCC, TCC ou o que vem com o MinGW).

1.  **Clone o repositório** (ou navegue até a pasta do projeto):
    ```bash
    git clone [SEU_LINK_DO_REPOSITORIO]
    cd nome-da-pasta
    ```
2.  **Compile o arquivo `superTrunfo.c`** (usando GCC como exemplo):
    ```bash
    gcc superTrunfo.c -o supertrunfo
    ```
3.  **Execute o programa:**
    ```bash
    ./supertrunfo
    ```
4.  Siga as instruções na tela para cadastrar as duas cartas e escolher os atributos para o desafio.

---

## ⚙️ Estrutura do Código

O código é modularizado em funções claras para facilitar a manutenção e leitura:

- `typedef struct Carta`: Define a estrutura da carta com todos os 7 atributos.
- `cadastrarCarta()`: Responsável por coletar a entrada do usuário.
- `calcularAtributos()`: Gera os valores de Densidade, PIB per capita e Super Poder.
- `obterValor()`: Função de *switch* que retorna o valor numérico do atributo escolhido pelo usuário.
- `main()`: Gerencia o fluxo do jogo, a escolha dos atributos e a lógica de comparação para declarar o vencedor.

---

## 👤 Autor

Desenvolvido por **[Bruno Lopes de Oliveira Souza]**

📧 Entre em contato: **[https://www.linkedin.com/in/bruno-lopes-de-oliveira-souza-784764372/]**
