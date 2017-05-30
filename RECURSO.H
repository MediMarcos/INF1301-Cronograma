#if ! defined( RECURSO_ )
#define RECURSO_
/************************************************************************** 
*	$MCD Módulo de definição: Módulo recurso
*
*	Arquivo gerado:				RECURSO.H
*	Letras identificadoras:		REC
*
*	Projeto:	Disciplina  INF1301
*	Gestor:		Flávio Bevilaquia
*	Autores:    mmp - Marcos Porto, Matheus Santana e Pedro Moraes
*
*	$HA Histórico de evolução:
*	   Versão	Autor		Data		Observações
*		1.00	mmp			22/04/2017  Início do desenvolvimento
*
*	$ED	Descrição do módulo
*	   Este módulo implementa um conjunto simples de funções para criar e
*	   alterar recursos de um cronograma.
*	   O recurso possui uma matrícula, um nome, 
*      um status(0-disponível , 1-ocupado), e uma referência para a tarefa para
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
			/* Não criou elemento recurso */

         REC_CondRetFaltouMemoria = 2 ,
			/* Faltou memória ao alocar dados */

		 REC_CondRetRecursoNaoExiste = 3 ,
			/* Informações incompatíveis com todos recursos */

		 REC_CondRetRecursoOcupado = 4 ,
			/* Recurso já alocado em alguma tarefa */

		 REC_CondRetRecursoDisponível = 5 ,
			/* Recurso não foi alocado em nenhuma tarefa */

   } REC_tpCondRet ;

/***************************************************************************
*
*	$FC Função: REC Criar recurso
*
*	$ED Descrição da função
*	  Cria um recurso e preenche com a matrícula e nome passados.
*
*   $EP Parâmetros
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
*	$FC Função: REC Excluir recurso
*
*	$ED Descrição da função
*	   Exclui o recurso liberando o espaço ocupado pelo mesmo.
*
****************************************************************************/

   void REC_ExcluirRecurso ( void );


/***************************************************************************
*
*	$FC Função: REC Alterar recurso
*
*	$ED Descrição da função
*
*	$EP Parâmetros
*	  $P
*     $P
*
*	$FV Valor Retornado
*
****************************************************************************/

   REC_tpCondRet REC_AlteraRecurso (int matr , char * name);


/***************************************************************************
*
*	$FC Função: REC Consulta recurso
*
*	$ED Descrição da função
*
*	$EP Parâmetros
*	  $P
*     $P
*
*	$FV Valor Retornado
*
****************************************************************************/

   REC_tpCondRet REC_ConsultaRecurso (int matr);



/***************************************************************************
*
*	$FC Função: REC Troca Status
*
*	$ED Deescrição da função
*
*	$EP Parâmetros
*	  $P
*     $P
*
*	$FV Valor retornado
*
****************************************************************************/
   
   REC_tpCondRet REC_TrocaStatus ( int matr );

/***************************************************************************
*
*	$FC Função: REC Troca Status
*
*	$ED Deescrição da função
*
*	$EP Parâmetros
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

/********** Fim do módulo de definição: Módulo recurso **********/


#else
#endif
