#include "recursive.h"
#include "hw4.h"

int accumulate(list_t l, int (*fn)(int, int), int base)
{
  if (list_isEmpty(l)) {
    return base;
  } else {
    return accumulate(list_rest(l), fn, fn(base, list_first(l)));
  }
}


/*
PSEUDOCODE: 
if list is empty
  return 0
else 
  return firstItemOfList + sum(restOfTheList)
*/
int sum(list_t list){
  if (list_isEmpty(list)){
    return 0;
  } else {
    return list_first(list) + sum(list_rest(list));
  }
}


/*
PSEUDOCODE:
if list is empty
  return 1
else 
  return firstItemOfList * product(restOfTheList)
*/
int product(list_t list){
  if (list_isEmpty(list)){
    return 1;
  } else {
    return list_first(list) * product(list_rest(list));
  }
}


/*
PSEUDOCODE:
if second list is empty 
  return first list
if first list is empty
  return second list

first list = reverse of first list
second list = newList(firstListFirstElement, secondList)
first list = reverse of first list
return append(list_rest(first), second)

*/
list_t append(list_t first, list_t second){
  if(list_isEmpty(second) == true){
    return first;
  }
  if(list_isEmpty(first) == true){
    return second;
  }

  first = reverse(first);

  second = list_make(list_first(first), second);
  first = reverse(first);
  first = chop(first, 1);
  return append(first, second);
}


/*
PSEUDOCODE:

if n = 0
  return list

if list is empty
  return list

list = reverse of list
list = listMinusFirstElement
list = reverse of list
n = n - 1

return chop(list, n)
*/
list_t chop(list_t list, int n){
  if(n == 0){
    return list;
  } if (list_isEmpty(list) == true){
    return list;
  }

  list = reverse(list);

  list = list_rest(list);

  list = reverse(list);

  n--;

  return chop(list, n);
}


list_t reverse(list_t list){
  if(list_isEmpty(list) == true){
    return list;
  }

  return list_make(list_first(list), reverse(list_rest(list)));

}


list_t rotate(list_t list, int n){
  if (n == 0) {
    return list;
  } else if (list_isEmpty(list) == true){
    return list;
  }

  list_t temp1 = list_make();

  list_t temp = list_make(list_first(list), temp1);

  list = append(list_rest(list), temp);

  n--;

  return rotate(list, n);
}


/* 
PSEUDOCODE:
if list is empty 
  return list

bool n = 0

tempList = list

while restOfTemp is not empty
  if first element is even
    flip flag n
  tempList = restOfTempList

if n = 0
  return list
else
  if first element of list is odd 
    rotate list
  else
    rotate list
    chop last element of list

return filter_odd(list)
*/
list_t filter_odd(list_t list){
  if (list_isEmpty(list) == true){
    return list;
  }

  bool n = 0;

  list_t temp = list_make(list);

  while (list_isEmpty(temp) == false){
    if (list_first(temp) % 2 == 0){
      n = 1;
    }

    temp = list_rest(temp);
  }

  if (n = 0){
    return list;
  } else {
    if (list_first(list) % 2 = 1){
      rotate(list);
    } else {
      rotate(list);
      chop(list, 1);
    }
  }

  return filter_odd(list);
}



/* 
PSEUDOCODE:
if list is empty 
  return list

bool n = 0

tempList = list

while restOfTemp is not empty
  if first element is odd
    flip flag n
  tempList = restOfTempList

if n = 0
  return list
else
  if first element of list is even
    rotate list
  else
    rotate list
    chop last element of list

return filter_even(list)
*/
list_t filter_odd(list_t list){
  if (list_isEmpty(list) == true){
    return list;
  }

  bool n = 0;

  list_t temp = list_make(list);

  while (list_isEmpty(temp) == false){
    if (list_first(temp) % 2 == 1){
      n = 1;
    }

    temp = list_rest(temp);
  }

  if (n = 0){
    return list;
  } else {
    if (list_first(list) % 2 = 0){
      rotate(list);
    } else {
      rotate(list);
      chop(list, 1);
    }
  }

  return filter_even(list);
}