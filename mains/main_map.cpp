#include "main.hpp"

void    print_map()
{
    std::cout << std::endl << "\e[1;34m";
    std::cout << "______________________________________________________________________________" << std::endl;
    std::cout << "/$$      /$$  /$$$$$$  /$$$$$$$        /$$$$$$$$ /$$$$$$$$  /$$$$$$  /$$$$$$$$" << std::endl;
    std::cout << "|$$$    /$$$ /$$__  $$| $$__  $$      |__  $$__/| $$_____/ /$$__  $$|__  $$__/" << std::endl;
    std::cout << "|$$$$  /$$$$| $$  \\ $$| $$  \\ $$         | $$   | $$      | $$  \\__/   | $$" << std::endl;   
    std::cout << "|$$ $$/$$ $$| $$$$$$$$| $$$$$$$/         | $$   | $$$$$   |  $$$$$$    | $$" << std::endl;   
    std::cout << "|$$  $$$| $$| $$__  $$| $$____/          | $$   | $$__/    \\____  $$   | $$" << std::endl;   
    std::cout << "|$$\\  $ | $$| $$  | $$| $$               | $$   | $$       /$$  \\ $$   | $$" << std::endl;   
    std::cout << "|$$ \\/  | $$| $$  | $$| $$               | $$   | $$$$$$$$|  $$$$$$/   | $$" << std::endl;   
    std::cout << "|__/     |__/|__/  |__/|__/               |__/   |________/ \\______/    |__/" << std::endl;
    std::cout << "______________________________________________________________________________" << std::endl;
    std::cout << "\e[1;37m" << std::endl << std::endl;
}

bool fncomp(char lhs, char rhs)
{
    return lhs < rhs;
}

struct classcomp
{
    bool operator()(const char &lhs, const char &rhs) const { return lhs < rhs; }
};

void     map_test()
{
    print_map();
    std::cout << "\e[1;31mConstractors Test:\e[1;37m" << std::endl;
    {
        ft::map<char, int> first; 
        first['a'] = 10;
        first['b'] = 30;
        first['c'] = 50;
        first['d'] = 70;  
        ft::map<char, int> second(first.begin(), first.end());
        ft::map<char, int> third(second);
        ft::map<char, int>::iterator it;  
        it = third.begin();
        std::cout << it->first << std::endl;
    }   
    {
        ft::map<char, int> mymap; 
        mymap['b'] = 100;
        mymap['a'] = 200;
        mymap['c'] = 300; 
        // show content:
        for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " -> " << it->second << '\n';
    }   
    {
        ft::map<char, int> mymap; 
        mymap['x'] = 100;
        mymap['y'] = 200;
        mymap['z'] = 300; 
        // show content:
        ft::map<char, int>::reverse_iterator rit;
        for (rit = mymap.rbegin(); rit != mymap.rend(); ++rit)
            std::cout << rit->first << " -> " << rit->second << '\n';
    }   
    {
        ft::map<char, int> mymap; 
        mymap['a'] = 10;
        mymap['b'] = 20;
        mymap['c'] = 30;  
        while (!mymap.empty())
        {
            std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
            mymap.erase(mymap.begin());
        }
        std::cout << std::endl;
    }
    // SIZE
    std::cout << "\e[1;31mSize Test:\e[1;37m" << std::endl;
    {
        ft::map<char, int> mymap;
        mymap['a'] = 101;
        mymap['b'] = 202;
        mymap['c'] = 302; 
        std::cout << "mymap.size() is " << mymap.size() << '\n';
        std::cout << std::endl;
    }   
    //  MAX_SIZE
    std::cout << "\e[1;31mMAX_SIZE Test:\e[1;37m" << std::endl;
    {
        int i;
        ft::map<int, int> mymap;  
        if (mymap.max_size() > 1000)
        {
            for (i = 0; i < 1000; i++)
              mymap[i] = 0;
            std::cout << "The map contains 1000 elements.\n";
        }
        else
            std::cout << "The map could not hold 1000 elements.\n";
        std::cout << std::endl;
    }   
    // operator[]
    std::cout << "\e[1;31m[] Operator Test:\e[1;37m" << std::endl;  
    {
        ft::map<char, std::string> mymap; 
        mymap['a'] = "an element";
        mymap['b'] = "another element";
        mymap['c'] = mymap['b'];  
        std::cout << "mymap['a'] is " << mymap['a'] << '\n';
        std::cout << "mymap['b'] is " << mymap['b'] << '\n';
        std::cout << "mymap['c'] is " << mymap['c'] << '\n';
        std::cout << "mymap['d'] is " << mymap['d'] << '\n';  
        std::cout << "mymap now contains " << mymap.size() << " elements.\n";
        std::cout << std::endl;
    }   
    // INSERT
    std::cout << "\e[1;31mInsert Test:\e[1;37m" << std::endl;
    {
        ft::map<char, int> mymap; 
        // first insert function version (single parameter):
        mymap.insert(ft::pair<char, int>('a', 100));
        mymap.insert(ft::pair<char, int>('z', 200));  
        ft::pair<ft::map<char, int>::iterator, bool> ret;
        ret = mymap.insert(ft::pair<char, int>('z', 500));
        if (ret.second == false)
        {
            std::cout << "element 'z' already existed";
            std::cout << " with a value of " << ret.first->second << '\n';
        } 
        // second insert function version (with hint position):
        ft::map<char, int>::iterator it = mymap.begin();
        mymap.insert(it, ft::pair<char, int>('b', 300)); // max efficiency inserting
        mymap.insert(it, ft::pair<char, int>('c', 400)); // no max efficiency inserting   
        // third insert function version (range insertion):
        ft::map<char, int> anothermap;
        anothermap.insert(mymap.begin(), mymap.find('c'));    
        std::cout << "mymap contains:\n";
        for (it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n'; 
        std::cout << "anothermap contains:\n";
        for (it = anothermap.begin(); it != anothermap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << std::endl;
    }   
    // ERASE
    std::cout << "\e[1;31mErase Test:\e[1;37m" << std::endl;    
    {
        ft::map<char, int> mymap;
        ft::map<char, int>::iterator it;  
        // insert some values:
        mymap['a'] = 10;
        mymap['b'] = 20;
        mymap['c'] = 30;
        mymap['d'] = 40;
        mymap['e'] = 50;
        mymap['f'] = 60;  
        it = mymap.find('b');
        mymap.erase(it);
        mymap.erase('c');
        it = mymap.find('e');
        mymap.erase(it, mymap.end()); // erasing by range 
        for (it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << std::endl;
    }   
    // SWAP
    std::cout << "\e[1;31mSwap Test:\e[1;37m" << std::endl;
    {
        ft::map<char, int> foo, bar;  
        foo['x'] = 100;
        foo['y'] = 200;   
        bar['a'] = 11;
        bar['b'] = 22;
        bar['c'] = 33;    
        foo.swap(bar);    
        std::cout << "foo contains:\n";
        for (ft::map<char, int>::iterator it = foo.begin(); it != foo.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n'; 
        std::cout << "bar contains:\n";
        for (ft::map<char, int>::iterator it = bar.begin(); it != bar.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << std::endl;
    }   
    // CLEAR
    std::cout << "\e[1;31mClear Test:\e[1;37m" << std::endl;
    {
        ft::map<char, int> mymap;
        mymap['x'] = 100;
        mymap['y'] = 200;
        mymap['z'] = 300; 
        std::cout << "mymap contains:\n";
        for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n'; 
        mymap.clear();
        mymap['a'] = 1101;
        mymap['b'] = 2202;    
        std::cout << "mymap contains:\n";
        for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << std::endl;
    }   
    // KEY_COMP
    std::cout << "\e[1;31mKey_Comp Test:\e[1;37m" << std::endl;
    {
        ft::map<char, int> mymap; 
        ft::map<char, int>::key_compare mycomp = mymap.key_comp();    
        mymap['a'] = 100;
        mymap['b'] = 200;
        mymap['c'] = 300; 
        std::cout << "mymap contains:\n"; 
        char highest = mymap.rbegin()->first; // key value of last element    
        ft::map<char, int>::iterator it = mymap.begin();
        do
        {
            std::cout << it->first << " => " << it->second << '\n';
        } while (mycomp((*it++).first, highest)); 
        std::cout << '\n';
        std::cout << std::endl;
    }   
    // VALUE_COMP
    std::cout << "\e[1;31mValue_Comp Test:\e[1;37m" << std::endl;
    {
        ft::map<char, int> mymap; 
        mymap['x'] = 1001;
        mymap['y'] = 2002;
        mymap['z'] = 3003;    
        std::cout << "mymap contains:\n"; 
        ft::pair<char, int> highest = *mymap.rbegin(); // last element    
        ft::map<char, int>::iterator it = mymap.begin();
        do
        {
            std::cout << it->first << " => " << it->second << '\n';
        } while (mymap.value_comp()(*it++, highest));
    }   
    {
        ft::map<char, int> mymap;
        ft::map<char, int>::iterator it;  
        mymap['a'] = 50;
        mymap['b'] = 100;
        mymap['c'] = 150;
        mymap['d'] = 200; 
        it = mymap.find('b');
        if (it != mymap.end())
            mymap.erase(it);    
        // print content:
        std::cout << "elements in mymap:" << '\n';
        std::cout << "a => " << mymap.find('a')->second << '\n';
        std::cout << "c => " << mymap.find('c')->second << '\n';
        std::cout << "d => " << mymap.find('d')->second << '\n';
        std::cout << std::endl;
    }   
    // FIND
    std::cout << "\e[1;31mFind Test:\e[1;37m" << std::endl;
    {
        ft::map<char, int> mymap;
        ft::map<char, int>::iterator it;  
        mymap['a'] = 50;
        mymap['b'] = 100;
        mymap['c'] = 150;
        mymap['d'] = 200; 
        it = mymap.find('b');
        if (it != mymap.end())
            mymap.erase(it);    
        // print content:
        std::cout << "elements in mymap:" << '\n';
        std::cout << "a => " << mymap.find('a')->second << '\n';
        std::cout << "c => " << mymap.find('c')->second << '\n';
        std::cout << "d => " << mymap.find('d')->second << '\n';
        std::cout << std::endl;
    }   
    // COUNT
    std::cout << "\e[1;31mCount Test:\e[1;37m" << std::endl;
    {
        ft::map<char, int> mymap;
        char c;   
        mymap['a'] = 101;
        mymap['c'] = 202;
        mymap['f'] = 303; 
        for (c = 'a'; c < 'h'; c++)
        {
          std::cout << c;
          if (mymap.count(c) > 0)
            std::cout << " is an element of mymap.\n";
          else
            std::cout << " is not an element of mymap.\n";
        }
        std::cout << std::endl;
    }   
    // LOWER_BOUND
    std::cout << "\e[1;31mLower_Bound Test:\e[1;37m" << std::endl;
    {
        ft::map<char, int> mymap;
        ft::map<char, int>::iterator itlow, itup; 
        mymap['a'] = 20;
        mymap['b'] = 40;
        mymap['c'] = 60;
        mymap['d'] = 80;
        mymap['e'] = 100; 
        itlow = mymap.lower_bound('b'); // itlow points to b
        itup = mymap.upper_bound('d');  // itup points to e (not d!)  
        mymap.erase(itlow, itup);
        for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << std::endl;
    }   
    // UPPER_BOUND
    std::cout << "\e[1;31mUpper_bound Test:\e[1;37m" << std::endl;
    {
        ft::map<char, int> mymap;
        ft::map<char, int>::iterator itlow, itup; 
        mymap['a'] = 20;
        mymap['b'] = 40;
        mymap['c'] = 60;
        mymap['d'] = 80;
        mymap['e'] = 100; 
        itlow = mymap.lower_bound('b'); // itlow points to b
        itup = mymap.upper_bound('d');  
        mymap.erase(itlow, itup);
        // print content:
        for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << std::endl;
    }   
    // EQUAL_RANGE
    std::cout << "\e[1;31mEqual_range Test:\e[1;37m" << std::endl;
    {
        ft::map<char, int> mymap; 
        mymap['a'] = 10;
        mymap['b'] = 20;
        mymap['c'] = 30;  
        ft::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator> ret;
        ret = mymap.equal_range('b'); 
        std::cout << "lower bound points to: ";
        std::cout << ret.first->first << " => " << ret.first->second << '\n'; 
        std::cout << "upper bound points to: ";
        std::cout << ret.second->first << " => " << ret.second->second << '\n';
    }   
    {
        int psize;
        ft::map<char, int> mymap;
        ft::pair<const char, int> *p; 
        p = mymap.get_allocator().allocate(5);    
        psize = sizeof(ft::map<char, int>::value_type) * 5;   
        std::cout << "The allocated array has a size of " << psize << " bytes.\n";    
        mymap.get_allocator().deallocate(p, 5);
    }
}