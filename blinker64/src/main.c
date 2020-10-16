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

// shortcut to led mmio addresses
#define LED_GPFSEL      GPIO_GPFSEL2
#define LED_GPFBIT      27
#define LED_GPSET       GPIO_GPSET0
#define LED_GPCLR       GPIO_GPCLR0
#define LED_GPIO_BIT    29

// main entry point
void main(void) {
    volatile u32 time;
    
    *(u32*)LED_GPFSEL |= (1 << LED_GPFBIT);
    
    while (1) {
        for(time = 0; time < 500000; time++);
        *(u32*)LED_GPCLR = (1 << LED_GPIO_BIT);
        for(time = 0; time < 500000; time++);
        *(u32*)LED_GPSET = (1 << LED_GPIO_BIT);
    }
}