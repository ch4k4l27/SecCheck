# SecCheck - Verificador de Segurança

SecCheck é uma ferramenta simples e portátil projetada para ajudar a verificar a segurança básica de sistemas operacionais. Escrita em C, é ideal para desenvolvedores e administradores que desejam identificar rapidamente vulnerabilidades comuns sem depender de ferramentas externas complexas.

## Funcionalidades

1. **Verificação de permissões inseguras**: Identifica arquivos críticos do sistema que possuem permissões inadequadas, ajudando a prevenir acessos não autorizados.
2. **Escaneamento de portas abertas**: Analisa as portas abertas no localhost, identificando possíveis vetores de ataque.
3. **Verificação de variáveis de ambiente sensíveis**: Detecta variáveis de ambiente que podem conter informações confidenciais.
4. **Página de ajuda**: Explica como utilizar a ferramenta de maneira eficiente.

## Instalação

1. Clone este repositório:
   ```bash
   git clone https://github.com/seccheck/seccheck.git
   cd seccheck
   ```

2. Compile o programa:
   ```bash
   gcc main.c help.c permissions.c -o seccheck
   ```

3. Execute o programa:
   ```bash
   ./seccheck
   ```

## Uso

### Comandos básicos

- Exibir a página de ajuda:
  ```bash
  ./seccheck --help
  ```

- Executar todas as verificações:
  ```bash
  ./seccheck
  ```

### Exemplos de saída

**Permissões inseguras encontradas:**
```
[1/3] Verificando permissões inseguras...
⚠️ Permissões inseguras em /etc/passwd: 777 (esperado: 644)
⚠️ Permissões inseguras em /etc/shadow: 644 (esperado: 600)
✅ /etc/hosts: Permissões seguras (644).
```

**Nenhuma porta aberta encontrada:**
```
[2/3] Escaneando portas abertas...
✅ Nenhuma porta aberta encontrada.
```

## Como Contribuir

Contribuições são bem-vindas! Aqui estão algumas formas de ajudar:

1. **Reportar Problemas**:
   - Crie uma [issue](https://github.com/seccheck/seccheck/issues) no GitHub para bugs ou sugestões de melhorias.

2. **Adicionar Funcionalidades**:
   - Fork o repositório.
   - Faça suas alterações em um branch separado:
     ```bash
     git checkout -b nova-funcionalidade
     ```
   - Teste as alterações.
   - Envie um pull request explicando a mudança.

3. **Escrever Documentação**:
   - Melhore este README ou adicione guias detalhados para novos usuários.

## Estrutura do Projeto

- `main.c`: Função principal do programa.
- `help.c`: Página de ajuda e informações sobre o uso.
- `permissions.c`: Implementação da verificação de permissões inseguras.
- `Makefile` (opcional): Facilita o processo de build.

## Licença

Este projeto está licenciado sob a [Licença MIT](LICENSE). Sinta-se à vontade para usá-lo e modificá-lo conforme necessário.

