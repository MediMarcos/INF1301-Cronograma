/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo de teste espec�fico
*
*  Arquivo gerado:              TESTARV.C
*  Letras identificadoras:      TARV
*
*  Nome da base de software:    Exemplo de teste automatizado
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\SIMPLES.BSW
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: avs - Arndt von Staa
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*       3.00   avs   28/02/2003 Uniformiza��o da interface das fun��es e
*                               de todas as condi��es de retorno.
*       2.00   avs   03/08/2002 Elimina��o de c�digo duplicado, reestrutura��o
*       1.00   avs   15/08/2001 In�cio do desenvolvimento
*
*  $ED Descri��o do m�dulo
*     Este m�odulo cont�m as fun��es espec�ficas para o teste do
*     m�dulo �rvore. Ilustra como redigir um interpretador de comandos
*     de teste espec�ficos utilizando o arcabou�o de teste para C.
*
*  $EIU Interface com o usu�rio pessoa
*     Comandos de teste espec�ficos para testar o m�dulo �rvore:
*
*     =criar        - chama a fun��o ARV_CriarArvore( )
*     =insdir <Char>
*                   - chama a fun��o ARV_InserirDireita( <Char> )
*                     Obs. nota��o: <Char>  � o valor do par�metro
*                     que se encontra no comando de teste.
*
*     "=insesq" <Char>
*                   - chama a fun��o ARV_InserirEsquerda( <Char> )
*     "=irpai"      - chama a fun��o ARV_IrPai( )
*     "=iresq"      - chama a fun��o ARV_IrEsquerda( )
*     "=irdir"      - chama a fun��o ARV_IrDireita( )
*     "=obter" <Char>
*                   - chama a fun��o ARV_ObterValorCorr( ) e compara
*                     o valor retornado com o valor <Char>
*     "=destroi"    - chama a fun��o ARV_DestruirArvore( )
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"

#include    "crono.h"

/* Tabela dos nomes dos comandos de teste espec�ficos */

#define N 50

#define     CRIAR_CRN_CMD       "=criar"
#define     INS_REC_CMD         "=insrec"
#define     BSC_REC_CMD         "=buscarec"


#define     IR_PAI_CMD          "=irpai"
#define     IR_ESQ_CMD          "=iresq"
#define     IR_DIR_CMD          "=irdir"
#define     OBTER_VAL_CMD       "=obter"
#define     DESTROI_CMD         "=destruir"

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: TARV Efetuar opera��es de teste espec�ficas para �rvore
*
*  $ED Descri��o da fun��o
*     Efetua os diversos comandos de teste espec�ficos para o m�dulo
*     �rvore sendo testado.
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

      CRN_tpCondRet CondRetObtido   = CRN_CondRetOK ;
      CRN_tpCondRet CondRetEsperada = CRN_CondRetFaltouMemoria ;
                                      /* inicializa para qualquer coisa */
	  int i;
      char nomeDado[N];
	  char nomeRec[N];
	  int dataInicio=0;
	  int matrDada=0;


      int  NumLidos = -1 ;

      TST_tpCondRet Ret ;
	  for (i=0;i<N;i++)
	  {
		  nomeDado[i]='\0';
		  nomeRec[i]='\0';
	  }
      /* Testar ARV Criar �rvore */

         if ( strcmp( ComandoTeste , CRIAR_CRN_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "sii" ,
				               nomeDado ,
							   &dataInicio  ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = CRN_CriarCronograma (nomeDado ,dataInicio) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao criar �rvore." );

          } /* fim ativa: Testar ARV Criar �rvore */

		 else if ( strcmp( ComandoTeste , INS_REC_CMD ) == 0 )
		 {
			 NumLidos = LER_LerParametros("isi", 
				                          &matrDada   ,
										  nomeRec     ,
										  &CondRetEsperada);
			 if( NumLidos != 3 )
			 {
				 return TST_CondRetParm;
			 }

			 CondRetObtido = CRN_InserirRecurso (matrDada, nomeRec);

			 return TST_CompararInt( CondRetEsperada , CondRetObtido , "Retorno errado ao inserir Recurso" );

		 }
		 else if ( strcmp( ComandoTeste , BSC_REC_CMD ) == 0 )
		 {
			 NumLidos = LER_LerParametros("ii", &matrDada , &CondRetEsperada);
			 if(NumLidos != 2)
			 {
				 return TST_CondRetParm;
			 }
			 CondRetObtido = CRN_BuscaRecurso( matrDada );

			 return TST_CompararInt(CondRetEsperada , CondRetObtido , "Retorno errado ao buscar recurso");
		 }




      return TST_CondRetNaoConhec ;

   } /* Fim fun��o: TARV Efetuar opera��es de teste espec�ficas para �rvore */

/********** Fim do m�dulo de implementa��o: M�dulo de teste espec�fico **********/

