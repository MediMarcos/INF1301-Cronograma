#if ! defined( RECURSO_ )
#define RECURSO_
/************************************************************************** 
*	$MCD M�dulo de defini��o: M�dulo recurso
*
*	Arquivo gerado:				RECURSO.H
*	Letras identificadoras:		REC
*
*	Projeto:	Disciplina  INF1301
*	Gestor:		Fl�vio Bevilaquia
*	Autores:    mmp - Marcos Porto, Matheus Santana e Pedro Moraes
*
*	$HA Hist�rico de evolu��o:
*	   Vers�o	Autor		Data		Observa��es
*		1.00	mmp			22/04/2017  In�cio do desenvolvimento
*
*	$ED	Descri��o do m�dulo
*	   Este m�dulo implementa um conjunto simples de fun��es para criar e
*	   alterar recursos de um cronograma.
*	   O recurso possui uma matr�cula, um nome, 
*      um status(0-dispon�vel , 1-ocupado), e uma refer�ncia para a tarefa para
*      o qual foi alocado.
*
*
***************************************************************************/
#if defined( RECURSO_OWN )
   #define RECURSO_EXT
#else
   #define RECURSO_EXT extern
#endif

typedef struct tgElemRecurso tpElemRecurso;
/***************************************************************************
*
*	$TC	Tipo de dados:	REC Condicoes de retorno
*
*
****************************************************************************/
   typedef enum {

         REC_CondRetOK = 0 ,
			/* Executou correto */

         REC_CondRetNaoCriouRecurso = 1 ,
			/* N�o criou elemento recurso */

         REC_CondRetFaltouMemoria = 2 ,
			/* Faltou mem�ria ao alocar dados */

		 REC_CondRetRecursoNaoExiste = 3 ,
			/* Informa��es incompat�veis com todos recursos */

		 REC_CondRetRecursoOcupado = 4 ,
			/* Recurso j� alocado em alguma tarefa */

		 REC_CondRetRecursoDispon�vel = 5 ,
			/* Recurso n�o foi alocado em nenhuma tarefa */

   } REC_tpCondRet ;

/***************************************************************************
*
*	$FC Fun��o: REC Criar recurso
*
*	$ED Descri��o da fun��o
*	  Cria um recurso e preenche com a matr�cula e nome passados.
*
*   $EP Par�metros
*     $P Matr - 
*	  $P nome - 
*
*	$FV Valor retornado
*	  REC_CondRetNaoCriouRecurso
*	  REC_CondRetOK
*
****************************************************************************/
   REC_tpCondRet REC_CriarRecurso (int matr, char * name);

/***************************************************************************
*
*	$FC Fun��o: REC Excluir recurso
*
*	$ED Descri��o da fun��o
*	   Exclui o recurso liberando o espa�o ocupado pelo mesmo.
*
****************************************************************************/

   void REC_ExcluirRecurso ( void );


/***************************************************************************
*
*	$FC Fun��o: REC Alterar recurso
*
*	$ED Descri��o da fun��o
*
*	$EP Par�metros
*	  $P
*     $P
*
*	$FV Valor Retornado
*
****************************************************************************/

   REC_tpCondRet REC_AlteraRecurso (int matr , char * name);


/***************************************************************************
*
*	$FC Fun��o: REC Consulta recurso
*
*	$ED Descri��o da fun��o
*
*	$EP Par�metros
*	  $P
*     $P
*
*	$FV Valor Retornado
*
****************************************************************************/

   REC_tpCondRet REC_ConsultaRecurso (int matr);



/***************************************************************************
*
*	$FC Fun��o: REC Troca Status
*
*	$ED Deescri��o da fun��o
*
*	$EP Par�metros
*	  $P
*     $P
*
*	$FV Valor retornado
*
****************************************************************************/
   
   REC_tpCondRet REC_TrocaStatus ( int matr );

/***************************************************************************
*
*	$FC Fun��o: REC Troca Status
*
*	$ED Deescri��o da fun��o
*
*	$EP Par�metros
*	  $P
*     $P
*
*	$FV Valor retornado
*
****************************************************************************/

   tpElemRecurso * RetornaPonteiro ( int matr );

   REC_tpCondRet REC_ImprimirDados( tpElemRecurso * rec );

   REC_tpCondRet REC_ValidaMatricula ( tpElemRecurso * rec , int matr);

#undef RECURSO_EXT

/********** Fim do m�dulo de defini��o: M�dulo recurso **********/


#else
#endif
