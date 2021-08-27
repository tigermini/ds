int search(int *nums, int numsSize, int target)
{
	int left, right, index;

	left = 0;
	right = numsSize - 1;

	while (left <= right) {
		index = (right + left) / 2;
		if (target == nums[index]) {
			return index;
		} else if (target < nums[index]) {
			right = index - 1;
		} else {
			left = index + 1;
		}
	}

	return -1;
}
