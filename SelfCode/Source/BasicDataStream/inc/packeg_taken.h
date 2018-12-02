///////////////////////////////////////////////////////////////////
//����ʱ�䣺2018-11-27
//�޸�ʱ�䣺2018-12-1
//������Ա��HaHaHaHaHaGe
//�޸���Ա��HaHaHaHaHaGe
//��Ҫ���ܣ��Ӹ���������(ringbufffer)��ȡ��Ч���ݰ�
//�����е�һ��Ԥ��������λ��䣩/����λԤ����
//		
//��־��
//
//2018-11-27:�������ļ�
//�趨��ͷpacket_header��
//ȷ��ԭʼ���ݽṹsource_data
//
//2018-11-30
//ȥ��source_data
//
//2018-12-1
//���Ӻ���search_packeg
///////////////////////////////////////////////////////////////////
#ifndef  __PACKEG_TAKEN_H__
#define __RINGBUFFER_H__
#include "../../Factory/basic_header.h"
#include "../../Factory/inc/basic_crc32.h"

#define __REDUCTION_DATA_LENGTH__ 1024




/*
��ƴ�ӵ�����������Ѱ����ȷ�����ݰ�
���ݰ���ʽ��
-------------------------------------------------------
0-3		4-7		8-11	12-N
��ͷ	���ݳ�	CRC32	����
-------------------------------------------------------
��ڲ�����
src1:��һ������
src2:�ڶ�������
len1:��һ�������С
len2:�ڶ��������С
rdata_1:�������ݵĵ�һָ��
rdata_2:�������ݵĵڶ�ָ��
rlen_1:�������ݵ�һָ��ָ������ݶγ���
rlen_2:�������ݵڶ�ָ��ָ������ݶγ���
����ֵ��
�Ƿ��ҵ����ݰ�
*/
u8 search_packeg(u8*src1, u8*src2, u32 len1, u32 len2, u8**rdata_1, u8**rdata_2, u32*rlen_1, u32*rlen_2);

#endif