class Solution
{
	public:
		
		int distributeCandies(vector<int>& candyTYpe)
		{
			int n = candyType.size();
			int d = n/2;
			
			map<int, int> mp;
			for(int i=0;i<n;i++)
			{
				mp[candyType[i]]++;
			}
			
			int s = mp.size();
			
			if(s>=d)
				return d;
			else
				return s;
		}
};
