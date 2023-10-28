/*Programa que depende de lo vendido bruto calcula el 9% le suma el salario de
200 y lo agrega a un arreglo*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
int venta, salario=200,vendedores=0,temporal=0,i;
/*Declaramos un arreglo de 100 vendedores, pero pregruntaremos cuantos se van a
ingresar*/
int pagos[99];
int aleatorio(int min,int max);//Funcion prototipo para generar num aleatorios
int imprimir_arreglo(int arr[],int numero);//Imprimir arreglos
void calcPago(int arr[],int n);//Calcula el pago del 9% de las ventas
//void acomodar(int arr[]);
void ordenPagos(int arr[],int arr2[],int n);//Contador de los pagos
int imprimir_tabla(int arr[]);//tabla de pagos de 100 en 100
int main()
{
	printf("¿Cuantos trabajadores hicieron ventas esta semana?\n");
	scanf("%d",&vendedores);
	/* Para no ingresar las ventas manualmente se generaran sus transacciones 
	aleatoriamente con rangos de venta de 200 a 10,000*/
	srand(getpid());
	for(i=0;i<vendedores;i++)
	{
		temporal=aleatorio(200,15000);
		pagos[i]=temporal;		
	}
	//Imprimimos el arreglo para visualizarlo
	printf("\n\t Ventas de la semana\n");
	imprimir_arreglo(pagos,vendedores);
	//Calculamos su apgo bruto del 9% de las ventas mas su salario de 200
	calcPago(pagos,vendedores);
	//Volvemos a imprimir los valores para ver sus pagos
	printf("\n\n\t Cobros de los vendedores\n");
	imprimir_arreglo(pagos,vendedores);
	//Clasificamos los pagos de 100 en 100
	int contadorPagos[9]={0};
	ordenPagos(pagos,contadorPagos,vendedores);
	//Imprimimos la tabla
	imprimir_tabla(contadorPagos);
}
//Funcion que genera numeros aleatorios
int aleatorio(int min,int max)
{return min+rand() / (RAND_MAX /(max - min +1) +1);}
//Funcion para imprimir arreglos
int imprimir_arreglo(int arr[],int numero)
{
	for(i=0;i<numero;i++)
	{
		if((i+1)%10==0){printf("%d\n",arr[i]);}
		else{printf("%d\t",arr[i]);}
	}
	return 0;
}
//Funcion para caluclar el pago de los vendedores
void calcPago(int arr[],int n)
{
	for(i=0;i<n;i++)
	{
		temporal=pagos[i];
		venta=200+(temporal*0.09);
		//truncamos el valor
		venta=trunc(venta);
		//Regresamos la venta al arreglo
		pagos[i]=venta;
	}
}
//Funcion pra organizar los pagos en los rangos dados
void ordenPagos(int arr[],int arr2[],int n)
{
	int cont=0,varx;
	
	for(i=0;i<n;i++)
	{
		cont=0;
		varx=arr[i];varx=varx/100;varx=trunc(varx);
		switch(varx)
		{
		case 2:cont++;arr2[0]+=cont;break;
		case 3:cont++;arr2[1]+=cont;break;
		case 4:cont++;arr2[2]+=cont;break;
		case 5:cont++;arr2[3]+=cont;break;
		case 6:cont++;arr2[4]+=cont;break;
		case 7:cont++;arr2[5]+=cont;break;
		case 8:cont++;arr2[6]+=cont;break;
		case 9:cont++;arr2[7]+=cont;break;
		default:cont++;arr2[8]+=cont;break;
		}
		
	}
}
//Funcion pra imprimir la tabal de los vendedores
int imprimir_tabla(int arr[])
{
	printf("\n\tTabla de vendedores\n");
	printf("200-299: %d \n",arr[0]);
	printf("300-399: %i \n",arr[1]);	
	printf("400-499: %i \n",arr[2]);	
	printf("500-599: %i \n",arr[3]);	
	printf("600-699: %i \n",arr[4]);	
	printf("700-799: %i \n",arr[5]);	
	printf("800-899: %i \n",arr[6]);	
	printf("900-999: %i \n",arr[7]);	
	printf("1000 o más: %i \n",arr[8]);	
	return 0;
}
