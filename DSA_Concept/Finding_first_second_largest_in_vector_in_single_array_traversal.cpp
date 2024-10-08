
first = -1,second = -1
for(int i=0;i<arr.size();i++){
    if(first<arr[i]){
        second = first
        first = arr[i]
    }else{
        second = max(second,arr[i])
    }
}