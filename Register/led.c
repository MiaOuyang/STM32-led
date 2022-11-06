#define RCC_AP2ENR	*((unsigned volatile int*)0x40021018)
#define GPIOA_CRL	*((unsigned volatile int*)0x40010800)
#define	GPIOA_ORD	*((unsigned volatile int*)0x4001080C)
#define GPIOB_CRL	*((unsigned volatile int*)0x40010C04)
#define	GPIOB_ORD	*((unsigned volatile int*)0x40010C0C)
#define GPIOC_CRH	*((unsigned volatile int*)0x40011004)
#define	GPIOC_ORD	*((unsigned volatile int*)0x4001100C)
//-------------------???????-----------------------
void  Delay_ms( volatile  unsigned  int  t)
{
     unsigned  int  i;
     while(t--)
         for (i=0;i<800;i++);
}
void A_LED_LIGHT(){
	GPIOA_ORD=0x0<<5;		
	GPIOB_ORD=0x1<<9;		
	GPIOC_ORD=0x1<<14;		
}
void B_LED_LIGHT(){
	GPIOA_ORD=0x1<<5;		
	GPIOB_ORD=0x0<<9;		
	GPIOC_ORD=0x1<<14;		
}
void C_LED_LIGHT(){
	GPIOA_ORD=0x1<<5;		
	GPIOB_ORD=0x1<<9;		
	GPIOC_ORD=0x0<<14;			
}
int main()
{
	int j=100;
	RCC_AP2ENR|=1<<2;			
	RCC_AP2ENR|=1<<3;			
	RCC_AP2ENR|=1<<4;			
	GPIOA_CRL&=0xFF0FFFFF;			
	GPIOA_CRL|=0x00200000;		
	GPIOA_ORD|=1<<5;			
	
	GPIOB_CRL&=0xFFFFFF0F;			
	GPIOB_CRL|=0x00000020;		
	GPIOB_ORD|=1<<9;		
	
	GPIOC_CRH&=0xF0FFFFFF;		
	GPIOC_CRH|=0x02000000;   	
	GPIOC_ORD|=0x1<<14;			
	while(j)
	{	
		A_LED_LIGHT();	
		Delay_ms(10000000);
		B_LED_LIGHT();
		Delay_ms(10000000);
		C_LED_LIGHT();
		Delay_ms(10000000);
	}
}
