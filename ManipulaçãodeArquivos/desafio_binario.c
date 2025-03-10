#include<stdio.h>

void criararquivo() {
    FILE *arquivo = fopen("pessoas.bin", "wb");

    Pessoa pessoas[] = {
        {"Carlinhos", 30, 1.75},
        {"Mariazinha", 25, 1.65},
        {"Joãozinho", 40, 1.80}
    };

    fwrite(pessoas, sizeof(Pessoa), 3, arquivo);
    fclose(arquivo);

    printf("Arquivo 'pessoas.bin' criado com sucesso!\n");
}

void lerarquivo(){
    FILE *arquivo = fopen("pessoas.bin", "rb");

    Pessoa pessoa;

    printf("Pessoas no arquivo:\n");
    while(fread(&pessoa, sizeof(Pessoa), 1, arquivo)){
        printf("Nome: %s, Idade: %d, Altura: %.2f\n", pessoa.nome, pessoa.idade, pessoa.altura);
    }
    fclose(arquivo);
}

void alterarpessoa(const char* nome, int novaIdade){
    FILE *arquivo = fopen("pessoas.bin", "rb+");

    Pessoa pessoa;
    int pessoaAlterada = 0;

    while(fread(&pessoa, sizeof(Pessoa), 1, arquivo)){
        if (strcmp(pessoa.nome, nome) == 0){
            pessoa.idade = novaIdade;
            fseek(arquivo, -sizeof(Pessoa), SEEK_CUR);
            fwrite(&pessoa, sizeof(Pessoa), 1, arquivo);
            pessoaalterada = 1;
            break;
        }
    }
    fclose(arquivo);
    
    if(pessoaalterada){
        
    }
}


int main(){
    criararquivo();
    lerarquivo();
    printf("\n");
    alterarpessoa("Mariazinha", 28);

    lerarquivo();

    return 0;
}