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
        	if(!(stream>>array[i]))
		{
        		cout<<"nepolnuy massiv";
        		return false;
        	}   	
    	}
    	return true;
} 
void piramida(int *array,int k,int size){
	int fath;
	int son;
  	fath = array[k];
  	while(k <= size/2) {  		
    		son = 2*k;
    		if( son < size && array[son] < array[son+1] ) 
    		son++;
    		if( fath >= array[son] ) break;
    		array[k] = array[son]; 	
    		k = son;
  	}
  	array[k] = fath;
}
void heapsort(int * array,int size)
{
	for(int i=(size/2)-1;i>=0;i--)	{
		piramida(array,i,size-1);
	}
	for(int i=size;i>=0;i--)
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
