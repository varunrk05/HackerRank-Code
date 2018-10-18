/*Maximum Pairwise Product Problem
Find the maximum product of two distinct numbers
in a sequence of non-negative integers.
Input: A sequence of non-negative
integers.
Output: The maximum value that
can be obtained by multiplying
two different elements from the sequence*/

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

using std::cin;

using std::cout;


long long MaxPairwiseProduct(const vector<int> &numbers) {

    int n = numbers.size();



    int max_index1 = -1;

    for (int i = 0; i < n; ++i)

        if ((max_index1 == -1) || (numbers[i] > numbers[max_index1]))

            max_index1 = i;



    int max_index2 = -1;

    for (int j = 0; j < n; ++j)

        if ((j != max_index1) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2])))

            max_index2 = j;



    //cout << max_index1 << ' ' << max_index2 << "\n";



    return ((long long) (numbers[max_index1])) * numbers[max_index2];


}

int main() {
    int n;

    cin >> n;

    vector<int> numbers(n);

    for (int i = 0; i < n; ++i) {

        cin >> numbers[i];

    }



    long long result = MaxPairwiseProduct(numbers);

    cout << result << "\n";

    return 0;
}
