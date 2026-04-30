fun main() {
    println("Sum 1 to 10:")
    var sum : Int = 0
    var i : Int = 1
    while (i < 11) {
        sum = sum + i
        i = i + 1
    }
    println(sum)

    println("Factorial of 7:")
    var fact : Int = 1
    var n : Int = 7
    while (n > 1) {
        fact = fact * n
        n = n - 1
    }
    println(fact)

    println("Powers of 2:")
    var power : Int = 1
    var exp : Int = 0
    while (exp < 8) {
        println(power)
        power = power * 2
        exp = exp + 1
    }
}
