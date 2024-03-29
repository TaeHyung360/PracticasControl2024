/* 
PRACTICA 1: IMPLEMENTACION DE UN CONTROLADOR PARA UN MOTOR DE DC

*/

// DECLARACIONES //////////////////////////////////////////////////////////////////////////

// ACTIVACION DE CODIGO

#define NOMBRE_PRAC "P1-A"
#define VERSION_SW "1.0"

// #define ACTIVA_P1A
// #define DEBUG_P1A
// #define ACTIVA_P1B1
// #define ACTIVA_P1B2
// #define ACTIVA_P1B3
// #define ACTIVA_P1C
// #define DEBUG_P1C
// #define ACTIVA_P1C_MED_ANG
// #define ACTIVA_P1D2
// #define ACTIVA_P1D3

// Display OLED ///////////////////////////////////////////////////////////////////////////
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)

// Parametros cola de la interrupcion del encoder ///////////////////////////////////////
#define TAM_COLA_I 1024 /*num mensajes*/
#define TAM_MSG_I 1 /*num caracteres por mensaje*/

// TIEMPOS
#define BLOQUEO_TAREA_LOOPCONTR_MS 10 
#define BLOQUEO_TAREA_MEDIDA_MS 1000

// Configuración PWM  ////////////////////////////////////////////////////////////////////
uint32_t pwmfreq = 1000; // 1KHz
const uint8_t pwmChannel = 0;
const uint8_t pwmresolution = 8;
const int PWM_Max = pow(2,pwmresolution)-1; //

// Pines driver motor ////////////////////////////////////////////////////////////////////
const uint8_t PWM_Pin = 32; // Entrada EN 
const uint8_t PWM_f = 16; // Entrada PWM1 
const uint8_t PWM_r = 17; // Entrada PWM2 

// Voltaje maximo motor ////////////////////////////////////////////////////////////////////
float SupplyVolt = 12;

// Pines encoder ////////////////////////////////////////////////////////////////////
const uint8_t A_enc_pin = 35;
const uint8_t B_enc_pin = 34;

// Conversión a angulo y velocidad del Pololu 3072
//const float conv_rad = ; 
//const float conv_rev = ;
//const float conv_rad_grados = ; 

// Declarar funciones ////////////////////////////////////////////////////////////////////
void config_sp(); // Configuracion puerto serie
void config_oled(); // Configuracion OLED
//void config_enc(); // Configuracion del encoder
//void config_PWM(); // Configuracion PWM
//void excita_motor(float v_motor); // Excitacion motor con PWM
//float interpola_vel_vol_lut(float x); // Interpolacion velocidad/voltios LUT

// TABLA VELOCIDAD-VOLTAJE P1D
#ifdef ACTIVA_P1D2
#define LONG_LUT 12
//Vector de tensiones
const float Vol_LUT[LONG_LUT] = {0, , , 2, 3, 4, 5, 6, 7, 8, 9, 100};
// Vector de velocidades
const float Vel_LUT[LONG_LUT] = {0, 0, ...};
#endif

// Variables globales ////////////////////////////////////////////////////////////////////
//int32_t ang_cnt = 0;
//float pwm_volt = 0;
//int32_t pwm_motor = 0;
//int32_t sign_v_ant = 0;
//float v_medida = 0;    // Valor medido de angulo o velocidad -----------------
//float ref_val = 0;     // Valor de referencia de angulo o velocidad
//int8_t start_stop = 0; //1 -> en funcionamiento | 0 -> parado 
//float K_p = ;

// Declaracion objetos  ////////////////////////////////////////////////////////////////////

//xQueueHandle cola_enc; // Cola encoder

/*
 RUTINAS ATENCION INTERRUPCIONES ########################################################################
*/

/* 
 Rutina de atención a interrupción ISC_enc --------------------------------------------
*/

void IRAM_ATTR ISR_enc() {
	// Lee las salidas del Encoder		
	
	// Procesa los datos

	// Enviar los bytes a la cola 
	//if (xQueueSendFromISR( ... , ... ,NULL) != pdTRUE)
	{
	  printf("Error de escritura en la cola cola_enc \n");
	};
}

/*
 TAREAS #############################################################################
*/

/*
 Tarea task_enc #####################################################################
*/
#ifdef ACTIVA_P1A
void task_enc(void* arg) {
	// Declaracion de variables locales

	while(1){
		// Espera a leer los datos de la cola
		//if (xQueueReceive( ... , ... ,(TickType_t) portMAX_DELAY) == pdTRUE){
			// Codificar la fase del encoder

			// Calcular incremento/decremento y actualizar valor 

			#ifdef DEBUG_P1A
				// Enviar al monitor serie

			#endif
		// } else {
		// 	printf("Error de lectura de la cola cola_enc \n");
		// }
	
	}

}
#endif


/* 
Tarea de configuración de parámetros  #####################################################################
*/
void task_config(void *pvParameter) {
	char ini_char = '0';

	while(1) { 
		// Detectar caracter enviado

		// Guardar valor recibido

		// Escribir el valor recibido en la consola


		// Activacion de la tarea cada 0.1s
		// vTaskDelay(100 / portTICK_PERIOD_MS);
	}
}

/* 
Tarea del lazo principal del controlador  #####################################################################
*/
#ifdef ACTIVA_P1B3
void task_loopcontr(void* arg) {

	while(1) {
		
		// Excitacion del motor con PWM
		
		// Activacion de la tarea cada 0.01s
	
	}
}
#endif

/* 
Tarea del lazo principal del controlador  #####################################################################
*/
#ifdef DEBUG_P1C
void task_medidas(void* arg) 
{

	while(1) { 
		// Mostrar medidas de angulo y velocidad del motor
		#ifdef ACTIVA_P1C_MED_ANG // Medida de angulo

		#else // Medida de velocidad

		#endif

		// Activacion de la tarea cada 1s

	}
}
#endif

/*
SET UP -----------------------------------------------------------------------------------
*/
void setup() {
	// Configuracion puerto serie
	config_sp();
	
	// Configuracion OLED
	config_oled();

	// Configuracion PWM


	// Crear cola_enc
	// cola_enc = xQueueCreate(TAM_COLA_I, TAM_MSG_I);
	// if(cola_enc == NULL){
	// 	Serial.println("Error en creacion de cola_enc");
	// 	exit(-1);
	// };

	// Crear la tarea task_enc
	// if(xTaskCreate( ... , "task_enc", 2048, NULL, 1, NULL) != pdPASS){
	// 	Serial.println("Error en creacion tarea task_enc");
	// 	exit(-1);
	// }

	// Crear la tarea task_config


	// Crear la tarea task_loopcontr


	#ifdef DEBUG_P1C
		// Crear la tarea task_medidas

	#endif

	// Configuracion del encoder

}

/*
LOOP ---- NO USAR ------------------------------------------------------------------- 
*/
void loop() {}

// FUNCIONES ////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////
// Funcion configuracion del encoder
////////////////////////////////////////////////////////////////////////////////////
#ifdef ACTIVA_P1A
void config_enc(){
	// Configuracion de pines del encoder

	// Configuracion interrupcion
} 
#endif
////////////////////////////////////////////////////////////////////////////////////
// Funcion configuracion del PWM
////////////////////////////////////////////////////////////////////////////////////
#ifdef ACTIVA_P1B2
void config_PWM(){
	// Configuracion de pines de control PWM

	// Configuracion LED PWM 

	// Asignar el controlador PWM al GPIO

}  
#endif

////////////////////////////////////////////////////////////////////////////////////
// Funcion excitacion del motor con PWM
////////////////////////////////////////////////////////////////////////////////////
#ifdef ACTIVA_P1B3
void excita_motor(float v_motor){
	// Sentido de giro del motor

	// Calcula y limita el valor de configuración del PWM

	// El valor de excitación debe estar entro 0 y PWM_Max
				
	// Excitacion del motor con PWM
	
}  
#endif

////////////////////////////////////////////////////////////////////////////////////
// Funcion configuracion del puerto serie
////////////////////////////////////////////////////////////////////////////////////
void config_sp(){
	Serial.begin(115200);
	Serial.println("  ");
	Serial.println("--------------------------------------------");
	Serial.println("PRACTICA CONTROLADOR MOTOR " NOMBRE_PRAC);
	Serial.println("--------------------------------------------");
}  

////////////////////////////////////////////////////////////////////////////////////
// Funcion configuracion del OLED
////////////////////////////////////////////////////////////////////////////////////
void config_oled(){
	Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
	display.begin(SSD1306_SWITCHCAPVCC, 0x3C) ;
	display.clearDisplay();
	display.setTextColor(WHITE);        // 
	display.setCursor(0,0);             // Start at top-left corner
	display.println(F("CONTR. MOTOR " NOMBRE_PRAC));
	display.display();
	delay(1000);
	display.setTextColor(BLACK,WHITE);        // 
	display.setCursor(0,20);             // Start at top-left corner
	display.println(F(" SW v." VERSION_SW));
	display.display();
	delay(1000);
}  


////////////////////////////////////////////////////////////////////////////////////
// Funcion de interpolacion LUT de Velocidad-Voltaje
////////////////////////////////////////////////////////////////////////////////////
#ifdef ACTIVA_P1D2
float interpola_vel_vol_lut(float x) {
	// Buscar el valor superior más pequeño del array
	int8_t i = 0;
	if ( x >= Vel_LUT[LONG_LUT - 2] ) {i = LONG_LUT - 2;}
	else {while ( x > Vel_LUT[i+1] ) i++;}

	// Guardar valor superior e inferior
	float xL = Vel_LUT[i];
	float yL = Vol_LUT[i];
	float xR = Vel_LUT[i+1];
	float yR = Vol_LUT[i+1];

	// Interpolar
	float dydx = ( yR - yL ) / ( xR - xL );

	return yL + dydx * ( x - xL );
}
#endif