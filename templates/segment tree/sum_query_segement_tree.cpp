#include<bits/stdc++.h>

using namespace std;
#define boost        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int tree[200005]; //segment tree array

void buildTree(int* arr,int* tree, int start, int end, int treeNode){
  //base case
  if(start==end){
    tree[treeNode]=arr[start];
    return ;
  }
  int mid=(start+end)/2;
  buildTree(arr,tree,start,mid,2*treeNode); //left side of the segment tree
  buildTree(arr,tree,mid+1,end,2*treeNode+1); //right side of the segment tree

  tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1]; //filling the tree array
}

int sumQueryUtil(int* tree, int start, int end, int qStart, int qEnd, int treeNode){
  //if query segement is totally in the node segment
  if(start>=qStart && end<=qEnd)
    return tree[treeNode];
  //if query segment is totally outside the node segment
  else if(qEnd<start || qStart>end)
    return 0;
  //if the query segment has a intersection with the node segment
  else{
    int mid=(start+end)/2;
    return sumQueryUtil(tree,start,mid,qStart,qEnd,2*treeNode) + sumQueryUtil(tree,mid+1,end,qStart,qEnd,2*treeNode+1);
  }
}

int sumQuery(int* tree, int N, int qStart, int qEnd){
  if(qStart<0 || qEnd>N-1 || qStart>qEnd){
    cout<<"INVALID INPUT"<<" ";
    return -1;
  }
  else{
    return sumQueryUtil(tree,1,N,qStart,qEnd,1);
  }
}

int main(){
  boost;
  int N;
  cin>>N;
  int arr[N];
  for(int i=0;i<N;i++)
    cin>>arr[i];
  buildTree(arr,tree,0,N-1,1);  //building the segment tree with recursion

  int level=(log(N)/log(2))+1;
  // for(int i=1;i<(1<<(level+1));i++) // printing the tree
  //   cout<<tree[i]<<" ";
  int Q;
  cin>>Q;
  int a,b;
  while(Q--){ //in this query the array starting index is taken to be at 1 and thus query of 1..1 gives first element
    cin>>a>>b;
    cout<<sumQuery(tree,N,a,b)<<"\n";
  }
  return 0;
}
