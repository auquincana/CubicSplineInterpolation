#pragma once

#include <vector>
#include <algorithm>

using namespace std;

/*! \fn
* TEMPLATE FUNCTION lower_bound_custom.
* Compara los elementos de un vector con val retornando un puntero al mayor elemento menor que val
* @param first (InputIterator) puntero al primer elemento del vector
* @param last (InputIterator) puntero al ultimo elemento del vector
* @param val (const T&) valor a comparar
* @return (InputIterator) puntero al elemento que cumple la condicion
*/
template <class ForwardIterator, class T>
ForwardIterator lower_bound_custom(ForwardIterator first, ForwardIterator last, const T& val)
{
    ForwardIterator it = --last;

    if (val > *it) 
		return it;
    else if (val < *first) 
		return first;
    else
    {
        typename iterator_traits<ForwardIterator>::difference_type count, step;
        count = distance(first, last);
        while (count > 0)
        {
            it = first; 
			step = count / 2; 
			advance(it, step);
            if (*it < val)
            {
                first = ++it;
                count = step + 1;
            }
            else count = step;
        }

        if (*first > val) --first;

        return first;
    }
}

/*! \fn
* TEMPLATE FUNCTION index_fast.
* Compara los elementos de un vector con val retornando un puntero al mayor elemento menor que val
* @param first (InputIterator) puntero al primer elemento del vector
* @param last (InputIterator) puntero al ultimo elemento del vector
* @param val (const T&) valor a comparar
* @return (unsigned int) posicion del elemento que cumple la condicion
*/

template <class ForwardIterator, class T>
unsigned long long int index_fast(ForwardIterator first, ForwardIterator last, const T& val)
{
    ForwardIterator inicial = first;
    ForwardIterator it = --last;

    if ( val > *it) return 
		distance(inicial, last);
    else if (val < *first) 
		return 0;
    else
    {
		typename iterator_traits<ForwardIterator>::difference_type count, step;
        count = distance(first, last);
        while (count > 0)
        {
            it = first; 
			step = count / 2;
			advance(it, step);
            if (*it < val)
            {
                first = ++it;
                count -= step + 1;
            }
            else count = step;
        }

        if (*first > val) 
			--first;

        return distance(inicial, first);
    }
}
