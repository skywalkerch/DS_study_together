#define MaxSize 50
typedef struct {
    int data[MaxSize];
    int length;
}SqList;

int swap(int &a, int &b){
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
    return 0;
}

int BubbleSort(SqList &L,SqList &L_Sort){
    L_Sort = L;
    for(int i = 1;i<L_Sort.length ;i++){
        for(int j = 0;j<L_Sort.length - i;j++){
            if(L.data[j] > L.data[j+1])
                swap(L.data[j],L.data[j+1]);
        }
    }
    return 0;
}

int InsertSort(SqList &L){
    int j = 0;//已排序的队列长度
    for(int i = 1;i < L.length; i++){
        int min = 0,max = j,mid = (min+max)/2;;
        while(min <= max){
            if(L.data[i] > mid){
                min = mid + 1;
            }
            else{
                max = mid - 1;
            }
        }
        swap(L.data[mid],L.data[i]);
        j ++;
    }
    return 0;
}

int Parction(SqList &L, int low, int high){
    int pivot = L.data[low];
    while(low < high){
        while(low < high && L.data[high] >= pivot) --high;
        L.data[low] = L.data[high];
        while(low < high && L.data[low] <= pivot) ++low;
        L.data[high] = L.data[low];
    }
    L.data[low] = pivot;
    return low;
}

int QuickSort(SqList &L, int low, int high){
    if(low < high){
        int pivotpos = Parction(L,low,high);
        QuickSort(L,low,pivotpos-1);
        QuickSort(L,pivotpos+1,high);
    }
}

int HeadAdjust(SqList L, int k, int len){
    L.data[0] = L.data[k];
    for(int i = 2 * k; i <= len; i *= 2){
        if(i < len && L.data[i] < L.data[i+1])  i ++;
        if(L.data[0] >= L.data[i])   break;
        else{
            L.data[k] = L.data[i];
            k = i;
        }
    }
    L.data[k] = L.data[0];
}

int BulidMaxHeap(SqList L, int len){
    for(int i = len/2; i > 0; i--)
    HeadAdjust(L,i,len);
}

int HeapSort(SqList L, int len){
    BulidMaxHeap(L, len);
    for(int i = len; i > 1; i --){
        swap(L.data[i], L.data[1]);
        HeadAdjust(L, 1, i-1);
    }
}

int Merge(SqList L, int low, int mid, int high){
    SqList B;
    int i, j, k;
    //copy
    for(k = low; k<= high; k++){
        B.data[k] = L.data[k];
    }
    //
    for(i = low, j = mid + 1, k = i; i <= mid && j<= high; k++){
        if(L.data[k] <= B.data[j])  L.data[k] = B.data[i++];
        else L.data[k] = B.data[j++];
    }
    while(i <= mid)     L.data[k++] = B.data[i++];
    while(j <= high)    L.data[k++] = B.data[j++];
};

int MergeSort(SqList L, int low, int high){
    if(low < high){
        int mid = (low + high)/2;
        MergeSort(L, low, mid);
        MergeSort(L, mid + 1, high);
        Merge(L, low, mid, high);
    }
}

int main(){
    SqList L;
    int tmp[50] = {1};
}





