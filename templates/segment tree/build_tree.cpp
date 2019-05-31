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

int main(){
  boost;
  int N;
  cin>>N;
  int arr[N];
  for(int i=0;i<N;i++)
    cin>>arr[i];
  buildTree(arr,tree,0,N-1,1);  //building the segment tree with recursion

  int level=(log(N)/log(2))+1;
  for(int i=1;i<(1<<(level+1));i++) // printing the tree
    cout<<tree[i]<<" ";

  return 0;
}
