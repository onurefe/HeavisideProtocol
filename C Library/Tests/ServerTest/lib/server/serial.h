#ifndef __SERIAL_H
#define __SERIAL_H

#include "generic.h"

#ifdef __cplusplus
extern "C"
{
#endif

	/* Exported typedefs -------------------------------------------------------*/
	enum
	{
		SERIAL_STATE_UNINIT = 0,
		SERIAL_STATE_READY,
		SERIAL_STATE_OPERATING,
		SERIAL_STATE_ERROR
	};
	typedef uint8_t Serial_State_t;

	enum
	{
		SERIAL_EVENT_DATA_READY = 0,
		SERIAL_EVENT_ERROR_OCCURRED
	};
	typedef uint8_t Serial_Event_t;

	typedef void (*Serial_EventOccurredDelegate_t)(Serial_Event_t event);

	/* Exported functions ------------------------------------------------------*/
	extern void Serial_Setup(Serial_EventOccurredDelegate_t eventHandler);
	extern Bool_t Serial_Start(void);
	extern void Serial_Execute(void);
	extern void Serial_Stop(void);
	extern uint16_t Serial_GetAvailableSpace(void);
	extern void Serial_ReadBuffer(uint8_t *data, uint16_t maxLength, uint16_t *length);
	extern void Serial_Send(uint8_t *data, uint16_t dataLength);

#ifdef __cplusplus
}
#endif

#endif