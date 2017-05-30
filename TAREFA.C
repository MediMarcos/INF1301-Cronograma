
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

/*****  Dados encapsulados no módulo  *****/ 
tpElemTarefa * pTRF = NULL;
/***** Protótipos das funções encapuladas no módulo *****/

  static void TRF_Bonding ( void * esp);
/*****  Código das funções exportadas pelo módulo  *****/



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
	 printf("\nCódigo:   %d",tar->codigo);
	 printf("\nDuração:  %d dias",tar->duracao);
	 printf("\nDescrição:%s",tar->descricao);
	 if(tar->Recurso != NULL)
	 {
		 printf("\nRecurso");
		 REC_ImprimirDados(tar->Recurso);
	 }
	 return TRF_CondRetOK;
 }

 

/*****  Código das funções encapsuladas pelo módulo  *****/

/********** Fim do módulo de implementação: Módulo tarefa **********/

