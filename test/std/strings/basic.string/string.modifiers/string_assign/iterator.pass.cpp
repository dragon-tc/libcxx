//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <string>

// template<class InputIterator>
//   basic_string& assign(InputIterator first, InputIterator last);

#include <string>
#include <cassert>

#include "test_iterators.h"
#include "min_allocator.h"

template <class S, class It>
void
test(S s, It first, It last, S expected)
{
    s.assign(first, last);
    assert(s.__invariants());
    assert(s == expected);
}

template <class S, class It>
void
test_exceptions(S s, It first, It last)
{
	S aCopy = s;
    try {
   	    s.assign(first, last);
    	assert(false);
    	}
    catch (...) {}
    assert(s.__invariants());
    assert(s == aCopy);
}

int main()
{
    {
    typedef std::string S;
    const char* s = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    test(S(), s, s, S());
    test(S(), s, s+1, S("A"));
    test(S(), s, s+10, S("ABCDEFGHIJ"));
    test(S(), s, s+52, S("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"));

    test(S("12345"), s, s, S());
    test(S("12345"), s, s+1, S("A"));
    test(S("12345"), s, s+10, S("ABCDEFGHIJ"));
    test(S("12345"), s, s+52, S("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"));

    test(S("1234567890"), s, s, S());
    test(S("1234567890"), s, s+1, S("A"));
    test(S("1234567890"), s, s+10, S("ABCDEFGHIJ"));
    test(S("1234567890"), s, s+52, S("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"));

    test(S("12345678901234567890"), s, s, S());
    test(S("12345678901234567890"), s, s+1, S("A"));
    test(S("12345678901234567890"), s, s+10, S("ABCDEFGHIJ"));
    test(S("12345678901234567890"), s, s+52,
         S("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"));

    test(S(), input_iterator<const char*>(s), input_iterator<const char*>(s), S());
    test(S(), input_iterator<const char*>(s), input_iterator<const char*>(s+1), S("A"));
    test(S(), input_iterator<const char*>(s), input_iterator<const char*>(s+10),
         S("ABCDEFGHIJ"));
    test(S(), input_iterator<const char*>(s), input_iterator<const char*>(s+52),
         S("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"));

    test(S("12345"), input_iterator<const char*>(s), input_iterator<const char*>(s),
         S());
    test(S("12345"), input_iterator<const char*>(s), input_iterator<const char*>(s+1),
         S("A"));
    test(S("12345"), input_iterator<const char*>(s), input_iterator<const char*>(s+10),
         S("ABCDEFGHIJ"));
    test(S("12345"), input_iterator<const char*>(s), input_iterator<const char*>(s+52),
         S("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"));

    test(S("1234567890"), input_iterator<const char*>(s), input_iterator<const char*>(s),
         S());
    test(S("1234567890"), input_iterator<const char*>(s), input_iterator<const char*>(s+1),
         S("A"));
    test(S("1234567890"), input_iterator<const char*>(s), input_iterator<const char*>(s+10),
         S("ABCDEFGHIJ"));
    test(S("1234567890"), input_iterator<const char*>(s), input_iterator<const char*>(s+52),
         S("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"));

    test(S("12345678901234567890"), input_iterator<const char*>(s), input_iterator<const char*>(s),
         S());
    test(S("12345678901234567890"), input_iterator<const char*>(s), input_iterator<const char*>(s+1),
         S("A"));
    test(S("12345678901234567890"), input_iterator<const char*>(s), input_iterator<const char*>(s+10),
         S("ABCDEFGHIJ"));
    test(S("12345678901234567890"), input_iterator<const char*>(s), input_iterator<const char*>(s+52),
         S("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"));
    }
#if __cplusplus >= 201103L
    {
    typedef std::basic_string<char, std::char_traits<char>, min_allocator<char>> S;
    const char* s = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    test(S(), s, s, S());
    test(S(), s, s+1, S("A"));
    test(S(), s, s+10, S("ABCDEFGHIJ"));
    test(S(), s, s+52, S("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"));

    test(S("12345"), s, s, S());
    test(S("12345"), s, s+1, S("A"));
    test(S("12345"), s, s+10, S("ABCDEFGHIJ"));
    test(S("12345"), s, s+52, S("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"));

    test(S("1234567890"), s, s, S());
    test(S("1234567890"), s, s+1, S("A"));
    test(S("1234567890"), s, s+10, S("ABCDEFGHIJ"));
    test(S("1234567890"), s, s+52, S("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"));

    test(S("12345678901234567890"), s, s, S());
    test(S("12345678901234567890"), s, s+1, S("A"));
    test(S("12345678901234567890"), s, s+10, S("ABCDEFGHIJ"));
    test(S("12345678901234567890"), s, s+52,
         S("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"));

    test(S(), input_iterator<const char*>(s), input_iterator<const char*>(s), S());
    test(S(), input_iterator<const char*>(s), input_iterator<const char*>(s+1), S("A"));
    test(S(), input_iterator<const char*>(s), input_iterator<const char*>(s+10),
         S("ABCDEFGHIJ"));
    test(S(), input_iterator<const char*>(s), input_iterator<const char*>(s+52),
         S("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"));

    test(S("12345"), input_iterator<const char*>(s), input_iterator<const char*>(s),
         S());
    test(S("12345"), input_iterator<const char*>(s), input_iterator<const char*>(s+1),
         S("A"));
    test(S("12345"), input_iterator<const char*>(s), input_iterator<const char*>(s+10),
         S("ABCDEFGHIJ"));
    test(S("12345"), input_iterator<const char*>(s), input_iterator<const char*>(s+52),
         S("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"));

    test(S("1234567890"), input_iterator<const char*>(s), input_iterator<const char*>(s),
         S());
    test(S("1234567890"), input_iterator<const char*>(s), input_iterator<const char*>(s+1),
         S("A"));
    test(S("1234567890"), input_iterator<const char*>(s), input_iterator<const char*>(s+10),
         S("ABCDEFGHIJ"));
    test(S("1234567890"), input_iterator<const char*>(s), input_iterator<const char*>(s+52),
         S("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"));

    test(S("12345678901234567890"), input_iterator<const char*>(s), input_iterator<const char*>(s),
         S());
    test(S("12345678901234567890"), input_iterator<const char*>(s), input_iterator<const char*>(s+1),
         S("A"));
    test(S("12345678901234567890"), input_iterator<const char*>(s), input_iterator<const char*>(s+10),
         S("ABCDEFGHIJ"));
    test(S("12345678901234567890"), input_iterator<const char*>(s), input_iterator<const char*>(s+52),
         S("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"));
    }
#endif
	{ // test iterator operations that throw
    typedef std::string S;
    typedef ThrowingIterator<char> TIter;
    typedef input_iterator<TIter> IIter;
    const char* s = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    test_exceptions(S(), IIter(TIter(s, s+10, 4, TIter::TAIncrement)), IIter());
    test_exceptions(S(), IIter(TIter(s, s+10, 5, TIter::TADereference)), IIter());
    test_exceptions(S(), IIter(TIter(s, s+10, 6, TIter::TAComparison)), IIter());

    test_exceptions(S(), TIter(s, s+10, 4, TIter::TAIncrement), TIter());
    test_exceptions(S(), TIter(s, s+10, 5, TIter::TADereference), TIter());
    test_exceptions(S(), TIter(s, s+10, 6, TIter::TAComparison), TIter());
	}
}
