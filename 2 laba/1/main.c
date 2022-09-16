#include <stdio.h>

int main(){
    int fn, sn, num;
    //fn + sn = 11
    //sn = 11 - fn
    //we repeat this loop for 9 times, since number should have one digit
    //fn = 2, since (11 - fn) should be one-digit number
    for (fn = 2; fn <= 9; fn++) {
        sn = 11 - fn;
        num = (10 * fn) + sn;
        //10fn + sn + 27 = 10sn + fn
        if (num + 27 == ((10 * sn) + fn)){
            printf("The number is %d.", num);
        }
    }
    return 0;
}
