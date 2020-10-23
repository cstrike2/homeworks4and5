/*
PSEUDOCODE:
flag (bool) swap = true

while swap = true
  swap = false
  for i < size
    if current element is greater than next element
      add i element with i+1 element and store in i
      subtract i+1 element from i element and store in i+1
      i element = i element minus i+1 element
      // ^^ just (what i think is) an efficient way to swap places
*/
void BubbleSort(std::vector<std::string> strings){

  bool swap = true;
    while(swap == true) {
        swap = false;
        for (int i = 0; i < strings.size()-1; i++) {
            if (strings[i].compare(strings[i+1]) > 0){
                strings[i] += strings[i+1];
                strings[i+1] = strings[i] - strings[i+1];
                strings[i] -= strings[i+1];
                swap = true;
            }
        }
    }
}


/*
PSEUDOCODE:
int n = size of vector

if n <= 1
  return vector

int counter = 0

while counterElement <= counter+1Element
  if counter >= totalElements
    return vect
  counter++

for all elements up to counter (first unsorted element)
  if element is greater than first unsorted element
    for all elements from insertion place to end of sorted part of vector
      int temp = element j
      element j = first unsorted element
      element j+1 = temp
      // ^^ the way I did it for bubbleSort was confusing so I did it this way

return InsertionSort(vect)
*/
void InsertionSort (std::vector<int> vect){
  int n = vector.size();

  if (n <= 1){
    return vect;
  }

  int counter = 0;

  while(vect[counter] <= vect[counter+1]){
    if (counter >= (n-1)){
      return vect;
    }
    
    counter++;
  }

  for (int i = 0; i <= counter; i++){
    if (vect[counter] < vect[i]){
      for (int j = (i-1); j < counter; j++){
        int temp = vect[j];
        vect[j] = vect[counter];
        vect[j+1] = temp;
      }
    }
  }
  
  return InsertionSort(vect);
}



void MergeSort (std::vector<std::string> vect){
  int l = 0;
  int r = vect.size();
  int m = (l + r) / 2;

  if (l < r) {
    
    mergeSort(vect);
    merge(vect);

  }
}



void Merge (std::vector<std::string> vect, l, m, r){
  int n1 = m - l + 1;
  int n2 = r - m; 

  std::vector<std::string> L[n1];
  std:vector<std::string> R[n2];

  for (int i = 0; i < n1; i++){
    L[i] = vect[l + i];
  }
  for (int j = 0; j < n2; j++){
    R[j] = vect[m + l + j]
  }

  int i = 0;
  int j = 0; 
  int k = l;

  while (i < n1 && j < n2){
    if (L[i].compare(R[j]) < 0) {
      vect[k] = L[i];
      i++;
    } else {
      vect[k] = R[j];
      j++;
    }
    k++;
  }

  while (j < n2){
    vect[k] = R[j];
    j++;
    k++;
  }
}