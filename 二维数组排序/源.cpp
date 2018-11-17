/**********************************************
对二维数组进行冒泡排序
二维数组在内存中是线性排列的
所以可以将二维数组看成一个大的一维数组
一维数组到二维数组下标对应关系为
b[pos] ------> a[i][j]
pos / col = i	; 	pos % col = j
**********************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
void sort(int a[][5], int n = 4)
{
	//直接对二维数组进行排序
	for (int i = 0; i < n * 5 - 1; ++i)
	{
		for (int j = 0; j < n * 5 - i - 1; ++j)
		{
			if (a[j / 5][j % 5] > a[(j + 1) / 5][(j + 1) % 5])
			{
				swap(a[j / 5][j % 5], a[(j + 1) / 5][(j + 1) % 5]);
			}
		}
	}
	/*************************************************
	//第二种方法先将二维数组转存在一个一维数组中
	//这种方法比较直观，但是多了一个步骤
	int *b = new int[5 * n];
	//以下注释的带pos的语句是二维数组与一维数组之间不需要计算坐标的转化方式
	//int pos = 0;
	for(int i = 0; i != n; ++i)
		for(int j = 0; j != 5; ++j)
			b[i * 5 + j] = a[i][j];
			//b[pos++] = a[i][j];
	//对一维数组排序
	for(int i = 0; i != 5 * n - 1; ++i)
		for(int j = 0; j != 5 * n - 1 - i; ++j)
			if(b[j] > b[j + 1])
				swap(b[j], b[j + 1]);
	//把一维数组内容回存到二维数组
	//pos = 0;
	//for(int i = 0; i != n; ++i)
	//	for(int j = 0; j != 5; ++j)
	//		a[i][j] = b[pos++];
	for(int i = 0; i != 5 * n; ++i)
		a[i / 5][i % 5] = b[i];
	delete []b;		//释放内存
	*********************************************/
}
void print(int a[][5], int n = 4)
{
	for (int i = 0; i != n; ++i)
	{
		for (int j = 0; j != 5; ++j)
			cout << a[i][j] << '\t';
		cout << endl;
	}
}

int main()
{
	cout << "二维数组排序" << endl;
	int a[4][5];
	srand(static_cast<unsigned int>(time(0)));
	for (int i = 0; i != 4; ++i)
		for (int j = 0; j != 5; ++j)
			a[i][j] = rand() % 100;
	sort(a);
	print(a);
	system("pause");
	return 0;
}
