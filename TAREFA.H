#if ! defined( TAREFA_ )
#define TAREFA_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo tarefa
*
*	Arquivo gerado:				TAREFA.H
*	Letras Identificadoras:		TRF
*
*	Projeto:	Disciplina  INF1301
*	Gestor:		Fl�vio Bevilaquia
*	Autores:    mmp - Marcos Porto, Matheus Santana e Pedro Moraes
*
*	$HA Hist�rico de evolu��o:
*	   Vers�o	Autor		Data		Observa��es
*		1.00	mmp			22/04/2017  In�cio do desenvolvimento
*
*	$ED Descri��o do m�dulo
*	  Este m�dulo implementa um conjunto simples de fun��es para criar e
*	  Alterar tarefas em um cronograma, al�m de alocar recursos nessas
*	  tarefas.
*	  A tarefa possui um c�digo, uma descri��o, uma data de inicio, um tempo
*     de conclus�o esperado, um tempo real de conclus�o e uma refer�ncia 
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
			/* N�o criou tarefa */

		 TRF_CondRetTarefaNaoExiste = 2 ,
			/* Tarefa N�o Existe */

		 TRF_CondRetCodIncorreto = 3 ,
			/* C�digo Incorreto */

		 TRF_CondRetTrfSemRecurso = 4 ,
			/* Nenhum recurso alocado na tarefa */

		 TRF_CondRetTrfComRecurso = 5 ,
			/* Um recurso alocado na terafa */

		 TRF_CondRetNaoAlocouRecurso = 6 ,
			/* Erro ao alocar recurso */

		 TRF_CondRetFaltouMemoria = 7
			/* Faltou mem�ria ao alocar dados */
                             

       

   } TRF_tpCondRet ;

   typedef struct tgElemTarefa tpElemTarefa;

/***************************************************************************
*
*	$FC Fun��o: REC Testa
*
*	$ED Descri��o da fun��o
*
*	$EP Par�metros
*	  $P
*     $P
*
*	$FV Valor retornado
*
****************************************************************************/

   TRF_tpCondRet TRF_CriaTarefa ( int cod , char * desc, int tempo);



/***************************************************************************
*
*	$FC Fun��o: REC Testa
*
*	$ED Descri��o da fun��o
*
*	$EP Par�metros
*	  $P
*     $P
*
*	$FV Valor retornado
*
****************************************************************************/

   TRF_tpCondRet TRF_AlteraDescTarefa (int cod , char * desc);



/***************************************************************************
*
*	$FC Fun��o: REC Testa
*
*	$ED Descri��o da fun��o
*
*	$EP Par�metros
*	  $P
*     $P
*
*	$FV Valor retornado
*
****************************************************************************/

   TRF_tpCondRet TRF_AlteraDuracao(int cod, int tempo);

/***************************************************************************
*
*	$FC Fun��o: REC Testa
*
*	$ED Descri��o da fun��o
*
*	$EP Par�metros
*	  $P
*     $P
*
*	$FV Valor retornado
*
****************************************************************************/

   TRF_tpCondRet TRF_ConsultarTarefa (int cod);


/***************************************************************************
*
*	$FC Fun��o: REC Testa
*
*	$ED Descri��o da fun��o
*
*	$EP Par�metros
*	  $P
*     $P
*
*	$FV Valor retornado
*
****************************************************************************/
   
   void TRF_ExcluirTarefa(void);


/***************************************************************************
*
*	$FC Fun��o: REC Testa
*
*	$ED Descri��o da fun��o
*
*	$EP Par�metros
*	  $P
*     $P
*
*	$FV Valor retornado
*
****************************************************************************/
   
   TRF_tpCondRet TRF_InsereRecurso( int matr , char * nome );

/***************************************************************************
*
*	$FC Fun��o: REC Testa
*
*	$ED Descri��o da fun��o
*
*	$EP Par�metros
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

   /********** Fim do m�dulo de defini��o: M�dulo recurso **********/

#else
#endif
