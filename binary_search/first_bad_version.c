int firstBadVersion(int n) 
{
	unsigned long long bad, left, right;

	left = 1;
	right = n;

	while (left <= right) {
		bad = (left + right) / 2;
		if (isBadVersion(bad)) {
			right = bad - 1;
			if (!isBadVersion(right)) {
				return bad;
			}
		} else {
			left = bad + 1;
			if (isBadVersion(left)) {
				return left;
			}
		}
	}

	return -1;
}
