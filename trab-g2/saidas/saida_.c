#include <stdio.h>


	void ligar(char* namedevice)
	{
		printf("%s ligado!\n", namedevice);
	}

	void desligar(char* namedevice)
	{
		printf("%s desligado!\n", namedevice);
	}

	void alerta_simples(char* namedevice, char* msg)
	{
		printf("%s recebeu o alerta:\n", namedevice);
		printf("%s\n", msg);
	}

	void alerta_comp(char* namedevice, char* msg, char* var)
	{
		printf("%s recebeu o alerta:\n", namedevice);
		printf("%s %s\n", msg, var);
	}

int main() {

	char *celular = "celular";
	int movimento;
	char *hidrometro = "hidrometro";
	int umidade;
	char *lampada = "lampada";
	int potencia;
	char *Monitor = "Monitor";
	potencia = 100;
	if (umidade < 40) {
		alerta_simples(Monitor,  " Ar seco detectado "); 
	}
	if (movimento == 1) {
		
	} else {
		desligar("lampada");
	}

return 0;
}
