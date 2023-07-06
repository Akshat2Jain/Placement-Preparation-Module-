 bool knows(vector<vector<int>> M, int a, int b)
    {
        if(M[a][b] == 1)
            return true;
            
        return false;
    }
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
           int ans = -1;
       stack<int> s;
       
       //step 1: Put all candidates in stack
       for(int i = 0; i < n; i++)
       {
           s.push(i);
       }
       
      //step 2: pop out two element and check if they know eact other unitl single element is left
      while(s.size() > 1)
      {
          int a = s.top();
          s.pop();
          
          int b = s.top();
          s.pop();
          
          if(knows(M, a, b)){
              //if a knows b. it can't be  celebrity
              s.push(b);
          }
          else{
              //if b knows a. it can't be celebrity
              s.push(a);
          }
      }
      
      //single element left and it can be celebrity
      ans = s.top();
      
      //step 3: verify if ans is celebrity or not
      
      //condition 1: celebrity knows no one
      int zeroCount = 0;
      for(int i = 0; i < n; i++)
      {
          if(M[ans][i] == 0)
            zeroCount++;
      }
       
      //it can't be celebrity 
      if(zeroCount != n)
            return -1;
            
       //condition 2: everyone knows celebrity
       int oneCount = 0;
       for(int i = 0; i < n; i++)
       {
           if(M[i][ans] == 1)
                oneCount++;
       }
       
       //it can't be celebrity 
       //n-1 bcz at index of celebrity itself value is zero i.e diagonal
       if(oneCount != n-1)
            return -1;
            
        return ans;
    }
