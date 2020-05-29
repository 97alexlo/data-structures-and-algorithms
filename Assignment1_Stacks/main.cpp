#include <iostream>
#include "Sequence.h"

using std::cout;
using std::endl;

void exercise1();

int main() {

    exercise1();
    return 0;
}

void exercise1()
{
    Sequence sq;
    sq.insert(1.1);
    double arr2[3] = {2.1,3.1,4.1};
    sq.insert(arr2, 3);
    sq.print();
    Sequence sq2;
    double arr[4] = {1,2,3,4};
    sq2.insert(arr, 4);
    sq2.print();
    Sequence sq3(sq2);
    sq3 = sq;
    sq3.print();
    Sequence sq4 = sq2.concatenate(sq);
    sq4.print();
    cout << "sq4 size " << sq4.size() << endl;
    Sequence sq5;
    sq5.insert(5.5);
    sq5.print();
    Sequence sq6;
    cout << "sq6 size " << sq6.size() << endl;
    cout << "sq size " << sq.size() << endl;
    cout << "sq5 size " << sq5.size() << endl;
    sq6 = sq.concatenate(sq5);
    sq6.print();
    sq6.size();
    cout << "sq6 size " << sq6.size() << endl;
    cout << "number of matches " << sq.find(2) << endl;
    cout << "size = " << sq.size() << endl;
    cout << "sum = " << sq.sum() << endl;
    cout << "mean = " << sq.mean() << endl;
    cout << "median = " << sq.median() << endl;
    cout << "standard deviation = " << sq.stddev() << endl;
}
