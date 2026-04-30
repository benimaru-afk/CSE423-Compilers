fun main() {
    var a : Int = 0
    var b : Int = 1
    var count : Int = 0

    while (count < 10) {
        println(a)
        var next : Int = a + b
        a = b
        b = next
        count = count + 1
    }
}
