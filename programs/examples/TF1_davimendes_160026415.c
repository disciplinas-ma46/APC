#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <windows.h>
#include <locale.h>
#include <Conio.h>

#define LARGURACONSOLE 120 //Largura da tela do console.
#define ALTURACONSOLE 27 //Altura da tela do console.
#define MAXIMO 513 //M�ximo de deputados no cadastro.
#define TAMANHONOME 51 //Define o tamanho maximo para a string de nomes dos deputados.
#define TAMANHOSIGLA 11 //Define o tamanho maximo para a string da sigla do partido.
#define MINIMATRICULA 10 //Valor m�nimo para a matr�cula individual de cada deputado.

//Objetivo: Armanezar os dados para cada um dos deputados cadastrados.
//Parametros: Nome, sexo, sigla, matr�cula e idade.
//Retorno: Nenhum.
typedef struct{
	int matricula;
	int idade;
	char nome[TAMANHONOME];
	char sexo;
	char siglaPartido [TAMANHOSIGLA];
} infoDeputado;

//Objetivo: Armazenar a quantidade de linhas e colunas do console aberto.
//Parametros: Linhas e colunas.
//Retorno: Nenhum.
typedef struct{
    int linhas;
    int colunas;
} Window;

//=========================PROT�TIPOS====================

int verificaUnicidadeMatricula (int,Window *);
int quantidadeCadastrosArquivo (FILE *,Window *);
int controlaPagina (Window *);
int validaPagina(char *,int,Window *);

float calculaMediaIdades(Window *);

char validaContinuaCadastro(char,Window *);
char continuaCadastro (Window *);
char registraModoImpressao (Window *);
char validaModoImpressao (char,Window *);
char validaOpcaoEdicao(char,Window *);

void cadastraDeputado(infoDeputado *, Window *,int);
void imprimirDeputados (infoDeputado deputados[], int,char,Window*,int);
void moveto(int,int);
void getDimension(Window *);
void imprimeMenu (Window *);
void centerPrint (char *,Window *, int, int);
void limpaLinha (Window *, int);
void limpaNovaLinha(char *);
void ordenaDeputados (Window *,infoDeputado[]);
void adjustWindowSize();
void removerArquivo (Window *);
void listarVazio (Window *);
void formataNome (char *);
void printArtboard (Window *);
void listaMaximo(Window *);
void printArtboardTabela(Window *);
void imprimeDivisoriaVertical(int,Window *);
void mensagemFinal(Window *);
void setFontSize(int);
void editaDeputado (Window *);
void erroLerArquivo(Window *);
void alteraNome (char *,Window *);
void alteraSigla (char *,Window *);
void alteraSexo (char *,Window *);
void removeDeputado (Window *);
void validaAberturaArquivo (FILE *,Window*);

bool validaAlteraSexo (char,Window *);
bool removeCadastroArquivo (infoDeputado *,FILE *,Window*);
bool validaAlteraNome (char *,Window*);
bool validaAlteraSigla (char *,Window *);
bool validaNome (char*,Window *);
bool validaIdade (char*,Window *);
bool validaSexo (char *,Window *);
bool validaMatricula(char*,Window *,char);
bool validaSigla (char *,Window *);
bool validaOpcao (char, Window *);
bool gravaCadastro (infoDeputado *,FILE *,Window*);
bool validaTamanhoConsole (Window*);
bool validaExluirArquivo (char,Window*);

//=============================FIM DOS PROT�TIPOS===========================

// S�ntese
//  Objetivo: Acompanhar o processso de vota��o dos deputados.
//  Entrada : Nome, matr�cula, idade, sexo e sigla do partido.
//  Sa�da   : Nome, matr�cula, m�dia das idades, sexo, sigla do partido e quantidade de cadastros.
int main()
{
    setlocale(LC_ALL,"Portuguese"); //Habilitar acentos e outros.
    SetConsoleTitle("| VOTER BETA | by Davi Mendes"); //Troca o t�tulo da janela
    setFontSize(18); //Altera o tamanho atual da fonte

	char opcao,continua,modoImpressao;
    bool erroCadastro;
    int cadastros,pagina;
	
    infoDeputado deputado;
    FILE *pArquivo;
    Window *dimension = (Window*) malloc(sizeof(Window)); //Alocar mem para armazenar a dimens�o da tela na struct.
    if (dimension == NULL)
    {
        printf("Erro CR�TICO ao alocar mem�ria para o programa.\n");
        system ("pause");
        exit (2);
    }

    getDimension(dimension); //Armazena o tamanho das linhas e colunas do console.
    if (validaTamanhoConsole(dimension) == false)
    {
        adjustWindowSize ();
        getDimension(dimension);
    }

    do {
        printArtboard(dimension);
        imprimeMenu(dimension);
        do {
            centerPrint("Digite a op��o correspondente do menu: _",dimension,20,0);
            moveto (dimension->colunas/2 +19,20);
            opcao=getche();
            opcao = toupper(opcao);
	    } while (validaOpcao(opcao,dimension)==FALSE);
        printArtboard(dimension);

	    switch (opcao)
        {
            case '1' :
                cadastros = quantidadeCadastrosArquivo(pArquivo,dimension);
                if (cadastros == MAXIMO)
                    listaMaximo(dimension);
                else
                    do {
                        erroCadastro = false;
                        cadastraDeputado(&deputado,dimension,cadastros);
                        if(gravaCadastro (&deputado, pArquivo, dimension) == false)
                        {
                            erroCadastro = true;
                            continue;
                        }
                        else if(quantidadeCadastrosArquivo(pArquivo,dimension) < 2)
                        {
                            centerPrint("Prossiga para cadastrar o pr�ximo deputado (Aperter ENTER). . .",dimension,22,0);
                            moveto(dimension->colunas/2,23);
                            getch();
                            continua = 'S';
                        }
                        else
                        {
                            cadastros = quantidadeCadastrosArquivo(pArquivo,dimension);
                            if (cadastros == 513)
                            {
                                system("cls");
                                printArtboard(dimension);
                                listaMaximo(dimension);
                            }
                            else
                                continua = continuaCadastro(dimension);
                        }
                    } while((continua == 'S' || erroCadastro == true) && cadastros < MAXIMO);
                break;
            case '2' :
                cadastros = quantidadeCadastrosArquivo(pArquivo,dimension);
                if (cadastros == 0)
                    listarVazio(dimension);
                else
                {
                    printArtboard(dimension);
                    editaDeputado(dimension);
                }
                break;
            case '3' :
                cadastros = quantidadeCadastrosArquivo(pArquivo,dimension);
                if (cadastros == 0)
                    listarVazio(dimension);
                else
                    removeDeputado(dimension);
                break;
            case '4' :
                cadastros = quantidadeCadastrosArquivo(pArquivo,dimension);
                if (cadastros == 0)
                    listarVazio(dimension);
                else
                {
                    modoImpressao = registraModoImpressao(dimension);
                    infoDeputado *deputadosOrdenados = (infoDeputado*) calloc(sizeof(infoDeputado),cadastros);
                    if (deputadosOrdenados == NULL)
                    {
                        printArtboard(dimension);
                        centerPrint(">> ERRO AO ALOCAR MEM�RIA PARA O PROGRAMA <<",dimension,10,0);
                        moveto(dimension->colunas/2 -22,15);
                        system ("pause");
                        continue;
                    }
                    ordenaDeputados(dimension,deputadosOrdenados);
                    pagina = 1;
                    printArtboardTabela(dimension);
                    imprimirDeputados(deputadosOrdenados,cadastros,modoImpressao,dimension,pagina);//imprime a 1a p�gina
                    do {
                        moveto(dimension->colunas/2 +2,dimension->linhas -2);
                        printf("%d",pagina);
                        pagina = controlaPagina(dimension);
                        moveto(dimension->colunas/2 +2,dimension->linhas -2);
                        printf("%d",pagina);
                        if (pagina != 0)
                        {
                            printArtboardTabela(dimension);
                            imprimirDeputados(deputadosOrdenados,cadastros,modoImpressao,dimension,pagina);
                        }
                    } while (pagina != 0);
                    free(deputadosOrdenados);
                }
                break;
            case '5' :
                cadastros = quantidadeCadastrosArquivo(pArquivo,dimension);
                if (cadastros == 0)
                    listarVazio(dimension);
                else               
                    removerArquivo(dimension);
        }
    } while (opcao != '0');
    printArtboard(dimension);
    mensagemFinal(dimension);
    free(dimension);
	return 0;
}
// =================== SUBALGORITMOS ============================

//==========================SUBPROGRAMAS GR�FICOS/IMPRESS�O================

//Objetivo: Configurar o tamanho da fonte do console.
//Parametro: Tamanho da fonte.
//Retorno: Nenhum.
void setFontSize(int FontSize)
{
    CONSOLE_FONT_INFOEX info = {0};
    info.cbSize       = sizeof(info);
    info.dwFontSize.Y = FontSize;
    info.FontWeight   = FW_NORMAL;
    wcscpy(info.FaceName, L"Consolas");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), true, &info);
}

//Objetivo: Imprimir o contorno da planilha do relat�rio dos deputados.
//Parametros: Dimens�es da tela.
//Retorno: Nenhum.
void printArtboardTabela(Window *dimension)
{
    printArtboard(dimension);
    setlocale(LC_ALL,"C");
    int contador;
    //Imprimindo a 1a divis�ria da tabela (horizontal)
    moveto(1,3);
    printf("%c",(char) 204);
    moveto(2,3);
    for(contador=0;contador<dimension->colunas-2;contador++)
        printf("%c",(char) 196);
    printf("%c",(char) 185);
    //FIM
    //imprimindo 2a divis�ria da tabela (horizontal)
    moveto(1,dimension->linhas-3);
    printf("%c",(char) 204);
    for (contador = 0;contador<dimension->colunas-2;contador++)
        printf("%c",(char) 205);
    printf("%c",(char) 185);
    //FIM
    //imprimindo 1 divis�ria na vertical
    imprimeDivisoriaVertical(51,dimension);
    //Imprimindo 2 divis�ria na vertical
    imprimeDivisoriaVertical(71,dimension);
    //Imprimindo 3 divis�ria na vertical
    imprimeDivisoriaVertical(96,dimension);
    //imprimindo infos da tabela
    setlocale(LC_ALL,"Portuguese");
    moveto(18,2);
    printf("Nome Completo");
    moveto (51+6,2);
    printf("Matr�cula");
    moveto(71+5,2);
    printf("Sigla do Partido");
    moveto(96+10,2);
    printf("Sexo");
}

//Objetivo: Imprimir o contorno da divis�ria vertical da planilha do relat�rio dos deputados.
//Parametros: Coluna da impress�o e dimens�es da tela.
//Retorno: Nenhum.
void imprimeDivisoriaVertical(int coluna,Window*dimension)
{
    int contador;
    moveto(coluna,1);
    printf("%c",(char) 203);
    for(contador=0;contador<dimension->linhas-5;contador++)
    {
        moveto(coluna,2+contador);
        printf("%c",(char) 179);
    }
    moveto(coluna,2+contador);
    printf("%c",(char) 202);
    moveto(coluna,3);
    printf("%c",(char) 197);
}

//Objetivo: Imprimir mensagem de M�ximo de cadastros efetuados.
//Parametros: Dimens�es da tela.
//Retorno: Nenhum.
void listaMaximo (Window *dimension)
{
    centerPrint("*  *   *   *   *   *   *   *   *   *   *   *",dimension,9,0);
    centerPrint("*  N�mero m�ximo de cadastros alcan�ado    *",dimension,10,0);
    centerPrint("*  *   *   *   *   *   *   *   *   *   *   *",dimension,11,0);
    moveto (dimension->colunas/2 - 22,18);
    system ("pause");
}

//Objetivo: Limpar uma linha do console sem apagar a borda.
//Parametros: Dimens�es da tela e linha a ser apagada.
//Retorno: Nenhum.
void limpaLinha (Window * dimension, int linha)
{
    int contador;
    moveto(2,linha);
    for (contador=0;contador<dimension->colunas-2;contador++)
        printf (" ");
}

//Objetivo: Imprimir o menu principal.
//Parametros: Dimens�es da tela.
//Retorno: Nenhum.
void imprimeMenu (Window * dimension)
{
    FILE *pArquivo;
    centerPrint("#   #    #   #   #   #   #   #   #   #   #    #    #",dimension,4,0);
    centerPrint("#    >>> Seja Bem-Vindo ao | BUNDA CHEIROZA |. <<< #",dimension,5,0);
    centerPrint("# -> O programa possui     registros de deputados. #",dimension,6,0);
    centerPrint("#   #    #   #   #   #   #   #   #   #   #    #    #",dimension,7,0);
    moveto(dimension->colunas/2 -3,6);
    printf("%d", quantidadeCadastrosArquivo(pArquivo,dimension));
    centerPrint("1. Novo Deputado          ",dimension,10,0);
    centerPrint("2. Edita Deputado         ",dimension,11,0);
    centerPrint("3. Remove Deputado        ",dimension,12,0);
    centerPrint("4. Lista Todos Deputados  ",dimension,13,0);
    centerPrint("5. Remove Arquivo de Dados",dimension,14,0);
    centerPrint("0. Encerra Programa       ",dimension,15,0);
}

//Objetivo: Imprimir uma string no centro da tela.
//Parametros: String a ser impressa, dimens�es da tela, linha para impress�o e recuo da impress�o.
//Retorno: Nenhum.
void centerPrint (char *impressao,Window * dimension, int linha, int recuo)
{
    moveto((dimension->colunas - strlen (impressao))/2 + recuo,linha);
    puts (impressao);
}

//Objetivo: Configurar o tamanho do console.
//Parametros: Nenhum.
//Retorno: Nenhum.
void adjustWindowSize()
{
    HANDLE hStdout;
    COORD coord;
    coord.X = LARGURACONSOLE;
    coord.Y = ALTURACONSOLE;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT WinRect = {0, 0, coord.X-1,coord.Y-1};
    SMALL_RECT* WinSize = &WinRect;
    SetConsoleWindowInfo(hStdout,SetConsoleScreenBufferSize(hStdout, coord),WinSize);
}

//Objetivo: Armazenar na struct as dimens�es do console.
//Parametros: Ponteiro da struct.
//Retorno: Nenhum.
void getDimension(Window* dimension)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    dimension->colunas = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    dimension->linhas = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

//Objetivo: Mover o cursor.
//Parametros: Coordenadas para o destino do cursor.
//Retorno: Nenhum.
void moveto(int x, int y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}

//Objetivo: Imprimir mensagem de erro em caso de erro na leitura de um arquivo.
//Parametros: Dimens�es da tela.
//Retorno: Nenhum.
void erroLerArquivo (Window *dimension)
{
    printArtboard(dimension);
    centerPrint("ERRO AO LER ARQUIVO DE DADOS, SUGERE-SE REINICIAR O PROCESSO.",dimension,15,0);
    getch();
}

//Objetivo: Imprimir borda do console.
//Parametros: Dimens�es da tela.
//Retorno: Nenhum.
void printArtboard (Window * dimension)
{
    setlocale(LC_ALL,"C");
    int contador;
    system("cls");
    moveto(1,1);
    printf("%c",(char) 201);
    moveto(dimension->colunas,1);
    printf("%c",(char) 187);
    moveto(1,dimension->linhas);
    printf("%c",(char) 200);
    moveto(dimension->colunas,dimension->linhas);
    printf("%c",(char) 188);
    moveto(2,1);
    for(contador=0;contador<dimension->colunas-2;contador++)
        printf("%c",(char) 205);
    moveto(2,dimension->linhas);
    for(contador=0;contador<dimension->colunas-2;contador++)
        printf("%c",(char) 205);
    moveto(1,2);
    for(contador=0;contador<dimension->linhas-2;contador++)
        printf("%c\n",(char) 186);
    moveto(dimension->colunas,2);
    for(contador=0;contador<dimension->linhas-1;contador++)
    {
        printf("%c",(char) 186);
        moveto(dimension->colunas,2+contador);
    }
    setlocale(LC_ALL,"Portuguese");
}

//Objetivo: Imprimir as informa��es registradas dos deputados.
//Parametros: Vetor dos deputados, n�mero de cadastros, modo de impress�o, dimens�es da tela e p�gina da impress�o.
//Retorno: TRUE caso v�lido, FALSE caso inv�lido.
void imprimirDeputados(infoDeputado deputadosOrdenados[], int indiceDeputado, char modo,Window * dimension,int pagina)
{
    int indiceInicial, indiceFinal,indice,paginaMax,linha=0;
    paginaMax = indiceDeputado/19;
    if (indiceDeputado % 19 > 0)
        paginaMax ++;
   
    if (modo == 'C')
    {
        indiceInicial = 19*(pagina-1);
        indiceFinal = 19*pagina;
        if (indiceFinal > indiceDeputado)
            indiceFinal = indiceDeputado;

        for (indice=indiceInicial;indice<indiceFinal;indice++)
        {
            moveto(2,4+linha);
            printf("%s",deputadosOrdenados[indice].nome);
            moveto(53,4+linha);
            printf("%d",deputadosOrdenados[indice].matricula);
            moveto(73,4+linha);
            printf("%s", deputadosOrdenados[indice].siglaPartido);
            moveto(98,4+linha);
            if (deputadosOrdenados[indice].sexo == 'M')
                printf("Masculino");
            else
                printf("Feminino");
            linha++;
        }
    }
    else if (modo == 'D')
    {
        indiceInicial = indiceDeputado-1-((pagina-1)*19);
        indiceFinal = indiceInicial - 19;
        if (indiceFinal < 0)
            indiceFinal = 0;
        for (indice=indiceInicial;indice>=indiceFinal;indice--)
        {
            moveto(2,4+linha);
            printf("%s",deputadosOrdenados[indice].nome);
            moveto(53,4+linha);
            printf("%d",deputadosOrdenados[indice].matricula);
            moveto(73,4+linha);
            printf("%s", deputadosOrdenados[indice].siglaPartido);
            moveto(98,4+linha);
            if (deputadosOrdenados[indice].sexo == 'M')
                printf("Masculino");
            else
                printf("Feminino");
            linha++;
        }
    }
}

//Objetivo: Imprimir a mensagem final do programa (ap�s encerramento).
//Parametros: Dimens�es da tela.
//Retorno: Nenhum.
void mensagemFinal(Window * dimension)
{
    FILE * pArquivo;
    int cadastros = quantidadeCadastrosArquivo(pArquivo,dimension);
    centerPrint("*   *   *   *   *   *   *   *   *   *   *   *",dimension,7,0);
    centerPrint("*    Obrigado por utilizar |VOTER BETA| !   *",dimension,8,0);
    centerPrint("*   *   *   *   *   *   *   *   *   *   *   *",dimension,9,0);
    if (cadastros == 0)
    {
        centerPrint(">> N�o h� nenhum cadastro arquivado. <<",dimension,14,0);
        centerPrint(">>  N�o havendo deputados cadastrados, n�o � poss�vel mostrar a m�dia de suas idades. <<",dimension,16,0);
    }
    else
    {
        centerPrint(">> H�     cadastros arquivados. <<",dimension,14,0);
        moveto(dimension->colunas/2 - 11,14);
        printf("%d",cadastros);
        centerPrint(">> A m�dia de idade dos deputados � de:      anos. <<",dimension,16,0);
        moveto(dimension->colunas/2 + 13,16);
        printf("%.1f", calculaMediaIdades(dimension));
    }
    moveto (dimension->colunas/2 - 22,20);
    system ("pause");
}

//Objetivo: Imprimir mensagem de 0 cadastros.
//Parametros: Dimens�es da tela.
//Retorno: Nenhum.
void listarVazio (Window * dimension)
{
    printArtboard(dimension);
    centerPrint("*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *",dimension,8,0); 
    centerPrint("*  N�o h� dados a serem mostrados, favor cadastrar deputados.  *",dimension,9,0);
    centerPrint("*  N�o h� dados no arquivo, digite algo para retornar ao menu  *",dimension,10,0);
    centerPrint("*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *",dimension,11,0);
    moveto(dimension->colunas/2,20);
    getch();    
}

//====================FIM DOS SUBPROGRAMAS GR�FICOS/IMPRESS�O===================

//====================SUBPROGRAMAS MISTOS=======================================

//Objetivo: Gerenciar o processo de remo��o de um deputado.
//Parametros: Dimens�es da tela.
//Retorno: Nenhum.
void removeDeputado (Window * dimension)
{
   FILE * pArquivo;
   infoDeputado tempDeputado;
   char matricula [9],opcao;
   int cadastros = quantidadeCadastrosArquivo(pArquivo,dimension),posicaoArquivo,matriculaInteiro;
   do {
        printArtboard(dimension);
        centerPrint("*   *   *   *   *   *   *   *   *   *   *   *",dimension,3,0);
        centerPrint("*  >> Bem-Vindo a remo��o de cadastros. <<  *",dimension,4,0);
        centerPrint("*   *   *   *   *   *   *   *   *   *   *   *",dimension,5,0);
        do {
            limpaLinha(dimension,7);
            moveto(dimension->colunas/6,7);
            printf("Para prosseguir, digite a matr�cula do deputado: ________");
            moveto(dimension->colunas/2 + 9,7);
            fgets(matricula,9,stdin);
            limpaNovaLinha(matricula);
            limpaLinha(dimension,8);
        } while (validaMatricula(matricula,dimension,'P') == false);
        limpaLinha(dimension,8);
        matriculaInteiro=atoi(matricula);
        posicaoArquivo = verificaUnicidadeMatricula(matriculaInteiro,dimension);
        if (posicaoArquivo == -1)
        {
            centerPrint(">> Matr�cula n�o cadastrada, deseja reiniciar a edi��o de dados (S/N): _ <<",dimension,9,0);
            moveto(dimension->colunas/2 + 33,9);
            opcao = getch();
            opcao = validaOpcaoEdicao(opcao,dimension);
        }
        else
        {
            pArquivo = fopen("camara.bin","a+b");
            validaAberturaArquivo(pArquivo,dimension);
            fseek(pArquivo,(posicaoArquivo-1)*sizeof(infoDeputado),SEEK_SET);
            if (fread(&tempDeputado,sizeof(infoDeputado),1,pArquivo) == 1)
            {
                moveto(dimension->colunas/12,12);
                printf("Nome Completo: %s",tempDeputado.nome);
                moveto(dimension->colunas/12,14);
                printf("Sigla do Partido: %s",tempDeputado.siglaPartido);
                moveto(dimension->colunas/12,16);
                printf("Sexo (M-Masculino/F-Feminino): ");
                if (tempDeputado.sexo == 'M')
                    printf("Masculino");
                else
                    printf("Feminino");
                moveto(dimension->colunas/12,18);
                printf("Matr�cula: %d", tempDeputado.matricula);
                moveto(dimension->colunas/12,20);
                printf("Idade: %d",tempDeputado.idade);
            }
            else
                erroLerArquivo(dimension);
            fclose(pArquivo);
            centerPrint("> > > Para prosseguir com a remo��o, confirme sua escolha (S/N): _.",dimension,9,2);
            moveto(dimension->colunas/2 + 33,9);
            opcao = getch();
            opcao = validaOpcaoEdicao(opcao,dimension);
            if (opcao == 'S')
            {
                removeCadastroArquivo(&tempDeputado,pArquivo,dimension);
                moveto(dimension->colunas/12,22);
                printf("> > > Deputado %s apagado com sucesso! < < <",tempDeputado.nome);
            }
            else
            {
                moveto(dimension->colunas/12,22);
                printf("> > > Cancelada a retirada do deputado %s. < < <",tempDeputado.nome);                
            }
            limpaLinha(dimension,9);
            centerPrint("> > > Confirme caso queria CONTINUAR removendo cadastros (S/N): _",dimension,9,2);
            moveto(dimension->colunas/2 + 33,9);
            opcao = getch();
            opcao = validaOpcaoEdicao(opcao,dimension);
        }
    } while (opcao != 'N');
}

//Objetivo: Remover um cadastro do arquivo de dados.
//Parametros: Dados do deputado a ser removido, ponteiro do arquivo de dados e dimens�es da tela.
//Retorno: Em caso de sucesso: verdadeiro, em caso de fracasso: falso.
bool removeCadastroArquivo (infoDeputado * deputado,FILE * pArquivo,Window * dimension)
{
    FILE * pNovoArquivo;
    infoDeputado tempDeputado;
    pArquivo = fopen("camara.bin","a+b");
    validaAberturaArquivo (pArquivo,dimension);
    rewind(pArquivo);
    pNovoArquivo = fopen("temp.bin","w+b");
    validaAberturaArquivo(pNovoArquivo,dimension);
    while (fread(&tempDeputado,sizeof(infoDeputado),1,pArquivo) != 0 && !feof(pArquivo)) 
    {
        if (deputado->matricula != tempDeputado.matricula) 
        {
            fwrite(&tempDeputado,sizeof(infoDeputado),1,pNovoArquivo);
        }
    }
    if (ferror (pArquivo) != 0 || ferror (pNovoArquivo) != 0)
    {
        fclose(pArquivo);
        fclose(pNovoArquivo);
        remove("temp.bin");
        return false;        
    }
    fclose(pArquivo);
    fclose(pNovoArquivo);
    remove("camara.bin");
    rename("temp.bin","camara.bin");
    return true;
}

//Objetivo: Gerenciar o processo de edi��o de um deputado.
//Parametros: Dimens�es da tela.
//Retorno: Nenhum.
void editaDeputado(Window * dimension)
{
   FILE * pArquivo;
   infoDeputado tempDeputado;
   char matricula [9],opcao;
   int cadastros = quantidadeCadastrosArquivo(pArquivo,dimension),posicaoArquivo,matriculaInteiro;

   do {
        printArtboard(dimension);
        centerPrint("*   *   *   *   *   *   *   *   *   *   *   *",dimension,3,0);
        centerPrint("* >>> Bem-Vindo a edi��o de cadastros. <<<  *",dimension,4,0);
        centerPrint("*   *   *   *   *   *   *   *   *   *   *   *",dimension,5,0);
        do {
            limpaLinha(dimension,7);
            moveto(dimension->colunas/6,7);
            printf("Para prosseguir, digite a matr�cula do deputado: _______");
            moveto(dimension->colunas/2 + 9,7);
            fgets(matricula,9,stdin);
            limpaNovaLinha(matricula);
            limpaLinha(dimension,8);
        } while (validaMatricula(matricula,dimension,'P') == false);
        limpaLinha(dimension,8);
        matriculaInteiro=atoi(matricula);
        posicaoArquivo = verificaUnicidadeMatricula(matriculaInteiro,dimension);
        if (posicaoArquivo == -1)
        {
            centerPrint(">> Matr�cula n�o cadastrada, deseja reiniciar a edi��o de dados (S/N): _ <<",dimension,9,0);
            moveto(dimension->colunas/2 + 33,9);
            opcao = getch();
            opcao = validaOpcaoEdicao(opcao,dimension);
        }
        else
        {
            pArquivo = fopen("camara.bin","a+b");
            validaAberturaArquivo(pArquivo,dimension);
            fseek(pArquivo,(posicaoArquivo-1)*sizeof(infoDeputado),SEEK_SET);
            if (fread(&tempDeputado,sizeof(infoDeputado),1,pArquivo) == 1)
            {
                limpaLinha(dimension,12);
                limpaLinha(dimension,14);
                limpaLinha(dimension,16);
                moveto(dimension->colunas/12,12);
                printf("Nome Completo: %s",tempDeputado.nome);
                moveto(dimension->colunas/12,14);
                printf("Sigla do Partido: %s",tempDeputado.siglaPartido);
                moveto(dimension->colunas/12,16);
                printf("Sexo (M-Masculino/F-Feminino): %c",tempDeputado.sexo);
            }
            else
                erroLerArquivo(dimension);
            fclose(pArquivo);
            limpaLinha(dimension,9);
            centerPrint("> > > Confirme caso queira alterar o NOME da(o) deputada(o) (S/N) ? _",dimension,9,0);
            moveto(dimension->colunas/2 + 33,9);
            opcao = getch();
            opcao = validaOpcaoEdicao(opcao,dimension);
            if (opcao == 'S')
            {
                alteraNome(tempDeputado.nome,dimension);
                limpaLinha(dimension,12);
                moveto(dimension->colunas/12,12);
                printf("Nome Completo: %s",tempDeputado.nome);
            }
            limpaLinha(dimension,9);
            centerPrint("> > > Confirme caso queira alterar a SIGLA da(o) deputada(o) (S/N) ? _",dimension,9,-1);
            moveto(dimension->colunas/2 + 33,9);
            opcao = getch();
            opcao = validaOpcaoEdicao(opcao,dimension);
            if (opcao == 'S')
            {
                alteraSigla(tempDeputado.siglaPartido,dimension);
                limpaLinha(dimension,14);
                moveto(dimension->colunas/12,14);
                printf("Sigla do Partido: %s",tempDeputado.siglaPartido);
            }
            limpaLinha(dimension,9);
            centerPrint("> > > Confirme caso queira alterar o SEXO da(o) deputada(o) (S/N) ? _",dimension,9,0);
            moveto(dimension->colunas/2 + 33,9);
            opcao = getch();
            opcao = validaOpcaoEdicao(opcao,dimension);
            if (opcao == 'S')
            {
                alteraSexo(&tempDeputado.sexo,dimension);
                limpaLinha(dimension,16);
                moveto(dimension->colunas/12,16);
                printf("Sexo: %c",tempDeputado.sexo);
            }
            if (removeCadastroArquivo(&tempDeputado,pArquivo,dimension) == false || gravaCadastro(&tempDeputado,pArquivo,dimension) == false)
            {
                opcao = 'S';
                continue; 
            }
            limpaLinha(dimension,9);
            centerPrint("> > > Confirme caso queria CONTINUAR editando cadastros (S/N): _",dimension,9,2);
            moveto(dimension->colunas/2 + 33,9);
            opcao = getch();
            opcao = validaOpcaoEdicao(opcao,dimension);
        }
    } while (opcao != 'N');
}

//Objetivo: Alterar o sexo de um cadastro de deputado.
//Parametros: Sexo e dimens�es da tela.
//Retorno: Nenhum.
void alteraSexo (char * sexo, Window * dimension)
{
    do {
        limpaLinha(dimension,16);
        moveto(dimension->colunas/12,16);
        printf("Digite o sexo (M/F): _");
        moveto(dimension->colunas/12 + 21,16);
        *sexo = getch();
    } while (validaAlteraSexo(*sexo,dimension) == false);
}

//Objetivo: Alterar a sigla no modo edi��o de deputados.
//Parametros: Sigla do partido e dimens�es da tela.
//Retorno: Nenhum. 
void alteraSigla (char * sigla,Window * dimension)
{
   do {
        limpaLinha(dimension,14);
        moveto (dimension->colunas/12,14);
        printf("Digite a sigla do partido: __________");
        moveto (dimension->colunas/12 + 27,14);
        fflush (stdin);
        fgets (sigla,TAMANHOSIGLA,stdin);
        limpaNovaLinha(sigla);
    } while (validaAlteraSigla (sigla,dimension) == false);
}

//Objetivo: Alterar o nome no modo edi��o de deputados.
//Parametros: Nome e dimens�es da tela.
//Retorno: Nenhum.
void alteraNome (char * nome, Window * dimension)
{
    int contador;
    do {
        limpaLinha(dimension,12);
        moveto(dimension->colunas/12,12);
        printf("Nome Completo: ");
        for (contador=0;contador<TAMANHONOME;contador++)
            printf("_");
        moveto(dimension->colunas/12 + 15,12);
        fflush(stdin);
        fgets(nome,TAMANHONOME,stdin);
        limpaNovaLinha(nome);
    } while (validaAlteraNome (nome,dimension) == false);
    formataNome(nome);
}

//Objetivo: Calcular a m�dia das idades dos deputados cadastrados.
//Parametros: Dimens�es da tela.
//Retorno: M�dia das idades.
float calculaMediaIdades(Window * dimension)
{
    FILE * pArquivo;
    infoDeputado tempDeputado;
    float somaIdades=0;
    int cadastros = quantidadeCadastrosArquivo(pArquivo,dimension);

    pArquivo = fopen("camara.bin","a+b");
    validaAberturaArquivo(pArquivo,dimension);
    rewind(pArquivo);
    while (!feof(pArquivo) && fread (&tempDeputado,sizeof(infoDeputado),1,pArquivo)== 1)
    {
        if (ferror (pArquivo) == 0)
            somaIdades+=tempDeputado.idade;
    }
    fclose (pArquivo);
    return somaIdades/cadastros;
}

//Objetivo: Gerenciar o acesso das p�ginas do relat�rio dos deputados.
//Parametros: Dimens�es da tela.
//Retorno: P�gina a ser acessada.
int controlaPagina(Window *dimension)
{
    char paginaPesquisada[4];
    FILE *pArquivo;
    int cadastros=quantidadeCadastrosArquivo(pArquivo,dimension),paginaMax=cadastros/19;
    if (cadastros % 19 > 0)
        paginaMax++;
    centerPrint("Digite S para sair ou pagina que deseja acessar: __",dimension,dimension->linhas -1,0);
    centerPrint("Pagina atual:",dimension,dimension->linhas -2,-5);
    moveto(dimension->colunas/2 +5,dimension->linhas -2);
    printf("de %d.",paginaMax);
    moveto(dimension->colunas/2+23,dimension->linhas -1);
    fflush(stdin);
    fgets(paginaPesquisada,4,stdin);
    limpaNovaLinha(paginaPesquisada);
    return validaPagina(paginaPesquisada,paginaMax,dimension);
}

//Objetivo: Formatar o nome do deputado(remover espa�os duplos e tornar-lo "CamelCase").
//Parametros: Nome.
//Retorno: Nenhum.
void formataNome (char * nome)
{
    char nomeFormatado[TAMANHONOME];
    int indice=0,indice2,tamanhoString=strlen(nome),quantidadeEspacos,contador=0;
    do {
        if(nome[indice] == ' ')
        {
            quantidadeEspacos=0;
            for(indice2=indice; nome[indice2] == ' ' && indice2<tamanhoString;indice2++)
                quantidadeEspacos++;
            if (quantidadeEspacos>1)
            {
                indice = indice2-1;
            }
        }
        nomeFormatado[contador] = tolower(nome[indice]);
        contador++;
        indice++;
    } while (indice <tamanhoString);
    nomeFormatado[contador]='\0';
    tamanhoString=strlen(nomeFormatado);
    nomeFormatado[0]=toupper(nomeFormatado[0]);
    indice=0;
    do {
        if(nomeFormatado[indice] == ' ' && nomeFormatado[indice+1] != '\0')
            nomeFormatado[indice+1]=toupper(nomeFormatado[indice+1]);
        indice++;
    } while (indice < tamanhoString);
    strcpy(nome,nomeFormatado);
}

//Objetivo: Remover o arquivo de dados.
//Parametros: Dimens�es da tela.
//Retorno: Nenhum.
void removerArquivo (Window * dimension)
{
    char opcao;
    FILE * pArquivo;

    centerPrint("*  *   *   *   *   *   *   *   *   *   *   *",dimension,8,0); 
    centerPrint("* BEM-VINDO A REMO��O DO ARQUIVO DE DADOS. *",dimension,9,0);
    centerPrint("*  *   *   *   *   *   *   *   *   *   *   *",dimension,10,0); 
    do {
    centerPrint("Digite S para SIM e N para N�O: _.",dimension,14,0);
    centerPrint("Deseja realmente apagar o arquivo de dados ?",dimension,13,0);
    moveto(dimension->colunas/2 +15,14);
    opcao=getche();
    } while(validaExluirArquivo(opcao,dimension)==false);
    if (opcao == 'S')
    {
        pArquivo = fopen("camara.bin","w+b");
        validaAberturaArquivo(pArquivo,dimension);
        fclose (pArquivo);
        centerPrint("->> CONFIRMADO apagar arquivo de dados. Digite algo para retornar ao menu.<<-",dimension,16,0);
        getch();
    }
    else
    {
        centerPrint("->> CANCELADO apagar arquivo de dados. Digite algo para retornar ao menu.<<-",dimension,16,0);
        getch(); 
    }
}

//Objetivo: Registrar o modo de impress�o do relat�rio dos deputados.
//Parametros: Dimens�es da tela.
//Retorno: Modo de impress�o ('D' ou 'C').
char registraModoImpressao(Window *dimension)
{
    char opcao;

    centerPrint("*  *   *   *   *   *   *   *   *   *   *   *",dimension,8,0); 
    centerPrint("* BEM-VINDO A LISTA DE DEPUTADOS CADASTRADOS *",dimension,9,0);
    centerPrint("*  *   *   *   *   *   *   *   *   *   *   *",dimension,10,0);
    centerPrint("-> Insira D para listar de maneira alfab�tica DECRESCENTE",dimension,12,0);
    centerPrint("-> Insira C para listar de maneira alfab�tica CRESCENTE",dimension,13,0);
    centerPrint("-> Digite sua op��o correspondente (D/C): _ <-",dimension,15,0);
    moveto (dimension->colunas/2 + 19,15);
    opcao = getche();
    return validaModoImpressao(opcao,dimension);
}

//Objetivo: Verificar a unicidade de uma matr�cula no arquivo.
//Parametros: Matricula a ser testada e dimens�es da tela.
//Retorno: Posi��o do registro com matr�cula coincidente ou -1 caso a matr�cula seja �nica.
int verificaUnicidadeMatricula(int matricula,Window *dimension)
{
    FILE * pArquivo;
    infoDeputado tempDeputado;
    int posicaoArquivo=0;

    pArquivo = fopen("camara.bin","a+b");
    validaAberturaArquivo(pArquivo,dimension);
    rewind(pArquivo);
    while (!feof(pArquivo) && fread (&tempDeputado,sizeof(infoDeputado),1,pArquivo)== 1)
    {
        posicaoArquivo ++;
        if (tempDeputado.matricula == matricula)
        {
            fclose(pArquivo);
            return posicaoArquivo;
        }
    }
    fclose(pArquivo);
    return -1;
}

//Objetivo: Calcular a quantidade de cadastros no arquivo.
//Parametros: Ponteiro do arquivo e dimens�es da tela.
//Retorno: Quantidade de cadastros no arquivo.
int quantidadeCadastrosArquivo(FILE *pArquivo,Window * dimension)
{
    long int tamanhoArquivo;
    pArquivo = fopen("camara.bin","a+b");
    validaAberturaArquivo (pArquivo,dimension);
    rewind(pArquivo);
    fseek (pArquivo , 0 , SEEK_END);
    tamanhoArquivo = ftell (pArquivo);
    fclose(pArquivo);
    return tamanhoArquivo/(int)sizeof(infoDeputado);
}

//Objetivo: Registrar a op��o de continua��o dos cadastros.
//Parametros: Dimens�es da tela.
//Retorno: Op��o do usu�rio.
char continuaCadastro (Window * dimension)
{
    char continuaCadastro;
    centerPrint("Deseja cadastrar mais deputados? _ (S-Sim & N-N�o)",dimension,22,0);
    moveto (dimension->colunas/2 + 8,22);
    continuaCadastro = getche();
    return validaContinuaCadastro(continuaCadastro,dimension);  
}

//Objetivo: Ordernar alfabeticamente os cadastros do arquivo em um vetor.
//Parametros: Dimens�es da tela e vetor dos deputados.
//Retorno: Nenhum.
void ordenaDeputados (Window * dimension,infoDeputado deputadosOrdenados[])
{
    int aux1, aux2,indice,indiceDeputado=0;
    infoDeputado tempDeputado;
    FILE *pArquivo;

    pArquivo = fopen("camara.bin","a+b");
    validaAberturaArquivo(pArquivo,dimension);
    rewind(pArquivo);

    while (!feof(pArquivo) && fread(&tempDeputado,sizeof(infoDeputado),1,pArquivo) == 1)
    {
        deputadosOrdenados[indiceDeputado]=tempDeputado;
        indiceDeputado ++;
    }
    fclose(pArquivo);
    indice = quantidadeCadastrosArquivo(pArquivo,dimension);
    for(aux1 = 0; aux1 < indice; aux1++){
        for(aux2 = 0; aux2 < (indice-1); aux2++){
            if(strcmp(deputadosOrdenados[aux2].nome,deputadosOrdenados[aux2+1].nome) > 0){
                tempDeputado = deputadosOrdenados[aux2];
                deputadosOrdenados[aux2] = deputadosOrdenados[aux2+1];
                deputadosOrdenados[aux2+1] = tempDeputado;
            }
        }
        indice--;
    }
}

//Objetivo: Arquivar um �nico cadastro no arquivo dos deputados.
//Parametros: Informa��es do deputado, ponteiro do arquivo e dimens�es da tela.
//Retorno: Em caso de sucesso verdadeiro, em caso de fracasso falso.
bool gravaCadastro (infoDeputado* deputado,FILE* pArquivo, Window * dimension)
{
    pArquivo = fopen("camara.bin","a+b");
    validaAberturaArquivo (pArquivo,dimension);

    if (fwrite(deputado,sizeof(infoDeputado),1,pArquivo) == 0 || ferror (pArquivo))
    {
        printArtboard(dimension);
        centerPrint("*  *   *   *   *   *   *   *   *   *   *   *   *   *   *",dimension,9,0);
        centerPrint("*   ERRO AO GRAVAR NO ARQUIVO, REINICIE O CADASTRO.    *",dimension,10,0);
        centerPrint("*  *   *   *   *   *   *   *   *   *   *   *   *   *   *",dimension,11,0);
        getch();
        fclose (pArquivo);
        printArtboard(dimension);
        return false;
    } 
    else //Arquivo cadastrado com sucesso
    {
        fclose (pArquivo);
        centerPrint(">> CADASTRO SALVO COM SUCESSO <<",dimension,20,0);
        return true;
    }
}

//Objetivo: Registrar informa��es v�lidas dos deputados na estrutura de dados.
//Parametros: Dados do deputado (vari�vel), dimens�es da tela e quantidade de cadastros.
//Retorno: Nenhum.
void cadastraDeputado (infoDeputado* deputado,Window * dimension,int cadastros)
{
    int contador;
    char idade[5], matricula [9];
    printArtboard(dimension);
    centerPrint("# BEM-VINDO AO CADASTRO DO DEPUTADO #",dimension,2,0);
    centerPrint("Este � o cadastro de n�mero:",dimension,3,-3);
    moveto(dimension->colunas/2 + 13,3);
    printf("%d",cadastros+1);
    if (cadastros <= 1)
        centerPrint("OBS:� necess�rio cadastrar ao menos 2 deputados.",dimension,4,0);
    else
        limpaLinha(dimension,4);

    // Esta � a tela base do cadastro.
    moveto (dimension->colunas/12,6);
    printf("Nome Completo: ");
    for (contador=0;contador<TAMANHONOME;contador++)
        printf("_");
    moveto (dimension->colunas/12,9);
    printf("Idade: ___");
    moveto (dimension->colunas/12,12);
    printf("Sexo (USAR M [Masculino] ou F [Feminino]: _");
    moveto (dimension->colunas/12,15);
    printf("Digite a sigla do partido: __________");
    moveto (dimension->colunas/12,18);
    printf ("Matricula (�nica e intransfer�vel): _______");

    do {
            limpaLinha(dimension,6);
            moveto (dimension->colunas/12,6);
            printf("Nome Completo: ");
            for (contador=0;contador<TAMANHONOME;contador++)
                printf("_");
            moveto (dimension->colunas/12 +15, 6);
            fflush (stdin);
            fgets (deputado->nome,TAMANHONOME,stdin);
            limpaNovaLinha(deputado->nome);
    } while (validaNome(deputado->nome,dimension) == FALSE);
    formataNome(deputado->nome);
    limpaLinha(dimension,6);
    moveto (dimension->colunas/12,6);
    printf("Nome Completo: %s.",deputado->nome);

    do {
            limpaLinha(dimension,9);
            moveto (dimension->colunas/12,9);
            printf("Idade: ___");
            moveto (dimension->colunas/12 +7, 9);
            fflush(stdin);
            fgets (idade,5,stdin);
            limpaNovaLinha (idade);
    } while (validaIdade (idade,dimension) == FALSE);
    deputado->idade = atoi(idade);
    limpaLinha(dimension,9);
    moveto (dimension->colunas/12,9);
    printf("Idade: %d.",deputado->idade);

    do {
            limpaLinha(dimension,12);
            moveto (dimension->colunas/12,12);
        	printf("Sexo (USAR M [Masculino] ou F [Feminino]: _");
        	moveto (dimension->colunas/12 +42,12);
            fflush(stdin);
        	deputado->sexo = getche();
    } while (validaSexo (&deputado->sexo,dimension) == FALSE);
    limpaLinha(dimension,12);
    moveto (dimension->colunas/12,12);
    printf("Sexo: ");
    if(deputado->sexo == 'M')
        printf("Masculino.");
    else
        printf("Feminino.");

    do {
            limpaLinha(dimension,15);
            moveto (dimension->colunas/12,15);
            printf("Digite a sigla do partido: __________");
            moveto (dimension->colunas/12 + 27,15);
            fflush (stdin);
            fgets (deputado->siglaPartido,TAMANHOSIGLA,stdin);
            limpaNovaLinha(deputado->siglaPartido);
    } while (validaSigla (deputado->siglaPartido,dimension)==FALSE);
    limpaLinha(dimension,15);
    moveto (dimension->colunas/12,15);
    printf("Sigla do Partido: %s.",deputado->siglaPartido);

    do {
            limpaLinha(dimension,18);
            moveto (dimension->colunas/12,18);
            printf ("Matr�cula (�nica e intransfer�vel): _______");
            moveto (dimension->colunas/12 + 36,18);
            fflush (stdin);
            fgets(matricula,9,stdin);
            limpaNovaLinha(matricula);
    } while (validaMatricula (matricula,dimension,'C') == FALSE);
    deputado->matricula = atoi(matricula);
    limpaLinha(dimension,18);
    moveto (dimension->colunas/12,18);
    printf("Matr�cula: %d.",deputado->matricula);
}

//Objetivo: Limpar a quebra de linha em strings.
//Parametros: String.
//Retorno: Nenhum.
void limpaNovaLinha(char *string)
{
    char *pos;
    if ((pos=strchr(string, '\n')) != NULL)
        *pos = '\0';
}

//====================FIM DOS SUBPROGRAMAS MISTOS=================

//========SUBPROGRAMAS DE VALIDA��O=============

//Objetivo: Verificar se as dimens�es do console est�o adequadas para o layout do programa.
//Parametros: Dimens�es do console. 
//Retorno: Verdadeiro (est�o adequadas) ou falso (est�o inadequadas).
bool validaTamanhoConsole (Window * dimension)
{
    if (dimension->colunas == LARGURACONSOLE-1 && dimension ->linhas == ALTURACONSOLE-1)
    {
        return true;
    }
    else
        return false;
}

//Objetivo: Determinar se a idade inserida � v�lida.
//Parametros: Idade e dimens�es da tela.
//Retorno: TRUE caso v�lido, FALSE caso inv�lido.
bool validaIdade (char *idade,Window *dimension)
{
    int contador, tamanhoString = strlen (idade),idadeInteiro;
    bool retorno=true;
    limpaLinha (dimension,10);
    moveto (dimension->colunas/12 +7, 10);
    if (tamanhoString == 0)
    {
        printf("Digite novamente, idade n�o pode estar vazia.");
        return false;
    }
    else
    {
        for(contador=0;contador<tamanhoString;contador++)
            if (idade [contador] > '9' || idade[contador] < '0')
                retorno=false;
        if (retorno == false)
        {
            printf("Digite novamente, idade deve conter somente n�meros.");
            return false;
        }
        else
        {
            idadeInteiro=atoi(idade);
            if (idadeInteiro < 18 || idadeInteiro > 150)
            {
                printf("Digite novamente, esta idade � inv�lida.");
                return false;
            } 
            else
            {
                limpaLinha (dimension,10);
                return true;
            }
        }
    }
}

//Objetivo: Determinar se o nome inserido � v�lido.
//Parametros: Nome.
//Retorno: TRUE caso v�lido, FALSE caso inv�lido.
bool validaNome(char *nome,Window * dimension)
{
    int indice,quantidadeEspacos=0;
    int tamanhoString = strlen(nome);
    int retorno=1;
    for (indice = 0; indice < tamanhoString; indice ++)
        if (nome [indice] == ' ')
            quantidadeEspacos ++;
    if (tamanhoString == quantidadeEspacos)
    {
        limpaLinha (dimension,7);
        moveto (dimension->colunas/12 +15, 7);
        printf("Digite novamente, nome n�o pode ser vazio.");
        limpaLinha (dimension,6);
        return FALSE;
    }
    else
    {
        for (indice=0;indice<tamanhoString;indice++)
            if ((isdigit(nome[indice]) == 1 && nome[indice] != ' ' )|| nome[indice] == '\t')
            {
                retorno=0;
                if (nome[indice] == '\t')
                    retorno=2;
            }

        if (retorno==1)
        {
            limpaLinha (dimension,7);
            return TRUE;   
        } 
        else if (retorno == 0)
        {
            moveto (dimension->colunas/12 +15, 7);
            printf("Digite novamente, nome deve conter somente letras.");
            limpaLinha (dimension,6);
            return false;
        }
        else if (retorno == 2)
        {
            moveto (dimension->colunas/12 +15, 7);
            printf("Digite novamente, nome n�o deve conter tabula��es.");
            limpaLinha (dimension,6);
            return false;
        }
    }                                                       
}

//Objetivo: Determinar se o caracter correspondente ao sexo inserido � valido.
//Parametros: Caracter correspondente ao sexo e dimens�es da tela.
//Retorno: TRUE caso v�lido, FALSE caso inv�lido.
bool validaSexo(char *sexo, Window * dimension)
{
    //*sexo=toupper(*sexo);
    switch (*sexo)
	{
		case 'f' :
        case 'm' :
            limpaLinha (dimension,12);
            moveto (dimension->colunas/12+42,13);
            printf("Digite novamente em mai�sculo.");
            return FALSE;
            break;
        case 'M' :
		case 'F' :
            limpaLinha (dimension,13);
            return TRUE;
			break;
		default :
            limpaLinha (dimension,12);
            moveto (dimension->colunas/12+42,13);
            printf("Digite novamente,sexo inv�lido.");
            return FALSE;
	}
}

//Objetivo: Determinar se a sigla do partido � valida.
//Parametros: Sigla do partido e dimens�es da tela.
//Retorno: TRUE caso v�lido, FALSE caso inv�lido.
bool validaSigla (char *sigla,Window * dimension)
{
    int aux;
	char validos[] = "ABCDEFGHIJKLMNOPQRSTUVXWYZ";
    char * procurados;
    int ocorrencias = 0;
    int tamanhoString = strlen(sigla);
    limpaLinha (dimension,16);
    if (tamanhoString == 0)
    {
        moveto (dimension->colunas/12 + 27,16);
        printf ("Digite novamente, campo de preenchimento obrigat�rio.");
        return FALSE;
    }
    else
    {
        for (aux=0;aux<tamanhoString;aux++)
            *(sigla+aux) = toupper(*(sigla+aux));
        procurados = strpbrk (sigla, validos);
        while (procurados != NULL)
        {
            ocorrencias ++;
            procurados = strpbrk (procurados+1,validos);
        }
        if (ocorrencias == tamanhoString && ocorrencias >= 2)
        {
            limpaLinha (dimension,16);
            return TRUE;
        }
        else
        {
            moveto (dimension->colunas/12 + 27,16);
            printf ("Digite novamente, a sigla digitada � inv�lida.");
            limpaLinha (dimension,15);
            return FALSE;
        }
    }
}

//Objetivo: Verificar se a matr�cula inserida � valida e �nica.
//Parametros: Matr�cula, dimens�es da tela e modo de valida��o (P-Pesquisa ou C-Cadastro).
//Retorno: TRUE caso v�lido, FALSE caso inv�lido.
bool validaMatricula (char * matricula,Window *dimension,char modo)
{
    int indice,contador,tamanhoString = strlen(matricula),ocorrencias=0,matriculaInteiro;
    FILE * pArquivo;
    int cadastros = quantidadeCadastrosArquivo (pArquivo,dimension);
    bool retorno=true;

    limpaLinha(dimension,19);
    if (modo == 'C')
        moveto (dimension->colunas/12 + 36,19);
    else
        moveto(dimension->colunas/6 + 9,8);
    if (tamanhoString==0)
    {
        printf("Digite novamente, matr�cula n�o pode ser vazio.");
        limpaLinha (dimension,18);
        return false;
    }
    else
    {
	    if (tamanhoString == 8)
        {
            printf("Digite novamente, matr�cula deve conter menos de 8 d�gitos.");
            limpaLinha (dimension,18);
            return false;
        }
        for(contador=0;contador<tamanhoString;contador++)
            if (matricula[contador] > '9' || matricula[contador] < '0')
                retorno=false;
        if (retorno == false)
        {
            printf("Digite novamente, a matr�cula deve conter somente n�meros.");
            limpaLinha (dimension,18);
            return false;
        }
        else if (atoi (matricula) > MINIMATRICULA)
        {
            matriculaInteiro = atoi(matricula);
            if (modo == 'C')
            {
                if (cadastros == 0)
                    return true;
                else if (verificaUnicidadeMatricula(matriculaInteiro,dimension) != -1)
                {
        	        printf("Digite novamente, n�o � poss�vel cadastrar matriculas iguais.");
                    limpaLinha (dimension,18);
                    return FALSE;
                }
                else
                    return true;
            }
            else if (modo = 'P')
                return true;
        }
        else
        {
            printf("Digite novamente, a matr�cula deve ser maior que %d.",MINIMATRICULA);
            limpaLinha (dimension,18);
            return false;
        }
	}
}

//Objetivo: Determinar se a op��o do menu � valida.
//Parametros: Op��o do menu e dimens�es da tela.
//Retorno: TRUE caso v�lido, FALSE caso inv�lido.
bool validaOpcao(char opcao, Window *dimension)
{
    switch (opcao)
    {
    	case '1' :
        case '2' :
        case '3' :
        case '4' :
        case '5' :
        case '0' :
            limpaLinha(dimension,21);
            return TRUE;
        default :
            moveto (dimension->colunas/2 +19,21);
            printf("Digite novamente, escolha inv�lida.");
            return FALSE;
    }
}

//Objetivo: Validar a op��o de continua��o do cadastro.
//Parametros: Op��o do usu�rio e dimens�es da tela.
//Retorno: Op��o validada.
char validaContinuaCadastro (char continua, Window * dimension)
{
    continua = toupper(continua);
    switch (continua)
    {
        case 'S' :
            moveto (dimension->colunas/2 + 8,22);
            printf("_");
            limpaLinha (dimension,23);
            return continua;
        case 'N' :
            moveto (dimension->colunas/2 + 8,22);
            printf("_");
            limpaLinha (dimension,23);
            return continua;
        default :
            centerPrint ("Digite novamente, escolha inv�lida.",dimension,23,0);
            moveto (dimension->colunas/2 + 8,22);
            printf("_");
            moveto (dimension->colunas/2 + 8,22);
            continua = getche();
            continua = validaContinuaCadastro (continua,dimension);
            return continua;
    }
}

//Objetivo: Validar a abertura do arquivo.
//Parametros: Ponteiro do arquivo e dimens�es da tela.
//Retorno: Nenhum.
void validaAberturaArquivo (FILE *pArquivo,Window*dimension)
{
    if (pArquivo == NULL)
    {
        printArtboard(dimension);
        centerPrint("*  *   *   *   *   *   *   *   *",dimension,9,0);
        centerPrint("*  ERRO AO ABRIR O ARQUIVO.    *",dimension,10,0);
        centerPrint("* >>> REINICIE O PROGRAMA. <<< *",dimension,11,0);
        centerPrint("*  *   *   *   *   *   *   *   *",dimension,12,0);
        moveto(dimension->colunas/2,20);
        getch();
    }
}

//Objetivo: Determinar se a op��o de excluir o arquivo � v�lida.
//Parametros: Op��o e dimens�es da tela.
//Retorno: Verdadeiro caso v�lido, falso caso inv�lido.
bool validaExluirArquivo (char opcao,Window *dimension)
{
    switch (opcao)
    {
        case 'N' :
        case 'S' :
            limpaLinha(dimension,15);
            return true;
        default :
            centerPrint("Digite novamente, escolha inv�lida.",dimension,15,0);
            return false;
    }
}

//Objetivo: Validar o modo de impress�o do relat�rio dos deputados.
//Parametros: Op��o do modo e dimens�es da tela.
//Retorno: Modo de impress�o validado.
char validaModoImpressao (char opcao,Window *dimension)
{
    limpaLinha(dimension,16);
    switch (opcao)
    {
        case 'd' :
        case 'c' :
            centerPrint("Op��o inv�lida, digite em mai�sculo.",dimension,16,0);
            moveto (dimension->colunas/2 + 19,15);
            printf("_");
            return registraModoImpressao(dimension);
        case 'D' :  
        case 'C' :
            limpaLinha (dimension,16);
            return opcao;
        default :
            centerPrint("Op��o inv�lida, digite novamente.",dimension,16,0);
            moveto (dimension->colunas/2 + 19,15);
            printf("_");
            return registraModoImpressao(dimension);
    }
}

//Objetivo: Validar a p�gina inserida.
//Parametros: P�gina, p�gina m�xima e dimens�es da tela.
//Retorno: P�gina validada.
int validaPagina(char* paginaPesquisada,int paginaMax,Window* dimension)
{
    int tamanhoString = strlen(paginaPesquisada),contador,paginaInteiro;
    if (tamanhoString == 0)
    {
        limpaLinha(dimension,dimension->linhas -1);
        moveto(dimension->colunas/2 + 27,dimension->linhas -1);
        printf("<P�gina n�o pode estar vazia>    ");
        return controlaPagina(dimension);
    }
    else if (tamanhoString == 1 && toupper(paginaPesquisada[0]) == 'S')
    {
        limpaLinha(dimension,dimension->linhas -1);
        return 0;
    }
    else
    {
        for(contador=0;contador<tamanhoString;contador++)
            if(isdigit(paginaPesquisada[contador]) == 0)
            {
                limpaLinha(dimension,dimension->linhas -1);
                moveto(dimension->colunas/2 + 27,dimension->linhas -1);
                printf("<P�gina n�o pode conter letras>");
                return controlaPagina(dimension);
            }
        paginaInteiro = atoi(paginaPesquisada);
        if (paginaInteiro >= 1 && paginaInteiro <= paginaMax)
        {
            limpaLinha(dimension,dimension->linhas -1);
            return paginaInteiro;
        }
        else
        {
            limpaLinha(dimension,dimension->linhas -1);
            moveto(dimension->colunas/2 + 27,dimension->linhas -1);
            printf("<P�gina inv�lida>              ");
            return controlaPagina(dimension);
        }
    }
}

//Objetivo: Validar a op��o do menu de edi��o.
//Parametros: Op��o e dimens�es da tela.
//Retorno: Op��o validada.
char validaOpcaoEdicao (char opcao, Window * dimension)
{
    switch (opcao)
    {
        case 's' :
        case 'n' :
            limpaLinha(dimension,10);
            centerPrint ("Digite novamente em mai�sculo.",dimension,10,0);
            moveto(dimension->colunas/2 + 33,9);
            opcao = getch();
            opcao = validaOpcaoEdicao(opcao,dimension);
            break;
        case 'S' :
        case 'N' :
            limpaLinha(dimension,10);
            return opcao;
        default :
            limpaLinha(dimension,10);
            centerPrint ("Digite novamente, op��o inv�lida.",dimension,10,0);
            moveto(dimension->colunas/2 + 33,9);
            opcao = getch();
            opcao = validaOpcaoEdicao(opcao,dimension);
    }
}

//Objetivo: Determinar se o sexo a ser alterado no modo de edi��o � v�lido.
//Parametros: Sexo e dimens�es da tela.
//Retorno: Verdadeiro caso v�lido, falso caso inv�lido.
bool validaAlteraSexo (char sexo,Window * dimension)
{
    switch (sexo)
    {
        case 'f' :
        case 'm' :
            limpaLinha(dimension,17);
            moveto(dimension->colunas/12 + 21,17);
            printf("Sexo inv�lido, digite novamente em mai�sculo.");
            return false;
        case 'F' :
        case 'M' :
            limpaLinha(dimension,17);
            return true;
        default :
            limpaLinha(dimension,17);
            moveto(dimension->colunas/12 + 21,17);
            printf("Sexo inv�lido, digite novamente.");
            return false;
    }
}

//Objetivo: Determinar se a sigla a ser alterada no modo de edi��o � v�lida.
//Parametros: Sigla do partido e dimens�es da tela.
//Retorno: Verdadeiro caso v�lido, falso caso inv�lido.
bool validaAlteraSigla (char * sigla,Window * dimension)
{
    int aux;
    char validos[] = "ABCDEFGHIJKLMNOPQRSTUVXWYZ";
    char * procurados;
    int ocorrencias = 0;
    int tamanhoString = strlen(sigla);
    limpaLinha (dimension,15);
    if (tamanhoString == 0)
    {
        limpaLinha (dimension,15);
        moveto (dimension->colunas/12 + 27,15);
        printf ("Digite novamente, campo de preenchimento obrigat�rio.");
        return FALSE;
    }
    else
    {
        for (aux=0;aux<tamanhoString;aux++)
            *(sigla+aux) = toupper(*(sigla+aux));
        procurados = strpbrk (sigla, validos);
        while (procurados != NULL)
        {
            ocorrencias ++;
            procurados = strpbrk (procurados+1,validos);
        }
        if (ocorrencias == tamanhoString && ocorrencias >= 2)
        {
            limpaLinha (dimension,15);
            return TRUE;
        }
        else
        {
            limpaLinha (dimension,15);
            moveto (dimension->colunas/12 + 27,15);
            printf ("Digite novamente, a sigla digitada � inv�lida.");
            return FALSE;
        }
    }
}

//Objtivo: Determinar se o nome a ser alterado no modo de edi��o � v�lido.
//Parametros: Nome e dimens�es da tela.
//Retorno: Verdadeiro caso v�lido, falso caso inv�lido.
bool validaAlteraNome (char * nome,Window * dimension)
{
    int indice,quantidadeEspacos=0;
    int tamanhoString = strlen(nome);
    int retorno=1;
    for (indice = 0; indice < tamanhoString; indice ++)
        if (nome [indice] == ' ')
            quantidadeEspacos ++;
    if (tamanhoString == quantidadeEspacos)
    {
        moveto (dimension->colunas/12 +15, 13);
        printf("Digite novamente, nome n�o pode ser vazio.");
        return FALSE;
    }
    else
    {
        for (indice=0;indice<tamanhoString;indice++)
            if ((isdigit(nome[indice]) == 1 && nome[indice] != ' ' )|| nome[indice] == '\t')
            {
                retorno=0;
                if (nome[indice] == '\t')
                    retorno=2;
            }

        if (retorno==1)
        {
            limpaLinha (dimension,7);
            return TRUE;   
        } 
        else if (retorno == 0)
        {
            moveto (dimension->colunas/12 +15, 13);
            printf("Digite novamente, nome deve conter somente letras.");
            return false;
        }
        else if (retorno == 2)
        {
            moveto (dimension->colunas/12 +15, 13);
            printf("Digite novamente, nome n�o deve conter tabula��es.");
            return false;
        }
    }
}

//======FIM DOS SUBPROGRAMAS DE VALIDA��O=============
