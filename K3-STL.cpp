// Flagi kompilacji do debugowania (więcej ostrzeżeń od kompilatora, sanitizer, debugi STL'a):
// g++ -std=c++20 -Wall -Wextra -Wlogical-op -Wshadow -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_GLIBCXX_ASSERTIONS -o main main.cpp

// Hack na wypisywanie stack trace (stos wywołań funkcji i linia powodująca błąd wykonania)
// dla debugów STL'a. Kompilować z sanitizerem i debugami STL'a.
// Ważne: przed wszystkimi #include. Może powodować warningi kompilatora.
// class SS { int x[0]; };
// extern "C" SS __sanitizer_print_stack_trace();
// #define __last_state }; SS x { __sanitizer_print_stack_trace()

#include<bits/stdc++.h>
using namespace std;

int a[3];
int32_t main(){
    ios::sync_with_stdio(false);

    // Przykłady rzeczy łapanych przez sanitizer:
    // for(int i=0;i<100;i++)
    //     a[rand() % 4] = 1;

    // Przykłady rzeczy łapanych przez debugi i asserty stl'a:
    vector<int> v;
    for(int i=0;i<3;i++)
        v.push_back(i);
    // cout<<v[3]<<endl;

    //
    // sort(v.begin(), v.end(), [&](int a, int b) {return a <= b;});

    //
    set<int> s;
    s.insert(1);
    cout<<*s.end()<<endl;
}


// valgrind:
// kompilacja: bez sanitizera, debugów stla, O3 i statica
// uruchomienie: valgrind ./main < test1ocen.in
// lub valgrind --leak-check=full ./main < test1ocen.in
