#include <iostream>
#include "dictionary.h"



template<class K, class V>
void test(Dictionary<K, V>& dic)
{
    dic.set(1, 300);

    try
    {
        std:: cout << dic.get(2) << std::endl;
    }
    catch(MapNotFoundException<int>& e)
    {
        std::cout<< e.get_key() <<" " << e.what() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    if (dic.is_set(1))
    {
        std::cout << "Key is already there \n";
    }

    if (!dic.is_set(2))
    {
        std::cout << "Key is not already there \n";
    }
}



int main(int, char**) {


   MapDictionary<int, int> md;
       
   test(md);    

}
