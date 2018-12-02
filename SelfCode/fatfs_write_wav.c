#include "fatfs_write_wav.h"
#include "../inc/ringbuffer.h"

__WaveHeader wav_head;
FIL wav_file;
UINT br,bw;
ringbuffer buffer;
u8 dmabuffer[2048];
u8*data_1,*data_2;
u32 data1_len,data2_len;
extern TIM_HandleTypeDef htim3;
extern ADC_HandleTypeDef hadc1;

unsigned char close_wav_file()
{
	retSD = f_lseek(&wav_file,0);
	if(retSD != FR_OK)
		return retSD;
	retSD = f_write(&wav_file, (const void*)&wav_head, sizeof(__WaveHeader), &bw);
	if(retSD != FR_OK)
		return retSD;
	retSD = f_close(&wav_file);
	return retSD;
	
}


unsigned char create_wav_file(char*filename,unsigned int fs)
{
	retSD = f_open(&wav_file, filename, FA_CREATE_ALWAYS | FA_WRITE | FA_READ);
	if(retSD != FR_OK)
		return retSD;
	recoder_wav_init(&wav_head,fs);
	retSD = f_write(&wav_file, (const void*)&wav_head, sizeof(__WaveHeader), &bw);
	return retSD;
}


unsigned char write_wav_file(unsigned char*wavdata,unsigned int len)
{
	retSD = f_write(&wav_file, wavdata, len, &bw);
	if(retSD != FR_OK)
		return retSD;
	recoder_wav_update(&wav_head,len);
	return retSD;
}



void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc)
{
	write_buffer_data(&buffer,dmabuffer,1024);
}
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
	write_buffer_data(&buffer,&dmabuffer[1024],1024);
}



unsigned char initial_recoder(char*filename,unsigned int fs)
{
	htim3.Instance->ARR = (96000000/fs) - 1;
	initial_buffer(&buffer,YES,65536);
	return create_wav_file(filename,fs);
}

void start_recoder()
{
	HAL_TIM_Base_Start(&htim3);
	HAL_ADC_Start_DMA(&hadc1,(uint32_t*)dmabuffer,1024);
}


u8 stop_recoder()
{
	HAL_ADC_Stop_DMA(&hadc1);
	HAL_TIM_Base_Stop(&htim3);
	return close_wav_file();
}



void tick_recoder()
{
		__disable_irq();
		get_unread_ptr(&buffer,&data_1,&data_2,&data1_len,&data2_len,NO);
		__enable_irq();
		if(data1_len != 0)
			write_wav_file(data_1,data1_len);
		if(data2_len != 0)
			write_wav_file(data_2,data2_len);
}








