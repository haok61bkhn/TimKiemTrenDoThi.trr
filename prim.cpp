#include<bits/stdc++.h>
#include<list>
#include<queue> 
#define Nmax int(1e5+100)
using namespace std;

int n,m,nheap;

queue< pair<int,int> > res;
bool kt[Nmax];


struct block{
	int first;
	int last;
	int weight;
};

block a[Nmax],heap[4*Nmax];
list<block> adj[Nmax];

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
		adj[u].push_back(a[i]);
		adj[v].push_back(a[i]);
		
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

void Program(){
	int Res1=0;
	int d=0;
	int u=1;
	while(d<n-1){
		
		d++;
		for(list<block> :: iterator i = adj[u].begin() ;i != adj[u].end();i++ ){
			block v=*i;
			if(!kt[v.first] or !kt[v.last]){
				Insert(v);
				
			}
			
		}
		int p=0;
		kt[u]=true;
		
		pair<int,int> x;
		while(kt[u]){
			if(!kt[heap[1].last]) u= heap[1].last;else u = heap[1].first;
		
			x=make_pair(heap[1].first,heap[1].last);
			p=heap[1].weight;
		
			swap(heap[1],heap[nheap]);
			nheap--;
			Downheap(1);
		}
		
			res.push(x);
			Res1+=p;

		
		


	
	}
//	while(!res.empty()){
//		cout<<res.front().first<<" "<<res.front().second<<"\n";
//		res.pop();
//	}
	cout<<Res1;
}

main(){
Input();
Program();
}

