#include <iostream>
using namespace std;

int main(){

int a[10];

for(int i=0; i<10; i++){
cin>>a[i];
}

cout<<"Vettore di partenza"<<endl;
for(int i=0; i<10; i++){
cout<<a[i]<<'\t';
}

cout<<"Ordine crescente"<<endl;
//Ordine crescente
for(int i=0; i<10; i++){
	for(int j=0; j<10; j++){
		if(a[j]>a[j+1]){
			int temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
		}
	}
}

for(int i=0; i<10; i++){
cout<<a[i]<<'\t';
}

cout<<"Ordine decrescente"<<endl;


//Ordine decrescente
for(int i=0; i<10; i++){
	for(int j=0; j<10; j++){
		if(a[j]<a[j+1]){
			int temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
		}
	}
}

for(int i=0; i<10; i++){
cout<<a[i]<<'\t';
}

return 0;
}
