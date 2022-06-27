#include <p18f4520.h>

#define sinal PORTAbits.RA1

int  resto, frequencia, inteiro;
unsigned char unidade, dezena;

void delay_freq ()
{
	unsigned char i;
	for (i=0;i<29;i++) {}

}
int mede_freq(void)
{
	int contador=0;
		while(sinal) {}; 
		while(!sinal) {}; //detecta transição de subida
		while(sinal)
		{
			delay_freq(1);
			contador++; //conta o número de delay's enquando sinal = 1
		}
		while(!sinal)
		{
			delay_freq(1);
			contador++;  //conta o número de delay's enquando sinal = 0
		}
		return contador;
}



void show_display(int contador)
{
	frequencia = 1/(0.0001*contador);
	resto = frequencia%10;
	inteiro = frequencia /10;
	
	 if (inteiro == 9)
	{
		dezena = 0b00001001;
	}
	else if (inteiro ==8)
	{
		dezena = 0b00001000;
	}
	else if (inteiro ==7)
	{
		dezena = 0b00000111;
	}
	else if (inteiro == 6)
	{
		dezena = 0b00000110;
	}
	else if (inteiro == 5)
	{
		dezena = 0b00000101;
	}
	else if (inteiro == 4)
	{
		dezena = 0b00000100;
	}
	else if (inteiro == 3)
	{
		dezena = 0b00000011;
	}
	else if (inteiro == 2)
	{
		dezena = 0b00000010;
	}
	else if (inteiro ==1)
	{
		dezena = 0b00000001;
	}
	else if (inteiro ==0)
	{
		dezena = 0b00000000;
	}
	
	if (resto==9)
	{
		unidade = 0b00001001;
	}
	else if (resto == 8)
	{
		unidade = 0b00001000;
	}
	else if (resto == 7)
	{
		unidade = 0b00000111;
	}
	else if (resto == 6)
	{
		unidade = 0b00000110;
	}
	else if (resto == 5)
	{
		unidade = 0b00000101;
	}
	else if (resto == 4)
	{
		unidade = 0b00000100;
	}
	else if (resto == 3)
	{
		unidade = 0b00000011;
	}
	else if (resto == 2)
	{
		unidade = 0b00000010;
	}
	else if (resto == 1)
	{
		unidade = 0b00000001;
	}
	else if (resto == 0)
	{
		unidade = 0b00000000;
	}	
	if (inteiro >9)
	{
		dezena = 0b00001110;
		unidade = 0b00001110;
	}

	LATC = dezena; 	
	LATD = unidade;
}

main()
{
//área de configuração do sistema
	TRISC= 0b00000000 ; //// display de 7 segmentos como saída
	TRISD = 0b00000000;
	TRISAbits.RA1=1; //RD0 configurado como entrada.
	ADCON1 = 0b00001111; //Configura portas A e B como IO

// programa monitor (sistema operacional)
	while(1)
	{
		show_display(mede_freq());
	}
}

