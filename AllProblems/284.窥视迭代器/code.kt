// Kotlin Iterator reference:
// https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.collections/-iterator/

class PeekingIterator(iterator:Iterator<Int>):Iterator<Int> {
    fun peek(): Int {
    	
    }
    
    override fun next(): Int {
        
    }
    
    override fun hasNext(): Boolean {
        
    }
}

/**
 * Your PeekingIterator object will be instantiated and called as such:
 * var obj = PeekingIterator(arr)
 * var param_1 = obj.next()
 * var param_2 = obj.peek()
 * var param_3 = obj.hasNext()
 */