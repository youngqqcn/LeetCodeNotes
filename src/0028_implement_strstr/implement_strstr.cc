// author: yqq
// date: 2021-05-28 20:38:02
// descriptions:
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

/*

  template<typename _CharT, typename _Traits, typename _Alloc>
    typename basic_string<_CharT, _Traits, _Alloc>::size_type
    basic_string<_CharT, _Traits, _Alloc>::
    find(const _CharT* __s, size_type __pos, size_type __n) const
    _GLIBCXX_NOEXCEPT
    {
      __glibcxx_requires_string_len(__s, __n);
      const size_type __size = this->size();

        if (__n == 0)
            return __pos <= __size ? __pos : npos;
        if (__pos >= __size)
            return npos;

        const _CharT __elem0 = __s[0];
        const _CharT* const __data = data();
        const _CharT* __first = __data + __pos;
        const _CharT* const __last = __data + __size;
        size_type __len = __size - __pos;

        // 分块匹配
        while (__len >= __n)
        {
            // 查找模式串的第0个字符,第一次出现的位置
            // Find the first occurrence of __elem0:
            __first = traits_type::find(__first, __len - __n + 1, __elem0);
            if (!__first)
                return npos;
            
            // 使用字符串比较
            // Compare the full strings from the first occurrence of __elem0.
            // We already know that __first[0] == __s[0] but compare them again
            // anyway because __s is probably aligned, which helps memcmp.
            if (traits_type::compare(__first, __s, __n) == 0)
                return __first - __data;

            __len = __last - ++__first;  // 继续匹配后面的, 长度减小
        }
        return npos;
    }


    size_type
    find(const basic_string& __str, size_type __pos = 0) const
      _GLIBCXX_NOEXCEPT
    { 
        return this->find(__str.data(), __pos, __str.size()); 
    }


*/

// 这道算法题,用 KMP算法可能不是好的选择,
class Solution
{
public:
    int strStr_STL(string haystack, string needle)
    {
        if ("" == needle)
            return 0;
        // 可以学习 std::string 的find实现, STL做了很大的算法优化
        size_t pos = haystack.find(needle);
        if (string::npos == pos)
        {
            return -1;
        }
        return pos;
    }

    // 生成next树组
    void genNext(vector<int> &next, string needle)
    {
        // aabaaf
        // 1.初始化
        next.resize(needle.length());
        next[0] = 0; // 不减1
        int slow = 0, fast = 1;
        for (int fast = 1; fast < needle.size(); fast++)
        {
            // 2.处理前后缀不相同的情况
            while (slow > 0 && needle[slow] != needle[fast])
            {
                // 回退
                slow = next[slow - 1];
            }

            // 3.处理前后缀相同的情况
            if (needle[slow] == needle[fast])
            {
                slow++;
            }
            next[fast] = slow;
        }
    }

    // KMP 算法实现
    int strStr_KMP(string haystack, string needle)
    {
        if (needle.empty())
            return 0;

        int j = 0;
        vector<int> next(needle.size());
        genNext(next, needle);
        int i = 0;
        for (; i < haystack.size() && j < next.size(); i++)
        {
            // 不匹配时, 回退
            while (j > 0 && haystack[i] != needle[j])
            {
                j = next[j - 1];
            }

            if (haystack[i] == needle[j])
            {
                j++;
            }
        }

        if (next.size() == j)
        {
            return i - next.size();
        }

        return -1;
    }

    // 非KMP实现, 模仿STL的string::find实现
    int strStr(string haystack, string needle)
    {
        using size_type = size_t;
        size_type __n = needle.size();
        size_type __pos = 0;
        using _CharT = char;
        const _CharT *__s = needle.c_str();

        const size_type __size = haystack.size();

        if (__n == 0) return 0;
            // return __pos <= __size ? __pos : -1;
        // if (__pos >= __size)
            // return 0;

        const _CharT __elem0 = __s[0];
        const _CharT *const __data = haystack.data();
        const _CharT *__first = __data + __pos;
        const _CharT *const __last = __data + __size;
        size_type __len = __size - __pos;

        while (__len >= __n)
        {
            // 查找模式串的第0个字符,第一次出现的位置
            // Find the first occurrence of __elem0:
            // __first = traits_type::find(__first, __len - __n + 1, __elem0);
            for (int i = 0; i < __len - __n + 1; i++)
            {
                if (__elem0 == __first[i])
                {
                    __first = &(__first[i]);
                    break; // for
                }
            }

            if (!__first)
                return -1;

            // 比较
            // Compare the full strings from the first occurrence of __elem0.
            // We already know that __first[0] == __s[0] but compare them again
            // anyway because __s is probably aligned, which helps memcmp.
            // if (traits_type::compare(__first, __s, __n) == 0)
            // return __first - __data;
            if (0 == memcmp(__first, __s, __n))
                return __first - __data;

            __len = __last - ++__first; // 继续匹配后面的, 长度减小
        }
        return -1;
    }
};

void test(string haystack, string needle, int expected)
{
    Solution sol;
    int ret = sol.strStr(haystack, needle);
    if (ret != expected)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    Solution sol;
    vector<int> next;
    sol.genNext(next, "aabaaf");
    // 0 1 0 1 2 0
    if (next != vector<int>({0, 1, 0, 1, 2, 0}))
    {
        cout << "FAILED" << endl;
        return 0;
    }

    test("hello", "ll", 2);
    test("aaaaa", "bba", -1);
    test("aabaabaaf", "aabaaf", 3);
    test("", "", 0);

    // cout << "hello world" << endl;
    return 0;
}
