class KidsWithCandies {

    public boolean isIthIndexGreaterThanAllIndicies(int[] arr, int target){
        for(int i = 0; i < arr.length; i++){
            if(target < arr[i]){
                return false;
            }
        }
        return true;
    }

    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        LinkedList<Boolean> list = new LinkedList<Boolean>();
        for(int i = 0; i < candies.length; i++){
            list.add(isIthIndexGreaterThanAllIndicies(candies, candies[i] + extraCandies));
        }
        return list;
    }

}