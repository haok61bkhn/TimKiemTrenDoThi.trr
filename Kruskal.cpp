#include<bits/stdc++.h>
#include<list>
#define Nmax int(1e5)


using namespace std;
int nheap,n,m,Res;
int fa[Nmax],rank[Nmax];


struct block{
	int first;
	int last;
	int weight;
};

block a[Nmax],heap[4*Nmax];


void Input(){
int v , w , u;
//freopen("int.txt","r",stdin);
	cin>>n;
	cin>>m;
	for(int i = 0 ; i < m ; i++){
		cin>> u >> v >> w; 
		a[i].first = u;
		a[i].last = v;
		a[i].weight = w;
		
	}
}

void Downheap(int m){
	int n=m*2;
	if(n<nheap and heap[n].weight>heap[n+1].weight) n++;
	if(n<=nheap and heap[n].weight<heap[m].weight){
		swap(heap[m],heap[n]);
		Downheap(n);
	}
	
}

void Upheap(int m){
	int n= m/2;
	if(heap[m].weight<heap[n]. weight and n>0){
		swap(heap[m],heap[n]);
		Upheap(n);
	}
}

void Insert(block m){
	heap[++nheap]=m;
	Upheap(nheap);
	
}

int Find(int u){
	while(u != fa[u]) u=fa[u];
	
	return fa[u];
}

bool Check(int n,int m){
int u = Find(n);
int v = Find(m);

	if( u == v) return false;
	if( rank[u] == rank[v]) rank[u]++;
	if(rank[u] > rank[v]) fa[v] = u ;else fa[u] = v;
	return true;
	
}

void Program(){
	for(int i=0;i<m;i++)
	 Insert(a[i]);
	for(int i=0;i<n;i++) fa[i]=i;
	
	int d=0;
	 while(d<n-1){
	 	if(Check(heap[1].first , heap[1].last)) {
	 		Res += heap[1].weight;
	 		d ++ ;
	 		
		 }
		 swap(heap[nheap],heap[1]);
		 nheap--;
		 Downheap(1);
		 
	 }	
	 cout<<Res;
}


main(){
	Input();
	Program();
	
}
	
	


