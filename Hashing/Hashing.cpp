#include <iostream>

using namespace std;
int hashingFun(const char * key, int size)
{
    int sum = 0;
    for (int j = 0; j < size; j++)
        sum = sum + static_cast<int>(key[j]);
    return (sum % 13);

}

int main()
{
    cout<<hashingFun("mahmoud", 7);

}