#include "tReceita.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tReceita {
    int qntd;
    eTipoUso tipoUso;
    char nomePaciente[101];
    char nomeMedicamento[MAX_TAM_NOME_MEDICAMENTO];
    char tipoMedicamento[MAX_TAM_TIPO_MEDICAMENTO];
    char instrucoes[MAX_TAM_INSTRUCOES];
    char nomeMedico[101];
    char CRM[12];
    char dataStr[11];
};

tReceita *criaReceita(char *nomePaciente, eTipoUso tipoUso, char *nomeMedicamento,
                      char *tipoMedicamento, char *instrucoes, int qntd,
                      char *nomeMedico, char *CRM, char *dataStr) {
    
    tReceita* receita = (tReceita*) malloc (sizeof(tReceita));

    if(receita == NULL) {
        printf("Erro na alocacao dinamica - CriaReceita(...)\n");
        exit(1);
    }

    receita->qntd = qntd;
    receita->tipoUso = tipoUso;
    strcpy(receita->nomePaciente, nomePaciente);
    strcmp(receita->nomeMedicamento, nomeMedicamento);
    strcmp(receita->tipoMedicamento, tipoMedicamento);
    strcmp(receita->instrucoes, instrucoes);
    strcmp(receita->nomeMedico, nomeMedico);
    strcmp(receita->CRM, CRM);
    strcmp(receita->dataStr, dataStr);

    return receita;
}

void desalocaReceita(void *dado) {
    tReceita* receita = (tReceita*) dado;
    free(receita);
}

void ImprimeTipoUsoReceita(eTipoUso tipo) {
    if(tipo == 0) {
        printf("USO ORAL\n\n");
    } else if(tipo == 1) {
        printf("USO TOPICO\n\n");
    } else {
        printf("Houve erro ao printar o eTipoUso na imprimeNaTelaReceita()\n");
        exit(1);
    }
}

void imprimeNaTelaReceita(void *dado) {
    tReceita* receita = (tReceita*) dado;

    printf("RECEITUARIO\n");
    printf("NOME: %s\n\n", receita->nomePaciente);
    ImprimeTipoUsoReceita(receita->tipoUso);
    printf("%s\n", receita->nomeMedicamento);
    printf("%d %s\n\n", receita->qntd, receita->tipoMedicamento);
    printf("%s\n\n", receita->instrucoes);
    printf("%s (%s)\n", receita->nomeMedico, receita->CRM);
    printf("%s\n", receita->dataStr);
}

void imprimeEmArquivoReceita(void *dado, char *path) {
    
}