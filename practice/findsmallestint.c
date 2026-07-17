//-4 -2 0 1 2 4 5 
/*
arr , size=7
i=0, i< size, exp=1
arr[0]<0-- true -- skip
i=1, i<size
arr[1]<0--- true --skip
i=2, i<size
arr[2]==0-- true -- skip
i=3, i<size
arr[3]==expected==1 --true --expected=2
i=4, i<size
arr[4]==2==expected --true --expected=3
i=5, i<size
arr[5]>expected --true --expected=3
return expected
*/


#include <stdio.h>
int findSmallMissingPos(int arr[], int size) {
    int expected = 1;
    for (int i = 0; i < size; i++) {
        //ignore nonpositive numbers
        if(arr[i] <= 0) {
            continue;
        }
        if(arr[i] == expected){
            expected++;
        }
        else if(arr[i] > expected){
            return expected;
        }
    }
    return expected;
}

int main() {
    int arr[] = {-4, -2, 0, 1, 2, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Smallest missing positive number = %d\n",
           findSmallMissingPos(arr, size));

    return 0;
}