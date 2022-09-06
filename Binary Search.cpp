// using recursion
int search(int arr[],int s,int e,int key)
{
    // base case // ek jab element found or dusra not found
    if(s>e)
    {
return -1; // not found case
    }
    int mid=s+(e-s)/2;
    if(arr[mid]==key)
    {
        return mid;
    }
    if(arr[mid]<key)
    {
        return search(arr,mid+1,e,key);
    }
    else{
 return search(arr,s,mid-1,key);
    }

}
int binarySearch(int *input, int n, int val)
{
    //Write your code here
    int ans=search(input,0,n-1,val);
 
    
}
