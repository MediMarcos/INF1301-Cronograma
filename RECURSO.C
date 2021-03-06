/***************************************************************************
*	$MCI M�dulo de implementa��o: M�dulo recurso
*
*	Arquivo gerado:					RECURSO.C
*	Letras identificadoras:			REC
*
*	Projeto:	Disciplina  INF1301
*	Gestor:		Fl�vio Bevilaquia
*	Autores:    mmp - Marcos Porto, Matheus Santana e Pedro Moraes
*
*	$HA Hist�rico de evolu��o:
*	   Vers�o	Autor		Data		Observa��es
*		1.00	mmp			22/04/2017  In�cio do desenvolvimento
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
*	$ED Descri��o do tipo
*	   Descreve a organiza��o do elemento
*
*************************************************************************/

   typedef struct tgElemRecurso {

         int matricula;
			/*matr�cula para fins de identifica��o*/

		 char * nome;
			/*nome para fins de identifica��o*/

		 int status;
			/*status de ocupa��o
				1 - Ocupado
				0 - Dispon�vel */
   } tpElemRecurso ;

 
/*****  Dados exportados pelo m�dulo  *****/

 tpElemRecurso * recurso = NULL;
	/* Ponteiro para elemento do recurso */

/***** Prot�tipos das fun��es encapuladas no m�dulo *****/

void imprime (void) ;

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/

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
			   return REC_CondRetRecursoDispon�vel;
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
		   printf("\nDispon�vel");
   }

   REC_tpCondRet REC_ValidaMatricula ( tpElemRecurso * rec , int matr)
   {
	   if( rec->matricula == matr )
		   return REC_CondRetOK;
	   return REC_CondRetRecursoNaoExiste;
   }
   
   
/*****  C�digo das fun��es encapsuladas no m�dulo  *****/

   

