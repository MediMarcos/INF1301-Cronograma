/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo �rvore
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
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*       3.00   avs   28/02/2003 Uniformiza��o da interface das fun��es e
*                               de todas as condi��es de retorno.
*       2.00   avs   03/08/2002 Elimina��o de c�digo duplicado, reestrutura��o
*       1.00   avs   15/08/2001 In�cio do desenvolvimento
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
*  $TC Tipo de dados: ARV Descritor do n� da �rvore
*
*
*  $ED Descri��o do tipo
*     Descreve a organiza��o do n�
*
***********************************************************************/

   typedef struct tgCrono {

	   char * nome;
	   int dataInicio;
	   LIS_tppLista lisTarefas;
	   LIS_tppLista lisRecursos;


     
   } tpCrono ;





/*****  Dados encapsulados no m�dulo  *****/

      static tpCrono * Crono = NULL;
            /* Ponteiro para a cabe�a da �rvore */
	  //static tpElemRecurso * recGlobal = NULL;

/***** Prot�tipos das fun��es encapuladas no m�dulo *****/

   static tpCrono * CriarCronograma( char * nome ) ;

   static void LiberarEspaco(void * espaco);

   static LIS_tpCondRet conLis = LIS_CondRetOK;

   static REC_tpCondRet conRec = REC_CondRetOK;

   static TRF_tpCondRet conTrf = TRF_CondRetOK;

   static DATA_tpCondRet conDat = DATA_CondRetOK;

   //static ARV_tpCondRet CriarNoRaiz( char ValorParm ) ;

   //static void DestroiArvore( tpNoArvore * pNo ) ;

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/

/***************************************************************************
*
*  Fun��o: ARV Criar cronograma
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
	   tpElemRecurso * recIns;
	   if(REC_CriarRecurso(matr,nome)==REC_CondRetOK)
		   recIns = RetornaPonteiro(matr);
	   LIS_InserirElementoApos(Crono->lisRecursos,recIns);
	   if(LIS_ProcurarValor( Crono->lisRecursos , recIns ) == LIS_CondRetOK)
		   return CRN_CondRetOK;
	   return CRN_CondRetNaoInseriuRecurso;
   } 
/*****  C�digo das fun��es encapsuladas no m�dulo  *****/


   void LiberarEspaco(void * espaco)
   {
	   free(espaco);
   }


   CRN_tpCondRet CRN_BuscaRecurso( int matr )
   {
	   REC_tpCondRet cond = REC_CondRetRecursoNaoExiste;
	   LIS_tpCondRet ret = LIS_CondRetOK;
	   tpElemRecurso * r;
	   IrInicioLista(Crono->lisRecursos);
	   //r = (tpElemRecurso*)LIS_ObterValor(Crono->lisRecursos);
	   while(cond != REC_CondRetOK && ret != LIS_CondRetFimLista )
	   {
		   r = (tpElemRecurso*)LIS_ObterValor(Crono->lisRecursos);
		   REC_ImprimirDados (r);
		   cond = REC_ValidaMatricula( r , matr );
		   ret = LIS_AvancarElementoCorrente(Crono->lisRecursos,2);
		   
	   }
	   if(ret = LIS_CondRetFimLista )
	   {
		   return CRN_CondRetNaoAchouRecurso;
	   }
	   return CRN_CondRetOK;


   }

/***********************************************************************
*
*  $FC Fun��o: ARV Criar n� da �rvore
*
*  $FV Valor retornado
*     Ponteiro para o n� criado.
*     Ser� NULL caso a mem�ria tenha se esgotado.
*     Os ponteiros do n� criado estar�o nulos e o valor � igual ao do
*     par�metro.
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

   } /* Fim fun��o: ARV Criar n� da �rvore */




/********** Fim do m�dulo de implementa��o: M�dulo �rvore **********/

