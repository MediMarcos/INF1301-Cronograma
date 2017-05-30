

#include    <string.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"

#include    "tarefa.h"

/* Tabela dos nomes dos comandos de teste específicos */

#define     CRIAR_TRF_CMD       "=criar"
#define		ALT_DESC_TRF_CMD	"=altdesc"
#define		ALT_TMP_TRF_CMD		"=altduracao"
#define		CONS_TRF_CMD		"=consultar"
#define		INSREC_TRF_CMD      "=insrec"
#define		RETREC_TRF_CMD		"=retrec"
#define		EXCLUI_TRF_CMD		"=excluir"


#define     N   50
/*****  Código das funções exportadas pelo módulo  *****/




   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

      TRF_tpCondRet CondRetObtido   = TRF_CondRetOK ;
      TRF_tpCondRet CondRetEsperada = TRF_CondRetFaltouMemoria ;
                                      /* inicializa para qualquer coisa */
	  int i ;
      int codDado = 0  ;
      int codObtido   = 0  ;
	  int dataDada = 0;
	  int tempoDado = 0;
	  int matrDada = 0;
	  char nomeDado[N];
      char descDada[N] ;
	  char descObtida[N];
      int  NumLidos = -1 ;
      
	  for (i=0;i<N;i++)
	  {
		  descDada[i]= '\0';
		  descObtida[i]='\0';
		  nomeDado[i]='\0';
	  }


      /* Testar ARV Criar árvore */

         if ( strcmp( ComandoTeste , CRIAR_TRF_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "isiii" ,
										  &codDado	,
										  descDada    ,
										  &dataDada   ,
										  &tempoDado  ,
                                          &CondRetEsperada ) ;
            if ( NumLidos != 5 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = TRF_CriaTarefa(  codDado ,  descDada,  dataDada,  tempoDado ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao criar tarefa." );

         } 
		 else if ( strcmp( ComandoTeste , ALT_DESC_TRF_CMD ) == 0 )
		 {
			 NumLidos = LER_LerParametros( "isi"    ,
										  &codDado	  ,
										  descDada    ,
                                          &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = TRF_AlteraDescTarefa(  codDado ,  descDada ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao alterar descrição da tarefa." );
		 }
		 
		 else if ( strcmp( ComandoTeste , ALT_TMP_TRF_CMD ) == 0 )
		 {
			 NumLidos = LER_LerParametros( "iii"       ,
											&codDado   ,
											&tempoDado  ,
											&CondRetEsperada  );
			 if ( NumLidos != 3 )
			 {
				 return TST_CondRetParm;
			 }

			 CondRetObtido = TRF_AlteraDuracao ( codDado , tempoDado );

			 return TST_CompararInt( CondRetEsperada , CondRetObtido ,
									 "Retorno errado ao alterar tempo de conclusão esperado da tarefa");
		 }
		 else if ( strcmp( ComandoTeste , CONS_TRF_CMD ) == 0 )
		 {
			 NumLidos = LER_LerParametros("ii", &codDado , &CondRetEsperada );

			 if (NumLidos != 2)
			 {
				 return TST_CondRetParm;
			 }
			 
			 CondRetObtido = TRF_ConsultarTarefa ( codDado );

			 return TST_CompararInt(CondRetEsperada , CondRetObtido ,
									"Retorno errado ao consultar tarefa");
		 }
		 else if ( strcmp( ComandoTeste , INSREC_TRF_CMD ) == 0 )
		 {
			 NumLidos = LER_LerParametros("isi"        ,
										  	&matrDada  ,
											nomeDado   ,
											&CondRetEsperada);
			 if ( NumLidos != 3 )
			 {
				 return TST_CondRetParm;
			 }

			 CondRetObtido = TRF_InsereRecurso(matrDada,nomeDado);

			 return TST_CompararInt(CondRetEsperada,CondRetObtido,
									"Retorno errado ao inserir recurso");
		 }
		 else if ( strcmp( ComandoTeste , RETREC_TRF_CMD ) == 0 )
		 {
			 TRF_RetiraRecurso();
			 return TST_CondRetOK;
		 }
		 else if ( strcmp( ComandoTeste , EXCLUI_TRF_CMD ) == 0 )
		 {
			 TRF_ExcluirTarefa();
			 return TST_CondRetOK;
		 }
      return TST_CondRetNaoConhec ;

   } 

/********** Fim do módulo de implementação: Módulo de teste específico **********/

