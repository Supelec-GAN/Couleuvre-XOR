#include <iostream>

#include "neurone.hpp"
#include "neuronelayer.hpp"

using namespace std;

int main()
{
    NeuroneLayer n(5, 5);
    Eigen::VectorXf input(5);
    input << 1,2,3,4,5;
    cout << n.process(input)<< endl;
    return 0;
}
