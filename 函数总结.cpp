#include<stdio.h>
#include<string.h>
#include<math.h>
 
unsigned char TraversalArray(float element, float *array, unsigned char length);
float ArrayMode(float *array, unsigned char length);
void BubbleSortFloat(float *array, unsigned char length); 
void BubbleSortInt(int *array, unsigned char length);
bool ArrayComparison(float *array1, float *array2, unsigned char length, float redundancy);
double StrConvertDouble(char *str);
 
int main()
{
	float array1[5] = {1.045, 8.023, 3.346, 4.25, 5.027};
	float array2[5] = {1.145, 9.988, 3.446, 4.123, 5.045}; 
	char str[10] = "123.45678";
	//bool flag = ArrayComparison(array1, array2, 5, 0.2);
	//printf("%d\n",flag);
	double target = StrConvertDouble(str);
	printf("%lf\n",target);
	return 0;
} 



/*******************************
���ܣ���������Ѱ��Ԫ�����ڵ��±� 
element:ҪѰ�ҵ�Ԫ�� 
array:������
length:����ĳ��� 
index:���ظ�Ԫ�ص��±� 
********************************/
unsigned char TraversalArray(float element, float *array, unsigned char length)
{
	unsigned char i,index;
	for(i=0;i<length;i++)
	{
		if(*array == element)
		{
			index = i+1;
			break;	
		}
		array += 1;
	}
	return index;
}

/*******************************
���ܣ���������Ѱ������ 
array:������
length:����ĳ��� 
mode:���ص����� 
********************************/
float ArrayMode(float *array, unsigned char length)
{
	unsigned char i, j, count, count_last, index;
	float mode;               
	for(j=0;j<length;j++)
	{
		for(i=j+1;i<length;i++)
		{
			if(array[i] == array[j])
			{
				count++;
			}
		}
		if(count>count_last)
			index = j;
		count_last = count;
	}
	mode = 	array[index];
	return mode;	
}

/*******************************
���ܣ��Ը������������ð������ 
���������Ӵ�С 
array:������
length:����ĳ��� 
********************************/
void BubbleSortFloat(float *array, unsigned char length) 
{
	float temp;
	for(unsigned int i=0;i<length-1;i++)
	{
		for(unsigned int j=0 ; j<length-1-i;j++)
		{
			if (*(array+j)<*(array+j+1))
			{
				temp = *(array+j);
				*(array+j) = *(array+j+1);
				*(array+j+1) = temp;
			}
		}
	}
}

/*******************************
���ܣ��������������ð������ 
���������Ӵ�С 
array:������
length:����ĳ��� 
********************************/
void BubbleSortInt(int *array, unsigned char length) 
{
	int temp;
	for(unsigned int i=0;i<length-1;i++)
	{
		for(unsigned int j=0 ; j<length-1-i;j++)
		{
			if (*(array+j)<*(array+j+1))
			{
				temp = *(array+j);
				*(array+j) = *(array+j+1);
				*(array+j+1) = temp;
			}
		}
	}
}
 
/*******************************
���ܣ�������������ͬ�±��Ԫ��ֵ
	  ���бȽϣ��ж����������ƫ
	  ���Ƿ�����Ҫ�� 
array1:����1
array2:����2
length:����ĳ��� 
redundancy:����ȣ����ж���Χ 
retrun: 1:���㣻0 ������ 
********************************/
bool ArrayComparison(float *array1, float *array2, unsigned char length, float redundancy)
{
	bool judge;
	unsigned char count;
	for(unsigned char i=0; i<length; i++)
	{
		float error = *(array1+i) - *(array2+i);
		if(error<=redundancy && error>=-redundancy)
			count++;
	}
	judge = (count == length) ? 1:0;
	return judge;
}

/*******************************
���ܣ����ַ���ת��Ϊdouble���� 
str: �ַ�������  
retrun: target��Ϊ�����double���� 
********************************/
double StrConvertDouble(char *str)
{
	unsigned char i;
	unsigned char point_index;
	double integr;
	double decimal;
	unsigned char length = strlen(str);
	for(i=0;i<length;i++)
	{
		if(*(str+i) == '.')
			point_index = i;
	}
	for(i=0;i<point_index;i++)
		integr += (str[i] - '0') * pow(10,(point_index-i-1));
	for(i=point_index+1;i<length;i++)
		decimal += (str[i] - '0') * pow(0.1,(i-point_index));
	
	double target = integr+decimal;
	return target;
} 















