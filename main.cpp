#include <iostream>
#include <string>
#include <sstream>
using namespace std;
void vyvod(int *array,unsigned int size)
{
	for(unsigned int i=0;i<size;i++)
	{
		cout<<array[i]<<" ";
	}
}
bool vvod(int *array,unsigned int size)
{
    string stroka;
    getline(cin,stroka);	
    istringstream stream(stroka);
    for(unsigned int i=0;i<size;i++)
    {
        if(!(stream>>array[i])){
            cout<<"nepolnuy massiv";
            return false;
        }   	
    }
    return true;
} 
void piramida(int *array,int k,int size){
int a;
  int x;
  a = array[k];
  while(k <= size/2) {  		
    x = 2*k;
    if( x < size && array[x] < array[x+1] ) 
    x++;
    if( a >= array[x] ) break;
    array[k] = array[x]; 	
    k = x;
  }
  array[k] = a;
}
void heapsort(int * array,int size)
{
for(int i=(size/2)-1;i>=0;i--)	{
		piramida(array,i,size-1);
	}
		for(int i=size-1;i>=0;i--)
		{
			swap(array[0],array[i]);
			piramida(array,0,i-1);
		}
	}
int main(int argc, char** argv) {
	unsigned int size;
	string stroka;
        getline(cin,stroka);
        istringstream stream(stroka);
	if(!(stream>>size)){
        	cout<<"error"<<endl;
       		return -1;
    	}	
	int *array=new int[size];
	if(vvod(array,size))
	{
		heapsort(array,size-1);
		vyvod(array,size);
	}
	delete[]array;
	return 0;
}
