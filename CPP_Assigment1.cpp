//Menelaos Pikridas AM:141291

#include <iostream>
#include <string>

using namespace std;

int calculation (int a, int b);
void change_variables(int &a,int &b);

int main (int argc, char **argv)
{
	int a = 5;
	int b = 8;
		
	//Dunamikh Desmeush Pinaka 
	int *grades = new int[3];
	
	//Allagh timhs const metablhths
	volatile const int  size = 3;
	//const int *size1 = &size;
	int *p = (int*) &size;
	*p = 100;
	
	for(int i=0; i<3; i++)
	{
		cout << "Dwse ton " <<i+1<<"o vathmo: ";
		cin >> grades[i]; 
	}
	cout << "\n";
	for(int i=0; i<3; i++)
	{
		cout<<i+1<<"os Vathmos: "<<grades[i]<<endl; 
	}
	cout << "\n";
	
	//Kaloume thn Calculation me parametrous 3 kai 5 
	int g = calculation(3,5); 
	cout << "Calculation:" << g << endl;
	cout << "\n";
	
	//Kaloume thn  change_variables
	change_variables(a,b); 
	cout << "a=" << a << "\n" << "b=" << b << endl;
	cout <<"Size:" << size << endl;
	cout << "\n";
	
	//Apeleutherwsh mnhmhs
	delete[] grades;
	delete p;
	return 0;
}

//Elegxei ton megalutero kai allazei thn mikroterh timh me ton megalutero
void change_variables(int &a,int &b)
{
	if(a>b)
	{
		b=a;
	}
	else
	{
		a=b;	
	}	
}

//Briskei tom megalutero arithmo apo tis duo parametrous kai ton epistrefei
int calculation (int a, int b)  
{
	if(a>b)
		return a;
	else
		return b;
}