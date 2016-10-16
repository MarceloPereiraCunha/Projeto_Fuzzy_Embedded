/* 
 * File:   Fuzzy.c
 * Author: Eletrocursos
 *
 * Created on 21 de Novembro de 2013, 10:11
 */

#include "FuzzyHead.h"

float variavelAnalogica_a = 11.6, variavelAnalogica_b = 12.5;

void main()
{
    struct Fuzzyphy_type fzm;
    struct Rulebase_type rbm;
    struct Defuzzy_type dfm;
    const uint8_t Nrules = 25;
    uint8_t i, Input_a_rule[26], Input_b_rule[26], Input_c_rule[26];
    float grauMtoBaixo_a, grauBaixo_a, grauNeutro_a, grauAlto_a, grauMtoAlto_a;
    float grauMtoBaixo_b, grauBaixo_b, grauNeutro_b, grauAlto_b, grauMtoAlto_b;
    float OutputDegreeRule[26], Saida_Logica_Fuzzy;
    
    while(1)
    {

        fzm.EntradaSinal = variavelAnalogica_a;
		//Define os subconjuntos para a entrada A
        fzm.SubMtoBaixo[0] = 0;
        fzm.SubMtoBaixo[1] = 10;
        fzm.SubBaixo[0] = 0;
        fzm.SubBaixo[1] = 20;
        fzm.SubNeutro[0] = 10;
        fzm.SubNeutro[1] = 30;
        fzm.SubAlto[0] = 20;
        fzm.SubAlto[1] = 40;
        fzm.SubMtoAlto[0] = 30;
        fzm.SubMtoAlto[1] = 40;

        Fuzzyphy(&fzm);

        grauMtoBaixo_a = fzm.GrauMtoBaixo;
        grauBaixo_a = fzm.GrauBaixo;
        grauNeutro_a = fzm.GrauNeutro;
        grauAlto_a = fzm.GrauAlto;
        grauMtoAlto_a = fzm.GrauMtoAlto;

        fzm.EntradaSinal = variavelAnalogica_b;
		//Define os subconjuntos para a entrada B
        fzm.SubMtoBaixo[0] = 0;
        fzm.SubMtoBaixo[1] = 10;
        fzm.SubBaixo[0] = 0;
        fzm.SubBaixo[1] = 20;
        fzm.SubNeutro[0] = 10;
        fzm.SubNeutro[1] = 30;
        fzm.SubAlto[0] = 20;
        fzm.SubAlto[1] = 40;
        fzm.SubMtoAlto[0] = 30;
        fzm.SubMtoAlto[1] = 40;

        Fuzzyphy(&fzm);

        grauMtoBaixo_b = fzm.GrauMtoBaixo;
        grauBaixo_b = fzm.GrauBaixo;
        grauNeutro_b = fzm.GrauNeutro;
        grauAlto_b = fzm.GrauAlto;
        grauMtoAlto_b = fzm.GrauMtoAlto;

        rbm.Input_a_degree[1] = grauMtoBaixo_a;
        rbm.Input_a_degree[2] = grauBaixo_a;
        rbm.Input_a_degree[3] = grauNeutro_a;
        rbm.Input_a_degree[4] = grauAlto_a;
        rbm.Input_a_degree[5] = grauMtoAlto_a;

        rbm.Input_b_degree[1] = grauMtoBaixo_b;
        rbm.Input_b_degree[2] = grauBaixo_b;
        rbm.Input_b_degree[3] = grauNeutro_b;
        rbm.Input_b_degree[4] = grauAlto_b;
        rbm.Input_b_degree[5] = grauMtoAlto_b;

        rbm.Nrules = Nrules;

        /*Definição das regras*/

        /*Regra 1*/
		//Se A=SubMtoBaixo & B=SubMtoBaixo ENTÃO C=SubMtoAlto
        Input_a_rule[1] = 1;
        Input_b_rule[1] = 1;
        Input_c_rule[1] = 5;

        /*Regra 2*/
		//Se A=SubBaixo & B=SubMtoBaixo ENTÃO C=SubMtoAlto
        Input_a_rule[2] = 2;
        Input_b_rule[2] = 1;
        Input_c_rule[2] = 5;

        /*Regra 3*/
		//Se A=SubNeutro & B=SubMtoBaixo ENTÃO C=SubAlto
        Input_a_rule[3] = 3;
        Input_b_rule[3] = 1;
        Input_c_rule[3] = 4;

        /*Regra 4*/
        Input_a_rule[4] = 4;
        Input_b_rule[4] = 1;
        Input_c_rule[4] = 3;

        /*Regra 5*/
        Input_a_rule[5] = 5;
        Input_b_rule[5] = 1;
        Input_c_rule[5] = 3;

        /*Regra 6*/
        Input_a_rule[6] = 1;
        Input_b_rule[6] = 2;
        Input_c_rule[6] = 5;

        /*Regra 7*/
        Input_a_rule[7] = 2;
        Input_b_rule[7] = 2;
        Input_c_rule[7] = 4;

        /*Regra 8*/
        Input_a_rule[8] = 3;
        Input_b_rule[8] = 2;
        Input_c_rule[8] = 4;

        /*Regra 9*/
        Input_a_rule[9] = 4;
        Input_b_rule[9] = 2;
        Input_c_rule[9] = 3;

        /*Regra 10*/
        Input_a_rule[10] = 5;
        Input_b_rule[10] = 2;
        Input_c_rule[10] = 3;

        /*Regra 11*/
        Input_a_rule[11] = 1;
        Input_b_rule[11] = 3;
        Input_c_rule[11] = 4;

        /*Regra 12*/
        Input_a_rule[12] = 2;
        Input_b_rule[12] = 3;
        Input_c_rule[12] = 4;

        /*Regra 13*/
        Input_a_rule[13] = 3;
        Input_b_rule[13] = 3;
        Input_c_rule[13] = 3;

        /*Regra 14*/
        Input_a_rule[14] = 4;
        Input_b_rule[14] = 3;
        Input_c_rule[14] = 2;

        /*Regra 15*/
        Input_a_rule[15] = 5;
        Input_b_rule[15] = 3;
        Input_c_rule[15] = 2;

        /*Regra 16*/
        Input_a_rule[16] = 1;
        Input_b_rule[16] = 4;
        Input_c_rule[16] = 3;

        /*Regra 17*/
        Input_a_rule[17] = 2;
        Input_b_rule[17] = 4;
        Input_c_rule[17] = 3;

        /*Regra 18*/
        Input_a_rule[18] = 3;
        Input_b_rule[18] = 4;
        Input_c_rule[18] = 2;

        /*Regra 19*/
        Input_a_rule[19] = 4;
        Input_b_rule[19] = 4;
        Input_c_rule[19] = 2;

        /*Regra 20*/
        Input_a_rule[20] = 5;
        Input_b_rule[20] = 4;
        Input_c_rule[20] = 1;

        /*Regra 21*/
        Input_a_rule[21] = 1;
        Input_b_rule[21] = 5;
        Input_c_rule[21] = 3;

        /*Regra 22*/
        Input_a_rule[22] = 2;
        Input_b_rule[22] = 5;
        Input_c_rule[22] = 3;

        /*Regra 23*/
        Input_a_rule[23] = 3;
        Input_b_rule[23] = 5;
        Input_c_rule[23] = 2;

        /*Regra 24*/
        Input_a_rule[24] = 4;
        Input_b_rule[24] = 5;
        Input_c_rule[24] = 1;

        /*Regra 25*/
        Input_a_rule[25] = 5;
        Input_b_rule[25] = 5;
        Input_c_rule[25] = 1;

        for(i=1;i<=Nrules;i++)
        {
            rbm.Input_a_rule[i] = Input_a_rule[i];
            rbm.Input_b_rule[i] = Input_b_rule[i];
        }

        Rulebase(&rbm);

        for(i=1;i<=Nrules;i++)
        {
            OutputDegreeRule[i] = rbm.OutputDegreeRule[i];
        }

		//Define os subconjuntos para a saída C
        dfm.SubMtoBaixo[0] = 0;
        dfm.SubMtoBaixo[1] = 10;
        dfm.SubBaixo[0] = 0;
        dfm.SubBaixo[1] = 20;
        dfm.SubNeutro[0] = 10;
        dfm.SubNeutro[1] = 30;
        dfm.SubAlto[0] = 20;
        dfm.SubAlto[1] = 40;
        dfm.SubMtoAlto[0] = 30;
        dfm.SubMtoAlto[1] = 40;

        dfm.Nrules = Nrules;

        for(i=1;i<=Nrules;i++)
        {
            dfm.DegreeRule[i] = OutputDegreeRule[i];
            dfm.Output_rule[i] = Input_c_rule[i];
        }

        Defuzzy(&dfm);

        Saida_Logica_Fuzzy = dfm.Output_element;
        
    }
}

