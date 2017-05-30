#if ! defined( TAREFA_ )
#define TAREFA_
/***************************************************************************
*
*  $MCD Módulo de definição: Módulo tarefa
*
*	Arquivo gerado:				TAREFA.H
*	Letras Identificadoras:		TRF
*
*	Projeto:	Disciplina  INF1301
*	Gestor:		Flávio Bevilaquia
*	Autores:    mmp - Marcos Porto, Matheus Santana e Pedro Moraes
*
*	$HA Histórico de evolução:
*	   Versão	Autor		Data		Observações
*		1.00	mmp			22/04/2017  Início do desenvolvimento
*
*	$ED Descrição do módulo
*	  Este módulo implementa um conjunto simples de funções para criar e
*	  Alterar tarefas em um cronograma, além de alocar recursos nessas
*	  tarefas.
*	  A tarefa possui um código, uma descrição, uma data de inicio, um tempo
*     de conclusão esperado, um tempo real de conclusão e uma referência 
*	  para recurso alocado.
*
*
***************************************************************************/
 
#if defined( TAREFA_OWN )
   #define TAREFA_EXT
#else
   #define TAREFA_EXT extern
#endif


/***********************************************************************
*
*  $TC Tipo de dados: TRF Condicoes de retorno
*
*
***********************************************************************/

   typedef enum {

         TRF_CondRetOK = 0 ,
			/* Executou correto */

         TRF_CondRetNaoCriouTarefa = 1 ,
			/* Não criou tarefa */

		 TRF_CondRetTarefaNaoExiste = 2 ,
			/* Tarefa Não Existe */

		 TRF_CondRetCodIncorreto = 3 ,
			/* Código Incorreto */

		 TRF_CondRetTrfSemRecurso = 4 ,
			/* Nenhum recurso alocado na tarefa */

		 TRF_CondRetTrfComRecurso = 5 ,
			/* Um recurso alocado na terafa */

		 TRF_CondRetNaoAlocouRecurso = 6 ,
			/* Erro ao alocar recurso */

		 TRF_CondRetFaltouMemoria = 7
			/* Faltou memória ao alocar dados */
                             

       

   } TRF_tpCondRet ;

   typedef struct tgElemTarefa tpElemTarefa;

/***************************************************************************
*
*	$FC Função: REC Testa
*
*	$ED Descrição da função
*
*	$EP Parâmetros
*	  $P
*     $P
*
*	$FV Valor retornado
*
****************************************************************************/

   TRF_tpCondRet TRF_CriaTarefa ( int cod , char * desc, int tempo);



/***************************************************************************
*
*	$FC Função: REC Testa
*
*	$ED Descrição da função
*
*	$EP Parâmetros
*	  $P
*     $P
*
*	$FV Valor retornado
*
****************************************************************************/

   TRF_tpCondRet TRF_AlteraDescTarefa (int cod , char * desc);



/***************************************************************************
*
*	$FC Função: REC Testa
*
*	$ED Descrição da função
*
*	$EP Parâmetros
*	  $P
*     $P
*
*	$FV Valor retornado
*
****************************************************************************/

   TRF_tpCondRet TRF_AlteraDuracao(int cod, int tempo);

/***************************************************************************
*
*	$FC Função: REC Testa
*
*	$ED Descrição da função
*
*	$EP Parâmetros
*	  $P
*     $P
*
*	$FV Valor retornado
*
****************************************************************************/

   TRF_tpCondRet TRF_ConsultarTarefa (int cod);


/***************************************************************************
*
*	$FC Função: REC Testa
*
*	$ED Descrição da função
*
*	$EP Parâmetros
*	  $P
*     $P
*
*	$FV Valor retornado
*
****************************************************************************/
   
   void TRF_ExcluirTarefa(void);


/***************************************************************************
*
*	$FC Função: REC Testa
*
*	$ED Descrição da função
*
*	$EP Parâmetros
*	  $P
*     $P
*
*	$FV Valor retornado
*
****************************************************************************/
   
   TRF_tpCondRet TRF_InsereRecurso( int matr , char * nome );

/***************************************************************************
*
*	$FC Função: REC Testa
*
*	$ED Descrição da função
*
*	$EP Parâmetros
*	  $P
*     $P
*
*	$FV Valor retornado
*
****************************************************************************/

   TRF_tpCondRet TRF_RetiraRecurso(void);


   tpElemTarefa * TRF_RetornaPonteiro (void);


   TRF_tpCondRet TRF_ImprimirDados ( tpElemTarefa * tar );


#undef TAREFA_EXT

   /********** Fim do módulo de definição: Módulo recurso **********/

#else
#endif
