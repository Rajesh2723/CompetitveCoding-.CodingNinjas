/*
Aakash is a member of Ninja club. He has a weird family structure. Every male member (M) gives birth to a male child first and then a female child, whereas every female (F) member gives birth to a female child first and then to a male child. Aakash analyses this pattern and wants to know what will be the Kth child in his Nth generation. Can you help him?
  */
string kthChildNthGeneration(int n, long long int k)

{

    return (__builtin_popcountll(k - 1) & 1 ? "Female" : "Male");

}
