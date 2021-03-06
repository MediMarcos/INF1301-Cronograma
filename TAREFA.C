
#include   <malloc.h>
#include   <stdio.h>
#include   <string.h>
#include "RECURSO.H"
#define TAREFA_OWN
#include "TAREFA.H"
#undef TAREFA_OWN

   
typedef struct tgElemTarefa{

	int codigo;
	char * descricao;
	tpElemRecurso * Recurso;
	void * ListPredecessoras;
	void * ListaSucessoras;
	int dataMaisCedo;
	int dataMaisTarde;
	int folga;
	int duracao;


}tpElemTarefa;

/*****  Dados encapsulados no m�dulo  *****/ 
tpElemTarefa * pTRF = NULL;
/***** Prot�tipos das fun��es encapuladas no m�dulo *****/

  static void TRF_Bonding ( void * esp);
/*****  C�digo das fun��es exportadas pelo m�dulo  *****/



TRF_tpCondRet TRF_CriaTarefa ( int cod , char * desc, int tempo)
{
	if (pTRF != NULL)
	{
		TRF_ExcluirTarefa();
	}
	pTRF = (tpElemTarefa *)malloc(sizeof(tpElemTarefa));
	if (pTRF==NULL)
	{
		return TRF_CondRetNaoCriouTarefa;
	}
	pTRF->codigo = cod;
	pTRF->descricao = desc;
	pTRF->duracao = tempo;
	pTRF->Recurso=NULL;
	pTRF->ListPredecessoras=NULL;
	pTRF->ListaSucessoras=NULL;
	pTRF->folga=0;
	pTRF->dataMaisCedo=0;
	pTRF->dataMaisTarde=0;
	return TRF_CondRetOK;
}
 TRF_tpCondRet TRF_AlteraDescTarefa (int cod , char * desc)
 {
	 if (pTRF==NULL)
	 {
		 return TRF_CondRetNaoCriouTarefa;
	 }
	 if(pTRF->codigo == cod)
	 {
		 strcpy(pTRF->descricao,desc);
		 return TRF_CondRetOK;
	 }
	 return TRF_CondRetTarefaNaoExiste;
 }
 TRF_tpCondRet TRF_AlteraDuracao(int cod, int tempo)
 {
	 if ( pTRF == NULL )
	 {
		 return TRF_CondRetNaoCriouTarefa;
	 }
	 if ( pTRF->codigo == cod )
	 {
		 pTRF->duracao = tempo;
		 return TRF_CondRetOK;
	 }
	 return TRF_CondRetTarefaNaoExiste;
 }

 TRF_tpCondRet TRF_ConsultarTarefa (int cod)
 {
	 if (pTRF==NULL)
	 {
		 return TRF_CondRetNaoCriouTarefa;
	 }
	 if (pTRF->codigo != cod)
	 {
		 return TRF_CondRetTarefaNaoExiste;
	 }
	 if ( pTRF->Recurso == NULL)
	 {
		 return TRF_CondRetTrfSemRecurso ;
	 }
	 return TRF_CondRetTrfComRecurso;
 }
 void TRF_ExcluirTarefa(void)
 {
	 if (pTRF->Recurso!=NULL)
	 {
		 REC_ExcluirRecurso();
	 }
	 free (pTRF);
 }
 
 TRF_tpCondRet TRF_InsereRecurso( int matr , char * nome )
 {
	 if ( pTRF->Recurso != NULL )
	 {
		 REC_ExcluirRecurso();
	 }
	 if ( REC_CriarRecurso( matr , nome ) == REC_CondRetOK )
	 {
		 pTRF->Recurso = RetornaPonteiro(matr);
		 return TRF_CondRetOK;
	 }
	 return TRF_CondRetNaoAlocouRecurso;
 }
 TRF_tpCondRet TRF_RetiraRecurso(void)
 {
	 REC_ExcluirRecurso;
	 pTRF->Recurso = NULL;
	 return TRF_CondRetOK;
 }

 tpElemTarefa * TRF_RetornaPonteiro(void)
 {
	 return pTRF;
 }

 TRF_tpCondRet TRF_ImprimirDados ( tpElemTarefa * tar )
 {
	 printf("\nC�digo:   %d",tar->codigo);
	 printf("\nDura��o:  %d dias",tar->duracao);
	 printf("\nDescri��o:%s",tar->descricao);
	 if(tar->Recurso != NULL)
	 {
		 printf("\nRecurso");
		 REC_ImprimirDados(tar->Recurso);
	 }
	 return TRF_CondRetOK;
 }

 

/*****  C�digo das fun��es encapsuladas pelo m�dulo  *****/

/********** Fim do m�dulo de implementa��o: M�dulo tarefa **********/

