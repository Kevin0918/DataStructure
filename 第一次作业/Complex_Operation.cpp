#include <stdio.h>
typedef struct Complex
{
	float real;//复数的实部
	float image;//复数的虚部
}Complex;
void CreateComplex(Complex &c,float a,float b)//创建复数
{
	c.real=a;
	c.image=b;
}
void OutComplex(Complex c)//输出复数
{
	if(c.real==0.0)
		printf("%2.1f*i\n",c.image);
	else
		printf("%2.1f+%2.1f*i\n",c.real,c.image);
	if(c.image==0.0)
		printf("%2.1f\n",c.image);
}
void AddComplex(Complex &sum,Complex c1,Complex c2)//复数加运算
{
	sum.real=c1.real+c2.real;
	sum.image=c1.image+c2.image;
}
void SubComplex(Complex &sub,Complex c1,Complex c2)//复数减运算
{
	sub.real=c1.real-c2.real;
	sub.image=c1.image-c2.image;	
}
void MulComplex(Complex &mul,Complex c1,Complex c2)//复数乘运算
{
	mul.real=c1.real*c2.real-c1.image*c2.image;
	mul.image=c1.real*c2.image-c1.image*c2.real;
	
}
void DivComplex(Complex &div,Complex c1,Complex c2)//复数除运算
{
	div.real=(c1.real*c2.real+c1.image*c2.image)/(c2.real*c2.real+c2.image*c2.image);
	div.image=(c1.image*c2.real-c1.real*c2.image)/(c2.real*c2.real+c2.image*c2.image);
}
int main()
{
	float a,b,c,d;
	int i;
	Complex c1,c2,sum,sub,mul,div;
	printf("请输入复数的实部和虚部：\n");
	scanf("%f%f",&a,&b);
	printf("请再次输入另一个复数的实部和虚部：\n");
	scanf("%f%f",&c,&d);
	CreateComplex(c1,a,b);
	CreateComplex(c2,c,d);
	printf("您输入的复数分别是：\n");
	OutComplex(c1);
	OutComplex(c2);
	printf("---------------------\n");
	printf("请选择你所要的运算：\n");
	printf("1、相加\n2、相减\n3、相乘\n4、相除\n");
	scanf("%d",&i);
	switch(i){
		case 1: 
			AddComplex(sum,c1,c2);
			printf("两复数之和为： ");
			OutComplex(sum);
			break;
		case 2: 
			SubComplex(sub,c1,c2);
			printf("两复数之差为： ");
			OutComplex(sub);
			break;
		case 3: 
			MulComplex(mul,c1,c2);
			printf("两复数之积为： ");
			OutComplex(mul);
			break;
		case 4: 
			DivComplex(div,c1,c2);
			printf("两复数之商为： ");
			OutComplex(div);
			break;
	}
	return 0;
}