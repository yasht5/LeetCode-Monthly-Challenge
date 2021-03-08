class Solution
{
	public:
		
		int removePlaindrome(string s)
		{
			int n = s.length();
			
			if(n==0)
				return 0;
			int left = 0;
			int right = n-1;
			while(left<=right)
			{
				if(s[left]==s[high])
				{
					left++;
					right--;
				}
				else
					return 2;
			}
			return 1;
		}
};
