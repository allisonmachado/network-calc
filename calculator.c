#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
    unsigned char * raw_ptr; // pointer to get single bytes
    int i, aux_int;
    raw_ptr = (unsigned char *) number_addr;

    for (i = 3; i > -1; i--) // run through the four integer bytes
    {
        aux_int = raw_ptr[i];
        printf("%d", aux_int);
        if(i != 0)
            printf(".");
    }
    printf(" ");
}

void binary_print(unsigned int number)
{
    unsigned int mask = 0xff000000; // last byte mask
    unsigned int shift = 24; // separate bytes
    unsigned int byte, byte_iterator, bit_iterator; // auxiliary variables

    for(byte_iterator = 0; byte_iterator < 4; byte_iterator++) // byte iterator
    {
        byte = (number & mask) >> shift;
        printf(" ");

        for(bit_iterator = 0; bit_iterator < 8; bit_iterator++) // bit iterator
        {
            if(byte & 128) // print bit values
                printf("1");
            else
                printf("0");
            byte <<= 1;
        }
        mask >>= 8; // adjust mask for next byte
        shift -= 8; // adjust shift for next byte
        
    }
}

// store the results in the global variables
void handle_input(char * string)
{
    unsigned int i, shift, temp = 0;
    
    // makes the input string an integer number in ip_number
    shift = 24;
    ip_number = (atoi(&string[0]) << shift);
    shift -= 8;

    for(i = 0; string[i] != 0; i++)
    {
    	if(string[i] == 46) // check if it's a dot and get the value after it

    	{
    		ip_number += (atoi(&string[i + 1]) << shift);
    		shift -= 8;
    	}
    }
    
    // gets the number of bits of the mask
    for(i = 0; string[i] != 0; i++)
    {
    	if(string[i] == 47) // check if it's a slash and get the value after it
    	{
    		number_of_mask_bits += atoi(&string[i + 1]);
    	}
    }

    // makes the mask an integer number
    for(i = 31; i > (31 - number_of_mask_bits); i--)
    {
        temp = (1 << i);
        mask_number += temp;
    }
}

int main(int argc, char ** argv)
{
    // declarations
    unsigned int network_address = 0;
    unsigned int broadcast = 0;
    unsigned int host_min = 0;
    unsigned int host_max = 0;
    double number_of_hosts_bits = 0;

    // check if an address was given
    if(argc < 2)
    {
        usage(argv[0]);
    }

    printf("\n");
    printf("Entry: %s\n", argv[1]);
    printf("\n");

    // transform the given input in numbers
    handle_input(argv[1]);

    // calculating values through the global variables
    network_address = ip_number & mask_number; 
    broadcast = ~(mask_number);
    broadcast = broadcast + network_address;
    host_min = network_address + 1;
    host_max = broadcast - 1;

    // printing the results
    printf("Network address: ");
    printf("\t");
    binary_print(network_address);
    printf("\t");
    print_ip_address(&network_address);
    printf("\n");

    printf("Netmask:          ");
    printf("\t");
    binary_print(mask_number);
    printf("\t");
    print_ip_address(&mask_number);
    printf("(%d bits)", number_of_mask_bits);
    printf("\n");

    printf("Broadcast addr:   ");
    printf("\t");
    binary_print(broadcast);
    printf("\t");
    print_ip_address(&broadcast);
    printf("\n");

    printf("Min Host value:   ");
    printf("\t");
    binary_print(host_min);
    printf("\t");
    print_ip_address(&host_min);
    printf("\n");

    printf("Max Host value:   ");
    printf("\t");
    binary_print(host_max);
    printf("\t");
    print_ip_address(&host_max);
    printf("\n");
    printf("\n");

    number_of_hosts_bits = 32 - number_of_mask_bits;

    printf("The possible number of hosts on this network is %d.\n", (int)pow(2, number_of_hosts_bits) - 2);
    printf("\n");
}
