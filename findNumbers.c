/*Given an array nums of integers, return how many of them contain an even number of digits.
*/
int findNumbers(int* nums, int numsSize) {
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        int digits = 0;

        if (num == 0) {
            digits = 1;
        } else {
            while (num != 0) {
                num /= 10;
                digits++;
            }
        }

        if (digits % 2 == 0) {
            count++;
        }
    }

    return count;
}
