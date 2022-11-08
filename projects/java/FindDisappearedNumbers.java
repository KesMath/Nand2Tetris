class FindDisappearedNumbers {

    /* a more efficient approach without using LinkedList contains()
     * would be to search for gaps within consecutive elements in sorted array
     * that is, if nums[i] == nums[i+1] + 1, there exists no gaps
     * else, we do nums[i+1] - nums[i] to get gaps between those two bounds,
     * and iterate x times to generate those disappeared numbers
     */
    public List<Integer> findDisappearedNumbers(int[] nums) {
        LinkedList<Integer> list = new LinkedList<Integer>();

        for(int i = 1; i < nums.length; i++){
            list.add(i);
        }

        for(int i = 0; i < nums.length; i++){
            if(list.contains(nums[i])){
                int index = list.indexOf(nums[i]);
                list.remove(index);
            }
        }

        return list;
    }

}