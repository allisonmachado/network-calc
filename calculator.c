#include <stdio.h>
#include <stdlib.h>

#define BUFFER 100

unsigned int ip_number = 0;
unsigned int mask_number = 0, number_of_mask_bits;

void usage(char * program_name)
{
    printf("Usage: %s <ip-addr/mask or net-addr/mask>\n", program_name);
    exit(EXIT_FAILURE);
}

void print_ip_address(int * number_addr)
{
    unsigned char * raw_ptr;
    int i, aux_int;
    raw_ptr = (unsigned char *) number_addr;

    for (i = 3; i > -1; i--)
    {
        aux_int = raw_ptr[i];
        printf("%d", aux_int);
        if(i != 0)
            printf(".");
    }
    printf("\n");
}

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
        mask >>= 8; // ashiftusta a máscara para pegar o próximo byte
        shift -= 8; // ashiftusta o shift para pegar o próximo byte
        
    }
}

void handle_input(char * string)
{
    //char string[BUFFER] = "10.10.12.0/30";
    unsigned int i, shift, temp = 0;
    
    shift = 24;
    ip_number = (atoi(&string[0]) << shift);
    shift -= 8;

    for(i = 0; string[i] != 0; i++)
    {
    	if(string[i] == 46) // Verifica se o caractere é um ponto e pega o valor númérico após o ponto

    	{
    		ip_number += (atoi(&string[i + 1]) << shift);
    		shift -= 8;
    	}
    }
    
    for(i = 0; string[i] != 0; i++)
    {
    	if(string[i] == 47)
    	{
    		number_of_mask_bits += atoi(&string[i + 1]);
    	}
    }

    for(i = 31; i > (31 - number_of_mask_bits); i--)
    {
        temp = (1 << i);
        mask_number += temp;
    }
}

int main(int argc, char ** argv)
{
    // Declarações
    unsigned int network_address = 0;
    unsigned int broadcast = 0;
    unsigned int host_min = 0;
    unsigned int host_max = 0;

    if(argc < 2)
    {
        usage(argv[0]);
    }

    printf("Entry address %s\n", argv[1]);

    handle_input(argv[1]);

    // Calculando valores
    network_address = ip_number & mask_number; 
    broadcast = ~(mask_number);
    broadcast = broadcast + network_address;
    host_min = network_address + 1;
    host_max = broadcast - 1;

    // Imprimindo valores
    printf("Network address: ");
    print_ip_address(&network_address);
    printf("Mask address: ");
    print_ip_address(&mask_number);
    printf("Broadcast address: ");
    print_ip_address(&broadcast);
    printf("Host Min: ");
    print_ip_address(&host_min);
    printf("Host Max: ");
    print_ip_address(&host_max);
}
