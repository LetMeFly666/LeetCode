type Foo struct {

}

func NewFoo() *Foo {
	return &Foo{
	}
}

func (f *Foo) First(printFirst func()) {
	// Do not change this line
	printFirst()
}

func (f *Foo) Second(printSecond func()) {
	/// Do not change this line
	printSecond()
}

func (f *Foo) Third(printThird func()) {
	// Do not change this line
	printThird()
}