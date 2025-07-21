class Solution {
    bool isFan(char c1,char c2,char c3){
        if(c1 == c2 && c2 == c3) return true;
        else return false;
    }
public:
    string makeFancyString(string s) {
        if(s.size()<3) return s;
        string res ="";
        for(int i=0;i<s.size()-2;i++){
            if(isFan(s[i],s[i+1],s[i+2])){
                continue;
            }else{
                res += s[i];
            }
        }
        res+=s[s.size()-2];
        res+=s[s.size()-1];
        return res;
    }
};