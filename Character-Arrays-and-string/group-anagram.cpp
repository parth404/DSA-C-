// 49. Group Anagrams

// Given an array of strings strs, group the anagrams together.
// You can return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a
// different word or phrase, typically using all the original letters exactly once.

// Example 1:

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

// Example 2:

// Input: strs = [""]
// Output: [[""]]

// Example 3:

// Input: strs = ["a"]
// Output: [["a"]]

// Constraints:

// 1 <= strs.length <= 104
// 0 <= strs[i].length <= 100
// strs[i] consists of lowercase English letters.

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

std::array<int, 256> hashIt(string s)
{
    std::array<int, 256> hash = {0};
    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i]]++;
    }
    return hash;
}

// #1 APPROACH
//----------------------------------------------------------------------------------------

// vector<vector<string>> groupAnagrams(vector<string> &strs)
// {

//     // --------------------------------TIME COMPLEXITY---------------------------------
//     // N -> size of strs
//     // K -> length of largest string inside strs
//     // For sorting T.C -> O(N Klogk) & S.C -> O(NK)

//     // create a hash map to store key value pairs
//     map<string, vector<string>> mp;

//     // Our Approach consists of following steps
//     // 1. Sorting the string inside strs and making it the key
//     // 2. Storing the string as a value to the key

//     // map values to keys
//     for (auto str : strs)
//     {
//         string s = str;
//         sort(s.begin(), s.end()); // s is sorted and can be used as key
//         mp[s].push_back(str);     // map string to the key
//     }

//     vector<vector<string>> ans;

//     // store values to answer array
//     for (auto it = mp.begin(); it != mp.end(); it++)
//     {
//         ans.push_back(it->second);
//     }

//     return ans;
// }

// #2 APPROACH :: Without using sorting
//----------------------------------------------------------------------------------------

vector<vector<string>> groupAnagrams(vector<string> &strs)
{

    // --------------------------------TIME COMPLEXITY---------------------------------
    // N -> size of strs
    // K -> length of largest string inside strs
    // For sorting T.C -> O(N Klogk) & S.C -> O(NK)

    // create a hash map to store key value pairs
    map<std::array<int, 256>, vector<string>> mp;

    // Our Approach consists of following steps
    // 1. Sorting the string inside strs and making it the key
    // 2. Storing the string as a value to the key

    // map values to keys
    for (auto str : strs)
    {
        mp[hashIt(str)].push_back(str);
    }

    // store values to answer array
    vector<vector<string>> ans;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        ans.push_back(it->second);
    }

    return ans;
}

// OUTPUT
int main()
{
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};

    for (auto val : groupAnagrams(strs))
    {
        cout << "[";
        for (auto grp : val)
        {
            cout << grp << ", ";
        }
        cout << "], ";
    }
    return 0;
}