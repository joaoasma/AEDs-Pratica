/***************************************************************
 * João Antonio de Souza Martins 2025.1.08.013
 * Lucas Freire Mesquita 2025.1.08.017
 *
 * Objetivo: Manipular um vetor de até 200 registros de imóveis com menu
 *           interativo, incluindo funcionalidades como inserção,
 *           remoção, busca, contagem e inicialização aleatória/manual.
 ****************************************************************/


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// declarando a maior
const int MAX_IMOVEIS = 200;

// Registro com as 22 colunas de cada imóvel
typedef struct
{
    string tipo;
    string finalidade;
    string endereco;
    string bairro;
    string cidade;
    int area;
    string valor;
    float iptu;
    int quartos;
    int suites;
    int banheiros;
    int vagas;
    string cozinha;
    string sala;
    string varanda;
    string area_servico;
    string piso;
    string conservacao;
    string armarios;
    string ar_condicionado;
    string aquecedor;
    string ventilador;
} Imovel;

// função para pular o cabeçalho
void pular_linha1(ifstream &arquivo)
{
    string ignorar;
    for (int i = 0; i < 23; i++) // 22 palavras + #
    {
        arquivo >> ignorar;
    }
}

// extrai só a parte numérica de strings como "1200" ou "300/dia"
int extrairNumero(const string &s)
{
    int num = 0;
    for (char c : s) // vai ler cada caractere da string
    {
        if (c >= '0' && c <= '9') // usa os valores numéricos da tabela ASCII
        {
            num = num * 10 + (c - '0'); // fórmula para "converter de string para int"
        }
        else
        {
            break; // para ao encontrar '/' ou qualquer não-dígito encerrar a operação
        }
    }
    return num; // retorna o número inteiro
}

// função para imprimir lista de todos os imóveis, OPÇÃO 7
void imprimir_lista(const Imovel imoveis[], int totalImoveis)
{
    cout << "\n--- Lista de todos os imóveis (" << totalImoveis << ") ---\n";
    for (int i = 0; i < totalImoveis; i++)
    {
        const Imovel &im = imoveis[i];
        cout << "Imóvel " << (i + 1) << ":\n";
        cout << "  Tipo: " << im.tipo << "\n";
        cout << "  Finalidade: " << im.finalidade << "\n";
        cout << "  Endereço: " << im.endereco << "\n";
        cout << "  Bairro: " << im.bairro << "\n";
        cout << "  Cidade: " << im.cidade << "\n";
        cout << "  Área: " << im.area << "\n";
        cout << "  Valor: " << im.valor << "\n";
        cout << "  IPTU: " << im.iptu << "\n";
        cout << "  Quartos: " << im.quartos << "\n";
        cout << "  Suítes: " << im.suites << "\n";
        cout << "  Banheiros: " << im.banheiros << "\n";
        cout << "  Vagas: " << im.vagas << "\n";
        cout << "  Cozinha: " << im.cozinha << "\n";
        cout << "  Sala: " << im.sala << "\n";
        cout << "  Varanda: " << im.varanda << "\n";
        cout << "  Área de Serviço: " << im.area_servico << "\n";
        cout << "  Piso: " << im.piso << "\n";
        cout << "  Conservação: " << im.conservacao << "\n";
        cout << "  Armários: " << im.armarios << "\n";
        cout << "  Ar-condicionado: " << im.ar_condicionado << "\n";
        cout << "  Aquecedor: " << im.aquecedor << "\n";
        cout << "  Ventilador: " << im.ventilador << "\n";
        cout << "--------------------------------------\n";
    }
}

// funão para a OPÇÃO 2
void buscar_e_excluir_por_rua(Imovel imoveis[], int &totalImoveis)
{
    string rua;
    cout << "Digite o nome exato da rua (endereço) a buscar: ";
    cin >> ws;
    getline(cin, rua);

    bool encontrado = false;
    for (int i = 0; i < totalImoveis; i++)
    {
        if (imoveis[i].endereco == rua)
        {
            cout << "\nImóvel encontrado:\n";
            cout << "Tipo: " << imoveis[i].tipo << ", Finalidade: " << imoveis[i].finalidade << ", Endereço: " << imoveis[i].endereco << "\n";
            cout << "Valor: " << imoveis[i].valor << ", Quartos: " << imoveis[i].quartos << ", Suítes: " << imoveis[i].suites << "\n";

            char confirmacao;
            cout << "\nDeseja realmente excluir este imóvel? (s/n): ";
            cin >> confirmacao;

            if (confirmacao == 's' || confirmacao == 'S')
            {
                for (int j = i; j < totalImoveis - 1; j++)
                {
                    imoveis[j] = imoveis[j + 1]; // desloca os valores para a esquerda para excluir
                }
                totalImoveis--;
                cout << "Imóvel excluído com sucesso!\n";
            }
            else
            {
                cout << "Exclusão cancelada.\n";
            }

            encontrado = true; // caso tenha sido achado
            break;
        }
    }

    if (!encontrado) // se não for encontrado, exibe essa mensagem
    {
        cout << "Nenhum imóvel encontrado com esse endereço.\n";
    }
}

// PARA A OPÇÃO 1, função para incluir um imóvel
void incluir_imovel(Imovel imoveis[], int &totalImoveis)
{
    if (totalImoveis >= MAX_IMOVEIS) // checa para ver se já há 200 imóveis
    {
        cout << "Limite de imóveis atingido!\n";
        return;
    }

    Imovel novo; // novo.(algo) -> digitar as características do imóvel 
    cout << "Digite os dados do novo imóvel:\n";

    
    cout << "Tipo: ";
    getline(cin >> ws, novo.tipo);
    cout << "Finalidade: ";
    getline(cin, novo.finalidade);
    cout << "Endereço: ";
    getline(cin, novo.endereco);
    cout << "Bairro: ";
    getline(cin, novo.bairro);
    cout << "Cidade: ";
    getline(cin, novo.cidade);

    cout << "Área (m2): ";
    cin >> novo.area;
    cout << "Valor (ex: 1200 ou 300/dia): ";
    cin >> novo.valor;
    cout << "IPTU: ";
    cin >> novo.iptu;
    cout << "Quartos: ";
    cin >> novo.quartos;
    cout << "Suítes: ";
    cin >> novo.suites;
    cout << "Banheiros: ";
    cin >> novo.banheiros;
    cout << "Vagas: ";
    cin >> novo.vagas;

    cout << "Cozinha (sim/nao): ";
    cin >> novo.cozinha;
    cout << "Sala (sim/nao): ";
    cin >> novo.sala;
    cout << "Varanda (sim/nao): ";
    cin >> novo.varanda;
    cout << "Área de serviço (sim/nao): ";
    cin >> novo.area_servico;

    cout << "Piso: ";
    cin >> novo.piso;
    cout << "Conservação (novo/usado/reformado): ";
    cin >> novo.conservacao;

    cout << "Armários (sim/nao): ";
    cin >> novo.armarios;
    cout << "Ar-condicionado (sim/nao): ";
    cin >> novo.ar_condicionado;
    cout << "Aquecedor (sim/nao): ";
    cin >> novo.aquecedor;
    cout << "Ventilador (sim/nao): ";
    cin >> novo.ventilador;

    imoveis[totalImoveis++] = novo; // APÓS o último imóvel, denotado pelo ++, adiciona o novo registro
    cout << "Imóvel adicionado com sucesso!\n";
}

// função para buscar por imóveis, OPÇÃO 4
void buscar_por_moveis(const Imovel imoveis[], int totalImoveis)
{
  // para saber se esses objetos serão usados pela pessoa na casa
    string usar_arm, usar_ar, usar_aq, usar_vent;
		
  // usuário digita o filtro das buscas
    cout << "Deseja buscar imóveis com armários? (sim/nao): ";
    cin >> usar_arm;
    cout << "Deseja com ar-condicionado? (sim/nao): ";
    cin >> usar_ar;
    cout << "Deseja com aquecedor? (sim/nao): ";
    cin >> usar_aq;
    cout << "Deseja com ventilador? (sim/nao): ";
    cin >> usar_vent;

    cout << "\nImóveis encontrados:\n";

    bool encontrou = false;
    for (int i = 0; i < totalImoveis; i++)
    {
        bool ok = true;
				// usa-se operadores lógicos para trabalhar apenas com as escolhas que o usuário executou previamente
        if (usar_arm == "sim" && imoveis[i].armarios != "sim")
            ok = false;
        if (usar_ar == "sim" && imoveis[i].ar_condicionado != "sim")
            ok = false;
        if (usar_aq == "sim" && imoveis[i].aquecedor != "sim")
            ok = false;
        if (usar_vent == "sim" && imoveis[i].ventilador != "sim")
            ok = false;

        if (ok)
        {
            encontrou = true; 
            cout << "- " << imoveis[i].endereco << " (" << imoveis[i].tipo << ", " << imoveis[i].finalidade << ")\n";
        }
    }

    if (!encontrou) // se NÃO encontrou
    {
        cout << "Nenhum imóvel encontrado com as características exigidas.\n";
    }
}

// função para a OPÇÃO 7, estatística
void relatorio_estatisticas(const Imovel imoveis[], int totalImoveis)
{
  // usuário digita qual opção ele quer
    cout << "\nRelatório de Estatísticas:\n";
    cout << "  1 - % por finalidade\n";
    cout << "  2 - % de casas com suítes\n";
    cout << "  3 - % de salas comerciais c/ piso cerâmica\n";
    cout << "Escolha (1/2/3): ";
    int opc;
    cin >> opc;

    if (opc == 1)
    {
        cout << "Digite a finalidade (venda / aluguel / temporada): ";
        string f;
        cin >> f;

        int contador = 0;
        for (int i = 0; i < totalImoveis; i++)
            if (imoveis[i].finalidade == f)
                contador++; // contar quantos possui no vetor

        int perc;
        if (totalImoveis > 0) 
            perc = contador * 100 / totalImoveis; // transformar o número em %
        else
            perc = 0;

        cout << "\nDos " << totalImoveis << " imóveis, "
             << perc << "% têm finalidade " << f << ".\n";
    }
    else if (opc == 2)
    {
        int totalCasas = 0, comSuite = 0;
        for (int i = 0; i < totalImoveis; i++)
        {
            if (imoveis[i].tipo == "casa")
            {
                totalCasas++;
                if (imoveis[i].suites > 0)
                    comSuite++;
            }
        }
        int perc = (totalCasas > 0) ? (comSuite * 100 / totalCasas) : 0;
        cout << "\nDas " << totalCasas << " casas, "
             << perc << "% têm suíte(s).\n";
    }
    else if (opc == 3)
    {
        int totalSalas = 0, comCeramica = 0;
        for (int i = 0; i < totalImoveis; i++)
        {
            if (imoveis[i].tipo == "sala_comercial")
            {
                totalSalas++;
                if (imoveis[i].piso == "cerâmica" || imoveis[i].piso == "ceramica")
                    comCeramica++;
            }
        }
        int perc = (totalSalas > 0) ? (comCeramica * 100 / totalSalas) : 0;
        cout << "\nDas " << totalSalas << " salas comerciais, "
             << perc << "% têm piso cerâmica.\n";
    }
    else
    {
        cout << "\nOpção inválida. Voltando ao menu.\n";
    }
}

// para salvar os dados no vetor de uma só vez (acoplado à opção 0)
void salvar_dados(const Imovel imoveis[], int totalImoveis) {
    ofstream arquivo("BD_Imoveis2.txt");
    if (!arquivo.is_open()) { // caso, durante a execução, haja problemas com o arquivo
        cout << "Erro ao salvar no arquivo!\n";
        return;
    }

  // recria o arquivo, mas agora com base nas operações que foram feitas pelo usuário durante a execução do código
  // cabeçalho
  arquivo << "# Tipo Finalidade Endereco Bairro Cidade Area Valor IPTU Quartos Suites Banheiros Vagas Cozinha Sala Varanda Area_de_Servico Piso Conservacao Armarios Ar_condicionado Aquecedor Ventilador\n";

  // características separadas por " "
    for (int i = 0; i < totalImoveis; i++) {
        const Imovel &im = imoveis[i];
        arquivo << im.tipo << " " << im.finalidade << " " << im.endereco << " " << im.bairro << " " << im.cidade << " ";
        arquivo << im.area << " " << im.valor << " " << im.iptu << " " << im.quartos << " " << im.suites << " ";
        arquivo << im.banheiros << " " << im.vagas << " " << im.cozinha << " " << im.sala << " " << im.varanda << " ";
        arquivo << im.area_servico << " " << im.piso << " " << im.conservacao << " " << im.armarios << " ";
        arquivo << im.ar_condicionado << " " << im.aquecedor << " " << im.ventilador << "\n";
    }
  
// finaliza com a palavra fim
    arquivo << "fim\n";
    arquivo.close();
    cout << "Alterações salvas com sucesso no arquivo!\n"; // mostra ao usuário que as informações foram salvas
}

int main()
// Abre o arquivo com os dados dos imóveis
{
    ifstream arquivo("BD_Imoveis2.txt");
    if (!arquivo.is_open()) //Caso o arquivo não possa ser aberto, exibe mensagem de erro e retorna 1
    {
        cout << "Erro: não foi possível abrir o arquivo BD_Imoveis2.txt\n";
        return 1;
    }

    cout << "Arquivo aberto com sucesso!\n";
    pular_linha1(arquivo);

    Imovel imoveis[MAX_IMOVEIS];
    int totalImoveis = 0;

// Lê os dados do arquivo e armazena no vetor
    while (totalImoveis < MAX_IMOVEIS)
    {
        Imovel im;
        arquivo >> im.tipo;
        if (im.tipo == "fim")
            break;
// Lê os outros campos do imóvel
        arquivo >> im.finalidade >> im.endereco >> im.bairro >> im.cidade >> im.area >> im.valor >> im.iptu >> im.quartos >> im.suites >> im.banheiros >> im.vagas >> im.cozinha >> im.sala >> im.varanda >> im.area_servico >> im.piso >> im.conservacao >> im.armarios >> im.ar_condicionado >> im.aquecedor >> im.ventilador;

        imoveis[totalImoveis] = im;
        totalImoveis++;
    }

    cout << "As informações do arquivo foram coletadas\n";

    int opcao = 123;
    // Loop do menu
    while (opcao != 0)
    {
        cout << "\nMenu de Opções:\n";
        cout << "1 - Adicionar um imóvel\n";
        cout << "2 - Buscar por rua e excluir\n";
        cout << "3 - Buscar por valores\n";
        cout << "4 - Buscar por armários, ar-condicionado, ventilador ou aquecedor\n";
        cout << "5 - Busca de imóveis pelo número de quartos e suítes\n";
        cout << "6 - Estatísticas\n";
        cout << "7 - Listar todos os imóveis\n";
        cout << "8 - Buscar um imóvel específico\n";
        cout << "0 - Sair\n";
        cout << "R: ";
        cin >> opcao;

        switch (opcao)	// Executa função escolhida
        {
            case 1: 
                incluir_imovel(imoveis, totalImoveis);	// Adiciona novo imóvel
                break;

            case 2:
                buscar_e_excluir_por_rua(imoveis, totalImoveis);	// Exclui imóvel por endereço
                break;

            case 3:
            {
                cout << "\nBuscar por faixa de valor em:\n"	// Escolhe tipo de negociação
                     << "  1 - venda\n"
                     << "  2 - aluguel\n"
                     << "  3 - temporada\n"
                     << "Opção: ";
                int opcaoFinalidade;
                cin >> opcaoFinalidade;

                string finalidadeEscolhida;
                if (opcaoFinalidade == 1)
                    finalidadeEscolhida = "venda";
                else if (opcaoFinalidade == 2)
                    finalidadeEscolhida = "aluguel";
                else if (opcaoFinalidade == 3)
                    finalidadeEscolhida = "temporada";
                else
                {
                  // Se digitar algo inválido, interrompe a operação
                    cout << "Finalidade inválida\n";
                    break;
                }
              // Solicita os valores mínimo e máximo para filtrar os imóveis
                cout << "Valor mínimo: ";	
                int valorMin;
                cin >> valorMin;
                cout << "Valor máximo: ";
                int valorMax;
                cin >> valorMax;

                int encontrados = 0;	// Contador para saber se algum imóvel foi localizado
                cout << "\nImóveis de finalidade " << finalidadeEscolhida
                     << " entre " << valorMin << " e " << valorMax << ":\n";
    						// Percorre todos os imóveis cadastrados
                for (int i = 0; i < totalImoveis; i++)
                {
                // Ignora imóveis que não têm a finalidade desejada
                    if (imoveis[i].finalidade != finalidadeEscolhida) 
                        continue;
                  // Converte o valor string (como "300/dia") para número inteiro  
                  int v = extrairNumero(imoveis[i].valor);
                  // Verifica se o valor está dentro da faixa escolhida
                    if (v >= valorMin && v <= valorMax)
                    {
                        cout << "  Imóvel " << (i + 1)
                             << " — valor: " << imoveis[i].valor << "\n";
                        encontrados++;
                    }
                }
                  // Se nenhum imóvel for encontrado, informa o usuário
                if (encontrados == 0)
                    cout << "  Nenhum imóvel encontrado nessa faixa.\n";
                break;
            }

            case 4:
                buscar_por_moveis(imoveis, totalImoveis);
                break;
                
            case 5:
            {
                int subopcao;
                cout << "\nQuer buscar por qual?\n";
                cout << "1 - Quartos\n";
                cout << "2 - Suítes\n";
                cout << "Para sair, digite qualquer outro número.\n";
                cout << "R: ";
                cin >> subopcao;

                if (subopcao != 1 && subopcao != 2)
                {
                    cout << "Opção inválida de busca. Operação encerrada.\n";
                    break;
                }

                int quantidade;
                cout << "Digite a quantidade desejada: ";
                cin >> quantidade;

                int encontrou = 0;
                cout << "Os imóveis que possuem essa quantidade são: ";
                for (int i = 0; i < totalImoveis; i++)
                {
                  // Verifica se o imóvel tem a quantidade desejada
                    if ((subopcao == 1 && imoveis[i].quartos == quantidade) ||
                        (subopcao == 2 && imoveis[i].suites == quantidade))
                    {
                        cout << (i + 1) << " ";
                        encontrou = 1;
                    }
                }

                if (encontrou == 0)
                {
                    cout << "nenhum";
                }

                cout << endl;
                break;
            }
            case 6:
            // Estatística sobre os imóveis
                relatorio_estatisticas(imoveis, totalImoveis);
                break;

            case 7:
            //Lista todos imóveis cadastrados
                imprimir_lista(imoveis, totalImoveis);
                break;
                
            case 8:
            // Mostra os dados completos de um imóvel específico
            {
                int buscar;
                cout << "Digite o nº do imóvel (1 a " << totalImoveis << "): ";
                cin >> buscar;
                if (buscar < 1 || buscar > totalImoveis)
                {
                    cout << "Número inválido\n";
                    break;
                }
                Imovel &im = imoveis[buscar - 1];
                cout << "\nImóvel " << buscar << ":\n";
                cout << "Tipo: " << im.tipo << "\n";
                cout << "Finalidade: " << im.finalidade << "\n";
                cout << "Endereço: " << im.endereco << "\n";
                cout << "Bairro: " << im.bairro << "\n";
                cout << "Cidade: " << im.cidade << "\n";
                cout << "Área: " << im.area << "\n";
                cout << "Valor: " << im.valor << "\n";
                cout << "IPTU: " << im.iptu << "\n";
                cout << "Quartos: " << im.quartos << "\n";
                cout << "Suítes: " << im.suites << "\n";
                cout << "Banheiros: " << im.banheiros << "\n";
                cout << "Vagas: " << im.vagas << "\n";
                cout << "Cozinha: " << im.cozinha << "\n";
                cout << "Sala: " << im.sala << "\n";
                cout << "Varanda: " << im.varanda << "\n";
                cout << "Área de Serviço: " << im.area_servico << "\n";
                cout << "Piso: " << im.piso << "\n";
                cout << "Conservação: " << im.conservacao << "\n";
                cout << "Armários: " << im.armarios << "\n";
                cout << "Ar-condicionado: " << im.ar_condicionado << "\n";
                cout << "Aquecedor: " << im.aquecedor << "\n";
                cout << "Ventilador: " << im.ventilador << "\n";
                break;
            }
            
							// para encerrar o programa e salvar as alterações no arquivo
            case 0:
                salvar_dados(imoveis, totalImoveis);
                cout << "Encerrando o programa...\n";
                break;

            default:
                cout << "Opção inválida. Tente novamente.\n";
        }
    }

    arquivo.close();
    return 0;
}