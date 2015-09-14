public class Solution {
    public String largestNumber(int[] nums) {
        String[] str = new String[nums.length];
        for(int i = 0; i < nums.length; ++i){
        	str[i] = nums[i] + "";
        }

        Comparator<String> comp = new Comparator<String>(){
        	@Override
            public int compare(String o1, String o2) {
                return (o2 + o1).compareTo(o1 + o2);   
            }
        };

        Arrays.sort(str,comp);

        if (str[0].equals("0")) {
            return "0";
        }

        String ans = new String();
        for (String s : str)
            ans += s;

        return ans;

    }
}