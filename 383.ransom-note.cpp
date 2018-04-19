class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> hs; 
    for (char c : magazine) hs[c]++;

    for (char c : ransomNote) --hs[c];

    for (auto& pr : hs) if (pr.second < 0) return false;
    return true;
  }
};
