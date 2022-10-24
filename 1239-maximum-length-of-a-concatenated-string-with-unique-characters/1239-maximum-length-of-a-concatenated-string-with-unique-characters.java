class Solution {
    public int maxLength(List<String> arr) {
        return solve(arr,"",0);
    }
    
    private int solve(List<String> arr,String ans,int ind){
        
        if(ind==arr.size()){
            return ans.length();
        };
        
        char alphabet[]=new char[26];
        
        for(int i=0;i<ans.length();i++){
            alphabet[ans.charAt(i)-'a']++;
            if(alphabet[ans.charAt(i)-'a']>1) return 0;
        }
        
        int finalans=ans.length();
        
        for(int i=ind;i<arr.size();i++){
            String str=arr.get(i);
            
            boolean check=true;
            char temp_alphabet[]=new char[26];
            for(int j=0;j<str.length();j++){
                if(alphabet[str.charAt(j)-'a']>0 || temp_alphabet[str.charAt(j)-'a']>0){
                    check=false;
                    break;
                }
                temp_alphabet[str.charAt(j)-'a']++;
                
            }
            
            if(check){
                ans+=str;
                // System.out.println(ans);
                finalans=Math.max(finalans,solve(arr,ans,i+1));
                ans=ans.substring(0,(ans.length()-str.length()));
            }
            
        }
        return finalans;
        
        
        
    }
}