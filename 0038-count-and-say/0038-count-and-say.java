class Solution {
    public String countAndSay(int n) {
        String ret="1";
        while(n-->1) {
            StringBuilder make=new StringBuilder();
            for(int i=0;i<ret.length();i++) {
                char ch=ret.charAt(i);
                int freq=1;
                while(i+1<ret.length() && ret.charAt(i)==ret.charAt(i+1)) {
                    freq++;
                    i++;
                }
                make.append(freq+""+ch);
            }
            ret=make.toString();
        }
        return ret;
    }
}