import kotlin.math
import java.util.ArrayList

// ===== Basic function =====
fun main() {
    println("Hello, World!")
}

// ===== Parameters, return types, arithmetic =====
fun add(x: Int, y: Int): Int {
    return x + y
}

fun compute(a: Int, b: Int): Int {
    val sum = a + b
    val product = a * b
    val ratio = a / b
    return sum + product - ratio
}

// ===== Variables, literals =====
fun variables() {
    val a = 10
    var b = 20
    val big = 100L
    val pi = 3.14
    val flag = true
    val nothing = null
    val letter = 'z'
    val greeting = "hello"
    b += 5
    b -= 1
    b *= 2
    b /= 3
    b %= 4
    b++
    b--
    val neg = -a
    val pos = +a
}

// ===== If / else if / else =====
fun classify(n: Int): Int {
    if (n > 0) {
        return 1
    } else if (n < 0) {
        return -1
    } else {
        return 0
    }
}

// ===== While loop =====
fun countdown(n: Int) {
    var i = n
    while (i > 0) {
        println(i)
        i--
    }
}

// ===== Do-while loop =====
fun doLoop() {
    var x = 0
    do {
        x++
    } while (x < 10)
}

// ===== For / in loop =====
fun sumList(items: List) {
    var total = 0
    for (x in items) {
        total += x
    }
    return total
}

// ===== For with type annotation =====
fun typedFor(items: List) {
    for (x: Int in items) {
        println(x)
    }
}

// ===== When with subject =====
fun describe(x: Int) {
    when (x) {
        1 -> println("one")
        2 -> println("two")
        3 -> println("three")
        else -> println("other")
    }
}

// ===== When without subject =====
fun grade(score: Int) {
    when {
        score >= 90 -> println("A")
        score >= 80 -> println("B")
        score >= 70 -> println("C")
        else -> println("F")
    }
}

// ===== Operators and expressions =====
fun expressions() {
    val x = 1 + 2 * 3 - 4 / 2
    val y = x > 0 && x < 100
    val z = y || false
    val w = !z
    val r = 1..10
    val s = 1..<10
    val t = x ?: 0
    val a = x == 5
    val b = x != 5
    val c = x >= 0
    val d = x <= 100
    val e = x === x
    val f = x !== x
}

// ===== Dot chaining, safe call, indexing =====
fun chaining() {
    val items = [1, 2, 3]
    val first = items[0]
    val len = items.size
    val safe = items?.size
    val up = "hello".toUpperCase()
}

// ===== Collection literal =====
fun collections() {
    val empty = []
    val nums = [1, 2, 3]
    val mixed = [1 + 1, 2 * 2, 3 - 1]
}

// ===== Prefix / postfix =====
fun incrementing() {
    var a = 0
    val b = ++a
    val c = --a
    val d = a++
    val e = a--
}

// ===== Null-safe type and Elvis =====
fun nullable(x: Int?) {
    val y = x ?: 0
    val z = x?.toString()
}

// ===== As (type cast) =====
fun casting(x: Int) {
    val y = x as Int
}

// ===== Return / break / continue =====
fun jumps() {
    var i = 0
    while (i < 10) {
        if (i == 3) {
            i++
            continue
        }
        if (i == 7) {
            break
        }
        i++
    }
    return
}

// ===== Single-expression function body =====
fun double(x: Int): Int = x * 2

// ===== Nested function calls =====
fun nested() {
    println(add(compute(1, 2), double(3)))
}

// ===== Named argument =====
fun namedArg() {
    val r = add(x = 1, y = 2)
}

// ===== In operator in range =====
fun inRange(x: Int) {
    val r = x in 1..10
}

// ===== Const val =====
const val MAX = 100