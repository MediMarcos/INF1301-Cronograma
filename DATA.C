/***************************************************************************
*  $MCI Módulo de implementação: Módulo árvore
*
*  Arquivo gerado:              ARVORE.C
*  Letras identificadoras:      ARV
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
***************************************************************************/

#include   <malloc.h>
#include   <stdio.h>

#define DATA_OWN
#include "DATA.H"
#undef DATA_OWN

/***********************************************************************
*
*  $TC Tipo de dados: ARV Descritor do nó da árvore
*
*
*  $ED Descrição do tipo
*     Descreve a organização do nó
*
***********************************************************************/


/***********************************************************************
*
*  $TC Tipo de dados: ARV Descritor da cabeça de uma árvore
*
*
*  $ED Descrição do tipo
*     A cabe‡a da árvore é o ponto de acesso para uma determinada árvore.
*     Por intermédio da referência para o nó corrente e do ponteiro
*     pai pode-se navegar a árvore sem necessitar de uma pilha.
*     Pode-se, inclusive, operar com a árvore em forma de co-rotina.
*
***********************************************************************/

   typedef struct tgData {

         int dia;
		 int mes;
		 int ano;
		 char  dtString[11];

   } tpData ;

/*****  Dados encapsulados no módulo  *****/

   static tpData * vtData[2] = {NULL,NULL} ;
            /* Ponteiro para a cabe‡a da árvore */

/***** Protótipos das funções encapuladas no módulo *****/

   static tpData * DATA_CriaData(int d) ;

   static void Liberar (void);
  


   //static ARV_tpCondRet CriarNoRaiz( char ValorParm ) ;

   //static void DestroiArvore( tpNoArvore * pNo ) ;

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: ARV Criar árvore
*  ****/

   DATA_tpCondRet DATA_CompararData( int d1 , int d2 )
   {
	   if(vtData != NULL)
		   Liberar;
	   vtData[0] = DATA_CriaData(d1);
	   if (vtData[0]==NULL)
		   return DATA_CondRetFaltouMemoria;
	   vtData[1] = DATA_CriaData(d2);
	   if (vtData[1]==NULL)
		   return DATA_CondRetFaltouMemoria;


	   if             (vtData[0]->ano > vtData[1]->ano)
		   return DATA_CondRetPrimMaisRecente;

	   else if        (vtData[0]->ano < vtData[1]->ano)
		   return DATA_CondRetPrimMaisTarde;

	   else if        (vtData[0]->mes > vtData[1]->mes)
		   return DATA_CondRetPrimMaisRecente;

	   else if        (vtData[0]->mes < vtData[1]->mes)
		   return DATA_CondRetPrimMaisTarde;

	   else if        (vtData[0]->dia > vtData[1]->dia)
		   return DATA_CondRetPrimMaisRecente;

	   else 
		   return DATA_CondRetPrimMaisTarde;

      
   } /* Fim função: ARV Criar árvore */

   int DATA_DiferencaEmDias(int d1 , int d2)
   {
	   int ano,mes,dia;
	   if( DATA_CompararData(d1,d2) == DATA_CondRetPrimMaisRecente )
	   {
		   ano = vtData[0]->ano  - vtData[1]->ano;
		   mes = vtData[0]->mes  - vtData[1]->mes;
		   dia = vtData[0]->dia  - vtData[1]->dia;
	   }
	   else
	   {
		   ano = vtData[1]->ano  - vtData[0]->ano;
		   mes = vtData[1]->mes  - vtData[0]->mes;
		   dia = vtData[1]->dia  - vtData[0]->dia;


	   }
	   return (ano*365)+(mes*30)+dia;
   }

   void DATA_ImprimirData(int d)
   {
	   tpData * dt = DATA_CriaData(d);
	   printf("Data:%s",dt->dtString);
   }



   void Liberar (void)
   {
	   free(vtData);
   }



/*****  Código das funções encapsuladas no módulo  *****/


/***********************************************************************
*
*  $FC Função: ARV Criar nó da árvore
*
*  $FV Valor retornado
*     Ponteiro para o nó criado.
*     Será NULL caso a memória tenha se esgotado.
*     Os ponteiros do nó criado estarão nulos e o valor é igual ao do
*     parâmetro.
*
***********************************************************************/

   tpData * DATA_CriaData(int d)
   {
	   tpData * t1;
	   t1 = (tpData *)malloc(sizeof(tpData));
	   if (t1==NULL)
		   return NULL;
	   t1->ano = d%10000;
	   t1->mes = ((d-t1->ano)%1000000)/10000;
	   t1->dia = (d-d%1000000)/1000000;
	   t1->dtString[0] = '0'+(t1->dia)/10;
	   t1->dtString[1] = '0'+(t1->dia)%10;
	   t1->dtString[2] = '/';
	   t1->dtString[3] = '0'+(t1->mes)/10;
	   t1->dtString[4] = '0'+(t1->mes)%10;
	   t1->dtString[5] = '/';
	   t1->dtString[6] = '0'+(t1->ano)/1000;
	   t1->dtString[7] = '0'+((t1->ano)/100)%10;
	   t1->dtString[8] = '0'+((t1->ano)%100)/10;
	   t1->dtString[9] = '0'+(t1->ano)%10;
	   t1->dtString[10] = '\0';
	   return t1;


   } /* Fim função: DAT Criar data */

 


/********** Fim do módulo de implementação: Módulo árvore **********/

