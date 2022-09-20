vector<string> fullJustify(vector<string> &words, int maxWidth) {
   // Write your code here
   int n = words.size();
vector<string> ans;  // ans vector
   
   int count = 0;   // keeps current count (characters + min in-b/w spaces)
   int spaces = 0;   // keeps count of in-between spaces  
   int extraSpaces = 0; // extra right-side spaces
   
   int j = 0;    // initialise outside
   for(int i=0;i<n;i++){ // iterate each word
       if(count+words[i].size()<=maxWidth){ // add till possible
           count += words[i].size() + 1; // +1 for in-b/w space
           spaces++;      // simple
       }
       else{   // here its not possible anymore to add in same line
           spaces--;   // ex -> 3 words == 2 spaces
           extraSpaces = maxWidth - count + 1;   // +1 for extra min-space counted for last word      
           string line = "";
           
           int eachSpace = 0;  // no of spaces each in-b/w space will get
           int extraLeft = 0;  // if no of extraspaces doesnt divide evenly between words
           string oneWord = ""; // for case where there is only 1 word, all extraspaces towards right
           if(spaces>0){
               eachSpace = extraSpaces/spaces; // simple logic
               extraLeft = extraSpaces%spaces;
           }
           else{ // one word only case
               while(extraSpaces!=0){
                   oneWord += " ";
                   extraSpaces--;
               }
           }
           // create space-string
           string sp = " "; // as there is already min-space present
           while(eachSpace!=0){
               sp += " ";   //simple
               eachSpace--;
           }

           while(spaces!=0){
               line += words[j] + sp; //simple
               if(extraLeft>0){ // extra towards left case
                   line += " ";
                   extraLeft--;
               }
               j++;   //simple
               spaces--;
           }
           line += words[j] + oneWord; // add last word and also oneWord case (right side spaces)
           
           j = i;   // beginning word of next line
           i--;  // as we arent adding current word yet
           count = 0;
           spaces = 0;  //reset
           ans.push_back(line);
       }
   }
   
//***********for last line**************    
   spaces--;
   extraSpaces = maxWidth - count + 1;
   string line = "";    
   while(spaces!=0){
       line += words[j] + " "; //only one space for last line
       j++;
       spaces--;
   }
   line += words[n-1];    
   while(extraSpaces!=0){ // as lastLine is left aligned
       line += " ";
       extraSpaces--;
   }
   ans.push_back(line);
//***************************************
   
   return ans;
}
