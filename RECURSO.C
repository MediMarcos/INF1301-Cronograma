/***************************************************************************
*	$MCI Módulo de implementação: Módulo recurso
*
*	Arquivo gerado:					RECURSO.C
*	Letras identificadoras:			REC
*
*	Projeto:	Disciplina  INF1301
*	Gestor:		Flávio Bevilaquia
*	Autores:    mmp - Marcos Porto, Matheus Santana e Pedro Moraes
*
*	$HA Histórico de evolução:
*	   Versão	Autor		Data		Observações
*		1.00	mmp			22/04/2017  Início do desenvolvimento
*
*
****************************************************************************/

#include   <malloc.h>
#include   <stdio.h>
#include   <string.h>

#define RECURSO_OWN
#include "RECURSO.H"
#undef RECURSO_OWN

#define N 15
/**************************************************************************
*
*	$TC	Tipo de dados: REC Descritor do elemento recurso
*
*	$ED Descrição do tipo
*	   Descreve a organização do elemento
*
*************************************************************************/

   typedef struct tgElemRecurso {

         int matricula;
			/*matrícula para fins de identificação*/

		 char * nome;
			/*nome para fins de identificação*/

		 int status;
			/*status de ocupação
				1 - Ocupado
				0 - Disponível */
   } tpElemRecurso ;

 
/*****  Dados exportados pelo módulo  *****/

 tpElemRecurso * recurso = NULL;
	/* Ponteiro para elemento do recurso */

/***** Protótipos das funções encapuladas no módulo *****/

void imprime (void) ;

/*****  Código das funções exportadas pelo módulo  *****/

   REC_tpCondRet REC_CriarRecurso (int matr, char * name)
   {
	   int i;
	   if (recurso != NULL)
	   {
		   REC_ExcluirRecurso();
	   }
	   recurso = (tpElemRecurso *)malloc(sizeof(tpElemRecurso));
	   recurso->nome = (char *)malloc((strlen(name)+1));
	   recurso->matricula = matr;
	   strcpy(recurso->nome,name);
	   recurso->status=0;
	   if (recurso==NULL)
	   {
		   
		   return REC_CondRetNaoCriouRecurso;
	   }
	   return REC_CondRetOK;
   }
  
   void REC_ExcluirRecurso ( void )
   {
	   free(recurso);
   }

   REC_tpCondRet REC_AlteraRecurso (int matr , char * name)
   {
	   if (recurso == NULL)
	   {
		   return REC_CondRetNaoCriouRecurso;
	   }
	   if (recurso->matricula != matr)
	   {
		   return REC_CondRetRecursoNaoExiste;
	   }
	   strcpy(recurso->nome,name);
	   return REC_CondRetOK;
   }

   REC_tpCondRet REC_ConsultaRecurso (int matr)
   {
	   if(recurso == NULL)
	   {
		   return REC_CondRetNaoCriouRecurso;
	   }
	   if (recurso->matricula == matr)
	   {
		   if(recurso->status==0)
		   {
			   return REC_CondRetRecursoDisponível;
		   }
		   return REC_CondRetRecursoOcupado;
	   }
	   return REC_CondRetRecursoNaoExiste;
   }


   REC_tpCondRet REC_TrocaStatus ( int matr )
   {
	   if(recurso == NULL)
	   {
		   return REC_CondRetNaoCriouRecurso;
	   }
	   if(recurso->matricula != matr)
	   {
		   return REC_CondRetRecursoNaoExiste;
	   }
	   if (recurso->status == 0)
	   {
		   recurso->status = 1;
		   return REC_CondRetOK;
	   }
	   else 
	   {
		   recurso->status = 0;
		   return REC_CondRetOK;
	   }
   }

   tpElemRecurso * RetornaPonteiro ( int matr )
   {
	  return recurso;
   }

   REC_tpCondRet REC_ImprimirDados( tpElemRecurso * rec )
   {
	   printf("\nMatricula:%d",rec->matricula);
	   printf("\nNome     :%s",rec->nome);
	   if(rec->status == 1)
		   printf("\nOcupado");
	   else
		   printf("\nDisponível");
   }

   REC_tpCondRet REC_ValidaMatricula ( tpElemRecurso * rec , int matr)
   {
	   if( rec->matricula == matr )
		   return REC_CondRetOK;
	   return REC_CondRetRecursoNaoExiste;
   }
   
   
/*****  Código das funções encapsuladas no módulo  *****/

   

