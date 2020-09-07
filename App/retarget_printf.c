

#include "main.h"
#include "usart.h"

#define PUTC_UART &huart1

#ifdef __GNUC__
/* With GCC, small printf (option LD Linker->Libraries->Small printf
 set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */


PUTCHAR_PROTOTYPE {
	/* Place your implementation of fputc here */
    HAL_UART_Transmit(PUTC_UART, (uint8_t*)&ch, 1, 10);
	return ch;
}
