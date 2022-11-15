#ifndef		_ADC_INTERFACE_H
#define		_ADC_INTERFACE_H


#define    channel0     0
#define    channel1     1
#define    channel2     2
#define    channel3     3
#define    channel4     4
#define    channel5     5
#define    channel6     6
#define    channel7     7





void set_channel(u8 channel_id);

void ADC_INTI(void);

u16 ADC_GET_RES (void);

#endif
