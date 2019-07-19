#include <bits/stdc++.h>

using namespace std;

// Complete the strangeCounter function below.
long strangeCounter(long t) {

    long num = 3;
    long counter = num;
    long inc = 1;

    while(inc < t) {
        inc += num - 1;
        counter -= num - 1;
        num *= 2;
        counter = num;
        inc += 1;
    }

    if(inc == t)
        return counter;
    else if (inc > t) {
        return (counter + (inc - t)) % num;
    }

    return counter;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    long t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = strangeCounter(t);

    fout << result << "\n";

    fout.close();

    return 0;
}
