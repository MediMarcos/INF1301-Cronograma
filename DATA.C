/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo �rvore
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
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*       3.00   avs   28/02/2003 Uniformiza��o da interface das fun��es e
*                               de todas as condi��es de retorno.
*       2.00   avs   03/08/2002 Elimina��o de c�digo duplicado, reestrutura��o
*       1.00   avs   15/08/2001 In�cio do desenvolvimento
*
***************************************************************************/

#include   <malloc.h>
#include   <stdio.h>

#define DATA_OWN
#include "DATA.H"
#undef DATA_OWN

/***********************************************************************
*
*  $TC Tipo de dados: ARV Descritor do n� da �rvore
*
*
*  $ED Descri��o do tipo
*     Descreve a organiza��o do n�
*
***********************************************************************/


/***********************************************************************
*
*  $TC Tipo de dados: ARV Descritor da cabe�a de uma �rvore
*
*
*  $ED Descri��o do tipo
*     A cabe�a da �rvore � o ponto de acesso para uma determinada �rvore.
*     Por interm�dio da refer�ncia para o n� corrente e do ponteiro
*     pai pode-se navegar a �rvore sem necessitar de uma pilha.
*     Pode-se, inclusive, operar com a �rvore em forma de co-rotina.
*
***********************************************************************/

   typedef struct tgData {

         int dia;
		 int mes;
		 int ano;
		 char  dtString[11];

   } tpData ;

/*****  Dados encapsulados no m�dulo  *****/

   static tpData * vtData[2] = {NULL,NULL} ;
            /* Ponteiro para a cabe�a da �rvore */

/***** Prot�tipos das fun��es encapuladas no m�dulo *****/

   static tpData * DATA_CriaData(int d) ;

   static void Liberar (void);
  


   //static ARV_tpCondRet CriarNoRaiz( char ValorParm ) ;

   //static void DestroiArvore( tpNoArvore * pNo ) ;

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/

/***************************************************************************
*
*  Fun��o: ARV Criar �rvore
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

      
   } /* Fim fun��o: ARV Criar �rvore */

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



/*****  C�digo das fun��es encapsuladas no m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: ARV Criar n� da �rvore
*
*  $FV Valor retornado
*     Ponteiro para o n� criado.
*     Ser� NULL caso a mem�ria tenha se esgotado.
*     Os ponteiros do n� criado estar�o nulos e o valor � igual ao do
*     par�metro.
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


   } /* Fim fun��o: DAT Criar data */

 


/********** Fim do m�dulo de implementa��o: M�dulo �rvore **********/

