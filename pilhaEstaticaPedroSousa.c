#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
//definindo a constante que será o tamanho do vetor da pilha
#define MAX 100

/*
	Pedro Sousa 
	Engennharia da Computação  
	Algoritmos e Estrutura de Dados II 
*/

// Definindo a struct pilha estática
typedef struct pilha
{
	// variável que armanezará a posição do topo
    int topo;
    // vetor para armazenar os valores
    int vet[MAX];
} pilha;

// Função para inicializar a pilha
pilha *criaPilha()
{
	// criando a pilha na função
    pilha *p;
    // armazenando espaço de memória para ela
    p = (pilha *)malloc(1 * sizeof(pilha));
    // definindo a posição inicial do topo
    p->topo = -1;
    // retornando a pilha criada
    return p;
}

// função para verificar se a pilha está vazia 
int estahVazia(pilha *p)
{
	// verificando se está vazia de acordo com a posição do topo
    if (p->topo == -1)
    {
    	// retornando 1 para verdadeiro
        return 1;
    }
    else
    {
    	// retornando 0 para falso
        return 0;
    }
}

// função para verificar se a pilha está cheia 
int estahCheia(pilha *p)
{
	// verificando se está cheia através da posição do topo, 
	// se é o máximo estabelecido pela constante -1 (pois conta-se o 0)
    if (p->topo == MAX-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// função para imprimir o topo da pilha
int imprimeTopo(pilha *p)
{
	// verificando se está vazia, se não estiver, vai imprimir o topo
    if (!estahVazia(p))
    {
        printf("Topo atual: %i\n", p->vet[p->topo]);
        return 1;
    }
    else
    {
        printf("A pilha atual está vazia! \n");
        return 0;
    }
}

// função para empilhar um valor
int empilha(pilha *p, int v)
{
	// verificando se está cheia, caso não, poderá empilhar
    if (estahCheia(p) != 1)
    {
        p->topo++;
        p->vet[p->topo] = v;
        return 1;
    }
    else
    {
    	printf("\nPilha cheia\n");
        return 0;
    }
}

// Função para desempilha o valor do topo. 
// Pede-se a referência de um variável por parânetro para receber o valor retirado
int desempilha(pilha *p, int *v)
{
    if (estahVazia(p) == 1)
    {
        return 0;
    }
    else
    {
        *v = p->vet[p->topo];
        p->topo -= 1;
        return 1;
    }
}

// Função para liberar todo espaço utilizado pela pilha
int liberaPilha(pilha *p)
{
    free(p);
    return 1;
}

// Função (ou método) main para se aplicar as funções
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int respMenu;
    printf("Bem-vindo ao programa de Pilha\n");
    pilha *p;
    int v;
    char respSair;
    int temPilha = 0;
    do
    {
        respMenu = 0;
        printf("Digite uma opção: \n");
        printf("[1] - Criar uma pilha \n");
        printf("[2] - Liberar pilha \n");
        printf("[3] - Empilhar \n");
        printf("[4] - Desempilhar \n");
        printf("[5] - Ver topo da pilha \n");
        printf("[6] - Verificar se uma pilha está vazia \n");
        printf("[7] - Verificar se uma pilha está cheia \n");
        printf("[8] - Sair \n");
        scanf("%i", &respMenu);
        fflush(stdin);
        switch (respMenu)
        {
        case 1:
            p = criaPilha();
            temPilha = 1;
            system("cls");
            printf("\n---Pilha criada com sucesso!---\n\n");
            respMenu = 0;
            break;
        case 2:
        	system("cls");
            if (temPilha == 1)
            {
                temPilha = 0;
                liberaPilha(p);
                printf("Pilha excluída com sucesso!\n");
            }
            else
            {
                printf("Não há pilha para excluir.\n");
            }
            respMenu = 0;
            break;
        case 3:
        	system("cls");
            if (temPilha == 1)
            {
                printf("Digite o valor que deseja empilhar: \n");
                scanf("%i", &v);
                fflush(stdin);
                if (empilha(p, v) == 1)
                {
                    printf("Item '%i' adicionado com sucesso!\n", v);
                }
                else
                {
                    printf("A pilha escolhida já está cheia!\n");
                }
            }
            else
            {
                printf("Não há pilha criada no momento.\n");
            }
            respMenu = 0;
            break;
        case 4:
        	system("cls");
            if (temPilha == 1)
            {
            	if(p->topo >= 0){
            		desempilha(p, &v);
	                printf("O item (topo) retirado foi o: %i\n", v);
	                imprimeTopo(p);
	                respMenu = 0;
				}else{
					printf("A pilha está vazia\n");
					respMenu = 0;
				}
                
            }
            else
            {
                printf("Não há pilha criada no momento.\n");
                respMenu = 0;
            }
            break;
        case 5:
        	system("cls");
            if (temPilha == 1)
            {
                printf("\n--------------------\n");
				imprimeTopo(p);
                printf("\n--------------------\n");
                respMenu = 0;
            }
            else
            {
                printf("Não há pilha criada no momento.\n");
                respMenu = 0;
            }
            break;
        case 6:
        	system("cls");
            if (temPilha == 1)
            {
                if (estahVazia(p) == 1)
                {
                    printf("A pilha está vazia.\n");
                }
                else
                {
                    printf("Há itens na pilha.\n");
                }
                respMenu = 0;
            }
            else
            {
                printf("Não há pilha criada no momento.\n");
                respMenu = 0;
            }
            break;
        case 7:
        	system("cls");
            if (temPilha == 1)
            {
                if (estahCheia(p) == 1)
                {
                    printf("A pilha está cheia.\n");
                }
                else
                {
                    printf("A pilha não está cheia.\n");
                }
                respMenu = 0;
            }
            else
            {
                printf("Não há pilha criada no momento.\n");
                respMenu = 0;
            }
            break;
        case 8:
        	system("cls");
            printf("Deseja realmente fazer isso? (s/n): \n");
				scanf("%s", &respSair);
				fflush(stdin);
				if(respSair == 's' || respSair == 'S'){
					printf("Obrigado por usar o programa!\n");
					system("exit");
					break;
				}else {
					respMenu = 0;
					break;
				}
        default:
            system("cls");
            printf("Opção inválida, tente novamente\n");
            respMenu = 0;
            break;
        }
    } while (respMenu < 1 || respMenu > 8);

    return 0;
}
