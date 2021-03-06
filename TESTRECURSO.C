/***************************************************************************
*	$MCI M�dulo de implementa��0: M�dulo de teste espec�fico
*
*	Arquivo gerado:					TESTRECURSO.C
*	Letras identificadoras:			TREC
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
*	   Este m�dulo cont�m fun��es espec�ficas para o teste do m�dulo
*	   recurso. Ilustra como redigir um interpretador de comandos de
*      teste espec�ficos utilizando o arcabou�o de teste para C.
*
*	$EIU Interface com o usu�rio pessoa
*	   Comandos de teste espec�ficos para testar o m�dulo �rvore:
*
*	   "=criar" <Int> <String>
*						- chama a fun��o REC_CriarRecurso (<Int>,<String>)
*      "=alterar" <Int> <String>
*						-chama a fun��o REC_AlterarRecurso(<Int>,<String>)
*	   "=consultar" <Int>
*						-chama a fun��o REC_ConsultaRecurso(<Int>)
*      "=excluir"		-chama a fun��o REC_ExcluirRecurso()
*
****************************************************************************/
#include    <string.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"

#include    "recurso.h"

#define N 50
/* Tabela dos nomes dos comandos de teste espec�ficos */

#define     CRIAR_REC_CMD      "=criar"
#define     ALT_REC_CMD        "=alterar"
#define     CONS_REC_CMD       "=consultar"
#define     EXCLUI_CMD         "=excluir"
#define     ALT_STATUS_CMD     "=altstatus"

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: TARV Efetuar opera��es de teste espec�ficas para recurso
*
*  $ED Descri��o da fun��o
*     Efetua os diversos comandos de teste espec�ficos para o m�dulo
*     recurso sendo testado.
*
*  $EP Par�metros
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
   
   } /* Fim fun��o: TREC Efetuar opera��es de teste espec�ficas para recurso */

/********** Fim do m�dulo de implementa��o: M�dulo de teste espec�fico **********/

