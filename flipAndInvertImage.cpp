#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {

        for(auto& result : image)
        {
            // Flip the row
            reverse(result.begin(), result.end());

            // Invert the values
            for(int i = 0; i < result.size(); i++)
            {
                result[i] = 1 - result[i];
            }
        }

        return image;
    }
};

int main()
{
    Solution obj;

    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    vector<vector<int>> image(rows, vector<int>(cols));

    cout << "Enter matrix elements:" << endl;

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cin >> image[i][j];
        }
    }

    vector<vector<int>> result = obj.flipAndInvertImage(image);

    cout << "Result:" << endl;

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << result[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}
