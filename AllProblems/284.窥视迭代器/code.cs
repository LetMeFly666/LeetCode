// C# IEnumerator interface reference:
// https://docs.microsoft.com/en-us/dotnet/api/system.collections.ienumerator?view=netframework-4.8

class PeekingIterator {
    // iterators refers to the first element of the array.
    public PeekingIterator(IEnumerator<int> iterator) {
        // initialize any member here.
    }
    
    // Returns the next element in the iteration without advancing the iterator.
    public int Peek() {
        
    }
    
    // Returns the next element in the iteration and advances the iterator.
    public int Next() {
        
    }
    
    // Returns false if the iterator is refering to the end of the array of true otherwise.
    public bool HasNext() {
		
    }
}