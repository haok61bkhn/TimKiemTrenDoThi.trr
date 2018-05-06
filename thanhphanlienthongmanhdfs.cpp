#include<bits/stdc++.h>
#include<string>
#include<list>
#define Nmax int(3e4)
using namespace std;
int n,postvisit[Nmax],previsit[Nmax];
int cl,m;
bool visited[Nmax];

list<int> a[Nmax];
list<int> ar[Nmax];

struct node{
	int previsit;
	int postvisit;
	bool visited=false;
	int data;
};typedef node Node;
Node b[Nmax];




bool Check(string x,string y){	
int j;
    for(int i=x.length()-1;i>=x.length()-4;i--){
    	for( j=0;j<y.length();j++)
			if(x[i]==y[j]){
				y[j]='0';
				break;
			} 
    	if(j==y.length()) return false;
		
	}
		   	
	return true;
}

void Input(){

string s;	
int j;
int d=0;
ifstream ifs("int.txt");
	
	for( n=1;n<=5757;n++){
		getline(ifs,s);
		c[n]=s;
		for(j=1;j<n-1;j++){
		  if(Check(b[j],s)) {a[j].push_back(n);ar[n].push_back(j);}
		  if(Check(s,b[j])) {a[n].push_back(j);ar[j].push_back(n);}
		}
		
	}
	
	n--;
				
}


void DFS(int u){
	cl++;
	b[u].data=u;
	b[u].previsit=cl;
	b[u].visited=true;
	
list<int>::iterator i=a[u].begin();
	for(;i!=a[u].end();i++)
		if(!b[*i].visited){	
		DFS(*i);
		}
		cl++;		
		b[u].postvisit=cl;
}

void Dijkstra

void Program(){
	for(int i=1;i<=n;i++)
	  if(!b[i].visited) DFS(i);
}

main(){
Input();
Program();
}
