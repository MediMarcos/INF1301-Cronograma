/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico
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
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       3.00   avs   28/02/2003 Uniformização da interface das funções e
*                               de todas as condições de retorno.
*       2.00   avs   03/08/2002 Eliminação de código duplicado, reestruturação
*       1.00   avs   15/08/2001 Início do desenvolvimento
*
*  $ED Descrição do módulo
*     Este mÇodulo contém as funções específicas para o teste do
*     módulo árvore. Ilustra como redigir um interpretador de comandos
*     de teste específicos utilizando o arcabouço de teste para C.
*
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo árvore:
*
*     =criar        - chama a função ARV_CriarArvore( )
*     =insdir <Char>
*                   - chama a função ARV_InserirDireita( <Char> )
*                     Obs. notação: <Char>  é o valor do parâmetro
*                     que se encontra no comando de teste.
*
*     "=insesq" <Char>
*                   - chama a função ARV_InserirEsquerda( <Char> )
*     "=irpai"      - chama a função ARV_IrPai( )
*     "=iresq"      - chama a função ARV_IrEsquerda( )
*     "=irdir"      - chama a função ARV_IrDireita( )
*     "=obter" <Char>
*                   - chama a função ARV_ObterValorCorr( ) e compara
*                     o valor retornado com o valor <Char>
*     "=destroi"    - chama a função ARV_DestruirArvore( )
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"

#include    "crono.h"

/* Tabela dos nomes dos comandos de teste específicos */

#define N 50

#define     CRIAR_CRN_CMD       "=criar"
#define     INS_REC_CMD         "=insrec"
#define     INS_ESQ_CMD         "=insesq"
#define     IR_PAI_CMD          "=irpai"
#define     IR_ESQ_CMD          "=iresq"
#define     IR_DIR_CMD          "=irdir"
#define     OBTER_VAL_CMD       "=obter"
#define     DESTROI_CMD         "=destruir"

/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TARV Efetuar operações de teste específicas para árvore
*
*  $ED Descrição da função
*     Efetua os diversos comandos de teste específicos para o módulo
*     árvore sendo testado.
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
      /* Testar ARV Criar árvore */

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
                                    "Retorno errado ao criar árvore." );

          } /* fim ativa: Testar ARV Criar árvore */

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




      return TST_CondRetNaoConhec ;

   } /* Fim função: TARV Efetuar operações de teste específicas para árvore */

/********** Fim do módulo de implementação: Módulo de teste específico **********/

