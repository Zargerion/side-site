#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>
 
int main()
{
    const size_t row = 5;
    const size_t col = 3;
    std::vector<std::vector<int> > imatrix(row);
    // Заполнение
    for(size_t i = 0; i < row; ++i)
    {
        imatrix[i].resize(col);
        for(size_t j = 0; j < col; ++j)
            imatrix[i][j] = rand() % 666;
    }
    // Печать
    std::for_each(imatrix.begin(), imatrix.end(), [](std::vector<int>& ivec)
    {
        std::for_each(ivec.begin(), ivec.end(), [](int i)
        {
            std::cout  << i;
        });
        std::cout << std::endl;
    });
    system("pause");
    return 0;
}
