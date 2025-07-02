#include <stdio.h>


	void ligar(char* namedevice, int *status_device)
	{
		if (*status_device == 1) {
			printf("O Dispositivo ja esta ligado!\n");
		} else {
			*status_device = 1;
			printf("%s ligado!\n", namedevice);
		}
	}

	void desligar(char* namedevice, int* status_device)
	{
		if (*status_device == 0) {
			printf("O Dispositivo ja esta desligado!\n");
		} else {
			*status_device = 0;
			printf("%s desligado!\n", namedevice);
		}
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

	void verifica_status(char* namedevice, int *status_device)
	{
		if (*status_device == 1) {
			printf("%s está ativo!\n", namedevice);
		} else {
			printf("%s está inativo!\n", namedevice);
		}
	}

int main() {

	char *celular = "celular";
	int celular_status = 0;
	int movimento = 0;
	char *hidrometro = "hidrometro";
	int hidrometro_status = 0;
	int umidade = 0;
	char *lampada = "lampada";
	int lampada_status = 0;
	int potencia = 0;
	char *Monitor = "Monitor";
	int Monitor_status = 0;
	potencia = 100;
	if (umidade < 40) {
		alerta_simples(Monitor,  " Ar seco detectado "); 
	}
	if (movimento == 1 && potencia <= 100 && umidade > 0) {
		
	} else {
		desligar("lampada", &lampada_status );
	}

return 0;
}
