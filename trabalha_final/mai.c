//Bibliotecas
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <dirent.h>

//Definições
#define TAMANHO_VOO 8
#define TAMANHO_RESER 9
#define TAMANHO_CPF 14
#define TAMANHO_STATUS 9
#define TAMANHO_NOME 300
#define TAMANHO_SEXO 15

//Declarando os structs

struct cadastrar_voo{
    char num_voo[TAMANHO_VOO];
    int quan_max_passag;
    int dia, mes, ano, hora, minutos;
    char status[TAMANHO_STATUS];
};

struct cadastrar_reserva{
    char num_reserva[TAMANHO_RESER];
    char CPF_passag[TAMANHO_CPF];
    char nome_passag[TAMANHO_NOME];
    char sexo[TAMANHO_SEXO];
    int dia,mes,ano;
    char status_reserv[TAMANHO_STATUS];
};

//Declarando os procedimentos que serão utilizados no menu de  Opções

void cadastrar_voo();
void cadastrar_reserva();
void consultar_voo();
void consultar_reserva();
void consultar_passageiro();
void cancelar_voo();
void cancelar_reserva();
void excluir_voo();

//Declarando os procedimentos que serão utilizados como cabeçalho no menu de Opções: estética

void cabecalho_casd_voo();
void cabecalho_casd_reserv();
void cabecalho_cons_voo();
void cabecalho_cons_reserv();
void cabecalho_cons_passag();
void cabecalho_canc_voo();
void cabecalho_canc_reser();
void cabecalho_excl_voo();
void gravando_voos();
void gravando_reservas();


int main()
{   setlocale(LC_ALL,"Portuguese");

    //Declarações
    float result;
    int num_opcao;
    FILE *arquivo_cadastrar_voo; 
    FILE *arquivo_cadastrar_reserva;
    struct cadastrar_reserva second; 
    struct cadastrar_voo first;
    
    
    
    
    printf("                 `. _");
    printf("                ,' _`.                ..----....\n");
    printf("    ...--.'``;.   ,.   ;``--..     .'    ,-._    _.-'\n");
printf("  ..-''-------'   `'   `'   `'     O ``-''.   (,;') _,'\n");
printf(",'__                          -._`-','\n");
printf(" `._              ``------..._   '-.._'-:\n");
printf("    --.._      ,.                     `--...__.\n");
printf("            `.--. `-`                       __    |  |`\n");
printf("              `. `.                       ,'``.  ;  ;`\n");
printf("                   `-:._///_`.         `\n");
printf("                               |       `._    `.    \n");
printf("                              `._`-.   `.   `._\n");
printf("                                               `------'`\n");
     
    
    
    //Menu de Opções
    printf("------------------------------------BEM-VINDO À GALATIC BIRDS-----------------------------------\n");
    printf("\n");
    printf("-----------------------------------------Menu de Opções-----------------------------------------\n");
    printf("\n");
    printf("1) Cadastrar voo\n");
    printf("2) Cadastrar reserva\n");
    printf("3) Consultar voo\n");
    printf("4) Consultar reserva\n");
    printf("5) Consultar passageiro\n");
    printf("6) Cancelar voo\n");
    printf("7) Cancelar reserva\n");
    printf("8) Excluir voo\n");
    printf("9) Sair do programa\n");
    printf("\n");
    printf("Por gentileza, digite o número da opção desejada\n");
    scanf("%d",&num_opcao);
    if(num_opcao==1){
        //Realizando o cadastro de um voo
        cabecalho_casd_voo();
        cadastrar_voo();
        gravando_voos();
        main();
    }else{
        if(num_opcao==2){
            //Realizando o cadastro de uma reserva
            cabecalho_casd_reserv();
            cadastrar_reserva();
            gravando_reservas();
            main();
        }else{
            if(num_opcao==3){
                //Realizando a consulta de um voo
                cabecalho_cons_voo();
                consultar_voo();
                main();
            }else{
                if(num_opcao==4){
                    //Realizando a consulta de uma reserva
                    cabecalho_cons_reserv();
                    consultar_reserva();
                    main();
                }else{
                    if(num_opcao==5){
                        //Realizando a consulta de um passageiro
                        cabecalho_cons_passag();
                        consultar_passageiro();
                        main();
                    }else{
                        if(num_opcao==6){
                            //Realizando o cancelamento de um voo
                            cabecalho_canc_voo();
                            cancelar_voo();
                            main();
                        }else{
                            if(num_opcao==7){
                                //Realizando o cancelamento de uma reserva
                                cabecalho_canc_reser();
                                cancelar_reserva();
                                main();
                            }else{
                                if(num_opcao==8){
                                    //Realizando a exclusão de um voo
                                    cabecalho_excl_voo();
                                    excluir_voo();
                                    main();
                                }else{
                                    //Opção para sai do código
                                    if(num_opcao==9){
                                        printf("-----------------Obrigado por utilizar os serviços da Galatic Birds!-----------------\n");
                                    }else{
                                        printf("Opção inválida!\n");
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}

//Procedimento para cadastrar um voo
void cadastrar_voo(){
    //Declarando as variáveis precisas para cadastrar um voo
    struct cadastrar_voo first;

    //Instruções para cadastrar um voo
    printf("Por gentileza, digite o número do voo no formato JEB-XXXX, em que XXXX são dígitos numéricos:\n");
    
    //Lendo o número do voo no formato JEB-XXXX
    scanf("%s",first.num_voo);
    while(1){
        if(strlen(first.num_voo)==TAMANHO_VOO && first.num_voo[0]=='J' && first.num_voo[1]=='E' && first.num_voo[2]=='B'&& first.num_voo[3]=='-' && first.num_voo[4]>='0' && first.num_voo[4]<='9' && first.num_voo[5]>='0' && first.num_voo[5]<='9' && first.num_voo[6]>='0' && first.num_voo[6]<='9' && first.num_voo[7]>='0' && first.num_voo[7]<='9'){
           printf("\n");
        printf("Número de voo cadastrado! O número de voo é: %s \n",first.num_voo);
        break; 
        }else{
        printf("O número de voo digitado é inválido!Digite Novamente o no formato JEB-XXXX em que XXXX são dígitos numéricos:\n");
        scanf("%s",first.num_voo);
    }
    
    }
    printf("\n");
    
    
    //Lendo a quantidade de passageiros no voo
    printf("Por gentileza, digite a quantidade de passageiros no voo:\n");
    scanf("%i",&first.quan_max_passag);
    printf("\n");
    printf("O número de passageiros do voo é: %i\n",first.quan_max_passag);
    printf("\n");
    printf("Por gentileza, digite o dia, o mês, o ano, a hora e os minutos da data de partida do voo,respectivamente: de modo que ao digitar o dia, aperte a tecla enter, depois após digitar o mês, aperte a tecla enter e assim sucessivamente. APENAS NÚMEROS\n");
    
    //lendo a data e o horário do voo
    scanf("%d %d %d %d %d",&first.dia,&first.mes,&first.ano,&first.hora,&first.minutos);
    printf("\n");
    while(1){
    if(first.dia<0 || first.mes<0 || first.ano<0 || first.ano<2030 || first.hora<0 || first.minutos<0){
        printf("Data de voo invalida.\n");
        scanf("%d %d %d %d %d",&first.dia,&first.mes,&first.ano,&first.hora,&first.minutos);
        
    }else{
        if(first.hora<0 || first.hora>23 || first.minutos<0 || first.minutos>59){
            printf("Data de voo invalida.\n");
            scanf("%d %d %d %d %d",&first.dia,&first.mes,&first.ano,&first.hora,&first.minutos);
            
        }else{
            if(first.dia<=0 || first.dia>31 || first.mes<=0 || first.mes>12){
                printf("Data de voo invalida.\n");
                scanf("%d %d %d %d %d",&first.dia,&first.mes,&first.ano,&first.hora,&first.minutos);
                
            }else{
                if(first.dia<=31 && (first.mes==1 || first.mes==3 || first.mes==5 || first.mes==7 || first.mes==8 || first.mes==10 || first.mes==12)){
                    printf("A Data e o horário de partida do voo são: %d/%d/%d, às %d:%d horas.\n",first.dia,first.mes,first.ano,first.hora,first.minutos);
                    break;
                }else{
                    if(first.dia<=30 &&(first.mes==4 || first.mes==6 || first.mes==9 || first.mes==11)){
                        printf("A Data e o horário de partida do voo são: %d/%d/%d, às %d:%d horas.\n",first.dia,first.mes,first.ano,first.hora,first.minutos);
                        break;
                    }else{
                        if(first.dia<=28 && first.mes==2){
                            printf("A Data e o horário de partida do voo são: %d/%d/%d, às %d:%d horas.\n",first.dia,first.mes,first.ano,first.hora,first.minutos);
                            break;
                        }else{
                            if(first.dia>=1 && first.dia<=28 && first.mes==2){
                               printf("A Data e o horário de partida do voo são: %d/%d/%d, às %d:%d horas.\n",first.dia,first.mes,first.ano,first.hora,first.minutos);
                               break;
                            }else{
                                if((first.ano % 4 ==0 && first.ano % 100!=0)|| first.ano % 400){
                                    printf("A Data e o horário de partida do voo são: %d/%d/%d, às %d:%d horas.\n",first.dia,first.mes,first.ano,first.hora,first.minutos);
                                    break;
                                }else{
                                    if(first.dia==29 && first.mes==2){
                                        printf("A Data e o horário de partida do voo são: %d/%d/%d, às %d:%d horas.\n",first.dia,first.mes,first.ano,first.hora,first.minutos);
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    }
    printf("\n");
    printf("Digite o status do voo com letras minúsculas, sendo que ele só pode estar ativo ou cancelado:\n");
    getc(stdin);
    char ativo[]="ativo";
    
    //Lendo o status do voo
    scanf("%s",first.status);
    
    while(1){
    if(strcmp(first.status,ativo)==0){
        printf("O status do voo é: ativo\n");
        break;
    }else{
        if(strcmp(first.status,"cancelado")==0){
            printf("O status do voo é cancelado\n");
            break;
        }else{
            printf("O status do voo digitado é invalido!Digite o status novamente\n");
            scanf("%s",first.status);
            
        }
    }
    }
    printf("\n");
}

//Procedimento para gravar voos em arquivos
void gravando_voos(){
    //Declarando as variáveis necessárias para gravar os voos num arquivo
    char nome_arquivo_voo[TAMANHO_VOO];
    
    //Gravando os dados do struct cadastrar_voo num arquivo
    //1)Criando um arquivo, gravando e salvando
    FILE *arquivo_cadastrar_voo;
    struct cadastrar_voo first;
    printf("\n");
    printf("Por gentileza, digite o mesmo número de voo digitado anteriormente no formato JEB-XXXX em que XXXX são dígitos numéricos\n");
    
    getc(stdin);
    
    //Dando nome ao arquivo de voo a ser criado
    scanf("%s",nome_arquivo_voo);
    getc(stdin);
    
    //Abrindo o arquivo
    arquivo_cadastrar_voo= fopen(nome_arquivo_voo,"wb");
    
    //Escrevendo no arquivo
    fwrite(&first,sizeof(struct cadastrar_voo),1, arquivo_cadastrar_voo);
    
    //Fechando o arquivo
    fclose(arquivo_cadastrar_voo);
    printf("\n");
}

//Procedimento para cadastrar reserva
void cadastrar_reserva(){
    //Declarando as variáveis necessárias para cadastrar um voo
    struct cadastrar_reserva second; 
    char nome_arquivo_reserva[TAMANHO_RESER];
    
    
    printf("Por gentileza, digite o número de reserva no formato GB-XXXXXX, em que XXXXXX são dígitos numéricos:\n");
    
    //Lendo o número do voo no formato GB-XXXXXX
    scanf("%s",second.num_reserva);
    while(1){
    if(strlen(second.num_reserva)==TAMANHO_RESER && second.num_reserva[0]=='G' && second.num_reserva[1]=='B' && second.num_reserva[2]=='-' && second.num_reserva[3]>='0'&& second.num_reserva[3]<='9'&& second.num_reserva[4]>='0' && second.num_reserva[4]<='9' && second.num_reserva[5]>='0' && second.num_reserva[5]<='9' && second.num_reserva[6]>='0' && second.num_reserva[6]<='9' && second.num_reserva[7]>='0' && second.num_reserva[7]<='9' && second.num_reserva[8]>='0' && second.num_reserva[8]<='9'){
        printf("\n");
        printf("Reserva de voo cadastrada! O número de reserva é: %s\n",second.num_reserva);
        break;
    }else{
        printf("O número de reserva digitado é inválido, por favor, digite novamente!\n");
        scanf("%s",second.num_reserva);
    }
    printf("\n");
    }
    
    //Lendo o CPF do passageiro no formato XXX.XXX.XXX-XX
    printf("Por gentileza, digite o CPF no Formato XXX.XXX.XXX-XX, EM QUE X são dígitos numéricos:\n");
    scanf("%s",second.CPF_passag);
    while(1){
    if(strlen(second.CPF_passag)==TAMANHO_CPF &&second.CPF_passag[0]>='0' && second.CPF_passag[0]<='9' && second.CPF_passag[1]>='0' && second.CPF_passag[1]<='9' && second.CPF_passag[2]>='0' && second.CPF_passag[2]<='9' && second.CPF_passag[3]=='.' && second.CPF_passag[4]>='0' && second.CPF_passag[4]<='9' && second.CPF_passag[5]>='0' && second.CPF_passag[5]<='9' && second.CPF_passag[6]>='0' && second.CPF_passag[6]<='9' && second.CPF_passag[7]=='.' && second.CPF_passag[8]>='0' && second.CPF_passag[8]<='9' && second.CPF_passag[9]>='0' && second.CPF_passag[9]<='9' && second.CPF_passag[10]>='0' && second.CPF_passag[10]<='9' && second.CPF_passag[11]=='-' && second.CPF_passag[12]>='0' && second.CPF_passag[12]<='9' && second.CPF_passag[13]>='0' && second.CPF_passag[13]<='9'){
        printf("Número de CPF cadastrado! O número de CPF é: %s",second.CPF_passag);
        break;
    }else{
        printf("O número de CPF digitado é inválido, por favor, digite novamente!\n");
        scanf("%s",second.CPF_passag);
    }
    }
    printf("\n");
    printf("\n");
    printf("Digite o nome completo do passageiro:\n");//Lendo o nome completo do passageiro
    getc(stdin);
    
    //Lendo o nome do passageiro
    scanf("%[^\n]s",second.nome_passag);
    printf("\n");
    printf("Nome Digitado:\n");
    puts(second.nome_passag);
    printf("\n");
    printf("Por gentileza,digite o sexo masculino ou feminino\n");
    getc(stdin);
    
    //Lendo o sexo do passageiro
    scanf("%s",second.sexo);
    while(1){
    if(strcmp(second.sexo,"masculino")==0){
        printf("O sexo do passageiro é masculino\n");
        break;
    }else{
        if(strcmp(second.sexo,"feminino")==0){
            printf("O sexo do passageiro é feminino\n");
            break;
        }else{
            printf("Dado incorreto, por favor, digite novamente!\n");
            scanf("%s",second.sexo);
        }
    }
    }
    printf("\n");
    printf("Digite a data de nascimento do passageiro\n");
    
    //Lendo a data de nascimento do passageiro
    scanf("%d %d %d",&second.dia,&second.mes,&second.ano);
    
    while(1){
    if(second.dia<0 || second.mes<0 || second.ano<0 || second.ano<1941){
        printf("Data de nascimento invalida.\n");
        scanf("%d %d %d",&second.dia,&second.mes,&second.ano);
    }else{
        if(second.dia<=0 || second.dia>31 || second.mes<=0 || second.mes>12){
            printf("Data de nascimento invalida.\n");
            scanf("%d %d %d",&second.dia,&second.mes,&second.ano);
        }else{
            if(second.dia<=31 && (second.mes==1 || second.mes==3 || second.mes==5 || second.mes==7 || second.mes==8 || second.mes==10 || second.mes==12)){
                printf("A Data de nascimento do passageiro é: %d/%d/%d \n",second.dia,second.mes,second.ano);
                break;
            }else{
                if(second.dia<=30 &&(second.mes==4 || second.mes==6 || second.mes==9 || second.mes==11)){
                    printf("A Data de nascimento do passageiro é: %d/%d/%d \n",second.dia,second.mes,second.ano);
                    break;
                }else{
                    if(second.dia<=28 && second.mes==2){
                        printf("A Data de nascimento do passageiro é: %d/%d/%d \n",second.dia,second.mes,second.ano);
                        break;
                    }else{
                        if(second.dia>=1 && second.dia<=28 && second.mes==2){
                            printf("A Data de nascimento do passageiro é: %d/%d/%d \n",second.dia,second.mes,second.ano);
                            break;
                        }else{
                            if((second.ano % 4 ==0 && second.ano % 100!=0)|| second.ano % 400){
                                printf("A Data de nascimento do passageiro é: %d/%d/%d \n",second.dia,second.mes,second.ano);
                                break;
                            }else{
                                if(second.dia==29 && second.mes==2){
                                    printf("A Data de nascimento do passageiro é: %d/%d/%d \n",second.dia,second.mes,second.ano);
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    }
    printf("\n");
    
    //Lendo o status da reserva do passageiro
    printf("Digite o status da reserva, sendo ativo ou cancelado:\n ");
    getc(stdin);
    scanf("%s",second.status_reserv);
    
    while(1){
    if(strcmp(second.status_reserv,"ativo")==0){
        printf("O status da reserva é ativo\n");
        break;
    }else{
        if(strcmp(second.status_reserv,"cancelado")==0){
            printf("O status da reserva é cancelado\n");
            break;
        }else{
            printf("Dado incorreto!Por favor, digite novamente\n");
            scanf("%s",second.status_reserv);
        }
    }
    }
    printf("\n");
}

//Procedimento para gravar reservas
void gravando_reservas(){
    
    //Declarando variáveis necessárias para gravar uma reserva
    FILE *arquivo_cadastrar_reserva;
    struct cadastrar_reserva second;
    char nome_arquivo_reserva[TAMANHO_RESER+1];
    
    
   
    //Gravando os dados do struct cadastrar_reserva num arquivo
    //1)Criando um arquivo, gravando e salvando
    getc(stdin);
    
    //Lendo o número da reserva
    printf("Por gentileza, digite o mesmo número de reserva digitado anteriormente no formato GB-XXXXXX em que XXXXXX são dígitos numéricos\n");
    scanf("%s",nome_arquivo_reserva);
    
    //Abrindo arquivo
    arquivo_cadastrar_reserva= fopen(nome_arquivo_reserva,"wb");
    
    //Escrevendo no arquivo
    fwrite(&second,sizeof(struct cadastrar_reserva),1, arquivo_cadastrar_reserva);
    
    //Fechando o arquivo
    fclose(arquivo_cadastrar_reserva);
    printf("\n");
    
}


//Procedimento para consultar voo
void consultar_voo(){
    
    //Declarando as variáveis necessárias para consultar um voo
    FILE *arquivo_cadastrar_voo;
    struct cadastrar_voo first;
    char num_voo_valida[TAMANHO_VOO];
    
    //Lendo o número do voo
    printf("Digite o número do voo que deseja consultar no formato JEB-XXXX, em que XXXX são dígitos numéricos:\n");
    scanf("%s",num_voo_valida);
    
    //Abrindo o arquivo
    arquivo_cadastrar_voo = fopen(num_voo_valida,"rb");
    
    //Lendo o arquivo
    fread(&first,sizeof(struct cadastrar_voo),1,arquivo_cadastrar_voo);
    
    //printando o que há no arquivo no terminal
    printf("\n");
    printf("N° voo:%.8s  - Data:%d/%d/%d -  Hora:%d:%d , status:%.9s e Quan.MáX.passageiro: %d \n", first.num_voo,first.dia, first.mes, first.ano, first.hora,first.minutos,first.status,first.quan_max_passag);
    printf("\n");
    
    //Fcehando o arquivo
    fclose(arquivo_cadastrar_voo);
}

//Procedimento para consultar reserva
void consultar_reserva(){
    
    //Declarando as variáveis necessárias para consultar uma reserva
    FILE *arquivo_cadastrar_reserva;
    struct cadastrar_reserva second;
    char num_reserva_valida[TAMANHO_RESER];
    
    //Lendo o número da reserva
    printf("Por gentileza, digite o número do da reserva que deseja consultar no formato GB-XXXXXX em que XXXXXX são dígitos numéricos:\n");
    scanf("%s",num_reserva_valida);
    
    //Abrindo o arquivo
    arquivo_cadastrar_reserva = fopen(num_reserva_valida,"rb");
    
    //Lendo o arquivo
    fread(&second,sizeof(struct cadastrar_reserva),1,arquivo_cadastrar_reserva);
    
    //printando o que há no arquivo no terminal
    printf("\n");
    printf("Nome: %s - CPF: %s - Sexo: %s - Data de Nascimento: %d/%d/%d - Status da reserva: %.9s \n ",second.nome_passag,second.CPF_passag,second.sexo,second.dia,second.mes,second.ano,second.status_reserv);
    printf("\n");    
    fclose(arquivo_cadastrar_reserva);   
}

//Procedimento para consultar passageiro
void consultar_passageiro(){                 
    
    //Declarando as variáveis necessárias para consultar um passageiro
    FILE *arquivo_cadastrar_reserva;
    struct cadastrar_reserva second;
    char CPF_passag_valida[TAMANHO_CPF];
    
    DIR* pasta = opendir(".");
    struct dirent *arquivo;

    printf("Digite o número CPF do passageiro que deseja consultar no fomarto XXX.XXX.XXX-XX, em que X são dígitos numéricos:\n");
    scanf("%s", CPF_passag_valida);
    
    if(strlen(second.CPF_passag)==TAMANHO_CPF &&second.CPF_passag[0]>='0' && second.CPF_passag[0]<='9' && second.CPF_passag[1]>='0' && second.CPF_passag[1]<='9' && second.CPF_passag[2]>='0' && second.CPF_passag[2]<='9' && second.CPF_passag[3]=='.' && second.CPF_passag[4]>='0' && second.CPF_passag[4]<='9' && second.CPF_passag[5]>='0' && second.CPF_passag[5]<='9' && second.CPF_passag[6]>='0' && second.CPF_passag[6]<='9' && second.CPF_passag[7]=='.' && second.CPF_passag[8]>='0' && second.CPF_passag[8]<='9' && second.CPF_passag[9]>='0' && second.CPF_passag[9]<='9' && second.CPF_passag[10]>='0' && second.CPF_passag[10]<='9' && second.CPF_passag[11]=='-' && second.CPF_passag[12]>='0' && second.CPF_passag[12]<='9' && second.CPF_passag[13]>='0' && second.CPF_passag[13]<='9'){
        printf("Digite o número CPF do passgeiro que deseja consultar no fomarto XXX.XXX.XXX-XX, em que X são dígitos numéricos:\n");
        scanf("%s", CPF_passag_valida);
    }

    if (pasta){

        while ((arquivo = readdir(pasta)) != NULL) {
            // verifica se o arquivo é de reserva no formato GB-XXXXXX
            if (arquivo->d_name[0] == 'G' && arquivo->d_name[1] == 'B'){
                FILE *file = fopen(arquivo->d_name,"rb");
                fread(&second, sizeof(struct cadastrar_reserva), 1, file);
                if(strcmp(second.CPF_passag,CPF_passag_valida)){
                    printf("Nome do passageiro: %s - Data de Nascimento %d/%d/%d - Sexo: %s e Status da reserva: %.9s \n",second.nome_passag,second.dia,second.mes,second.ano,second.sexo,second.status_reserv);
               
                }
                fclose(file);
            }
        }
        
    }
    
}

//Procedimento para cancelar voo
void cancelar_voo(){
    //Declarando as variáveis necessárias para cadastrar um voo
    struct cadastrar_voo second; 
    char nome_arquivo_voo[TAMANHO_VOO];
    
    
    printf("Por gentileza, digite o número do voo no formato JEB-XXXX, em que XXXX são dígitos numéricos:\n");
    
    //Lendo o número do voo no formato GB-XXXXXX
    scanf("%s",second.num_voo);
    if(strlen(second.num_voo)==TAMANHO_RESER && second.num_voo[0]=='J' && second.num_voo[1]=='E' && second.num_voo[2]=='B' && second.num_voo[3]=='-' && second.num_voo[4]>='0'&& second.num_voo[4]<='9'&& second.num_voo[5]>='0' && second.num_voo[5]<='9' && second.num_voo[6]>='0' && second.num_voo[6]<='9' && second.num_voo[7]>='0' && second.num_voo[7]<='9' && second.num_voo[8]>='0' && second.num_voo[8]<='9' && second.num_voo[9]>='0' && second.num_voo[9]<='9'){
        printf("\n");
        printf("Reserva de voo cadastrada! O número de reserva é: %s\n",second.num_voo);
    }else{
        printf("O número de voo digitado é inválido, por favor, digite novamente!\n");
    }
    printf("\n");
    nome_arquivo_voo[0]=second.num_voo[0];
    nome_arquivo_voo[1]=second.num_voo[1];
    nome_arquivo_voo[2]=second.num_voo[2];
    nome_arquivo_voo[3]=second.num_voo[3];
    nome_arquivo_voo[4]=second.num_voo[4];
    nome_arquivo_voo[5]=second.num_voo[5];
    nome_arquivo_voo[6]=second.num_voo[6];
    nome_arquivo_voo[7]=second.num_voo[7];
    nome_arquivo_voo[8]=second.num_voo[8];
    
    
    FILE *arquivo = fopen(nome_arquivo_voo,"rb");
    if(arquivo != NULL){
        fread(&second,sizeof(struct cadastrar_voo),1,arquivo);
        fclose(arquivo);
        arquivo = fopen(nome_arquivo_voo,"wb");
        if(strcmp(second.status,"cancelado")){
            second.status[0]= 'c';
            second.status[1]= 'a';
            second.status[2]= 'n';
            second.status[3]= 'c';
            second.status[4]= 'e';
            second.status[5]= 'l';
            second.status[6]= 'a';
            second.status[7]= 'd';
            second.status[8]= 'o';
            
            fwrite(&second,sizeof(struct cadastrar_voo),1,arquivo);
            fclose(arquivo);
            
        }
        
    }else{
        fclose(arquivo);
    }
}

//Procedimento para cancelar reserva
void cancelar_reserva(){
    //Declarando as variáveis necessárias para cadastrar um voo
    struct cadastrar_reserva second; 
    char nome_arquivo_reserva[TAMANHO_RESER];
    
    
    printf("Por gentileza, digite o número de reserva no formato GB-XXXXXX, em que XXXXXX são dígitos numéricos:\n");
    
    //Lendo o número do voo no formato GB-XXXXXX
    scanf("%s",second.num_reserva);
    if(strlen(second.num_reserva)==TAMANHO_RESER && second.num_reserva[0]=='G' && second.num_reserva[1]=='B' && second.num_reserva[2]=='-' && second.num_reserva[3]>='0'&& second.num_reserva[3]<='9'&& second.num_reserva[4]>='0' && second.num_reserva[4]<='9' && second.num_reserva[5]>='0' && second.num_reserva[5]<='9' && second.num_reserva[6]>='0' && second.num_reserva[6]<='9' && second.num_reserva[7]>='0' && second.num_reserva[7]<='9' && second.num_reserva[8]>='0' && second.num_reserva[8]<='9'){
        printf("\n");
        printf("Reserva de voo cadastrada! O número de reserva é: %s\n",second.num_reserva);
    }else{
        printf("O número de reserva digitado é inválido, por favor, digite novamente!\n");
    }
    printf("\n");
    nome_arquivo_reserva[0]=second.num_reserva[0];
    nome_arquivo_reserva[1]=second.num_reserva[1];
    nome_arquivo_reserva[2]=second.num_reserva[2];
    nome_arquivo_reserva[3]=second.num_reserva[3];
    nome_arquivo_reserva[4]=second.num_reserva[4];
    nome_arquivo_reserva[5]=second.num_reserva[5];
    nome_arquivo_reserva[6]=second.num_reserva[6];
    nome_arquivo_reserva[7]=second.num_reserva[7];
    nome_arquivo_reserva[8]=second.num_reserva[8];
    
    
    FILE *arquivo = fopen(nome_arquivo_reserva,"rb");
    if(arquivo != NULL){
        fread(&second,sizeof(struct cadastrar_reserva),1,arquivo);
        fclose(arquivo);
        arquivo = fopen(nome_arquivo_reserva,"wb");
        if(strcmp(second.status_reserv,"cancelado")){
            second.status_reserv[0]= 'c';
            second.status_reserv[1]= 'a';
            second.status_reserv[2]= 'n';
            second.status_reserv[3]= 'c';
            second.status_reserv[4]= 'e';
            second.status_reserv[5]= 'l';
            second.status_reserv[6]= 'a';
            second.status_reserv[7]= 'd';
            second.status_reserv[8]= 'o';
            
            fwrite(&second,sizeof(struct cadastrar_reserva),1,arquivo);
            fclose(arquivo);
            
        }
        
    }else{
        fclose(arquivo);
    }
}

//Procedimento para excluir voo
void excluir_voo(){
    FILE *arquivo_cadastrar_voo;
    struct cadastrar_voo first;
    
    printf("Por gentileza, digite o número do voo a ser excluído no formato JEB-XXXX em que XXXX são dígitos numéricos:\n");
    scanf("%s",first.num_voo);
    remove(first.num_voo);
    
    
}

//Cabeçalho para cadastrar voo
void cabecalho_casd_voo(){
    printf("\n");
    printf("-----------------------------------\n");
    printf("CADASTRO DE VOOS\n");
    printf("-----------------------------------\n");
    printf("\n");
}

//Cabeçalho para cadastrar reserva 
void cabecalho_casd_reserv(){
    printf("\n");
    printf("-----------------------------------\n");
    printf("CADASTRO DE RESERVAS\n");
    printf("-----------------------------------\n");
    printf("\n");
}

//Cabeçalho para consultar voo
void cabecalho_cons_voo(){
    printf("\n");
    printf("-----------------------------------\n");
    printf("CONSULTA DE VOOS\n");
    printf("-----------------------------------\n");
    printf("\n");
}

//Cabeçalho para consultar reserva
void cabecalho_cons_reserv(){
    printf("\n");
    printf("-----------------------------------\n");
    printf("CONSULTA DE RESERVAS\n");
    printf("-----------------------------------\n");
    printf("\n");
}

//Cabeçalho para consultar passageiro
void cabecalho_cons_passag(){
    printf("\n");
    printf("-----------------------------------\n");
    printf("CONSULTA DE PASSAGEIROS\n");
    printf("-----------------------------------\n");
    printf("\n");
}

//Cabeçalho para cancelar voo
void cabecalho_canc_voo(){
    printf("\n");
    printf("-----------------------------------\n");
    printf("CANCELAMENTO DE VOOS\n");
    printf("-----------------------------------\n");
    printf("\n");
}

//Cabeçalho para cancelar reserva 
void cabecalho_canc_reser(){
    printf("\n");
    printf("-----------------------------------\n");
    printf("CANCELAMENTO DE RESERVAS\n");
    printf("-----------------------------------\n");
    printf("\n");
}

//Cabeçalho para excluir voo
void cabecalho_excl_voo(){
    printf("\n");
    printf("-----------------------------------\n");
    printf("EXCLUSÃO DE VOOS\n");
    printf("-----------------------------------\n");
    printf("\n");
}