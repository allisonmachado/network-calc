#include <stdio.h>
#include <stdlib.h>

#define BUFFER 100

void binary_print(unsigned int number)
{
    unsigned int mask = 0xff000000; // máscara para o último byte
    unsigned int shift = 24; // isolar os bytes, começa isolando o primeiro byte
    unsigned int byte, byte_iterator, bit_iterator; //variáveis auxiliares

    for(byte_iterator = 0; byte_iterator < 4; byte_iterator++) // percorre todos os bytes
    {
        byte = (number & mask) >> shift;
        printf(" ");

        for(bit_iterator = 0; bit_iterator < 8; bit_iterator++) // percorre todos os bits
        {
            if(byte & 128) //imprime o valor do bit 
                printf("1");
            else
                printf("0");
            byte <<= 1;
        }
        mask >>= 8; // ajusta a máscara para pegar o próximo byte
        shift -= 8; // ajusta o shift para pegar o próximo byte
        
    }
}

void handle_input()
{
	char string[BUFFER] = "10.10.12.0/30";
	unsigned int shift = 0;
	unsigned int ip_number = 0;
	unsigned int mask_number = 0, number_of_bits;
	unsigned int i, j, temp = 0;

	j = 16;
	
	ip_number = (atoi(&string[0]) << 24);

	for(i = 0; string[i] != 0; i++)
	{
		if(string[i] == 46) // Verifica se o caractere é um ponto e pega o valor númérico após o ponto
		{
			//printf("string: %d\n", atoi(&string[i + 1]));
			ip_number += (atoi(&string[i + 1]) << j);
			j -= 8;
		}
	}
	
	for(i = 0; string[i] != 0; i++)
	{
		if(string[i] == 47)
		{
			number_of_bits += atoi(&string[i + 1]);
		}
	}

    printf("\n");
    printf("\n");

	for(i = 31; i > (31 - number_of_bits); i--)
	{
        temp = (1 << i);
        mask_number += temp;
	}

	printf("%d\n",ip_number);
	printf("%d\n",number_of_bits);
	printf("%d\n",mask_number);
}

int main()
{
	// Declarações
	unsigned int network_address = 0;
	unsigned int broadcast = 0;
	unsigned int host_min = 0;
	unsigned int host_max = 0;

	// É necessário tratar os valores abaixo
	unsigned int input_address = 168430592;
	unsigned int net_mask = 4294967292;
	unsigned int qtd_bt_host = 2;

	// Calculando valores
	network_address = input_address & net_mask; 
	broadcast = ~(net_mask);
	broadcast = broadcast + network_address;
	host_min = network_address + 1;
	host_max = broadcast - 1;

	// Imprimindo valores
	printf("Network address = %d\n", network_address);
	printf("Broadcast address = %d\n", broadcast);
	printf("Host Min = %d\n", host_min);
	printf("Host Max = %d\n", host_max);
	handle_input();
}
