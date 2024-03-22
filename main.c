#include<stdio.h>
#include<windows.h>
#include<math.h>
#include <string.h>

main() {
	system("cls");
	double valor, periodo, dec, numeF, denoF, numeA, denoA, sla;
	int tamanhoP, tamanhoPS, i, nume, deno, resto, mdc, n;
	char valorStr[20], periodoStr[20]= "0.";
	char periodoFin[20], decStr[20];
	char slat, resp;
	
	system("cls");

	n = 1;
	
	printf("Entre com o valor a ser convertido em fracao: \n");
	scanf("%lf", &valor);
	
	if (valor < 0)
	{
		n = -1;
		valor = valor*n;
	}
	
	sprintf(valorStr, "%g", valor);
	
	printf("Exemplo: 2.35, periodo 1 (o numero 5 se repete)): \n ");
	printf("periodo 2 (o numero 35 se repete)): \n ");	
	printf("Qual e o tamanho do periodo (caso n tenha um periodo, entao = 0 ): \n ");
	scanf("%i", &tamanhoP);

	valor =  strtod(valorStr, &slat);
	tamanhoPS = strlen(valorStr);
	
	// fração geratriz de um número decimal
	if (tamanhoP == 0)
	{
		do
		{
			dec = modf(valor, &numeF);		
		
			valor = valor*10;
			denoF = pow(10, i);
		
			i++;	
		}
		while (dec != 0);
	}
	// fração geratriz de uma dízima periódica
	else if (tamanhoP > 0)
	{
		i = 0;
		while (i != tamanhoP)
		{
			periodoStr[i+2] = valorStr[tamanhoPS-tamanhoP+i];
			printf("%s", periodoStr);
			i++;
		}
		
		periodo = strtod(periodoStr, &slat);
		i = 0;
		numeA = valor*pow(10, tamanhoP);
		denoF = 1*pow(10, tamanhoP)-1;
		
		
		dec = modf(numeA, &sla);
		if (dec != 0)
		{
			sprintf(decStr, "%.g", dec);
			periodo = periodo/pow(10, strlen(decStr)-2);
	
		}
		numeA = numeA + periodo;
		
		numeF = numeA - valor;
		
		i = 0;
		while (dec != 0)
		{
			dec = modf(numeF, &sla);		
		
			numeF = numeF*10;
			denoF = denoF*10;
		}
		
	}
	else
	{
		printf("Valor para periodo invalido \n");
		system("pause");
		return 0;
	}
	
	// maximo divisor comun
	nume = numeF;
	deno = denoF;
	
	while (deno != 0)
	{
		resto = nume % deno;
		nume = deno;
		deno = resto;
	}
 
	mdc = nume;
 
	numeF = (numeF/mdc)*n;
	denoF = denoF/mdc;
	
	printf("O numero equivale a fracao: \n");
	printf("%.lf/%.lf ou\n", numeF, denoF);
	printf("%lf... \n", numeF/denoF);

	system("pause");
	return 0;
}

