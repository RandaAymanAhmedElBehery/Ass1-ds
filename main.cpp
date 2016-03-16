#include <iostream>
#include <vector>
#include <algorithm>
#include "Set.h"

using namespace std;

int main()
{
    Set<char> s1 , s2 , s;
    s1.insert('a');
    s1.view();
    s1.insert('v');
    s1.view();
    s1.insert('3');
    s1.view();
    s1.insert('7');
    s1.view();
    s1.insert('g');
    s1.view();
    s1.insert('r');
    s1.view();

    s2.insert('r');
    s2.insert('3');

    cout << s1.contains(50) << endl;
    cout << s1.size() << endl;
    cout << s1.isEmpty() << endl ;

    s1.remove('7');
    s1.view();
    s2.insert('y') ;
    s2.insert('m');
    s2.view();


    cout << s1.isSubsetOf(s2) << endl ;
    cout << s2.isSubsetOf(s1) << endl ;
    cout << (s1==s1) << endl ;
    cout << (s1!=s1) << endl ;
    cout << (s1!=s2) << endl ;

    s = s1+s2 ;
    s.view();

    s=s1*s2 ;
    s.view();

    s1.view();
    s2.view();
    s=s1-s2 ;
    s.view();
    s1=s2 ;
    s1.view();

    cin << s2 ;
    s2.view();

    return 0;
}
