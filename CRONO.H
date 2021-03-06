#if ! defined( CRONO_ )
#define CRONO_
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
 
#if defined( CRONO_OWN )
   #define CRONO_EXT
#else
   #define CRONO_EXT extern
#endif


/***********************************************************************
*
*  $TC Tipo de dados: ARV Condicoes de retorno
*
*
***********************************************************************/

   typedef enum {

         CRN_CondRetOK = 0 ,
               /* Executou correto */

		CRN_CondRetFaltouMemoria = 5 ,

		CRN_CondRetNaoAchouRecurso = 2 ,

		CRN_CondRetNaoInseriuRecurso =3


   } CRN_tpCondRet ;


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

   //ARV_tpCondRet ARV_CriarArvore( void ) ;
   CRN_tpCondRet CRN_CriarCronograma (char * nome , int dataInicio);
   CRN_tpCondRet CRN_InserirRecurso(int matr , char * nome);
   CRN_tpCondRet CRN_BuscaRecurso( int matr );





#undef CRONO_EXT

/********** Fim do m�dulo de defini��o: M�dulo �rvore **********/

#else
#endif
