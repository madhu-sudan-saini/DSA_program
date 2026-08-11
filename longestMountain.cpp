#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {

        int n = arr.size();
        int ans = 0;

        for(int i = 1; i < n - 1; i++)
        {
            // Check whether i is a peak
            if(arr[i - 1] < arr[i] && arr[i] > arr[i + 1])
            {
                int left = i;
                int right = i;

                // Find the left side of mountain
                while(left > 0 && arr[left - 1] < arr[left])
                {
                    left--;
                }

                // Find the right side of mountain
                while(right < n - 1 && arr[right + 1] < arr[right])
                {
                    right++;
                }

                int length = right - left + 1;

                ans = max(ans, length);
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int result = obj.longestMountain(arr);

    cout << "Longest Mountain Length: " << result << endl;

    return 0;
}
