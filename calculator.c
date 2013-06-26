#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned int network_address = 0;
	unsigned int broadcast = 0;
	unsigned int host_max = 0;
	unsigned int host_min = 0;

	//É necessário tratar os valores abaixo
	unsigned int number = 168430592;
	unsigned int net_mask = 4294967292;
	unsigned int qtd_bt_host = 2;

	//unsigned int x = 2;
	//unsigned int bit;

	network_address = number & net_mask; 
	broadcast = ~(net_mask);
	broadcast = broadcast + network_address;
	host_min = network_address + 1;
	host_max = broadcast - 1;

	printf("Network address = %d\n", network_address);
	printf("Broadcast address = %d\n", broadcast);
	printf("Host Min = %d\n", host_min);
	printf("Host Max = %d\n", host_max);
	
	// Setando um bit
	//number |= 1 << x;
	//printf("%d\n",number);

	// Limpando um bit
	//number &= ~(1 << x);
	//printf("%d\n",number);

	// Trocando um bit
	//number ^= 1 << x;
	//printf("%d\n",number);

	// Checando o bit
	//bit = number & (1 << x);
	//printf("%d\n",bit);
}
