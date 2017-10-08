#include <iostream>

#include "neurone.hpp"

using namespace std;

int main()
{
    Neurone n(5);
    Eigen::VectorXf input(5);
    input << 1,2,3,4,5;
    cout << n.process(input)<< endl;
    //Eigen::VectorXd b(5);
    //b << 1,2,3,4,5;

    //cout << b.transpose()*input;

    return 0;
}
