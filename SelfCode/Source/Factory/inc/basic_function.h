///////////////////////////////////////////////////////////////////
//����ʱ�䣺2018-11-16
//�޸�ʱ�䣺2018-11-30
//������Ա��HaHaHaHaHaGe
//�޸���Ա��HaHaHaHaHaGe
//��Ҫ���ܣ�basic_function�ж������뱾Э��ջ�޹صĹ����ຯ��
//			�磬�ڴ�Ĺ�����
//		
//��־��
//
//2018-11-16:
//�������ļ�������
//void* basic_malloc(u32 size)
//void basic_free(void* block)
//�����������ڴ�ķ������ͷ�
//
//2018-11-21:
//���Ӻ���void basic_memcpy(u8* dst,u8* src,u32 size)
//
//2018-11-30:
//����basic_swap���������ڴ�����ͬ��С�˵�����
//////////////////////////////////////////////////////////////////
#ifndef __BASIC_FUNCTION_H__
#define __BASIC_FUNCTION_H__

#include "../basic_header.h"

/*
�����ڴ�
��ڲ���:
size:��Ҫ����Ŀռ��С����λ�ֽ�
*/
void* basic_malloc(u32 size);


/*
�ͷ��ڴ�
��ڲ���:
block:�ͷſռ��ָ��
*/
void basic_free(void* block);




/*
�ڴ濽��
��ڲ�����
dst����������λ��
src����Ҫ������λ��
size����Ҫ�����Ĵ�С���ֽڣ�
*/
void basic_memcpy(u8* dst, u8* src, u32 size);



/*
���ݴ�С�˵Ĳ�ͬ�޸�����
��ڲ�����
x��Դ����
����ֵ��
�����������
*/
u32 basic_swap(u32 x);
#endif // !__BASIC_FUNCTION_H__