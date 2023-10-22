#include <stdio.h>
#include <stdlib.h>


int menu (int opcao, int v, int matriz[][v])
{
  int i,j;
  if(opcao == 1)
    {
      int laco=0;
      for(i=0; i<v; i++)
      {
        laco += matriz[i][i];
      }
      printf("\nNúmero de laços: %d\n",laco);
    }
    else if(opcao == 2)
    {
      int maior = 0, mp, soma[v];
      for(i=0; i<v; i++)
      {
        soma[i] = 0;
      }
      for(i=0; i<v; i++)
      {
        for(j=0; j<v; j++)
        {
          if(i != j)
          {
            soma[i] += matriz[i][j];
          }
          else
          {
            soma[i] += matriz[i][j] * 2;
          }
        }
        if (maior < soma[i])
        {
          maior = soma[i];
          mp = i;
        }
      
      }
      if(maior > 0)
      {
        printf("%d é o vértice de maior grau, e possui grau: %d",mp,maior);
      }
    }
    else if(opcao == 3)
    {
      int menor = 1000000000, mep, soma2[v];
      for(i=0; i<v; i++)
      {
        soma2[i] = 0;
      }
      for(i=0; i<v; i++)
      {
        for(j=0; j<v; j++)
        {
          if(i != j)
          {
            soma2[i] += matriz[i][j];
          }
          else
          {
            soma2[i] += matriz[i][j] * 2;
          }
        }
        if (menor > soma2[i])
        {
          menor = soma2[i];
          mep = i;
        }
      }
      if(menor > 0)
      {
      printf("\nO Vértice %d é o de menor grau, e possui grau: %d",mep,menor);
      }
    }
      
    else if(opcao == 4)
    {
      int cont=0;
      for(i=0; i<v; i++)
      {
       for(j=0; j<v; j++)
        {
          if(matriz[i][j] > 1)
          {
            cont += 1;
          }
        }
      }
      if(cont >= 1)
      {
        printf("\nO grafo é um multigrafo!\n");
      }
      else
      {
        printf("\nO grafo não é um multigrafo!\n");
      }
    }
    else if(opcao == 5)
    {
      int laco=0;
      for(i=0; i<v; i++)
      {
        laco += matriz[i][i];
      }
      int cont=0;
      for(i=0; i<v; i++)
      {
       for(j=0; j<v; j++)
        {
          if(matriz[i][j] > 1)
          {
            cont += 1;
          }
        }
      }
      if(laco == 0 && cont == 0)
      {
        printf("\nÉ um grafo simples!\n");
      }
      else
      {
        printf("\nNão é um grafo simples!\n");
      }
    }
    else if(opcao == 6)
    {
      int cont = 0;
      for(i=0; i<v; i++)
      {
        for(j=0; j<v; j++)
        {
          int laco = 0;
          for(i=0; i<v; i++)
          {
            laco += matriz[i][i];
            if(matriz[i][j] == 0 && laco == 0)
            {
              cont += 1;  
            }
          }
        }
      }
      if(cont > 0)
      {
        printf("\nExiste vértice isolado!\n");
      }
      else
      {
        printf("\nNão existe nenhum vértice isolado!\n");
      }
    }
    else if(opcao == 7)
    {
      int soma = 0, quant = 0;
        for (int i = 0; i < v; i++)
        {
          for (int j = 0; j < v; j++)
          {
            if (i != j)
            {
              soma += matriz[i][j];
            }
            else
            {
              soma += matriz[i][j] * 2;
            }
          }
          if (soma == 1)
          {
            quant += 1;
            soma = 0;
          }
        }
      if(quant > 0)
      {
        printf("\nExiste vértice folha!\n");
      }
      else
      {
        printf("\nNão existe vértice folha!\n");
      }
    }

    else if(opcao == 8)
    {
      int cont = 0, cont2 = (v*v)-v;
      for(i=0; i<v; i++)
      {
        for(j=0; j<v; j++)
        {
          if(matriz[i][j] > 0)
          {
            cont += 1;
          }
        }
      }
      if(cont > 0 && cont == cont2)
      {
        printf("\nO grafo é completo!\n");
      }
      else
      {
        printf("\nO grafo não é completo!\n");
      }
    }
  }
  

int main()
{
  int v = v-1;
  int grafo;
  
  printf("Informe a quantidade de vértices: ");
  scanf("%d",&v);
  printf("\n[1] - Grafo direcionado\n[2] - Grafo não direcionado:\n\n-> ");
  scanf("%d",&grafo);

  int i,j;
  int matriz[v][v];

  for(i=0; i<v; i++)
  {
    for(j=0; j<v; j++)
    {
      matriz[i][j] = -1;
    }
  }
  
printf("\nPreenchendo arestas...\n\n");
  for(i=0; i<v; i++)
  {
    for(j=0; j<v; j++)
    {
      if (matriz [i][j] == -1)
      {
        printf("%d-%d: ",i,j);
        scanf("%d",&matriz[i][j]);
      }
      if(grafo == 2)
      {
        matriz[j][i] = matriz[i][j];
      }
    }
    printf("\n");
  }
  printf("Matriz\n\n");
  for(i=0; i<v; i++)
  {
    for(j=0; j<v; j++)
    {
      printf("%d ",matriz[i][j]);
    }
    printf("\n");
  }
  printf("\nLista\n\n");
  for(i=0; i<v; i++)
  {
    printf("|%d| -> ",i);
    for(j=0; j<v; j++)
    {
      if(matriz[i][j] != 0)
      {
        printf("|%d",j);    
      }
    }printf("\n");
  }
  int acesso;
  
  printf("\n\nDeseja acessar o menu:");
  printf("\n\n[1] - Sim [2] - Não\n\n--> ");
  scanf("%d",&acesso);

  if(acesso == 1)
  {
    int opcao;
    while(acesso == 1)
    {
      printf("\nMENU\n\n[1] - Número de laços do grafo\n[2] - Maior grau do grafo\n[3] - Menor grau do grafo\n[4] - É um multigrafo?\n[5] - É um grafo simples?\n[6] - Existe vértice isolado?\n[7] - Existe vértice folha?\n[8] - É um grafo completo\n\n--> ");
    scanf("%d",&opcao);
    printf("\n");
    menu(opcao,v,matriz);
    printf("\n\nDeseja acessar o menu:");
    printf("\n\n[1] - Sim [2] - Não\n\n--> ");
    scanf("%d",&acesso);
    }
    printf("\nPrograma encerrado!\n");
  }
      
return 0;
}