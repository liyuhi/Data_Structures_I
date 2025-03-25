/*Crie uma união chamada Senha com os campos Alfanumérica e Numérica. Na função principal pergunte ao usuário se ele quer exibir a senha armazenada ou gravar uma nova senha no arquivo. Se o arquivo não tiver sido criado ainda, a opção de exibição não deve fazer nada, a não ser avisar o usuário que o arquivo não existe.
Use um arquivo binário para guardar a senha. Na gravação da senha, grave primeiro um número para representar o tipo da senha. O modo alfanumérico
será correspondente ao número 1, e o modo simplesmente numérico será
correspondente ao 2. Quando o usuário abrir o programa e selecionar a opção
de exibição, o tipo da senha deve ser lido para decidir qual campo da união
apresentar na tela (campo alfanumérico ou o campo numérico).*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef union{
    char alfa[50];
    int num;
} Senha;

void gravarSenha(Senha *p){
    FILE *file = fopen("s.bin", "wb");
    if (file == 0) {
        printf("\n>> Erro ao abrir o arquivo, por favor tente novamente.\n");
        exit(1);
    }
    int tipo;
    
    printf("Escolha o tipo de senha:\n[1] Alfanumérica \n[2] Numérica\n");
    scanf("%d", &tipo);
    setbuf(stdin, NULL);
    
    if (tipo == 1) {
        printf("Digite a senha alfanumérica: ");
        fgets(p->alfa, sizeof(p->alfa), stdin);
        p->alfa[strcspn(p->alfa, "\n")] = '\0';
    } else if (tipo == 2) {
        printf("Digite a senha numérica: ");
        scanf("%d", &p->num);
    } else {
        printf("\n>> Opção inválida, por favor tente novamente\n");
        fclose(file);
        return;
    }
    fwrite(&tipo, sizeof(int), 1, file);
    fwrite(&p, sizeof(Senha), 1, file);
    fclose(file);
    printf("\n>> Senha salva com sucesso.\n");
}

void exibirSenha() {
    FILE *file = fopen("s.bin", "rb");
    if (file == NULL) {
        printf("\n>> O arquivo de senhas não existe.\n");
        return;
    }
    int tipo;
    Senha s;
    fread(&tipo, sizeof(int), 1, file);
    fread(&s, sizeof(Senha), 1, file);
    fclose(file);
    if (tipo == 1) {
        printf("Senha alfanumérica: %s\n", s.alfa);
    } else if (tipo == 2) {
        printf("Senha numérica: %d\n", s.num);
    } else {
        printf("\n>> Erro ao ler o tipo da senha.\n");
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int opc;
    Senha s;
    while(1){
        printf("\n[1] Gravar nova senha \n[2] Exibir senha armazenada \n[3] Sair \n");
        printf(">> Selecione a opção desejada: ");
        scanf("%d", &opc);
        setbuf(stdin, NULL);
        switch (opc){
            case 1:
                gravarSenha(&s);
                break;
            case 2:
                exibirSenha();
                break;
            case 3:
                printf("\n>> Obrigado, volte sempre.\n");
                return 0;
            default:
                printf("\n>> Opção inválida, por favor tente novamente.\n");
                break;
        }
    }
}