#include <iostream>

using namespace std;

//迭代
int BinarySearch(int table[],int length,int k)
{
    int left = 0;
    int right = length;
    int notFound=-1;
    while(left<=right) {
        int mid = (left + right) / 2;
        if (k < table[mid]){
            right=mid-1;
        }else if(k>table[mid])
        {

            left=mid+1;
        }
        else if(k==table[mid])
        {

            return mid;
        }
    }
    return notFound;
}
//递归
int BinarySearchRecursive(int table[],int left,int right,int k)
{
    int mid=(left+right)/2;
    int notFound=-1;
    if(left<right)
    {
        if(k<table[mid])
        {
            return BinarySearchRecursive(table,left,mid-1,k);
        }else if(k>table[mid])
        {
            return BinarySearchRecursive(table,mid+1,right,k);
        }else{
            return mid;
        }
    }else if(left==right)
    {

        if(table[mid]==k)
        {
            return mid;
        }
        else
        {
            return notFound;
        }
    }
    return notFound;
}
//时间复杂度O(logN)
int main() {
    int table[]={2,6,9,10,43,65,87,321,1234,5642};
    int k=321;
    int result=BinarySearch(table, sizeof(table)/ sizeof(table[0]),k);
    int recursive = BinarySearchRecursive(table,0, sizeof(table)/ sizeof(table[0]),k);
    if(result!=-1){
        cout << "I found it by BinarySearch,the position is " <<result+1<< endl;}
    else{
        cout<<"I didn't find it by BinarySearch"<<endl;
    }
    if(recursive!=-1)
    {
        cout<<"I found it by recursive search,the position is "<<recursive+1<<endl;
    }else
    {
        cout<<"I didn't find it by recursive search"<<endl;
    }
    return 0;
}

