/**

There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

 You can test your code in 
 https://leetcode-cn.com/problems/median-of-two-sorted-arrays/?utm_source=LCUS&utm_medium=ip_redirect_q_uns&utm_campaign=transfer2china
 */

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::vector;
using std::swap;
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

int main(int argc, char** argv)
{
  vector<int> nums1{1, 2, 3, 4, 5, 6, 7, 8, 9, 15, 67};
  vector<int> nums2{2, 3, 4, 5, 7, 9, 11, 13, 16, 20, 100};
  double res = findMedianSortedArrays(nums1, nums2);

  cout << "Result is : " << res << "\n";
  return 0;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
  int m = nums1.size();
  int n = nums2.size();
  if(m > n)
    {
      swap(nums1, nums2);
      swap(n, m);
    }

  int low = 0;
  int high = m;
  int k = (m+n+1)/2;

  while(low <= high)
    {
      int i = (low+high)/2; // nums1
      int j = k-i; // nums2
      if (i < high && nums1[i] < nums2[j-1]) // i is small and need move right
	{
	  low = i + 1;
	}
      else if (i > low && nums1[i-1] > nums2[j]) // i is large and need move left
	{
	  high = i - 1;
	}
      else // i and j is reasonable
	{
	  int maxleft;
	  if (i == 0)
	    {
	      maxleft = nums2[j-1];
	    }
	  else if (j == 0)
	    {
	      maxleft = nums1[i-1];
	    }
	  else
	    {
	      maxleft = max(nums1[i-1], nums2[j-1]);
	    }

	  if ((m+n)%2 == 1)
	    {
	      return maxleft * 1.0;
	    }

	  int minright;
	  if (i == m)
	    minright = nums2[j];
	  else if (j == n)
	    minright = nums1[i];
	  else
	    minright = min(nums1[i], nums2[j]);

	  return (maxleft+minright)/2.0;
	}
      
    }
  
}
