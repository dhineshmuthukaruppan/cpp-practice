/* 
Sample Input

4 3
<tag1 value = "HelloWorld">
<tag2 name = "Name1">
</tag2>
</tag1>
tag1.tag2~name
tag1~name
tag1~value

Sample Output

Name1
Not Found!
HelloWorld

 */


#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;    

int main(){

    // n denotes no of lines of input and q denotes no of queries
    int n, q; 

    // cout << "Enter no of lines of input and no of queries " << endl;     
    cin >> n >> q;    

    vector<string> vec; 
    map<string, string> m;

    string tmp;
    getline(cin, tmp);    

    for(int i=0; i<n; i++){

        string s; 
        // cout << "enter line" << endl;     
        getline(cin, s);  

        if(s[1] == '/'){
            // then it denotes that it is a closing tag, then in that case we are supposed to pop one element back from the vector

            /* @TODO */
            vec.pop_back();     

        }else{
            // it denotes that it is a opening tag
            // <tag1 value = "HelloWorld">
            // <tag1> - s.length = 6
            int j = 1;
            string tagname = "";   
            while(j<s.length() && s[j]!=' ' && s[j]!='>'){  
                tagname += s[j];     
                j++; 
            }  
            // status: In this stage we have populated the tag name and we have also reached the ' ' character. 
            // At this stage j's value is 5
            vec.push_back(tagname);   

            string sofar=""; 
            for(int k=0; k<vec.size(); k++){
                if(k==0){
                    sofar+=vec[k];  
                }else{
                    sofar+='.';
                    sofar+=vec[k];
                }
            }
            // status: we have formed the sofar string - eg: tag1.tag2
            
            j++; // j value becomes 6
            while(j<s.length()){   
                // <tag1> - since j is 6, this block will not execute
                // <tag1 value = "hello world"> - length 28  - last double quotes - 26-  In this case it is not less than lenght of string. so this block will continue
                // <tag1 value = "hello world" attribute2 = "value">
                string attributename = ""; 
                while(j<s.length() && s[j]!=' '){
                    attributename+=s[j];
                    j++;   
                }

                while(j<s.length() && s[j]!='\"'){
                    j++; 
                }
                // status: j is in the position of first double quotes
                j++; // j value will be on the first letter of attribute value
                string attributevalue = ""; 
                while(j<s.length() && s[j]!='\"'){
                    attributevalue+=s[j];
                    j++;  
                }
                // status: j value will be on the closing doble quotes

                m[sofar+"~"+attributename] = attributevalue;      

                if(j==(s.length()-2)){
                    break;       
                }
                j++; j++; 
            }  /* end of while loop */



        } // end of else block


    }  /* end of for i loop  */

    for(int i=0; i<q; i++){
        string s; 
        getline(cin, s);
        if(m.find(s) != m.end() ){
            cout << m[s] << endl; 
        }else{
            cout << "Not Found!" << endl;       
        } 
    }   

    return 0;

} // end of main()

