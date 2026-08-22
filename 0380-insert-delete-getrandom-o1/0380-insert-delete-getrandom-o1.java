class RandomizedSet {
    private List<Integer> list;
    public RandomizedSet() {
        list = new ArrayList<>();
    }

    public boolean insert(int val) {
        if(list.contains(val))
            return false;
        list.add(val);
       return true;
    }

    public boolean remove(int val) {
        boolean flag = false;
        if(list.contains(val))
        {
            list.remove((Integer) val);
            flag = true;
        }
        return flag;
    }

    public int getRandom() {
        int randIdx = new Random().nextInt(list.size());
        return list.get(randIdx);
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */