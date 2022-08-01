class NumArray {
public:
    int *st;
    vector<int> a;
    int midV(int s, int e )
    {
        return s+ (e-s)/2;
    }
    
    int getSumU(int *st, int ss, int se , int qs , int qe, int si)
    {
        if(ss>qe||se<qs) return 0;
        if(ss>=qs && se<=qe) return st[si];
        int mid = midV(ss,se);
        return getSumU(st,ss ,mid,qs,qe,2*si+1) + getSumU(st,mid+1, se,qs,qe,2*si+2);

    }
    
    int getSum(int *st, int n , int qs , int qe)
    {
        if(qs<0 || qe>=n || qs>qe){
            cout<<"INvalid input";
            return -1;
        }
        return getSumU(st, 0,n-1,qs,qe,0);
    }
    int constructUtill(vector<int>& a, int ss, int se,int *st , int si)
    {
        if(ss==se){
            st[si] = a[ss];
            return a[ss];
        }
        int mid  = midV(ss,se);
        st[si] = constructUtill(a,ss,mid, st,2*si+1)+constructUtill(a,mid+1,se, st, 2*si+2);
        return st[si];

    }
    int *construct( vector<int>& a, int n )
    {
        int x = (int) (ceil(log2(n))); // height of the tree
        int maxlen = 2*(int)pow(2,x)-1; //sizeof segment tree array
        int *st = new int[maxlen];

        constructUtill(a, 0 , n-1 ,st, 0);
        return st;
    }
    void updateV(int *st,  int ss,int se , int i, int diff, int si)
    {
        if(i<ss || i>se) return ;
        st[si] = st[si] +diff;
        if(se!=ss)
        {
            int mid = midV(ss,se);
            updateV(st,ss, mid ,i,diff,2*si+1);
            updateV(st, mid+1,se ,i,diff,2*si+2);
        }
    }
    
    
    void updated(vector<int>& a, int *st ,int n, int i , int value)
    {
        if(i<0 || i>n-1)
        {
            cout<<"invalid values";
            return;
        }
        int diff =value-a[i];
        a[i] = value;
        updateV(st,0,n-1,i ,diff, 0);
    }
    
    
    
    
    
    NumArray(vector<int>& nums) {
        a= nums;
        int n = a.size();
        st = construct(a,n);
    }
    
    void update(int index, int val) {
        int n = a.size();
        updated(a,st,n,index , val);
    }
    
    int sumRange(int left, int right) {
        int n = a.size();
        return getSum(st, n,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */