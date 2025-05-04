// Java Iterator interface reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html

class PeekingIterator implements Iterator<Integer> {
	public PeekingIterator(Iterator<Integer> iterator) {
	    // initialize any member here.
	    
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	public Integer peek() {
        
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	@Override
	public Integer next() {
	    
	}
	
	@Override
	public boolean hasNext() {
	    
	}
}