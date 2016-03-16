#ifndef SET_H
#define SET_H
#include <vector>
#include <algorithm>

using namespace std ;

template <typename ValueType>
class Set
{
private:
    vector<ValueType> vec ;
public:
    Set();
    ~Set();
    int size() const;
    bool isEmpty() const;
    void insert (const ValueType& value);
    void remove (const ValueType& value);
    bool contains (const ValueType& value) const;
    bool isSubsetOf(const Set& set2) const;
    void clear();
    bool operator==(const Set& set2) const;
    bool operator!=(const Set& set2) const;
    Set  operator+ (const Set& set2) const;
    Set  operator* (const Set& set2) const;
    Set  operator- (const Set& set2) const;

    friend istream& operator << (istream& in ,Set<ValueType> &mySet)
    {
        ValueType x ;
        cout << "Enter values to add to the set, each in a new line\n" ;
        cout << "To stop the input, Enter the last value twice \n" ;

        mySet.clear();
        ValueType m = mySet.vec.back() ;
        while (1)
        {
            m = x ;
            cin >> x ;
            bool f = (x==m) ;

            if (f)
                break ;
            mySet.insert(x);

        }
        return in ;
    }

    Set operator= (const Set& set2) ;
    void view ();
    int BinarySearch (vector<ValueType> v , int target , int first ,int last ) ;
};

#endif // SET_H


template <typename ValueType>
Set<ValueType>::Set()
{

}

template <typename ValueType>
Set<ValueType>::~Set()
{

}

template <typename ValueType>
int Set<ValueType>::size() const
{
    return vec.size() ;
}

template <typename ValueType>
bool Set<ValueType>::isEmpty() const
{
    if (vec.size()==0)
        return true ;
    else return false ;
}

template <typename ValueType>
void Set<ValueType>::insert (const ValueType& value)
{
    if (!contains(value))
    {
        vec.push_back(value) ;
        sort (vec.begin(), vec.end());
    }
}

template <typename ValueType>
void Set<ValueType>::remove (const ValueType& value)
{
    int index = BinarySearch(vec , value , 0 , vec.size()-1) ;
    vec.erase(vec.begin()+index) ;
}

template <typename ValueType>
bool Set<ValueType>::contains (const ValueType& value) const
{
    for (ValueType x : vec)
    {
        if (x==value)
            return true ;
    }
    return false ;
}

template <typename ValueType>
bool Set<ValueType>::isSubsetOf(const Set& set2) const
{
    bool subset = true ;
    for (ValueType x : this->vec)
    {
        if (!set2.contains(x))
        {
            subset = false ;
            break ;
        }
    }
    return subset ;
}

template <typename ValueType>
void Set<ValueType>::clear()
{
    vec.clear();
}

template <typename ValueType>
bool Set<ValueType>::operator==(const Set& set2) const
{
    bool equals = true ;
    if (vec.size() != set2.vec.size())
    {
        equals = false ;
    }
    else
    {
        for (int i=0 ; i<vec.size() ; i++)
        {
            if (vec[i]!=set2.vec[i])
            {
                equals = false ;
            }
        }
    }
    return equals ;
}

template <typename ValueType>
bool Set<ValueType>::operator!=(const Set& set2) const
{
    bool equals = false ;
    if (vec.size() != set2.vec.size())
    {
        equals = true ;
    }
    else
    {
        for (int i=0 ; i<vec.size() ; i++)
        {
            if (vec[i]!=set2.vec[i])
            {
                equals = true ;
            }
        }
    }
    return equals ;
}

template <typename ValueType>
Set<ValueType> Set<ValueType>::operator+ (const Set& set2) const //Union
{
    Set<ValueType> s ;
    for (ValueType v : vec)
    {
        s.insert(v) ;
    }
    for (ValueType x : set2.vec)
    {
        s.insert(x);
    }
    return s ;
}

template <typename ValueType>
Set<ValueType>  Set<ValueType>::operator* (const Set& set2) const// Intersection of two
{
    Set<ValueType> s ;
    for (ValueType x : set2.vec)
    {
        if (this->contains(x))
        {
            s.insert(x) ;
        }
    }
    return s ;
}

template <typename ValueType>
Set<ValueType> Set<ValueType>::operator- (const Set& set2) const // Subtract set two from one
{
    Set<ValueType> s ;
    for (ValueType v : vec)
    {
        s.insert(v) ;
    }
    for (ValueType x : set2.vec)
    {
        if (s.contains(x))
        {
            s.remove(x);
        }
    }
    return s;
}

template <typename ValueType>
Set<ValueType> Set<ValueType>::operator= (const Set& set2)
{
    Set<ValueType> s ;
    for (ValueType x : set2.vec )
    {
        s.insert(x) ;
    }
    this->clear();
    for (ValueType x : s.vec )
    {
        this->insert(x) ;
    }
    return s ;
}

template <typename ValueType>
void Set<ValueType>::view()
{
    for (ValueType x : vec)
    {
        cout << x << " " ;
    }
    cout << endl ;
}

template <typename ValueType>
int Set<ValueType>::BinarySearch (vector<ValueType> v , int target , int first ,int last )
{
    int mid = (first+last)/2  ;

    if (target == v[mid])
        return mid ;
    else if (target > v[mid])
    {
        return BinarySearch(v, target , mid+1 , last) ;
    }
    else if (target < v[mid])
    {
        return BinarySearch(v, target , first , mid-1) ;
    }
}
