class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> v(k);
        if(x<arr[0])
        {
            for(int i=0;i<k;i++)
            {
                v[i]=arr[i];
            }
            return v;
        }
        if(x>arr[arr.size()-1])
        {
            int i=arr.size()-1;
            int j=k-1;
            while(j>=0)
            {
                v[j]=arr[i];
                j--,i--;
            }
            return v;
        }


    int lo=0;
    int hi=arr.size()-1;
    bool flag=false;
    int mid=-1;
    int t=0;
    while(lo<=hi)
    {
        mid=lo+(hi-lo)/2;
        if(arr[mid]==x)
        {
            flag=true;
            v[t]=arr[mid];
            t++;
            break;
        }
        else if(arr[mid]<x) lo=mid+1;
        else{
            hi=mid-1;
        }
    }
    int lb=hi,ub=lo;
    if(flag==true)
    {
        lb=mid-1;
        ub=mid+1;
    }
    while(t<k && ub<=arr.size()-1 && lb>=0)
    {
       int d1=abs(x-arr[lb]);
       int d2=abs(x-arr[ub]);
        if(d1<=d2)
        {
            v[t]=arr[lb];
            lb--;
        }
        else
        {
             v[t]=arr[ub];
            ub++;
        }
        t++;

        }
        if(lb<0)
        {
            while(t<k)
            {
                 v[t]=arr[ub];
                ub++,t++;
            }
        }
        if(ub>arr.size()-1)
        {
            while(t<k)
            {
                 v[t]=arr[lb];
                lb--,t++;
            } 
        }

 sort(v.begin(),v.end());
return v;
    }
};
