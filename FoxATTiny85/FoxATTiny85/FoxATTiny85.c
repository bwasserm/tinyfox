/*
 * FoxATTiny85.c
 *
 * Created: 8/31/2013 18:56:03
 *  Author: bwasserm
 */ 

#include <avr/io.h>
#include <util/delay.h>

#define DATA_PIN 3
#define PTT_PIN 4
#define DOT_COUNT 150
#define DASH_COUNT 450
#define WAVE_DELAY_US 500
#define SYMB_DELAY_MS 200
#define CHAR_DELAY_MS (300 - SYMB_DELAY_MS)
#define KEY_UP_DELAY_MS 200
#define TX_HOLD_MS 0
#define TX_OFF_DELAY_MS 5000

void dot(){
	int count = 0;
	for(count = 0; count < DOT_COUNT; count++){
		PORTB |= (1<<DATA_PIN);
		_delay_us(WAVE_DELAY_US);
		PORTB &= ~(1<<DATA_PIN);
		_delay_us(WAVE_DELAY_US);
	}
	_delay_ms(SYMB_DELAY_MS);
}

void dash(){
	int count = 0;
	for(count = 0; count < DASH_COUNT; count++){
		PORTB |= (1<<DATA_PIN);
		_delay_us(WAVE_DELAY_US);
		PORTB &= ~(1<<DATA_PIN);
		_delay_us(WAVE_DELAY_US);
	}
	_delay_ms(SYMB_DELAY_MS);
}

void txon(){
	PORTB &= ~(1<<PTT_PIN);
}

void txoff(){
	PORTB |= (1<<PTT_PIN);
}

void sendChar(char symbol){
	switch(symbol){
		case '1':
		dot(); dash();	dash();	dash();	dash();
		break;
		case '2':
		dot();	dot();	dash();	dash();	dash();
		break;
		case '3':
		dot();	dot();	dot();	dash();	dash();
		break;
		case '4':
		dot(); dot(); dot(); dot(); dash(); dash();
		break;
		case '5':
		dot(); dot(); dot(); dot(); dot();
		break;
		case '6':
		dash(); dot(); dot(); dot(); dot();
		break;
		case '7':
		dash(); dash(); dot(); dot(); dot();
		break;
		case '8':
		dash(); dash(); dash(); dot(); dot();
		break;
		case '9':
		dash(); dash(); dash(); dash(); dot();
		break;
		case '0':
		dash(); dash(); dash(); dash();	dash();
		break;
		case 'a':
		dot(); dash();
		break;
		case 'b':
		dash();	dot();	dot();	dot();
		break;
		case 'c':
		dash();	dot();	dash();	dot();
		break;
		case 'd':
		dash();	dot();	dot();
		break;
		case 'e':
		dot();
		break;
		case 'f':
		dot();	dot();	dash();	dot();
		break;
		case 'g':
		dash();	dash();	dot();
		break;
		case 'h':
		dot();	dot();	dot();	dot();
		break;
		case 'i':
		dot();	dot();
		break;
		case 'j':
		dot();	dash();	dash();	dash();
		break;
		case 'k':
		dash();	dot();	dash();
		break;
		case 'l':
		dot();	dash();	dot();	dot();
		break;
		case 'm':
		dash();	dash();
		break;
		case 'n':
		dash();	dot();
		break;
		case 'o':
		dash();	dash();	dash();
		break;
		case 'p':
		dot();	dash();	dash();	dot();
		break;
		case 'q':
		dash();	dash();	dot();	dash();
		break;
		case 'r':
		dot();	dash();	dot();
		break;
		case 's':
		dot();	dot();	dot();
		break;
		case 't':
		dash();
		break;
		case 'u':
		dot();	dot();	dash();
		break;
		case 'v':
		dot();	dot();	dot();	dash();
		break;
		case 'w':
		dot();	dash();	dash();
		break;
		case 'x':
		dash();	dot();	dot();	dash();
		break;
		case 'y':
		dash();	dot();	dash();	dash();
		break;
		case 'z':
		dash();	dash();	dot();	dot();
		break;
		default:
		break;
	}
	_delay_ms(CHAR_DELAY_MS);
}

int main(void)
{
	// Setup
	// Set pin directions & initial state
	DDRB = 0xFF;
	txoff();
	PORTB &= ~(1<<DATA_PIN);
	
	// Create message
	char *message = "kk6bbm";
	int message_len = 4;
	int index = 0;
		
    while(1)
    {
        // Send message
		txon();
		_delay_ms(KEY_UP_DELAY_MS);
		for(index = 0; index < message_len; index++){
			sendChar(message[index]);
		}
		_delay_ms(TX_HOLD_MS);
		txoff();
		_delay_ms(TX_OFF_DELAY_MS);
					
    }
}