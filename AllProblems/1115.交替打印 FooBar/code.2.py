class FooBar(object):
    def __init__(self, n):
        self.n = n


    def foo(self, printFoo):
        """
        :type printFoo: method
        :rtype: void
        """
        for i in xrange(self.n):
            
            # printFoo() outputs "foo". Do not change or remove this line.
        	printFoo()


    def bar(self, printBar):
        """
        :type printBar: method
        :rtype: void
        """
        for i in xrange(self.n):
            
            # printBar() outputs "bar". Do not change or remove this line.
        	printBar()