#include "FuzzyHead.h"

 /********************************************************************
 * Define os subconjuntos a partir dos valores limites do conjunto de entrada
 * A partir do valor atual da vari�vel de entrada � calculado um valor no eixo y (grau de pertin�ncia) para cada subconjunto
 * Para calcular este valor � necess�rio aplicar o conceito de semelhan�a de tri�ngulos da trigonometria
 ********************************************************************/
void Fuzzyphy(struct Fuzzyphy_type *fzb)
{
    float CentroMtoBaixo;
    float CentroBaixo;
    float CentroNeutro;
    float CentroAlto;
    float CentroMtoAlto;
    float A;
    float ALinha;
    float B;
    float BLinha;
    float EntradaSinalAnterior;

    /*Calcula o centro de cada subconjunto fuzzy*/

	CentroMtoBaixo = fzb->SubMtoBaixo[0]+(((fzb->SubMtoBaixo[1])-(fzb->SubMtoBaixo[0]))/2);
	CentroBaixo = fzb->SubBaixo[0]+(((fzb->SubBaixo[1])-(fzb->SubBaixo[0]))/2);
	CentroNeutro = fzb->SubNeutro[0]+(((fzb->SubNeutro[1])-(fzb->SubNeutro[0]))/2);
	CentroAlto = fzb->SubAlto[0]+(((fzb->SubAlto[1])-(fzb->SubAlto[0]))/2);
	CentroMtoAlto = fzb->SubMtoAlto[0]+(((fzb->SubMtoAlto[1])-(fzb->SubMtoAlto[0]))/2);

    /*Localiza em qual subconjunto o sinal de entrada est� presente e calcula o grau de pertin�ncia por semelhan�a de tri�ngulos*/
	//Se sinal de entrada atual for difente do sinal processado anteriormente, zera o valor para os graus de pertin�ncia
	if (fzb->EntradaSinal != EntradaSinalAnterior)
    {
		fzb->GrauMtoBaixo = 0;
		fzb->GrauBaixo = 0;
		fzb->GrauNeutro = 0;
		fzb->GrauAlto = 0;
		fzb->GrauMtoAlto = 0;
    }
	EntradaSinalAnterior = fzb->EntradaSinal;
	/*verifica se est� no primeiro subconjunto e calcula o valor do grau de pertin�ncia deste por semelhan�a de tri�ngulos*/
	if ((fzb->EntradaSinal >= fzb->SubMtoBaixo[0])&&(fzb->EntradaSinal <= fzb->SubMtoBaixo[1]))
    {
		A = fzb->SubMtoBaixo[1] - fzb->SubMtoBaixo[0];
		ALinha = fzb->SubMtoBaixo[1] - fzb->EntradaSinal;
		B = 1;
		BLinha = ((B*ALinha)/A);
		fzb->GrauMtoBaixo = BLinha;
    }

	/*verifica se est� no segundo subconjunto e em qual dos lados*/
	//Calcula o valor do grau de pertin�ncia para o lado esquerdo por semelhan�a de tri�ngulos
	if ((fzb->EntradaSinal >= fzb->SubBaixo[0])&&(fzb->EntradaSinal <= CentroBaixo))
    {
		A = CentroBaixo - fzb->SubBaixo[0];
		ALinha = fzb->EntradaSinal - fzb->SubBaixo[0];
		B = 1;
		BLinha = ((B*ALinha)/A);
		fzb->GrauBaixo = BLinha;
    }
	//Calcula o valor do grau de pertin�ncia para o lado direito por semelhan�a de tri�ngulos
	if ((fzb->EntradaSinal > CentroBaixo)&&(fzb->EntradaSinal <= fzb->SubBaixo[1]))
    {
		A = fzb->SubBaixo[1] - CentroBaixo;
		ALinha = fzb->SubBaixo[1] - fzb->EntradaSinal;
		B = 1;
		BLinha = ((B*ALinha)/A);
		fzb->GrauBaixo = BLinha;
    }

	/*verifica se est� no terceiro subconjunto e em qual dos lados*/
	//Calcula o valor do grau de pertin�ncia para o lado esquerdo por semelhan�a de tri�ngulos
	if ((fzb->EntradaSinal >= fzb->SubNeutro[0])&&(fzb->EntradaSinal <= CentroNeutro))
    {
		A = CentroNeutro - fzb->SubNeutro[0];
		ALinha = fzb->EntradaSinal - fzb->SubNeutro[0];
		B = 1;
		BLinha = ((B*ALinha)/A);
		fzb->GrauNeutro = BLinha;
    }
	//Calcula o valor do grau de pertin�ncia para o lado direito por semelhan�a de tri�ngulos
	if ((fzb->EntradaSinal > CentroNeutro)&&(fzb->EntradaSinal <= fzb->SubNeutro[1]))
    {
		A = fzb->SubNeutro[1] - CentroNeutro;
		ALinha = fzb->SubNeutro[1] - fzb->EntradaSinal;
		B = 1;
		BLinha = ((B*ALinha)/A);
		fzb->GrauNeutro = BLinha;
    }

	/*verifica se est� no quarto subconjunto e em qual dos lados*/
	//Calcula o valor do grau de pertin�ncia para o lado esquerdo por semelhan�a de tri�ngulos
	if ((fzb->EntradaSinal >= fzb->SubAlto[0])&&(fzb->EntradaSinal <= CentroAlto))
    {
		A = CentroAlto - fzb->SubAlto[0];
		ALinha = fzb->EntradaSinal - fzb->SubAlto[0];
		B = 1;
		BLinha = ((B*ALinha)/A);
		fzb->GrauAlto = BLinha;
    }
	//Calcula o valor do grau de pertin�ncia para o lado direito por semelhan�a de tri�ngulos
	if ((fzb->EntradaSinal > CentroAlto)&&(fzb->EntradaSinal <= fzb->SubAlto[1]))
    {
		A = fzb->SubAlto[1] - CentroAlto;
		ALinha = fzb->SubAlto[1] - fzb->EntradaSinal;
		B = 1;
		BLinha = ((B*ALinha)/A);
		fzb->GrauAlto = BLinha;
    }

	/*verifica se est� no quinto subconjunto e calcula o valor do grau de pertin�ncia por semelhan�a de tri�ngulos*/
	if ((fzb->EntradaSinal >= fzb->SubMtoAlto[0])&&(fzb->EntradaSinal <= fzb->SubMtoAlto[1]))
    {
		A = fzb->SubMtoAlto[1] - fzb->SubMtoAlto[0];
		ALinha = fzb->EntradaSinal - fzb->SubMtoAlto[0];
		B = 1;
		BLinha = ((B*ALinha)/A);
		fzb->GrauMtoAlto = BLinha;
    }
}


 /********************************************************************
 * Define a base de regras para duas vari�veis de entrada e uma sa�da
 ********************************************************************/
void Rulebase(struct Rulebase_type *rbb)
{
    uint8_t i;
    uint8_t j;
    uint8_t k;

    	//Executa um loop para definir os 'n' graus de pertin�ncia para as 'n' sa�das do sistema
    	for(i=1;i<=rbb->Nrules;i++)
        {
    		//Varre o valor do grau de pertin�ncia e regras para as 5 fun��es de pertin�ncia da entrada 'a' do sistema
    		for(j=1;j<=5;j++)
            {
    				//Varre o valor do grau de pertin�ncia e regras para as 5 fun��es de pertin�ncia da entrada 'b' do sistema
    				for(k=1;k<=5;k++)
                    {
    						//Verifica cada uma das 'n' regras definidas para o sistema
    						//ex.: Regra i=1  SE INPUT_A = 1 E INPUT_B = 1, OUTPUT = 5, onde 1 a 5 s�o os subconjuntos fuzzy
    						if ((rbb->Input_a_rule[i] == j)&&(rbb->Input_b_rule[i] == k))
                            {
    							//rbb->OutputDegreeRule[i]= MIN(rbb->Input_a_degree[j],rbb->Input_b_degree[k]);
    							//Faz a intersec��o dos subconjuntos para gerar o grau de sa�da, ou seja, pega o valor m�nimo entre os 2 conjuntos de entrada
                                if(rbb->Input_a_degree[j] < rbb->Input_b_degree[k]) rbb->OutputDegreeRule[i] = rbb->Input_a_degree[j];
                                else if(rbb->Input_a_degree[j] > rbb->Input_b_degree[k]) rbb->OutputDegreeRule[i] = rbb->Input_b_degree[k];
                                else if(rbb->Input_a_degree[j] == rbb->Input_b_degree[k]) rbb->OutputDegreeRule[i] = rbb->Input_b_degree[k];
                            }
                    }
            }
        }
}

/********************************************************************
 * Calcula o centro de gravidade baseado nas regras e fun��es de pertin�ncia de sa�da
 ********************************************************************/
void Defuzzy(struct Defuzzy_type *dfb)
{
    float CentroMtoBaixo;
    float CentroBaixo;
    float CentroNeutro;
    float CentroAlto;
    float CentroMtoAlto;
    uint8_t i;
    float CentroRegra[26];
    float Numerador;
    float Denominador;
    float b;
    float h;
    float hLinha;
    float bLinha;
    float bDuasLinhas;
    float Area1;
    float Area2;
    float x1;
    float x2;

    /*Calcula o centro de cada subconjunto fuzzy*/
    /*Matem�tica simples*/

    CentroBaixo = dfb->SubBaixo[0]+(((dfb->SubBaixo[1])-(dfb->SubBaixo[0]))/2);
    CentroNeutro = dfb->SubNeutro[0]+(((dfb->SubNeutro[1])-(dfb->SubNeutro[0]))/2);
    CentroAlto = dfb->SubAlto[0]+(((dfb->SubAlto[1])-(dfb->SubAlto[0]))/2);

    for(i=1;i<=dfb->Nrules;i++)
    {
		if(dfb->Output_rule[i] == 1)
        {
			/*Por a fun��o MtoBaixo ser um trap�zio que tem seu centro de gravidade modificado de acordo com o grau de pertin�ncia
	 		este calculo � um pouco mais complexo e leva uma formula��o matem�tica espec�fica para tal*/
			if(dfb->DegreeRule[i] > 0)
            {
				b = (dfb->SubMtoBaixo[1] - dfb->SubMtoBaixo[0]);
				h = 1;
				hLinha = dfb->DegreeRule[i];
				bLinha = (hLinha*b)/h;
				bDuasLinhas = b - bLinha;
				Area1 = bDuasLinhas*hLinha;
				Area2 = (bLinha*hLinha)/2;
				x1 = dfb->SubMtoBaixo[0] + (bDuasLinhas/2);
				x2 = dfb->SubMtoBaixo[1] - ((2*bLinha)/3);
				CentroMtoBaixo = (Area1*x1 + Area2*x2)/(Area1 + Area2);
             }
             else
             {
				CentroMtoBaixo = 0;
             }

			 CentroRegra[i] = CentroMtoBaixo;
        }

		if (dfb->Output_rule[i] == 2)
        {
			CentroRegra[i] = CentroBaixo;
        }

		if (dfb->Output_rule[i] == 3)
        {
			CentroRegra[i] = CentroNeutro;
        }

		if (dfb->Output_rule[i] == 4)
        {
			CentroRegra[i] = CentroAlto;
        }

		if (dfb->Output_rule[i] == 5)
        {
			/*Por a fun��o MtoAlto ser um trap�zio que tem seu centro de gravidade modificado de acordo com o grau de pertin�ncia
	 		este calculo � um pouco mais complexo e leva uma formula��o matem�tica espec�fica para tal*/
			if (dfb->DegreeRule[i] > 0)
            {
				b = (dfb->SubMtoAlto[1] - dfb->SubMtoAlto[0]);
				h = 1;
				hLinha = dfb->DegreeRule[i];
				bLinha = (hLinha*b)/h;
				bDuasLinhas = b - bLinha;
				Area1 = bDuasLinhas*hLinha;
				Area2 = (bLinha*hLinha)/2;
				x1 = dfb->SubMtoAlto[1] - (bDuasLinhas/2);
				x2 = dfb->SubMtoAlto[0] + ((2*bLinha)/3);
				CentroMtoAlto = (Area1*x1 + Area2*x2)/(Area1 + Area2);
            }
            else
            {
				CentroMtoAlto = 0;
            }
			CentroRegra[i] = CentroMtoAlto;
        }

    }

	/*Calcula o centroide*/
	Numerador = 0;
	Denominador = 0;
	dfb->Output_element = 0;
	/*Calcula o numerador e denominador da equa��o de calculo da centroide*/

	for(i=1;i<=dfb->Nrules;i++)
    {
		Numerador = Numerador + ((dfb->DegreeRule[i])*(CentroRegra[i]));
		Denominador = Denominador + dfb->DegreeRule[i];
    }

	if (Denominador != 0)
    {
		dfb->Output_element = Numerador/Denominador;
    }
}
