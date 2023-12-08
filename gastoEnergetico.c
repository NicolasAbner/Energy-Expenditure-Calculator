#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <math.h>


char cidade[4];
float tarifa;
float meta;
float ult_consumo;
float equipamentos[12]; 
float qntdEquip[6];
float totalConsumo[20];
float metaConsumo;
float contaLuz;
float consumoGeral;
int cid = 0;

void menu(){
    
    printf("-----------------------------------------------\n");
    printf("--- CALCULADORA DE META DE GASTO ENERGETICO ---\n");
    printf("-----------------------------------------------\n");

}

float calcTarifa(){

    printf("INFORME A CIDADE QUE RESIDE:\n");
    printf("CXS - Caxias do Sul\n");
    printf("POA - Porto Alegre\n");
    printf("NH - Novo Hamburgo\n");
    printf("FR - Farroupilha\n");
    printf("FC - Flores da Cunha\n");
    printf("GM - Gramado\n");
    printf("FZ - Feliz\n");
    
    scanf("%s", &cidade);
    strupr(cidade);
    
    if (strcmp(cidade, "CXS") == 0){
        tarifa = 0.7;
    } else if (strcmp(cidade, "POA") == 0){
        tarifa = 0.6;
    } else if (strcmp(cidade, "NH") == 0){
        tarifa = 0.7;
    } else if (strcmp(cidade, "FR") == 0){
        tarifa = 0.6;
    } else if (strcmp(cidade, "FC") == 0){
        tarifa = 0.7;
    } else if (strcmp(cidade, "GM") == 0){
        tarifa = 0.7;
    } else if (strcmp(cidade, "FZ") == 0){
        tarifa = 0.6;
    } else {
        printf("Nomenclatura nao encontrada! Utilizando tarifa media para calculo.\n");
        cid = 1;
        tarifa = 0.7;
    }

        
    return tarifa;

}

float metaGasto(){

    printf("INFORME SUA META MENSAL;\n");
    scanf("%f", &meta);
    
    if (meta < 30){
        
        printf("VALOR INVALIDO IMPOSSIVEL CALCULAR. VALOR MINIMO: R$30,00\n");
        exit(1);

    }

    return meta;

}

float consumoAnterior(){
        
    printf("INFORME SEU ULTIMO CONSUMO DE ENERGIA:(EM KwH)\n");
    scanf("%f", &ult_consumo);

    if (ult_consumo <= 0){

        printf("VALOR INVALIDO IMPOSSIVEL CALCULAR\n");
        exit(1);

    }

    return ult_consumo;
}

float cadastroEletrodomesticos(){

    for (int x = 0; x <= 6; x++){

        printf("----------------------------------------------------\n");
        printf("CADASTRE SEUS PRINCIPAIS ELETRODOMESTICOS (Em KwH)\n");
        printf("----------------------------------------------------\n");
        printf("Caso nao possua o eletrodomestico, informe: 0!\n\n");

        if (x == 0){
            printf("INFORME O CONSUMO MEDIO DE SUA GELADEIRA:\n");
        } else if (x == 1){
            printf("FOGAO/COOKTOP:\n");
        } else if (x == 2){
            printf("CHUVEIRO ELETRICO:\n");
        } else if (x == 3){
            printf("CARREGADOR DE CELULAR:\n");
        } else if (x == 4){
            printf("FORNO:\n");
        } else if (x == 5){
            printf("MICROONDAS:\n");
        } else{
            printf("TELEVISAO:\n");           
        }
        
        scanf(" %f", &equipamentos[x]);

        printf("QUANTIDADE DE EQUIPAMENTOS NA RESIDENCIA...\n");
        scanf(" %f", &qntdEquip[x]);
        system("cls");
    }

}

float reajuste(float taxaTarifa, float metaAtual, float uConsumo, float *equipamentos, float *qntdEquip){

    contaLuz = taxaTarifa * uConsumo;
    metaConsumo = (metaAtual / taxaTarifa);

    for (int i = 0; i <= 6; i++){
        totalConsumo[i] = (equipamentos[i] * qntdEquip[i]);
    }

    for (int i = 0; i <= 6; i++){
        consumoGeral = consumoGeral + totalConsumo[i];
    }

    return consumoGeral;
    
}

int relatorio(int cid, float uConsumo, float metaAtual, float metaConsumo, float *totalConsumo, float consumoGeral){

    printf("Pressione qualquer tecla para visualizar o relatorio....\n");
    getch();
    system("cls");
    printf("--------------------------------");
    printf(" RELATORIO DE REDUCAO DE CONSUMO!");
    printf("--------------------------------\n");

    if (cid == 1){
        printf("CIDADE DESCONHECIDA\n");
        printf("TARIFA ASSUMIDA: %.2f\n", tarifa);
    } else{
        printf("SIGLA DA CIDADE: %s\n", cidade);
        printf("TARIFA - CIDADE: %.2f / %s\n", tarifa, cidade);
    }


    printf("CONSUMO MEDIO ANTERIOR DE ENERGIA (KhW): %.2f\n", uConsumo);
    printf("GASTO MONETARIO MES ANTERIOR: R$ %.2f\n", contaLuz);
    printf("META DE GASTO MONETARIO: R$%.2f\n", metaAtual);

    printf("CONSUMO MAXIMO DE ENERGIA (KwH): %.2f\n", metaConsumo);

    printf("Pressione qualquer tecla para continuar....\n\n");
    getch();

    for (int x = 0; x <= 6; x++){

        if (x == 0){
            printf("EQUIPAMENTOS CADASTRADOS / CONSUMO MEDIO MENSAL:\n");
        }else if (x == 1){
            printf("FOGAO/COOKTOP:\n");
        } else if (x == 2){
            printf("CHUVEIRO ELETRICO:\n");
        } else if (x == 3){
            printf("CARREGADOR DE CELULAR:\n");
        } else if (x == 4){
            printf("FORNO:\n");
        } else if (x == 5){
            printf("MICROONDAS:\n");
        } else{
            printf("TELEVISAO:\n");           
        }

        if (x > 0){
            printf("CONSUMO: %.2f\n\n", totalConsumo[x]);
        }
        

    }

    float estimativa = consumoGeral * tarifa;
    float reducao = consumoGeral - metaConsumo;
    printf("Pressione qualquer tecla para continuar....\n\n");
    getch();
    printf("CONSUMO TOTAL DOS EQUIPAMENTOS CADASTRADOS EM MEDIA MENSAL (KwH): %.2f\n", consumoGeral);
    printf("GASTO ESTIMADO: R$ %.2f\n", estimativa);
    printf("ACONSELHAVEL REDUCAO DE: %.1f KwH\n", reducao);

}

int validaSistema(){

    int laco = 0;

    getch();
    printf("DESEJA REALIZAR OUTRA CONSULTA?\n");
    printf("1- SIM\n");
    printf("2- NAO/SAIR\n");
    scanf(" %d", &laco);

    if ((laco <= 0) || (laco > 2)){

        printf("OPCAO INVALIDA! TENTE NOVAMENTE!");

    }

    return laco;
    
}


//FUNÇÃO PRINCIPAL
int main(){

    int programa = 1;
    float taxaTarifa;
    float metaAtual;
    float uConsumo;
    float gastoEquip;

   menu();
   getch();
   
    //LAÇO INICIO DO PROGRAMA
    do{

        //LEVANTAMENTO DE DADOS
        taxaTarifa = calcTarifa();

        metaAtual = metaGasto();

        uConsumo = consumoAnterior();

        system("cls");
        cadastroEletrodomesticos();

        // RELATÓRIO DOS DADOS
        reajuste(taxaTarifa, metaAtual, uConsumo, equipamentos, qntdEquip);

        relatorio(cid, uConsumo, metaAtual, metaConsumo, totalConsumo, consumoGeral);

        programa = validaSistema();

        if (programa == 1){
            system("cls");
            cid = 0;
        }

    }while (programa == 1);

    system("cls");
    printf("OBRIGADO POR CONSULTAR! VOLTE SEMPRE!\n ");
    getch();
    system("cls");

}