/***************************************************************************
*	$MCI Módulo de implementaçã0: Módulo de teste específico
*
*	Arquivo gerado:					TESTRECURSO.C
*	Letras identificadoras:			TREC
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
*	   Este módulo contém funções específicas para o teste do módulo
*	   recurso. Ilustra como redigir um interpretador de comandos de
*      teste específicos utilizando o arcabouço de teste para C.
*
*	$EIU Interface com o usuário pessoa
*	   Comandos de teste específicos para testar o módulo árvore:
*
*	   "=criar" <Int> <String>
*						- chama a função REC_CriarRecurso (<Int>,<String>)
*      "=alterar" <Int> <String>
*						-chama a função REC_AlterarRecurso(<Int>,<String>)
*	   "=consultar" <Int>
*						-chama a função REC_ConsultaRecurso(<Int>)
*      "=excluir"		-chama a função REC_ExcluirRecurso()
*
****************************************************************************/
#include    <string.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"

#include    "recurso.h"

#define N 50
/* Tabela dos nomes dos comandos de teste específicos */

#define     CRIAR_REC_CMD      "=criar"
#define     ALT_REC_CMD        "=alterar"
#define     CONS_REC_CMD       "=consultar"
#define     EXCLUI_CMD         "=excluir"
#define     ALT_STATUS_CMD     "=altstatus"

/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TARV Efetuar operações de teste específicas para recurso
*
*  $ED Descrição da função
*     Efetua os diversos comandos de teste específicos para o módulo
*     recurso sendo testado.
*
*  $EP Parâmetros
*     $P ComandoTeste - String contendo o comando
*
*  $FV Valor retornado
*     Ver TST_tpCondRet definido em TST_ESPC.H
*
***********************************************************************/

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

      REC_tpCondRet CondRetObtido   = REC_CondRetOK ;
      REC_tpCondRet CondRetEsperada = REC_CondRetFaltouMemoria ;
                                      /* inicializa para qualquer coisa */
	  int i              = 0 ;
	  int MatrDada       = 0 ;
      int MatrEsperada   = 0 ;
      int MatrObtida     = 0 ;
	  int StatusEsperado = 0 ;
	  int StatusObtido   = 0 ;

	  char NomeEsperado  [N];
	  char NomeObtido    [N];
	  char NomeDado      [N];
      int  NumLidos     = -1 ;

     // TST_tpCondRet Ret ;

	  for (i=0 ; i<N ; i++)
	  {
		  NomeEsperado[i]='\0';
		  NomeObtido[i]='\0';
		  NomeDado[i]='\0';
	  }
	  /* Testar REC Criar Recurso */
         if ( strcmp( ComandoTeste , CRIAR_REC_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "isi" ,&MatrDada , 
												NomeDado ,
											&CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = REC_CriarRecurso (MatrDada, NomeDado) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao criar recurso." );
		 }/* fim ativa: Testar REC Criar recurso*/

		 /* Testar REC ALterar recurso */

		 else if ( strcmp( ComandoTeste , ALT_REC_CMD ) == 0 )
		 {
			 NumLidos = LER_LerParametros("isi" ,&MatrDada , 
												NomeDado ,
											&CondRetEsperada);
			 if ( NumLidos != 3 )
			 {
				 return TST_CondRetParm;
			 }/* if */

			 CondRetObtido = REC_AlteraRecurso(MatrDada, NomeDado) ;

			 return TST_CompararInt ( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao alterar recurso." );
		 }/* fim ativa: Testar REC ALterar recurso */

		 /* Testar REC Consultar Recurso */

		 else if ( strcmp( ComandoTeste , CONS_REC_CMD ) == 0 )
		 {
			 NumLidos = LER_LerParametros( "ii" ,&MatrDada , 
											&CondRetEsperada );
			 if ( NumLidos != 2 )
			 {
				 return TST_CondRetParm;
			 }/* if */

			 CondRetObtido = REC_ConsultaRecurso(MatrDada) ;

			 return TST_CompararInt ( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao consultar recurso." );
		 }/* fim ativa: Testar REC Consultar Recurso */

		 /* Testar Excluir Recurso */
		 else if ( strcmp( ComandoTeste , EXCLUI_CMD ) == 0 )
		 {
			 
			 REC_ExcluirRecurso( ) ;

			 return TST_CondRetOK;
		 }/* fim ativa: Testar Excluir Recurso */

		 /* Testar Trocar Status */
		 else if ( strcmp( ComandoTeste, ALT_STATUS_CMD ) == 0 )
		 {
			NumLidos = LER_LerParametros("ii",&MatrDada,&CondRetEsperada);

			if ( NumLidos !=2 )
			{
				return TST_CondRetParm;
			}
			CondRetObtido = REC_TrocaStatus(MatrDada);

			return TST_CompararInt( CondRetEsperada , CondRetObtido , " Retorno errado ao trocar status ");
		 }
		 


      return TST_CondRetNaoConhec ;
   
   } /* Fim função: TREC Efetuar operações de teste específicas para recurso */

/********** Fim do módulo de implementação: Módulo de teste específico **********/

