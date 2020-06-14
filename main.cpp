#include <bits/stdc++.h>

using namespace std;
//Pranay Samrit Coding
struct node{    //node is basic element of graph
int index,value,gate;
};
//this is used to return 3 values from "min_node" function
struct m_node{
int vl,lb,hb;
};
//Graph
vector<vector<node> >G;

// function for returning minimum OR choice among children
struct m_node  min_node(int head)
{
if(G[head].size()<1){
    m_node pq;
    pq.vl=-1; pq.lb=-1; pq.hb=-1;
    return pq;
}
int m=INT_MAX,temp=INT_MAX,l,h,fx;
int j,k;
for(j=1;j<G[head].size();j++){
    fx=G[head][j].value+G[ G[head][j].index ][0].value;
    temp=fx;
     k=j+1;
    while( G[head][k].gate == G[head][j].gate && k < G[head].size() ){
        fx=G[head][k].value+G[ G[head][k].index ][0].value;
        temp+=fx;
        k++;
    }
    if(temp<m){
        l=j;    h=k-1;
        m=temp;
    }
    j=k-1;
    }
m_node p;
p.vl=m; p.lb=l; p.hb=h;
return p;
}

int fun(int head){
    int st=0;
if(G[head][0].value==0){
        G[head][0].index=-5;
    return 1;
}
m_node pq=min_node(head);
int minv=pq.vl,l=pq.lb,h=pq.hb;
if(minv==-1){
    return 0;
}
if(minv!=G[head][0].value){
    cout<<"head & l   h  "<<head<<"\t"<<l<<"\t"<<h<<endl;
    G[head][0].value=minv;
    return 0;
}
else{
st=0;
for(int k=l;k<h+1;k++){
    int f=fun(G[head][k].index);
    if(f==1)    st=1;
    else st=0;
}
}
if(st==1){
m_node pq=min_node(head);
int minv=pq.vl;
G[head][0].value=minv;
G[head][0].index=-5;
return 1;
}
else{
m_node pq=min_node(head);
int minv=pq.vl;
G[head][0].value=minv;
return 0;
}

}

void printfun(int head){
cout<<head<<"-->";
if(G[head][0].value==0){
    return ;
}
for(int k=1;k<G[head].size();k++){
    if(G[ G[head][k].index ][0].index==-5)
    {
        printfun(G[head][k].index);
    }
}
}
int main()
{int n,temp;
cout<<"Enter number of nodes\n";
cin>>n;
cout<<"Enter h value for each\n";
for(int i=0;i<n;i++){
    cin>>temp;
    node p;
    p.value=temp;p.index=-1; p.gate=-1;
    vector<node>v;
    G.push_back(v);
    G[i].push_back(p);
}
int m,id,ed,gt;
cout<<"Enter children details\n";
for(int i=0;i<n;i++){
    cout<<"Enter number of children of "<<i<<" th node\n";
    cin>>m;
    cout<<"Enter details in format 1.index of child 2.edge value 3.AND gate no\n";
    for(int j=0;j<m;j++){
        cin>>id>>ed>>gt;
        node p;
        p.index=id; p.value=ed; p.gate=gt;
        G[i].push_back(p);
    }
}
int f=0;
while(f!=1)
    f=fun(0);
cout<<" So Path is :\t";
printfun(0);
cout<<endl;
cout<<"Cost is : "<<G[0][0].value;
      return 0;
}
