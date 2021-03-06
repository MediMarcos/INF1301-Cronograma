#if ! defined( DATA_ )
#define DATA_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo �rvore
*
*  Arquivo gerado:              ARVORE.H
*  Letras identificadoras:      ARV
*
*  Nome da base de software:    Exemplo de teste automatizado
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\SIMPLES.BSW
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: avs - Arndt von Staa
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*       3.00   avs   28/02/2003 Uniformiza��o da interface das fun��es e
*                               de todas as condi��es de retorno.
*       2.00   avs   03/08/2002 Elimina��o de c�digo duplicado, reestrutura��o
*       1.00   avs   15/08/2001 In�cio do desenvolvimento
*
*  $ED Descri��o do m�dulo
*     Este m�dulo implementa um conjunto simples de fun��es para criar e
*     explorar �rvores bin�rias.
*     A �rvore possui uma cabe�a que cont�m uma refer�ncia para a ra�z da
*     �rvore e outra para um n� corrente da �rvore.
*     A cada momento o m�dulo admite no m�ximo uma �nica �rvore.
*     Ao iniciar a execu��o do programa n�o existe �rvore.
*     A �rvore poder� estar vazia. Neste caso a raiz e o n� corrente
*     ser�o nulos, embora a cabe�a esteja definida.
*     O n� corrente ser� nulo se e somente se a �rvore estiver vazia.
*
***************************************************************************/
 
#if defined( DATA_OWN )
   #define DATA_EXT
#else
   #define DATA_EXT extern
#endif


/***********************************************************************
*
*  $TC Tipo de dados: ARV Condicoes de retorno
*
*
***********************************************************************/

   typedef enum {

         DATA_CondRetOK                   = 0 ,

         DATA_CondRetPrimMaisRecente      = 1 ,
		 
		 DATA_CondRetPrimMaisTarde        = 2 ,
		 
		 DATA_CondRetFaltouMemoria        = 3 ,

		 DATA_CondRetFormatoIncorretoPrim = 4 ,

		 DATA_CondRetFormatoIncorretoSeg  = 5

   } DATA_tpCondRet ;


/***********************************************************************
*
*  $FC Fun��o: ARV Criar �rvore
*
*  $ED Descri��o da fun��o
*     Cria uma nova �rvore vazia.
*     Caso j� exista uma �rvore, esta ser� destru�da.
*
*  $FV Valor retornado
*     ARV_CondRetOK
*     ARV_CondRetFaltouMemoria
*
***********************************************************************/

   DATA_tpCondRet DATA_CompararData (int d1 , int d2) ;

   int DATA_DiferencaEmDias(int d1 , int d2);

   void DATA_ImprimirData(int d);




#undef DATA_EXT

/********** Fim do m�dulo de defini��o: M�dulo �rvore **********/

#else
#endif
