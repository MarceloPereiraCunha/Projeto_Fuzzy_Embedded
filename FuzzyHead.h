/* 
 * File:   FuzzyHead.h
 * Author: Eletrocursos
 *
 * Created on 19 de Novembro de 2013, 13:17
 */
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

 /********************************************************************
 * Estrutura para definição dos limites de cada subconjunto das variáveis de entrada
 ********************************************************************/
struct Fuzzyphy_type{
    float EntradaSinal;
    float SubMtoBaixo[2];
    float SubBaixo[2];
    float SubNeutro[2];
    float SubAlto[2];
    float SubMtoAlto[2];
    float GrauMtoBaixo;
    float GrauBaixo;
    float GrauNeutro;
    float GrauAlto;
    float GrauMtoAlto;
};
 /********************************************************************
 * Define os subconjuntos a partir dos valores limites do conjunto de entrada
 * A partir do valor atual da variável de entrada é calculado um valor no eixo y (grau de pertinência) para cada subconjunto
 * Para calcular este valor é necessário aplicar o conceito de semelhança de triângulos da trigonometria
 ********************************************************************/
void Fuzzyphy(struct Fuzzyphy_type *fz);

struct Rulebase_type{
    uint8_t Nrules;
    uint8_t Input_a_rule[26];
    uint8_t Input_b_rule[26];
    float Input_a_degree[6];
    float Input_b_degree[6];
    float OutputDegreeRule[26];

};
 /********************************************************************
 * Define a base de regras para duas variáveis de entrada e uma saída
 ********************************************************************/
void Rulebase(struct Rulebase_type *rb);

/********************************************************************
* Estrutura para definição dos limites de cada subconjunto da variável de saída
********************************************************************/
struct Defuzzy_type{
    float Output_element;
    float SubMtoBaixo[2];
    float SubBaixo[2];
    float SubNeutro[2];
    float SubAlto[2];
    float SubMtoAlto[2];
    uint8_t Nrules;
    uint8_t Output_rule[26];
    float DegreeRule[26];
};

 /********************************************************************
 * Calcula o centro de gravidade baseado nas regras e funções de pertinência de saída
 ********************************************************************/
void Defuzzy(struct Defuzzy_type *df);


