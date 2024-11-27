# Lista Dinâmica com Redimensionamento Automático

Este trabalho implementa uma lista dinâmica em C++ que suporta redimensionamento automático. A lista começa com uma capacidade inicial de 50 elementos e pode expandir ou reduzir sua capacidade automaticamente, conforme elementos são adicionados ou removidos.

## Histórico de Atualizações

### Versão 1: Implementação inicial
- Criada a estrutura base da lista dinâmica.
- Implementadas as funções para inicializar a lista, adicionar elementos e exibir a lista.

### Versão 2: Adicionada a função de remoção
- Implementada a função para remover o último elemento da lista.
- Adicionados testes básicos para verificar a remoção no programa principal.

### Versão 3: Redimensionamento para redução
- Adicionada lógica para reduzir a capacidade da lista quando o número de elementos cair para 25% da capacidade atual.
- Incluídos testes para verificar o redimensionamento dinâmico.

### Versão 4: Validações e melhorias
- Adicionadas verificações para garantir a integridade da lista (por exemplo, evitar remoção de elementos em uma lista vazia).
- Incluida validação para manter a capacidade mínima de 50 elementos.

### Versão 5: Testes detalhados
- Criado um conjunto de testes no programa principal para verificar o comportamento em cenários variados.
- Testes incluem adição em massa, remoção em massa e redimensionamento automático.

---

## Como o Programa Funciona

### **Inicialização:**
- A lista é criada com uma capacidade inicial de 50.

### **Adição de Elementos (`addElement`):**
- Adiciona novos elementos ao final da lista.
- Redimensiona a lista automaticamente, dobrando sua capacidade quando ela está cheia.

### **Remoção de Elementos (`removeElement`):**
- Retira o último elemento da lista.
- A capacidade diminui para metade se a contagem de elementos restantes for igual ou menor que 25% da capacidade atual (a capacidade mínima que deve ser retida é 50).

### **Validação da Lista (`validateList`):**
- Faz a verificação da integridade da lista, ou seja, uma verificação de que o ponteiro de dados não é NULL e a capacidade nunca é menor que o número de elementos.

### **Impressão da Lista (`printList`):**
- Mostra todos os elementos armazenados e a capacidade atual da lista.

### **Testes (`testAddElements` e `testRemoveElements`):**
- Funções auxiliares para adicionar ou remover múltiplos elementos de uma vez, testando diferentes cenários.

### **Teste de Comportamento no `main()`:**
1. Adiciona 100 elementos e imprime a lista.
2. Remove 80 elementos e verifica a redução de capacidade.
3. Adiciona mais 30 elementos e imprime a lista novamente.
4. Remove todos os elementos restantes e verifica a integridade da lista.

---

## Uso de Memória
- A lista utiliza memória dinâmica (funções `malloc` e `realloc`) para armazenar os elementos, garantindo eficiência no uso de recursos.
- A capacidade nunca é menor que 50, evitando problemas de redimensionamento excessivo.

---




