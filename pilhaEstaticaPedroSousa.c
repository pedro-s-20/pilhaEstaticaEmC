#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
//definindo a constante que ser� o tamanho do vetor da pilha
#define MAX 100

/*
	Pedro Sousa 
	Engennharia da Computa��o  
	Algoritmos e Estrutura de Dados II 
*/

// Definindo a struct pilha est�tica
typedef struct pilha
{
	// vari�vel que armanezar� a posi��o do topo
    int topo;
    // vetor para armazenar os valores
    int vet[MAX];
} pilha;

// Fun��o para inicializar a pilha
pilha *criaPilha()
{
	// criando a pilha na fun��o
    pilha *p;
    // armazenando espa�o de mem�ria para ela
    p = (pilha *)malloc(1 * sizeof(pilha));
    // definindo a posi��o inicial do topo
    p->topo = -1;
    // retornando a pilha criada
    return p;
}

// fun��o para verificar se a pilha est� vazia 
int estahVazia(pilha *p)
{
	// verificando se est� vazia de acordo com a posi��o do topo
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

// fun��o para verificar se a pilha est� cheia 
int estahCheia(pilha *p)
{
	// verificando se est� cheia atrav�s da posi��o do topo, 
	// se � o m�ximo estabelecido pela constante -1 (pois conta-se o 0)
    if (p->topo == MAX-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// fun��o para imprimir o topo da pilha
int imprimeTopo(pilha *p)
{
	// verificando se est� vazia, se n�o estiver, vai imprimir o topo
    if (!estahVazia(p))
    {
        printf("Topo atual: %i\n", p->vet[p->topo]);
        return 1;
    }
    else
    {
        printf("A pilha atual est� vazia! \n");
        return 0;
    }
}

// fun��o para empilhar um valor
int empilha(pilha *p, int v)
{
	// verificando se est� cheia, caso n�o, poder� empilhar
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

// Fun��o para desempilha o valor do topo. 
// Pede-se a refer�ncia de um vari�vel por par�netro para receber o valor retirado
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

// Fun��o para liberar todo espa�o utilizado pela pilha
int liberaPilha(pilha *p)
{
    free(p);
    return 1;
}

// Fun��o (ou m�todo) main para se aplicar as fun��es
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
        printf("Digite uma op��o: \n");
        printf("[1] - Criar uma pilha \n");
        printf("[2] - Liberar pilha \n");
        printf("[3] - Empilhar \n");
        printf("[4] - Desempilhar \n");
        printf("[5] - Ver topo da pilha \n");
        printf("[6] - Verificar se uma pilha est� vazia \n");
        printf("[7] - Verificar se uma pilha est� cheia \n");
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
                printf("Pilha exclu�da com sucesso!\n");
            }
            else
            {
                printf("N�o h� pilha para excluir.\n");
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
                    printf("A pilha escolhida j� est� cheia!\n");
                }
            }
            else
            {
                printf("N�o h� pilha criada no momento.\n");
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
					printf("A pilha est� vazia\n");
					respMenu = 0;
				}
                
            }
            else
            {
                printf("N�o h� pilha criada no momento.\n");
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
                printf("N�o h� pilha criada no momento.\n");
                respMenu = 0;
            }
            break;
        case 6:
        	system("cls");
            if (temPilha == 1)
            {
                if (estahVazia(p) == 1)
                {
                    printf("A pilha est� vazia.\n");
                }
                else
                {
                    printf("H� itens na pilha.\n");
                }
                respMenu = 0;
            }
            else
            {
                printf("N�o h� pilha criada no momento.\n");
                respMenu = 0;
            }
            break;
        case 7:
        	system("cls");
            if (temPilha == 1)
            {
                if (estahCheia(p) == 1)
                {
                    printf("A pilha est� cheia.\n");
                }
                else
                {
                    printf("A pilha n�o est� cheia.\n");
                }
                respMenu = 0;
            }
            else
            {
                printf("N�o h� pilha criada no momento.\n");
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
            printf("Op��o inv�lida, tente novamente\n");
            respMenu = 0;
            break;
        }
    } while (respMenu < 1 || respMenu > 8);

    return 0;
}
