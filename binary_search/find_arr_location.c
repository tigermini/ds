int searchInsert(int *nums, int numsSize, int target) {
	int left, right, index;

	left = 0;
	right = numsSize - 1;

	while (left <= right) {
		index = (left + right) / 2;
		if (target == nums[index]) {
			return index;
		} else if (target < nums[index]) {
			if (index == 0) {
				return 0;
			}
			if (target > nums[index - 1]) {
				return index;
			}
			right = index - 1;
		} else {
			if (index == numsSize - 1) {
				return numsSize;
			}
			if (target < nums[index + 1]) {
				return index + 1;
			}
			left = index + 1;
		}
	}

	return -1;
}
