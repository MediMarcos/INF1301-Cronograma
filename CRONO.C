/***************************************************************************
*  $MCI Módulo de implementação: Módulo árvore
*
*  Arquivo gerado:              ARVORE.C
*  Letras identificadoras:      ARV
*
*  Nome da base de software:    Exemplo de teste automatizado
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\SIMPLES.BSW
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: avs - Arndt von Staa
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       3.00   avs   28/02/2003 Uniformização da interface das funções e
*                               de todas as condições de retorno.
*       2.00   avs   03/08/2002 Eliminação de código duplicado, reestruturação
*       1.00   avs   15/08/2001 Início do desenvolvimento
*
***************************************************************************/

#include   <malloc.h>
#include   <stdio.h>

#define CRONO_OWN
#include "CRONO.H"
#undef CRONO_OWN

#include "LISTA.H"
#include"TAREFA.H"
#include"RECURSO.H"
#include"DATA.H"

/***********************************************************************
*
*  $TC Tipo de dados: ARV Descritor do nó da árvore
*
*
*  $ED Descrição do tipo
*     Descreve a organização do nó
*
***********************************************************************/

   typedef struct tgCrono {

	   char * nome;
	   int dataInicio;
	   LIS_tppLista lisTarefas;
	   LIS_tppLista lisRecursos;


     
   } tpCrono ;





/*****  Dados encapsulados no módulo  *****/

      static tpCrono * Crono = NULL;
            /* Ponteiro para a cabe‡a da árvore */

/***** Protótipos das funções encapuladas no módulo *****/

   static tpCrono * CriarCronograma( char * nome ) ;

   static void LiberarEspaco(void * espaco);

   static LIS_tpCondRet conLis = LIS_CondRetOK;

   static REC_tpCondRet conRec = REC_CondRetOK;

   static TRF_tpCondRet conTrf = TRF_CondRetOK;

   static DATA_tpCondRet conDat = DATA_CondRetOK;

   //static ARV_tpCondRet CriarNoRaiz( char ValorParm ) ;

   //static void DestroiArvore( tpNoArvore * pNo ) ;

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: ARV Criar cronograma
*  ****/

   CRN_tpCondRet CRN_CriarCronograma (char * nome , int dataInicio)
   {
	   Crono = (tpCrono*)malloc(sizeof(tpCrono));
	   if(Crono == NULL)
		   return CRN_CondRetFaltouMemoria;
	   Crono->dataInicio = dataInicio;
	   Crono->lisRecursos = LIS_CriarLista(LiberarEspaco);
	   Crono->lisTarefas = LIS_CriarLista(LiberarEspaco);
	   Crono->nome = nome;
	   return CRN_CondRetOK;
   }

   CRN_tpCondRet CRN_InserirRecurso(int matr , char * nome)
   {
	   tpElemRecurso * rec;
	   if(REC_CriarRecurso(matr,nome)==REC_CondRetOK)
		   rec = RetornaPonteiro(matr);
	   LIS_InserirElementoApos(Crono->lisRecursos,rec);

	   if(LIS_ProcurarValor( Crono->lisRecursos , rec ) == LIS_CondRetOK)
		   return CRN_CondRetOK;
   }
   



/*****  Código das funções encapsuladas no módulo  *****/


   void LiberarEspaco(void * espaco)
   {
	   free(espaco);
   }


   int CRN_BuscaRecurso( int matr , char * nome )
   {
	   IrInicioLista( Crono->lisRecursos );
	   while(LIS_ObterValor(Crono->lisRecursos) != NULL)
	   {
		   LIS_AvancarElementoCorrente(Crono->lisRecursos , 1);

	   }

   }

/***********************************************************************
*
*  $FC Função: ARV Criar nó da árvore
*
*  $FV Valor retornado
*     Ponteiro para o nó criado.
*     Será NULL caso a memória tenha se esgotado.
*     Os ponteiros do nó criado estarão nulos e o valor é igual ao do
*     parâmetro.
*
***********************************************************************

   tpNoArvore * CriarNo( char ValorParm )
   {

      tpNoArvore * pNo ;

      pNo = ( tpNoArvore * ) malloc( sizeof( tpNoArvore )) ;
      if ( pNo == NULL )
      {
         return NULL ;
      } /* if /

      pNo->pNoPai = NULL ;
      pNo->pNoEsq = NULL ;
      pNo->pNoDir = NULL ;
      pNo->Valor  = ValorParm ;
      return pNo ;

   } /* Fim função: ARV Criar nó da árvore */




/********** Fim do módulo de implementação: Módulo árvore **********/

