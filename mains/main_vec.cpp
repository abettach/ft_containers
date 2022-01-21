#include "main.hpp"

void    print_vec()
{
    std::cout << std::endl << "\e[1;34m";
    std::cout << "__________________________________________________________________________________________________________" << std::endl;
    std::cout <<"|$$\\    $$\\ $$$$$$$$\\  $$$$$$\\ $$$$$$$$\\  $$$$$$\\  $$$$$$$\\        $$$$$$$$\\ $$$$$$$$\\  $$$$$$\\ $$$$$$$$\\|"<< std::endl;
    std::cout <<"|$$ |   $$ |$$  _____|$$  __$$\\\\__$$  __|$$  __$$\\ $$  __$$\\       \\__$$  __|$$  _____|$$  __$$\\\\__$$  __|" << std::endl;
    std::cout <<"|$$ |   $$ |$$ |      $$ /  \\__|  $$ |   $$ /  $$ |$$ |  $$ |         $$ |   $$ |      $$ /  \\__|  $$ |"  << std::endl;
    std::cout <<"|\\$$\\  $$  |$$$$$\\    $$ |        $$ |   $$ |  $$ |$$$$$$$  |         $$ |   $$$$$\\    \\$$$$$$\\    $$ |"  << std::endl;
    std::cout <<"| \\$$\\$$  / $$  __|   $$ |        $$ |   $$ |  $$ |$$  __$$<          $$ |   $$  __|    \\____$$\\   $$ |"<< std::endl;
    std::cout <<"|  \\$$$  /  $$ |      $$ |  $$\\   $$ |   $$ |  $$ |$$ |  $$ |         $$ |   $$ |      $$\\   $$ |  $$ |" << std::endl;
    std::cout <<"|   \\$  /   $$$$$$$$\\ \\$$$$$$  |  $$ |    $$$$$$  |$$ |  $$ |         $$ |   $$$$$$$$\\ \\$$$$$$  |  $$ |"  << std::endl;
    std::cout <<"|    \\_/    \\________| \\______/   \\__|    \\______/ \\__|  \\__|         \\__|   \\________| \\______/   \\__|" << std::endl;
    std::cout << "|_________________________________________________________________________________________________________";
    std::cout << "\e[1;37m" << std::endl << std::endl;
}

void vector_test()
{
    print_vec();
    std::cout << "\e[1;31mConstractors Test:\e[1;37m" << std::endl;
    {
      ft::vector<int> first;            
      ft::vector<int> second(4, 100); 
      ft::vector<int> third(second.begin(), second.end());
      ft::vector<int> fourth(third);  
      int myints[] = {16, 2, 77, 29};
      ft::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int)); 
      std::cout << "The contents of fifth are:";
      for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
        std::cout << ' ' << *it;
      std::cout << '\n' << std::endl;
    }

    // --> BEGIN/END
    std::cout << "\e[1;31mBegine & End Test:\e[1;37m" << std::endl;
    {
      ft::vector<int> myvector;
      for (int i = 1; i <= 5; i++)
        myvector.push_back(i);  
      std::cout << "myvector contains:";
      for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        std::cout << ' ' << *it;
      std::cout << '\n'<< std::endl;;
    }
    // --> RBEGIN/REND
    std::cout << "\e[1;31mReverse Begine & Reverse End Test:\e[1;37m" << std::endl;
    {
      ft::vector<int> myvector(5); // 5 default-constructed ints    
      int i = 0;    
      ft::vector<int>::reverse_iterator rit = myvector.rbegin();
      for (; rit != myvector.rend(); ++rit)
        *rit = ++i; 
      std::cout << "myvector contains:";
      for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        std::cout << ' ' << *it;
      std::cout << '\n'<< std::endl;;
    }   
    // --> SIZE
    std::cout << "\e[1;31mSize Test:\e[1;37m" << std::endl;
    {
      ft::vector<int> myints;
      std::cout << "0. size: " << myints.size() << '\n';    
      for (int i = 0; i < 10; i++)
        myints.push_back(i);
      std::cout << "1. size: " << myints.size() << '\n';    
      myints.insert(myints.end(), 10, 100);
      std::cout << "2. size: " << myints.size() << '\n';    
      myints.pop_back();
      std::cout << "3. size: " << myints.size() << '\n'<< std::endl;;
    }   
    // --> MAX_SIZE
    std::cout << "\e[1;31mMAX_SIZE Test:\e[1;37m" << std::endl;
    {
      ft::vector<int> myvector; 
      for (int i = 0; i < 100; i++)
        myvector.push_back(i);  
      std::cout << "size: " << myvector.size() << "\n";
      std::cout << "capacity: " << myvector.capacity() << "\n";
      std::cout << "max_size: " << myvector.max_size() << "\n"<< std::endl;;
    }   
    // --> RESIZE
    std::cout << "\e[1;31mResize Test:\e[1;37m" << std::endl;

    {
      ft::vector<int> myvector; 
      for (int i = 1; i < 10; i++)
        myvector.push_back(i);  
      myvector.resize(5);
      myvector.resize(8, 100);
      myvector.resize(12);  
      std::cout << "myvector contains:";
      for (size_t i = 0; i < myvector.size(); i++)
        std::cout << ' ' << myvector[i];
      std::cout << '\n'<< std::endl;;
    }   
    // --> CAPACITY
    std::cout << "\e[1;31mCapacity Test:\e[1;37m" << std::endl;
    {
      ft::vector<int> myvector; 

      for (int i = 0; i < 100; i++)
        myvector.push_back(i);  
      std::cout << "size: " << (int)myvector.size() << '\n';
      std::cout << "capacity: " << (int)myvector.capacity() << '\n';
      std::cout << "max_size: " << (int)myvector.max_size() << '\n'<< std::endl;;
    }   
    // --> EMPTY
    std::cout << "\e[1;31mEmpty Test:\e[1;37m" << std::endl;
    {
      ft::vector<int> myvector;
      int sum = 0;  
      for (int i = 1; i <= 10; i++)
        myvector.push_back(i);  
      while (!myvector.empty())
      {
        sum += myvector.back();
        myvector.pop_back();
      } 
      std::cout << "total: " << sum << '\n'<< std::endl;;
    }   
    // RESERVE
    std::cout << "\e[1;31mReserve Test:\e[1;37m" << std::endl;
    {
      ft::vector<int>::size_type sz;    
      ft::vector<int> foo;
      sz = foo.capacity();
      std::cout << "making foo grow:\n";
      for (int i = 0; i < 100; ++i)
      {
        foo.push_back(i);
        if (sz != foo.capacity())
        {
          sz = foo.capacity();
          std::cout << "capacity changed: " << sz << '\n';
        }
      } 
      ft::vector<int> bar;
      sz = bar.capacity();
      bar.reserve(100); // this is the only difference with foo above
      std::cout << bar.capacity() << " " << bar.size() << " making bar grow:\n";
      for (int i = 0; i < 100; ++i)
      {
        bar.push_back(i);
        if (sz != bar.capacity())
        {
          sz = bar.capacity();
          std::cout << "capacity changed: " << sz << '\n';
        }
      }
      std::cout << std::endl;
    }   
    // OPERATOR[]
    std::cout << "\e[1;31m[] Operator Test:\e[1;37m" << std::endl;
    {
      ft::vector<int> myvector(10); // 10 zero-initialized elements 
      ft::vector<int>::size_type sz = myvector.size();  
      for (unsigned i = 0; i < sz; i++)
        myvector[i] = i;    
      // reverse vector using operator[]:
      for (unsigned i = 0; i < sz / 2; i++)
      {
        int temp;
        temp = myvector[sz - 1 - i];
        myvector[sz - 1 - i] = myvector[i];
        myvector[i] = temp;
      } 
      std::cout << "myvector contains:";
      for (unsigned i = 0; i < sz; i++)
        std::cout << ' ' << myvector[i];
      std::cout << '\n'<< std::endl;;    
    }   
    // AT() 
    std::cout << "\e[1;31mAT() Test:\e[1;37m" << std::endl;\
    {
      ft::vector<int> myvector(10); // 10 zero-initialized ints 
      // assign some values:
      for (unsigned i = 0; i < myvector.size(); i++)
        myvector.at(i) = i; 
      std::cout << "myvector contains:";
      for (unsigned i = 0; i < myvector.size(); i++)
        std::cout << ' ' << myvector.at(i);
      std::cout << '\n'<< std::endl;;
    }
    // FRONT()
    std::cout << "\e[1;31mFront Test:\e[1;37m" << std::endl;

    {
      ft::vector<int> myvector; 
      myvector.push_back(78);
      myvector.push_back(16);   
      // now front equals 78, and back 16   
      myvector.front() -= myvector.back();  
      std::cout << "myvector.front() is now " << myvector.front() << '\n'<< std::endl;;
    }   
    // back()
    std::cout << "\e[1;31mBack Test:\e[1;37m" << std::endl;

    {
      ft::vector<int> myvector; 
      myvector.push_back(10);   
      while (myvector.back() != 0)
      {
        myvector.push_back(myvector.back() - 1);
      } 
      std::cout << "myvector contains:";
      for (unsigned i = 0; i < myvector.size(); i++)
        std::cout << ' ' << myvector[i];
      std::cout << '\n'<< std::endl;;
    }   
    // ASSIGN
    std::cout << "\e[1;31mAssign Test:\e[1;37m" << std::endl;
    {
      ft::vector<int> first;
      ft::vector<int> second;
      ft::vector<int> third;    
      first.assign(7, 100); // 7 ints with a value of 100   
      ft::vector<int>::iterator it;
      it = first.begin() + 1;   
      second.assign(it, first.end() - 1); // the 5 central values of first  
      int myints[] = {1776, 7, 4};
      third.assign(myints, myints + 3); // assigning from array.    
      std::cout << "Size of first: " << int(first.size()) << '\n';
      std::cout << "Size of second: " << int(second.size()) << '\n';
      std::cout << "Size of third: " << int(third.size()) << '\n'<< std::endl;
    }   
    // PUSH_BACK
    std::cout << "\e[1;31mPush_back Test:\e[1;37m" << std::endl;
    {
      ft::vector<int> myvector;
      int myint;    
      std::cout << "Please enter some integers (enter 0 to end):\n";    
      do
      {
        std::cin >> myint;
        myvector.push_back(myint);
      } while (myint);  
      std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n"<< std::endl;;
    }   
    // POP_BACK
    std::cout << "\e[1;31mPop_Back Test:\e[1;37m" << std::endl;

    {
      ft::vector<int> myvector;
      int sum(0);
      myvector.push_back(100);
      myvector.push_back(200);
      myvector.push_back(300);  
      while (!myvector.empty())
      {
        sum += myvector.back();
        myvector.pop_back();
      } 
      std::cout << "The elements of myvector add up to " << sum << '\n'<< std::endl;;
    }   
    // INSERT
    std::cout << "\e[1;31mInsert Test:\e[1;37m" << std::endl;

    {
      ft::vector<int> myvector(3, 100);
      ft::vector<int>::iterator it; 
      it = myvector.begin();
      it = myvector.insert(it, 200);    
      myvector.insert(it, 2, 300);  
      // "it" no longer valid, get a new one:
      it = myvector.begin();    
      ft::vector<int> anothervector(2, 400);
      myvector.insert(it + 2, anothervector.begin(), anothervector.end());  
      int myarray[] = {501, 502, 503};
      myvector.insert(myvector.begin(), myarray, myarray + 3);  
      std::cout << "myvector contains:";
      for (it = myvector.begin(); it < myvector.end(); it++)
        std::cout << ' ' << *it;
      std::cout << '\n'<< std::endl;;
    }   
    // ERASE
    std::cout << "\e[1;31mErase Test:\e[1;37m" << std::endl;

    {
      ft::vector<int> myvector; 
      // set some values (from 1 to 10)
      for (int i = 1; i <= 10; i++)
        myvector.push_back(i);  
      // erase the 6th element
      myvector.erase(myvector.begin() + 5); 
      // erase the first 3 elements:
      myvector.erase(myvector.begin(), myvector.begin() + 3);   
      std::cout << "myvector contains:";
      for (unsigned i = 0; i < myvector.size(); ++i)
        std::cout << ' ' << myvector[i];
      std::cout << '\n'<< std::endl;;
    }   
    // SWAP
    std::cout << "\e[1;31mSwap Test:\e[1;37m" << std::endl;
    {
      ft::vector<int> foo(3, 100); // three ints with a value of 100
      ft::vector<int> bar(5, 200); // five ints with a value of 200 
      foo.swap(bar);    
      std::cout << "foo contains:";
      for (unsigned i = 0; i < foo.size(); i++)
        std::cout << ' ' << foo[i];
      std::cout << '\n';    
      std::cout << "bar contains:";
      for (unsigned i = 0; i < bar.size(); i++)
        std::cout << ' ' << bar[i];
      std::cout << '\n'<< std::endl;;
    }
    // CLEAR
    std::cout << "\e[1;31mClear Test:\e[1;37m" << std::endl;
    {
      ft::vector<int> myvector;
      myvector.push_back(100);
      myvector.push_back(200);
      myvector.push_back(300);  
      std::cout << "myvector contains:";
      for (unsigned i = 0; i < myvector.size(); i++)
        std::cout << ' ' << myvector[i];
      std::cout << '\n';    
      myvector.clear();
      myvector.push_back(1101);
      myvector.push_back(2202); 
      std::cout << "myvector contains:";
      for (unsigned i = 0; i < myvector.size(); i++)
        std::cout << ' ' << myvector[i];
      std::cout << '\n'<< std::endl;;
    }
    // GET_ALLOCATOR
    std::cout << "\e[1;31mGet_allocator Test:\e[1;37m" << std::endl;

    {
      ft::vector<int> myvector;
      int *p;
      unsigned int i;   
      // allocate an array with space for 5 elements using vector's allocator:
      p = myvector.get_allocator().allocate(5); 
      // construct values in-place on the array:
      for (i = 0; i < 5; i++)
        myvector.get_allocator().construct(&p[i], i);   
      std::cout << "The allocated array contains:";
      for (i = 0; i < 5; i++)
        std::cout << ' ' << p[i];
      std::cout << '\n';    
      // destroy and deallocate:
      for (i = 0; i < 5; i++)
        myvector.get_allocator().destroy(&p[i]);
      myvector.get_allocator().deallocate(p, 5);
      std::cout << std::endl;
    }   
    // SWAP(VECTOR)
    std::cout << "\e[1;31mVector Swap Test:\e[1;37m" << std::endl;
    {
      ft::vector<int> foo(3, 100); // three ints with a value of 100
      ft::vector<int> bar(5, 200); // five ints with a value of 200 
      foo.swap(bar);    
      std::cout << "foo contains:";
      for (ft::vector<int>::iterator it = foo.begin(); it != foo.end(); ++it)
        std::cout << ' ' << *it;
      std::cout << '\n';    
      std::cout << "bar contains:";
      for (ft::vector<int>::iterator it = bar.begin(); it != bar.end(); ++it)
        std::cout << ' ' << *it;
      std::cout << '\n';
    }   
    {
      ft::vector<int> foo(3, 100); // three ints with a value of 100
      ft::vector<int> bar(2, 200); // two ints with a value of 200  
      if (foo == bar)
        std::cout << "foo and bar are equal\n";
      if (foo != bar)
        std::cout << "foo and bar are not equal\n";
      if (foo < bar)
        std::cout << "foo is less than bar\n";
      if (foo > bar)
        std::cout << "foo is greater than bar\n";
      if (foo <= bar)
        std::cout << "foo is less than or equal to bar\n";
      if (foo >= bar)
        std::cout << "foo is greater than or equal to bar\n";
    std::cout << std::endl;
    }
}