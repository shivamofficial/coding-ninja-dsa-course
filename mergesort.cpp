void merge(vector < int > & arr,int s,int e)
{
    int mid=(s+e)/2;
    int len1=mid-s+1;
    int len2=e-mid;
    
    int *first=new int [len1];
    int *second=new int[len2];
    int k=s;
    
    for(int i=0;i<len1;i++)
    {
        first[i]=arr[k++]; // copy value in 1st half
    }
    k=mid+1;
    for(int i=0;i<len2;i++)
    {
        second[i]=arr[k++]; // copy value into 2nd half
    }
    // merge 2 sort array
    int i=0;
    int j=0;
    k=s;
    while(i<len1 && j<len2)
    {
        if(first[i]<second[j])
        {
            arr[k++]=first[i++];
        }
        else
        {
            arr[k++]=second[j++];
        }
    }
    while(i<len1)
    {
        arr[k++]=first[i++];
    }
    while(j<len2)
    {
        arr[k++]=second[j++];
    }
    delete[]first;
    delete[]second;
        
}
void solve(vector < int > & arr,int s,int e)
{
    if(s>=e)
        return;
    int mid=(s+e)/2;
    // left part sort
    solve(arr,s,mid);
    // right part sort
    solve(arr,mid+1,e);
    // merge
    merge(arr,s,e);
}

void mergeSort(vector < int > & arr, int n) {
    // Write your code here.
    solve(arr, 0,n-1);
    
}
