#include<bits/stdc++.h>
#include<list>
#define Nmax int(1e4);
using namespace std;

int n,m;
list<int> adj[Nmax];

struct block{
	int first;
	int last;
	int weight;
};

block a[Nmax],heap[n*Nmax];

void Input(){
int v , w , u;
freopen("int.txt","r",stdin);
	cin>>n;
	m =  n*(n-1)/2 ;
	for(int i = 0 ; i < m ; i++){
		cin>> u >> v >> w; 
		a[i].first = u;
		a[i].last = v;
		a[i].weight = w;
		adj[u].push_back(v);
		adj[v].push_back(u);
		
	}
}

void Downheap(int m){
	int n=m*2;
	if(m<nheap and heap[m].weight>heap[m+1].weight) m++;
	if(m<=nheap){
		swap(heap[m],heap[n]);
		Downheap(n);
	}
	
}

void Upheap(int m){
	int n= m/2;
	if(heap[m].weight<heap[n].weight){
		swap(heap[m],heap[n]);
		Upheap(n);
	}
}

void Insert(block m){
	heap[++nheap]=m;
	Upheap(nheap);
	
}

void Test(){
	for(int i=0;i<n;i++)
		Insert(a[i]);
		
	while(nheap!=0){
		cout<<heap[1].first<<" "<<heap[1].last<<" "<<heap[1].weight<<"\n";
		swap(heap[1],heap[nheap]);
		nheap--;
		Downheap(1);
	}
}

main(){
Input();
Test();
}

