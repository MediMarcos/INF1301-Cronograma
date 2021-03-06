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

#include    "data.h"

/* Tabela dos nomes dos comandos de teste espec�ficos */

#define     COMP_DATA_CMD       "=comparar"
#define     DIF_DATA_CMD        "=diferenca" 

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

      DATA_tpCondRet CondRetObtido   = DATA_CondRetOK ;
      DATA_tpCondRet CondRetEsperada = DATA_CondRetFaltouMemoria ;
                                      /* inicializa para qualquer coisa */

      int data1         = 0;
	  int data2         = 0;
	  int diasEsperados = 0;
	  int diasObtidos   = 0;
      int  NumLidos   = -1 ;

//      TST_tpCondRet Ret ;

      /* Testar ARV Criar �rvore */

         if ( strcmp( ComandoTeste , COMP_DATA_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "iii" ,
				               &data1  ,
							   &data2  ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = DATA_CompararData(data1,data2) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao comparar datas" );

         } /* fim ativa: Testar ARV Criar �rvore */
		 else if ( strcmp( ComandoTeste , DIF_DATA_CMD ) == 0 )
		 {
			 NumLidos = LER_LerParametros( "iii" ,
				                           &data1,
										   &data2,
										   &diasEsperados) ;
			 if (NumLidos != 3)
			 {
				 return TST_CondRetParm;
			 }

			 diasObtidos = DATA_DiferencaEmDias(data1 , data2);

			 return TST_CompararInt(diasEsperados , diasObtidos , "Retorno errado ao calcular diferen�a");
			 
		 }
      /* Testar ARV Adicionar filho � direita */

         

      return TST_CondRetNaoConhec ;

   } /* Fim fun��o: TARV Efetuar opera��es de teste espec�ficas para �rvore */

/********** Fim do m�dulo de implementa��o: M�dulo de teste espec�fico **********/

