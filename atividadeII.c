#include <stdio.h>
#include <stdlib.h>

struct Aluno {
  int matricula;
  float g1;
  float g2;
  float media;
};

int main() {
    struct Aluno* alunos = NULL;
    int quantidade = 0;
    char continuar = 's';

    while (continuar == 's' || continuar == 'S') {
    alunos = realloc(alunos, (quantidade + 1) * sizeof(struct Aluno));

        printf("Digite a matrícula do aluno: ");
        scanf("%d", &alunos[quantidade].matricula);

        printf("Digite a nota G1: ");
        scanf("%f", &alunos[quantidade].g1);

        printf("Digite a nota G2: ");
        scanf("%f", &alunos[quantidade].g2);


        alunos[quantidade].media = (alunos[quantidade].g1 + alunos[quantidade].g2) / 2;

        quantidade++;

        printf("Deseja cadastrar outro aluno? (s/n): ");
        scanf(" %c", &continuar);

    }

for (int i = 0; i < quantidade; i++) {
    for (int j = 0; j < quantidade - 1 - i; j++) {
        if (alunos[j].media < alunos[j + 1].media) {
            struct Aluno temp = alunos[j];
            alunos[j] = alunos[j + 1];
            alunos[j + 1] = temp;
        }
    }
}

printf("\nAluno com a maior média:\n");
printf("Matrícula: %d\n", alunos[0].matricula);
printf("G1: %.2f, G2: %.2f, Média: %.2f\n", alunos[0].g1, alunos[0].g2, alunos[0].media);
    printf("\nAlunos cadastrados:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("Aluno: Matrícula %d, media %.2f\n",
            alunos[i].matricula, alunos[i].media);
    }

printf("\nAlunos de substituição:\n");
for (int i = 0; i < quantidade; i++) {
    if (alunos[i].media < 6) {
        printf("Aluno: Matrícula %d, Média: %.2f\n", alunos[i].matricula, alunos[i].media);
    }
}

    free(alunos);
    return 0;
}
