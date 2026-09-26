type ZeroEvenOdd struct {
	n        int
}

func NewZeroEvenOdd(n int) *ZeroEvenOdd {
	zeo := &ZeroEvenOdd{
		n:        n
	}
	return zeo
}

func (z *ZeroEvenOdd) Zero(printNumber func(int)) {

}

func (z *ZeroEvenOdd) Even(printNumber func(int)) {

}

func (z *ZeroEvenOdd) Odd(printNumber func(int)) {

}