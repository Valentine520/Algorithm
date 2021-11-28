#include <stdio.h>
/*
 * 查找数组中的最大连续子数组
 * 最大子数组存在于要么是左边要么是右边要么是中间
 * 利用递归的方式求解 计算左中右的值 返回最大的即可
 * 同时 利用这种思想 可以设计一个时间复杂度为线性的算法
 * 即k+1规模的最大连续子数组 只可能位于k规模的最大数组
 * 或者i到k+1的连续子数组上 利用这种思想既可以设计线性时间复杂度的算法
 * 详情见《算法导论》
 */
typedef struct{
    int left;//最长连续数组的left
    int right;//同理
    int value;//最长连续数组的长度
}Item;

/*
 * 递归版本求解最大连续子数组
 */

//接口
Item Find_Max_SunArray_Recursion_Interface(int *array,int size);

//主要函数
Item Find_Max_SubArray_Recursion(int *array,int left,int right);

//求解中间cross内容
Item Find_Cross_Max_SubArray_Recursion(const int *array,int left,int right);


/*
 * 线性版本求解
 */
Item Find_Max_SubArray_Linear(const int *array,int size);

Item Find_Cross_Max_SubArray_Linear(const int *array,int right);


int main() {
    Item data1;
    Item data2;
    int array1[]={1,2,3,3,-10,2,30};
    int array2[]={1,2,1,34,-221,2,1,231,1};
    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof array2 / sizeof array2[0];
    int sum1=0;
    for(int i=0;i<size1;i++){
        sum1+=array1[i];
    }
    printf("%d\n",sum1);
    int sum2=0;
    for(int i=0;i<size2;i++){
        sum2+=array2[i];
    }
    printf("%d\n",sum2);
    data1 = Find_Max_SubArray_Linear(array1,size1);
    data2 = Find_Max_SunArray_Recursion_Interface(array2,size2);
    printf("Linear: \nleft:%d right:%d value:%d\n",data1.left,data1.right,data1.value);
    printf("Recursion: \nleft:%d right:%d value:%d\n",data2.left,data2.right,data2.value);
    return 0;
}




/*
 * 由于Recursion涉及到递归 对于函数的接口不同
 * 因此定义一个对外接口 以便能够统一调用
 */

Item Find_Max_SunArray_Recursion_Interface(int *array,int size){
    return Find_Max_SubArray_Recursion(array,0,size-1);
}


Item Find_Max_SubArray_Recursion(int *array,int left,int right){
    //表明该值就是最大的
    if(left>=right){
        Item data;
        data.left=data.right=left;
        data.value=array[left];
        return  data;
    }
    else{
        int mid=(right-left)/2+left;
        //划分
        Item info1 = Find_Max_SubArray_Recursion(array,left,mid);
        Item info2 = Find_Max_SubArray_Recursion(array,mid+1,right);

        //解决
        Item info3 = Find_Cross_Max_SubArray_Recursion(array,left,right);

        //合并 选择三者中最大的
        if(info1.value>=info2.value&&info1.value>=info3.value){
            return info1;
        }
        else if(info2.value>=info1.value&&info2.value>=info3.value){
            return info2;
        }
        else{
            return info3;
        }
    }
}
//中间的长度为max
Item Find_Cross_Max_SubArray_Recursion(const int *array,int left,int right){
    int mid=(right-left)/2+left;
    int sum=0;
    Item data;
    int left_max=0;
    data.left=0;
    int right_max=0;
    data.right=0;
    for(int i=mid;i>=left;i--){
        sum+=array[i];
        if(sum>left_max){
            left_max=sum;
            data.left=i;
        }
    }
    sum=0;
    for(int i=mid+1;i<=right;i++){
        sum+=array[i];
        if(sum>right_max){
            right_max = sum;
            data.right=i;
        }
    }
    data.value=left_max + right_max;
    return data;
}

//中间的长度为max
Item Find_Cross_Max_SubArray_Linear(const int *array,int right){
    int left=0;
    int sum=0;
    Item data;
    int max=0;
    data.right=right;
    data.left=left;
    for(int i=right;i>=0;i--){
        sum+=array[i];
        if(sum>max){
            max=sum;
            data.left=i;
        }
    }
    data.value=max;
    return data;
}

//线性时间复杂度的算法
Item Find_Max_SubArray_Linear(const int *array,int size){
    int left=0;
    //从left开始 作为第一个max数组
    Item MaxInfo;
    MaxInfo.left=MaxInfo.right=left;
    MaxInfo.value=array[left];
    for(int i=1;i<=size-1;i++){
        Item NewInfo = Find_Cross_Max_SubArray_Linear(array,i);//时间复杂度主要来源于该函数 可以在线性时间内完成
       //判断左边最大的数组和从i+1到左边的数组大小
       if(MaxInfo.value<NewInfo.value){
           MaxInfo=NewInfo;
       }
    }
    return MaxInfo;
}

