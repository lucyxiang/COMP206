/* A naive solution to print all combination of 4 elements in A[]
  with sum equal to X */
void findFourElements(int A[], int n, int X)
{
  // Fix the first element and find other three
  int counter=0;
  for (int i = 0; i < n-3; i++)
  {
    // Fix the second element and find other two
    for (int j = i+1; j < n-2; j++)
    {
      // Fix the third element and find the fourth
      for (int k = j+1; k < n-1; k++)
      {
        // find the fourth
        for (int l = k+1; l < n; l++)
           if (A[i] + A[j] + A[k] + A[l] == X)
              //printf("%d, %d, %d, %d", A[i], A[j], A[k], A[l]);
              counter++
      }
    }
  }
  printf("d\n", counter);
}

// Driver program to test above funtion
int main()
{
  int A[288];
  for(int i=0; i<289; i++){
    A[i] = i;
  }
    int n = sizeof(A) / sizeof(A[0]);
    int X = 288;
    findFourElements (A, n, X);
    return 0;
}
