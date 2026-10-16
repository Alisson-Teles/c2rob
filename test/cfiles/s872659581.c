#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>





#define MAX_INT 2147483647
#define MIN_INT -2147483648





/*以下便利なマクロを定義する。*/

#define rep(i, min, max) for(i=min; i<=max; i=i+1)



#define if_forall(i, min, max, prop)\
\
	rep(i, min, max)\
	{\
		if(!(prop))\
		{\
			break;\
		}\
	}\
\
	if(i==max+1)\



#define if_exists(i, min, max, prop)\
\
	rep(i, min, max)\
	{\
		if(prop)\
		{\
			break;\
		}\
	}\
\
	if(i<max+1)\



#define sum(i, min, max, sequence, answer)\
{\
	answer=0;\
	rep(i, min, max)\
	{\
		answer=answer+sequence;\
	}\
}\



#define prod(i, min, max, sequence, answer)\
{\
	answer=1;\
	rep(i, min, max)\
	{\
		answer=answer*sequence;\
	}\
}\











/*以下便利な関数を定義する。*/

void fill_int(int array[], int min, int max, int element)
{
	int i=min;

	rep(i, min, max)
	{
		array[i]=element;
	}

}



void fill_int_array(int size_1, int size_2, int array[size_1][size_2], int i_min, int i_max, int j_min, int j_max, int element)
{
	int i=i_min;

	rep(i, i_min, i_max)
	{
		fill_int(array[i], j_min, j_max, element);
	}
}



void fill_char(char array[], int min, int max, char element)
{
	int i=min;

	rep(i, min, max)
	{
		array[i]=element;
	}

}



void fill_char_array(int size_1, int size_2, char array[size_1][size_2], int min, int max, char element[])
{
	int i=min, j=0;

	rep(i, min, max)
	{
		fill_char(array[i], 0, size_2-2, '\0');
		for(j=0; j<strlen(element); j=j+1)
		{
			array[i][j]=element[j];
		}
	}
}



void  swap_int(int* x, int* y)
{
    int  tmp;

    tmp = *x;
    *x = *y;
    *y = tmp;
}



void  swap_int_array(int x[], int y[], int min, int max)
{
	int i;

    rep(i, min, max)
	{
		swap_int(&x[i], &y[i]);
	}
}



void  swap_char(char* x, char* y)
{
    char  tmp;

    tmp = *x;
    *x = *y;
    *y = tmp;
}



void  swap_char_array(char x[], char y[], int min, int max)
{
	int i;

    rep(i, min, max)
	{
		swap_char(&x[i], &y[i]);
	}
}



void reverse_char(char array[], int min, int max)
{
	int i;

	rep(i, min, (min+max)/2)
	{
		swap_char(&array[i], &array[min+max-i]);
	}
}



int max_int(int var1, int var2)
{
	int answer=var1;

	if(answer<var2)
	{
		answer=var2;
	}

	return answer;
}



int min_int(int var1, int var2)
{
	int answer=var1;

	if(answer>var2)
	{
		answer=var2;
	}

	return answer;
}



double max_double(double var1, double var2)
{
	double answer=var1;

	if(answer<var2)
	{
		answer=var2;
	}

	return answer;
}



double min_double(double var1, double var2)
{
	double answer=var1;

	if(answer>var2)
	{
		answer=var2;
	}

	return answer;
}



long int pow_int(int base, unsigned int exponent)
{
	long int answer=1;

	answer=(long int)pow((double)base, (double)exponent);

	return answer;
}



long int pow_int_mod(int base, unsigned int exponent, int mod)
{
	long int answer=1;
	while (exponent>0)
	{
		if (exponent&1)
		{
			answer=(answer*(base%mod))%mod;
			if(answer==0)
			{
				break;
			}
		}
		base=(base*base)%mod;
		exponent=exponent>>1;
	}
	return answer;
}



unsigned long int factorial(unsigned int num)
{
	unsigned int i=0;
	unsigned long int answer=1;
	rep(i, 2, num)
	{
		answer=answer*i;
	}
	return answer;
}



unsigned long int factorial_mod(unsigned int num, int mod)
{
	unsigned int i=0;
	unsigned long int answer=1;
	rep(i, 2, num)
	{
		answer=(answer*(i%mod))%mod;
		if(answer==0)
		{
			break;
		}
	}
	return answer;
}



unsigned long int combination(unsigned int n, unsigned int k)
{
	unsigned int i=0;
	unsigned long int numerator=1;
	unsigned long int denominator=1;

	k=min_int(k, n-k);

	rep(i, 2, k)
	{
		numerator=numerator*(n+1-i);
		denominator=denominator*i;
	}
	return numerator/denominator;
}



double combination_general(double alpha, unsigned int k)
{
	unsigned int i;
	double numerator=1;
	unsigned long int denominator=1;

	rep(i, 1, k)
	{
		numerator=numerator*(alpha+1-i);
		denominator=denominator*i;
	}
	return numerator/denominator;
}



int gcd(int a, int b)
{
	if(a<b)
	{
		swap_int(&a, &b);
	}

	int r=a%b;

	while(r!=0)
	{
		a=b;
		b=r;
		r=a%b;
	}

	return b;
}



int lcm(int a, int b)
{
	return (a/gcd(a, b))*b;
}



int order(long int num)
{
	int answer=-1;
	while(num!=0)
	{
		num=num/10;
		answer=answer+1;
	}
	return answer;
}



long int convert_adic_int(char num[], unsigned int p_adic, unsigned int q_adic)
{
	int i=0;
	long int answer=0;
	bool sgn=0;
	long int tmp=strtol(num, NULL, p_adic);

	if(tmp<0)
	{
		sgn=1;
		tmp=-tmp;
	}

	while(tmp>0)
	{
		answer=answer+(tmp%q_adic)*pow_int(10, i);
		tmp=tmp/q_adic;
		i=i+1;
	}

	if(sgn==0)
	{
		return answer;
	}
	else
	{
		return -answer;
	}
}



void convert_adic_char(char num[], unsigned int p_adic, unsigned int q_adic)
{
	int i=0;
	int mod[32]={0};
	bool sgn=0;
	int digit=0;
	long int tmp=strtol(num, NULL, p_adic);

	if(tmp<0)
	{
		sgn=1;
		tmp=-tmp;
	}

	while(tmp>0)
	{
		mod[i]=tmp%q_adic;

		digit=i;
		tmp=tmp/q_adic;
		i=i+1;
	}

	fill_char(num, 0, min_int(0, strlen(num)-1), '\0');

	if(sgn==1)
	{
		num[0]='-';
	}

	rep(i, 0, digit)
	{
		if(mod[i]<10)
		{
			num[sgn+digit-i]='0'+mod[i];
		}
		else if(mod[i]<q_adic)
		{
			num[sgn+digit-i]='a'+(mod[i]-10);
		}
	}
}



int digit(int num)
{
	int i=0;
	int answer=0;
	while(num!=0)
	{
		num=num/10;
		answer=answer+1;
	}
	return answer;
}



int sum_digit(int num)
{
	int answer=0;
	num=abs(num);

	while(num>0)
	{
		answer=answer+num%10;
		num=num/10;
	}
	return answer;
}



int count_mod(int min, int max, int num)
{
	if(min>0)
	{
		return max/num-(min-1)/num;
	}
	else if(min==0)
	{
		return max/num+1;
	}
	else
	{
		return -1;
	}
}



void shift_char(char array[], int min, int max, int num)
{
	int i;
	int l=strlen(array);

	if(num>0)
	{
		max=min_int(max, l-num-1);

		for(i=max; i>=min; i=i-1)
		{
			array[i+num]=array[i];
		}

		for(i=min; i<=min+num-1; i=i+1)
		{
			array[i]='\0';
		}
	}
	else if(num<0)
	{
		min=max_int(min, -num);

		for(i=min; i<=max; i=i+1)
		{
			array[i+num]=array[i];
		}

		for(i=max+num+1; i<=max; i=i+1)
		{
			array[i]='\0';
		}
	}
}



void shift_int_array(int size, int array[size], int min, int max, int num)
{
	int i;

	if(num>0)
	{
		max=min_int(max, size-num-1);

		for(i=max; i>=min; i=i-1)
		{
			array[i+num]=array[i];
		}

		for(i=min; i<=min+num-1; i=i+1)
		{
			array[i]=0;
		}
	}
	else if(num<0)
	{
		min=max_int(min, -num);

		for(i=min; i<=max; i=i+1)
		{
			array[i+num]=array[i];
		}

		for(i=max+num+1; i<=max; i=i+1)
		{
			array[i]=0;
		}
	}
}



void convert_char(char array[], int min, int max, char pre, char post)
{
	int i=min;

	rep(i, min, max)
	{
		if(array[i]==pre)
		{
			array[i]=post;
		}
	}
}



void sort_asc_int(int array[], int min, int max)
{
	int i, j;

	rep(i, min, max)
	{
		rep(j, i+1, max)
		{
			if(array[i]>array[j])
			{
				swap_int(&array[i], &array[j]);
			}
		}
	}
}



void sort_des_int(int array[], int min, int max)
{
	int i, j;

	rep(i, min, max)
	{
		rep(j, i+1, max)
		{
			if(array[i]<array[j])
			{
				swap_int(&array[i], &array[j]);
			}
		}
	}
}



void sort_asc_char_dic(char array[], int min, int max)
{
	int i, j;

	rep(i, min, max)
	{
		rep(j, i+1, max)
		{
			if(strcmp(&array[i], &array[j])>0)
			{
				swap_char(&array[i], &array[j]);
			}
		}
	}
}



void sort_asc_char_array_dic(int size_1, int size_2, char array[size_1][size_2], int min, int max)
{
	int i, j;

	rep(i, min, max)
	{
		rep(j, i+1, max)
		{
			if(strcmp(array[i], array[j])>0)
			{
				swap_char_array(array[i], array[j], 0, size_2-1);
			}
		}
	}
}



void sort_des_char_dic(char array[], int min, int max)
{
	int i, j;

	rep(i, min, max)
	{
		rep(j, i+1, max)
		{
			if(strcmp(&array[i], &array[j])<0)
			{
				swap_char(&array[i], &array[j]);
			}
		}
	}
}



void sort_des_char_array_dic(int size_1, int size_2, char array[size_1][size_2], int min, int max)
{
	int i, j;

	rep(i, min, max)
	{
		rep(j, i+1, max)
		{
			if(strcmp(array[i], array[j])<0)
			{
				swap_char_array(array[i], array[j], 0, size_2-1);
			}
		}
	}
}



int max_int_array(int array[], int min, int max)
{
	int i;
	int answer;

	answer=array[min];

	rep(i, min+1, max)
	{
		answer=max_int(answer, array[i]);
	}

	return answer;
}



void max_int_array_num(int array[], int min, int max, int answer[])
{
	int i, j;
	int count=0;

	fill_int(answer, 0, max-min, -1);

	rep(i, min, max)
	{
		count=0;
		rep(j, min, max)
		{
			if(array[i]<array[j])
			{
				count=count+1;
			}
		}
		j=0;
		while(answer[count+j]!=-1)
		{
			j=j+1;
		}
		answer[count+j]=i;
	}
}



void max_int_array_table(int array[], int min, int max, int size_1, int size_2, int answer[size_1][size_2])
{
	int i, j;
	int count=1;

	fill_int(answer[0], 0, size_2-1, 0);
	for(i=1; i<=size_1-1; i=i+1)
	{
		answer[i][0]=MIN_INT;
		fill_int(answer[i], 1, size_2-1, -1);
	}



	int copy[max-min+1];
	for(i=0; i<=max-min; i=i+1)
	{
		copy[i]=array[i+min];
	}

	sort_des_int(copy, 0, max-min);

	answer[1][0]=copy[0];

	i=1;
	count=2;
	while(i<=max-min)
	{
		if(copy[i]!=answer[count-1][0])
		{
			answer[count][0]=copy[i];
			count=count+1;
		}
		i=i+1;
	}
	answer[0][0]=count-1;



	for(j=1; j<=answer[0][0]; j=j+1)
	{
		count=0;
		for(i=min; i<=max; i=i+1)
		{
			if(array[i]==answer[j][0])
			{
				count=count+1;
				answer[j][count]=i;
			}
		}
		answer[0][j]=count;
	}
}



int max_int_whatnumber(int array[], int min, int max, int num)
{
	int i;
	int ans=1;

	for(i=min; i<=max; i=i+1)
	{
		if(array[num]<array[i])
		{
			ans=ans+1;
		}
	}
	return ans;
}




int min_int_array(int array[], int min, int max)
{
	int i;
	int answer;

	answer=array[min];

	rep(i, min+1, max)
	{
		answer=min_int(answer, array[i]);
	}

	return answer;
}



void min_int_array_num(int array[], int min, int max, int answer[])
{
	int i, j;
	int count=0;

	fill_int(answer, 0, max-min, -1);

	rep(i, min, max)
	{
		count=0;
		rep(j, min, max)
		{
			if(array[i]>array[j])
			{
				count=count+1;
			}
		}
		j=0;
		while(answer[count+j]!=-1)
		{
			j=j+1;
		}
		answer[count+j]=i;
	}
}



void min_int_array_table(int array[], int min, int max, int size_1, int size_2, int answer[size_1][size_2])
{
	int i, j;
	int count=1;

	fill_int(answer[0], 0, size_2-1, 0);
	for(i=1; i<=size_1-1; i=i+1)
	{
		answer[i][0]=MAX_INT;
		fill_int(answer[i], 1, size_2-1, -1);
	}



	int copy[max-min+1];
	for(i=0; i<=max-min; i=i+1)
	{
		copy[i]=array[i+min];
	}

	sort_asc_int(copy, 0, max-min);

	answer[1][0]=copy[0];

	i=1;
	count=2;
	while(i<=max-min)
	{
		if(copy[i]!=answer[count-1][0])
		{
			answer[count][0]=copy[i];
			count=count+1;
		}
		i=i+1;
	}
	answer[0][0]=count-1;



	for(j=1; j<=answer[0][0]; j=j+1)
	{
		count=0;
		for(i=min; i<=max; i=i+1)
		{
			if(array[i]==answer[j][0])
			{
				count=count+1;
				answer[j][count]=i;
			}
		}
		answer[0][j]=count;
	}
}



int min_int_whatnumber(int array[], int min, int max, int num)
{
	int i;
	int ans=1;

	for(i=min; i<=max; i=i+1)
	{
		if(array[num]>array[i])
		{
			ans=ans+1;
		}
	}
	return ans;
}



double max_double_array(double array[], int min, int max)
{
	int i=min;
	double answer;

	answer=array[min];

	rep(i, min+1, max)
	{
		answer=max_double(answer, array[i]);
	}

	return answer;
}



double min_double_array(double array[], int min, int max)
{
	int i=min;
	double answer;

	answer=array[min];

	rep(i, min+1, max)
	{
		answer=min_double(answer, array[i]);
	}

	return answer;
}



int max_char_array_dic(int size_1, int size_2, char array[size_1][size_2], int min, int max)
{
	int i;
	int answer=min;

	rep(i, min+1, max)
	{
		if(strcmp(array[answer], array[i])<0)
		{
			answer=i;
		}
	}

	return answer;
}



void max_char_array_dic_num(int size_1, int size_2, char array[size_1][size_2], int min, int max, int answer[])
{
	int i, j;
	int count=0;

	fill_int(answer, 0, max-min, -1);

	for(i=min; i<=max; i=i+1)
	{
		count=0;
		for(j=min; j<=max; j=j+1)
		{
			if(strcmp(array[i], array[j])<0)
			{
				count=count+1;
			}
		}
		j=0;
		while(answer[count+j]!=-1)
		{
			j=j+1;
		}
		answer[count+j]=i;
	}
}



int max_char_whatnumber(int size_1, int size_2, char array[size_1][size_2], int min, int max, int num)
{
	int i;
	int ans=1;

	for(i=min; i<=max; i=i+1)
	{
		if(strcmp(array[num], array[i])<0)
		{
			ans=ans+1;
		}
	}
	return ans;
}



int min_char_array_dic(int size_1, int size_2, char array[size_1][size_2], int min, int max)
{
	int i;
	int answer=min;

	rep(i, min+1, max)
	{
		if(strcmp(array[answer], array[i])>0)
		{
			answer=i;
		}
	}

	return answer;
}



void min_char_array_dic_num(int size_1, int size_2, char array[size_1][size_2], int min, int max, int answer[])
{
	int i, j;
	int count=0;

	fill_int(answer, 0, max-min, -1);

	for(i=min; i<=max; i=i+1)
	{
		count=0;
		for(j=min; j<=max; j=j+1)
		{
			if(strcmp(array[i], array[j])>0)
			{
				count=count+1;
			}
		}
		j=0;
		while(answer[count+j]!=-1)
		{
			j=j+1;
		}
		answer[count+j]=i;
	}
}



int min_char_whatnumber(int size_1, int size_2, char array[size_1][size_2], int min, int max, int num)
{
	int i;
	int ans=1;

	for(i=min; i<=max; i=i+1)
	{
		if(strcmp(array[num], array[i])>0)
		{
			ans=ans+1;
		}
	}
	return ans;
}



int sum_array(int array[], int min, int max)
{
	int i=min;
	int answer=0;

	rep(i, min, max)
	{
		answer=answer+array[i];
	}

	return answer;
}



bool detect_int(int array[], int min, int max, int element)
{
	int i;
	bool answer=0;

	if_exists(i, min, max, array[i]==element)
	{
		answer=1;
	}

	return answer;
}



bool detect_char(char array[], int min, int max, char element)
{
	int i;
	bool answer=0;

	if_exists(i, min, max, array[i]==element)
	{
		answer=1;
	}
	return answer;
}



bool detect_char_array(char array[], int min, int max, char element[], int start, int goal)
{
	int i, j;
	bool answer=0;

	if(goal-start<=max-min)
	{
		rep(i, min, max-(goal-start))
		{
			if_forall(j, start, goal, array[i+j-start]==element[j])
			{
				answer=1;
				break;
			}
		}
	}

	return answer;
}




int count_differentelement_int(int array[], int min, int max)
{
	int i=min;
	int pickup[max];
	fill_int(pickup, 0, max, 0);
	int answer=0;

	rep(i, min, max)
	{
		if(detect_int(pickup, 0, answer-1, array[i])==0)
		{
			pickup[answer]=array[i];
			answer=answer+1;
		}
	}

	return answer;
}



int count_differentelement_char(char array[], int min, int max)
{
	int i=min;
	char pickup[max];
	fill_char(pickup, 0, max, '\0');
	int answer=0;

	rep(i, min, max)
	{
		if(detect_char_array(pickup, 0, answer-1, array, i, i)==0)
		{
			pickup[answer]=array[i];
			answer=answer+1;
		}
	}

	return answer;
}



int count_equalelement_int(int array[], int min, int max, int element)
{
	int i;
	int answer=0;

	rep(i, min, max)
	{
		if(array[i]==element)
		{
			answer=answer+1;
		}
	}

	return answer;
}



int count_equalelement_char(char array[], int min, int max, char element)
{
	int i;
	int answer=0;

	rep(i, min, max)
	{
		if(array[i]==element)
		{
			answer=answer+1;
		}
	}

	return answer;
}



int count_equalelement_char_array(int size_1, int size_2, char array[size_1][size_2], int min, int max, char element[])
{
	int i;
	int answer=0;

	rep(i, min, max)
	{
		if(strcmp(array[i], element)==0)
		{
			answer=answer+1;
		}
	}
	return answer;
}



int graph_number_of_euler_path_sub(int size, int adjacency_matrix[size][size], int start, int target)
{
	int i=0;
	int j=0;
	int k=0;

	bool flag=1;

	int answer=0;
	int answer_sub=0;

	int copy_matrix[size][size];

	for(i=0; i<size; i=i+1)
	{
		for(j=0; j<size; j=j+1)
		{
			copy_matrix[i][j]=adjacency_matrix[i][j];
		}
	}

	if(adjacency_matrix[start][target]>0)
	{
		if(start!=target)
		{
			copy_matrix[start][target]=copy_matrix[start][target]-1;
			copy_matrix[target][start]=copy_matrix[target][start]-1;
		}
		else
		{
			copy_matrix[start][target]=copy_matrix[start][target]-1;
		}
		if_exists(j, 0, size-1, copy_matrix[target][j]>0)
		{
			for(k=0; k<size; k=k+1)
			{
				answer_sub=answer_sub+graph_number_of_euler_path_sub(size, copy_matrix, target, k);
			}
		}
		else
		{
			for(i=0; i<size; i=i+1)
			{
				for(j=0; j<size; j=j+1)
				{
					if(copy_matrix[i][j]!=0)
					{
						answer_sub=0;
						flag=0;
						break;
					}
				}
				if(flag==0)
				{
					break;
				}
			}

			if(flag==1)
			{
				answer_sub=1;
				flag=-1;
			}
		}
	}
	answer=adjacency_matrix[start][target]*answer_sub;
	return answer;
}


int graph_number_of_euler_path(int size, int adjacency_matrix[size][size])
{
	int i=0;
	int j=0;

	int answer=0;

	for(i=0; i<size; i=i+1)
	{
		for(j=0; j<size; j=j+1)
		{
			answer=answer+graph_number_of_euler_path_sub(size, adjacency_matrix, i, j);
		}
	}
	return answer;
}



int graph_number_of_hamilton_path_sub(int size, int adjacency_matrix[size][size], int start, int target)
{
	int i=0;
	int j=0;
	int k=0;

	int answer=0;

	int copy_matrix[size-1][size-1];

	if(start==target)
	{
		answer=0;
	}
	else
	{
		if(size==2)
		{
			if(adjacency_matrix[start][target]>0)
			{
				answer=adjacency_matrix[start][target];
			}
			else
			{
				answer=0;
			}
		}
		else if(size>2)
		{
			if(adjacency_matrix[start][target]>0)
			{
				for(i=0; i<start; i=i+1)
				{
					for(j=0; j<start; j=j+1)
					{
						copy_matrix[i][j]=adjacency_matrix[i][j];
					}
					for(j=start; j<size-1; j=j+1)
					{
						copy_matrix[i][j]=adjacency_matrix[i][j+1];
					}
				}
				for(i=start; i<size-1; i=i+1)
				{
					for(j=0; j<start; j=j+1)
					{
						copy_matrix[i][j]=adjacency_matrix[i+1][j];
					}
					for(j=start; j<size-1; j=j+1)
					{
						copy_matrix[i][j]=adjacency_matrix[i+1][j+1];
					}
				}
				for(k=0; k<size-1; k=k+1)
				{
					if(start>target)
					{
						answer=answer+adjacency_matrix[start][target]*graph_number_of_hamilton_path_sub(size-1, copy_matrix, target, k);
					}
					else if(start<target)
					{
						answer=answer+adjacency_matrix[start][target]*graph_number_of_hamilton_path_sub(size-1, copy_matrix, target-1, k);
					}
				}
			}
			else if(adjacency_matrix[start][target]==0)
			{
				answer=0;
			}
		}
	}
	return answer;
}



int graph_number_of_hamilton_path(int size, int adjacency_matrix[size][size])
{
	int i=0;
	int j=0;

	int answer=0;

	for(i=0; i<size; i=i+1)
	{
		for(j=0; j<size; j=j+1)
		{
			answer=answer+graph_number_of_hamilton_path_sub(size, adjacency_matrix, i, j);
		}
	}
	return answer;
}



void scanf_int_array(int array[], int min, int max)
{
	int i;
	rep(i, min, max)
	{
		scanf("%d", &array[i]);
	}
}



void scanf_int_array_2(int array1[], int array2[], int min, int max)
{
	int i;
	rep(i, min, max)
	{
		scanf("%d %d", &array1[i], &array2[i]);
	}
}



void scanf_int_array_3(int array1[], int array2[], int array3[], int min, int max)
{
	int i;
	rep(i, min, max)
	{
		scanf("%d %d %d", &array1[i], &array2[i], &array3[i]);
	}
}



void scanf_char(char array[], int num)
{
	scanf("%s", array);
	shift_char(array, 0, strlen(array)-1, num);
}



void scanf_char_array(int size_1, int size_2, char array[size_1][size_2], int min, int max, int num)
{
	int i;
	rep(i, min, max)
	{
		scanf_char(array[i], num);
	}

}



void printf_int_array(int array[], int min, int max)
{
	int i;
	rep(i, min, max)
	{
		printf("%d\n", array[i]);
	}
}



void printf_char_array(char array[], int min, int max)
{
	int i;
	for(i=min; i<=max; i=i+1)
	{
		printf("%c", array[i]);
	}
}










int main(void)
{
	int i=0;
	int answer=10;

	long int N;
	scanf("%ld", &N);

	int root=floor(sqrt(N));

	for(i=root; i>=1; i=i-1)
	{
		if(N%i==0)
		{
			answer=digit(N/i);
			break;
		}
	}

	printf("%d\n",answer);

	return 0;
}
