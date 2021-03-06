// primitive types
typedef unsigned int u32;

// mmio addresses
#define MMIO_BASE_ADDRESS (0x3F000000)
#define GPIO_BASE_ADDRESS (MMIO_BASE_ADDRESS + 0x00200000)

// gpio mmio addresses
#define GPIO_GPFSEL0   (GPIO_BASE_ADDRESS + 0x00000000)
#define GPIO_GPFSEL1   (GPIO_BASE_ADDRESS + 0x00000004)
#define GPIO_GPFSEL2   (GPIO_BASE_ADDRESS + 0x00000008)
#define GPIO_GPFSEL3   (GPIO_BASE_ADDRESS + 0x0000000C)
#define GPIO_GPFSEL4   (GPIO_BASE_ADDRESS + 0x00000010)
#define GPIO_GPFSEL5   (GPIO_BASE_ADDRESS + 0x00000014)

#define GPIO_GPSET0    (GPIO_BASE_ADDRESS + 0x0000001C)
#define GPIO_GPSET1    (GPIO_BASE_ADDRESS + 0x00000020)

#define GPIO_GPCLR0    (GPIO_BASE_ADDRESS + 0x00000028)
#define GPIO_GPCLR1    (GPIO_BASE_ADDRESS + 0x0000002C)

// main entry point
void main(void) {
    volatile u32 time;
    
    *(u32*)GPIO_GPFSEL2 |= (1 << 27);
    
    while (1) {
        for (time = 0; time < 500000; ++time);
        *(u32*)GPIO_GPCLR0 = (1 << 29);
        for (time = 0; time < 500000; ++time);
        *(u32*)GPIO_GPSET0 = (1 << 29);
    }
}
