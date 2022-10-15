vector<int> numberOfPairs(vector<int>& nums) {
  map<int, int> mp;
  for (auto it : nums)  mp[it]++;
  int pair = 0, left = 0;
  for (auto it : mp)  pair += it.second / 2;
  for (auto it : mp)  left += it.second % 2;
  return { pair,left };
}
