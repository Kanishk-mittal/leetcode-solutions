# include <iostream>
# include <vector>

using namespace std;

class ProductOfNumbers
{
private:
    vector<int> prefix;
    int lastZeroIndex = -1;
public:
    ProductOfNumbers()
    {
        prefix.push_back(1);
    }

    void add(int num)
    {
        if (num == 0)
        {
            prefix.clear();
            prefix.push_back(1);
            lastZeroIndex = prefix.size() - 1;
        }
        else
        {
            prefix.push_back(prefix.back() * num);
        }
    }

    int getProduct(int k)
    {
        if (k >= prefix.size() - lastZeroIndex)
        {
            return 0;
        }
        return prefix.back() / prefix[prefix.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

int main(int argc, char const *argv[])
{
    
    return 0;
}