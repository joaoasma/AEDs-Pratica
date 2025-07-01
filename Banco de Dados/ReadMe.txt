============================================================
               PROJETO: SISTEMA DE IMÓVEIS
============================================================

Descrição:
-----------
Este projeto em C++ é um sistema de cadastro e consulta de imóveis.  
O sistema permite carregar uma base de dados de imóveis de um arquivo de texto e manipulá-la durante a execução.

Todos os dados são carregados no início da execução e, ao final, são **salvos novamente no mesmo arquivo**, atualizados com inclusões e exclusões feitas durante o uso.

Arquivo de dados:
------------------
O arquivo de entrada deve se chamar **BD_Imoveis2.txt** e deve estar na **mesma pasta que o executável**.  
A primeira linha deve ser ignorada (cabeçalho) e a última linha deve conter a palavra "fim", indicando o fim do conteúdo válido.

Cada linha representa um imóvel com **22 atributos separados por espaço**, como nos exemplos fornecidos no próprio arquivo.

Funcionalidades disponíveis:
----------------------------
> Incluir novo imóvel manualmente pelo usuário  
> Buscar imóvel pela rua (com opção de exclusão do mesmo)  
> Buscar imóveis por faixa de valor (locação, aluguel ou temporada)  
> Buscar imóveis com determinadas características (ex: ar-condicionado, aquecedor, ventilador etc.)  
> Buscar imóveis por número de quartos ou suítes  
> Gerar estatísticas personalizadas (ex: % por finalidade, % com suítes, % com piso cerâmica)  
> Listar todos os imóveis cadastrados  
> Atualizar o arquivo original com os dados manipulados

Formato dos valores:
---------------------
- Imóveis com finalidade de **"temporada"** têm o valor escrito como **"300/dia"**  
- Imóveis de **aluguel ou venda** têm valores numéricos simples (ex: 2500)

Instruções de uso:
-------------------
1. Coloque o arquivo `BD_Imoveis2.txt` na mesma pasta do executável.
2. Compile o programa com um compilador C++.
3. Execute o programa. Um menu será exibido com todas as funcionalidades.
4. Digite o número da opção desejada e siga as instruções na tela.
5. Ao encerrar o programa, o vetor de imóveis será salvo de volta no arquivo de texto.

Requisitos:
-----------
- Compilador C++ instalado  
- Sistema compatível com execução em terminal (Windows, Linux etc.)

Observações importantes:
------------------------
- O número máximo de imóveis é **200**.  
- O programa **lê e salva os dados no mesmo arquivo de entrada** (`BD_Imoveis2.txt`).  
- Todas as operações são feitas em um vetor sem "buracos", ou seja, exclusões deslocam os dados para a esquerda.  

============================================================
