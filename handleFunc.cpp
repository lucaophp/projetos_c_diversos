#include <iostream>
#include <stdlib.h>

using namespace std;
int sum(int n1,int n2)
{
	return n1+n2;
}
void show(int (*f)(int,int),int n1,int n2)
{
	cout << f(n1,n2) << endl;
}
int* map(int* arr,int n, int (*handle)(int)){
	int i = 0;
	int *arr2;
	arr2 = (int*) malloc(n*sizeof(int));
	for(i = 0; i < n;i++)
	{
		int x = handle(arr[i]);
		arr2[i] = x;
	}
	cout << endl;
	return arr2;
}
// callback function
int showValues(int n){
	cout << n << '\t';
	int a = n;
	a = a+1;
	return a;
}
int main()
{
	int arr[] = {1,2,3,4,5,6,7};
	int *ptrArr = NULL;
	ptrArr = map(arr,7,showValues);
	for(int i = 0; i < 7;i++)
	{
		cout << ptrArr[i] << endl;
	}
	map(ptrArr,7,showValues);
	show(sum,10,20);
	return 0;
}
