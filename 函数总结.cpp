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
功能：遍历数组寻找元素所在的下标 
element:要寻找的元素 
array:数组名
length:数组的长度 
index:返回该元素的下标 
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
功能：遍历数组寻找众数 
array:数组名
length:数组的长度 
mode:返回的众数 
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
功能：对浮点型数组进行冒泡排序 
排序结果：从大到小 
array:数组名
length:数组的长度 
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
功能：对整型数组进行冒泡排序 
排序结果：从大到小 
array:数组名
length:数组的长度 
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
功能：对两个数组相同下标的元素值
	  进行比较，判断两个数组的偏
	  差是否满足要求 
array1:数组1
array2:数组2
length:数组的长度 
redundancy:冗余度，即判定范围 
retrun: 1:满足；0 不满足 
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
功能：将字符串转化为double类型 
str: 字符串数组  
retrun: target即为所求的double数据 
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















